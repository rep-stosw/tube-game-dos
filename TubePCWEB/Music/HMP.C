#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>

#if defined(_OPL3_)

#include "opl3.h"

#elif defined(_DBOPL_)

#include "dbopl.h"

#else

#include "fmopl.h"

#endif

#include "hmpopl.h"
#include "hmpfile.h"

#include "Type.h"

#include "misc.h"

#include "MPU401.c"

#include "HMP.H"
#include "SB16.H"

u8 MusicMode=1;  //Воспроизведение мелодий: 0 - с помощью MIDI(MPU401), 1 - с помощью Adlib(OPL)

#ifdef _DBOPL_

DBOPL::Handler opl;

#else

opl3_chip opl;

#endif

static hmpopl *h;
static hmp_file *hf;

static hmp_event ev;
static unsigned char msg[3];

static IO u8 TIMER_FLAG=0;
static IO u8 AUDIO_FLAG=0;

static IO int Delta=0;
static IO int DeltaAbsolute=0;

static char *INST=NULL;
static char *DRUM=NULL;
static u32 INST_Size;
static u32 DRUM_Size;

#define NM 2 /* число мелодий в игре */

static char *MUSIC_Base=NULL;
static char *MUSIC[NM]={NULL};
static u32 MSIZE[NM]={0};

static const int MUSIC_Delta[NM]={0x7500,0x5A00}; //на этих дельтах мелодии заканчиваются(чтобы не ждать длинной паузы в конце и сразу скруглять)
static u8 MUSIC_NUMBER=0xFF;

static void OutAdlib(int Index,int Address,int Data)
{
 #ifdef _DBOPL_

 opl.WriteReg((Index<<8)|Address,Data);

 #else

 OPL3_WriteRegBuffered(&opl,(Index<<8)|Address,Data);

 #endif
}

static void opl_noteoff(unsigned short voice)
{
 if(voice>=9) /* if voice is one of the OPL3 set, adjust it and route over secondary OPL port */
 {
  OutAdlib(0,0x1B0+voice-9,0);
  OutAdlib(1,0x1B0+voice-9,0);
 }
 else
 {
  OutAdlib(0,0xB0+voice,0);
  OutAdlib(1,0xB0+voice,0);
 }
}

static void opl_clear(void) /* turns off all notes */
{
/*
01: Test Register / Waveform Select Enable
02: Timer 1 Count
03: Timer 2 Count
004: IRQ-Reset / Mask / Start
104: Four-Operator Enable
105: OPL3 Mode Enable
08: CSW / NOTE-SEL 
20-35: Tremolo / Vibrato / Sustain / KSR / Frequency Multiplication Factor	=> эти тоже нужно подчищать!
40-55: Key Scale Level / Output Level
60-75: Attack Rate / Decay Rate
80-95: Sustain Level / Release Rate
A0-A8: Frequency Number
B0-B8: Key On / Block Number / F-Number(hi bits)				=> подчищаются
BD: Tremolo Depth / Vibrato Depth / Percussion Mode / BD/SD/TT/CY/HH On		=> подчищается
C0-C8: FeedBack Modulation Factor / Synthesis Type
E0-F5: Waveform Select 
*/

 #define VOICECOUNT 9
 for(int i=0;i<VOICECOUNT;i++)opl_noteoff(i);

 /* reset the percussion bits at the 0xBD register */
 OutAdlib(0,0xBD,0);
 OutAdlib(1,0xBD,0);

 for(int i=0x20;i<=0x35;i++) //20-35: Tremolo / Vibrato / Sustain / KSR / Frequency Multiplication Factor
 {
  OutAdlib(0,i,0x00);
  OutAdlib(1,i,0x00);
 }
}

static void song_step(void)
{
 if(MusicMode)hmpopl_play_midi(h,msg[0]>>4,msg[0]&0x0f,msg[1],msg[2]);
 else OutMIDI(msg[0]|(msg[1]<<8)|(msg[2]<<16));

 while(1)        
 {
  if(hmp_get_event(hf,&ev))return;

  if(ev.datalen)continue;

  if((ev.msg[0]&0xf0)==0xb0 && ev.msg[1] == 7)
  {
   int vol = ev.msg[2];
   vol = (vol * 127) >> 7;
   vol = (vol * 127) >> 7;
   ev.msg[2] = vol;
  }

  if(ev.delta)
  {
   msg[0] = ev.msg[0];
   msg[1] = ev.msg[1];
   msg[2] = ev.msg[2];

   Delta+=ev.delta;
   break;
  }

  if(MusicMode)hmpopl_play_midi(h,ev.msg[0]>>4,ev.msg[0]&0x0f,ev.msg[1],ev.msg[2]);
  else OutMIDI(ev.msg[0]|(ev.msg[1]<<8)|(ev.msg[2]<<16));

 }
}

static void song_init(void)
{
 FILE *f=NULL;
 u8 nanobuf[16];

 if(MusicMode)
 {
  f=fopen("SOUND/INST.BNK","rb");
  INST_Size=FileSize(f);
  INST=(char*)malloc(INST_Size);
  fread(INST,1,INST_Size,f);
  fclose(f);

  f=fopen("SOUND/DRUM.BNK","rb");
  DRUM_Size=FileSize(f);
  DRUM=(char*)malloc(DRUM_Size);
  fread(DRUM,1,DRUM_Size,f);
  fclose(f);
 }

 f=fopen("SOUND/MUSICF-0.TAB","rb");

 fread(nanobuf,1,sizeof(nanobuf),f);
 fread(nanobuf,1,sizeof(nanobuf),f);
 fread(nanobuf,1,sizeof(nanobuf),f);

 fread(nanobuf,1,sizeof(nanobuf),f);
 MUSIC[0]=(char*)(*(u32NA*)&nanobuf[0x2]);
 MSIZE[0]=*(u32NA*)&nanobuf[0xA];

 fread(nanobuf,1,sizeof(nanobuf),f);

 fread(nanobuf,1,sizeof(nanobuf),f);
 MUSIC[1]=(char*)(*(u32NA*)&nanobuf[0x2]);
 MSIZE[1]=*(u32NA*)&nanobuf[0xA];

 fclose(f);

 f=fopen("SOUND/MUSICF-0.DAT","rb");
 int s=FileSize(f);
 MUSIC_Base=(char*)malloc(s);
 fread(MUSIC_Base,1,s,f);
 fclose(f);

 MUSIC[0]+=(u32)MUSIC_Base;
 MUSIC[1]+=(u32)MUSIC_Base;

 if(MusicMode)
 {
  h=hmpopl_new();

  hmpopl_set_bank(h,INST,INST_Size,0);
  hmpopl_set_bank(h,DRUM,DRUM_Size,1);

  hmpopl_set_write_callback(h,OutAdlib);
 }
 else MIDI_Open();
}

static void song_start(u8 sn)
{
 memset(&msg,0,sizeof(msg));
 memset(&ev,0,sizeof(hmp_event));

 if(!(hf=hmp_open(MUSIC[sn],MSIZE[sn],0xA009,1)))
 {
  printf("read failed\n");

  if(MusicMode)hmpopl_done(h);
  else MIDI_Close();

  return;
 }

 hmp_reset_tracks(hf);

 if(MusicMode)
 {
  hmpopl_start(h);

  //hmpopl_reset(h);
  opl_clear();
 }
 else MIDI_Clear();

 Delta=0;
 DeltaAbsolute=0;
}

static void mySDL_AudioCallback(void*, Uint8 *stream, int len) //аналог обработчика прерывания звуковой системы
{
 AUDIO_FLAG=0;

 if(TIMER_FLAG)
 {
  if(Delta>=MUSIC_Delta[MUSIC_NUMBER])
  {
   hmp_reset_tracks(hf);

   if(MusicMode)
   {
    //hmpopl_reset(h);
    opl_clear();
   }
   else MIDI_Clear();

   DeltaAbsolute=0;
   Delta=0;
  }

  MIXER((s16*)stream);

  DeltaAbsolute++;
  while(Delta<=DeltaAbsolute)song_step();
 }
 else memset(stream,0,len);

 AUDIO_FLAG=1;
}

void MY_OpenMusic(unsigned int a4)
{
 TIMER_FLAG=0;

 if(SDL_Init(SDL_INIT_AUDIO)<0)
 {
  printf("error!\n");
  exit(-1);
 }

 SDL_AudioSpec spec;
 SDL_AudioDeviceID dev;

 #ifdef __EMSCRIPTEN__

 spec.freq     = 32000;

 #else

 spec.freq     = 44100;               //частота семплирования

 #endif

 spec.format   = AUDIO_S16SYS;        //16 бит, знаковый
 spec.channels = 1;                   //1 канал
 spec.samples  = SB_SAMPLE;           //Fs/TEMPO
 spec.callback = mySDL_AudioCallback;
 spec.userdata = NULL;

 if(SDL_OpenAudio(&spec,NULL)<0)
 {
  printf("error!\n");
  exit(-1);
 }

 #ifdef _DBOPL_

 if(MusicMode)opl.Init(spec.freq);

 #else

 if(MusicMode)OPL3_Reset(&opl,spec.freq);

 #endif

 song_init();

 SDL_PauseAudio(0); //включение кольцевого буфера
}

void MY_FreeMusic(void)
{
 TIMER_FLAG=0;

 SDL_PauseAudio(1); //выключение кольцевого буфера

 SDL_CloseAudio();

 if(hf)
 {
  hmp_close(hf);
  hf=NULL;
 }

 if(MusicMode)
 {
  //hmpopl_reset(h);
  opl_clear();

  hmpopl_done(h);
 }
 else
 {
  MIDI_Clear();
  MIDI_Close();
 }

 if(INST)free(INST);
 if(DRUM)free(DRUM);
 if(MUSIC_Base)free(MUSIC_Base);
}

void MY_StartMusic(short a1, unsigned char a2)
{
 if(((a1-1)==MUSIC_NUMBER)&&TIMER_FLAG)return;

 MY_StopMusic();

 if(!TIMER_FLAG)
 {
  MUSIC_NUMBER=a1-1;
  song_start(MUSIC_NUMBER);
  TIMER_FLAG=1;
 }
}

void MY_StopMusic(void)
{
 if(TIMER_FLAG)
 {
  while(!AUDIO_FLAG); //prevent broken audio callback
  AUDIO_FLAG=0;

  TIMER_FLAG=0;

  if(hf)
  {
   hmp_close(hf);
   hf=NULL;
  }

  if(MusicMode)
  {
   //hmpopl_reset(h);
   opl_clear();
  }
  else MIDI_Clear();

 }
}

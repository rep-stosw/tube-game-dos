#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SB16.H"

#include "HMP.H"

#include "Type.h"

#include "defs.h"
#include "misc.h"

#if defined(_OPL3_)

#include "opl3.h"

#elif defined(_DBOPL_)

#include "dbopl.h"

#else

#include "fmopl.h"

#endif

#ifdef _DBOPL_

extern DBOPL::Handler opl;

#else

extern opl3_chip opl;

#endif

#define NS 15 /* число семплов в игре */

#define NUM_SOUND_CHANNELS (NS*2) /* 15 семплов * 2 игрока = 30 каналов */

static IO u8     Voice_Play[NUM_SOUND_CHANNELS];
static    u32    Voice_Size[NUM_SOUND_CHANNELS];
static IO double Voice_Position[NUM_SOUND_CHANNELS]; //дробная позиция для переменного питча
static    u8     Voice_Loop[NUM_SOUND_CHANNELS];
static    u8    *Voice_Data[NUM_SOUND_CHANNELS];
static   s16     Voice_Volume[NUM_SOUND_CHANNELS];
static    u8     Voice_Pitch[NUM_SOUND_CHANNELS];

static void FreeChannel(u32 channel)
{
 Voice_Play[channel]=0;
 Voice_Size[channel]=0;
 Voice_Position[channel]=0.0;
 Voice_Loop[channel]=0;
 Voice_Volume[channel]=0x7FFF;
 Voice_Pitch[channel]=0x64;
}

static void SB_Prepare(void)
{
 for(int i=0;i<NUM_SOUND_CHANNELS;i++)FreeChannel(i);
}

static void SB_Load(u8* Data,u32 Size,unsigned char channel)
{
 Voice_Play[channel]=0;         //for IRQ
 Voice_Position[channel]=0.0;   //принудительно !!!
 Voice_Size[channel]=Size;
 Voice_Data[channel]=Data;
}

static void SB_Play(u8 Loop, unsigned char channel)
{
 Voice_Play[channel]=1;
 Voice_Loop[channel]=Loop;
}

static s32 MIX_BUFFER[SB_SAMPLE];

#ifdef _DBOPL_

static void StereoAudio(unsigned long count, int *samples)
{
 for(u32 i=0;i<count<<1;i+=2)MIX_BUFFER[i>>1]+=samples[i]+samples[i|1]; //подмешиваем музыку, громкость увеличена в 2 раза
}

#endif

void MIXER(s16 *stream) //mixer: pitch, volume, loop
{
 //Clear
 memset(MIX_BUFFER,0,sizeof(MIX_BUFFER));

 //SB
 for(u32 j=0;j<NUM_SOUND_CHANNELS;j++)
 {
  if(Voice_Play[j]&&Voice_Data[j])for(u32 i=0;i<SB_SAMPLE;i++)
  {
   MIX_BUFFER[i]+=(((((s16)Voice_Data[j][(int)Voice_Position[j]])*257)-32768)*Voice_Volume[j])/0x7FFF; //0..255 => -32768..+32767 * Volume / VolumeMax

   Voice_Position[j]+=((double)Voice_Pitch[j])*(((double)22050)/((double)(100*FS)));

   if((int)Voice_Position[j]>=(int)Voice_Size[j])
   {
    if(Voice_Loop[j])Voice_Position[j]=0.0;
    else
    {
     Voice_Play[j]=0;
     break;
    }
   }
  }
 }

 //Adlib
 if(MusicMode)
 {
  #ifdef _DBOPL_

  opl.Generate(NULL,StereoAudio,SB_SAMPLE);

  #else

  OPL3_GenerateStream(&opl,MIX_BUFFER,SB_SAMPLE);

  #endif
 }

 //Clamp
 for(u32 i=0;i<SB_SAMPLE;i++)
 {
       if(MIX_BUFFER[i]<-32768)stream[i]=-32768;
  else if(MIX_BUFFER[i]> 32767)stream[i]= 32767;
  else                         stream[i]=MIX_BUFFER[i];
 }

}

//static char SAMPLE_name[NS][16]={0};
static u32 SAMPLE_offset[NS];
static u32 SAMPLE_size[NS];
static char *SAMPLE_Base=NULL;

void MY_OpenSound(void)
{
 char b[16];

 FILE *f=fopen("SOUND/S822-0.TAB","rb");

 fread(b,1,16,f); //пропускаем первые 32 байта
 fread(b,1,16,f);

 for(int n=0;n<NS;n++) //начитываем оффсеты и размеры семплов
 {
  fread(b,1,16,f);
//strcpy(SAMPLE_name[n],b); //имя семпла

  fread(b,1,16,f);
  SAMPLE_offset[n]=*(UA<u32>*)&b[0x2]; //смещение семпла
  SAMPLE_size[n]=*(UA<u32>*)&b[0xA];   //размер семпла

  SAMPLE_size[n]-=16; //корректируем размер семпла: уменьшаем на 16(последние 16 отсчётов - мусор, ведущий к щелчку)
 }

 fclose(f);

 f=fopen("SOUND/S822-0.DAT","rb"); //начитываем семплы
 u32 s=FileSize(f);
 SAMPLE_Base=(char*)malloc(s);
 fread(SAMPLE_Base,1,s,f);
 fclose(f);

 SB_Prepare(); //чистим буфера
}

void MY_FreeSound(void)
{
 if(SAMPLE_Base)free(SAMPLE_Base);
}

//a1 - игрок(0..1), a2 - семпл/канал(1..15), a3 - громкость(0..0x7FFF), a4 - ?, a5 - питч(0x64 = 100%), a6 - зацикливание(-1..0), a7 - ?
void MY_PlaySample(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, signed int a6, unsigned int a7)
{
 a2--;

 u8 ch=(a1*NS)+a2; //номер канала: 0..14 - первый игрок, 15..29 - второй игрок

 if((a6==-1)&&(Voice_Loop[ch]==1))return;  //если зацикливание и канал уже играет, то выход

 Voice_Volume[ch]=a3; //громкость

 Voice_Pitch[ch]=a5; //питч

 SB_Load((u8*)((u32)SAMPLE_Base+SAMPLE_offset[a2]),SAMPLE_size[a2],ch); //загрузка данных

 SB_Play((a6==-1)?1:0, ch); //loop, channel запуск канала звука
}

//a1 - игрок, a2 - семпл/канал, a3 - громкость, a4 - ?
void MY_FadeOutSample(short a1, short a2, short a3, short a4)
{
 u8 ch=(a1*NS)+(a2-1); //номер канала

 Voice_Volume[ch]=a3; //громкость

 if(a3==0)
 {
  Voice_Play[ch]=0; //если громкость = 0, то выключить звук
  Voice_Loop[ch]=0; //и отключить зацикливание
  return;
 }
}

//a1 - игрок, a2 -семпл/канал, a3 - громкость, a4 - ?
void MY_FadeInSample(short a1, short a2, short a3, short a4)
{
 a2--;

 u8 ch=(a1*NS)+a2; //номер канала

 Voice_Volume[ch]=a3; //громкость

 SB_Load((u8*)((u32)SAMPLE_Base+SAMPLE_offset[a2]),SAMPLE_size[a2],ch); //загрузка данных

 SB_Play(0,ch); //loop=0, channel запуск канала звука
}

//a1 - игрок, a2 - семпл/канал, a3 - питч
void MY_SetSamplePitch(short a1, short a2, short a3)
{
 u8 ch=(a1*NS)+(a2-1); //номер канала

 Voice_Pitch[ch]=a3; //питч
}

void MY_SetSamplePan(short a1, short a2, unsigned short a3) //ничего не делает
{
}


#if defined(__linux__) || defined(__EMSCRIPTEN__)

#include <unistd.h>
#include <fcntl.h>

int fmidi=-1;

#else

#include <windows.h>
#include <mmsystem.h>

HMIDISTRM mpu_stream=0;

#endif

static void OutMIDI(u32 Data)
{
 #if defined(__linux__) || defined(__EMSCRIPTEN__)

 write(fmidi,&Data,3);

 #else

 midiOutShortMsg((HMIDIOUT)mpu_stream,Data);

 #endif
}

static void MIDI_Clear(void) //Очистка MPU401
{
 for(int i=0;i<16;i++)
 {
  OutMIDI((0xB0|i)|(0x7B<<8)|(0x00<<16));
  OutMIDI((0xB0|i)|(0x78<<8)|(0x00<<16));
  OutMIDI((0xB0|i)|(0x79<<8)|(0x00<<16));
 }
}

static void MIDI_Open(void)
{
 #if defined(__linux__) || defined(__EMSCRIPTEN__)

 fmidi=open("/dev/snd/midiC2D0",O_WRONLY);
 if(fmidi<0)
 {
  printf("error!\n");
  exit(-1);
 }

 #else

 UINT mpu_device=MIDI_MAPPER;
 if(midiStreamOpen(&mpu_stream,&mpu_device,1,(DWORD_PTR)NULL,(DWORD_PTR)NULL,CALLBACK_NULL))
 {
  printf("error!\n");
  exit(-1);
 }

 MIDI_Clear();

 #endif
}

static void MIDI_Close(void)
{
 MIDI_Clear();

 #if defined(__linux__) || defined(__EMSCRIPTEN__)

 close(fmidi);

 #else

 midiStreamClose(mpu_stream);

 #endif
}


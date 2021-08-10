#ifndef _SB16_H_
#define _SB16_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Type.h"

#ifdef __EMSCRIPTEN__

#define SB_SAMPLE 256 /* обязательно степень двойки */

#else

#define SB_SAMPLE 368 /* такая длина буфера выбрана, чтобы обеспечить синхронизацию MIDI: Fs/TEMPO = 44100/120 */

#endif

void MIXER(s16 *stream);

void MY_OpenSound(void);
void MY_FreeSound(void);
void MY_PlaySample(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, signed int a6, unsigned int a7);
void MY_FadeOutSample(short a1, short a2, short a3, short a4);
void MY_FadeInSample(short a1, short a2, short a3, short a4);
void MY_SetSamplePitch(short a1, short a2, short a3);
void MY_SetSamplePan(short a1, short a2, unsigned short a3);

#ifdef __cplusplus
}
#endif

#endif


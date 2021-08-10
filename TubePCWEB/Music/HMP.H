#ifndef _HMP_H_
#define _HMP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Type.h"

extern u8 MusicMode;

void MY_OpenMusic(unsigned int a4);
void MY_FreeMusic(void);
void MY_StartMusic(short a1, unsigned char a2);
void MY_StopMusic(void);

#ifdef __cplusplus
}
#endif

#endif

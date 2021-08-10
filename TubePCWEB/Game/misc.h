#ifndef _LOW_LEVEL_H_
#define _LOW_LEVEL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#include "Type.h"

#if defined(__linux__) || defined(__EMSCRIPTEN__)

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

#endif

/*
__attribute__((may_alias, aligned(1))), to tell the compiler the type is under-aligned as well as possibly aliasing. 
example: typedef int __attribute__((may_alias, aligned(1))) unaligned_int;
*/
typedef int          __attribute__((may_alias,aligned(1)))    intNA;
typedef unsigned int __attribute__((may_alias,aligned(1))) _DWORDNA;
typedef unsigned int __attribute__((may_alias,aligned(1)))    u32NA;

//#define intNA         int
//#define _DWORDNA      _DWORD
//#define u32NA         u32

#define _WORDNA       _WORD
#define __int16NA     __int16

/*
bit shifts left
*/
#define SHL6    * (1<< 6) /*<<  6*/
#define SHL8    * (1<< 8) /*<<  8*/
#define SHL16   * (1<<16) /*<< 16*/
#define OSHL8   *=(1<< 8) /*<<= 8*/
#define OSHL16  *=(1<<16) /*<<=16*/

extern u32 DSEG3;
extern u32 DSEG4;

void LoadDSEG(void);
void FreeDSEG(void);

u32 FileSize(FILE *f);

#ifdef __cplusplus
}
#endif

#endif

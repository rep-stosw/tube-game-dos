/*

   This file contains definitions used in the Hex-Rays decompiler output.
   It has type definitions and convenience macros to make the
   output more readable.

   Copyright (c) 2007-2020 Hex-Rays

*/

#ifndef HEXRAYS_DEFS_H
#define HEXRAYS_DEFS_H

static inline char __CFSHL__(int x,char y) //флаг переноса при сдвиге влево
{
 if((((unsigned)x)&0x80000000)&&y)return 1;
 return 0;

/*
 _asm
 {
  mov	eax,x
  mov	cl,y
  shl	eax,cl
  jnc	END
  mov	r,1
  END:
 }
 return r;
*/

}

typedef long long             int64;
typedef signed long long      sint64;
typedef unsigned long long    uint64;

typedef          char   int8;
typedef   signed char   sint8;
typedef unsigned char   uint8;
typedef          short  int16;
typedef   signed short  sint16;
typedef unsigned short  uint16;
typedef          int    int32;
typedef   signed int    sint32;
typedef unsigned int    uint32;

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

typedef int8 _BOOL1;
typedef int16 _BOOL2;
typedef int32 _BOOL4;
//typedef int64 _BOOL8;

#define _BYTE  uint8
#define _WORD  uint16
#define _DWORD uint32
#define _QWORD uint64

#define BYTEn(x, n)   (*((_BYTE*)&(x)+n))
#define WORDn(x, n)   (*((_WORD*)&(x)+n))
#define DWORDn(x, n)  (*((_DWORD*)&(x)+n))

#define LAST_IND(x,part_type)    (sizeof(x)/sizeof(part_type) - 1)

#define HIGH_IND(x,part_type)  LAST_IND(x,part_type)
#define LOW_IND(x,part_type)   0

#define LOBYTE(x)  BYTEn(x,LOW_IND(x,_BYTE))
#define LOWORD(x)  WORDn(x,LOW_IND(x,_WORD))
#define LODWORD(x) DWORDn(x,LOW_IND(x,_DWORD))
#define HIBYTE(x)  BYTEn(x,HIGH_IND(x,_BYTE))
#define HIWORD(x)  WORDn(x,HIGH_IND(x,_WORD))
#define HIDWORD(x) DWORDn(x,HIGH_IND(x,_DWORD))

#define BYTE1(x)   BYTEn(x,  1)         // byte 1 (counting from 0)
#define BYTE2(x)   BYTEn(x,  2)
#define BYTE3(x)   BYTEn(x,  3)
#define BYTE4(x)   BYTEn(x,  4)
#define BYTE5(x)   BYTEn(x,  5)
#define BYTE6(x)   BYTEn(x,  6)
#define BYTE7(x)   BYTEn(x,  7)
#define BYTE8(x)   BYTEn(x,  8)
#define BYTE9(x)   BYTEn(x,  9)
#define BYTE10(x)  BYTEn(x, 10)
#define BYTE11(x)  BYTEn(x, 11)
#define BYTE12(x)  BYTEn(x, 12)
#define BYTE13(x)  BYTEn(x, 13)
#define BYTE14(x)  BYTEn(x, 14)
#define BYTE15(x)  BYTEn(x, 15)
#define WORD1(x)   WORDn(x,  1)
#define WORD2(x)   WORDn(x,  2)         // third word of the object, unsigned
#define WORD3(x)   WORDn(x,  3)
#define WORD4(x)   WORDn(x,  4)
#define WORD5(x)   WORDn(x,  5)
#define WORD6(x)   WORDn(x,  6)
#define WORD7(x)   WORDn(x,  7)

// Generate a pair of operands. S stands for 'signed'
#define __SPAIR16__(high, low)  (((int16)  (high) <<  8) | (uint8) (low))
#define __SPAIR32__(high, low)  (((int32)  (high) << 16) | (uint16)(low))
#define __SPAIR64__(high, low)  (((int64)  (high) << 32) | (uint32)(low))
#define __SPAIR128__(high, low) (((int128) (high) << 64) | (uint64)(low))
#define __PAIR16__(high, low)   (((uint16) (high) <<  8) | (uint8) (low))
#define __PAIR32__(high, low)   (((uint32) (high) << 16) | (uint16)(low))
#define __PAIR64__(high, low)   (((uint64) (high) << 32) | (uint32)(low))
#define __PAIR128__(high, low)  (((uint128)(high) << 64) | (uint64)(low))

// sign flag
template<class T> int8 __SETS__(T x)
{
  if ( sizeof(T) == 1 )
    return int8(x) < 0;
  if ( sizeof(T) == 2 )
    return int16(x) < 0;
  if ( sizeof(T) == 4 )
    return int32(x) < 0;
  return int64(x) < 0;
}

// overflow flag of addition (x+y)
template<class T, class U> int8 __OFADD__(T x, U y)
{
  if ( sizeof(T) < sizeof(U) )
  {
    U x2 = x;
    int8 sx = __SETS__(x2);
    return ((1 ^ sx) ^ __SETS__(y)) & (sx ^ __SETS__(U(x2+y)));
  }
  else
  {
    T y2 = y;
    int8 sx = __SETS__(x);
    return ((1 ^ sx) ^ __SETS__(y2)) & (sx ^ __SETS__(T(x+y2)));
  }
}

// rotate left
template<class T> T __ROL__(T value, int count)
{
  const uint nbits = sizeof(T) * 8;

  if ( count > 0 )
  {
    count %= nbits;
    T high = value >> (nbits - count);
    if ( T(-1) < 0 ) // signed value
      high &= ~((T(-1) << count));
    value <<= count;
    value |= high;
  }
  else
  {
    count = -count % nbits;
    T low = value << (nbits - count);
    value >>= count;
    value |= low;
  }
  return value;
}

inline uint8  __ROL1__(uint8  value, int count) { return __ROL__((uint8)value, count); }
inline uint16 __ROL2__(uint16 value, int count) { return __ROL__((uint16)value, count); }
inline uint32 __ROL4__(uint32 value, int count) { return __ROL__((uint32)value, count); }
//inline uint64 __ROL8__(uint64 value, int count) { return __ROL__((uint64)value, count); }
inline uint8  __ROR1__(uint8  value, int count) { return __ROL__((uint8)value, -count); }
inline uint16 __ROR2__(uint16 value, int count) { return __ROL__((uint16)value, -count); }
inline uint32 __ROR4__(uint32 value, int count) { return __ROL__((uint32)value, -count); }
//inline uint64 __ROR8__(uint64 value, int count) { return __ROL__((uint64)value, -count); }

// carry flag of addition (x+y)
template<class T, class U> int8 __CFADD__(T x, U y)
{
  int size = sizeof(T) > sizeof(U) ? sizeof(T) : sizeof(U);
  if ( size == 1 )
    return uint8(x) > uint8(x+y);
  if ( size == 2 )
    return uint16(x) > uint16(x+y);
  if ( size == 4 )
    return uint32(x) > uint32(x+y);
  return uint64(x) > uint64(x+y);
}

// overflow flag of subtraction (x-y)
template<class T, class U> int8 __OFSUB__(T x, U y)
{
  if ( sizeof(T) < sizeof(U) )
  {
    U x2 = x;
    int8 sx = __SETS__(x2);
    return (sx ^ __SETS__(y)) & (sx ^ __SETS__(U(x2-y)));
  }
  else
  {
    T y2 = y;
    int8 sx = __SETS__(x);
    return (sx ^ __SETS__(y2)) & (sx ^ __SETS__(T(x-y2)));
  }
}

#include <stddef.h> // for size_t

// memcpy() with determined behavoir: it always copies
// from the start to the end of the buffer
// note: it copies byte by byte, so it is not equivalent to, for example, rep movsd
inline void *qmemcpy(void *dst, const void *src, size_t cnt)
{
  char *out = (char *)dst;
  const char *in = (const char *)src;
  while ( cnt > 0 )
  {
    *out++ = *in++;
    --cnt;
  }
  return dst;
}

#endif // HEXRAYS_DEFS_H

# Tube
My first reverse engineering game.

Tube is a little known game from Bullfrog developed for M$ DOS, released in 1994.

I was able to recreate the source code of this game using the Hex-rays decompiler and the IDA Pro disassembler.
In addition, of course, I used a set of my own programs and scripts!

For final debugging, I used the GDB debugger and the ASAN and UBSAN sanitizers for Linux.

The game is currently compiled by the following toolchains:

1. MinGW32 (Windows)
2. GCC (Linux)
3. Emscripten (Web)
4. OpenWatcom 1.9 (DOS DPMI)

Please keep in mind that this game will only work on 32-bit platforms! It won't work on 64-bit ones, because of 32-bit pointers in the game code.

The unaligned data access is done through "packed" pointers and can be redesigned for a different compiler that supports directives for handling unaligned data.

HOW TO COMPILE:

1. for Windows (only 32 bit mode) - run build_windows.bat
2. for Linux (only 32 bit mode) - run build_linux.sh
3. for Web - run build_web.bat

The "bin" directory contains compiled programs.

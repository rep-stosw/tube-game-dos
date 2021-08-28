![1](https://user-images.githubusercontent.com/88702500/128820449-94b8fe0d-296d-4232-a6eb-2eba36968028.png)
![2](https://user-images.githubusercontent.com/88702500/128820980-07c0d238-edba-4681-8c02-4eb6ea317a98.png)

# Tube

My first reverse engineering game.

Last update: 28.08.2021

https://www.youtube.com/watch?v=dgaLhOj14e8

Tube is a little known game from Bullfrog developed for M$ DOS, released in 1994.

I was able to recreate the source code of this game using the Hex-rays decompiler and the IDA Pro disassembler.

In addition, of course, I used a set of my own programs and scripts!

For final debugging, I used the GDB debugger and the ASAN and UBSAN sanitizers for Linux.

The game is currently compiled by the following toolchains:

1. MinGW32 (Windows)
2. GCC (Linux)
3. Emscripten (Web)
4. OpenWatcom 1.9 (DOS DPMI)
5. ARM GCC (Cortex-A7 Allwinner V3s) - https://www.youtube.com/watch?v=9L44_1E7QJg
6. TI CGT C6x (DSP TMS320C6745) - https://www.youtube.com/watch?v=ejwfzwd2_3A

Fully cross-platform, SDL2 is used.

This program will not work on 64-bit architectures due to 32-bit pointers in the game code, 32-bit typecasts and a specific memory manager.

For 64-bit please, see my new project Tube64: https://github.com/rep-stosw/tube64

The unaligned data access and alias pointers were fixed via C++ operators overloading and special data type creation.

So rejoice, the program will work on architectures that hate unaligned data!

Even the most aggressive optimization doesn't break the program! Because this program follows strict aliasing rules!

HOW TO COMPILE:

1. for Windows (only 32 bit mode) - run build_windows.bat
2. for Linux (only 32 bit mode) - run build_linux.sh
3. for Web - run build_web.bat

The "bin" directory contains compiled programs.

Play game in browser: https://clobberasm.itch.io/tube

Tech discussion: https://gamedev.ru/flame/forum/?id=262348&page=8&m=5430353#m119

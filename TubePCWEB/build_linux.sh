#!/bin/bash

#if false; then

rm -f *.o
rm -f *.map
rm -f bin/tube
clear

echo 'Complie tube...'

g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -DNDEBUG -Wno-unused-result -c Game/tube.cpp   -IGame -IMusic -ISound -fsigned-char -fmax-errors=1
g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -DNDEBUG -Wno-unused-result -c Game/trig.cpp   -IGame -IMusic -ISound
g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -DNDEBUG -Wno-unused-result -c Game/misc.cpp   -IGame -IMusic -ISound

g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -DNDEBUG -D_OPL3_ -Wno-unused-result -c Sound/SB16.cpp -IGame -IMusic -ISound
g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -DNDEBUG -D_OPL3_ -Wno-unused-result -c Music/HMP.cpp  -IGame -IMusic -ISound

gcc -m32 -Ofast -fomit-frame-pointer -ffast-math           -fno-exceptions -DNDEBUG -Wno-unused-result -c Music/hmpfile.c -IGame -IMusic -ISound
gcc -m32 -Ofast -fomit-frame-pointer -ffast-math           -fno-exceptions -DNDEBUG -Wno-unused-result -c Music/hmpopl.c  -IGame -IMusic -ISound

gcc -m32 -Ofast -fomit-frame-pointer -ffast-math           -fno-exceptions -DNDEBUG -Wno-unused-result -c Music/opl3.c -o opl.o -IGame -IMusic -ISound

#fi

echo 'Link tube...'

g++ -m32 -o bin/tube tube.o trig.o misc.o SB16.o HMP.o hmpfile.o hmpopl.o opl.o -static-libstdc++ -static-libgcc -lSDL2 -lasound -Xlinker -Map=tube.map -Wl,--strip-all

chmod +x bin/tube


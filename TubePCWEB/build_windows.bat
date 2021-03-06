::goto LINK

@echo Clear...

del bin\tube.exe
del *.o
del *.map
cls

:COMPILE

@echo Compile...

g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fno-builtin -ftree-vectorize -fno-math-errno -fno-unwind-tables -fno-asynchronous-unwind-tables -DNDEBUG -Wno-unused-result -c Game/tube.cpp -IGame -IMusic -ISound -fsigned-char -fmax-errors=1
g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fno-builtin -ftree-vectorize -fno-math-errno -fno-unwind-tables -fno-asynchronous-unwind-tables -DNDEBUG -Wno-unused-result -c Game/trig.cpp -IGame -IMusic -ISound
g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fno-builtin -ftree-vectorize -fno-math-errno -fno-unwind-tables -fno-asynchronous-unwind-tables -DNDEBUG -Wno-unused-result -c Game/misc.cpp -IGame -IMusic -ISound

g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fno-builtin -ftree-vectorize -fno-math-errno -fno-unwind-tables -fno-asynchronous-unwind-tables -DNDEBUG -D_OPL3_ -Wno-unused-result -c Sound/SB16.cpp -IGame -IMusic -ISound
g++ -m32 -Ofast -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fno-builtin -ftree-vectorize -fno-math-errno -fno-unwind-tables -fno-asynchronous-unwind-tables -DNDEBUG -D_OPL3_ -Wno-unused-result -c Music/HMP.cpp  -IGame -IMusic -ISound

gcc -m32 -Ofast -fomit-frame-pointer -ffast-math           -fno-exceptions -fno-builtin -ftree-vectorize -fno-math-errno -fno-unwind-tables -fno-asynchronous-unwind-tables -DNDEBUG -Wno-unused-result -c Music/hmpfile.c -IGame -IMusic -ISound
gcc -m32 -Ofast -fomit-frame-pointer -ffast-math           -fno-exceptions -fno-builtin -ftree-vectorize -fno-math-errno -fno-unwind-tables -fno-asynchronous-unwind-tables -DNDEBUG -Wno-unused-result -c Music/hmpopl.c  -IGame -IMusic -ISound

gcc -m32 -Ofast -fomit-frame-pointer -ffast-math           -fno-exceptions -fno-builtin -ftree-vectorize -fno-math-errno -fno-unwind-tables -fno-asynchronous-unwind-tables -DNDEBUG -Wno-unused-result -c Music/opl3.c -o opl.o -IGame -IMusic -ISound

:LINK

@echo Link...

g++ -m32 -o bin/tube.exe tube.o trig.o misc.o SB16.o HMP.o hmpfile.o hmpopl.o opl.o -static-libstdc++ -static-libgcc -lwinmm -lmingw32 -lSDL2main -lSDL2 -mwindows -Xlinker -Map=tube.map -Wl,--strip-all

pause
exit

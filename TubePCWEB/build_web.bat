@echo off

cls

::goto LINK

::FMOPL(fast, but poor) DBOPL(compromise) OPL3(slow, but accuracy)
set ADLIB=DBOPL

echo %ADLIB% selected

echo Clear...

if exist *.o del *.o
if exist bin\index.js del bin\index.js
if exist bin\index.wasm del bin\index.wasm
if exist bin\index.data del bin\index.data

if exist asset goto COMPILE

echo Asset...

::if exist asset rmdir /s /q asset
mkdir asset
copy bin\tube.cfg asset\tube.cfg > nul
copy bin\DSEG3.bin asset\DSEG3.bin > nul
copy bin\DSEG4.bin asset\DSEG4.bin > nul
echo D | xcopy bin\DATA asset\DATA > nul
echo D | xcopy bin\SOUND\*.TAB asset\SOUND\*.TAB > nul
echo D | xcopy bin\SOUND\*.BNK asset\SOUND\*.BNK > nul
echo D | xcopy bin\SOUND\*.DAT asset\SOUND\*.DAT > nul

:COMPILE

echo Compile...

call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -c Game/tube.cpp -IGame -IMusic -ISound -fsigned-char
call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -c Game/trig.cpp -IGame -IMusic -ISound
call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -c Game/misc.c   -IGame -IMusic -ISound

call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -D_%ADLIB%_ -c Sound/SB16.C -IGame -IMusic -ISound
call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -D_%ADLIB%_ -c Music/HMP.C  -IGame -IMusic -ISound

call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -c Music/hmpfile.c -IGame -IMusic -ISound
call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -c Music/hmpopl.c  -IGame -IMusic -ISound

if "%ADLIB%" == "FMOPL" ( call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -c Music/fmopl.c   -o opl.o -IGame -IMusic -ISound )
if "%ADLIB%" == "DBOPL" ( call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -c Music/dbopl.cpp -o opl.o -IGame -IMusic -ISound )
if "%ADLIB%" == "OPL3"  ( call emcc -O3 -fomit-frame-pointer -ffast-math -fno-rtti -fno-exceptions -fpermissive -fdata-sections -ffunction-sections -DNDEBUG -c Music/opl3.c    -o opl.o -IGame -IMusic -ISound )

:LINK

echo Link...

emcc tube.o trig.o misc.o SB16.o HMP.o hmpfile.o hmpopl.o opl.o -s WASM=1 -s USE_SDL=2 -s ALLOW_MEMORY_GROWTH=1 -s ASYNCIFY -o bin/index.js --no-heap-copy --preload-file asset@ -Wl,--gc-sections -Wl,--strip-all

:END

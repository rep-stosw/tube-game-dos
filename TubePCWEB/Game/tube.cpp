#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <SDL2/SDL.h>

#include "Type.h"

#include "misc.h"

#include "DSEG3.h" //Game Data Segments: variables, arrays, pointers,...
#include "DSEG4.h"

#include "defs.h"

#include "HMP.H"  //Music
#include "SB16.H" //Sound

#include "in_al_60h.c" //keyboard scancodes

#ifdef __EMSCRIPTEN__

#include <emscripten.h>

#endif

#if defined(__linux__) || defined(__EMSCRIPTEN__)

#include <termios.h>
#include <unistd.h>

#define stricmp strcasecmp

int getch(void) //reads from keypress, doesn't echo
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void fixfilename(char *d,const char *s)
{
 memset(d,0,strlen(s)+1);
 for(u32 i=0;i<strlen(s);i++)d[i]=toupper(s[i]);
 for(u32 i=0;i<strlen(d);i++)if(d[i]=='\\')d[i]='/';
}

#else

#include <conio.h>

#endif

int main(int argc, char *argv[]);								//OK
int CPP_setup_game(void);									//OK
void CPP_game(void);										//OK
void CPP_LoadAllData(int a2);									//OK
void CPP_load_all_tmaps(void);									//OK
void CPP_load_all_3d_files(void);								//OK
void CPP_setup_host(void);									//OK
char CPP_FindColor(u8 *a1, u8 a2, u8 a3, u8 a4);	//OK
void CPP_InitMusic(void);									//OK
void CPP_InitSound(void);									//OK
void CPP_calibrate_digistick(void);								//OK
void CPP_setup_a_sprite(unsigned int a1, unsigned int a2, unsigned int a3);			//OK
void CPP_fill_stack(void);									//?
int CPP_MyAlloc(int a2);									//OK
void CPP_SetupMemory(void);									//OK
int CPP_MyLowAlloc(int a2);									//OK
int *CPP_CheckMemory(void);									//OK
char CPP_split_arena(int a1, int a2);								//OK
int CPP_LoadData(int a3);									//OK
int *CPP_FreeData(int a1);									//OK
int *CPP_MyFree(int a1);									//OK
int CPP_LoadFileAt(const char *a1, char *a2);							//OK
int CPP_RncFileLength(int a1);									//OK
int CPP_MyOpen(int a1, int a2);									//OK
int CPP_MyRead(int a1, int a2, int a3);							//OK
int CPP_MyClose(int a1);								//OK
int CPP_UnpackM1(int a1, char *a2);							//NOT USED
int CPP_delete_arena(int a1);								//OK
void CPP_setup_vecs(int a1, int a2, int a3, int a4, int a5);				//OK
void CPP_SetupScreenMCGA(u8 *a1);						//OK SDL2
void CPP_SetGraphicsWindow(i16 a1, i16 a2, i16 a3, i16 a4);      	//OK
void CPP_SetPalette256(u8 *a1);						//OK SDL2
void CPP_GetPalette256(u8 *a1);						//OK SDL2
void CPP_WaitVbi(void);									//OK SDL2
i16 CPP_FadePalette256(u8 *a1, u8 a2, char a3);		//OK

unsigned int CPP_load_game(void);						//OK
int CPP_init_tube(void);							//OK
int CPP_setup_stuff(void);							//OK
int CPP_SaveFileAt(int a1, int a2, int a3);				//OK
int CPP_MyWrite(int a1, int a2, int a3);				//OK
void CPP_make_fade_table(u8 *A2, u8 *A3, signed char a4, signed char a5, signed char a6, short a7, short a8, short a9); //OK Snowman
int CPP_clear_tube(void);							//OK
char CPP_setup_tube_graphics(int a1);					//OK
int CPP_find_distant(void);							//OK
int CPP_tunnel_table(void);							//OK
int CPP_setup_high_scores(void);						//OK
int CPP_set_scroll(int a1);						//OK
void CPP_setup_addresses(void);						//OK
int CPP_check_anim(u16 a1, u16 *a2);		//OK
char CPP_control_game(void);						//OK
void CPP_read_digistick(void);						//OK
int CPP_game_over(u8 a1);					//OK
int CPP_do_ships(void);							//OK
int CPP_do_players_ships(void);						//OK
u8 CPP_do_bullets(void);					//OK
int CPP_enter_ships(u8 a1);				//OK
int CPP_quick_sort_ships(int a1, i16 a2);				//OK
char CPP_change_hit_block(u8 a1, u16 a2, u16 a3); //OK
char CPP_draw_block(int a1, u16 a2);			//OK
int  CPP_do_tube(void);							//OK
int CPP_check_scroll_change(u8 a1);			//OK
char CPP_check_for_race_end(u8 a1);			//OK
char CPP_scroll_tube(char a1, u8 a2);			//OK
int CPP_delete_anims(u8 a1, unsigned int a2);		//OK
int CPP_add_anims(u8 a1, int a2, u16 a3);	//OK
int CPP_check_effects(u8 a1);				//OK
int CPP_remove_effect(u8 a1);				//OK
int CPP_add_alien(u8 a1, u8 a2, u8 a3, u8 a4);	//OK
int CPP_do_anims(u8 a1);									//OK
void CPP_do_death_sound(u8 a3, char a4);							//OK
int CPP_do_swamp_sounds(u8 a1);								//OK

_BOOL1 CPP_load_level(u8 a1);				//OK
int CPP_next_frames(void);						//OK
int CPP_draw_tube(void);						//OK
void CPP_omni_map(int a1, int a2, i16 a3);				//OK
int CPP_fade_zone(unsigned int a1, int a2, int a3, int a4);		//OK
int CPP_new_starfield(i16 a1, int a2);				//OK
int CPP_setup_anims(void);						//OK
char CPP_setup_tube(void);						//OK
u8 CPP_setup_ships(void);					//OK
int CPP_setup_bullets(void);						//OK
int CPP_setup_aliens(void);						//OK
u8 CPP_check_extra_life(void);						//OK
u8 CPP_draw_game(void);							//OK
int CPP_draw_ships(void);								//OK
u16 CPP_move_it(int a1, int a2, int a3, i16 a4, i16 a5, int a6);	//OK
int CPP_draw_success(void);								//OK
int CPP_draw_time_out(void);								//OK
int CPP_draw_winner(u8 a1);						//OK
int CPP_draw_loser(u8 a1);							//OK
int CPP_DrawASpriteMCGA(i16 a1, i16 a2, int a3);				//OK
void CPP_DrawSpriteVres256(i16 a1 /*dx*/ , int a2 /*ecx*/, int a3 /*ebx*/, char *a4 /*esi*/ , u8 a5, char a6);	//OK
int CPP_draw_level_no(u8 a1);						//OK
void CPP_DrawBoxBPP(int a1, int a2, int a3, int a4, char a5, char a6);			//OK
i16 CPP_draw_hiscore(void);								//OK
int CPP_high_tube(void);								//OK
int CPP_new_game(void);									//OK
int CPP_enter_scores(void);								//OK
void CPP_ClearScreenMCGA(void *a2, u16 a3, char a4);			//OK
char CPP_draw_enter_score(u8 a1, u8 a2);			//OK
unsigned int CPP_save_score(u8 a1, u8 a2, const char *a3);	//OK
int CPP_who_won(void);									//OK
unsigned int CPP_draw_the_winner(char a1);						//OK

char CPP_do_player_blk_collision(u8 a3, u8 *a4, u8 *a5, u8 *a6, u8 *a7);	//OK
i16 CPP_what_block(u8 a1, u16 a2, u16 a3);			//OK
char CPP_death_block(u16 a1);								//OK
char CPP_ice_block(u16 a1);								//OK
char CPP_solid_block(u16 a1);								//OK
char CPP_swamp_block(u16 a1);								//OK
char CPP_reverse_all(u16 a1);								//OK
char CPP_reverse_y(u16 a1);								//OK
char CPP_reverse_x(u16 a1);								//OK
u8 CPP_do_contact_blocks(void);								//OK
char CPP_change_block(u8 a1, u16 a2, u16 a3);			//OK
u16 *CPP_organise_blocks(u8 a1, u16 *a2, u16 *a3, u16 *a4, u16 *a5, u16 *a6, u16 *a7, u16 *a8, u16 *a9, u16 *a10, u16 *a11, u16 *a12, u16 *a13);	//OK
i16 CPP_arctan(int a1, int a2);									//OK
u8 CPP_do_aliens(void);									//OK
char CPP_check_alien_to_players(u8 a3, int a4);						//OK
char CPP_check_point_with_players(u8 a1, u16 a2, u16 a3, u16 a4, u16 a5, u16 a6, u16 a7);	//OK
int CPP_power_up(u8 a3);											//OK
int CPP_add_extra_life(u8 a3);										//OK
int CPP_lose_life(u8 a3);											//OK
char CPP_insert_effect(u16 a1, u16 a2, i16 a3);						//OK
char CPP_add_alien_at_pos(u8 a3, char a4, i16 a5, i16 a6, i16 a7, u16 a8);	//OK
char CPP_check_bullets_to_aliens(int a2);										//OK
u16 *CPP_organise_block(u8 a1, u16 *a2, u16 *a3);							//OK
int CPP_nearest_alien(u8 a1, u16 a2, u16 a3, u16 a4, u16 *a5, u16 *a6, u16 *a7);	//OK
i16 CPP_move_in_line(int a1, int a2, u16 a3, u16 a4);								//OK
int CPP_save_game(void);															//OK

//void CPP_OpenIKeyboard(void);									//OK not need for Win32
void /*interrupt far*/ CPP_KInt(void);								//OK SDL2
void CPP_reset_game(void);									//OK
void CPP_reset_host(void);									//OK
void CPP_ResetScreen(void);									//OK SDL2
void CPP_CloseKeyboard(void);									//OK
void CPP_ResetNetwork(void);									//OK
int *CPP_FreeAllData(int a1);									//OK
void CPP_ResetMemory(void);									//OK
extern void CPP_trig(int *a1, int *a2, int *a3);						//OK
char CPP_add_bullet(u8 a3);							//OK
char CPP_how_many_bullets(char a1, u8 a2);						//OK
int CPP_smart_bomb(u8 a3);								//OK
int CPP_count_swamp_anims(u8 a1);							//OK
int CPP_FindMusicType(int a1);									//OK

//int CPP_compare(const void *a, const void *b);						//OK not need for Win32
//int CPP_dos_free(int a1);									//OK not need for Win32
//int CPP_dos_alloc(unsigned int a1);								//OK not need for Win32

char aHighScoresNNjo[]="     HIGH SCORES/n/nJONTY.........1000000/nMARK...........100000/nGLENN...........10000/nSEAN.............1000/nDARREN...........1000/nRUSSELL...........100/nDANIEL.............10/nSIMON...............8/nALEX................6/nRICHARD.............0/n\0\x90";

int SCALE=1; //для масштабирования окна

void *GlobalHeap=NULL; //для аллокатора памяти

u8 Palette[256*3];         //эмуляция палитры VGA 6:6:6
u16 PAL16[256];            //сконверченная палитра в 16-битные цвета RGB 5:6:5

u16 VRAMBuffer[320*200]; //видеобуфер для SDL2

static SDL_Renderer *renderer=NULL;
static SDL_Window   *window  =NULL;
static SDL_Texture  *texture =NULL;

void ToScreen(void) //переброс видеобуфера игры в видеобуфер SDL2 с конверсией палитры и отправкой в окно
{
 for(int i=0;i<320*200;i++)VRAMBuffer[i]= /* ((u8*)WScreen)[i]; */ PAL16[((u8*)WScreen)[i]]; //Paletted 256 col. to Direct 64K col.

 SDL_RenderClear(renderer);
 SDL_UpdateTexture(texture,NULL,VRAMBuffer,320*2);
 SDL_RenderCopy(renderer,texture,NULL,NULL);
 SDL_RenderPresent(renderer);
}

//---------------------------------------------------------------------------------

void ReadConfig(void) //считывает конфигурацию из файла. Если файла нет, то дефолтная конфигурация
{
 FILE *f=fopen("tube.cfg","rt");
 if(!f)
 {
  printf("config error!\n");
  return;
 }

 char nanobuf[64];
 int tmp;         //ради совместимости используется размер int. Потому что fscanf() в short(%hx) и char(%hhx) может быть несовместим с другими компиляторами!

 memset(nanobuf,0,sizeof(nanobuf));
 fgets(nanobuf,sizeof(nanobuf),f);
 fscanf(f,"%d\n",&tmp);
 MusicMode=tmp;

 memset(nanobuf,0,sizeof(nanobuf));
 fgets(nanobuf,sizeof(nanobuf),f);
 fscanf(f,"%x\n",&tmp);
// MIDI=tmp;

 memset(nanobuf,0,sizeof(nanobuf));
 fgets(nanobuf,sizeof(nanobuf),f);
 fscanf(f,"%x\n",&tmp);
// ADLIB=tmp;

 memset(nanobuf,0,sizeof(nanobuf));
 fgets(nanobuf,sizeof(nanobuf),f);
 fscanf(f,"%x\n",&tmp);
// SB_IO=tmp;

 memset(nanobuf,0,sizeof(nanobuf));
 fgets(nanobuf,sizeof(nanobuf),f);
 fscanf(f,"%d\n",&tmp);
// SB_IRQ=tmp;

 memset(nanobuf,0,sizeof(nanobuf));
 fgets(nanobuf,sizeof(nanobuf),f);
 fscanf(f,"%d\n",&tmp);
// SB_DMA16=tmp;

 memset(nanobuf,0,sizeof(nanobuf));
 fgets(nanobuf,sizeof(nanobuf),f);
 fscanf(f,"%d\n",&tmp);
 SCALE=tmp;

 fclose(f);

 //printf("%d %x %x %x %d %d\n",MusicMode,MIDI,ADLIB,SB_IO,SB_IRQ,SB_DMA16);
 //while(1);
}

int main(int argc, char *argv[]) //FINAL
{
 #ifdef __EMSCRIPTEN__

 emscripten_run_script("var elem=document.getElementById('wait');elem.parentNode.removeChild(elem);setInterval(()=>window.focus(),2000);");

 #endif

 ReadConfig();
 LoadDSEG();   //загрузка сегментов данных игры

/*
  int v3; // edx
  i16 v4; // cx
  unsigned int *v5; // ebx
  int v6; // edi
  i16 v7; // si
  char v9[32]; // [esp+0h] [ebp-4Ch] BYREF
  char v10[32]; // [esp+20h] [ebp-2Ch] BYREF
  int i; // [esp+40h] [ebp-Ch]
  char v12; // [esp+48h] [ebp-4h]

  v12 = 1;
  for ( i = 1; (u16)argc > i; ++i )
  {
    if ( *argv[i] == 45 || *argv[i] == 47 )
    {
      strcpy(v10, argv[i] + 1);
      v9[0] = 0;
      v3 = i + 1;
      if ( i + 1 < (u16)argc )
        strcpy(v9, argv[i + 1]);
      if ( !stricmp(aTables, v10) )
      {
        tabgen = 1;
      }
      else if ( stricmp(aDebug, v10) )
      {
        printf("Unrecognised option : %s\n\n", v10);
        printf("The following options are available : \n");
        printf("-tables                           //table generation\n");
        printf("-debug                            //debugger option allowed\n");
        v12 = 0;
      }
    }
  }
  if ( v12 )
  {
*/
tabgen=0; //=1 отладка

    CPP_setup_game/*setup_game*/ (/*v3, v4, v6, v7*/);		//загрузка, инит ресурсов

    CPP_game(/*v5, v6*/);					//сама игра

    CPP_reset_game();						
    CPP_ResetMemory();
//  }

  FreeDSEG();

  SDL_Quit();

  return 0;
}

int CPP_setup_game(void) //FINAL
{
  int result; // eax
  glass_map = (int)byte_2A26BC;

  CPP_LoadAllData( (int)startup_files );

  CPP_load_all_tmaps();
  CPP_load_all_3d_files();
  CPP_setup_host();

  colour_lookup = CPP_FindColor((u8 *)palette, 0, 0, 0);
  byte_22EDA1 = CPP_FindColor((u8 *)palette, 0x3Fu, 0x3Fu, 0x3Fu);
  byte_22EDA2 = CPP_FindColor((u8 *)palette, 0x3Fu, 0, 0);
  byte_22EDA3 = CPP_FindColor((u8 *)palette, 0, 0x3Fu, 0);
  byte_22EDA4 = CPP_FindColor((u8 *)palette, 0, 0, 0x3Fu);
  byte_22EDA5 = CPP_FindColor((u8 *)palette, 0x3Fu, 0x3Fu, 0);
  byte_22EDA6 = CPP_FindColor((u8 *)palette, 0, 0x3Fu, 0x3Fu);
  byte_22EDA7 = CPP_FindColor((u8 *)palette, 0x3Fu, 0, 0x3Fu);

  CPP_InitSound();
  CPP_InitMusic();

  CPP_calibrate_digistick();
  CPP_setup_a_sprite(logo, logo_end, logo_data);
  CPP_fill_stack();
  level = CPP_MyAlloc(66136);
  result = level + 0x10000;
  effect_list = level + 0x10000;

  return result;
}

void CPP_game(void) //FINAL
{
//  u64 StartTime; //новая переменная для синхронизации

  int v2; // [esp+0h] [ebp-4h]
  //int v3; // [esp+0h] [ebp-4h]

  CPP_load_game();
  CPP_init_tube();
  CPP_setup_high_scores();
  CPP_setup_addresses();

  fading = 1;

  if ( file_error )
    printf("FILE ERROR");

  while ( !quit_game && !file_error )
  {
//  start_time = clock(/*v2*/ );
//  StartTime=RTC_Tick; //свой счётчик из обработчика прерывания таймера

    start_time=SDL_GetTicks();

    CPP_KInt(); //обработчик  клавиатуры

    CPP_control_game( /*a1, (unsigned int *)a2*/ );

    //LOBYTE(v3) = game_mode;

    switch ( game_mode )
    {
      case 0:			//стейт игры
        if ( !game_pause )
        {
          MY_StartMusic(1, 0x7Fu);
          CPP_do_ships(/*a1, (unsigned int *)a2*/);
          CPP_do_tube(/*(unsigned int *)a2*/);
          CPP_check_extra_life(/*(unsigned int *)a2*/);
          CPP_draw_game(/*(unsigned int *)a2*/);
        }
        break;
      case 2:
        MY_FadeOutSample(0, 4, 0, 2u);
        MY_FadeOutSample(1, 4, 0, 2u);
        MY_FadeOutSample(0, 12, 0, 2u);
        MY_FadeOutSample(1, 12, 0, 2u);
        MY_StartMusic(2, 0x7Fu);
        CPP_draw_hiscore();
        break;
      case 3:
        MY_FadeOutSample(0, 4, 0, 2u);
        MY_FadeOutSample(1, 4, 0, 2u);
        MY_FadeOutSample(0, 12, 0, 2u);
        MY_FadeOutSample(1, 12, 0, 2u);
        MY_StartMusic(2, 0x7Fu);
        CPP_enter_scores();
        break;
      case 4:
        MY_FadeOutSample(0, 4, 0, 2u);
        MY_FadeOutSample(1, 4, 0, 2u);
        MY_FadeOutSample(0, 12, 0, 2u);
        MY_FadeOutSample(1, 12, 0, 2u);
        MY_StartMusic(2, 0x7Fu);
        CPP_who_won();
        break;
      default:
        break;
    }

    ToScreen(); //qmemcpy((void *)0xA0000, (const void *)WScreen, 0xFA00u);

//    a2 = 719360;

//  for ( end_time = clock(/*v3*/); (int)abs(end_time - start_time) < 5; end_time = clock(/*v2*/) );
//  for ( end_time = RTC_Tick; (int)abs(end_time - start_time) < 6 /*5*/ ; end_time = RTC_Tick );
//  while(RTC_Tick-StartTime<7 /*5*/ );

    for(end_time=SDL_GetTicks();(int)abs(end_time-start_time)<58;end_time=SDL_GetTicks())SDL_Delay(1);

    ++turn;
  }

  CPP_FadePalette256(0, 0x18u, 0);
  CPP_save_game();
  MY_StopMusic();
}

//---------------------------------------------------------------------------------

#if 0
int CPP_dos_alloc(unsigned int a1) //not need for Win32
{
  s8 r=0;
  u16 seg;
  u16 sel;

  int v1; // ebx
  int v3[7]; // [esp+0h] [ebp-38h] BYREF
  int v4[7]; // [esp+1Ch] [ebp-1Ch] BYREF

  v1 = 0;
  if ( a1 < 0xA0000 )
  {
   r=DOS_Allocate((a1+15)>>4,&seg,&sel);

   if(r==0)
   {
     v1=sel;
     v1<<=16;
     v1|=seg; //старшее слово - селектор, младшее - сегмент
   }

/*
    v3[1] = (a1 + 15) >> 4;
    v3[0] = 256;
    int386(49, (union REGS*)v3, (union REGS*)v4); //int386(49, v3, v4);
    if ( !v4[6] )
      v1 = v4[0] | (v4[3] << 16);
*/
  }

  return v1;
}

int CPP_dos_free(int a1) //not need for Win32
{
  int result; // eax
  int v2[7]; // [esp+0h] [ebp-38h] BYREF
  char v3[28]; // [esp+1Ch] [ebp-1Ch] BYREF

  result = a1;
  if ( (u16)a1 )
  {

/*
    v2[0] = 257;
    v2[3] = (u16)a1;
    result = int386(49, (union REGS*)v2, (union REGS*)v3); //result = int386(49, v2, v3);
*/
   result=DOS_Free((u16)a1); //=0 - успех, -1 - что-то пошло не так

  }
  return result;
}
#endif

int CPP_FindMusicType(int a1) //FINAL
{
  while ( *(u8 *)a1 )
  {
    if ( !stricmp((char*) musicboard, (char*)a1) )
      return *(UA<u32> *)(a1 + 12);
    a1 += 16;
  }
  return -1;
}

void CPP_ResetMemory(void)
{
#if 0
  int *i; // ebx
  int result; // eax

  for ( i = MemoryBlocks; i[2]; i += 3 )
  {
    if ( i[1] )
      ; //result = CPP_dos_free(*((u16 *)i + 2));
    else
      /*result =*/ free((void*)*i);

    i[2] = 0;
    *i = 0;
    i[1] = 0;
  }
#endif

  free((void*)fade_out); //added
  free(GlobalHeap);      //added
}

void CPP_ResetScreen() //SDL2
{
 SDL_DestroyTexture(texture);
 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);

/*
 __asm
 {
  mov       ax,3
  int       0x10
  mov       ax,0x1112
  xor       bx,bx
  int       0x10
 }
*/

/*
  char v1[28]; // [esp+0h] [ebp-38h] BYREF
  int v2[7]; // [esp+1Ch] [ebp-1Ch] BYREF
  v2[0] = (u16)OldVideoMode;
  return int386(16, v2, v1);
*/
}

void CPP_CloseKeyboard(void) //FINAL
{
//  i64 result; // rax

//  BYTE1(result) = 0;
  KeyboardInstalled = 0;
//  return result;
}

void CPP_ResetNetwork(void) //FINAL
{
/*
  int v0; // ebx
  int *result; // eax
  int v2; // [esp-4h] [ebp-4h]

  if ( (u8)Network )  //(u8)Network = 0
  {
    v0 = 0;
    MyFree(dword_226294);
    while ( v0 < 8 )
    {
      v2 = dword_226298[v0++];
      MyFree(v2);
    }
    MyFree(dword_22628C);
    result = MyFree(dword_226290);
    LOBYTE(Network) = 0;
  }
  return result;
*/
}

void CPP_reset_host(void) //FINAL
{
  CPP_CloseKeyboard();
  CPP_ResetScreen();
  CPP_ResetNetwork();
}

int *CPP_FreeAllData(int a1) //FINAL
{
  int *result; // eax

  while ( *(UA<u32> *)(a1 + 28) )
  {
    result = CPP_FreeData(a1);
    a1 += 44;
  }
  return result;
}

void CPP_reset_game(void)
{
  CPP_MyFree(level);

  MY_FreeSound();
  MY_FreeMusic();

  CPP_reset_host();
  /*return*/ CPP_FreeAllData((int)startup_files);
}

int CPP_save_game(void) //FINAL
{
  int result; // eax

  result = CPP_SaveFileAt((int)aDataHiscoreDat, high_scores, 832);
  if ( result != 832 )
    file_error = 1;
  return result;
}

unsigned int CPP_draw_the_winner(char a1) //FINAL
{
  unsigned int result; // eax
  u8 *v2; // edx
  char v3[256]; // [esp+0h] [ebp-120h] BYREF
  u8 *v4; // [esp+100h] [ebp-20h]
  int v5; // [esp+104h] [ebp-1Ch]
  int v6; // [esp+108h] [ebp-18h]
  int v7; // [esp+10Ch] [ebp-14h]
  int v8; // [esp+110h] [ebp-10h]
  int k; // [esp+114h] [ebp-Ch]
  int j; // [esp+118h] [ebp-8h]
  int i; // [esp+11Ch] [ebp-4h]

  v5 = WScreen + 24420;
  v7 = WScreen + 26980;

  if ( ascii )
    fading = 2;

  if ( a1 )
  {
    if ( a1 == 1 )
      sprintf((char*)v3, (const char*)aCongratulation_1); //((void (__cdecl *)(char *, char *))sprintf)(v3, aCongratulation_1);
    else
      sprintf(v3, aCongratulation_2); //((void (__cdecl *)(char *, char *))sprintf)(v3, aCongratulation_2);
  }
  else
  {
   sprintf(v3, aCongratulation_0); //((void (__cdecl *)(char *, char *))sprintf)(v3, aCongratulation_0);
  }
  for ( i = 0; ; ++i )
  {
    result = strlen(v3);

    if ( (u16)i >= result )
      break;

    if ( v3[(u16)i] == 47 && v3[(u16)i + 1] == 110 )
    {
      v5 = v7;
      v7 += 2560;
      ++i;
    }
    else
    {
      v8 = (u8)v3[(u16)i] + 1952;
      v4 = (u8 *)(((u16)v8 << 6) + block_data);
      for ( j = 0; (u16)j < 8u; ++j )
      {
        v6 = 320 * (u16)j;
        for ( k = 0; (u16)k < 8u; ++k )
        {
          v2 = v4++;
          *(u8 *)(v6 + (u16)k + v5) = *v2;
        }
      }
      v5 += 8;
    }
  }
  ascii = 0;
  return result;
}

int CPP_who_won(void) //FINAL
{
  if ( fading == 1 )
  {
    if ( CPP_FadePalette256((u8 *)palette, 0x18u, 1) >= 24 )
      fading = 0;
  }
  else if ( fading == 2 )
  {
    if ( CPP_FadePalette256(0, 0x18u, 1) >= 24 )
    {
      fading = 1;
      game_mode = 3;
    }
  }
  else
  {
    CPP_ClearScreenMCGA(/*200,*/ (void *)WScreen, 0xC8u, 0);
  }

  CPP_setup_vecs(WScreen, 0, 320, 320, 200);

  CPP_set_scroll((int)(u16)word_25677C[0] >> 5);

  if ( (unsigned int)wins[0] <= (u8)byte_256B35 )
  {
    if ( (unsigned int)wins[0] >= (u8)byte_256B35 )
      CPP_draw_the_winner(10);
    else
      CPP_draw_the_winner(1);
  }
  else
  {
    CPP_draw_the_winner(0);
  }
  HIBYTE(scrollpos[0]) += 8;
  return CPP_new_starfield(scrollpos[0], 256);
}

void CPP_ClearScreenMCGA(void *a2, u16 a3, char a4) //FINAL
{
 memset(a2,a4,(80*4)*a3);
}

unsigned int CPP_save_score(u8 a1, u8 a2, const char *a3) //FINAL
{
  u16 *v3; // eax
  u16 *v4; // edx
  char v5; // bl
  unsigned int result; // eax
  i16 v7; // ax
  u16 *v8; // edx
  int v9; // [esp+0h] [ebp-13Ch]
  int v10; // [esp+4h] [ebp-138h]
  u8 j; // [esp+10h] [ebp-12Ch]
  u8 i; // [esp+14h] [ebp-128h]
  char v13[256]; // [esp+18h] [ebp-124h] BYREF
  char v14[24]; // [esp+118h] [ebp-24h] BYREF
  u16 *v15; // [esp+130h] [ebp-Ch]
  int k; // [esp+134h] [ebp-8h]
  u8 v17; // [esp+138h] [ebp-4h]

  if ( a2 != 10 )
  {
    for ( i = 10; i > a2; --i )
    {
      v10 = (i << 6) + 64 + high_scores;
      v9 = (i << 6) + high_scores;
      for ( j = 0; j < 0x15u; ++j )
      {
        v3 = (u16 *)v9;
        v9 += 2;
        v4 = (u16 *)v10;
        v10 += 2;
        *v4 = *v3;
      }
    }
  }

  sprintf(v13, "%d", the_score[a1]);

  v5 = 21 - strlen((const char*)a3);
  v17 = v5 - strlen(v13);

  for ( k = 0; (u16)k < (int)v17; ++k )
    v14[(u16)k] = 46;

  v14[(u16)k] = 0;

  sprintf(v13, "%s%s%d", a3, v14, the_score[a1]);

  the_score[a1] = 0;

  v15 = (u16 *)((a2 << 6) + 64 + high_scores);

  for ( k = 0; ; ++k )
  {
    result = strlen(v13);

    if ( (u16)k >= result )
      break;

    v7 = (u8)v13[(u16)k] + 1952;
    v8 = v15++;
    *v8 = v7;
  }

  return result;
}

char CPP_draw_enter_score(u8 a1, u8 a2) //FINAL
{
  u8 v2; // al
  unsigned int v3; // eax
  u8 *v4; // edx
  unsigned int v5; // eax
  u8 *v6; // edx
  char v8[256]; // [esp+0h] [ebp-128h] BYREF
  u8 *v9; // [esp+100h] [ebp-28h]
  int v10; // [esp+104h] [ebp-24h]
  int v11; // [esp+108h] [ebp-20h]
  int v12; // [esp+10Ch] [ebp-1Ch]
  int v13; // [esp+110h] [ebp-18h]
  u8 j; // [esp+114h] [ebp-14h]
  u8 i; // [esp+11Ch] [ebp-Ch]
  u8 k; // [esp+120h] [ebp-8h]
  char v17; // [esp+124h] [ebp-4h]

  v17 = 0;

  sprintf(v8, (char*)aCongratulation, a1 + 1);

  v12 = WScreen + 24420;
  v10 = WScreen + 26980;
  if ( (u8)ascii < 0x20u || (u8)ascii > 0x5Au || (u8)byte_220A58 >= 0xAu )
  {
    if ( ascii == 8 && byte_220A58 )
      byte_220A59[(u8)--byte_220A58] = 0;
  }
  else
  {
    v2 = byte_220A58++;
    byte_220A59[v2] = ascii;
    byte_220A59[(u8)byte_220A58] = 0;
  }
  for ( i = 0; ; ++i )
  {
    v3 = strlen(v8);

    if ( i >= v3 )
      break;

    if ( v8[i] == 47 && v8[i + 1] == 110 )
    {
      v12 = v10;
      v10 += 2560;
      ++i;
    }
    else
    {
      v13 = (u8)v8[i] + 1952;
      v9 = (u8 *)(((u16)v13 << 6) + block_data);
      for ( j = 0; j < 8u; ++j )
      {
        v11 = 320 * j;
        for ( k = 0; k < 8u; ++k )
        {
          v4 = v9++;
          *(u8 *)(v11 + k + v12) = *v4;
        }
      }
      v12 += 8;
    }
  }
  for ( i = 0; ; ++i )
  {
    v5 = strlen(byte_220A59);

    if ( i >= v5 )
      break;

    v13 = (u8)byte_220A59[i] + 1952;
    v9 = (u8 *)(((u16)v13 << 6) + block_data);
    for ( j = 0; j < 8u; ++j )
    {
      v11 = 320 * j;
      for ( k = 0; k < 8u; ++k )
      {
        v6 = v9++;
        *(u8 *)(v11 + k + v12) = *v6;
      }
    }
    v12 += 8;
  }
  if ( ascii == 13 )
  {

    if ( !stricmp((char*)byte_220A59, aJty) )
      cheat_on = 1;

    CPP_save_score(a1, a2, byte_220A59);

    byte_220A58 = 0;

    strcpy(byte_220A59, asc_21F11C);

    v17 = 1;
  }
  else if ( byte_2B37D1 )
  {
    byte_220A58 = 0;

    strcpy(byte_220A59, asc_21F11C);

    v17 = 1;
  }
  ascii = 0;
  return v17;
}

int CPP_enter_scores(void) //FINAL
{
  u16 *v0; // eax
  u16 *v1; // eax
  u16 *v2; // edx
  u16 *v3; // eax
  int v5; // [esp+0h] [ebp-2Ch]
  u16 j; // [esp+4h] [ebp-28h]
  u16 k; // [esp+4h] [ebp-28h]
  u16 l; // [esp+4h] [ebp-28h]
  int v9; // [esp+8h] [ebp-24h]
  u16 *i; // [esp+Ch] [ebp-20h]
  int v11; // [esp+10h] [ebp-1Ch]
  unsigned int v12; // [esp+14h] [ebp-18h]
  u8 v13; // [esp+18h] [ebp-14h]

  CPP_setup_vecs(WScreen, 0, 320, 320, 200);

  CPP_set_scroll((int)(u16)word_25677C[0] >> 5);

  if ( (u8)byte_220C44 >= (u8)no_players )
  {
    fading = 2;
  }
  else
  {
    v13 = 11;
    v12 = 0;
    while ( the_score[(u8)byte_220C44] > v12 && v13 > 1u )
    {
      v12 = 0;
      v11 = 1;
      for ( i = (u16 *)((v13 << 6) + 40 + high_scores); *i != 1998; --i )
      {
        v12 += (u16)v11 * ((u16)*i - 2000);
        v11 *= 10;
      }
      if ( the_score[(u8)byte_220C44] > v12 )
        --v13;
    }
    if ( v13 > 0xAu )
      v13 = 0;
    if ( v13 )
    {
      CPP_ClearScreenMCGA(/*200,*/ (void *)WScreen, 0xC8u, 0);

      if ( CPP_draw_enter_score(byte_220C44, v13) )
        ++byte_220C44;
    }
    else
    {
      ++byte_220C44;
    }
  }
  if ( fading == 1 )
  {
    if ( CPP_FadePalette256((u8 *)palette, 0x18u, 1) >= 24 )
      fading = 0;
  }
  else if ( fading == 2 && CPP_FadePalette256(0, 0x18u, 1) >= 24 )
  {
    fading = 1;

    CPP_clear_tube();
    CPP_setup_vecs(WScreen, 0, 320, 320, 200);
    CPP_set_scroll((int)(u16)word_25677C[0] >> 5);

    v9 = level;
    game_mode = 2;
    hiscore_ticks = 0;
    hi_look = (int)&hiscore_lookup;
    level_line[0] = 987;

    if ( bodge )
      ++level_line[0];

    lastscroll[0] = 1;
    scrollpos[0] = 0;
    scrollsave[0] = 0;
    no_players = 0;

    for ( j = 0; j < 0x306u; ++j )
    {
      v0 = (u16 *)v9;
      v9 += 2;
      *v0 = 0;
    }

    v5 = high_scores;

    for ( k = 0; k < 0x1A0u; ++k )
    {
      v1 = (u16 *)v5;
      v5 += 2;
      v2 = (u16 *)v9;
      v9 += 2;
      *v2 = *v1;
    }

    for ( l = 0; l < 0x27Au; ++l )
    {
      v3 = (u16 *)v9;
      v9 += 2;
      *v3 = 0;
    }

    byte_220C44 = 0;
  }
  HIBYTE(scrollpos[0]) += 8;

  return CPP_new_starfield(scrollpos[0], 256);
}

int CPP_high_tube(void) //FINAL Знакозависимая функция. Принудительно задал signed там, где надо. Иначе корректно работала только при all chars signed в настройках компилятора.
{
  signed char *v0; // eax
  signed char *v1; // eax
  signed char *v2; // eax
  u8 v4; // [esp+8h] [ebp-24h]
  _BOOL1 v5; // [esp+10h] [ebp-1Ch]
  u8 i; // [esp+28h] [ebp-4h]
  u8 j; // [esp+28h] [ebp-4h]

  if ( !hiscore_ticks )
  {
    if ( *(u8 *)hi_look == 100 )
      hi_look = (int)&hiscore_second[0]; //fix [0] pointer
    v0 = (signed char *)hi_look++;
    vx[0] = *v0;
    v1 = (signed char *)hi_look++;
    vy[0] = *v1;
    v2 = (signed char *)hi_look++;
    hiscore_ticks = *v2;
  }

  --hiscore_ticks;

  if ( vy[0] > 0 && lastscroll[0] == 1 )
  {
    for ( i = 0; i <= 0x20u; ++i )
    {
      if ( --level_line[0] <= 0x3C8u )
        level_line[0] = 1024;
    }
    lastscroll[0] = 2;
  }
  else if ( vy[0] < 0 && lastscroll[0] == 2 )
  {
    for ( j = 0; j <= 0x20u; ++j )
    {
      if ( ++level_line[0] >= 0x400u )
        level_line[0] = 969;
    }
    lastscroll[0] = 1;
  }

  LOBYTE(scrollpos[0]) -= vx[0];
  HIBYTE(scrollpos[0]) += LOBYTE(vy[0]);

  if ( level_line[0] >= 0x400u )
    level_line[0] = 968;

  if ( vy[0] >= 0 )
  {
    if ( vy[0] > 0 )
    {
      while ( 1 )
      {
        if ( ((v4 = scrollsave[0] + 8, scrollsave[0] == -8) || v4 > 0xF0u) && HIBYTE(scrollpos[0]) <= 0x10u )
          v5 = 1;
        else
          v5 = v4 <= HIBYTE(scrollpos[0]) && scrollsave[0] != -8;

        if ( !v5 )
          break;

        CPP_scroll_tube(2, 0);
        scrollsave[0] += 8;
      }
    }
  }
  else
  {
  //while ( HIBYTE(scrollpos[0]) > 0xEFu && scrollsave[0] < 0x10u || HIBYTE(scrollpos[0]) < (unsigned int)scrollsave[0] )
  //здесь именно такой типкаст, иначе блокирует цикл выше, или не показывает HIGH SCORES, или время вылета табло с очками неверное
    while ( HIBYTE(scrollpos[0]) > 0xEFu && scrollsave[0] < 0x10u || HIBYTE(scrollpos[0]) < (unsigned char)scrollsave[0] )
    {
      CPP_scroll_tube(1, 0);
      scrollsave[0] -= 8;
    }
  }

  scrollsave[0] = HIBYTE(scrollpos[0]) - HIBYTE(scrollpos[0]) % 8;

  return CPP_draw_tube();
}

int CPP_new_game(void) //FINAL
{
  u8 j; // [esp+0h] [ebp-8h]
  u8 i; // [esp+4h] [ebp-4h]

  bodge = 1;
  no_players = temp_no_players;
  bonus_game = temp_no_players == 1;

  for ( i = 0; i < (u8)no_players; ++i )
  {
    old_score[i] = 0;
    wins[i] = 0;
    the_score[i] = 0;
    no_lives[i] = 3;  //число жизней у игрока в начале уровня
  }

  level_no = 0;

  CPP_load_level(0);

  bonus = 4000;
  race_finished = 0;
  game_pause = 0;
  game_mode = 0;
  level_start = 1;
  fading = 1;
  for ( j = 0; j < (u8)no_players; ++j )
  {
    scrollpos[j] = 0;
    level_line[j] = 28;
    laps[j] = 0;
    myvx[j] = 0;
    game_over_flag[j] = 0;
    lastscroll[j] = 1;
    flicker[j] = 127;
  }

  CPP_clear_tube();
  CPP_setup_tube_graphics(level + 63744);
  CPP_setup_ships();
  CPP_setup_bullets();
  CPP_setup_aliens();

  blk_collision = 0;
  return CPP_setup_anims();
}

i16 CPP_draw_hiscore(void) //FINAL
{
  i16 result; // ax

  CPP_high_tube();

  CPP_DrawASpriteMCGA(166, 40, logo + 6);
  CPP_DrawASpriteMCGA(316, 44, logo + 12);
  result = CPP_DrawASpriteMCGA(192, 180, logo + 18);

  if ( fading == 2 )
  {
    result = CPP_FadePalette256(0, 0x18u, 1);
    if ( result >= 24 )
    {
      fading = 0;
      result = CPP_new_game();
    }
  }
  else if ( fading == 1 )
  {
    result = CPP_FadePalette256((u8 *)palette, 0x18u, 1);
    if ( result >= 24 )
      fading = 0;
  }
  return result;
}

u16 CPP_move_it(int a1, int a2, int a3, i16 a4, i16 a5, int a6) //FINAL
{
  u16 result; // ax
   char *v7; // [esp+4h] [ebp-60h]
  int v8; // [esp+8h] [ebp-5Ch]
  int v9; // [esp+Ch] [ebp-58h]
  int v10; // [esp+1Ch] [ebp-48h]
  int v11; // [esp+20h] [ebp-44h]
  int v12; // [esp+30h] [ebp-34h]
  int v13; // [esp+34h] [ebp-30h]
  int v14; // [esp+38h] [ebp-2Ch]
  int v15; // [esp+3Ch] [ebp-28h]
  int v16; // [esp+40h] [ebp-24h]
  int v17; // [esp+44h] [ebp-20h]
   char *v18; // [esp+48h] [ebp-1Ch]
  u32 *v19; // [esp+4Ch] [ebp-18h]
   char *v20; // [esp+50h] [ebp-14h]
  char *v21; // [esp+54h] [ebp-10h]
  char *j; // [esp+58h] [ebp-Ch]
  u32 *v23; // [esp+5Ch] [ebp-8h]
  u16 i; // [esp+60h] [ebp-4h]
  u16 v25; // [esp+60h] [ebp-4h]
  int v26; // [esp+78h] [ebp+14h]
  int v27; // [esp+84h] [ebp+20h]
  int v28; // [esp+88h] [ebp+24h]

  v21 = (char *) object3ds + 16 * a6;
  v19 = (u32 *)*((u32 *)v21 + 2);
  v23 = (u32 *) polypoints;
  v26 = (a1 >> 5) & 0x7FF;
  v27 = a4 & 0x7FF;
  v28 = a5 & 0x7FF;

  v17 = sintable[v27];
  v16 = costable[v27];
  v15 = sintable[v26];
  v14 = costable[v26];
  v13 = sintable[v28];
  v12 = costable[v28];

  for ( i = 0; i < *((u16 *)v21 + 2); ++i )
  {
    //типкаст в signed - иначе сдвиги неправильно работают: корабли артефачат жутко
    v11 = (signed)(*v19 * v16 - v19[1] * v17) >> 16;
    v10 = (signed)(v19[1] * v16 + *v19 * v17) >> 16;
    v9 =  (signed)(v10 * v13 + v19[2] * v12) >> 16;
    v8 = ((signed)((30 * (  (signed)(v10 * v12 - v19[2] * v13) >> 16) + a2) SHL6)) + 589824; //shift fix

    if ( v8 <= 0 )
      v8 = 1;

    *v23 = (8 * (256 - (a3 >> 8)) * v15 + 4 * (long long)(-v14 * v11 + v9 * v15)  ) / v8 + scroll_x; //overflow fix
    v23[1] = (4 * (long long)(-v15 * v11 - v9 * v14) - v14 * 5 * (256 - (a3 >> 8))) / v8 + scroll_y; //overflow fix
    v19 += 3;
    v23 += 6;
  }
  result = *((u16 *)v21 + 1);
  if ( result )
  {
    vec_map = tmaps[(u8)v21[1]];
    v25 = 0;
    for ( j = (char *)*((u32 *)v21 + 3); ; j += 15 )
    {
      result = v25;

      if ( v25 >= *((u16 *)v21 + 1) )
        return result;

      v20 = (char *) polypoints + 24 * (u8)j[3];
      v7 =  (char *) polypoints + 24 * (u8)j[4];
      v18 = (char *) polypoints + 24 * (u8)j[5];

      if ( ((u8)v18[22] & (u8)(v7[22] & v20[22])) == 0 )
        break;

LABEL_10:
      ++v25;
    }
    vec_mode = *j;
    if ( (u8)vec_mode < 0xCu )
    {
      if ( (u8)vec_mode >= 4u )
      {
        if ( (u8)vec_mode > 4u )
        {

          if ( (u8)vec_mode <= 6u )
            goto LABEL_36;

          if ( vec_mode != 7 )
            goto LABEL_37;

          goto LABEL_35;
        }
LABEL_34:
        vec_colour = j[2];
        *((u32 *)v20 + 4) = (u8)j[12] << 16;
        *((u32 *)v7  + 4) = (u8)j[13] << 16;
        *((u32 *)v18 + 4) = (u8)j[14] << 16;

LABEL_37:
        CPP_trig((int*)v20,(int*)v7,(int*)v18);

        goto LABEL_10;
      }
      if ( vec_mode )
      {
        if ( (u8)vec_mode < 2u )
          goto LABEL_37;

        goto LABEL_35;
      }
    }
    else
    {
      if ( (u8)vec_mode <= 0xDu )
        goto LABEL_35;

      if ( (u8)vec_mode >= 0x12u )
      {
        if ( (u8)vec_mode > 0x13u )
        {
          if ( (u8)vec_mode >= 0x16u )
          {
            if ( (u8)vec_mode > 0x17u )
            {
              if ( (u8)vec_mode > 0x19u )
                goto LABEL_37;

              goto LABEL_36;
            }
            goto LABEL_35;
          }
LABEL_36:
          vec_colour = j[2];
          *((u32 *)v20 + 4) = (u8)j[12] << 16;
          *((u32 *)v7  + 4) = (u8)j[13] << 16;
          *((u32 *)v18 + 4) = (u8)j[14] << 16;
          *((u32 *)v20 + 2) = (u8)j[6] << 16;
          *((u32 *)v20 + 3) = (u8)j[7] << 16;
          *((u32 *)v7  + 2) = (u8)j[8] << 16;
          *((u32 *)v7  + 3) = (u8)j[9] << 16;
          *((u32 *)v18 + 2) = (u8)j[10] << 16;
          *((u32 *)v18 + 3) = (u8)j[11] << 16;
          goto LABEL_37;
        }
LABEL_35:
        *((u32 *)v20 + 2) = (u8)j[6] << 16;
        *((u32 *)v20 + 3) = (u8)j[7] << 16;
        *((u32 *)v7  + 2) = (u8)j[8] << 16;
        *((u32 *)v7  + 3) = (u8)j[9] << 16;
        *((u32 *)v18 + 2) = (u8)j[10] << 16;
        *((u32 *)v18 + 3) = (u8)j[11] << 16;
        goto LABEL_37;
      }
      if ( (u8)vec_mode > 0xFu )
        goto LABEL_34;
    }
    if ( (v21[6] & 1) != 0 )
    {
      vec_colour = j[2];
    }
    else
    {
      j[13] = tables_start[256 * (u8)j[12] + (u8)j[2]];
      vec_colour = j[13];
    }
    goto LABEL_37;
  }
  return result;
}

int CPP_draw_ships(void) //FINAL
{
  int result; // eax
  int v1; // [esp+0h] [ebp-8h]
  int v2; // [esp+0h] [ebp-8h]
  int v3; // [esp+0h] [ebp-8h]
  u16 j; // [esp+4h] [ebp-4h]
  u16 k; // [esp+4h] [ebp-4h]
  u16 i; // [esp+4h] [ebp-4h]

  if ( (u8)no_players <= 1u )
  {
    v3 = (int)draw_items; //2451476; //0x256814 HARDCODED !!! 00256814 draw_items

    CPP_set_scroll((int)(u16)word_25677C[0] >> 5);
    CPP_setup_vecs(WScreen, 0, 320, 320, 200);

    for ( i = 0; ; ++i )
    {
      result = v3;

      if ( !*(UA<u32> *)v3 || i >= 0x60u )
        break;

      CPP_move_it(
        *(u16 *)(*(UA<u32> *)v3 + 4),
        *(u16 *)(*(UA<u32> *)v3 + 6) - 1792,
        *(u16 *)(*(UA<u32> *)v3 + 8),
        HIWORD(*(UA<u32> *)(*(UA<u32> *)v3 + 8)),
        HIWORD(*(UA<u32> *)(*(UA<u32> *)v3 + 10)),
        *(u8 *)(*(UA<u32> *)v3 + 16));

      v3 += 4;
    }
  }
  else
  {
    v1 = (int)draw_items; //2451476; HARDCODED !!!

    CPP_set_scroll((int)(u16)word_25677C[0] >> 5);
    CPP_setup_vecs(WScreen, 0, 320, 160, 200);

    for ( j = 0; *(UA<u32> *)v1 && j < 0x60u; ++j )
    {
      CPP_move_it(
        *(u16 *)(*(UA<u32> *)v1 + 4),
        *(u16 *)(*(UA<u32> *)v1 + 6) - 1792,
        *(u16 *)(*(UA<u32> *)v1 + 8),
        HIWORD(*(UA<u32> *)(*(UA<u32> *)v1 + 8)),
        HIWORD(*(UA<u32> *)(*(UA<u32> *)v1 + 10)),
        *(u8 *)(*(UA<u32> *)v1 + 16));

      v1 += 4;
    }

    CPP_setup_vecs(WScreen + 160, 0, 0, 160, 200);
    CPP_set_scroll((int)(u16)word_25679A >> 5);

    v2 =(int)byte_256994; // 2451860; //0x256994 HARDCODED !!! 00256994

    for ( k = 0; ; ++k )
    {
      result = v2;

      if ( !*(UA<u32> *)v2 || k >= 0x60u )
        break;

      CPP_move_it(
        *(u16 *)(*(UA<u32> *)v2 + 4),
        *(u16 *)(*(UA<u32> *)v2 + 6) - 1792,
        *(u16 *)(*(UA<u32> *)v2 + 8),
        HIWORD(*(UA<u32> *)(*(UA<u32> *)v2 + 8)),
        HIWORD(*(UA<u32> *)(*(UA<u32> *)v2 + 10)),
        *(u8 *)(*(UA<u32> *)v2 + 16));
      v2 += 4;
    }
  }
  return result;
}

int CPP_draw_success(void) //FINAL
{
  return CPP_DrawASpriteMCGA(290, 184, logo + 126);
}

int CPP_draw_time_out(void) //FINAL
{
  return CPP_DrawASpriteMCGA(266, 184, logo + 120);
}

int CPP_draw_winner(u8 a1) //FINAL
{
  return CPP_DrawASpriteMCGA(2 * (160 * a1 + 59), 184, logo + 108);
}

int CPP_draw_loser(u8 a1) //FINAL
{
  return CPP_DrawASpriteMCGA(2 * (160 * a1 + 63), 184, logo + 114);
}

void CPP_DrawSpriteVres256(i16 a1 /*dx*/ , int a2 /*ecx*/, int a3 /*ebx*/, char *a4 /*esi*/ , u8 a5, char a6) //FINAL
{
  int v6; // edi
  u8 *v7; // edi
  int v8; // ecx
  int v9; // eax
  u8 *v10; // ebx
  char v11; // al
  char v12; // al
  char v13; // al
  u8 *v14; // edi
  int v15; // ecx
  int v16; // eax
  u8 *v17; // ebx
  char v18; // al
  char v19; // al
  char v20; // al
  char *v21; // edi
  unsigned int v22; // ecx
  int v23; // eax
  char *v24; // ebx
  char *v25; // edi
  char v26; // al
  char *v27; // esi
  char *v28; // edi
  unsigned int v29; // ecx
  int v30; // eax
  char *v31; // ebx
  char *v32; // edi
  char v33; // al
  char *v34; // esi
  int v35; // ebp
  u8 *v36; // edi
  int v37; // ecx
  u8 *v38; // ebx
  char v39; // al
  int v40; // eax
  u8 *v41; // edi
  int v42; // ecx
  u8 i; // dl
  char v44; // al
  char v45; // al
  char v46; // cc
  char v47; // dl
  char v48; // al
  char *v49; // edi
  char v50; // al
  char v51; // dl
  char v52; // al
  char v53; // dl
  unsigned int v54; // ebx
  const void *v55; // esi
  char *v56; // edi
  unsigned int v57; // ecx
  int v58; // eax
  char *v59; // ebx
  char *v60; // edi
  char *v61; // edi
  unsigned int v62; // ecx
  int v63; // eax
  char *v64; // ebx
  char *v65; // edi
  char v66; // al
  char *v67; // esi
  int v68; // edi
  int v69; // ebx
  u8 *v70; // edi
  u8 *v71; // edx
  int v72; // ecx
  char v73; // al
  char v74; // al
  char v75; // al
  char v76; // al
  int v77; // ebx
  u8 *v78; // edi
  int v79; // ecx
  int v80; // eax
  u8 *v81; // ebx
  char v82; // al
  int v83; // ebx
  u8 *v84; // edi
  int v85; // ecx
  int v86; // eax
  u8 *v87; // ebx
  char v88; // al
  u8 *v89; // edi
  int v90; // ecx
  int v91; // ebx
  int v92; // eax
  u8 *v93; // ebx
  char v94; // al
  unsigned int v95; // ebx
  u8 *v96; // edi
  u8 *v97; // edx
  int v98; // ecx
  char v99; // al
  char v100; // al
  char v101; // al
  char v102; // al
  u8 *v103; // edi
  int v104; // ecx
  int v105; // ebx
  u8 *v106; // ebx
  int v107; // eax
  char v108; // al
  u8 *v109; // edi
  int v110; // ecx
  int v111; // ebx
  u8 *v112; // ebx
  int v113; // eax
  char v114; // al
  unsigned int v115; // ebx
  u8 *v116; // edi
  u8 *v117; // edx
  int v118; // ecx
  char v119; // al
  char v120; // al
  char v121; // al
  char v122; // al
  int v123; // eax
  int v124; // edi
  int v125; // eax
  int v126; // eax
  char v127; // al
  int v128; // eax
  char *v129; // [esp-4h] [ebp-Ch]
  u8 v130; // [esp+2h] [ebp-6h]
  u8 v131; // [esp+2h] [ebp-6h]
  u8 v132; // [esp+2h] [ebp-6h]
  u8 v133; // [esp+2h] [ebp-6h]
  u8 v134; // [esp+2h] [ebp-6h]
  u8 v135; // [esp+2h] [ebp-6h]
  u8 v136; // [esp+2h] [ebp-6h]
  u8 v137; // [esp+2h] [ebp-6h]
  char v138; // [esp+3h] [ebp-5h]
  char v139; // [esp+3h] [ebp-5h]
  u8 *v140; // [esp+4h] [ebp-4h]
  u8 *v141; // [esp+4h] [ebp-4h]

  if ( !HIBYTE(a1) )
    return;
  v6 = WScreen + GraphicsWindowLeft + ScreenWidth * GraphicsWindowTop;
  if ( (ScreenMode & 1) != 0 )
  {
    LOBYTE(a1) = (u8)a1 >> 1;
    HIBYTE(a1) >>= 1;
    a3 >>= 1;
    a2 >>= 1;
  }
  if ( a2 < 0 )
  {
    if ( (DrawFlags & 2) != 0 )
    {
      v126 = a2 + HIBYTE(a1);
      v46 = (v126 + 1 < 0) ^ __OFADD__(1, v126) | (v126 == -1);
      v127 = v126 + 1;
      if ( v46 )
        return;
      a2 = -1;
      HIBYTE(a1) = v127;
    }
    else
    {
      v128 = a2 + HIBYTE(a1);

      u8 tmp=HIBYTE(a1); //extra fix

      if ( (v128 < 0) ^ __OFADD__(a2, tmp /*HIBYTE(a1)*/ ) | (v128 == 0) )
        return;

      HIBYTE(a1) = v128;
      BYTE1(v128) = 0;
      do
      {
        while ( 1 )
        {
          LOBYTE(v128) = *a4++;
          if ( !(u8)v128 )
            break;
          if ( (v128 & 0x80u) == 0 )
            a4 += v128;
        }
        ++a2;
      }
      while ( a2 );
    }
  }
  else if ( a2 + HIBYTE(a1) >= GraphicsWindowHeight )
  {
    if ( (DrawFlags & 2) != 0 )
    {
      if ( a2 + 1 >= GraphicsWindowHeight )
        return;
      v123 = HIBYTE(a1) + a2 + 1 - GraphicsWindowHeight;
      HIBYTE(a1) = GraphicsWindowHeight - (a2 + 1);
      v124 = v123;
      v125 = 0;
      do
      {
        while ( 1 )
        {
          LOBYTE(v125) = *a4++;
          if ( !(u8)v125 )
            break;
          if ( (v125 & 0x80u) == 0 )
            a4 += v125;
        }
        --v124;
      }
      while ( v124 );
      v6 = WScreen;
    }
    else
    {
      if ( GraphicsWindowHeight <= a2 )
        return;
      HIBYTE(a1) = GraphicsWindowHeight - a2;
    }
  }
  if ( a3 >= 0 )
  {
    if ( a3 + (u8)a1 >= GraphicsWindowWidth )
    {
      if ( DrawFlags )
      {
        if ( (DrawFlags & 1) != 0 )
        {
          if ( (DrawFlags & 2) != 0 )
          {
            if ( GraphicsWindowRight - a3 >= 0 )
            {
              v77 = (u8)a1 + a3;
              v78 = (u8 *)(ScreenWidth * (HIBYTE(a1) + a2) + v77 + v6);
              v79 = 0;
              LOBYTE(a1) = GraphicsWindowRight - v77 - 2;
              v131 = a1;
              v80 = -1;
              v81 = v78;
              do
              {
                while ( 1 )
                {
                  while ( 1 )
                  {
                    LOBYTE(v80) = *a4++;
                    if ( (v80 & 0x80u) == 0 )
                      break;
                    v78 += v80;
                    LOBYTE(a1) = a1 - v80;
                  }
                  if ( !(u8)v80 )
                    break;
                  LOBYTE(v79) = v80;
                  do
                  {
                    v82 = *a4++;
                    LOBYTE(a1) = a1 + 1;
                    if ( (a1 & 0x80u) == 0 )
                      *v78 = v82;
                    --v78;
                    --v79;
                  }
                  while ( v79 );
                }
                v81 -= ScreenWidth;
                v78 = v81;
                a1 = __PAIR16__(HIBYTE(a1), v131) - 256;
              }
              while ( HIBYTE(a1) );
            }
          }
          else if ( GraphicsWindowRight - a3 >= 0 )
          {
            v83 = (u8)a1 + a3;
            v84 = (u8 *)(ScreenWidth * a2 + v83 + v6);
            v85 = 0;
            LOBYTE(a1) = GraphicsWindowRight - v83 - 2;
            v132 = a1;
            v86 = -1;
            v87 = v84;
            do
            {
              while ( 1 )
              {
                while ( 1 )
                {
                  LOBYTE(v86) = *a4++;
                  if ( (v86 & 0x80u) == 0 )
                    break;
                  v84 += v86;
                  LOBYTE(a1) = a1 - v86;
                }
                if ( !(u8)v86 )
                  break;
                LOBYTE(v85) = v86;
                do
                {
                  v88 = *a4++;
                  LOBYTE(a1) = a1 + 1;
                  if ( (a1 & 0x80u) == 0 )
                    *v84 = v88;
                  --v84;
                  --v85;
                }
                while ( v85 );
              }
              v87 += ScreenWidth;
              v84 = v87;
              a1 = __PAIR16__(HIBYTE(a1), v132) - 256;
            }
            while ( HIBYTE(a1) );
          }
        }
        else if ( (DrawFlags & 2) != 0 )
        {
          v89 = (u8 *)(ScreenWidth * (HIBYTE(a1) + a2) + a3 + v6);
          v90 = 0;
          v91 = GraphicsWindowRight - a3;
          if ( v91 >= 0 )
          {
            LOBYTE(a1) = v91;
            v133 = v91;
            v92 = -1;
            v93 = v89;
            do
            {
              while ( 1 )
              {
                while ( 1 )
                {
                  LOBYTE(v92) = *a4++;
                  if ( (v92 & 0x80u) == 0 )
                    break;
                  v89 -= v92;
                  LOBYTE(a1) = v92 + a1;
                }
                if ( !(u8)v92 )
                  break;
                LOBYTE(v90) = v92;
                do
                {
                  v94 = *a4++;
                  LOBYTE(a1) = a1 - 1;
                  if ( (a1 & 0x80u) == 0 )
                    *v89++ = v94;
                  --v90;
                }
                while ( v90 );
              }
              v93 -= ScreenWidth;
              v89 = v93;
              a1 = __PAIR16__(HIBYTE(a1), v133) - 256;
            }
            while ( HIBYTE(a1) );
          }
        }
      }
      else
      {
        v68 = a3 + v6;
        v69 = GraphicsWindowRight - a3;
        if ( v69 >= 0 )
        {
          v70 = (u8 *)(ScreenWidth * a2 + v68);
          BYTE1(v69) = HIBYTE(a1);
          v130 = v69;
          v71 = v70;
          v72 = 0;
          do
          {
            while ( 1 )
            {
              while ( 1 )
              {
                v73 = *a4++;
                if ( v73 >= 0 )
                  break;
                v46 = ((char)(v73 + v69) < 0) ^ __OFADD__(v73, (u8)v69) | (v73 + (u8)v69 == 0);
                LOBYTE(v69) = v73 + v69;
                if ( !v46 )
                {
                  v70 -= v73;
                  v75 = *a4++;
                  LOBYTE(v72) = v75;
                  do
                  {
                    v76 = *a4++;
                    LOBYTE(v69) = v69 - 1;
                    if ( (v69 & 0x80u) == 0 )
                      *v70++ = v76;
                    --v72;
                  }
                  while ( v72 );
                }
              }
              if ( !v73 )
                break;
              LOBYTE(v72) = v73;
              do
              {
                v74 = *a4++;
                LOBYTE(v69) = v69 - 1;
                if ( (v69 & 0x80u) == 0 )
                  *v70++ = v74;
                --v72;
              }
              while ( v72 );
            }
            v71 += ScreenWidth;
            v70 = v71;
            LOWORD(v69) = __PAIR16__(BYTE1(v69), v130) - 256;
          }
          while ( BYTE1(v69) );
        }
      }
    }
    else if ( (DrawFlags & 1) != 0 )
    {
      if ( (DrawFlags & 2) != 0 )
      {
        v7 = (u8 *)(ScreenWidth * (HIBYTE(a1) + a2) + (u8)a1 + a3 + v6);
        v8 = 0;
        v9 = -1;
        v10 = v7;
        do
        {
          while ( 1 )
          {
            while ( 1 )
            {
              LOBYTE(v9) = *a4++;
              if ( (v9 & 0x80u) == 0 )
                break;
              v7 += v9;
              v12 = *a4++;
              LOBYTE(v8) = v12;
              do
              {
                v13 = *a4++;
                *v7-- = v13;
                --v8;
              }
              while ( v8 );
            }
            if ( !(u8)v9 )
              break;
            LOBYTE(v8) = v9;
            do
            {
              v11 = *a4++;
              *v7-- = v11;
              --v8;
            }
            while ( v8 );
          }
          v10 -= ScreenWidth;
          v7 = v10;
          --HIBYTE(a1);
        }
        while ( HIBYTE(a1) );
      }
      else
      {
        v14 = (u8 *)(ScreenWidth * a2 + (u8)a1 + a3 + v6);
        v15 = 0;
        v16 = -1;
        v17 = v14;
        do
        {
          while ( 1 )
          {
            while ( 1 )
            {
              LOBYTE(v16) = *a4++;
              if ( (v16 & 0x80u) == 0 )
                break;
              v14 += v16;
              v19 = *a4++;
              LOBYTE(v15) = v19;
              do
              {
                v20 = *a4++;
                *v14-- = v20;
                --v15;
              }
              while ( v15 );
            }
            if ( !(u8)v16 )
              break;
            LOBYTE(v15) = v16;
            do
            {
              v18 = *a4++;
              *v14-- = v18;
              --v15;
            }
            while ( v15 );
          }
          v17 += ScreenWidth;
          v14 = v17;
          --HIBYTE(a1);
        }
        while ( HIBYTE(a1) );
      }
    }
    else if ( DrawFlags )
    {
      if ( (DrawFlags & 2) != 0 )
      {
        v28 = (char *)(ScreenWidth * (HIBYTE(a1) + a2) + a3 + v6);
        v29 = 0;
        v30 = -1;
        v31 = v28;
        do
        {
          while ( 1 )
          {
            while ( 1 )
            {
              LOBYTE(v30) = *a4++;
              if ( (v30 & 0x80u) == 0 )
                break;
              v32 = &v28[-v30];
              v33 = *a4;
              v34 = a4 + 1;
              LOBYTE(v29) = v33;
              qmemcpy(v32, v34, v29);
              a4 = &v34[v29];
              v28 = &v32[v29];
              v29 = 0;
            }
            if ( !(u8)v30 )
              break;
            LOBYTE(v29) = v30;
            qmemcpy(v28, a4, v29);
            a4 += v29;
            v28 += v29;
            v29 = 0;
          }
          v31 -= ScreenWidth;
          v28 = v31;
          --HIBYTE(a1);
        }
        while ( HIBYTE(a1) );
      }
      else if ( (DrawFlags & 4) != 0 )
      {
        v35 = GlassMap;
        v36 = (u8 *)(ScreenWidth * a2 + a3 + v6);
        v37 = 0;
        v38 = v36;
        do
        {
          while ( 1 )
          {
            while ( 1 )
            {
              v39 = *a4++;
              if ( v39 >= 0 )
                break;
              v36 -= v39;
            }
            if ( !v39 )
              break;
            LOBYTE(v37) = v39;
            v40 = (u8)v39;
            do
            {
              LOBYTE(v40) = *a4++;
              BYTE1(v40) = *v36;
              *v36++ = *(u8 *)(v40 + v35);
              --v37;
            }
            while ( v37 );
          }
          v38 += ScreenWidth;
          v36 = v38;
          --HIBYTE(a1);
        }
        while ( HIBYTE(a1) );
      }
      else if ( (DrawFlags & 8) != 0 )
      {
        v41 = (u8 *)(ScreenWidth * a2 + a3 + v6);
        v42 = 0;
        v140 = v41;
        v138 = HIBYTE(a1);
        for ( i = a5; ; i = a5 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              v44 = *a4++;
              if ( v44 >= 0 )
                break;
              v42 = (u8)-v44;
              do
              {
                v46 = (char)i-- < 1;
                if ( v46 )
                {
                  i = a5;
                  ++v41;
                }
                --v42;
              }
              while ( v42 );
            }
            if ( !v44 )
              break;
            LOBYTE(v42) = v44;
            do
            {
              v45 = *a4++;
              v46 = (char)i-- < 1;
              if ( v46 )
              {
                i = a5;
                *v41++ = v45;
              }
              --v42;
            }
            while ( v42 );
          }
          if ( !--v138 )
            break;
          v47 = a6;
          while ( --v47 >= 0 )
          {
            while ( 1 )
            {
              do
                v48 = *a4++;
              while ( v48 < 0 );
              if ( !v48 )
                break;
              a4 += (u8)v48;
            }
          }
          v140 += ScreenWidth;
          v41 = v140;
        }
      }
      else if ( (DrawFlags & 0x20) != 0 )
      {
        v49 = (char *)(ScreenWidth * a2 + a3 + v6);
        v141 = (u8*)v49;
        v139 = HIBYTE(a1);
        do
        {
          while ( 1 )
          {
            while ( 1 )
            {
              v50 = *a4++;
              if ( v50 >= 0 )
                break;
              v49 += (u16)(a5 * (u8)-v50);
            }
            if ( !v50 )
              break;
            v51 = v50;
            do
            {
              v52 = *a4++;
              memset(v49, v52, a5);
              v49 += a5;
              v46 = v51-- <= 1;
            }
            while ( !v46 );
          }
          v53 = a6 - 1;
          if ( a6 > 1 )
          {
            v129 = a4;
            v54 = (unsigned int)v49 - (unsigned int)v141;
            do
            {
              v55 = v141;
              v141 += ScreenWidth;
              qmemcpy(v141, v55, v54);
              v46 = v53-- <= 1;
            }
            while ( !v46 );
            a4 = v129;
          }
          v141 += ScreenWidth;
          v49 = (char*)v141;
          --v139;
        }
        while ( v139 );
      }
      else if ( (DrawFlags & 0x40) != 0 )
      {
        v56 = (char *)(ScreenWidth * a2 + a3 + v6);
        v57 = 0;
        v58 = -1;
        v59 = v56;
        do
        {
          while ( 1 )
          {
            while ( 1 )
            {
              LOBYTE(v58) = *a4++;
              if ( (v58 & 0x80u) == 0 )
                break;
              v60 = &v56[-v58];
              LOBYTE(v57) = *a4;
              a4 += v57 + 1;
              memset(v60, a5, v57);
              v56 = &v60[v57];
              v57 = 0;
            }
            if ( !(u8)v58 )
              break;
            LOBYTE(v57) = v58;
            a4 += v57;
            memset(v56, a5, v57);
            v56 += v57;
            v57 = 0;
          }
          v59 += ScreenWidth;
          v56 = v59;
          --HIBYTE(a1);
        }
        while ( HIBYTE(a1) );
      }
      else
      {
        v61 = (char *)(ScreenWidth * a2 + a3 + v6);
        v62 = 0;
        v63 = -1;
        v64 = v61;
        do
        {
          while ( 1 )
          {
            while ( 1 )
            {
              LOBYTE(v63) = *a4++;
              if ( (v63 & 0x80u) == 0 )
                break;
              v65 = &v61[-v63];
              v66 = *a4;
              v67 = a4 + 1;
              LOBYTE(v62) = v66;
              qmemcpy(v65, v67, v62);
              a4 = &v67[v62];
              v61 = &v65[v62];
              v62 = 0;
            }
            if ( !(u8)v63 )
              break;
            LOBYTE(v62) = v63;
            qmemcpy(v61, a4, v62);
            a4 += v62;
            v61 += v62;
            v62 = 0;
          }
          v64 += ScreenWidth;
          v61 = v64;
          --HIBYTE(a1);
        }
        while ( HIBYTE(a1) );
      }
    }
    else
    {
      v21 = (char *)(ScreenWidth * a2 + a3 + v6);
      v22 = 0;
      v23 = -1;
      v24 = v21;
      do
      {
        while ( 1 )
        {
          while ( 1 )
          {
            LOBYTE(v23) = *a4++;
            if ( (v23 & 0x80u) == 0 )
              break;
            v25 = &v21[-v23];
            v26 = *a4;
            v27 = a4 + 1;
            LOBYTE(v22) = v26;
            qmemcpy(v25, v27, v22);
            a4 = &v27[v22];
            v21 = &v25[v22];
            v22 = 0;
          }
          if ( !(u8)v23 )
            break;
          LOBYTE(v22) = v23;
          qmemcpy(v21, a4, v22);
          a4 += v22;
          v21 += v22;
          v22 = 0;
        }
        v24 += ScreenWidth;
        v21 = v24;
        --HIBYTE(a1);
      }
      while ( HIBYTE(a1) );
    }
    return;
  }
  if ( !DrawFlags )
  {
    v95 = -a3;
    if ( (u8)a1 <= v95 )
      return;
    v96 = (u8 *)(ScreenWidth * a2 + v6);
    BYTE1(v95) = HIBYTE(a1);
    v97 = v96;
    v134 = v95;
    v98 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v99 = *a4++;
          if ( v99 < 0 )
            break;
          if ( v99 )
          {
            LOBYTE(v98) = v99;
            do
            {
              v100 = *a4++;
              LOBYTE(v95) = v95 - 1;
              if ( (v95 & 0x80u) != 0 )
                *v96++ = v100;
              --v98;
            }
            while ( v98 );
          }
          else
          {
            v97 += ScreenWidth;
            v96 = v97;
            LOWORD(v95) = __PAIR16__(BYTE1(v95), v134) - 256;
            if ( !BYTE1(v95) )
              return;
          }
        }
        if ( (char)v95 > 0 )
          break;
LABEL_179:
        v96 -= v99;
        v101 = *a4++;
        LOBYTE(v98) = v101;
        do
        {
          v102 = *a4++;
          LOBYTE(v95) = v95 - 1;
          if ( (v95 & 0x80u) != 0 )
            *v96++ = v102;
          --v98;
        }
        while ( v98 );
      }
      LOBYTE(v95) = v99 + v95;
      if ( (v95 & 0x80u) != 0 )
      {
        v99 = v95;
        goto LABEL_179;
      }
    }
  }
  if ( (DrawFlags & 1) == 0 )
  {
    if ( (DrawFlags & 2) == 0 )
      return;
    v115 = -a3;
    if ( (u8)a1 <= v115 )
      return;
    v116 = (u8 *)(ScreenWidth * (HIBYTE(a1) + a2) + v6);
    BYTE1(v115) = HIBYTE(a1);
    v117 = v116;
    v137 = v115;
    v118 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v119 = *a4++;
          if ( v119 < 0 )
            break;
          if ( v119 )
          {
            LOBYTE(v118) = v119;
            do
            {
              v120 = *a4++;
              LOBYTE(v115) = v115 - 1;
              if ( (v115 & 0x80u) != 0 )
                *v116++ = v120;
              --v118;
            }
            while ( v118 );
          }
          else
          {
            v117 -= ScreenWidth;
            v116 = v117;
            LOWORD(v115) = __PAIR16__(BYTE1(v115), v137) - 256;
            if ( !BYTE1(v115) )
              return;
          }
        }
        if ( (char)v115 > 0 )
          break;
LABEL_225:
        v116 -= v119;
        v121 = *a4++;
        LOBYTE(v118) = v121;
        do
        {
          v122 = *a4++;
          LOBYTE(v115) = v115 - 1;
          if ( (v115 & 0x80u) != 0 )
            *v116++ = v122;
          --v118;
        }
        while ( v118 );
      }
      LOBYTE(v115) = v119 + v115;
      if ( (v115 & 0x80u) != 0 )
      {
        v119 = v115;
        goto LABEL_225;
      }
    }
  }
  if ( (DrawFlags & 2) != 0 )
  {
    v103 = (u8 *)(ScreenWidth * (HIBYTE(a1) + a2) + (u8)a1 + a3 + v6);
    v104 = 0;
    v105 = (u8)a1 + a3 + 1;
    if ( v105 >= 0 )
    {
      LOBYTE(a1) = v105;
      v135 = v105;
      v106 = v103;
      v107 = -1;
      do
      {
        while ( 1 )
        {
          while ( 1 )
          {
            LOBYTE(v107) = *a4++;
            if ( (v107 & 0x80u) == 0 )
              break;
            v103 += v107;
            LOBYTE(a1) = v107 + a1;
          }
          if ( !(u8)v107 )
            break;
          LOBYTE(v104) = v107;
          do
          {
            v108 = *a4++;
            LOBYTE(a1) = a1 - 1;
            if ( (a1 & 0x80u) == 0 )
              *v103 = v108;
            --v103;
            --v104;
          }
          while ( v104 );
        }
        v106 -= ScreenWidth;
        v103 = v106;
        a1 = __PAIR16__(HIBYTE(a1), v135) - 256;
      }
      while ( HIBYTE(a1) );
    }
  }
  else
  {
    v109 = (u8 *)(ScreenWidth * a2 + (u8)a1 + a3 + v6);
    v110 = 0;
    v111 = (u8)a1 + a3 + 1;
    if ( v111 >= 0 )
    {
      LOBYTE(a1) = v111;
      v136 = v111;
      v112 = v109;
      v113 = -1;
      do
      {
        while ( 1 )
        {
          while ( 1 )
          {
            LOBYTE(v113) = *a4++;
            if ( (v113 & 0x80u) == 0 )
              break;
            v109 += v113;
            LOBYTE(a1) = v113 + a1;
          }
          if ( !(u8)v113 )
            break;
          LOBYTE(v110) = v113;
          do
          {
            v114 = *a4++;
            LOBYTE(a1) = a1 - 1;
            if ( (a1 & 0x80u) == 0 )
              *v109 = v114;
            --v109;
            --v110;
          }
          while ( v110 );
        }
        v112 += ScreenWidth;
        v109 = v112;
        a1 = __PAIR16__(HIBYTE(a1), v136) - 256;
      }
      while ( HIBYTE(a1) );
    }
  }
}

int CPP_DrawASpriteMCGA(i16 a1, i16 a2, int a3) //FINAL
{
  u16 DX;
  ((char*)&DX)[0]=*(char*)(((char*)a3)+4);
  ((char*)&DX)[1]=*(char*)(((char*)a3)+5);

  CPP_DrawSpriteVres256(DX /*dx*/ , a2 /*ecx*/, a1 /*ebx*/, (char*)(i32)(*(UA<i32> *)a3) /*esi*/ , 0, 0); //сложная передача аргументов функции!

/*
  _asm
  {
     movsx   ebx, word ptr a1 //[ebp+8]
     movsx   ecx, word ptr a2 //[ebp+0Ch]
     mov     esi, a3          //[ebp+10h]

     mov     edi, WScreen     //это не используется

     mov     dl, [esi+4]
     mov     dh, [esi+5]

     mov     esi, [esi]

     push    0
     push    0
     call    DrawSpriteVres256
     add     esp, 8
  }
*/

//DrawSpriteVres256(*(UA<u16> *)(a3 + 4), a2, a1, *(char **)a3, 0, 0);

 return 0;
}

int CPP_draw_level_no(u8 a1) //FINAL
{
  int result; // eax
  u8 v2; // [esp+0h] [ebp-4h]

  v2 = level_no + 1;
  if ( (u8)no_players < 2u )
  {
    if ( v2 <= 0x63u )
    {
      if ( v2 <= 9u )
      {
        CPP_DrawASpriteMCGA(260, 184, logo + 24);
        result = CPP_DrawASpriteMCGA(362, 184, logo + 6 * (v2 % 10 + 5));
      }
      else
      {
        CPP_DrawASpriteMCGA(252, 184, logo + 24);
        CPP_DrawASpriteMCGA(352, 184, logo + 6 * (v2 % 100 / 10 + 5));
        result = CPP_DrawASpriteMCGA(370, 184, 6 * (v2 % 10 + 5) + logo);
      }
    }
    else
    {
      CPP_DrawASpriteMCGA(242, 184, logo + 24);
      CPP_DrawASpriteMCGA(344, 184, logo + 6 * (v2 / 100 + 5));
      CPP_DrawASpriteMCGA(362, 184, logo + 6 * (v2 % 100 / 10 + 5));
      result = CPP_DrawASpriteMCGA(380, 184, 6 * (v2 % 10 + 5) + logo);
    }
  }
  else if ( v2 <= 0x63u )
  {
    if ( v2 <= 9u )
    {
      CPP_DrawASpriteMCGA(2 * (160 * a1 + 50), 184, logo + 24);
      result = CPP_DrawASpriteMCGA(2 * (160 * a1 + 100), 184, logo + 6 * (v2 % 10 + 5));
    }
    else
    {
      CPP_DrawASpriteMCGA(2 * (160 * a1 + 46), 184, logo + 24);
      CPP_DrawASpriteMCGA(2 * (160 * a1 + 96), 184, logo + 6 * (v2 % 100 / 10 + 5));
      result = CPP_DrawASpriteMCGA(2 * (160 * a1 + 105), 184, 6 * (v2 % 10 + 5) + logo);
    }
  }
  else
  {
    CPP_DrawASpriteMCGA(2 * (160 * a1 + 41), 184, logo + 24);
    CPP_DrawASpriteMCGA(2 * (160 * a1 + 91), 184, 6 * (v2 / 100 + 5) + logo);
    CPP_DrawASpriteMCGA(2 * (160 * a1 + 100), 184, 6 * (v2 % 100 / 10 + 5) + logo);
    result = CPP_DrawASpriteMCGA(2 * (160 * a1 + 109), 184, 6 * (v2 % 10 + 5) + logo);
  }
  return result;
}

void CPP_DrawBoxBPP(int a1, int a2, int a3, int a4, char a5, char a6)
{
  int v6; // edi
  int v7; // edi
  int v8; // eax
  char *v9; // edi
  int v10; // edx
  int v11; // ebx
  int v12; // eax
  int result; // eax
  int v14; // ecx
  int v15; // esi
  int v16; // ecx
  int v17; // esi
  int v18; // ecx
  int v19; // [esp+4h] [ebp-4h]

  v6 = a2;

  if ( a2 >= GraphicsWindowBottom )
    return /*v19*/;

  if ( a2 < 0 )
  {
    a4 += a2;
    v6 = 0;
  }

  if ( a4 + v6 > GraphicsWindowHeight )
    a4 = GraphicsWindowHeight - v6;

  if ( a4 <= 0 )
    return /*v19*/;

  v7 = ScreenWidth * (GraphicsWindowTop + v6);
  v8 = a1;

  if ( a1 >= GraphicsWindowRight )
    return /*v19*/;

  if ( a1 < 0 )
  {
    a3 += a1;
    v8 = 0;
  }

  if ( a3 + v8 > GraphicsWindowWidth )
    a3 = GraphicsWindowWidth - v8;

  if ( a3 <= 0 )
    return /*v19*/;

  v9 = (char *)(WScreen + GraphicsWindowLeft + v8 + v7);
  v10 = a4;
  v11 = ScreenWidth - a3;
  v12 = a6 & 3;
  switch ( a6 & 3 )
  {
    case 0:
      do
      {
        v14 = a3;

        do
        {
          *v9++ = a5;
          --v14;
        }
        while ( v14 );

        v9 += v11;
        --v10;
      }
      while ( v10 );

//      result = v19;
      break;

    case 1:
      v15 = GlassMap;
      do
      {
        v16 = a3;
        do
        {
          BYTE1(v12) = *v9;
          LOBYTE(v12) = a5;
          *v9++ = *(u8 *)(v12 + v15);
          --v16;
        }
        while ( v16 );
        v9 += v11;
        --v10;
      }
      while ( v10 );
//      result = v19;
      break;
    case 2:
      v17 = GlassMap;
      do
      {
        v18 = a3;
        do
        {
          LOBYTE(v12) = *v9;
          BYTE1(v12) = a5;
          *v9++ = *(u8 *)(v12 + v17);
          --v18;
        }
        while ( v18 );
        v9 += v11;
        --v10;
      }
      while ( v10 );
//      result = v19;
      break;
    case 3:
//      result = v19;
      break;
  }
  return /*result*/;
}

u8 CPP_draw_game(void)
{
  u8 result; // al
  u8 v2; // dl
  u8 v3; // dl
//  i64 v4; // [esp-1Ch] [ebp-7Ch]
//  i64 v5; // [esp-1Ch] [ebp-7Ch]
  unsigned int v6; // [esp+0h] [ebp-60h]
  u8 v7; // [esp+4h] [ebp-5Ch]
  u8 k; // [esp+10h] [ebp-50h]
  u8 j; // [esp+1Ch] [ebp-44h]
  unsigned int v10; // [esp+20h] [ebp-40h]
  u8 v11; // [esp+2Ch] [ebp-34h]
  u8 v12; // [esp+30h] [ebp-30h]
  u8 v13; // [esp+48h] [ebp-18h]
  u8 i; // [esp+5Ch] [ebp-4h]

  CPP_draw_ships();

  for ( i = 0; ; ++i )
  {
    result = i;

    if ( i >= (u8)no_players )
      break;

    if ( flicker[i] )
    {
      if ( (u8)flicker[i] % 15 > 7 && level_no != 3 )
      {
        if ( game_over_flag[i] )
        {
          if ( (u8)no_players >= 2u )
            CPP_DrawASpriteMCGA(2 * (160 * i + 43), 184, logo + 96);
          else
            CPP_DrawASpriteMCGA(246, 184, logo + 96);
        }
        else if ( level_start )
        {
          if ( (u8)flicker[i] / 15 > 3 )
          {
            CPP_draw_level_no(i);
          }
          else if ( (u8)flicker[i] / 15 )
          {
            if ( (u8)flicker[i] % 15 == 14 )
            {
//              HIDWORD(v5) = 14;
//              LODWORD(v5) = i;
/*
              MY_PlaySample(
                (unsigned int *)0xF,
                a1,
                v5,
                0x7FFFu,
                -2 - 0x7FFF * (u8)no_players - 200,
                100i64,
                3u);
*/
              MY_PlaySample( /*(unsigned int *)0xF, a1, v5,*/ i , 0xE,  0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);
            }
            v13 = (u8)flicker[i] / 15;

            if ( (u8)no_players >= 2u )
              CPP_DrawASpriteMCGA(2 * (160 * i + 75), 184, logo + 6 * (v13 + 5));
            else
              CPP_DrawASpriteMCGA(310, 184, logo + 6 * (v13 + 5));
          }
          else
          {
            if ( (u8)flicker[i] % 15 == 14 )
            {
//              HIDWORD(v4) = 14;
//              LODWORD(v4) = i;

/*
              MY_PlaySample(
                (unsigned int *)0xF,
                a1,
                v4,
                0x7FFFu,
                -2 - 0x7FFF * (u8)no_players - 300,
                150i64,
                3u);
*/
              MY_PlaySample(/*(unsigned int *)0xF, a1, v4,*/ i ,0xE ,0x7FFF, -2 - 0x7FFF * (u8)no_players - 300, 0x96, 0 ,3);
            }

            if ( (u8)no_players >= 2u )
              CPP_DrawASpriteMCGA(2 * (160 * i + 72), 184, logo + 132);
            else
              CPP_DrawASpriteMCGA(304, 184, logo + 132);
          }
        }
      }
      --flicker[i];
    }
    else
    {
      level_start = 0;
    }
    if ( fading == 1 )
    {
      if ( CPP_FadePalette256((u8 *)palette, 0x18u, 1) >= 24 )
        fading = 0;
    }
    else if ( fading == 2 && (u8)flicker[i] < 0x27u && CPP_FadePalette256(0, 0x18u, 1) >= 24 )
    {
      fading = 1;
      game_mode = 3;
      flicker[i] = 1;
    }
    if ( level_no != 3 )
    {
      CPP_DrawBoxBPP(160 * i, 20, 3 * (*(UA<i32> *)((char *) dword_256784 + 30 * i) >> 16), 2, 15, 1); //рисует полоску под табло игрока

      v10 = the_score[i];
      v11 = i;
      v12 = 0;

      if ( (u8)no_players < 2u )
        v11 = 1;

      if ( v10 )
      {
        while ( v10 )
        {
          v2 = v12++;
          CPP_DrawASpriteMCGA(320 * v11 + 301 - 18 * v2, 0, logo + 6 * (v10 % 0xA + 5));
          v10 /= 0xAu;
        }
      }
      else
      {
        CPP_DrawASpriteMCGA(320 * v11 + 301, 0, logo + 30);
      }

      for ( j = 0; j < *(UA<i32> *)&unk_256B3D[i] >> 24; ++j )
        CPP_DrawASpriteMCGA(320 * i + 36 * j, 0, logo + 90);

      for ( k = 0; k < (u8)byte_25678A[30 * i]; ++k )
        CPP_DrawASpriteMCGA(320 * i + 6 + 36 * k, 16, logo + 102);

      v7 = 0;
      if ( bonus_game )
      {
        v6 = bonus;
        if ( bonus )
        {
          while ( v6 )
          {
            v3 = v7++;
            CPP_DrawASpriteMCGA(337 - 18 * v3, 0, logo + 6 * (v6 % 0xA + 5));
            v6 /= 0xAu;
          }
        }
        else
        {
          CPP_DrawASpriteMCGA(337, 0, logo + 30);
        }
      }
      if ( race_finished )
      {
        if ( bonus_game )
        {
          if ( bonus )
            CPP_draw_success();
          else
            CPP_draw_time_out();
        }
        else if ( (unsigned int)laps[0] <= (u8)byte_256B3B )
        {
          CPP_draw_winner(1u);
          CPP_draw_loser(0);
        }
        else
        {
          CPP_draw_winner(0);
          CPP_draw_loser(1u);
        }
      }
    }
  }
  return result;
}

u8 CPP_check_extra_life(void)
{
  u8 result; // al
//  i64 v2; // [esp-1Ch] [ebp-28h]
  u8 i; // [esp+8h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i;

    if ( i >= (u8)no_players )
      break;

    if ( (unsigned int)(the_score[i] - old_score[i]) >= 0x5DC )
    {
      old_score[i] += 1500;
      if ( no_lives[i] == 5 )
      {
        *((u16 *) dword_256784 + 15 * i + 1) = 20;
      }
      else
      {
//        HIDWORD(v2) = 10;
//        LODWORD(v2) = i;
//        MY_PlaySample((unsigned int *)(4 * i), a1, v2, 0x7FFFu, 0x8000u, 100i64, 3u);
          MY_PlaySample(i, 0xA, 0x7FFF, 0x8000, 0x64 ,0, 3);

        ++no_lives[i];
      }
    }
  }
  return result;
}

int CPP_check_scroll_change(u8 a1) //FINAL
{
  int result; // eax
  u8 i; // [esp+0h] [ebp-4h]
  u8 j; // [esp+0h] [ebp-4h]

  if ( vy[a1] > 0 && lastscroll[a1] == 1 )
  {
    for ( i = 0; i <= 0x20u; ++i )
    {
      if ( !--level_line[a1] )
        level_line[a1] = 1024;
    }
    result = a1;
    lastscroll[a1] = 2;
  }
  else
  {
    result = 2 * a1;
    if ( *(UA<i16> *)((char *)vy + result) < 0 )
    {
      result = a1;
      if ( lastscroll[a1] == 2 )
      {
        for ( j = 0; j <= 0x20u; ++j )
        {
          if ( (u16)++level_line[a1] > 0x400u )
            level_line[a1] = 1;
        }
        result = a1;
        lastscroll[a1] = 1;
      }
    }
  }
  return result;
}

char CPP_check_for_race_end(u8 a1) //FINAL
{
  char v3; // [esp+8h] [ebp-4h]

  v3 = 0;
  if ( bonus_game )
  {
    if ( (!flicker[a1] || !level_start) && level_no != 3 && !--bonus )
    {
      word_220C48[0] = 28;
      word_220C4A = 28;
      v3 = 1;
    }
  }

  if ( word_220C48[a1] == 1024 )
    word_220C48[a1] = 0;

  if ( (u16)level_line[a1] == (u16)word_220C48[a1] + 1
    && ++word_220C48[a1] == 32
    && ++laps[a1] == 4 )
  {
    word_220C48[0] = 28;
    word_220C4A = 28;
    v3 = 1;
  }
  return v3;
}

int CPP_delete_anims(u8 a1, unsigned int a2) //FINAL
{
  int result; // eax
  unsigned int *v3; // [esp+0h] [ebp-8h]
  u16 i; // [esp+4h] [ebp-4h]

  result = 1600 * a1;
  v3 = (unsigned int *)((char *)&on_anims + result);
  for ( i = 0; i < 0xC8u; ++i )
  {
    if ( *v3 >= a2 && a2 + 256 > *v3 )
      v3[1] = 0;
    result = (int)v3;
    v3 += 2;
  }
  return result;
}

int CPP_add_anims(u8 a1, int a2, u16 a3) //FINAL
{
  int result; // eax
  i16 j; // [esp+0h] [ebp-28h]
  u32 *v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+8h] [ebp-20h]
  int v7; // [esp+20h] [ebp-8h]
  u16 i; // [esp+24h] [ebp-4h]

  v7 = (int)anim_blks; //2289064; //22EDA8 HARDCODED !!!

  for ( i = 0; i < 0x3E8u; ++i )
  {
    if ( *(UA<u16> *)(v7 + 8) >= a3 && *(u16 *)(v7 + 8) < a3 + 32 )
    {
      v6 = 8 * (*(u16 *)(v7 + 8) - a3) + a2;
      v5 = (u32 *)((char *)&on_anims + 1600 * a1);
      for ( j = 0; (u16)j < 0xC8u; ++j )
      {
        if ( !v5[1] )
        {
          *v5 = v6;
          v5[1] = v7;
          j = 200;
        }
        v5 += 2;
      }
    }
    result = v7;
    v7 += 10;
  }
  return result;
}

char CPP_scroll_tube(char a1, u8 a2) //FINAL
{
  i16 v2; // dx
  i16 v3; // bx
  char result; // al
  u16 *v5; // eax
  unsigned int v6; // [esp+0h] [ebp-20h]
  int v7; // [esp+4h] [ebp-1Ch]
  int v8; // [esp+8h] [ebp-18h]
  unsigned int v9; // [esp+8h] [ebp-18h]
  u32 *v10; // [esp+Ch] [ebp-14h]
  i16 v11; // [esp+10h] [ebp-10h]
  u16 v12; // [esp+14h] [ebp-Ch]
  u8 i; // [esp+18h] [ebp-8h]
  u8 j; // [esp+1Ch] [ebp-4h]

  if ( a1 == 1 )
  {
    v8 = (u8)scrollsave[a2] << 8;
    v2 = level_line[a2];
    level_line[a2] = v2 + 1;
    v11 = 1024 - v2;
    v7 = ((u16)(1024 - v2) << 6) + level;

    if ( (u16)level_line[a2] > 0x400u )
      level_line[a2] = 1;
  }
  else
  {
    v8 = (((u8)scrollsave[a2] << 8) + 2048) % 0x10000;
    v3 = level_line[a2];
    level_line[a2] = v3 - 1;
    v11 = 1024 - v3;
    v7 = ((u16)(1024 - v3) << 6) + level;

    if ( !level_line[a2] )
      level_line[a2] = 1024;
  }
  v9 = (a2 << 16) + v8;

  CPP_delete_anims(a2, v9);
  result = CPP_add_anims(a2, v9, 32 * v11);

  for ( i = 0; i < 0x20u; ++i )
  {
    v5 = (u16 *)v7;
    v7 += 2;
    v12 = *v5;
    v6 = 8 * i + v9;

    if ( *v5 >= 0x800u )
      v12 = 0;

    v10 = (u32 *)((v12 << 6) + block_data);
    for ( j = 0; j < 8u; ++j )
    {
      *(UA<u32> *)(tube_graphics + v6) = *v10;
      *(UA<u32> *)(tube_graphics + v6 + 4) = v10[1];
      v6 += 256;
      v10 += 2;
    }
    result = i;
  }
  return result;
}

int CPP_add_alien(u8 a1, u8 a2, u8 a3, u8 a4) //FINAL
{
  int result; // eax
  int v5; // [esp+4h] [ebp-10h]
  u16 i; // [esp+Ch] [ebp-8h]
  i16 v7; // [esp+10h] [ebp-4h]

  for ( i = 60 * a1; byte_235148[30 * i] && i < 60 * (a1 + 1); ++i )
    ;

  if ( vy[a1] >= 0 )
    v5 = 0;
  else
    v5 = -1;

  if ( v5 )
    v7 = 1012;

  result = 60 * (a1 + 1);
  if ( i < result )
  {
    result = a2;
    switch ( a2 )
    {
      case 0u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 1;
        word_235142[15 * i] = v7;
        word_235144[15 * i] = 0;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        byte_235148[30 * i] = 7;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 2;
        break;
      case 1u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 5;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = v7;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 17;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 5;
        break;
      case 2u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 0;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = 1012;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 6;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 5;
        break;
      case 3u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 0;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = 1012;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 21;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 127;
        break;
      case 4u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 0;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = 0;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 12;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 10;
        break;
      case 5u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 8;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = 0;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 8;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 5;
        break;
      case 6u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 4;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = 0;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 16;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 5;
        break;
      case 7u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 4;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = 0;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 15;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 5;
        break;
      case 8u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 24;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = 0;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 23;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 5;
        break;
      case 9u:
        word_23513C[15 * i] = (LOBYTE(scrollpos[a1]) % 8 + 8 * (32 - a4 + ((int)LOBYTE(scrollpos[a1]) >> 3)) - 4) << 8;
        word_23513E[15 * i] = (8 * a3 - (4 - HIBYTE(scrollpos[a1]) % 8)) << 8;
        word_235140[15 * i] = 0;
        byte_235150[30 * i] = 0;
        byte_235152[30 * i] = 0;
        byte_235153[30 * i] = 0;
        word_235142[15 * i] = 1012;
        word_235144[15 * i] = 0;
        byte_235148[30 * i] = 49;
        result = 30 * i;
        *(UA<i16> *)((char *)word_235146 + result) = 127;
        break;
      default:
        return result;
    }
  }
  return result;
}

int CPP_remove_effect(u8 a1) //FINAL
{
  int result; // eax

  while ( *(UA<u16> *)(effect_list + 6 * a1 + 4) && a1 < 0x63u )
  {
    *(UA<u16> *)(6 * a1 + effect_list + 2) = *(UA<u16> *)(effect_list + 6 * (a1 + 1) + 2);
    *(UA<u16> *)(6 * a1 + effect_list) = *(UA<u16> *)(effect_list + 6 * (a1 + 1));
    *(UA<u16> *)(6 * a1 + effect_list + 4) = *(UA<u16> *)(effect_list + 6 * (a1 + 1) + 4);
    ++a1;
  }
  *(UA<u16> *)(effect_list + 6 * a1 + 2) = 0;
  *(UA<u16> *)(effect_list + 6 * a1) = 0;
  result = effect_list + 6 * a1;
  *(UA<u16> *)(result + 4) = 0;
  return result;
}

int CPP_check_effects(u8 a1) //FINAL
{
  int result; // eax
  i16 v2; // ax
  i16 v3; // ax
  i16 v4; // ax
  i16 v5; // ax
  int v6; // [esp+90h] [ebp-Ch]
  int v7; // [esp+90h] [ebp-Ch]
  i16 j; // [esp+94h] [ebp-8h]
  i16 i; // [esp+94h] [ebp-8h]
  u8 v10; // [esp+98h] [ebp-4h]
  u8 v11; // [esp+98h] [ebp-4h]

  if ( vy[a1] > 0 )
  {
    v7 = (2047 - (u16)level_line[a1]) % 1024;
    v11 = 1;
    for ( i = 0; ; ++i )
    {
      result = effect_list + 6 * i;
      if ( !*(UA<u16> *)(result + 4) )
        break;
      if ( *(u16 *)(effect_list + 6 * i) <= (i16)v7
        && *(u16 *)(effect_list + 6 * i) >= (i16)v7 - 4
        && *(UA<i16> *)(effect_list + 6 * i + 4) > 0 )
      {
        if ( *(UA<i16> *)(effect_list + 6 * i + 4) <= 33 )
        {
          v5 = *(UA<u16> *)(effect_list + 6 * i + 4);
          switch ( v5 )
          {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
              myvx[a1] = v5;
              break;
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
              myvx[a1] = 16 - v5;
              break;
            case 33:
              myvx[a1] = 0;
              break;
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
              CPP_add_alien(a1, v5 - 34, v11, *(u8 *)(effect_list + 6 * i + 2));
              break;
            default:
              continue;
          }
        }
        else
        {
          v11 += ((i16)v7 + 1024 - *(u16 *)(effect_list + 6 * i)) % 1024;
          v4 = *(UA<u16> *)(effect_list + 6 * i + 4);
          switch ( v4 )
          {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
              myvx[a1] = v4;
              break;
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
              myvx[a1] = 16 - v4;
              break;
            case 33:
              myvx[a1] = 0;
              break;
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
              CPP_add_alien(a1, v4 - 34, v11, *(u8 *)(effect_list + 6 * i + 2));
              break;
            default:
              break;
          }
          CPP_remove_effect(i);
        }
      }
    }
  }
  else
  {
    v6 = (1023 - (u16)level_line[a1] + 4) % 1024;
    v10 = 30;
    for ( j = 0; ; ++j )
    {
      result = effect_list + 6 * j;
      if ( !*(UA<u16> *)(result + 4) )
        break;
      if ( *(u16 *)(effect_list + 6 * j) >= (i16)v6
        && *(u16 *)(effect_list + 6 * j) <= (i16)v6 + 4
        && *(UA<i16> *)(effect_list + 6 * j + 4) > 0 )
      {
        if ( *(UA<i16> *)(effect_list + 6 * j + 4) <= 33 )
        {
          v3 = *(UA<u16> *)(effect_list + 6 * j + 4);
          switch ( v3 )
          {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
              myvx[a1] = v3;
              break;
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
              myvx[a1] = 16 - v3;
              break;
            case 33:
              myvx[a1] = 0;
              break;
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
              CPP_add_alien(a1, v3 - 34, v10, *(u8 *)(effect_list + 6 * j + 2));
              break;
            default:
              continue;
          }
        }
        else
        {
          v10 -= (*(u16 *)(effect_list + 6 * j) + 1024 - (i16)v6) % 1024;
          v2 = *(UA<u16> *)(effect_list + 6 * j + 4);
          switch ( v2 )
          {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
              myvx[a1] = v2;
              break;
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
              myvx[a1] = 16 - v2;
              break;
            case 33:
              myvx[a1] = 0;
              break;
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
              CPP_add_alien(a1, v2 - 34, v10, *(u8 *)(effect_list + 6 * j + 2));
              break;
            default:
              break;
          }
          CPP_remove_effect(j);
        }
      }
    }
  }
  return result;
}

int CPP_do_anims(u8 a1) //FINAL
{
  int result; // eax
  char *v2; // [esp+0h] [ebp-8h]
  u16 i; // [esp+4h] [ebp-4h]

  result = 1600 * a1;
  v2 = (char *)&on_anims + result;
  for ( i = 0; i < 0xC8u; ++i )
  {

    if ( *((u32 *)v2 + 1) )
      CPP_draw_block(*(UA<u32> *)v2, **((u16 **)v2 + 1));

    result = (int)v2;
    v2 += 8;
  }
  return result;
}

void CPP_do_death_sound(u8 a3, char a4)
{
//  i64 v4; // [esp-1Ch] [ebp-1Ch]

  if ( a4 )
  {
    dword_22616C = turn;
    dword_226168 = 1;
  }
  if ( dword_226168 )
  {
    if ( (int)abs(dword_22616C - turn) > 20 )
    {
      dword_226168 = 0;
//      HIDWORD(v4) = 13;
//      LODWORD(v4) = a3;

 //     MY_PlaySample(a1, a2, v4, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
        MY_PlaySample(/*a1, a2, v4*/ a3, 0xD, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);
    }
  }
}

int CPP_count_swamp_anims(u8 a1)
{
  char *v2; // [esp+0h] [ebp-10h]
  u16 v3; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]

  v2 = (char *)&on_anims + 1600 * a1;
  v3 = 0;
  v4 = 0;
  while ( v3 < 0xC8u )
  {
    if ( *((u32 *)v2 + 1) && CPP_swamp_block(**((u16 **)v2 + 1)) )
      ++v4;
    ++v3;
    v2 += 8;
  }
  return v4;
}

int CPP_do_swamp_sounds(u8 a1)
{
  int result; // eax
//  i64 v2; // [esp-10h] [ebp-14h]
  int v3; // [esp+0h] [ebp-4h]

  v3 = CPP_count_swamp_anims(a1);
  if ( (u16)v3 > 0x18u )
    v3 = 24;
  if ( (u16)v3 <= (u16)word_2B37C0[a1] )
  {
    MY_FadeOutSample(a1, 12, 1365 * v3, 3u);
  }
  else
  {
//    HIDWORD(v2) = 12;
//    LODWORD(v2) = a1;
    MY_FadeInSample(/*v2,*/ a1, 12, 1365 * v3, 3);
  }
  MY_SetSamplePan(a1, 12, -2 - 0x7FFF * (u8)no_players - 2 * a1);
  result = v3;
  word_2B37C0[a1] = v3;
  return result;
}

_BOOL1 CPP_load_level(u8 a1)
{
  char v2[40]; // [esp+0h] [ebp-2Ch] BYREF

  sprintf((char*)v2,(char*)aDataLev05dDat, a1);

  return CPP_LoadFileAt(v2, (char *)level) == 66136;
}

int CPP_next_frames(void) //FINAL
{
  int result; // eax
  int v1; // [esp+0h] [ebp-10h]
  u16 *v2; // [esp+4h] [ebp-Ch]
  u16 i; // [esp+8h] [ebp-8h]
  u16 v4; // [esp+Ch] [ebp-4h]

  v1 = (int)anim_blks; //2289064; //0x22EDA8 HARDCODED !!! 0022EDA8 anim_blks
  for ( i = 0; i < 0x3E8u; ++i )
  {
    if ( *(UA<u16> *)(v1 + 8) != 0xFFFF )
    {

      v2=(u16*)(u32)*(UA<u32>*)(v1+2);
//    MCPY(&v2 , (u16 **)(v1 + 2), 4); //v2 = *(u16 **)(v1 + 2);

      v4 = *(UA<u16> *)(v1 + 6) + 1;
      if ( *(UA<i32> *)&v2[*(u16 *)(v1 + 6)] >> 16 == -1 )
      {
        v4 = 0;
        *(UA<u16> *)v1 = *v2;
      }
      else
      {
        *(UA<u16> *)v1 = v2[v4];
      }
      *(UA<u16> *)(v1 + 6) = v4;
      *(UA<u16> *)(2 * *(u16 *)(v1 + 8) + level) = *(UA<u16> *)v1;
    }
    result = v1;
    v1 += 10;
  }
  return result;
}

void CPP_omni_map(int a1, int a2, i16 a3) //FINAL
{
  int v3; // ecx
  unsigned int v4; // eax
  u16 *v5; // esi
  int v6; // edx
  int *v7; // edi
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // [esp+0h] [ebp-34h]
  int v11; // [esp+4h] [ebp-30h]
  unsigned int v12; // [esp+8h] [ebp-2Ch]
  int v13; // [esp+Ch] [ebp-28h]
  unsigned int v14; // [esp+10h] [ebp-24h]

  v4 = vec_window_width & 0xFFE0;
  v12 = vec_screen_width - v4;
  v13 = 2 * (vec_screen_width - v4);
  v14 = v4 >> 5;
  v5 = (u16 *)(a1 + 2 * (tube_scroll_x + 320 * tube_scroll_y));
  HIWORD(v6) = 0;
  v7 = (int *)vec_screen;
  v11 = vec_window_height;
  do
  {
    HIWORD(v8) = HIWORD(v14);
    v10 = v14;
    do
    {
      LOWORD(v8) = v5[2];
      LOWORD(v6) = v5[3];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v3) = *(u8 *)(v8 + a2);
      BYTE1(v3) = *(u8 *)(v6 + a2);
      v9 = v3 SHL16;
      LOWORD(v6) = v5[1];
      LOBYTE(v8) = a3 + *v5;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) = HIBYTE(a3) + HIBYTE(*v5);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      *v7 = v9;
      LOWORD(v8) = v5[6];
      LOWORD(v6) = v5[7];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v9 OSHL16;
      LOWORD(v8) = v5[4];
      LOWORD(v6) = v5[5];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v7[1] = v9;
      LOWORD(v8) = v5[10];
      LOWORD(v6) = v5[11];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v9 OSHL16;
      LOWORD(v8) = v5[8];
      LOWORD(v6) = v5[9];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v7[2] = v9;
      LOWORD(v8) = v5[14];
      LOWORD(v6) = v5[15];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v9 OSHL16;
      LOWORD(v8) = v5[12];
      LOWORD(v6) = v5[13];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v7[3] = v9;
      LOWORD(v8) = v5[18];
      LOWORD(v6) = v5[19];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v9 OSHL16;
      LOWORD(v8) = v5[16];
      LOWORD(v6) = v5[17];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v7[4] = v9;
      LOWORD(v8) = v5[22];
      LOWORD(v6) = v5[23];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v9 OSHL16;
      LOWORD(v8) = v5[20];
      LOWORD(v6) = v5[21];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v7[5] = v9;
      LOWORD(v8) = v5[26];
      LOWORD(v6) = v5[27];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v9 OSHL16;
      LOWORD(v8) = v5[24];
      LOWORD(v6) = v5[25];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v7[6] = v9;
      LOWORD(v8) = v5[30];
      LOWORD(v6) = v5[31];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v9) = *(u8 *)(v8 + a2);
      BYTE1(v9) = *(u8 *)(v6 + a2);
      v3 = v9 SHL16;
      LOWORD(v8) = v5[28];
      LOWORD(v6) = v5[29];
      LOBYTE(v8) = a3 + v8;
      LOBYTE(v6) = a3 + v6;
      BYTE1(v8) += HIBYTE(a3);
      BYTE1(v6) += HIBYTE(a3);
      LOBYTE(v3) = *(u8 *)(v8 + a2);
      BYTE1(v3) = *(u8 *)(v6 + a2);
      v7[7] = v3;
      v7 += 8;
      v5 += 32;
      --v10;
    }
    while ( v10 );
    v7 = (int *)((char *)v7 + v12);
    v5 = (u16 *)((char *)v5 + v13);
    --v11;
  }
  while ( v11 );
}

int CPP_fade_zone(unsigned int a1, int a2, int a3, int a4) //FINAL
{
  int result; // eax
  int v5; // ecx
  u8 *v6; // esi
  u8 *v7; // edi
  int v8; // eax
  u8 *v9; // [esp+0h] [ebp-20h]
  int v10; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+8h] [ebp-18h]
  unsigned int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+14h] [ebp-Ch]
  signed int v14; // [esp+18h] [ebp-8h]
  signed int v15; // [esp+1Ch] [ebp-4h]

  v11 = a3;
  v12 = 0;
  v15 = a1 % 0x140 - tube_scroll_x;
  if ( v15 < 0 )
  {
    v12 = tube_scroll_x - a1 % 0x140;
    v11 = v15 + a3;
  }
  result = v15 + v11;
  if ( v15 + v11 > vec_window_width )
  {
    result = vec_window_width - v15;
    v11 = vec_window_width - v15;
  }
  if ( v11 > 0 )
  {
    v9 = (u8 *)(v12 + a2);
    v13 = a4;
    v14 = a1 / 0x140 - tube_scroll_y;
    if ( v14 < 0 )
    {
      v13 = v14 + a4;
      v9 -= v14 * a3;
      v14 = 0;
    }
    result = v14 + v13;
    if ( v14 + v13 > vec_window_height )
    {
      result = vec_window_height - v14;
      v13 = vec_window_height - v14;
    }
    if ( v13 > 0 )
    {
      result = 320 * v14;
      v10 = 320 * v14 + v15 + vec_screen + v12;
      while ( v13 )
      {
        v5 = v11;
        v6 = v9;
        v7 = (u8 *)v10;
        HIWORD(v8) = 0;
        do
        {
          LOBYTE(v8) = *v7;
          BYTE1(v8) = *v6;
          ++v7;
          ++v6;
//          *(v7 - 1) = *(u8 *)(v8 + 2750140); //2750140 29F6BC HARDCODED !!! 0029F6BC tables_start
            *(v7 - 1) = *(u8 *)(v8 + ((int)tables_start));
          --v5;
        }
        while ( v5 );
        v10 += 320;
        v9 += a3;
        result = v13--;
      }
    }
  }
  return result;
}

int CPP_new_starfield(i16 a1, int a2) //FINAL
{
  int result; // eax
  char v3; // dl
  int v4; // [esp+0h] [ebp-24h]
  int v5; // [esp+8h] [ebp-1Ch]
  int v6; // [esp+10h] [ebp-14h]
  int v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+18h] [ebp-Ch]
  int v9; // [esp+1Ch] [ebp-8h]

  v9 = 8 * (u8)a1;
  v5 = HIBYTE(a1);
  result = a2;
  v8 = a2;
  v7 = 0;
  while ( v8 )
  {
    v6 = ((signed)(sintable[v9] * sts[2 * v7]) >> 10) / (v5 + 57) + scroll_x; //здесь signed! иначе звёзды рисуются только в правой верхней четверти экрана!

    if ( (v6 >= 0) && (v6 < vec_window_width) )
    {
      v4 = scroll_y - ((signed)(costable[v9] * sts[2 * v7 + 1]) >> 10) / (v5 + 57); //тоже signed
      if ( (v4 >= 0) && (v4 < vec_window_height) && (!*(u8 *)(v6 + v4 * vec_screen_width + vec_screen)) )
      {

        if ( v5 <= 194 )
          v3 = (v7 & 0x3F) + 32;
        else
          v3 = byte_29F6DC[256 * ((256 - v5) >> 1) + (v7 & 0x3F)];

        *(u8 *)(v6 + v4 * vec_screen_width + vec_screen) = v3;
      }
    }
    v7 = (u8)(v7 + 1);
    v9 = ((u16)v9 + 111) & 0x7FF;
    v5 = (u8)(v5 + 78);
    result = v8--;
  }
  return result;
}

int CPP_draw_tube(void) //FINAL
{
  int result; // eax

  if ( (u8)no_players <= 1u )
  {
    CPP_setup_vecs(WScreen, 0, 320, 320, 200);
    CPP_set_scroll((int)(u16)word_25677C[0] >> 5);
    CPP_omni_map((int) tunnelmap, tube_graphics, scrollpos[0]);
    CPP_fade_zone(fade_offset, fade_out, (u16)fade_width, (u16)fade_height);
    result = CPP_new_starfield(scrollpos[0] + 256, 512);
  }
  else
  {
    CPP_setup_vecs(WScreen, 0, 320, 160, 200);
    CPP_set_scroll((int)(u16)word_25677C[0] >> 5);
    CPP_omni_map((int) tunnelmap, tube_graphics, scrollpos[0]);
    CPP_fade_zone(fade_offset, fade_out, (u16)fade_width, (u16)fade_height);
    CPP_new_starfield(scrollpos[0], 256);

    CPP_setup_vecs(WScreen + 160, 0, 0, 160, 200);
    CPP_set_scroll((int)(u16)word_25679A >> 5);
    CPP_omni_map((int) tunnelmap, tube_graphics + 0x10000, word_2567EA[0]);
    CPP_fade_zone(fade_offset, fade_out, (u16)fade_width, (u16)fade_height);
    result = CPP_new_starfield(word_2567EA[0], 256);
  }
  return result;
}

int CPP_setup_anims(void) //FINAL
{
  u16 v0; // ax
  int result; // eax
  i16 *v2; // [esp+0h] [ebp-Ch]
  u16 v3; // [esp+4h] [ebp-8h]
  i16 v4; // [esp+8h] [ebp-4h]
  u16 i; // [esp+8h] [ebp-4h]

  v2 = (i16 *)level;
  v4 = 0;
  v3 = 0;

  while ( (u16)v4 < 0x8000u && v3 < 0x3E8u )
  {
    if ( *(UA<i32> *)((char *) anim_addresses + 6 * (u16)*v2) )
    {
      anim_blks[5 * v3] = *v2;
      word_22EDAE[5 * v3] = word_2314BC[3 * (u16)*v2];
      word_22EDB0[5 * v3] = v4;
      v0 = v3++;
      *(UA<i32> *)((char *) dword_22EDAA + 10 * v0) = *(UA<i32> *)((char *) anim_addresses + 6 * (u16)*v2);
    }
    ++v4;
    ++v2;
  }

  while ( v3 < 0x3E8u )
    word_22EDB0[5 * v3++] = -1;

  for ( i = 0; ; ++i )
  {
    result = 200 * (u8)no_players;

    if ( i >= result )
      break;

    dword_2344BC[2 * i] = 0;
  }
  return result;
}

char CPP_setup_tube(void) //FINAL
{
  u8 i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < (u8)no_players; ++i )
  {
    scrollpos[i] = 0;
    level_line[i] = 28;
    laps[i] = 0;
    myvx[i] = 0;
    game_over_flag[i] = 0;
    lastscroll[i] = 1;
    flicker[i] = 127;
  }
  memset((char*)tube_graphics, 0, 0x10000u); //CLIB
  return CPP_setup_tube_graphics(level + 63744);
}

u8 CPP_setup_ships(void) //FINAL
{
  u8 result; // al
  u8 i; // [esp+0h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i;

    if ( i >= (u8)no_players )
      break;

    word_25677C[15 * i] = (i + 16) << 11;
    *((u16 *) unk_25677E + 15 * i) = 0x2000;
    *((u16 *) dword_256780 + 15 * i) = 0;
    *((u16 *) dword_256780 + 15 * i + 1) = 0;
    *((u16 *) dword_256784 + 15 * i) = 0;
    *((u8 *) dword_256791 + 30 * i) = 6;
    *((u8 *) dword_256791 + 30 * i + 1) = 0;
    *((u8 *) dword_256791 + 30 * i + 2) = 1;
    *((u8 *) dword_256791 + 30 * i + 3) = 0;
    byte_256788[30 * i] = i;
    *((u8 *) dword_25678D + 30 * i + 3) = 32;
    *((u16 *) dword_256784 + 15 * i + 1) = 20;
    byte_256795[30 * i] = 0;
    *((u8 *) dword_25678D + 30 * i + 2) = 3;
    *(UA<i32> *)((char *) players + 30 * i) = 0;
    byte_256789[30 * i] = 0;
    byte_25678A[30 * i] = 3;
    byte_25678B[30 * i] = 0;
    byte_25678C[30 * i] = 0;
    *((u8 *) dword_25678D + 30 * i) = 0;
    *((u8 *) dword_25678D + 30 * i + 1) = 0;
  }
  return result;
}

int CPP_setup_bullets(void) //FINAL
{
  int result; // eax
  u8 i; // [esp+0h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = 34 * (u8)no_players;

    if ( i >= result )
      break;

    byte_235F58[30 * i] = 0;
  }
  return result;
}

int CPP_setup_aliens(void) //FINAL
{
  int result; // eax
  u8 i; // [esp+0h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = 60 * (u8)no_players;

    if ( i >= result )
      break;

    byte_235148[30 * i] = 0;
  }
  return result;
}

int CPP_do_tube(void) //FINAL
{
  unsigned int *v1; // ebx
//  unsigned int v1;

  int result; // eax
  signed char v3; // [esp+4h] [ebp-2Ch]         добавил signed
  u8 v4; // [esp+8h] [ebp-28h]
  u8 v5; // [esp+Ch] [ebp-24h]
  _BOOL1 v6; // [esp+10h] [ebp-20h]
  u8 v7; // [esp+1Ch] [ebp-14h]
  u8 v8; // [esp+20h] [ebp-10h]
  _BOOL1 v9; // [esp+24h] [ebp-Ch]
  u8 i; // [esp+28h] [ebp-8h]
  char v11; // [esp+2Ch] [ebp-4h]

  v11 = 0;
  if ( !race_finished )
  {
    for ( i = 0; i < (u8)no_players; ++i )
    {
      if ( (*(UA<i32> *)&byte_21F942[2 * i] >> 16) >= -16 )
      {
        if ( vx[i] > 16 )
          vx[i] = 16;
      }
      else
      {
        vx[i] = -16;
      }
      if ( *(UA<i32> *)&byte_21F946[2 * i] >> 16 >= -16 )
      {
        if ( vy[i] > 16 )
          vy[i] = 16;
      }
      else
      {
        vy[i] = -16;
      }

      CPP_check_scroll_change(i);

      LOBYTE(scrollpos[i]) -= LOBYTE(vx[i]);
      HIBYTE(scrollpos[i]) += LOBYTE(vy[i]);
      if ( vy[i] >= 0 )
      {
        if ( vy[i] <= 0 )
        {
          v11 = CPP_check_for_race_end(i);
        }
        else
        {
          while ( 1 )
          {
            v3 = scrollsave[i];          //немного переписал, иначе не выходило из цикла (v6 не была равна 0)
            v5 = HIBYTE(scrollpos[i]);
            v4 = v3 + 8;

//          if ( ((v3 = scrollsave[i], v5 = HIBYTE(scrollpos[i]), v4 = v3 + 8, v3 == -8) || v4 > 0xF0u) && v5 <= 0x10u )
            if(((v3==-8)||v4>0xF0u)&&(v5<=0x10u))
              v6 = 1;
            else
            {
             //v6 = v4 <= v5 && v3 != -8;

             v6=(v4<=v5)&&(v3!=-8);
            }

            if ( !v6 )
              break;

            CPP_scroll_tube(2, i);

            scrollsave[i] += 8;

            v11 = CPP_check_for_race_end(i);
          }
        }
      }
      else
      {
        while ( 1 )
        {
          v7 = HIBYTE(scrollpos[i]);
          v8 = scrollsave[i];

          if ( (v7 > 0xEFu) && (v8 < 0x10u) )
            v9 = 1;
          else
            v9 = (v7 < v8);

          if ( !v9 )
            break;

          CPP_scroll_tube(1, i);

          scrollsave[i] -= 8;

          v11 = CPP_check_for_race_end(i);
        }
      }
    v1 = (unsigned int *)(HIBYTE(scrollpos[i]) - HIBYTE(scrollpos[i]) % 8);
//      v1 = HIBYTE(scrollpos[i]) - HIBYTE(scrollpos[i]) % 8;

    scrollsave[i] = (char)((int)v1); //??? mingw todo
//      scrollsave[i] = (char)v1;

      if ( v11 )
      {
        race_finished = 1;
        dword_256B60 = turn;
        ++wins[i];
        glob_value3 = dword_256B60;
      }

      CPP_check_effects(i);

      CPP_do_anims(i);
      CPP_do_death_sound(/*v1, a1,*/ i, 0);
      CPP_do_swamp_sounds(i);
    }
  }
  if ( (int)abs(turn - dword_256B60) > 63 && race_finished )
  {
    CPP_FadePalette256(0, 0x18u, 0);
    if ( !bonus_game && (result = (u8)level_no + 1, level_no == 2) )
    {
      game_mode = 4;
      fading = 1;
    }
    else
    {
      if ( bonus_game )
      {
        the_score[0] += bonus;
        if ( level_no == 3 )
        {
          BYTE2(dword_256791[0]) = -4; //fix [0]
          level_start = 0;
        }
        if ( bonus )
          ++level_no;
        CPP_load_level(level_no);
      }
      else
      {
        CPP_load_level(++level_no);
      }
      bonus = 4000;
      race_finished = 0;
      game_pause = 0;
      game_mode = 0;
      level_start = 1;
      fading = 1;
      CPP_setup_tube();
      CPP_setup_ships();
      CPP_setup_bullets();
      CPP_setup_aliens();
      blk_collision = 0;
      result = CPP_setup_anims();
    }
  }
  else
  {
    CPP_next_frames();
    result = CPP_draw_tube();
  }
  return result;
}

int CPP_add_extra_life(u8 a3) //FINAL
{
  int result; // eax
//  i64 v4; // [esp-1Ch] [ebp-1Ch]

  if ( no_lives[a3] == 5 )
  {
    result = 30 * a3;
    *(UA<u16> *)((char *) dword_256784 + result + 2) = 20;
  }
  else
  {
//    HIDWORD(v4) = 10;
//    LODWORD(v4) = a3;

//  MY_PlaySample(a1, a2, v4, 0x7FFFu, 0x8000u, 100i64, 3u);
    MY_PlaySample(/*a1, a2, v4,*/ a3 ,0xA, 0x7FFF, 0x8000, 0x64, 0, 3);

    result = a3;
    ++no_lives[a3];
  }
  return result;
}

int CPP_power_up(u8 a3) //FINAL
{
  int result; // eax

  switch ( ++byte_256789[30 * a3] )
  {
    case 1:
    case 2:
    case 3:
    case 7:
    case 8:
    case 12:
    case 13:
      result = 30 * a3;
      *((u8 *) dword_25678D + result + 2) += 3;
      break;
    case 4:
    case 5:
    case 9:
    case 10:
      result = 30 * a3;
      byte_25678B[result] += 2;
      break;
    case 6:
    case 11:
      ++*((u8 *) dword_25678D + 30 * a3);
      *((u8 *) dword_25678D + 30 * a3 + 2) -= 6;
      result = 30 * a3;
      byte_25678B[result] -= 4;
      break;
    case 14:
      *((u8 *) dword_25678D + 30 * a3 + 2) -= 6;
      result = 30 * a3;
      ++byte_25678C[result];
      break;
    case 15:
      result = 30 * a3;
      ++byte_25678C[result];
      break;
    case 16:
      byte_25678C[30 * a3] -= 2;
      result = 30 * a3;
      ++*((u8 *) dword_25678D + result + 1);
      break;
    case 17:
      result = 30 * a3;
      ++*((u8 *) dword_25678D + result + 1);
      break;
    case 18:
      result = 30 * a3;
      ++*((u8 *) dword_25678D + result);
      break;
    default:
      byte_256789[30 * a3] = 19;
      result = CPP_add_extra_life(/*a1, a2,*/ a3);
      break;
  }
  return result;
}

char CPP_check_point_with_players(u8 a1, u16 a2, u16 a3, u16 a4, u16 a5, u16 a6, u16 a7) //FINAL
{
  u16 v8; // [esp+0h] [ebp-Ch]
  char v9; // [esp+8h] [ebp-4h]

  v9 = 0;
  v8 = word_25677C[15 * a1];
  if ( (u16)(a5 + a2) < (u16)(a2 - a5) )
  {
    a2 += 0x8000;
    v8 = word_25677C[15 * a1] + 0x8000;
  }
  if ( (v8 + 1024 >= a2 - a5 && v8 + 1024 <= a5 + a2
     || v8 - 1024 >= a2 - a5 && v8 - 1024 <= a5 + a2
     || v8 >= a2 - a5 && v8 <= a2 + a5)
    && (*((u16 *) unk_25677E + 15 * a1) + 1792 >= a3 - a6
     && *((u16 *) unk_25677E + 15 * a1) + 1792 <= a3 + a6
     || *((u16 *) unk_25677E + 15 * a1) - 1792 >= a3 - a6
     && *((u16 *) unk_25677E + 15 * a1) - 1792 <= a3 + a6
     || *((u16 *) unk_25677E + 15 * a1) >= a3 - a6
     && *((u16 *) unk_25677E + 15 * a1) <= a3 + a6)
    && (*((u16 *) dword_256780 + 15 * a1) + 1536 >= a4
     && *((u16 *) dword_256780 + 15 * a1) + 1536 <= a4 + a7
     || *((u16 *) dword_256780 + 15 * a1) >= a4 && *((u16 *) dword_256780 + 15 * a1) <= a4 + a7
     || *((u16 *) dword_256780 + 15 * a1) + 768 >= a4
     && *((u16 *) dword_256780 + 15 * a1) + 768 <= a4 + a7) )
  {
    v9 = 1;
  }
  return v9;
}

int CPP_lose_life(u8 a3) //FINAL
{
  int result; // eax

  CPP_do_death_sound(/*a1, a2,*/ a3, 1);

  --no_lives[a3];
  if ( *(UA<i32> *)&unk_256B3D[a3] >> 24 >= 1 - (u8)no_players )
  {
    *((u8 *) dword_256791 + 30 * a3 + 1) = 0;
    *((u8 *) dword_256791 + 30 * a3 + 2) = 0;
    byte_256788[30 * a3] = a3;
    *((u16 *) dword_256784 + 15 * a3 + 1) = 20;
    result = a3;
    flicker[a3] = 127;
  }
  else
  {
    *((u8 *) dword_256791 + 30 * a3 + 1) = 0;
    *((u8 *) dword_256791 + 30 * a3 + 2) = 0;
    result = a3;
    game_over_flag[a3] = 1;
    if ( level_no != 3 )
    {
      result = a3;
      flicker[a3] = 127;
    }
    if ( no_players == 1 && game_over_flag[0] || game_over_flag[0] && byte_256B39 )
      fading = 2;
  }
  return result;
}

char CPP_check_alien_to_players(u8 a3, int a4) //FINAL
{
  char result; // al
//  i64 v5; // [esp-1Ch] [ebp-34h]
//  i64 v6; // [esp-1Ch] [ebp-34h]
//  i64 v7; // [esp-1Ch] [ebp-34h]
//  i64 v8; // [esp-1Ch] [ebp-34h]
//  i64 v9; // [esp-1Ch] [ebp-34h]
  u8 v10; // [esp+8h] [ebp-10h]
  u16 v11; // [esp+Ch] [ebp-Ch]
  u16 v12; // [esp+10h] [ebp-8h]
  u16 v13; // [esp+14h] [ebp-4h]

  v10 = *(u8 *)(a4 + 16);
  if ( v10 < 0xFu )
  {
    if ( v10 >= 8u )
    {
      if ( v10 > 8u )
      {
        if ( v10 >= 0xBu )
        {
          if ( v10 <= 0xBu )
          {
            v13 = 512;
            v11 = 1024;
            v12 = 1024;
          }
          else if ( v10 == 12 )
          {
            result = CPP_check_point_with_players(
                       a3,
                       *(UA<u16> *)(a4 + 4),
                       *(UA<u16> *)(a4 + 6),
                       *(UA<u16> *)(a4 + 8),
                       0x300u,
                       0x300u,
                       0x600u);
            goto LABEL_31;
          }
        }
        goto LABEL_30;
      }
      goto LABEL_27;
    }
    if ( v10 < 6u )
      goto LABEL_30;
    if ( v10 > 6u )
    {
      result = CPP_check_point_with_players(
                 a3,
                 *(UA<u16> *)(a4 + 4),
                 *(UA<u16> *)(a4 + 6),
                 *(UA<u16> *)(a4 + 8),
                 0x700u,
                 0x700u,
                 0x800u);
      goto LABEL_31;
    }
    goto LABEL_25;
  }
  if ( v10 <= 0xFu )
    goto LABEL_27;
  if ( v10 < 0x15u )
  {
    if ( v10 > 0x10u )
    {
      if ( v10 == 17 )
      {
        result = CPP_check_point_with_players(
                   a3,
                   *(UA<u16> *)(a4 + 4),
                   *(UA<u16> *)(a4 + 6),
                   *(UA<u16> *)(a4 + 8),
                   0x700u,
                   0x800u,
                   0x800u);
        goto LABEL_31;
      }
      goto LABEL_30;
    }
    goto LABEL_27;
  }
  if ( v10 <= 0x15u )
  {
LABEL_25:
    result = CPP_check_point_with_players(
               a3,
               *(UA<u16> *)(a4 + 4),
               *(UA<u16> *)(a4 + 6),
               *(UA<u16> *)(a4 + 8),
               0x500u,
               0x500u,
               0xC00u);
    goto LABEL_31;
  }
  if ( v10 < 0x17u )
    goto LABEL_30;
  if ( v10 <= 0x17u )
  {
LABEL_27:
    result = CPP_check_point_with_players(
               a3,
               *(UA<u16> *)(a4 + 4),
               *(UA<u16> *)(a4 + 6),
               *(UA<u16> *)(a4 + 8),
               0x800u,
               0xA00u,
               0x800u);
    goto LABEL_31;
  }
  if ( v10 == 49 )
    goto LABEL_25;
LABEL_30:
  result = CPP_check_point_with_players(a3, *(UA<u16> *)(a4 + 4), *(UA<u16> *)(a4 + 6), *(UA<u16> *)(a4 + 8), v11, v12, v13);
LABEL_31:
  if ( result )
  {
    if ( *(u8 *)(a4 + 16) == 21 )
    {
//      HIDWORD(v5) = 3;
//      LODWORD(v5) = a3;

//    MY_PlaySample(a1, a2, v5, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
      MY_PlaySample(/*a1, a2, v5,*/ a3, 3, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

      *(u8 *)(a4 + 16) = 0;
      result = CPP_power_up(/*a1, a2,*/ a3);
    }
    else if ( *(u8 *)(a4 + 16) == 49 )
    {
//      HIDWORD(v6) = 3;
//      LODWORD(v6) = a3;

//    MY_PlaySample(a1, a2, v6, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
      MY_PlaySample(/*a1, a2, v6,*/ a3, 3, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

      *(u8 *)(a4 + 16) = 0;
      result = 30 * a3;
      if ( (u8)byte_25678A[30 * a3] <= 4u )
      {
        result = 30 * a3;
        ++byte_25678A[30 * a3];
      }
    }
    else
    {
      if ( !*(UA<i32> *)((char *) players + 30 * a3) )
      {
        *((u16 *) dword_256784 + 15 * a3 + 1) -= *(UA<u16> *)(a4 + 14);
        if ( *((i16 *) dword_256784 + 15 * a3 + 1) < 0 )
          CPP_lose_life(/*a1, a2,*/ a3);
      }
      if ( *(u8 *)(a4 + 16) == 6 )
      {
//        HIDWORD(v7) = 15;
//        LODWORD(v7) = a3;

//      MY_PlaySample(a1, a2, v7, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
        MY_PlaySample(/*a1, a2, v7,*/ a3, 0xF , 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

        *(UA<u16> *)(a4 + 12) = 0;
        *(u8 *)(a4 + 16) = 21;
        *(u8 *)(a4 + 24) = 0;
        result = a4;
        *(UA<u16> *)(a4 + 14) = 127;
      }
      else if ( *(u8 *)(a4 + 16) == 11 )
      {
//        HIDWORD(v8) = 7;
//        LODWORD(v8) = a3;

//      MY_PlaySample(a1, a2, v8, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
        MY_PlaySample(/*a1, a2, v8,*/ a3 ,7 ,0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

        *(u8 *)(a4 + 16) = 41;
        *(UA<u16> *)(a4 + 10) = 0;
        result = a4;
        *(UA<u16> *)(a4 + 12) = 0;
      }
      else
      {
//        HIDWORD(v9) = 6;
//        LODWORD(v9) = a3;

//      MY_PlaySample(a1, a2, v9, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
        MY_PlaySample(/*a1, a2, v9,*/ a3 ,6 ,0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

        *(u8 *)(a4 + 16) = 25;
        *(UA<u16> *)(a4 + 12) = 0;
        result = a4;
        *(UA<u16> *)(a4 + 10) = 0;
      }
    }
  }
  return result;
}

char CPP_insert_effect(u16 a1, u16 a2, i16 a3) //FINAL
{
  int v3; // eax
  u8 j; // [esp+40h] [ebp-2Ch]
  char v6; // [esp+64h] [ebp-8h]
  u8 i; // [esp+68h] [ebp-4h]

  v6 = 0;
  for ( i = 0; ; ++i )
  {
    v3 = effect_list + 6 * i;
    if ( !*(UA<u16> *)(v3 + 4) || i >= 0x64u || v6 )
      break;
    if ( *(UA<u16> *)(effect_list + 6 * i) <= a2 && *(UA<u16> *)(effect_list + 6 * i + 2) <= a1 )
    {
      v6 = 1;
      if ( *(UA<u16> *)(effect_list + 6 * i) == a2 && *(UA<u16> *)(effect_list + 6 * i + 2) == a1 )
      {
        *(UA<u16> *)(6 * i + effect_list + 2) = a1;
        *(UA<u16> *)(6 * i + effect_list) = a2;
        *(UA<u16> *)(6 * i + effect_list + 4) = a3;
      }
      else
      {
        for ( j = i; *(UA<u16> *)(effect_list + 6 * j + 4) && j < 0x64u; ++j )
          ;
        if ( j != 100 )
        {
          while ( j > i )
          {
            *(UA<u16> *)(6 * j + effect_list + 2) = *(UA<u16> *)(effect_list + 6 * (j - 1) + 2);
            *(UA<u16> *)(6 * j + effect_list) = *(UA<u16> *)(effect_list + 6 * (j - 1));
            *(UA<u16> *)(6 * j + effect_list + 4) = *(UA<u16> *)(effect_list + 6 * (j - 1) + 4);
            --j;
          }
          *(UA<u16> *)(6 * i + effect_list + 2) = a1;
          *(UA<u16> *)(6 * i + effect_list) = a2;
          *(UA<u16> *)(6 * i + effect_list + 4) = a3;
        }
      }
    }
  }
  if ( !v6 )
  {
    LOBYTE(v3) = i;
    if ( i != 100 )
    {
      *(UA<u16> *)(6 * i + effect_list + 2) = a1;
      *(UA<u16> *)(6 * i + effect_list) = a2;
      LOBYTE(v3) = a3;
      *(UA<u16> *)(6 * i + effect_list + 4) = a3;
    }
  }
  return v3;
}

u8 CPP_do_aliens(void)
{
  u8 result; // al
  char v3; // dl
  int v4; // eax
  int v5; // eax
  int v6; // edx
  i16 v7; // dx
  int v8; // ebx
  int v9; // ebx
  char v10; // dl
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // ebx
  int v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // edx
  char v26; // dl
  int v27; // eax
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // ebx
  int v32; // ebx
  int v33; // eax
  int v34; // eax
  int v35; // edx
  int v36; // ebx
  int v37; // ebx
  int v38; // eax
  int v39; // eax
  int v40; // edx
  int v41; // ebx
  int v42; // ebx
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // edx
  int v47; // ebx
  int v48; // ebx
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // edx
//  i64 v53; // [esp-1Ch] [ebp-344h]
  signed int v54; // [esp+28h] [ebp-300h]
  int v55; // [esp+2Ch] [ebp-2FCh]
  u16 v56; // [esp+30h] [ebp-2F8h]
  int v57; // [esp+74h] [ebp-2B4h]
  u16 v58; // [esp+94h] [ebp-294h]
  signed int v59; // [esp+98h] [ebp-290h]
  int v60; // [esp+9Ch] [ebp-28Ch]
  u16 v61; // [esp+A0h] [ebp-288h]
  int v62; // [esp+E4h] [ebp-244h]
  u16 v63; // [esp+104h] [ebp-224h]
  int v64; // [esp+134h] [ebp-1F4h]
  u16 v65; // [esp+154h] [ebp-1D4h]
  signed int v66; // [esp+158h] [ebp-1D0h]
  int v67; // [esp+15Ch] [ebp-1CCh]
  int v68; // [esp+160h] [ebp-1C8h]
  int v69; // [esp+1A4h] [ebp-184h]
  u16 v70; // [esp+1C4h] [ebp-164h]
  signed int v71; // [esp+240h] [ebp-E8h]
  int v72; // [esp+244h] [ebp-E4h]
  u16 v73; // [esp+248h] [ebp-E0h]
  int v74; // [esp+28Ch] [ebp-9Ch]
  u16 v75; // [esp+2ACh] [ebp-7Ch]
  int v76; // [esp+2DCh] [ebp-4Ch]
  u16 v77; // [esp+2FCh] [ebp-2Ch]
  UA<i32> *v78; // [esp+304h] [ebp-24h]
  u16 v79; // [esp+308h] [ebp-20h]
  u16 v80; // [esp+308h] [ebp-20h]
  u16 v81; // [esp+308h] [ebp-20h]
  u16 v82; // [esp+308h] [ebp-20h]
  u16 v83; // [esp+308h] [ebp-20h]
  u16 v84; // [esp+30Ch] [ebp-1Ch]
  u16 v85; // [esp+30Ch] [ebp-1Ch]
  u16 v86; // [esp+30Ch] [ebp-1Ch]
  u16 v87; // [esp+30Ch] [ebp-1Ch]
  u16 v88; // [esp+314h] [ebp-14h]
  u16 v89; // [esp+314h] [ebp-14h]
  u16 v90; // [esp+314h] [ebp-14h]
  u16 v91; // [esp+314h] [ebp-14h]
  u16 v92; // [esp+314h] [ebp-14h]
  u16 v93; // [esp+314h] [ebp-14h]
  u16 v94; // [esp+314h] [ebp-14h]
  u16 v95; // [esp+314h] [ebp-14h]
  u16 v96; // [esp+314h] [ebp-14h]
  u16 v97; // [esp+314h] [ebp-14h]
  u16 v98; // [esp+31Ch] [ebp-Ch]
  u16 v99; // [esp+31Ch] [ebp-Ch]
  u16 v100; // [esp+31Ch] [ebp-Ch]
  u16 v101; // [esp+31Ch] [ebp-Ch]
  u16 v102; // [esp+31Ch] [ebp-Ch]
  u16 v103; // [esp+31Ch] [ebp-Ch]
  u8 j; // [esp+320h] [ebp-8h]
  u8 i; // [esp+324h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= (u8)no_players )
      break;
    v78 = (UA<i32>*)&aliens[450 * i];
    for ( j = 0; j < 0x3Cu; ++j )
    {
      switch ( *((u8 *)v78 + 16) )
      {
        case 6:
          v17 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v90 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v17 - (__CFSHL__(v17 >> 31, 3) + 8 * (v17 >> 31))) >> 3))
              % 32;
          v18 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v19 = (((v18 - (__CFSHL__(v18 >> 31, 3) + 8 * (v18 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v19 = (((v18 - (__CFSHL__(v18 >> 31, 3) + 8 * (v18 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          *((u16 *)v78 + 2) += -256 * vx[i];
          *((u16 *)v78 + 3) += (u16)vy[i] << 8; //shft fix
          *((u16 *)v78 + 5) += 36;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
            goto LABEL_301;

          CPP_insert_effect(v90, 1023 - v19, 36);

          *((u8 *)v78 + 16) = 0;
          break;
        case 7:
          v98 = *((u16 *) unk_25677E + 15 * i);
          if ( v98 >= *((u16 *)v78 + 3) )
            v3 = -*((u8 *)v78 + 24);
          else
            v3 = *((u8 *)v78 + 24);
          *((u8 *)v78 + 27) = v3;
          *((u16 *)v78 + 2) += -256 * vx[i];
          v77 = *((u16 *)v78 + 2);
          v76 = v77;
          if ( v77 >= 0x7800u )
          {
            if ( v77 - 0x8000 > v77 )
              HIWORD(v76) = 1;
          }
          else if ( v77 + 0x8000 < v77 )
          {
            v76 = v77 - 0x10000;
          }
          v84 = CPP_arctan(v76 - v77, *((u16 *)v78 + 3) - v98);
          v4 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v88 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v4 - (__CFSHL__(v4 >> 31, 3) + 8 * (v4 >> 31))) >> 3)) % 32;
          v5 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v6 = (((v5 - (__CFSHL__(v5 >> 31, 3) + 8 * (v5 >> 31))) >> 3) - 4 + (u16)level_line[i] + 994)
               % 1024;
          else
            v6 = (((v5 - (__CFSHL__(v5 >> 31, 3) + 8 * (v5 >> 31))) >> 3) - 4 + (u16)level_line[i] + 1027)
               % 1024;
          v99 = 1023 - v6;
          v7 = -256 * vy[i];
          if ( v78[2] >> 16 == v84 )
            v7 = ( *((char *)v78 + 27) SHL6) - (vy[i] SHL8); //shift fix
          *((u16 *)v78 + 3) -= v7;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
          {
            v8 = abs((v78[2] >> 16) - v84);
            if ( v8 <= abs((v78[2] >> 16) - v84 + 2024) )
            {
              v9 = abs((v78[2] >> 16) - v84);
              if ( v9 > abs((v78[2] >> 16) - v84 - 2024) )
                *((u16 *)v78 + 5) -= 2024;
            }
            else
            {
              *((u16 *)v78 + 5) += 2024;
            }
            if ( v78[2] >> 16 >= v84 )
            {
              if ( v78[2] >> 16 > v84 )
              {
                *((u16 *)v78 + 5) -= 36;
                if ( v78[2] >> 16 < v84 )
                  *((u16 *)v78 + 5) = v84;
              }
            }
            else
            {
              *((u16 *)v78 + 5) += 36;
              if ( v78[2] >> 16 > v84 )
                *((u16 *)v78 + 5) = v84;
            }
            goto LABEL_157;
          }
          CPP_insert_effect(v88, v99, 34);
          *((u8 *)v78 + 16) = 0;
          break;
        case 8:
          v93 = word_25677C[15 * i];
          v101 = *((u16 *) unk_25677E + 15 * i);
          v70 = *((u16 *)v78 + 2);
          v69 = v93;
          if ( v70 >= 0x7800u )
          {
            if ( v70 - 0x8000 > v93 )
              HIWORD(v69) = 1;
          }
          else if ( v70 + 0x8000 < v93 )
          {
            v69 = v93 - 0x10000;
          }
          v86 = CPP_arctan(v69 - v70, *((u16 *)v78 + 3) - v101);
          if ( v101 >= *((u16 *)v78 + 3) )
            v26 = -*((u8 *)v78 + 24);
          else
            v26 = *((u8 *)v78 + 24);
          *((u8 *)v78 + 27) = v26;
          *((u16 *)v78 + 2) += -256 * vx[i];
          *((u16 *)v78 + 3) -= -256 * vy[i];
          v27 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v80 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v27 - (__CFSHL__(v27 >> 31, 3) + 8 * (v27 >> 31))) >> 3))
              % 32;
          v28 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v29 = (((v28 - (__CFSHL__(v28 >> 31, 3) + 8 * (v28 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v29 = (((v28 - (__CFSHL__(v28 >> 31, 3) + 8 * (v28 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
          {
            v68 = abs(*(UA<i32> *)((char *)v78 + 21) >> 24) << 6;
            v67 = v93;
            v66 = *((u16 *)v78 + 2);
            if ( (unsigned int)v66 >= 0x7800 )
            {
              if ( v66 - 0x8000 > v93 )
                HIWORD(v67) = 1;
            }
            else if ( v66 + 0x8000 < v93 )
            {
              v67 = v93 - 0x10000;
            }
            if ( v66 >= v67 )
              v30 = (-(u16)v68
                   - (__CFSHL__(-(u16)v68 >> 31, 6)
                    + ( ((-(u16)v68) >> 31) SHL6))) >> 6; //shift fix
            else
              v30 = (int)(u16)v68 >> 6;
            *((u8 *)v78 + 26) = v30;
            if ( v66 >= v67 )
            {
              if ( v66 > v67 )
              {
                v66 -= (u16)v68;
                if ( v66 < v67 )
                  LOWORD(v66) = v67;
              }
            }
            else
            {
              v66 += (u16)v68;
              if ( v66 > v67 )
                LOWORD(v66) = v67;
            }
            *((u16 *)v78 + 2) = v66;
            if ( *((u16 *)v78 + 3) >= v101 )
            {
              if ( *((u16 *)v78 + 3) > v101 )
              {
                *((u16 *)v78 + 3) -= abs(  ((v78[6] >> 24) SHL6)); //shift fix
                if ( *((u16 *)v78 + 3) < v101 )
                  *((u16 *)v78 + 3) = v101;
              }
            }
            else
            {
              *((u16 *)v78 + 3) += abs(  ((v78[6] >> 24) SHL6)); //shift fix
              if ( *((u16 *)v78 + 3) > v101 )
                *((u16 *)v78 + 3) = v101;
            }
            v31 = abs((v78[2] >> 16) - v86);
            if ( v31 <= abs((v78[2] >> 16) - v86 + 2024) )
            {
              v32 = abs((v78[2] >> 16) - v86);
              if ( v32 > abs((v78[2] >> 16) - v86 - 2024) )
                *((u16 *)v78 + 5) -= 2024;
            }
            else
            {
              *((u16 *)v78 + 5) += 2024;
            }
            if ( v78[2] >> 16 >= v86 )
            {
              if ( v78[2] >> 16 > v86 )
              {
                *((u16 *)v78 + 5) -= 36;
                if ( v78[2] >> 16 < v86 )
                  *((u16 *)v78 + 5) = v86;
              }
            }
            else
            {
              *((u16 *)v78 + 5) += 36;
              if ( v78[2] >> 16 > v86 )
                *((u16 *)v78 + 5) = v86;
            }
            goto LABEL_157;
          }
          CPP_insert_effect(v80, 1023 - v29, 39);
          *((u8 *)v78 + 16) = 0;
          break;
        case 0xB:
          *((u16 *)v78 + 5) += 72;
          *((u16 *)v78 + 6) += 72;
          *((u16 *)v78 + 2) += ( *((char *)v78 + 26)  SHL8) - (vx[i]  SHL8); //shift fix
          *((u16 *)v78 + 3) -= ( *((char *)v78 + 27)  SHL8) - (vy[i]  SHL8); //shift fix
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
          {
            if ( --*v78 != -1 )
              goto LABEL_294;
//            HIDWORD(v53) = 7;
//            LODWORD(v53) = i;
/*
            MY_PlaySample(
              (unsigned int *)a1,
              a2,
              v53,
              0x7FFFu,
              -2 - 0x7FFF * (u8)no_players - 200,
              100i64,
              3u);
*/
            MY_PlaySample(/*(unsigned int *)a1, a2, v53,*/ i , 7, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

            *((u8 *)v78 + 16) = 41;
          }
          else
          {
            *((u8 *)v78 + 16) = 0;
          }
          break;
        case 0xC:
          v23 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v92 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v23 - (__CFSHL__(v23 >> 31, 3) + 8 * (v23 >> 31))) >> 3))
              % 32;
          v24 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v25 = (((v24 - (__CFSHL__(v24 >> 31, 3) + 8 * (v24 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v25 = (((v24 - (__CFSHL__(v24 >> 31, 3) + 8 * (v24 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          *((u16 *)v78 + 2) += -256 * vx[i];
          *((u16 *)v78 + 3) += vy[i]  SHL8; //shift fix
          *((u16 *)v78 + 5) += 36;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
            goto LABEL_301;
          CPP_insert_effect(v92, 1023 - v25, 38);
          *((u8 *)v78 + 16) = 0;
          break;
        case 0xF:
          v95 = word_25677C[15 * i];
          v102 = *((u16 *) unk_25677E + 15 * i);
          v63 = *((u16 *)v78 + 2);
          v62 = v95;
          if ( v63 >= 0x7800u )
          {
            if ( v63 - 0x8000 > v95 )
              HIWORD(v62) = 1;
          }
          else if ( v63 + 0x8000 < v95 )
          {
            v62 = v95 - 0x10000;
          }
          v87 = CPP_arctan(v62 - v63, *((u16 *)v78 + 3) - v102);
          *((u8 *)v78 + 27) = *((u8 *)v78 + 24);
          *((u16 *)v78 + 2) += -256 * vx[i];
          *((u16 *)v78 + 3) -= -256 * vy[i];
          v38 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v82 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v38 - (__CFSHL__(v38 >> 31, 3) + 8 * (v38 >> 31))) >> 3))
              % 32;
          v39 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v40 = (((v39 - (__CFSHL__(v39 >> 31, 3) + 8 * (v39 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v40 = (((v39 - (__CFSHL__(v39 >> 31, 3) + 8 * (v39 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
          {
            v41 = abs((v78[2] >> 16) - v87);
            if ( v41 <= abs((v78[2] >> 16) - v87 + 2024) )
            {
              v42 = abs((v78[2] >> 16) - v87);
              if ( v42 > abs((v78[2] >> 16) - v87 - 2024) )
                *((u16 *)v78 + 5) -= 2024;
            }
            else
            {
              *((u16 *)v78 + 5) += 2024;
            }
            if ( v78[2] >> 16 >= v87 )
            {
              if ( v78[2] >> 16 > v87 )
              {
                *((u16 *)v78 + 5) -= 72;
                if ( v78[2] >> 16 < v87 )
                  *((u16 *)v78 + 5) = v87;
              }
            }
            else
            {
              *((u16 *)v78 + 5) += 72;
              if ( v78[2] >> 16 > v87 )
                *((u16 *)v78 + 5) = v87;
            }
//            a1 = 2024;
            *((i16 *)v78 + 5) %= 2024;
            if ( *((u16 *)v78 + 3) >= v102 )
            {
              if ( *((u16 *)v78 + 3) > v102 )
              {
                *((u16 *)v78 + 3) -= abs(v78[6] >> 24 << 6);
                if ( *((u16 *)v78 + 3) < v102 )
                  *((u16 *)v78 + 3) = v102;
              }
            }
            else
            {
              *((u16 *)v78 + 3) += abs(v78[6] >> 24 << 6);
              if ( *((u16 *)v78 + 3) > v102 )
                *((u16 *)v78 + 3) = v102;
            }
            v61 = abs(*(UA<i32> *)((char *)v78 + 21) >> 24 << 6);
            v60 = v95;
            v59 = *((u16 *)v78 + 2);
            if ( (unsigned int)v59 >= 0x7800 )
            {
              if ( v59 - 0x8000 > v95 )
                HIWORD(v60) = 1;
            }
            else if ( v59 + 0x8000 < v95 )
            {
              v60 = v95 - 0x10000;
            }
            if ( v59 >= v60 )
              v43 = (-v61 - (__CFSHL__(-v61 >> 31, 6) + ( ((-v61) >> 31) SHL6))) >> 6; //shift fix
            else
              v43 = (int)v61 >> 6;
            *((u8 *)v78 + 26) = v43;
            if ( v59 >= v60 )
            {
              if ( v59 > v60 )
              {
                v59 -= v61;
                if ( v59 < v60 )
                  LOWORD(v59) = v60;
              }
            }
            else
            {
              v59 += v61;
              if ( v59 > v60 )
                LOWORD(v59) = v60;
            }
            *((u16 *)v78 + 2) = v59;
            if ( v78[2] >> 16 == v87 && (int)abs(*v78 - turn) > 14 )
              goto LABEL_293;
            goto LABEL_294;
          }
          CPP_insert_effect(v82, 1023 - v40, 41);
          *((u8 *)v78 + 16) = 0;
          break;
        case 0x10:
          v94 = word_25677C[15 * i];
          v65 = *((u16 *)v78 + 2);
          v64 = v94;
          if ( v65 >= 0x7800u )
          {
            if ( v65 - 0x8000 > v94 )
              HIWORD(v64) = 1;
          }
          else if ( v65 + 0x8000 < v94 )
          {
            v64 = v94 - 0x10000;
          }
          v87 = CPP_arctan(v64 - v65, *((u16 *)v78 + 3) - *((u16 *) unk_25677E + 15 * i));
          *((u16 *)v78 + 2) += -256 * vx[i];
          *((u16 *)v78 + 3) -= -256 * vy[i];
          v33 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v81 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v33 - (__CFSHL__(v33 >> 31, 3) + 8 * (v33 >> 31))) >> 3))
              % 32;
          v34 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v35 = (((v34 - (__CFSHL__(v34 >> 31, 3) + 8 * (v34 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v35 = (((v34 - (__CFSHL__(v34 >> 31, 3) + 8 * (v34 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
          {
            v36 = abs((v78[2] >> 16) - v87);
            if ( v36 <= abs((v78[2] >> 16) - v87 + 2024) )
            {
              v37 = abs((v78[2] >> 16) - v87);
              if ( v37 > abs((v78[2] >> 16) - v87 - 2024) )
                *((u16 *)v78 + 5) -= 2024;
            }
            else
            {
              *((u16 *)v78 + 5) += 2024;
            }
            if ( v78[2] >> 16 >= v87 )
            {
              if ( v78[2] >> 16 > v87 )
              {
                *((u16 *)v78 + 5) -= 36;
                if ( v78[2] >> 16 < v87 )
                  *((u16 *)v78 + 5) = v87;
              }
            }
            else
            {
              *((u16 *)v78 + 5) += 36;
              if ( v78[2] >> 16 > v87 )
                *((u16 *)v78 + 5) = v87;
            }
//            a1 = 2024;
            *((i16 *)v78 + 5) %= 2024;
            if ( v78[2] >> 16 == v87 && (int)abs(*v78 - turn) > 28 )
              goto LABEL_293;
            goto LABEL_294;
          }
          CPP_insert_effect(v81, 1023 - v35, 40);
          *((u8 *)v78 + 16) = 0;
          break;
        case 0x11:
          v89 = word_25677C[15 * i];
          v100 = *((u16 *) unk_25677E + 15 * i);
          v75 = *((u16 *)v78 + 2);
          v74 = v89;
          if ( v75 >= 0x7800u )
          {
            if ( v75 - 0x8000 > v89 )
              HIWORD(v74) = 1;
          }
          else if ( v75 + 0x8000 < v89 )
          {
            v74 = v89 - 0x10000;
          }
          v85 = CPP_arctan(v74 - v75, *((u16 *)v78 + 3) - v100);
          if ( v100 >= *((u16 *)v78 + 3) )
            v10 = -*((u8 *)v78 + 24);
          else
            v10 = *((u8 *)v78 + 24);
          *((u8 *)v78 + 27) = v10;
          *((u16 *)v78 + 2) += -256 * vx[i];
          *((u16 *)v78 + 3) -= -256 * vy[i];
          v11 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v79 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v11 - (__CFSHL__(v11 >> 31, 3) + 8 * (v11 >> 31))) >> 3))
              % 32;
          v12 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v13 = (((v12 - (__CFSHL__(v12 >> 31, 3) + 8 * (v12 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v13 = (((v12 - (__CFSHL__(v12 >> 31, 3) + 8 * (v12 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
          {
            v73 = abs(*(UA<i32> *)((char *)v78 + 21) >> 24 << 6);
            v72 = v89;
            v71 = *((u16 *)v78 + 2);
            if ( (unsigned int)v71 >= 0x7800 )
            {
              if ( v71 - 0x8000 > v89 )
                HIWORD(v72) = 1;
            }
            else if ( v71 + 0x8000 < v89 )
            {
              v72 = v89 - 0x10000;
            }
            if ( v71 >= v72 )
              v14 = (-v73 - (__CFSHL__(-v73 >> 31, 6) + (((-v73) >> 31) SHL6))) >> 6; //shift fix
            else
              v14 = (int)v73 >> 6;
            *((u8 *)v78 + 26) = v14;
            if ( v71 >= v72 )
            {
              if ( v71 > v72 )
              {
                v71 -= v73;
                if ( v71 < v72 )
                  LOWORD(v71) = v72;
              }
            }
            else
            {
              v71 += v73;
              if ( v71 > v72 )
                LOWORD(v71) = v72;
            }
            *((u16 *)v78 + 2) = v71;
            if ( *((u16 *)v78 + 3) >= v100 )
            {
              if ( *((u16 *)v78 + 3) > v100 )
              {
                *((u16 *)v78 + 3) -= abs(v78[6] >> 24 << 6);
                if ( *((u16 *)v78 + 3) < v100 )
                  *((u16 *)v78 + 3) = v100;
              }
            }
            else
            {
              *((u16 *)v78 + 3) += abs( (v78[6] >> 24) SHL6); //shift fix
              if ( *((u16 *)v78 + 3) > v100 )
                *((u16 *)v78 + 3) = v100;
            }
            v15 = abs((v78[2] >> 16) - v85);
            if ( v15 <= abs((v78[2] >> 16) - v85 + 2024) )
            {
              v16 = abs((v78[2] >> 16) - v85);
              if ( v16 > abs((v78[2] >> 16) - v85 - 2024) )
                *((u16 *)v78 + 5) -= 2024;
            }
            else
            {
              *((u16 *)v78 + 5) += 2024;
            }
            if ( v78[2] >> 16 >= v85 )
            {
              if ( v78[2] >> 16 > v85 )
              {
                *((u16 *)v78 + 5) -= 36;
                if ( v78[2] >> 16 < v85 )
                  *((u16 *)v78 + 5) = v85;
              }
            }
            else
            {
              *((u16 *)v78 + 5) += 36;
              if ( v78[2] >> 16 > v85 )
                *((u16 *)v78 + 5) = v85;
            }
LABEL_157:
//            a1 = 2024;
            *((i16 *)v78 + 5) %= 2024;
            CPP_check_alien_to_players( /* (unsigned int *)0x7E8, a2,*/  i, (int)v78);
          }
          else
          {
            CPP_insert_effect(v79, 1023 - v13, 35);
            *((u8 *)v78 + 16) = 0;
          }
          break;
        case 0x15:
          v20 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v91 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v20 - (__CFSHL__(v20 >> 31, 3) + 8 * (v20 >> 31))) >> 3))
              % 32;
          v21 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v22 = (((v21 - (__CFSHL__(v21 >> 31, 3) + 8 * (v21 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v22 = (((v21 - (__CFSHL__(v21 >> 31, 3) + 8 * (v21 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          *((u16 *)v78 + 2) += -256 * vx[i];
          *((u16 *)v78 + 3) += vy[i]  SHL8; //shift fix
          *((u16 *)v78 + 5) += 36;
          *((u16 *)v78 + 6) += 36;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
            goto LABEL_301;
          CPP_insert_effect(v91, 1023 - v22, 37);
          *((u8 *)v78 + 16) = 0;
          break;
        case 0x17:
          v96 = word_25677C[15 * i];
          v103 = *((u16 *) unk_25677E + 15 * i);
          v58 = *((u16 *)v78 + 2);
          v57 = v96;
          if ( v58 >= 0x7800u )
          {
            if ( v58 - 0x8000 > v96 )
              HIWORD(v57) = 1;
          }
          else if ( v58 + 0x8000 < v96 )
          {
            v57 = v96 - 0x10000;
          }
          v87 = CPP_arctan(v57 - v58, *((u16 *)v78 + 3) - v103);
          *((u16 *)v78 + 2) += -256 * vx[i];
          v44 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v83 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v44 - (__CFSHL__(v44 >> 31, 3) + 8 * (v44 >> 31))) >> 3))
              % 32;
          v45 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v46 = (((v45 - (__CFSHL__(v45 >> 31, 3) + 8 * (v45 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v46 = (((v45 - (__CFSHL__(v45 >> 31, 3) + 8 * (v45 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
          {
            v47 = abs((v78[2] >> 16) - v87);
            if ( v47 <= abs((v78[2] >> 16) - v87 + 2024) )
            {
              v48 = abs((v78[2] >> 16) - v87);
              if ( v48 > abs((v78[2] >> 16) - v87 - 2024) )
                *((u16 *)v78 + 5) -= 2024;
            }
            else
            {
              *((u16 *)v78 + 5) += 2024;
            }
            if ( v78[2] >> 16 >= v87 )
            {
              if ( v78[2] >> 16 > v87 )
              {
                *((u16 *)v78 + 5) -= 72;
                if ( v78[2] >> 16 < v87 )
                  *((u16 *)v78 + 5) = v87;
              }
            }
            else
            {
              *((u16 *)v78 + 5) += 72;
              if ( v78[2] >> 16 > v87 )
                *((u16 *)v78 + 5) = v87;
            }
//            a1 = 2024;
            *((i16 *)v78 + 5) %= 2024;
            if ( *((u16 *)v78 + 3) >= v103 + 10240 )
            {
              if ( *((u16 *)v78 + 3) > v103 + 10240 )
              {
                *((u16 *)v78 + 3) -= *((char *)v78 + 24) << 6;
                if ( *((u16 *)v78 + 3) < v103 + 10240 )
                  *((u16 *)v78 + 3) = v103 + 10240;
              }
            }
            else
            {
              *((u16 *)v78 + 3) += *((char *)v78 + 24) << 6;
              if ( *((u16 *)v78 + 3) > v103 + 10240 )
                *((u16 *)v78 + 3) = v103 + 10240;
            }
            if ( (int)abs(*((u16 *)v78 + 2) - v96) <= 10240 )
            {
              *((u16 *)v78 + 2) += *((char *)v78 + 26) << 6;
            }
            else
            {
              v56 = *((char *)v78 + 24) << 6;
              v55 = v96;
              v54 = *((u16 *)v78 + 2);
              if ( (unsigned int)v54 >= 0x7800 )
              {
                if ( v54 - 0x8000 > v96 )
                  HIWORD(v55) = 1;
              }
              else if ( v54 + 0x8000 < v96 )
              {
                v55 = v96 - 0x10000;
              }
              if ( v54 >= v55 )
                v49 = (-v56 - (__CFSHL__(-v56 >> 31, 6) + (-v56 >> 31 << 6))) >> 6;
              else
                v49 = (int)v56 >> 6;
              *((u8 *)v78 + 26) = v49;
              if ( v54 >= v55 )
              {
                if ( v54 > v55 )
                {
                  v54 -= v56;
                  if ( v54 < v55 )
                    LOWORD(v54) = v55;
                }
              }
              else
              {
                v54 += v56;
                if ( v54 > v55 )
                  LOWORD(v54) = v55;
              }
              *((u16 *)v78 + 2) = v54;
            }
            if ( v78[2] >> 16 == v87 && (int)abs(*v78 - turn) > 14 )
            {
LABEL_293:
              *v78 = turn;
              CPP_add_alien_at_pos(
//                (unsigned int *)0x7E8,
//                a2,
                i,
                11,
                *((u16 *)v78 + 2),
                *((u16 *)v78 + 3),
                *((u16 *)v78 + 4),
                v87);
            }
LABEL_294:
            CPP_check_alien_to_players(/*(unsigned int *)a1, a2,*/ i, (int)v78);
          }
          else
          {
            CPP_insert_effect(v83, 1023 - v46, 42);
            *((u8 *)v78 + 16) = 0;
          }
          break;
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
          *((u16 *)v78 + 3) -= ( *((char *)v78 + 27)  SHL6) - (vy[i]  SHL8); //shift fix
          if ( *((u16 *)v78 + 3) && *((u16 *)v78 + 3) <= 0xF000u )
            ++*((u8 *)v78 + 16);
          else
            *((u8 *)v78 + 16) = 0;
          break;
        case 0x28:
        case 0x2E:
          *((u8 *)v78 + 16) = 0;
          break;
        case 0x31:
          v50 = ((int)*((u16 *)v78 + 2) >> 8) + 8 - LOBYTE(scrollpos[i]) % 8;
          v97 = (((int)LOBYTE(scrollpos[i]) >> 3) + 32 - ((v50 - (__CFSHL__(v50 >> 31, 3) + 8 * (v50 >> 31))) >> 3))
              % 32;
          v51 = ((int)*((u16 *)v78 + 3) >> 8) + 8 - HIBYTE(scrollpos[i]) % 8;
//          a1 = 1024;
          if ( lastscroll[i] == 1 )
            v52 = (((v51 - (__CFSHL__(v51 >> 31, 3) + 8 * (v51 >> 31))) >> 3) - 4 + (u16)level_line[i]
                                                                                  + 994)
                % 1024;
          else
            v52 = (((v51 - (__CFSHL__(v51 >> 31, 3) + 8 * (v51 >> 31))) >> 3)
                 - 4
                 + (u16)level_line[i]
                 + 1027)
                % 1024;
          *((u16 *)v78 + 2) += -256 * vx[i];
          *((u16 *)v78 + 3) += vy[i]  SHL8; //shift fix
          *((u16 *)v78 + 5) += 36;
          *((u16 *)v78 + 6) += 36;
          if ( *((u16 *)v78 + 3) >= 0x800u && *((u16 *)v78 + 3) <= 0xF000u )
          {
LABEL_301:
            CPP_check_alien_to_players(/*(unsigned int *)0x400, a2,*/ i, (int)v78);
          }
          else
          {
            CPP_insert_effect(v97, 1023 - v52, 43);
            *((u8 *)v78 + 16) = 0;
          }
          break;
        default:
          break;
      }
      v78 = (UA<i32>*)((char *)v78 + 30);
    }
  }
  return result;
}

char CPP_add_alien_at_pos(u8 a3, char a4, i16 a5, i16 a6, i16 a7, u16 a8) //FINAL
{
  int v8; // eax
//  i64 v10; // [esp-1Ch] [ebp-24h]
  u8 i; // [esp+4h] [ebp-4h]

  for ( i = 60 * a3; byte_235148[30 * i] && i < 60 * (a3 + 1); ++i )
    ;
  v8 = 60 * (a3 + 1);
  if ( i < v8 )
  {
    LOBYTE(v8) = a4;
    if ( a4 == 11 )
    {
//      HIDWORD(v10) = 9;
//      LODWORD(v10) = a3;

//    MY_PlaySample(a1, a2, v10, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
      MY_PlaySample(/*a1, a2, v10,*/ a3, 9, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

      word_23513C[15 * i] = a5;
      word_23513E[15 * i] = a6;
      word_235140[15 * i] = a7;
      byte_235150[30 * i] = 8;
      byte_235152[30 * i] = costable[(a8 + 1518) % 2024] >> 13;
      byte_235153[30 * i] = sintable[(a8 + 1518) % 2024] >> 13;
      word_235142[15 * i] = a8;
      *(UA<i32> *)((char *)aliens + 30 * i) = 40;
      word_235144[15 * i] = 0;
      byte_235148[30 * i] = 11;
      LOBYTE(v8) = 30 * i;
      word_235146[15 * i] = 1;
    }
  }
  return v8;
}


int CPP_do_ships(void)
{
  i16 v2; // ax
  i16 v3; // ax
  int result; // eax
  i16 v5; // ax
  i64 v6; // [esp-2h] [ebp-8h]

  CPP_do_players_ships( /*(int)a1, a2*/ );

  if ( !level_start )
  {
    CPP_do_aliens(/*(int)a1, a2*/);

    CPP_do_bullets(/*a1, a2*/);
  }

  if ( (u8)no_players <= 1u )
  {
    CPP_enter_ships(0);
    v5 = CPP_enter_ships(0);
    result = CPP_quick_sort_ships(0, v5);
  }
  else
  {
    v2 = CPP_enter_ships(0);
    WORD2(v6) = v2 + 1;
    CPP_quick_sort_ships(0, v2);
    v3 = CPP_enter_ships(1u);
    LODWORD(v6) = (i16)(WORD2(v6) + v3);
    result = CPP_quick_sort_ships(*(UA<i32> *)((char *)&v6 + 2) >> 16, WORD2(v6) + v3);
  }

  return result;
}

int CPP_quick_sort_ships(int a1, i16 a2) //FINAL
{
  int result; // eax
  int v3; // [esp+0h] [ebp-44h]
  int v4; // [esp+14h] [ebp-30h]
  int v5; // [esp+28h] [ebp-1Ch]
  u16 v6; // [esp+3Ch] [ebp-8h]
  i16 i; // [esp+40h] [ebp-4h]

  result = a1;
  if ( (i16)a1 < a2 )
  {
    v5 = draw_items[(u16)a1];
    draw_items[(u16)a1] = draw_items[(u16)(((i16)a1 + a2) / 2)];
    draw_items[(u16)(((i16)a1 + a2) / 2)] = v5;
    v6 = a1;
    for ( i = a1 + 1; i <= a2; ++i )
    {
    //if ( *(UA<u16> *)(draw_items[i] + 6) > *(UA<u16> *)(draw_items[(i16)a1] + 6) ) //это бредовое условие вылетает в сегфолт
      if(*(UA<u16> *)&draw_items[i+6]>*(UA<u16> *)&draw_items[(i16)a1+6]) //fix
      {
        v4 = draw_items[++v6];
        draw_items[v6] = draw_items[(u16)i];
        draw_items[(u16)i] = v4;
      }
    }
    v3 = draw_items[(u16)a1];
    draw_items[(u16)a1] = draw_items[v6];
    draw_items[v6] = v3;
    CPP_quick_sort_ships((i16)a1, v6 - 1);
    result = CPP_quick_sort_ships((i16)(v6 + 1), a2);
  }
  return result;
}

int CPP_enter_ships(u8 a1) //FINAL
{
  int *v1; // edx
  int **v2; // edx
  int *v4; // [esp+0h] [ebp-14h]
  char *v5; // [esp+4h] [ebp-10h]
  int *v6; // [esp+4h] [ebp-10h]
  u16 i; // [esp+8h] [ebp-Ch]
  u16 j; // [esp+8h] [ebp-Ch]
  int v9; // [esp+10h] [ebp-4h]

  v4 = &draw_items[96 * a1];
  v9 = 0;
  v5 = (char *) bullets + 1020 * a1;
  for ( i = 0; i < 0x22u; ++i )
  {
    if ( v5[16] )
    {
      v1 = v4++;
      *v1 = (int)v5;
      ++v9;
    }
    v5 += 30;
  }
  v6 = &aliens[450 * a1];
  for ( j = 0; j < 0x3Cu; ++j )
  {
    if ( *((u8 *)v6 + 16) )
    {
      ++v9;
      v2 = (int **)v4++;
      *v2 = v6;
    }
    v6 = (int *)((char *)v6 + 30);
  }
  *v4 = (int) players + 30 * a1;
  v4[1] = 0;
  return v9;
}

char CPP_change_hit_block(u8 a1, u16 a2, u16 a3) //FINAL
{
  int v3; // edx
  u16 v5; // [esp+4h] [ebp-Ch]
  u16 v6; // [esp+8h] [ebp-8h]
  char v7; // [esp+Ch] [ebp-4h]

  v6 = *(UA<u16> *)(level + 2 * (32 * a3 + a2));
  v5 = 0;
  v7 = 0;

  while ( hit_blocks[v5] >= 0 && !v7 )
  {
    if ( *(UA<i32> *)((char *) byte_21FDDA + 2 * v5) >> 16 == v6 )
    {
      v6 = word_21FDDE[v5];
      v7 = 1;
    }
    v5 += 2;
  }

  *(UA<u16> *)(2 * (32 * a3 + a2) + level) = v6;

  if ( lastscroll[a1] == 1 )
    v3 = (a1 << 16)
       + (((((int)HIBYTE(scrollpos[a1]) >> 3) + (a3 + (u16)level_line[a1]) % 1024) % 32) << 11);
  else
    v3 = (a1 << 16)
       + (((((int)HIBYTE(scrollpos[a1]) >> 3) + 32 - ((2048 - (u16)level_line[a1] - a3) % 1024 - 1)) % 32) << 11);

  return CPP_draw_block(8 * a2 + v3, v6);
}

char CPP_draw_block(int a1, u16 a2) //FINAL
{
  int v2; // eax
  u32 *v4; // [esp+0h] [ebp-8h]
  u8 i; // [esp+4h] [ebp-4h]

  if ( a2 >= 0x800u )
    a2 = 0;

  v2 = a2 << 6;
  v4 = (u32 *)(v2 + block_data);

  for ( i = 0; i < 8u; ++i )
  {
    *(UA<u32> *)(tube_graphics + a1) = *v4;
    *(UA<u32> *)(tube_graphics + a1 + 4) = v4[1];
    LOBYTE(v2) = i;
    a1 += 256;
    v4 += 2;
  }
  return v2;
}

char CPP_check_bullets_to_aliens(int a2) //FINAL
{
  unsigned int *v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // edx
//  i64 v7; // [esp-1Ch] [ebp-90h]
//  i64 v8; // [esp-1Ch] [ebp-90h]
//  i64 v9; // [esp-1Ch] [ebp-90h]
  u8 v10; // [esp+2Ch] [ebp-48h]
  int v11; // [esp+30h] [ebp-44h]
  int *v12; // [esp+34h] [ebp-40h]
  unsigned int v13; // [esp+38h] [ebp-3Ch]
  u16 v14; // [esp+3Ch] [ebp-38h]
  u16 v15; // [esp+40h] [ebp-34h]
  u16 v16; // [esp+48h] [ebp-2Ch]
  u16 v17; // [esp+4Ch] [ebp-28h]
  u16 v18; // [esp+50h] [ebp-24h]
  u8 v19; // [esp+54h] [ebp-20h]
  u8 v20; // [esp+5Ch] [ebp-18h]
  u8 v21; // [esp+60h] [ebp-14h]
  u8 v22; // [esp+64h] [ebp-10h]
  char i; // [esp+68h] [ebp-Ch]
  u8 v24; // [esp+6Ch] [ebp-8h]
  char v25; // [esp+70h] [ebp-4h]

  v25 = 0;
  v10 = *(u8 *)(a2 + 16);
  if ( v10 < 9u )
  {
    if ( v10 < 3u )
    {
      if ( v10 == 2 )
      {
        v24 = 0;
        v20 = 1;
        v17 = 512;
      }
    }
    else if ( v10 <= 3u )
    {
      v24 = 1;
      v20 = 1;
      v17 = 512;
    }
    else if ( v10 <= 4u )
    {
      v24 = 0;
      v20 = 3;
      v17 = 768;
    }
    else if ( v10 == 5 )
    {
      v24 = 1;
      v20 = 3;
      v17 = 768;
    }
  }
  else if ( v10 <= 9u )
  {
    v24 = 0;
    v20 = 10;
    v17 = 768;
  }
  else if ( v10 < 0xEu )
  {
    if ( v10 <= 0xAu )
    {
      v24 = 1;
      v20 = 10;
      v17 = 768;
    }
    else if ( v10 == 13 )
    {
      v24 = 0;
      v20 = *(u8 *)(a2 + 14);
      v17 = 512;
    }
  }
  else if ( v10 <= 0xEu )
  {
    v24 = 1;
    v20 = *(u8 *)(a2 + 14);
    v17 = 512;
  }
  else if ( v10 >= 0x2Fu )
  {
    if ( v10 <= 0x2Fu )
    {
      v24 = 0;
      v20 = 2;
      v17 = 1024;
    }
    else if ( v10 == 48 )
    {
      v24 = 1;
      v20 = 2;
      v17 = 1024;
    }
  }
  v12 = &aliens[450 * v24];
  for ( i = 0; (u8)i < 0x3Cu; ++i )
  {
    if ( *((u8 *)v12 + 16)
      && *((u8 *)v12 + 16) != 21
      && *((u8 *)v12 + 16) != 49
      && (*((u8 *)v12 + 16) < 0x19u || *((u8 *)v12 + 16) > 0x2Eu) )
    {
      switch ( *((u8 *)v12 + 16) )
      {
        case 6:
          v16 = 3072;
          v14 = 1280;
          v18 = 1280;
          v22 = 10;
          v21 = 100;
          v19 = 36;
          break;
        case 7:
          v16 = 2048;
          v14 = 1792;
          v18 = 1792;
          v22 = 1;
          v21 = 5;
          v19 = 34;
          break;
        case 8:
          v16 = 2048;
          v14 = 2048;
          v18 = 2560;
          v22 = 6;
          v21 = 15;
          v19 = 39;
          break;
        case 0xB:
          v16 = 512;
          v14 = 1024;
          v18 = 1024;
          v22 = 1;
          v21 = 2;
          v19 = -1;
          break;
        case 0xC:
          v16 = 1536;
          v14 = 768;
          v18 = 768;
          v22 = 5;
          v21 = 50;
          v19 = 38;
          break;
        case 0xF:
          v16 = 2048;
          v14 = 2048;
          v18 = 2560;
          v22 = 6;
          v21 = 15;
          v19 = 41;
          break;
        case 0x10:
          v16 = 2048;
          v14 = 2048;
          v18 = 2560;
          v22 = 6;
          v21 = 15;
          v19 = 40;
          break;
        case 0x11:
          v16 = 2048;
          v14 = 1792;
          v18 = 2048;
          v22 = 4;
          v21 = 10;
          v19 = 35;
          break;
        case 0x17:
          v16 = 2048;
          v14 = 2048;
          v18 = 2560;
          v22 = 6;
          v21 = 15;
          v19 = 42;
          break;
        default:
          break;
      }
      if ( *(u16 *)(a2 + 8) <= v17 + v16 + *((u16 *)v12 + 4)
        && *(u16 *)(a2 + 8) >= *((u16 *)v12 + 4) - v17
        && *(u16 *)(a2 + 6) <= v17 + v18 + *((u16 *)v12 + 3)
        && *(u16 *)(a2 + 6) >= *((u16 *)v12 + 3) - v18 - v17 )
      {
        v13 = *(u16 *)(a2 + 4);
        v11 = *((u16 *)v12 + 2);
        v2 = (unsigned int *)(v14 + v11 + v17);
        if ( (unsigned int)v2 < v11 - v14 - (unsigned int)v17 )
        {
          v11 += 0x2000;
          v13 += 0x2000;
        }
        if ( v14 + v11 + (unsigned int)v17 > v13 && v11 - v14 - (unsigned int)v17 < v13 )
        {
          i = 60;
          if ( *(UA<u16> *)(a2 + 14) > *((u16 *)v12 + 7)
            && (*(u8 *)(a2 + 16) == 9
             || *(u8 *)(a2 + 16) == 10
             || *(u8 *)(a2 + 16) == 13
             || *(u8 *)(a2 + 16) == 14) )
          {
            *(UA<u16> *)(a2 + 14) -= *((u16 *)v12 + 7);
            v25 = 0;
          }
          else
          {
            v25 = 1;
          }
          *((u16 *)v12 + 7) -= v20;
          if ( *((i16 *)v12 + 7) >= 0 )
          {
            the_score[v24] += v22;
          }
          else
          {
            the_score[v24] += v21;
            if ( *((u8 *)v12 + 16) == 6 )
            {
//              HIDWORD(v7) = 15;
//              LODWORD(v7) = v24;

//            MY_PlaySample(v2, a1, v7, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
              MY_PlaySample(/*v2, a1, v7,*/ v24 ,15, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

              *((u16 *)v12 + 6) = 0;
              *((u8 *)v12 + 16) = 21;
              *((u8 *)v12 + 24) = 0;
              *((u16 *)v12 + 7) = 127;
            }
            else if ( *((u8 *)v12 + 16) == 11 )
            {
//              HIDWORD(v8) = 7;
//              LODWORD(v8) = v24;

//            MY_PlaySample(v2, a1, v8, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
              MY_PlaySample(/*v2, a1, v8,*/ v24, 7 ,0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

              *((u8 *)v12 + 16) = 41;
              *((u16 *)v12 + 5) = 0;
              *((u16 *)v12 + 6) = 0;
            }
            else
            {
//              HIDWORD(v9) = 6;
//              LODWORD(v9) = v24;

//            MY_PlaySample(v2, a1, v9, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
              MY_PlaySample(/*v2, a1, v9,*/ v24, 6 ,0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

              *((u8 *)v12 + 16) = 25;
              v3 = ((int)*((u16 *)v12 + 2) >> 8) + 8 - LOBYTE(scrollpos[v24]) % 8;
              v15 = (((int)LOBYTE(scrollpos[v24]) >> 3) + 32 - ((v3 - (__CFSHL__(v3 >> 31, 3) + 8 * (v3 >> 31))) >> 3))
                  % 32;
              v4 = ((int)*((u16 *)v12 + 3) >> 8) + 8 - HIBYTE(scrollpos[v24]) % 8;
              if ( lastscroll[v24] == 1 )
                v5 = (((v4 - (__CFSHL__(v4 >> 31, 3) + 8 * (v4 >> 31))) >> 3)
                    - 4
                    + (u16)level_line[v24]
                    + 994)
                   % 1024;
              else
                v5 = (((v4 - (__CFSHL__(v4 >> 31, 3) + 8 * (v4 >> 31))) >> 3)
                    - 4
                    + (u16)level_line[v24]
                    + 1027)
                   % 1024;
              if ( v19 != 0xFF )
                CPP_insert_effect(v15, 1023 - v5, v19);
              *((u16 *)v12 + 5) = 0;
              *((u16 *)v12 + 6) = 0;
            }
          }
        }
      }
    }
    v12 = (int *)((char *)v12 + 30);
  }
  return v25;
}

u16 *CPP_organise_block(u8 a1, u16 *a2, u16 *a3) //FINAL
{
  int v3; // eax
  int v4; // eax
  int v5; // edx
  u16 *result; // eax

  v3 = ((int)(u16)*a2 >> 8) + 8 - LOBYTE(scrollpos[a1]) % 8;
  *a2 = (((int)LOBYTE(scrollpos[a1]) >> 3) + 32 - ((v3 - (__CFSHL__(v3 >> 31, 3) + 8 * (v3 >> 31))) >> 3)) % 32;
  v4 = ((int)(u16)*a3 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
  if ( lastscroll[a1] == 1 )
    v5 = (((v4 - (__CFSHL__(v4 >> 31, 3) + 8 * (v4 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 994) % 1024;
  else
    v5 = (((v4 - (__CFSHL__(v4 >> 31, 3) + 8 * (v4 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 1027) % 1024;
  result = a3;
  *a3 = 1023 - v5;
  return result;
}

int CPP_nearest_alien(u8 a1, u16 a2, u16 a3, u16 a4, u16 *a5, u16 *a6, u16 *a7) //FINAL
{
  int result; // eax
  char *v9; // [esp+4h] [ebp-1Ch]
  int v10; // [esp+8h] [ebp-18h]
  u16 v11; // [esp+Ch] [ebp-14h]
  u16 v12; // [esp+10h] [ebp-10h]
  u16 v13; // [esp+14h] [ebp-Ch]
  u16 v14; // [esp+18h] [ebp-8h]
  u8 i; // [esp+1Ch] [ebp-4h]

  v11 = -1;
  result = 1800 * a1;
  v9 = (char *) aliens + result; //& fix
  for ( i = 0; i < 0x3Cu; ++i )
  {
    if ( v9[16] && v9[16] != 21 && v9[16] != 49 && ((u8)v9[16] < 0x19u || (u8)v9[16] > 0x2Eu) )
    {
      v10 = *((u16 *)v9 + 2);
      if ( a2 >= 0x7800u )
      {
        if ( a2 - 0x8000 > v10 )
          v10 += 0x10000;
      }
      else if ( a2 + 0x8000 < v10 )
      {
        v10 -= 0x10000;
      }
      v14 = abs(a2 - v10);
      v13 = abs(a3 - *((u16 *)v9 + 3));
      v12 = abs(a4 - *((u16 *)v9 + 4));
      if ( v13 < v11 && v14 < v11 && v12 < v11 )
      {
        if ( v14 <= v13 )
        {
          if ( v13 <= v12 )
            v11 = v12;
          else
            v11 = v13;
        }
        else if ( v14 <= v12 )
        {
          v11 = v12;
        }
        else
        {
          v11 = v14;
        }
        *a5 = *((u16 *)v9 + 2);
        *a6 = *((u16 *)v9 + 3);
        *a7 = *((u16 *)v9 + 4);
      }
    }
    result = (int)v9;
    v9 += 30;
  }
  return result;
}

i16 CPP_move_in_line(int a1, int a2, u16 a3, u16 a4) //FINAL
{
  i16 result; // ax
  int v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+0h] [ebp-30h]
  int v7; // [esp+4h] [ebp-2Ch]
  int v8; // [esp+4h] [ebp-2Ch]
  i16 v9; // [esp+8h] [ebp-28h]
  i16 v10; // [esp+8h] [ebp-28h]
  i16 v11; // [esp+8h] [ebp-28h]
  int v12; // [esp+Ch] [ebp-24h]
  int v13; // [esp+10h] [ebp-20h]
  int v14; // [esp+14h] [ebp-1Ch]
  int v15; // [esp+18h] [ebp-18h]
  int v16; // [esp+18h] [ebp-18h]
  int v17; // [esp+18h] [ebp-18h]
  int v18; // [esp+1Ch] [ebp-14h]
  int v19; // [esp+1Ch] [ebp-14h]
  int v20; // [esp+1Ch] [ebp-14h]
  int v21; // [esp+20h] [ebp-10h]
  int v22; // [esp+20h] [ebp-10h]
  char v23; // [esp+24h] [ebp-Ch]
  char v24; // [esp+28h] [ebp-8h]
  char v25; // [esp+2Ch] [ebp-4h]
  int v26; // [esp+4Ch] [ebp+1Ch]
  int v27; // [esp+50h] [ebp+20h]

  LOWORD(a2) = BYTE1(a2);
  v14 = (int)*(u16 *)(a1 + 4) >> 8;
  if ( (i16)v14 >= 128 )
  {
    if ( (u16)a2 < (i16)v14 - 128 )
      a2 += 256;
  }
  else if ( (u16)a2 > (i16)v14 + 128 )
  {
    a2 -= 256;
  }
  v21 = a2 - v14;
  v13 = (int)*(u16 *)(a1 + 6) >> 8;
  v26 = (int)a3 >> 8;
  v5 = (u16)v26 - (i16)v13;
  v12 = (int)*(u16 *)(a1 + 8) >> 8;
  v27 = (int)a4 >> 8;
  v7 = (u16)v27 - (i16)v12;
  if ( (i16)(a2 - v14) < 0 )
  {
    v23 = -1;
    v21 = v14 - a2;
  }
  else
  {
    v23 = 1;
  }
  if ( (v5 & 0x8000u) != 0 )
  {
    v5 = (i16)v13 - (u16)v26;
    v25 = -1;
  }
  else
  {
    v25 = 1;
  }
  if ( (v7 & 0x8000u) != 0 )
  {
    v7 = (i16)v12 - (u16)v27;
    v24 = -1;
  }
  else
  {
    v24 = 1;
  }
  v22 = v21 + 1;
  v6 = v5 + 1;
  v8 = v7 + 1;
  if ( (i16)v22 >= (i16)v6 && (i16)v22 >= (i16)v8 )
  {
    v9 = *(char *)(a1 + 24);
    if ( v9 > (i16)v22 )
      v9 = v22;
    v18 = v22;
    v15 = v22;
    while ( v9 > 0 )
    {
      if ( (i16)v14 != (u16)a2 )
      {
        LOWORD(v14) = v23 + (u16)v14;
        v18 -= v6;
        v15 -= v8;
      }
      if ( (v18 & 0x8000u) != 0 && (i16)v13 != (u16)v26 )
      {
        LOWORD(v13) = v25 + (u16)v13;
        v18 += v22;
      }
      if ( (v15 & 0x8000u) != 0 && (i16)v12 != (u16)v27 )
      {
        LOWORD(v12) = v24 + (u16)v12;
        v15 += v22;
      }
      --v9;
    }
  }
  else if ( (i16)v6 < (i16)v8 )
  {
    v11 = *(char *)(a1 + 24);
    if ( v11 > (i16)v8 )
      v11 = v8;
    v20 = v8;
    v17 = v8;
    while ( v11 > 0 )
    {
      if ( (i16)v12 != (u16)v27 )
      {
        LOWORD(v12) = v24 + (u16)v12;
        v20 -= v6;
        v17 -= v22;
      }
      if ( (v20 & 0x8000u) != 0 && (i16)v13 != (u16)v26 )
      {
        LOWORD(v13) = v25 + (u16)v13;
        v20 += v8;
      }
      if ( (v17 & 0x8000u) != 0 && (i16)v14 != (u16)a2 )
      {
        LOWORD(v14) = v23 + (u16)v14;
        v17 += v8;
      }
      --v11;
    }
  }
  else
  {
    v10 = *(char *)(a1 + 24);
    if ( v10 > (i16)v6 )
      v10 = v6;
    v19 = v6;
    v16 = v6;
    while ( v10 > 0 )
    {
      if ( (i16)v13 != (u16)v26 )
      {
        LOWORD(v13) = v25 + (u16)v13;
        v19 -= v22;
        v16 -= v8;
      }
      if ( (v19 & 0x8000u) != 0 && (i16)v14 != (u16)a2 )
      {
        LOWORD(v14) = v23 + (u16)v14;
        v19 += v6;
      }
      if ( (v16 & 0x8000u) != 0 && (i16)v12 != (u16)v27 )
      {
        LOWORD(v12) = v24 + (u16)v12;
        v16 += v6;
      }
      --v10;
    }
  }
  *(UA<u16> *)(a1 + 4) = (u16)v14 << 8;
  *(UA<u16> *)(a1 + 6) = (u16)v13 << 8;
  result = (u16)v12 << 8;
  *(UA<u16> *)(a1 + 8) = (u16)v12 << 8;
  return result;
}

u8 CPP_do_bullets(void) //FINAL
{
  u8 result; // al
  int v3; // edx
  int v4; // eax
  int v5; // eax
  i16 v6; // ax
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  i16 v11; // ax
  int v12; // eax
  int v13; // eax
  i16 v14; // ax
  int v15; // eax
  int v16; // eax
  i16 v17; // ax
  int v18; // eax
  i16 v19; // ax
  int v20; // eax
  i16 v21; // ax
  int v22; // eax
  int v23; // eax
  i16 v24; // ax
  int v25; // eax
  int v26; // eax
  int v27; // edx
  i16 v28; // ax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  i16 v33; // ax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  i16 v37; // ax
  int v38; // eax
  int v39; // eax
  int v40; // edx
//  i64 v41; // [esp-1Ch] [ebp-240h]
//  i64 v42; // [esp-1Ch] [ebp-240h]
  int v43; // [esp+0h] [ebp-224h] BYREF
  int v44[5]; // [esp+4h] [ebp-220h] BYREF
  int v45; // [esp+18h] [ebp-20Ch]
  int v46; // [esp+1Ch] [ebp-208h]
  char v47; // [esp+20h] [ebp-204h]
  u8 v48; // [esp+24h] [ebp-200h]
  int v49; // [esp+28h] [ebp-1FCh]
  int v50; // [esp+2Ch] [ebp-1F8h]
  _BOOL1 v51; // [esp+30h] [ebp-1F4h]
  int v52; // [esp+34h] [ebp-1F0h] BYREF
  int v53[5]; // [esp+38h] [ebp-1ECh] BYREF
  int v54; // [esp+4Ch] [ebp-1D8h]
  int v55; // [esp+50h] [ebp-1D4h]
  u8 v56; // [esp+54h] [ebp-1D0h]
  u8 v57; // [esp+58h] [ebp-1CCh]
  int v58; // [esp+5Ch] [ebp-1C8h]
  int v59; // [esp+60h] [ebp-1C4h]
  _BOOL1 v60; // [esp+64h] [ebp-1C0h]
  int v61; // [esp+68h] [ebp-1BCh] BYREF
  int v62[5]; // [esp+6Ch] [ebp-1B8h] BYREF
  int v63; // [esp+80h] [ebp-1A4h]
  int v64; // [esp+84h] [ebp-1A0h]
  u8 v65; // [esp+88h] [ebp-19Ch]
  char v66; // [esp+8Ch] [ebp-198h]
  int v67; // [esp+90h] [ebp-194h]
  int v68; // [esp+94h] [ebp-190h]
  _BOOL1 v69; // [esp+98h] [ebp-18Ch]
  int v70; // [esp+9Ch] [ebp-188h] BYREF
  int v71[5]; // [esp+A0h] [ebp-184h] BYREF
  int v72; // [esp+B4h] [ebp-170h]
  int v73; // [esp+B8h] [ebp-16Ch]
  u8 v74; // [esp+BCh] [ebp-168h]
  u8 v75; // [esp+C0h] [ebp-164h]
  int v76; // [esp+C4h] [ebp-160h]
  int v77; // [esp+C8h] [ebp-15Ch]
  _BOOL1 v78; // [esp+CCh] [ebp-158h]
  int v79; // [esp+D0h] [ebp-154h] BYREF
  int v80[5]; // [esp+D4h] [ebp-150h] BYREF
  int v81; // [esp+E8h] [ebp-13Ch]
  int v82; // [esp+ECh] [ebp-138h]
  char v83; // [esp+F0h] [ebp-134h]
  u8 v84; // [esp+F4h] [ebp-130h]
  int v85; // [esp+F8h] [ebp-12Ch]
  int v86; // [esp+FCh] [ebp-128h]
  _BOOL1 v87; // [esp+100h] [ebp-124h]
  int v88; // [esp+104h] [ebp-120h] BYREF
  int v89[5]; // [esp+108h] [ebp-11Ch] BYREF
  int v90; // [esp+11Ch] [ebp-108h]
  int v91; // [esp+120h] [ebp-104h]
  u8 v92; // [esp+124h] [ebp-100h]
  u8 v93; // [esp+128h] [ebp-FCh]
  int v94; // [esp+12Ch] [ebp-F8h]
  int v95; // [esp+130h] [ebp-F4h]
  _BOOL1 v96; // [esp+134h] [ebp-F0h]
  int v97; // [esp+138h] [ebp-ECh] BYREF
  int v98[5]; // [esp+13Ch] [ebp-E8h] BYREF
  int v99; // [esp+150h] [ebp-D4h]
  int v100; // [esp+154h] [ebp-D0h]
  char v101; // [esp+158h] [ebp-CCh]
  u8 v102; // [esp+15Ch] [ebp-C8h]
  int v103; // [esp+160h] [ebp-C4h]
  int v104; // [esp+164h] [ebp-C0h]
  _BOOL1 v105; // [esp+168h] [ebp-BCh]
  int v106; // [esp+16Ch] [ebp-B8h] BYREF
  int v107[5]; // [esp+170h] [ebp-B4h] BYREF
  int v108; // [esp+184h] [ebp-A0h]
  int v109; // [esp+188h] [ebp-9Ch]
  u8 v110; // [esp+18Ch] [ebp-98h]
  u8 v111; // [esp+190h] [ebp-94h]
  int v112; // [esp+194h] [ebp-90h]
  int v113; // [esp+198h] [ebp-8Ch]
  _BOOL1 v114; // [esp+19Ch] [ebp-88h]
  int v115; // [esp+1A0h] [ebp-84h] BYREF
  int v116[5]; // [esp+1A4h] [ebp-80h] BYREF
  int v117; // [esp+1B8h] [ebp-6Ch]
  int v118; // [esp+1BCh] [ebp-68h]
  char v119; // [esp+1C0h] [ebp-64h]
  u8 v120; // [esp+1C4h] [ebp-60h]
  int v121; // [esp+1C8h] [ebp-5Ch]
  int v122; // [esp+1CCh] [ebp-58h]
  _BOOL1 v123; // [esp+1D0h] [ebp-54h]
  int v124; // [esp+1D4h] [ebp-50h] BYREF
  int v125[5]; // [esp+1D8h] [ebp-4Ch] BYREF
  int v126; // [esp+1ECh] [ebp-38h]
  int v127; // [esp+1F0h] [ebp-34h]
  u8 v128; // [esp+1F4h] [ebp-30h]
  u8 v129; // [esp+1F8h] [ebp-2Ch]
  int v130; // [esp+1FCh] [ebp-28h]
  int v131; // [esp+200h] [ebp-24h]
  _BOOL1 v132; // [esp+204h] [ebp-20h]
  u8 v133; // [esp+208h] [ebp-1Ch]
  int v134; // [esp+20Ch] [ebp-18h]
  int v135; // [esp+210h] [ebp-14h] BYREF
  int v136; // [esp+214h] [ebp-10h] BYREF
  int v137; // [esp+218h] [ebp-Ch] BYREF
  u8 v138; // [esp+21Ch] [ebp-8h]
  u8 v139; // [esp+220h] [ebp-4h]

  v139 = 0;
LABEL_2:
  result = v139;
  if ( v139 < (u8)no_players )
  {
    v3 = (int) bullets + 1020 * v139;
    v134 = v3;
    v138 = 0;
    while ( 1 )
    {
      if ( v138 >= 0x22u )
      {
        ++v139;
        goto LABEL_2;
      }
      v133 = *(u8 *)(v134 + 16);
      if ( v133 < 0xAu )
      {
        if ( v133 < 4u )
        {
          if ( v133 >= 2u )
          {
            if ( v133 <= 2u )
            {
              LOWORD(v3) = vy[v139];
              HIWORD(v4) = HIWORD(v134);
              LOWORD(v4) = *(char *)(v134 + 24);
              v3 = (v4 SHL8) + (v3 SHL8);
              *(UA<u16> *)(v134 + 6) += v3;
              if ( *(UA<u16> *)(v134 + 6) > 0xE000u )
              {
                *(u8 *)(v134 + 16) = 0;
                goto LABEL_6;
              }
              LOWORD(v3) = vx[v139];
              HIWORD(v5) = HIWORD(v134);
              LOWORD(v5) = *(char *)(v134 + 26);
              v3 = (v5 SHL8) - (v3 SHL8);
              *(UA<u16> *)(v134 + 4) += v3;
              *(UA<u16> *)(v134 + 10) += 36;
              *(UA<u16> *)(v134 + 12) += 48;
              v131 = v134;
              v130 = v134;
              v132 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
              if ( v132 || (v6 = CPP_what_block(v139, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v6)) )
              {
                v128 = v139;
                HIWORD(v7) = HIWORD(v134);
                LOWORD(v7) = *(UA<u16> *)(v134 + 4);
                v127 = v7;
                HIWORD(v7) = HIWORD(v134);
                LOWORD(v7) = *(UA<u16> *)(v134 + 6);
                v126 = v7;
                HIWORD(v7) = HIWORD(v134);
                LOWORD(v7) = *(UA<u16> *)(v134 + 8);
                v125[4] = v7;
                v129 = v139;
                v125[3] = v127;
                v125[2] = v126;
                v125[1] = v7;
                v125[0] = v127;
                v124 = v126;
                if ( !(u16)v7 )
                {
                  CPP_organise_block(v129, (u16*)v125, (u16*)&v124);
                  CPP_change_hit_block(v129, v125[0], v124);
                }
                goto LABEL_106;
              }
              if ( --*(UA<u32> *)v134 == (unsigned)-1 ) //unsigned fix
                goto LABEL_106;
            }
            else
            {
              HIWORD(v8) = HIWORD(v134);
              LOWORD(v8) = *(char *)(v134 + 24);
              v8 OSHL8;
              v9 = v8;
              LOWORD(v8) = word_21F94A;
              v3 = (v8 SHL8) + v9;
              *(UA<u16> *)(v134 + 6) += v3;
              if ( *(UA<u16> *)(v134 + 6) > 0xE000u )
              {
                *(u8 *)(v134 + 16) = 0;
                goto LABEL_6;
              }
              LOWORD(v3) = vx[v139];
              HIWORD(v10) = HIWORD(v134);
              LOWORD(v10) = *(char *)(v134 + 26);
              v3 = (v10 SHL8) - (v3 SHL8);
              *(UA<u16> *)(v134 + 4) += v3;
              *(UA<u16> *)(v134 + 10) += 36;
              *(UA<u16> *)(v134 + 12) += 48;
              v122 = v134;
              v121 = v134;
              v123 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
              if ( v123 || (v11 = CPP_what_block(1u, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v11)) )
              {
                v119 = 1;
                HIWORD(v12) = HIWORD(v134);
                LOWORD(v12) = *(UA<u16> *)(v134 + 4);
                v118 = v12;
                HIWORD(v12) = HIWORD(v134);
                LOWORD(v12) = *(UA<u16> *)(v134 + 6);
                v117 = v12;
                HIWORD(v12) = HIWORD(v134);
                LOWORD(v12) = *(UA<u16> *)(v134 + 8);
                v116[4] = v12;
                v120 = 1;
                v116[3] = v118;
                v116[2] = v117;
                v116[1] = v12;
                v116[0] = v118;
                v115 = v117;
                if ( !(u16)v12 )
                {
                  CPP_organise_block(v120, (u16*)v116, (u16*)&v115);
                  CPP_change_hit_block(v120, v116[0], v115);
                }
                goto LABEL_106;
              }
              if ( --*(UA<u32> *)v134 == (unsigned)-1 ) //unsigned fix
                goto LABEL_106;
            }
          }
        }
        else if ( v133 <= 4u )
        {
          HIWORD(v13) = HIWORD(v134);
          LOWORD(v13) = *(UA<u16> *)(v134 + 4);
          v137 = v13;
          v135 = 57344;
          HIWORD(v13) = HIWORD(v134);
          LOWORD(v13) = *(UA<u16> *)(v134 + 8);
          v136 = v13;
          CPP_nearest_alien(0, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6), *(UA<u16> *)(v134 + 8), (u16*)&v137, (u16*)&v135, (u16*)&v136);
          CPP_move_in_line(v134, (u16)v137, v135, v136);
          if ( *(u8 *)(v134 + 24) != 8 && (turn & 3) == 0 )
            ++*(u8 *)(v134 + 24);
          if ( *(UA<u16> *)(v134 + 6) >= 0xE000u )
          {
            *(u8 *)(v134 + 16) = 0;
            goto LABEL_6;
          }
          *(UA<u16> *)(v134 + 10) += 72;
          v113 = v134;
          v112 = v134;
          v114 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
          if ( v114 || (v14 = CPP_what_block(v139, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v14)) )
          {
            v110 = v139;
            HIWORD(v15) = HIWORD(v134);
            LOWORD(v15) = *(UA<u16> *)(v134 + 4);
            v109 = v15;
            HIWORD(v15) = HIWORD(v134);
            LOWORD(v15) = *(UA<u16> *)(v134 + 6);
            v108 = v15;
            HIWORD(v15) = HIWORD(v134);
            LOWORD(v15) = *(UA<u16> *)(v134 + 8);
            v107[4] = v15;
            v111 = v139;
            v107[3] = v109;
            v107[2] = v108;
            v107[1] = v15;
            v107[0] = v109;
            v106 = v108;
            if ( !(u16)v15 )
            {
              CPP_organise_block(v111, (u16*)v107, (u16*)&v106);
              CPP_change_hit_block(v111, v107[0], v106);
            }
            goto LABEL_136;
          }
        }
        else if ( v133 <= 5u )
        {
          HIWORD(v16) = HIWORD(v134);
          LOWORD(v16) = *(UA<u16> *)(v134 + 4);
          v137 = v16;
          v135 = 57344;
          HIWORD(v16) = HIWORD(v134);
          LOWORD(v16) = *(UA<u16> *)(v134 + 8);
          v136 = v16;
          CPP_nearest_alien(1u, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6), *(UA<u16> *)(v134 + 8), (u16*)&v137, (u16*)&v135, (u16*)&v136);
          CPP_move_in_line(v134, (u16)v137, v135, v136);
          if ( *(u8 *)(v134 + 24) != 8 && (turn & 3) == 0 )
            ++*(u8 *)(v134 + 24);
          if ( *(UA<u16> *)(v134 + 6) >= 0xE000u )
          {
            *(u8 *)(v134 + 16) = 0;
            goto LABEL_6;
          }
          *(UA<u16> *)(v134 + 10) += 72;
          v104 = v134;
          v103 = v134;
          v105 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
          if ( v105 || (v17 = CPP_what_block(1u, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v17)) )
          {
            v101 = 1;
            HIWORD(v18) = HIWORD(v134);
            LOWORD(v18) = *(UA<u16> *)(v134 + 4);
            v100 = v18;
            HIWORD(v18) = HIWORD(v134);
            LOWORD(v18) = *(UA<u16> *)(v134 + 6);
            v99 = v18;
            HIWORD(v18) = HIWORD(v134);
            LOWORD(v18) = *(UA<u16> *)(v134 + 8);
            v98[4] = v18;
            v102 = 1;
            v98[3] = v100;
            v98[2] = v99;
            v98[1] = v18;
            v98[0] = v100;
            v97 = v99;
            if ( !(u16)v18 )
            {
              CPP_organise_block(v102, (u16*)v98, (u16*)&v97);
              CPP_change_hit_block(v102, v98[0], v97);
            }
            goto LABEL_136;
          }
        }
        else if ( v133 == 9 )
        {
          LOWORD(v3) = vy[v139];
          HIWORD(v23) = HIWORD(v134);
          LOWORD(v23) = *(char *)(v134 + 24);
          v3 = (v23 SHL8) + (v3 SHL8);
          *(UA<u16> *)(v134 + 6) += v3;
          if ( *(UA<u16> *)(v134 + 6) > 0xE000u || *(UA<u16> *)(v134 + 8) > 0xE000u )
          {
            *(u8 *)(v134 + 16) = 0;
            goto LABEL_6;
          }
          v77 = v134;
          v76 = v134;
          v78 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
          if ( v78 || (v24 = CPP_what_block(v139, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v24)) )
          {
            *(UA<u16> *)(v134 + 4) -= vx[v139]  SHL8; //shift fix
            v75 = v139;
            HIWORD(v25) = HIWORD(v134);
            LOWORD(v25) = *(UA<u16> *)(v134 + 4);
            v73 = v25;
            HIWORD(v25) = HIWORD(v134);
            LOWORD(v25) = *(UA<u16> *)(v134 + 6);
            v72 = v25;
            HIWORD(v25) = HIWORD(v134);
            LOWORD(v25) = *(UA<u16> *)(v134 + 8);
            v71[4] = v25;
            v74 = v139;
            v71[3] = v73;
            v71[2] = v72;
            v71[1] = v25;
            v71[0] = v73;
            v70 = v72;
            if ( !(u16)v25 )
            {
              CPP_organise_block(v74, (u16*)v71, (u16*)&v70);
              CPP_change_hit_block(v74, v71[0], v70);
            }
            goto LABEL_136;
          }
          if ( --*(UA<u32> *)v134 == (unsigned)-1 ) //unsigned fix
            goto LABEL_106;
        }
      }
      else if ( v133 <= 0xAu )
      {
        HIWORD(v26) = HIWORD(v134);
        LOWORD(v26) = *(char *)(v134 + 24);
        v26 OSHL8;
        v27 = v26;
        LOWORD(v26) = word_21F94A;
        v3 = (v26 SHL8) + v27;
        *(UA<u16> *)(v134 + 6) += v3;
        if ( *(UA<u16> *)(v134 + 6) > 0xE000u || *(UA<u16> *)(v134 + 8) > 0xE000u )
        {
          *(u8 *)(v134 + 16) = 0;
          goto LABEL_6;
        }
        v68 = v134;
        v67 = v134;
        v69 = CPP_check_bullets_to_aliens(/*a2, */ v134) != 0;
        if ( v69 || (v28 = CPP_what_block(1u, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v28)) )
        {
          *(UA<u16> *)(v134 + 4) -= vx[v139]  SHL8; //shift fix
          v66 = 1;
          HIWORD(v29) = HIWORD(v134);
          LOWORD(v29) = *(UA<u16> *)(v134 + 4);
          v64 = v29;
          HIWORD(v29) = HIWORD(v134);
          LOWORD(v29) = *(UA<u16> *)(v134 + 6);
          v63 = v29;
          HIWORD(v29) = HIWORD(v134);
          LOWORD(v29) = *(UA<u16> *)(v134 + 8);
          v62[4] = v29;
          v65 = 1;
          v62[3] = v64;
          v62[2] = v63;
          v62[1] = v29;
          v62[0] = v64;
          v61 = v63;
          if ( !(u16)v29 )
          {
            CPP_organise_block(v65, (u16*)v62, (u16*)&v61);
            CPP_change_hit_block(v65, v62[0], v61);
          }
          goto LABEL_136;
        }
        if ( --*(UA<u32> *)v134 == (unsigned)-1 ) //unsigned fix
          goto LABEL_106;
      }
      else if ( v133 < 0x29u )
      {
        if ( v133 >= 0xDu )
        {
          if ( v133 <= 0xDu )
          {
            HIWORD(v31) = HIWORD(v134);
            if ( *(u8 *)(v134 + 29) )
            {
              LOWORD(v31) = word_25677C[0] + 1536;
            }
            else
            {
              LOWORD(v31) = word_25677C[0];
              v31 -= 1536;
            }
            v137 = v31;
            LOWORD(v31) = unk_25677E[0]; //space fix
            v32 = v31 + 1;
            v135 = v32;
            LOWORD(v32) = dword_256780[0]; //space fix
            v136 = v32;
            CPP_nearest_alien(0, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6), *(UA<u16> *)(v134 + 8), (u16*)&v137, (u16*)&v135, (u16*)&v136);
            CPP_move_in_line(v134, (u16)v137, v135, v136);
            if ( *(u8 *)(v134 + 24) != 12 && (turn & 3) == 0 )
              ++*(u8 *)(v134 + 24);
            if ( *(UA<u16> *)(v134 + 6) >= 0xE000u )
            {
              *(u8 *)(v134 + 16) = 0;
              goto LABEL_6;
            }
            *(UA<u16> *)(v134 + 12) += 48;
            *(UA<u16> *)(v134 + 10) += 36;
            v59 = v134;
            v58 = v134;
            v60 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
            if ( v60 || (v33 = CPP_what_block(v139, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v33)) )
            {
              v56 = v139;
              HIWORD(v34) = HIWORD(v134);
              LOWORD(v34) = *(UA<u16> *)(v134 + 4);
              v55 = v34;
              HIWORD(v34) = HIWORD(v134);
              LOWORD(v34) = *(UA<u16> *)(v134 + 6);
              v54 = v34;
              HIWORD(v34) = HIWORD(v134);
              LOWORD(v34) = *(UA<u16> *)(v134 + 8);
              v53[4] = v34;
              v57 = v139;
              v53[3] = v55;
              v53[2] = v54;
              v53[1] = v34;
              v53[0] = v55;
              v52 = v54;
              if ( !(u16)v34 )
              {
                CPP_organise_block(v57, (u16*)v53, (u16*)&v52);
                CPP_change_hit_block(v57, v53[0], v52);
              }
              goto LABEL_136;
            }
          }
          else if ( v133 == 14 )
          {
            HIWORD(v35) = HIWORD(v134);
            if ( *(u8 *)(v134 + 29) )
            {
              LOWORD(v35) = word_25679A + 1536;
            }
            else
            {
              LOWORD(v35) = word_25679A;
              v35 -= 1536;
            }
            v137 = v35;
            LOWORD(v35) = word_25679C;
            v36 = v35 + 1;
            v135 = v36;
            LOWORD(v36) = word_25679E;
            v136 = v36;
            CPP_nearest_alien(1u, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6), *(UA<u16> *)(v134 + 8), (u16*)&v137, (u16*)&v135, (u16*)&v136);
            CPP_move_in_line(v134, (u16)v137, v135, v136);
            if ( *(u8 *)(v134 + 24) != 12 && (turn & 3) == 0 )
              ++*(u8 *)(v134 + 24);
            if ( *(UA<u16> *)(v134 + 6) >= 0xE000u )
            {
              *(u8 *)(v134 + 16) = 0;
              goto LABEL_6;
            }
            *(UA<u16> *)(v134 + 12) += 48;
            *(UA<u16> *)(v134 + 10) += 36;
            v50 = v134;
            v49 = v134;
            v51 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
            if ( v51 || (v37 = CPP_what_block(1u, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v37)) )
            {
              v47 = 1;
              HIWORD(v38) = HIWORD(v134);
              LOWORD(v38) = *(UA<u16> *)(v134 + 4);
              v46 = v38;
              HIWORD(v38) = HIWORD(v134);
              LOWORD(v38) = *(UA<u16> *)(v134 + 6);
              v45 = v38;
              HIWORD(v38) = HIWORD(v134);
              LOWORD(v38) = *(UA<u16> *)(v134 + 8);
              v44[4] = v38;
              v48 = 1;
              v44[3] = v46;
              v44[2] = v45;
              v44[1] = v38;
              v44[0] = v46;
              v43 = v45;
              if ( !(u16)v38 )
              {
                CPP_organise_block(v48, (u16*)v44, (u16*)&v43);
                CPP_change_hit_block(v48, v44[0], v43);
              }
LABEL_136:
              *(UA<u16> *)(v134 + 10) = 0;
              *(UA<u16> *)(v134 + 12) = 0;
              v39 = 100;
              LOBYTE(v39) = no_players;
              v3 = 65534 - 0x7FFF * v39;
//              HIDWORD(v42) = 7;
//              LODWORD(v42) = v139;

              //MY_PlaySample(a1, a2, v42, 0x7FFFu, v3 - 200, 100i64, 3u);
                MY_PlaySample(/*a1, a2, v42*/  v139, 7, 0x7FFF, v3 - 200, 0x64, 0, 3);

              *(u8 *)(v134 + 16) = 41;
              goto LABEL_6;
            }
          }
        }
      }
      else if ( v133 <= 0x2Du )
      {
        LOWORD(v3) = vx[v139];
        v40 = v3 SHL8;
        *(UA<u16> *)(v134 + 4) -= v40;
        LOWORD(v40) = vy[v139];
        v3 = v40 SHL8;
        *(UA<u16> *)(v134 + 6) += v3;
        if ( *(UA<u16> *)(v134 + 6) <= 0xE000u && *(UA<u16> *)(v134 + 8) <= 0xE000u )
          ++*(u8 *)(v134 + 16);
        else
          *(u8 *)(v134 + 16) = 0;
      }
      else
      {
        if ( v133 < 0x2Fu )
        {
          *(u8 *)(v134 + 16) = 0;
          goto LABEL_6;
        }
        if ( v133 <= 0x2Fu )
        {
          *(UA<u16> *)(v134 + 4) += *(char *)(v134 + 24)  SHL8; //shift fix
          v3 = *(UA<i32> *)(v134 + 22) >> 24;
          if ( (int)*(u16 *)(v134 + 4) >> 11 == v3 )
            goto LABEL_106;
          *(UA<u16> *)(v134 + 10) += 72;
          v95 = v134;
          v94 = v134;
          v96 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
          if ( v96 || (v19 = CPP_what_block(v139, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v19)) )
          {
            v92 = v139;
            HIWORD(v20) = HIWORD(v134);
            LOWORD(v20) = *(UA<u16> *)(v134 + 4);
            v91 = v20;
            HIWORD(v20) = HIWORD(v134);
            LOWORD(v20) = *(UA<u16> *)(v134 + 6);
            v90 = v20;
            HIWORD(v20) = HIWORD(v134);
            LOWORD(v20) = *(UA<u16> *)(v134 + 8);
            v89[4] = v20;
            v93 = v139;
            v89[3] = v91;
            v89[2] = v90;
            v89[1] = v20;
            v89[0] = v91;
            v88 = v90;
            if ( !(u16)v20 )
            {
              CPP_organise_block(v93, (u16*)v89, (u16*)&v88);
              CPP_change_hit_block(v93, v89[0], v88);
            }
            goto LABEL_106;
          }
        }
        else if ( v133 == 48 )
        {
          *(UA<u16> *)(v134 + 4) += *(char *)(v134 + 24) SHL8;
          v3 = *(UA<i32> *)(v134 + 22) >> 24;
          if ( (int)*(u16 *)(v134 + 4) >> 11 == v3 )
            goto LABEL_106;
          *(UA<u16> *)(v134 + 10) += 72;
          v86 = v134;
          v85 = v134;
          v87 = CPP_check_bullets_to_aliens(/*a2,*/ v134) != 0;
          if ( v87 || (v21 = CPP_what_block(1u, *(UA<u16> *)(v134 + 4), *(UA<u16> *)(v134 + 6)), CPP_solid_block(v21)) )
          {
            v83 = 1;
            HIWORD(v22) = HIWORD(v134);
            LOWORD(v22) = *(UA<u16> *)(v134 + 4);
            v82 = v22;
            HIWORD(v22) = HIWORD(v134);
            LOWORD(v22) = *(UA<u16> *)(v134 + 6);
            v81 = v22;
            HIWORD(v22) = HIWORD(v134);
            LOWORD(v22) = *(UA<u16> *)(v134 + 8);
            v80[4] = v22;
            v84 = 1;
            v80[3] = v82;
            v80[2] = v81;
            v80[1] = v22;
            v80[0] = v82;
            v79 = v81;
            if ( !(u16)v22 )
            {
              CPP_organise_block(v84, (u16*)v80, (u16*)&v79);
              CPP_change_hit_block(v84, v80[0], v79);
            }
LABEL_106:
            v30 = 100;
            LOBYTE(v30) = no_players;
            v3 = 65534 - 0x7FFF * v30;
//            HIDWORD(v41) = 7;
//            LODWORD(v41) = v139;

//            MY_PlaySample(a1, a2, v41, 0x7FFFu, v3 - 200, 100i64, 3u);
              MY_PlaySample(/*a1, a2, v41*/ v139, 7, 0x7FFF, v3 - 200, 0x64, 0, 3);

            *(u8 *)(v134 + 16) = 41;
            *(UA<u16> *)(v134 + 10) = 0;
            *(UA<u16> *)(v134 + 12) = 0;
            goto LABEL_6;
          }
        }
      }
LABEL_6:
      ++v138;
      v134 += 30;
    }
  }
  return result;
}

i16 CPP_what_block(u8 a1, u16 a2, u16 a3) //FINAL
{
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int v7; // [esp+1Ch] [ebp+18h]

  v3 = ((int)a2 >> 8) + 8 - LOBYTE(scrollpos[a1]) % 8;
  v7 = (((int)LOBYTE(scrollpos[a1]) >> 3) + 32 - ((v3 - (__CFSHL__(v3 >> 31, 3) + 8 * (v3 >> 31))) >> 3)) % 32;
  v4 = ((int)a3 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
  if ( lastscroll[a1] == 1 )
    v5 = (((v4 - (__CFSHL__(v4 >> 31, 3) + 8 * (v4 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 994) % 1024;
  else
    v5 = (((v4 - (__CFSHL__(v4 >> 31, 3) + 8 * (v4 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 1027) % 1024;
  return *(UA<u16> *)(level + 2 * (32 * (u16)(1023 - v5) + (u16)v7));
}

char CPP_death_block(u16 a1) //FINAL
{
  u16 i; // [esp+0h] [ebp-Ch]
  char v3; // [esp+4h] [ebp-8h]

  v3 = 0;
  for ( i = 0; death_blocks[i] >= 0; ++i )
  {
    if ( a1 == *(UA<i32> *)((char *) byte_21FAC0 + 2 * i) >> 16 )
      v3 = 1;
  }
  return v3;
}

char CPP_ice_block(u16 a1) //FINAL
{
  u16 i; // [esp+0h] [ebp-Ch]
  char v3; // [esp+4h] [ebp-8h]

  v3 = 0;
  for ( i = 0; ice_blocks[i] > 0; ++i )
  {
    if ( a1 == *(UA<i32> *)((char *) byte_21FA68 + 2 * i) >> 16 )
      v3 = 1;
  }
  return v3;
}

char CPP_solid_block(u16 a1) //FINAL
{
  u16 i; // [esp+0h] [ebp-Ch]
  char v3; // [esp+4h] [ebp-8h]

  v3 = 0;
  for ( i = 0; solid_blocks[i] > 0; ++i )
  {
    if ( a1 == *(UA<i32> *)((char *) byte_21FCCC + 2 * i) >> 16 )
      v3 = 1;
  }
  return v3;
}

char CPP_swamp_block(u16 a1) //FINAL
{
  u16 i; // [esp+0h] [ebp-Ch]
  char v3; // [esp+4h] [ebp-8h]

  v3 = 0;
  for ( i = 0; swamp_blocks[i] > 0; ++i )
  {
    if ( a1 == *(UA<i32> *)((char *) byte_21FA2A + 2 * i) >> 16 )
      v3 = 1;
  }
  return v3;
}

char CPP_reverse_all(u16 a1) //FINAL
{
  u16 i; // [esp+0h] [ebp-Ch]
  char v3; // [esp+4h] [ebp-8h]

  v3 = 0;
  for ( i = 0; reverse_all_blocks[i] > 0; ++i )
  {
    if ( a1 == *(UA<i32> *)((char *) byte_21FBDE + 2 * i) >> 16 )
      v3 = 1;
  }
  return v3;
}

char CPP_reverse_y(u16 a1) //FINAL
{
  u16 i; // [esp+0h] [ebp-Ch]
  char v3; // [esp+4h] [ebp-8h]

  v3 = 0;
  for ( i = 0; reverse_y_blocks[i] > 0; ++i )
  {
    if ( a1 == *(UA<i32> *)((char *) unk_21FC42 + 2 * i) >> 16 )
      v3 = 1;
  }
  return v3;
}

char CPP_reverse_x(u16 a1) //FINAL
{
  u16 i; // [esp+0h] [ebp-Ch]
  char v3; // [esp+4h] [ebp-8h]

  v3 = 0;
  for ( i = 0; reverse_x_blocks[i] > 0; ++i )
  {
    if ( a1 == *(UA<i32> *)((char *) byte_21FC38 + 2 * i) >> 16 )
      v3 = 1;
  }
  return v3;
}

char CPP_do_player_blk_collision(u8 a3, u8 *a4, u8 *a5, u8 *a6, u8 *a7)
{
  u16 v7; // ax
  u16 v8; // ax
  u16 v9; // ax
  u16 v10; // ax
  u16 v11; // ax
//  i64 v13; // [esp-1Ch] [ebp-114h]
  u16 v14; // [esp-4h] [ebp-FCh]
  u16 mm; // [esp+0h] [ebp-F8h]
  char v16; // [esp+Ch] [ebp-ECh]
  u16 ll; // [esp+14h] [ebp-E4h]
  char v18; // [esp+20h] [ebp-D8h]
  u16 kk; // [esp+28h] [ebp-D0h]
  char v20; // [esp+34h] [ebp-C4h]
  u16 jj; // [esp+3Ch] [ebp-BCh]
  char v22; // [esp+48h] [ebp-B0h]
  u16 ii; // [esp+50h] [ebp-A8h]
  char v24; // [esp+5Ch] [ebp-9Ch]
  u16 n; // [esp+64h] [ebp-94h]
  char v26; // [esp+70h] [ebp-88h]
  u16 m; // [esp+78h] [ebp-80h]
  char v28; // [esp+84h] [ebp-74h]
  u16 l; // [esp+8Ch] [ebp-6Ch]
  char v30; // [esp+98h] [ebp-60h]
  u16 k; // [esp+A0h] [ebp-58h]
  char v32; // [esp+ACh] [ebp-4Ch]
  u16 j; // [esp+B4h] [ebp-44h]
  char v34; // [esp+C0h] [ebp-38h]
  u16 i; // [esp+C8h] [ebp-30h]
  char v36; // [esp+D4h] [ebp-24h]
  i16 v37; // [esp+DCh] [ebp-1Ch]
  i16 v38; // [esp+E0h] [ebp-18h]
  i16 v39; // [esp+E4h] [ebp-14h]
  u16 v40; // [esp+E8h] [ebp-10h]
  i16 v41; // [esp+ECh] [ebp-Ch]
  char v42; // [esp+F0h] [ebp-8h]

  v42 = 0;
  v7 = *((u16 *) unk_25677E + 15 * a3);
  HIBYTE(v7) += 7;
  v14 = v7;
  v8 = word_25677C[15 * a3];
  HIBYTE(v8) += 4;
  v37 = CPP_what_block(a3, v8, v14);
  v9 = *((u16 *) unk_25677E + 15 * a3);
  HIBYTE(v9) += 7;
  v38 = CPP_what_block(a3, word_25677C[15 * a3] - 1024, v9);
  v10 = word_25677C[15 * a3];
  HIBYTE(v10) += 4;
  v41 = CPP_what_block(a3, v10, *((u16 *) unk_25677E + 15 * a3) - 1792);
  v39 = CPP_what_block(a3, word_25677C[15 * a3] - 1024, *((u16 *) unk_25677E + 15 * a3) - 1792);
  v11 = CPP_what_block(a3, word_25677C[15 * a3], *((u16 *) unk_25677E + 15 * a3));
  v40 = v11;
  if ( *((u16 *) dword_256780 + 15 * a3) || blk_collision )
  {
    if ( *(UA<i32> *)((char *) dword_256791 + 30 * a3) >> 24 < -118 )
      *((u8 *) dword_256791 + 30 * a3 + 3) = -118;
    *((u8 *) dword_256791 + 30 * a3 + 3) -= 8;
    *a4 = *((u8 *) dword_256791 + 30 * a3);
    *a5 = 1;
    *a7 = 0;
    *a6 = 0;
  }
  else
  {
    v36 = 0;
    for ( i = 0; death_blocks[i] >= 0; ++i )
    {
      if ( v11 == *(UA<i32> *)((char *) byte_21FAC0 + 2 * i) >> 16 )
        v36 = 1;
    }
    if ( v36 && (CPP_death_block(v37) || CPP_death_block(v38) || CPP_death_block(v41) || CPP_death_block(v39)) )
    {
      *((u8 *) dword_256791 + 30 * a3 + 2) = 0;
      *((u8 *) dword_256791 + 30 * a3 + 1) = 0;
    }
    v34 = 0;
    for ( j = 0; jump_blocks[j] > 0; ++j )
    {
      if ( v40 == *(UA<i32> *)((char *) byte_21FAE4 + 2 * j) >> 16 )
        v34 = 1;
    }
    if ( v34 )
    {
//      HIDWORD(v13) = 11;
//      LODWORD(v13) = a3;

//    MY_PlaySample(a1, a2, v13, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
      MY_PlaySample(/*a1, a2, v13,*/ a3 , 0xB, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

      *((u8 *) dword_256791 + 30 * a3 + 3) = 80;
    }
    else
    {
      if ( *(UA<i32> *)((char *) dword_256791 + 30 * a3) >> 24 < -118 )
        *((u8 *) dword_256791 + 30 * a3 + 3) = -118;
      *((u8 *) dword_256791 + 30 * a3 + 3) -= 8;
    }
    v32 = 0;
    for ( k = 0; ice_blocks[k] > 0; ++k )
    {
      if ( v40 == *(UA<i32> *)((char *) byte_21FA68 + 2 * k) >> 16 )
        v32 = 1;
    }
    if ( v32 || CPP_ice_block(v37) || CPP_ice_block(v38) || CPP_ice_block(v41) || CPP_ice_block(v39) )
      *a4 = 0;
    else
      *a4 = *((u8 *) dword_256791 + 30 * a3);
    v30 = 0;
    for ( l = 0; swamp_blocks[l] > 0; ++l )
    {
      if ( v40 == *(UA<i32> *)((char *) byte_21FA2A + 2 * l) >> 16 )
        v30 = 1;
    }
    if ( v30 )
      *a5 = 3;
    else
      *a5 = 1;
    v28 = 0;
    for ( m = 0; arrow_up_blocks[m] > 0; ++m )
    {
      if ( v40 == *(UA<i32> *)((char *) byte_21FB06 + 2 * m) >> 16 )
        v28 = 1;
    }
    if ( v28 )
    {
      *a7 = 10;
    }
    else
    {
      v26 = 0;
      for ( n = 0; arrow_down_blocks[n] > 0; ++n )
      {
        if ( v40 == *(UA<i32> *)((char *) byte_21FB1A + 2 * n) >> 16 )
          v26 = 1;
      }
      if ( v26 )
        *a7 = -10;
      else
        *a7 = 0;
    }
    v24 = 0;
    for ( ii = 0; arrow_left_blocks[ii] > 0; ++ii )
    {
      if ( v40 == *(UA<i32> *)((char *) byte_21FB2E + 2 * ii) >> 16 )
        v24 = 1;
    }
    if ( v24 )
    {
      *a6 = 10;
    }
    else
    {
      v22 = 0;
      for ( jj = 0; arrow_right_blocks[jj] > 0; ++jj )
      {
        if ( v40 == *(UA<i32> *)((char *) byte_21FB76 + 2 * jj) >> 16 )
          v22 = 1;
      }
      if ( v22 )
        *a6 = -10;
      else
        *a6 = 0;
    }
    v20 = 0;
    for ( kk = 0; reverse_all_blocks[kk] > 0; ++kk )
    {
      if ( v40 == *(UA<i32> *)((char *) byte_21FBDE + 2 * kk) >> 16 )
        v20 = 1;
    }
    if ( v20 || CPP_reverse_all(v37) || CPP_reverse_all(v38) || CPP_reverse_all(v41) || CPP_reverse_all(v39) )
    {
      v42 = 1;
      *((u8 *) dword_256791 + 30 * a3 + 1) = -*((u8 *) dword_256791 + 30 * a3 + 1);
      *((u8 *) dword_256791 + 30 * a3 + 2) = -*((u8 *) dword_256791 + 30 * a3 + 2);
    }
    else
    {
      v18 = 0;
      for ( ll = 0; reverse_x_blocks[ll] > 0; ++ll )
      {
        if ( v40 == *(UA<i32> *)((char *) byte_21FC38 + 2 * ll) >> 16 )
          v18 = 1;
      }
      if ( v18 || CPP_reverse_x(v37) || CPP_reverse_x(v38) || CPP_reverse_x(v41) || CPP_reverse_x(v39) )
      {
        v42 = 1;
        *((u8 *) dword_256791 + 30 * a3 + 1) = -*((u8 *) dword_256791 + 30 * a3 + 1);
      }
      else
      {
        v16 = 0;
        for ( mm = 0; reverse_y_blocks[mm] > 0; ++mm )
        {
          if ( v40 == *(UA<i32> *)((char *) unk_21FC42 + 2 * mm) >> 16 )
            v16 = 1;
        }
        if ( v16 || CPP_reverse_y(v37) || CPP_reverse_y(v38) || CPP_reverse_y(v41) || CPP_reverse_y(v39) )
        {
          v42 = 1;
          *((u8 *) dword_256791 + 30 * a3 + 2) = -*((u8 *) dword_256791 + 30 * a3 + 2);
        }
      }
    }
  }
  return v42;
}

char CPP_change_block(u8 a1, u16 a2, u16 a3) //FINAL
{
  int v3; // edx
  u16 i; // [esp+4h] [ebp-Ch]
  u16 v6; // [esp+4h] [ebp-Ch]
  u16 v7; // [esp+8h] [ebp-8h]
  char v8; // [esp+Ch] [ebp-4h]
  char v9; // [esp+Ch] [ebp-4h]

  v8 = 0;
  v7 = *(UA<u16> *)(level + 2 * (32 * a3 + a2));
  for ( i = 0; contact_blocks[i] >= 0 && !v8; i += 2 )
  {
    if ( *(UA<i32> *)((char *) byte_21FE6C + 2 * i) >> 16 == v7 )
    {
      v7 = anim_order_1[i];
      v8 = 1;
    }
  }
  v6 = 0;
  v9 = 0;
  while ( hit_blocks[v6] >= 0 && !v9 )
  {
    if ( *(UA<i32> *)((char *) byte_21FDDA + 2 * v6) >> 16 == v7 )
    {
      v7 = word_21FDDE[v6];
      v9 = 1;
    }
    v6 += 2;
  }
  *(UA<u16> *)(2 * (32 * a3 + a2) + level) = v7;
  if ( lastscroll[a1] == 1 )
    v3 = (a1 << 16)
       + (((((int)HIBYTE(scrollpos[a1]) >> 3) + (a3 + (u16)level_line[a1]) % 1024) % 32) << 11);
  else
    v3 = (a1 << 16)
       + (((((int)HIBYTE(scrollpos[a1]) >> 3) + 32 - ((2048 - (u16)level_line[a1] - a3) % 1024 - 1)) % 32) << 11);

  return CPP_draw_block(8 * a2 + v3, v7);
}

u16 *CPP_organise_blocks(u8 a1, u16 *a2, u16 *a3, u16 *a4, u16 *a5, u16 *a6, u16 *a7, u16 *a8, u16 *a9, u16 *a10, u16 *a11, u16 *a12, u16 *a13) //FINAL
{
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // edx
  u16 *result; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax

  v13 = ((int)(u16)*a2 >> 8) + 8 - LOBYTE(scrollpos[a1]) % 8;
  *a2 = (((int)LOBYTE(scrollpos[a1]) >> 3) + 32 - ((v13 - (__CFSHL__(v13 >> 31, 3) + 8 * (v13 >> 31))) >> 3)) % 32;
  v14 = ((int)(u16)*a4 >> 8) + 8 - LOBYTE(scrollpos[a1]) % 8;
  *a4 = (((int)LOBYTE(scrollpos[a1]) >> 3) + 32 - ((v14 - (__CFSHL__(v14 >> 31, 3) + 8 * (v14 >> 31))) >> 3)) % 32;
  v15 = ((int)(u16)*a6 >> 8) + 8 - LOBYTE(scrollpos[a1]) % 8;
  *a6 = (((int)LOBYTE(scrollpos[a1]) >> 3) + 32 - ((v15 - (__CFSHL__(v15 >> 31, 3) + 8 * (v15 >> 31))) >> 3)) % 32;
  v16 = ((int)(u16)*a8 >> 8) + 8 - LOBYTE(scrollpos[a1]) % 8;
  *a8 = (((int)LOBYTE(scrollpos[a1]) >> 3) + 32 - ((v16 - (__CFSHL__(v16 >> 31, 3) + 8 * (v16 >> 31))) >> 3)) % 32;
  v17 = ((int)(u16)*a10 >> 8) + 8 - LOBYTE(scrollpos[a1]) % 8;
  *a10 = (((int)LOBYTE(scrollpos[a1]) >> 3) + 32 - ((v17 - (__CFSHL__(v17 >> 31, 3) + 8 * (v17 >> 31))) >> 3)) % 32;
  v18 = ((int)(u16)*a12 >> 8) + 8 - LOBYTE(scrollpos[a1]) % 8;
  *a12 = (((int)LOBYTE(scrollpos[a1]) >> 3) + 32 - ((v18 - (__CFSHL__(v18 >> 31, 3) + 8 * (v18 >> 31))) >> 3)) % 32;
  v19 = ((int)(u16)*a3 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
  if ( lastscroll[a1] == 1 )
  {
    *a3 = 1023
        - (((v19 - (__CFSHL__(v19 >> 31, 3) + 8 * (v19 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 994)
        % 1024;
    v20 = ((int)(u16)*a5 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    *a5 = 1023
        - (((v20 - (__CFSHL__(v20 >> 31, 3) + 8 * (v20 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 994)
        % 1024;
    v21 = ((int)(u16)*a7 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    *a7 = 1023
        - (((v21 - (__CFSHL__(v21 >> 31, 3) + 8 * (v21 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 994)
        % 1024;
    v22 = ((int)(u16)*a9 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    *a9 = 1023
        - (((v22 - (__CFSHL__(v22 >> 31, 3) + 8 * (v22 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 994)
        % 1024;
    v23 = ((int)(u16)*a11 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    *a11 = 1023
         - (((v23 - (__CFSHL__(v23 >> 31, 3) + 8 * (v23 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 994)
         % 1024;
    v24 = ((int)(u16)*a13 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    v25 = (((v24 - (__CFSHL__(v24 >> 31, 3) + 8 * (v24 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 994)
        % 1024;
  }
  else
  {
    *a3 = 1023
        - (((v19 - (__CFSHL__(v19 >> 31, 3) + 8 * (v19 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 1027)
        % 1024;
    v27 = ((int)(u16)*a5 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    *a5 = 1023
        - (((v27 - (__CFSHL__(v27 >> 31, 3) + 8 * (v27 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 1027)
        % 1024;
    v28 = ((int)(u16)*a7 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    *a7 = 1023
        - (((v28 - (__CFSHL__(v28 >> 31, 3) + 8 * (v28 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 1027)
        % 1024;
    v29 = ((int)(u16)*a9 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    *a9 = 1023
        - (((v29 - (__CFSHL__(v29 >> 31, 3) + 8 * (v29 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 1027)
        % 1024;
    v30 = ((int)(u16)*a11 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    *a11 = 1023
         - (((v30 - (__CFSHL__(v30 >> 31, 3) + 8 * (v30 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 1027)
         % 1024;
    v31 = ((int)(u16)*a13 >> 8) + 8 - HIBYTE(scrollpos[a1]) % 8;
    v25 = (((v31 - (__CFSHL__(v31 >> 31, 3) + 8 * (v31 >> 31))) >> 3) - 4 + (u16)level_line[a1] + 1027)
        % 1024;
  }
  result = a13;
  *a13 = 1023 - v25;
  return result;
}

u8 CPP_do_contact_blocks(void) //FINAL
{
  u8 result; // al
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp+0h] [ebp-34h] BYREF
  int v14; // [esp+4h] [ebp-30h] BYREF
  int v15; // [esp+8h] [ebp-2Ch] BYREF
  int v16; // [esp+Ch] [ebp-28h] BYREF
  int v17; // [esp+10h] [ebp-24h] BYREF
  int v18; // [esp+14h] [ebp-20h] BYREF
  int v19; // [esp+18h] [ebp-1Ch] BYREF
  int v20; // [esp+1Ch] [ebp-18h] BYREF
  int v21; // [esp+20h] [ebp-14h] BYREF
  int v22; // [esp+24h] [ebp-10h] BYREF
  int v23; // [esp+28h] [ebp-Ch] BYREF
  int v24; // [esp+2Ch] [ebp-8h] BYREF
  u8 i; // [esp+30h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= (u8)no_players )
      break;
    if ( !*((u16 *) dword_256780 + 15 * i) )
    {
      v1 = 30 * i;
      LOWORD(v1) = *(UA<i16> *)((char *)word_25677C + v1);
      BYTE1(v1) += 4;
      v19 = v1;
      v2 = 30 * i;
      LOWORD(v2) = *(UA<u16> *)((char *) unk_25677E + v2);
      BYTE1(v2) += 7;
      v24 = v2;
      v3 = 30 * i;
      LOWORD(v3) = *(UA<i16> *)((char *)word_25677C + v3);
      v23 = v3 - 1024;
      v4 = 30 * i;
      LOWORD(v4) = *(UA<u16> *)((char *) unk_25677E + v4);
      BYTE1(v4) += 7;
      v22 = v4;
      v5 = 30 * i;
      LOWORD(v5) = *(UA<i16> *)((char *)word_25677C + v5);
      BYTE1(v5) += 4;
      v17 = v5;
      v6 = 30 * i;
      LOWORD(v6) = *(UA<u16> *)((char *) unk_25677E + v6);
      v16 = v6 - 1792;
      v7 = 30 * i;
      LOWORD(v7) = *(UA<i16> *)((char *)word_25677C + v7);
      v15 = v7 - 1024;
      v8 = 30 * i;
      LOWORD(v8) = *(UA<u16> *)((char *) unk_25677E + v8);
      v14 = v8 - 1792;
      v9 = 30 * i;
      LOWORD(v9) = *(UA<i16> *)((char *)word_25677C + v9);
      v21 = v9 - 1024;
      v10 = 30 * i;
      LOWORD(v10) = *(UA<u16> *)((char *) unk_25677E + v10);
      v20 = v10;
      v11 = 30 * i;
      LOWORD(v11) = *(UA<i16> *)((char *)word_25677C + v11);
      BYTE1(v11) += 4;
      v13 = v11;
      v12 = 30 * i;
      LOWORD(v12) = *(UA<u16> *)((char *) unk_25677E + v12);
      v18 = v12;

      CPP_organise_blocks(i, (u16*)&v19, (u16*)&v24, (u16*)&v23, (u16*)&v22, (u16*)&v21, (u16*)&v20, (u16*)&v13, (u16*)&v18, (u16*)&v17, (u16*)&v16, (u16*)&v15, (u16*)&v14);
      CPP_change_block(i, v19, v24);

      if ( (u16)v19 != (u16)v23 || (u16)v24 != (u16)v22 )
        CPP_change_block(i, v23, v22);
      if ( ((u16)v21 != (u16)v19 || (u16)v20 != (u16)v24)
        && ((u16)v21 != (u16)v23 || (u16)v20 != (u16)v22) )
      {
        CPP_change_block(i, v21, v20);
      }
      if ( ((u16)v13 != (u16)v19 || (u16)v18 != (u16)v24)
        && ((u16)v13 != (u16)v23 || (u16)v18 != (u16)v22)
        && ((u16)v13 != (u16)v21 || (u16)v18 != (u16)v20) )
      {
        CPP_change_block(i, v13, v18);
      }
      if ( ((u16)v17 != (u16)v19 || (u16)v16 != (u16)v24)
        && ((u16)v17 != (u16)v23 || (u16)v16 != (u16)v22)
        && ((u16)v17 != (u16)v21 || (u16)v16 != (u16)v20)
        && ((u16)v17 != (u16)v13 || (u16)v16 != (u16)v18) )
      {
        CPP_change_block(i, v17, v16);
      }
      if ( ((u16)v15 != (u16)v19 || (u16)v14 != (u16)v24)
        && ((u16)v15 != (u16)v23 || (u16)v14 != (u16)v22)
        && ((u16)v15 != (u16)v21 || (u16)v14 != (u16)v20)
        && ((u16)v15 != (u16)v13 || (u16)v14 != (u16)v18)
        && ((u16)v15 != (u16)v17 || (u16)v14 != (u16)v16) )
      {
        CPP_change_block(i, v15, v14);
      }
    }
  }
  return result;
}

i16 CPP_arctan(int a1, int a2) //FINAL
{
  int v2; // ebx
  i16 result; // ax
  int v4; // ebx
  int v5; // eax
  int v6; // ebx

  if ( a1 )
  {
    v2 = a2;
  }
  else
  {
    v2 = a2;
    if ( !a2 )
      return 0;
  }
  if ( a1 < 0 )
  {
    v5 = -a1;
    if ( v2 < 0 )
    {
      v6 = -v2;
      if ( v5 < v6 )
        result = 2048 - word_1A5300[-256 * a1 / (unsigned int)v6];
      else
        result = word_1A5300[(v6 << 8) / (unsigned int)v5] + 1536;
    }
    else if ( v5 < v2 )
    {
      result = word_1A5300[-256 * a1 / (unsigned int)v2] + 1024;
    }
    else
    {
      result = 1536 - word_1A5300[(v2 << 8) / (unsigned int)v5];
    }
  }
  else if ( v2 < 0 )
  {
    v4 = -v2;
    if ( a1 < v4 )
      result = word_1A5300[(a1 << 8) / (unsigned int)v4];
    else
      result = 512 - word_1A5300[(v4 << 8) / (unsigned int)a1];
  }
  else if ( a1 < v2 )
  {
    result = 1024 - word_1A5300[(a1 << 8) / (unsigned int)v2];
  }
  else
  {
    result = word_1A5300[(v2 << 8) / (unsigned int)a1] + 512;
  }
  return result;
}

char CPP_how_many_bullets(char a1, u8 a2) //FINAL
{
  char *v3; // [esp+0h] [ebp-10h]
  char v4; // [esp+8h] [ebp-8h]
  u8 i; // [esp+Ch] [ebp-4h]

  v4 = 0;
  v3 = (char *) bullets + 1020 * a2;
  for ( i = 0; i < 0x22u; ++i )
  {
    if ( v3[16] == a1 )
      ++v4;
    v3 += 30;
  }
  return v4;
}

char CPP_add_bullet(u8 a3)
{
 int a1;

  i16 v3; // dx
  i16 v4; // dx
  i16 v5; // dx
  int v6; // ebx
  char *v7; // eax
  int v8; // ebx
  i16 v9; // dx
  int v10; // ebx
  i16 v11; // dx
  i16 v12; // dx
  i16 v13; // dx
  int v14; // ebx
  i16 v15; // dx
  i16 v16; // dx
//  i64 v18; // [esp-1Ch] [ebp-30h]
//  i64 v19; // [esp-1Ch] [ebp-30h]
//  i64 v20; // [esp-1Ch] [ebp-30h]
//  i64 v21; // [esp-1Ch] [ebp-30h]
//  i64 v22; // [esp-1Ch] [ebp-30h]
  char *v23; // [esp+4h] [ebp-10h]
  u8 i; // [esp+8h] [ebp-Ch]
  u8 j; // [esp+8h] [ebp-Ch]
  u8 l; // [esp+8h] [ebp-Ch]
  u8 m; // [esp+8h] [ebp-Ch]
  u8 k; // [esp+8h] [ebp-Ch]
  u8 v29; // [esp+Ch] [ebp-8h]
  u8 v30; // [esp+Ch] [ebp-8h]
  u8 v31; // [esp+Ch] [ebp-8h]
  u8 v32; // [esp+10h] [ebp-4h]
  char v33; // [esp+10h] [ebp-4h]

  v23 = (char *) bullets + 1020 * a3;
  for ( i = 0; v23[30 * i + 16] && i < 0x22u; ++i )
    ;
  if ( i < 0x22u )
  {
    a1 = 30 * a3;
    if ( (u8)CPP_how_many_bullets(a3 + 13, a3) < *((u8 *) dword_25678D + a1 + 1) )
    {
      v23[30 * i + 16] = a3 + 13;
      v23[30 * i + 24] = 1;
      *(UA<u16> *)&v23[30 * i + 4] = word_25677C[15 * a3];
      v3 = *((u16 *) unk_25677E + 15 * a3);
      HIBYTE(v3) += 7;
      *(UA<u16> *)&v23[30 * i + 6] = v3;
      *(UA<u16> *)&v23[30 * i + 8] = *((u16 *) dword_256780 + 15 * a3);
      *(UA<u16> *)&v23[30 * i + 10] = 0;
      *(UA<u16> *)&v23[30 * i + 12] = 0;
      *(UA<u16> *)&v23[30 * i + 14] = 20;
      byte_29F698[a3] ^= 1u;
      v23[30 * i++ + 29] = byte_29F698[a3];
      while ( v23[30 * i + 16] && i < 0x22u )
        ++i;
    }
  }
  if ( i < 0x22u )
  {
    a1 = 30 * a3;
    v32 = CPP_how_many_bullets(a3 + 9, a3);
    if ( v32 < *((u8 *) dword_25678D + a1) )
    {
      a1 = 14 / *((u8 *) dword_25678D + 30 * a3);
      if ( abs(turn - dword_29F6A4[a3]) > a1 || !v32 )
      {
//        HIDWORD(v18) = 2;
//        LODWORD(v18) = a3;

//        MY_PlaySample((unsigned int *)a1, a2, v18, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
        MY_PlaySample(/*(unsigned int *)a1, a2, v18,*/ a3, 2, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

        dword_29F6A4[a3] = turn;
        v23[30 * i + 16] = a3 + 9;
        if ( vy[a3] > 0 )
          v23[30 * i + 24] = -12 - abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16);
        else
          v23[30 * i + 24] = abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16) + 12;
        *(UA<u16> *)&v23[30 * i + 4] = word_25677C[15 * a3];
        v4 = *((u16 *) unk_25677E + 15 * a3);
        HIBYTE(v4) += 7;
        *(UA<u16> *)&v23[30 * i + 6] = v4;
        a1 = (int)&v23[30 * i];
        *(UA<u16> *)(a1 + 8) = *((u16 *) dword_256780 + 15 * a3);
        *(UA<u16> *)(a1 + 12) = 0;
        *(UA<u16> *)(a1 + 10) = 0;
        *(UA<u16> *)(a1 + 14) = 10;
        ++i;
        while ( v23[30 * i + 16] && i < 0x22u )
          ++i;
      }
    }
  }
  if ( i < 0x22u )
  {
    a1 = 30 * a3;
    v32 = CPP_how_many_bullets(a3 + 4, a3);
    if ( v32 < (u8)byte_25678C[a1] )
    {
      a1 = 28 / (u8)byte_25678C[30 * a3];
      if ( abs(turn - dword_29F69C[a3]) > a1 || !v32 )
      {
        dword_29F69C[a3] = turn;
        v23[30 * i + 16] = a3 + 4;
        v23[30 * i + 24] = 1;
        *(UA<u16> *)&v23[30 * i + 4] = word_25677C[15 * a3];
        v5 = *((u16 *) unk_25677E + 15 * a3);
        HIBYTE(v5) += 7;
        *(UA<u16> *)&v23[30 * i + 6] = v5;
        *(UA<u16> *)&v23[30 * i + 8] = *((u16 *) dword_256780 + 15 * a3);
        *(UA<u16> *)&v23[30 * i + 12] = -506;
        *(UA<u16> *)&v23[30 * i + 10] = 0;
        *(UA<u16> *)&v23[30 * i++ + 14] = 3;
        while ( v23[30 * i + 16] && i < 0x22u )
          ++i;
      }
    }
  }
  if ( i < 0x22u )
  {
    v6 = (u8)byte_25678B[30 * a3];
    v32 = CPP_how_many_bullets(a3 + 47, a3);
    a1 = v6 - 2;
    if ( v32 <= a1 )
    {
      a1 = 4 * a3;
      if ( /*abs*/ ((unsigned)(turn - *(UA<i32> *)((char *)dword_29F6AC + a1)) > (unsigned int)(56 / (u8)byte_25678B[30 * a3])) || !v32 ) //unsigned fix
      {
        dword_29F6AC[a3] = turn;
        v29 = i;
        for ( j = i + 1; v23[30 * j + 16] && j < 0x22u; ++j )
          ;
        if ( j >= 0x22u )
        {
          i = v29;
        }
        else
        {
//          HIDWORD(v19) = 1;
//          LODWORD(v19) = a3;

//          MY_PlaySample((unsigned int *)a1, a2, v19, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
          MY_PlaySample(/*(unsigned int *)a1, a2, v19,*/ a3, 1, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

          v23[30 * j + 16] = a3 + 47;
          v23[30 * j + 24] = 4;
          *(UA<u16> *)&v23[30 * j + 12] = 0;
          *(UA<u16> *)&v23[30 * j + 4] = word_25677C[15 * a3];
          *(UA<u16> *)&v23[30 * j + 6] = *((u16 *) unk_25677E + 15 * a3);
          *(UA<u16> *)&v23[30 * j + 8] = *((u16 *) dword_256780 + 15 * a3);
          v23[30 * j + 25] = (((int)(u16)word_25677C[15 * a3] >> 11) + 16) % 32;
          *(UA<u16> *)&v23[30 * j + 14] = 2;
          v23[30 * v29 + 16] = a3 + 47;
          v23[30 * v29 + 24] = -4;
          *(UA<u16> *)&v23[30 * v29 + 12] = 0;
          *(UA<u16> *)&v23[30 * v29 + 4] = word_25677C[15 * a3];
          *(UA<u16> *)&v23[30 * v29 + 6] = *((u16 *) unk_25677E + 15 * a3);
          *(UA<u16> *)&v23[30 * v29 + 8] = *((u16 *) dword_256780 + 15 * a3);
          a1 = 32;
          v23[30 * v29 + 25] = (((int)(u16)word_25677C[15 * a3] >> 11) + 16) % 32;
          *(UA<u16> *)&v23[30 * v29 + 14] = 2;
          for ( i = j + 1; v23[30 * i + 16] && i < 0x22u; ++i )
            ;
        }
      }
    }
  }
  LOBYTE(v7) = 30 * a3;
  if ( *((u8 *) dword_25678D + 30 * a3 + 2) == 3 )
  {
    if ( i < 0x22u )
    {
      LOBYTE(v7) = 30 * a3;
      if ( !*((u8 *) dword_25678D + 30 * a3) )
      {
        if ( (v8 = 30 * a3,
              LOBYTE(v7) = CPP_how_many_bullets(a3 + 2, a3),
              v33 = (char)((int)v7), //??? mingw todo
              (u8)((int)v7) < *((u8 *) dword_25678D + v8 + 2)) //??? mingw todo
          && (v8 = 28 / *((u8 *) dword_25678D + 30 * a3 + 2),
              v7 = (char *)abs(turn - dword_29F6B4[a3]),
              (int)v7 > v8)
          || !v33 )
        {
//          HIDWORD(v20) = 1;
//          LODWORD(v20) = a3;

//          MY_PlaySample((unsigned int *)v8, a2, v20, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
          MY_PlaySample(/*(unsigned int *)v8, a2, v20,*/ a3, 1, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

          v23[30 * i + 16] = a3 + 2;
          if ( vy[a3] > 0 )
            v23[30 * i + 24] = -8 - abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16);
          else
            v23[30 * i + 24] = abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16) + 8;
          *(UA<u16> *)&v23[30 * i + 4] = word_25677C[15 * a3];
          v9 = *((u16 *) unk_25677E + 15 * a3);
          HIBYTE(v9) += 7;
          *(UA<u16> *)&v23[30 * i + 6] = v9;
          *(UA<u16> *)&v23[30 * i + 8] = *((u16 *) dword_256780 + 15 * a3);
          v23[30 * i + 26] = 0;
          *(UA<u32> *)&v23[30 * i] = 40;
          *(UA<u16> *)&v23[30 * i + 14] = 1;
          LOBYTE(v7) = turn;
          dword_29F6B4[a3] = turn;
        }
      }
    }
  }
  else if ( i >= 0x22u
         || (LOBYTE(v7) = 30 * a3, *((u8 *) dword_25678D + 30 * a3))
         || ((v10 = *((u8 *) dword_25678D + 30 * a3 + 2),
              v32 = CPP_how_many_bullets(a3 + 2, a3),
              LOBYTE(v7) = v32,
              a1 = v10 - 3,
              v32 > a1)
          || (a1 = 28 / (*((u8 *) dword_25678D + 30 * a3 + 2) / 3),
              v7 = (char *)abs(turn - dword_29F6B4[a3]),
              (int)v7 <= a1))
         && v32 >= 3u )
  {
    if ( i < 0x22u
      && (LOBYTE(v7) = 30 * a3, *((u8 *) dword_25678D + 30 * a3))
      && (v14 = *((u8 *) dword_25678D + 30 * a3 + 2)
              - *((u8 *) dword_25678D + 30 * a3 + 2) / 3,
          v32 = CPP_how_many_bullets(a3 + 2, a3),
          LOBYTE(v7) = v32,
          a1 = v14 - 2,
          v32 <= a1)
      && (a1 = 28 / (*((u8 *) dword_25678D + 30 * a3 + 2) / 3),
          v7 = (char *)abs(turn - dword_29F6B4[a3]),
          (int)v7 > a1)
      || v32 < 2u )
    {
      v31 = i;
      for ( k = i + 1; ; ++k )
      {
        v7 = &v23[30 * k];
        if ( !v7[16] || k >= 0x22u )
          break;
      }
      if ( k < 0x22u )
      {
//        HIDWORD(v22) = 1;
//        LODWORD(v22) = a3;

//        MY_PlaySample((unsigned int *)a1, a2, v22, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
        MY_PlaySample(/*(unsigned int *)a1, a2, v22,*/ a3, 1, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

        v23[30 * k + 16] = a3 + 2;
        if ( vy[a3] > 0 )
          v23[30 * k + 24] = -8 - abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16);
        else
          v23[30 * k + 24] = abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16) + 8;
        *(UA<u16> *)&v23[30 * k + 4] = word_25677C[15 * a3];
        v15 = *((u16 *) unk_25677E + 15 * a3);
        HIBYTE(v15) += 7;
        *(UA<u16> *)&v23[30 * k + 6] = v15;
        *(UA<u16> *)&v23[30 * k + 8] = *((u16 *) dword_256780 + 15 * a3);
        *(UA<u32> *)&v23[30 * k] = 40;
        *(UA<u16> *)&v23[30 * k + 14] = 1;
        v23[30 * k + 26] = 1;
        v23[30 * v31 + 16] = a3 + 2;
        if ( vy[a3] > 0 )
          v23[30 * v31 + 24] = -8 - abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16);
        else
          v23[30 * v31 + 24] = abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16) + 8;
        *(UA<u16> *)&v23[30 * v31 + 4] = word_25677C[15 * a3];
        v16 = *((u16 *) unk_25677E + 15 * a3);
        HIBYTE(v16) += 7;
        *(UA<u16> *)&v23[30 * v31 + 6] = v16;
        *(UA<u32> *)&v23[30 * v31] = 40;
        *(UA<u16> *)&v23[30 * v31 + 8] = *((u16 *) dword_256780 + 15 * a3);
        *(UA<u16> *)&v23[30 * v31 + 14] = 1;
        v23[30 * v31 + 26] = -1;
        LOBYTE(v7) = turn;
        dword_29F6B4[a3] = turn;
      }
    }
  }
  else
  {
    v30 = i;
    for ( l = i + 1; ; ++l )
    {
      v7 = &v23[30 * l];
      if ( !v7[16] || l >= 0x22u )
        break;
    }
    if ( l < 0x22u )
    {
//      HIDWORD(v21) = 1;
//      LODWORD(v21) = a3;

//      MY_PlaySample((unsigned int *)a1, a2, v21, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
      MY_PlaySample(/*(unsigned int *)a1, a2, v21,*/ a3, 1, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

      v23[30 * l + 16] = a3 + 2;
      v23[30 * l + 24] = vy[a3] > 0 ? -8 - abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16) : abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16)
                                                                                   + 8;
      *(UA<u16> *)&v23[30 * l + 4] = word_25677C[15 * a3];
      v11 = *((u16 *) unk_25677E + 15 * a3);
      HIBYTE(v11) += 7;
      *(UA<u16> *)&v23[30 * l + 6] = v11;
      *(UA<u16> *)&v23[30 * l + 8] = *((u16 *) dword_256780 + 15 * a3);
      *(UA<u32> *)&v23[30 * l] = 40;
      *(UA<u16> *)&v23[30 * l + 14] = 1;
      v23[30 * l + 26] = 1;
      v23[30 * v30 + 16] = a3 + 2;
      v23[30 * v30 + 24] = vy[a3] > 0 ? -8 - abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16) : abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16)
                                                                                     + 8;
      *(UA<u16> *)&v23[30 * v30 + 4] = word_25677C[15 * a3];
      v12 = *((u16 *) unk_25677E + 15 * a3);
      HIBYTE(v12) += 7;
      *(UA<u16> *)&v23[30 * v30 + 6] = v12;
      *(UA<u16> *)&v23[30 * v30 + 8] = *((u16 *) dword_256780 + 15 * a3);
      *(UA<u16> *)&v23[30 * v30 + 14] = 1;
      *(UA<u32> *)&v23[30 * v30] = 40;
      v23[30 * v30 + 26] = -1;
      dword_29F6B4[a3] = turn;
      for ( m = l + 1; ; ++m )
      {
        v7 = &v23[30 * m];
        if ( !v7[16] || m >= 0x22u )
          break;
      }
      if ( m < 0x22u )
      {
        v23[30 * m + 16] = a3 + 2;
        if ( vy[a3] > 0 )
          v23[30 * m + 24] = -8 - abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16);
        else
          v23[30 * m + 24] = abs(*(UA<i32> *)&byte_21F946[2 * a3] >> 16) + 8;
        *(UA<u16> *)&v23[30 * m + 4] = word_25677C[15 * a3];
        v13 = *((u16 *) unk_25677E + 15 * a3);
        HIBYTE(v13) += 7;
        *(UA<u16> *)&v23[30 * m + 6] = v13;
        *(UA<u16> *)&v23[30 * m + 8] = *((u16 *) dword_256780 + 15 * a3);
        *(UA<u32> *)&v23[30 * m] = 40;
        v23[30 * m + 26] = 0;
        v7 = &v23[30 * m];
        *((u16 *)v7 + 7) = 1;
      }
    }
  }
  return (char)((int)v7); //??? mingw todo
}

int CPP_smart_bomb(u8 a3)
{
  int result; // eax
//  i64 v4; // [esp-1Ch] [ebp-28h]
  int *v5; // [esp+4h] [ebp-8h]
  u16 i; // [esp+8h] [ebp-4h]

  v5 = &aliens[450 * a3];
  result = 30 * a3;
  if ( byte_25678A[result] )
  {
    result = abs(turn - dword_29F690[a3]);
    if ( result > 20 )
    {
      dword_29F690[a3] = turn;
//      HIDWORD(v4) = 5;
//      LODWORD(v4) = a3;

//      MY_PlaySample(a1, a2, v4, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 200, 100i64, 3u);
      MY_PlaySample(/*a1, a2, v4,*/ a3, 5, 0x7FFF, -2 - 0x7FFF * (u8)no_players - 200, 0x64, 0, 3);

      for ( i = 0; i < 0x3Cu; ++i )
      {
        if ( *((u8 *)v5 + 16)
          && *((u8 *)v5 + 16) != 21
          && (*((u8 *)v5 + 16) < 0x19u || *((u8 *)v5 + 16) > 0x2Eu) )
        {
          if ( *((i16 *)v5 + 7) > 50 )
          {
            *((u16 *)v5 + 7) -= 50;
          }
          else
          {
            switch ( *((u8 *)v5 + 16) )
            {
              case 6:
                the_score[a3] += 100;
                *((u16 *)v5 + 6) = 0;
                *((u8 *)v5 + 16) = 21;
                *((u8 *)v5 + 24) = 0;
                *((u16 *)v5 + 7) = 127;
                break;
              case 7:
                *((u8 *)v5 + 16) = 25;
                *((u16 *)v5 + 5) = 0;
                *((u16 *)v5 + 6) = 0;
                the_score[a3] += 5;
                break;
              case 8:
                *((u8 *)v5 + 16) = 25;
                *((u16 *)v5 + 5) = 0;
                *((u16 *)v5 + 6) = 0;
                the_score[a3] += 15;
                break;
              case 0xB:
                *((u8 *)v5 + 16) = 25;
                *((u16 *)v5 + 5) = 0;
                *((u16 *)v5 + 6) = 0;
                the_score[a3] += 2;
                break;
              case 0xC:
                *((u8 *)v5 + 16) = 25;
                *((u16 *)v5 + 5) = 0;
                *((u16 *)v5 + 6) = 0;
                the_score[a3] += 50;
                break;
              case 0xF:
                *((u8 *)v5 + 16) = 25;
                *((u16 *)v5 + 5) = 0;
                *((u16 *)v5 + 6) = 0;
                the_score[a3] += 15;
                break;
              case 0x10:
                *((u8 *)v5 + 16) = 25;
                *((u16 *)v5 + 5) = 0;
                *((u16 *)v5 + 6) = 0;
                the_score[a3] += 15;
                break;
              case 0x11:
                *((u8 *)v5 + 16) = 25;
                *((u16 *)v5 + 5) = 0;
                *((u16 *)v5 + 6) = 0;
                the_score[a3] += 10;
                break;
              case 0x17:
                *((u8 *)v5 + 16) = 25;
                *((u16 *)v5 + 5) = 0;
                *((u16 *)v5 + 6) = 0;
                the_score[a3] += 15;
                break;
              default:
                break;
            }
          }
        }
        v5 = (int *)((char *)v5 + 30);
      }
      result = 30 * a3;
      --byte_25678A[result];
    }
  }
  return result;
}

//#pragma GCC push_options

//#pragma GCC optimize ("no-tree-fre")
//#pragma GCC optimize ("no-tree-pre")
//#pragma GCC optimize ("no-tree-dominator-opts")

int CPP_do_players_ships(void) //Пересекающиеся указатели, не давали выставить маскимальную оптимизацию: dword_25678D и dword_256791.
{
  int result; // eax
  unsigned int *v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // esi
  int v19; // eax
  int v20; // eax
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // ebx
  int v30; // eax
  int v31; // eax
  int v32; // ebx
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
//  i64 v38; // [esp-1Ch] [ebp-50h]
//  i64 v39; // [esp-1Ch] [ebp-50h]
  int v40; // [esp-4h] [ebp-38h]
  int v41; // [esp-4h] [ebp-38h]
  int v42; // [esp-4h] [ebp-38h]
  int v43; // [esp-4h] [ebp-38h]
  int v44; // [esp-4h] [ebp-38h]
  int v45; // [esp-4h] [ebp-38h]
  int v46; // [esp-4h] [ebp-38h]
  int v47; // [esp-4h] [ebp-38h]
  int v48; // [esp-4h] [ebp-38h]
  int v49; // [esp-4h] [ebp-38h]
  char v50; // [esp+4h] [ebp-30h]
  char v51; // [esp+Ch] [ebp-28h]
  int v52; // [esp+10h] [ebp-24h]
  int v53; // [esp+10h] [ebp-24h]

  /*int*/ char  v54; // [esp+1Ch] [ebp-18h]  //ранее значение этой переменной подменялось, если она была char. Возможно, была порча памяти?

  char v55[4]; // [esp+20h] [ebp-14h] BYREF
  char v56[4]; // [esp+24h] [ebp-10h] BYREF
  char v57[4]; // [esp+28h] [ebp-Ch] BYREF
  char v58[4]; // [esp+2Ch] [ebp-8h] BYREF
  s8 i; // [esp+30h] [ebp-4h]

  if ( level_no == 3 )
    blk_collision = 0;

  for ( i = 0; ; ++i )
  {
    result = (u8)no_players;

    if ( i >= (int)(u8)no_players )
      break;

//----------------------------------------------------------------------------------
    if ( (!flicker[i] || !level_start) && !game_over_flag[i] )
    {
      v54 = CPP_do_player_blk_collision(/*(unsigned int *)a1, a2,*/  i, (u8*)v58, (u8*)v57, (u8*)v56, (u8*)v55);
      CPP_do_contact_blocks();

      if ( !v54 ) //ранее это условие не выполнялось, если v54 - char.  Была порча памяти? Спасало глобальное объявление, либо int
      {
        if ( joysx[i] )
        {
          v52 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
          v3 = (unsigned int *)(30 * i);
          *((u8 *) dword_256791 + (u32)v3 + 1) += *((u8 *) dword_256791 + (u32)v3) * -LOBYTE(joysx[i]);
          if ( v52 >= 0 )
            v51 = v52 > 0;
          else
            v51 = -1;
          if ( *((char *) dword_256791 + 30 * i + 1) >= 0 )
            v50 = *((u8 *) dword_256791 + 30 * i + 1) > 0;
          else
            v50 = -1;
          if ( v51 != v50 && v51 && v50 )
          {
//            HIDWORD(v38) = 8;
//            LODWORD(v38) = i;

            //MY_PlaySample(v3, a2, v38, 0x7FFFu, -2 - 0x7FFF * (u8)no_players - 2 * i, 100i64, 3u);
            MY_PlaySample(/*v3, a2, v38*/ i, 8 ,  0x7FFFu    , -2 - 0x7FFF * (u8)no_players - 2 * i, 0x64, 0, 3);
          }
        }
        else if ( *((char *) dword_256791 + 30 * i + 1) >= 0 )
        {
          if ( *((char *) dword_256791 + 30 * i + 1) > 0 )
          {
            *((u8 *) dword_256791 + 30 * i + 1) -= v58[0];
            if ( *((char *) dword_256791 + 30 * i + 1) < 0 )
              *((u8 *) dword_256791 + 30 * i + 1) = 0;
          }
        }
        else
        {
          *((u8 *) dword_256791 + 30 * i + 1) += v58[0];
          if ( *((char *) dword_256791 + 30 * i + 1) > 0 )
            *((u8 *) dword_256791 + 30 * i + 1) = 0;
        }

        int tmp=(*(UA<i32> *)((char *) dword_25678D + 30 * i) >> 24) ; // / v57[0]; sanitizer crash
        tmp/=v57[0];

        if ( *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24 >= -(tmp) )
        {
//          a1 = v57[0];
          if ( *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24 > tmp )
          {
//            a1 = v57[0];
            *((u8 *) dword_256791 + 30 * i + 1) = tmp;
          }
        }
        else
        {
//          a1 = v57[0];
          *((u8 *) dword_256791 + 30 * i + 1) = -(tmp);
        }
        *((u8 *) dword_256791 + 30 * i + 1) += v56[0];
        if ( *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24 >= -32 )
        {
          if ( *((char *) dword_256791 + 30 * i + 1) > 32 )
            *((u8 *) dword_256791 + 30 * i + 1) = 32;
        }
        else
        {
          *((u8 *) dword_256791 + 30 * i + 1) = -32;
        }
        if ( level_no == 3 )
        {
          if ( *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24 >= -4 )
          {
            if ( *((char *) dword_256791 + 30 * i + 1) > 4 )
              *((u8 *) dword_256791 + 30 * i + 1) = 4;
          }
          else
          {
            *((u8 *) dword_256791 + 30 * i + 1) = -4;
          }
        }
      }
      v53 = (  (u32)(*(UA<i32> *)((char *) dword_256791 + 30 * i) >> 24) << 6) + *((u16 *) dword_256780 + 15 * i);
      if ( v53 >= 0 )
        *((u16 *) dword_256780 + 15 * i) = v53;
      else
        *((u16 *) dword_256780 + 15 * i) = 0;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      if ( !v54 ) //это условие выполняется!
      {
        *((u8 *) dword_256791 + 30 * i + 2) += *((u8 *) dword_256791 + 30 * i) * -LOBYTE(joysy[i]);

        int tmp=(*(UA<i32> *)((char *) dword_25678D + 30 * i) >> 24); // / v57[0]; sanitizer crash
        tmp/=v57[0];

        if ( *(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24 >= -(tmp) )
        {
//          a1 = v57[0];
          if ( *(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24 > tmp )
          {
//            a1 = v57[0];
            *((u8 *) dword_256791 + 30 * i + 2) = tmp;
          }
        }
        else
        {
//          a1 = v57[0];
          *((u8 *) dword_256791 + 30 * i + 2) = -(tmp);
        }
        *((u8 *) dword_256791 + 30 * i + 2) += v55[0];
        if ( *(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24 >= -32 )
        {
          if ( *((char *) dword_256791 + 30 * i + 2) > 32 )
            *((u8 *) dword_256791 + 30 * i + 2) = 32;
        }
        else
        {
          *((u8 *) dword_256791 + 30 * i + 2) = -32;
        }
      }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

      if ( level_no == 3 )
        *((u8 *) dword_256791 + 30 * i + 2) = -4;
    }
//--------------------------------------------------------------------------


    if ( myvx[i] )
    {
//      a1 = 2 * i;
//      *(UA<i16> *)((char *)vx + a1) = *(UA<i16> *)((char *)myvx + a1);
        *(UA<i16> *)((char *)vx + (2 * i)) = *(UA<i16> *)((char *)myvx + (2 * i));
    }
    else if ( (u16)word_25677C[15 * i] >= 0x7800u )
    {
      vx[i] = (u16)word_25677C[15 * i] > 0x8800u;
    }
    else
    {
      vx[i] = -1;
    }
    if ( *((u16 *) unk_25677E + 15 * i) > 0x2000u && *((char *) dword_256791 + 30 * i + 2) > 0 )
    {
      v4 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24;
      vy[i] = -(i16)((v4 - (__CFSHL__(v4 >> 31, 2) + 4 * (v4 >> 31))) >> 2) - 6;
      *((u16 *) unk_25677E + 15 * i) -= 1536;
    }
    else if ( *((u16 *) unk_25677E + 15 * i) < 0x8000u && *((char *) dword_256791 + 30 * i + 2) < 0 )
    {
      v5 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24;
      vy[i] = 6 - ((v5 - (__CFSHL__(v5 >> 31, 2) + 4 * (v5 >> 31))) >> 2);
      byte_25677F[30 * i] += 6;
    }
    else
    {
      v6 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24;
      vy[i] = -(i16)((v6 - (__CFSHL__(v6 >> 31, 2) + 4 * (v6 >> 31))) >> 2);
    }
    if ( (!flicker[i] || !level_start) && !game_over_flag[i] )
    {
      word_25677C[15 * i] += ( *((char *) dword_256791 + 30 * i + 1)  SHL6) - (vx[i]  SHL8); //shift fix
      v7 = *(UA<i32> *)((char *) dword_256780 + 30 * i) >> 16;
      v8 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
      v40 = (v8 - (__CFSHL__(v8 >> 31, 2) + 4 * (v8 >> 31))) >> 2;
      v9 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
      LOWORD(v9) = CPP_arctan((v9 - (__CFSHL__(v9 >> 31, 2) + 4 * (v9 >> 31))) >> 2, v40);
      v10 = abs(v7 - (u16)v9);
      v11 = *(UA<i32> *)((char *) dword_256780 + 30 * i) >> 16;
      v12 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
      v41 = (v12 - (__CFSHL__(v12 >> 31, 2) + 4 * (v12 >> 31))) >> 2;
      v13 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
      LOWORD(v13) = CPP_arctan((v13 - (__CFSHL__(v13 >> 31, 2) + 4 * (v13 >> 31))) >> 2, v41);
      if ( v10 <= abs(v11 - (u16)v13 + 2024) )
      {
        v14 = *(UA<i32> *)((char *) dword_256780 + 30 * i) >> 16;
        v15 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
        v42 = (v15 - (__CFSHL__(v15 >> 31, 2) + 4 * (v15 >> 31))) >> 2;
        v16 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
        LOWORD(v16) = CPP_arctan((v16 - (__CFSHL__(v16 >> 31, 2) + 4 * (v16 >> 31))) >> 2, v42);
        v17 = abs(v14 - (u16)v16);
        v18 = *(UA<i32> *)((char *) dword_256780 + 30 * i) >> 16;
        v19 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
        v43 = (v19 - (__CFSHL__(v19 >> 31, 2) + 4 * (v19 >> 31))) >> 2;
        v20 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
        LOWORD(v20) = CPP_arctan((v20 - (__CFSHL__(v20 >> 31, 2) + 4 * (v20 >> 31))) >> 2, v43);
        if ( v17 > abs(v18 - (u16)v20 - 2024) )
          *((u16 *) dword_256780 + 15 * i + 1) -= 2024;
      }
      else
      {
        *((u16 *) dword_256780 + 15 * i + 1) += 2024;
      }
      v21 = *(UA<i32> *)((char *) dword_256780 + 30 * i) >> 16;
      v22 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
      v44 = (v22 - (__CFSHL__(v22 >> 31, 2) + 4 * (v22 >> 31))) >> 2;
      v23 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
      if ( v21 >= (u16)CPP_arctan((v23 - (__CFSHL__(v23 >> 31, 2) + 4 * (v23 >> 31))) >> 2, v44) )
      {
        v29 = *(UA<i32> *)((char *) dword_256780 + 30 * i) >> 16;
        v30 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
        v47 = (v30 - (__CFSHL__(v30 >> 31, 2) + 4 * (v30 >> 31))) >> 2;
        v31 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
        if ( v29 > (u16)CPP_arctan((v31 - (__CFSHL__(v31 >> 31, 2) + 4 * (v31 >> 31))) >> 2, v47) )
        {
          *((u16 *) dword_256780 + 15 * i + 1) -= 72;
          v32 = *(UA<i32> *)((char *) dword_256780 + 30 * i) >> 16;
          v33 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
          v48 = (v33 - (__CFSHL__(v33 >> 31, 2) + 4 * (v33 >> 31))) >> 2;
          v34 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
          if ( v32 < (u16)CPP_arctan((v34 - (__CFSHL__(v34 >> 31, 2) + 4 * (v34 >> 31))) >> 2, v48) )
          {
            v35 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
            v49 = (v35 - (__CFSHL__(v35 >> 31, 2) + 4 * (v35 >> 31))) >> 2;
            v36 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
            LOWORD(v36) = CPP_arctan((v36 - (__CFSHL__(v36 >> 31, 2) + 4 * (v36 >> 31))) >> 2, v49);
            *((u16 *) dword_256780 + 15 * i + 1) = v36;
          }
        }
      }
      else
      {
        *((u16 *) dword_256780 + 15 * i + 1) += 72;
        v24 = *(UA<i32> *)((char *) dword_256780 + 30 * i) >> 16;
        v25 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
        v45 = (v25 - (__CFSHL__(v25 >> 31, 2) + 4 * (v25 >> 31))) >> 2;
        v26 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
        if ( v24 > (u16)CPP_arctan((v26 - (__CFSHL__(v26 >> 31, 2) + 4 * (v26 >> 31))) >> 2, v45) )
        {
          v27 = -(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
          v46 = (v27 - (__CFSHL__(v27 >> 31, 2) + 4 * (v27 >> 31))) >> 2;
          v28 = *(UA<i32> *)((char *) dword_25678D + 30 * i + 2) >> 24;
          LOWORD(v28) = CPP_arctan((v28 - (__CFSHL__(v28 >> 31, 2) + 4 * (v28 >> 31))) >> 2, v46);
          *((u16 *) dword_256780 + 15 * i + 1) = v28;
        }
      }
      *((i16 *) dword_256780 + 15 * i + 1) %= 2024;
//      a1 = 30 * i;
//      if ( *(UA<u16> *)((char *) dword_256780 + a1) )
        if ( *(UA<u16> *)((char *) dword_256780 + (30 * i)) )
        *((u16 *) dword_256784 + 15 * i) += 101;
      else
        *((u16 *) dword_256784 + 15 * i) = 0;
      if ( level_no != 3 )
      {
        if ( (xbuttons[i] & 0x10) != 0 )
        {
          if ( (xbuttons[i] & 0x20) == 0 )
            CPP_smart_bomb(/*(unsigned int *)a1, a2,*/ i);
        }
        else
        {
          CPP_add_bullet(/*a1, a2,*/ i);
        }
      }
    }
//    HIDWORD(v39) = 4;
//    LODWORD(v39) = i;
/*
    MY_PlaySample(
      (unsigned int *)a1,
      a2,
      v39,
      0x2AF8u,
      -2 - 0x7FFF * (u8)no_players - 2 * i,
      -4294967196i64,
      2u);
*/
    MY_PlaySample(/*(unsigned int *)a1, a2, v39*/ i , 4 , 0x2AF8, -2 - 0x7FFF * (u8)no_players - 2 * i, 0x64, 0xFFFFFFFF, 2);


    v37 = abs(*(UA<i32> *)((char *) dword_25678D + 30 * i + 3) >> 24);
    new_ship_pitch[i] = ((120 * v37 - (__CFSHL__((120 * v37) >> 31, 5) + 32 * ((120 * v37) >> 31))) >> 5) + 100;
    if ( new_ship_pitch[i] != current_ship_pitch[i] )
    {
      if ( (u8)new_ship_pitch[i] <= (u8)current_ship_pitch[i] )
      {
        if ( (u8)new_ship_pitch[i] < (u8)current_ship_pitch[i] )
          current_ship_pitch[i] -= 4;
      }
      else
      {
        current_ship_pitch[i] += 4;
      }
      MY_SetSamplePitch(i, 4, (u8)current_ship_pitch[i]);
    }
  }
  return result;
}

//#pragma GCC pop_options

char CPP_control_game(void) //FINAL
{
  int v2; // eax

  ascii = inkey_asckey[(u8)Inkey];

  CPP_read_digistick(/*ascii*/ ); //только присвоения

  joysx[0] = joyx; //?
  joysy[0] = joyy; //?

  LOBYTE(v2) = buttons;
  xbuttons[0] = buttons; //xbuttons = buttons;

  if ( Inkey == 68 )
  {
    quit_game = 1;
  }
  else if ( game_mode || fading == 2 )
  {
    if ( game_mode == 2 )
    {
      switch ( Inkey )
      {
        case 2:
          temp_no_players = 1;
          fading = 2;
          break;
        case 3:
          temp_no_players = 2;
          fading = 2;
          break;
        case 1:
          quit_game = 1;
          break;
      }
    }
  }
  else if ( byte_2B37D1 )
  {
    level_start = 0;
    CPP_game_over(0);
    LOBYTE(v2) = CPP_game_over(1u);
  }
  else if ( byte_2B3812 )
  {
    v2 = abs(turn - dword_22ED90);
    if ( v2 > 10 )
    {
      game_pause ^= 1u;
      LOBYTE(v2) = turn;
      dword_22ED90 = turn;
    }
  }
  else
  {
    if ( cheat_on )
    {
      if ( byte_2B37DD )
      {
        CPP_power_up(/*a1, a2,*/ 0);
        CPP_power_up(/*a1, a2,*/ 1u);
      }

      if ( byte_2B37E6 )
        ++byte_25677F[0];  // ++byte_25677F;  //не совсем уверен что верно

      if ( byte_2B37D2 )
        blk_collision = 1;

      if ( byte_2B37DA )
        ++the_score[0];

      if ( byte_2B37DB )
      {
        ++dword_256744;
      }
      else if ( byte_2B37D3 )
      {
        blk_collision = 0;
      }
      else if ( byte_2B3806 )
      {
        byte_2567B1 = 0;
        *(UA<u16> *)((char *) dword_256791 + 1) = 0;
        byte_2567B0 = 0;
      }
      v2 = abs(turn - dword_22ED90);
      if ( v2 > 10 )
      {
        LOBYTE(v2) = turn;
        dword_22ED90 = turn;
        if ( byte_2B37D7 )
        {
          bonus += 10;
        }
        else if ( byte_2B37D8 && !race_finished )
        {
          LOWORD(v2) = (u8)++laps[0] / 5;
          laps[0] = (u8)laps[0] % 5;
        }
        else if ( byte_2B37D9 && !race_finished )
        {
          LOWORD(v2) = (u8)++byte_256B3B / 5;
          byte_256B3B = (u8)byte_256B3B % 5;
        }
      }
    }
    if ( (u8)no_players <= 1u )
    {
      if ( byte_2B37E8 )
      {
        LOBYTE(v2) = 2 * no_players;
        word_2567EE[(u8)no_players] = -1;
      }
      else if ( byte_2B37E9 )
      {
        LOBYTE(v2) = 2 * no_players;
        word_2567EE[(u8)no_players] = 1;
      }
      if ( byte_2B37E0 )
      {
        LOBYTE(v2) = 2 * no_players;
        word_2567EA[(u8)no_players] = -1;
      }
      else if ( byte_2B37EE )
      {
        LOBYTE(v2) = 2 * no_players;
        word_2567EA[(u8)no_players] = 1;
      }
      if ( byte_2B3809 )
      {
        LOBYTE(v2) = no_players;
        byte_256B41[(u8)no_players] &= 0xEFu;
      }
      if ( byte_2B37EC )
      {
        LOBYTE(v2) = no_players;
        byte_256B41[(u8)no_players] &= 0xDFu;
      }
    }
    else
    {
      if ( byte_2B37E8 )
      {
        word_2567EE[(u8)no_players] = -1;
      }
      else if ( byte_2B37E9 )
      {
        word_2567EE[(u8)no_players] = 1;
      }
      else
      {
        word_2567EE[(u8)no_players] = 0;
      }
      if ( byte_2B37E0 )
      {
        word_2567EA[(u8)no_players] = -1;
      }
      else if ( byte_2B37EE )
      {
        word_2567EA[(u8)no_players] = 1;
      }
      else
      {
        word_2567EA[(u8)no_players] = 0;
      }

      if ( byte_2B3809 )
        byte_256B41[(u8)no_players] &= 0xEFu;
      else
        byte_256B41[(u8)no_players] |= 0x10u;

      LOBYTE(v2) = no_players;

      if ( byte_2B37EC )
        byte_256B41[(u8)no_players] &= 0xDFu;
      else
        byte_256B41[(u8)no_players] |= 0x20u;
    }
  }
  Inkey = 0;
  return v2;
}

int CPP_game_over(u8 a1) //FINAL
{
  int result; // eax

  *((u8 *) dword_256791 + 30 * a1 + 1) = 0;
  *((u8 *) dword_256791 + 30 * a1 + 2) = 0;

  result = a1;
  game_over_flag[a1] = 1;

  if ( level_no != 3 )
  {
    result = a1;
    flicker[a1] = 127;
  }
  if ( no_players == 1 && game_over_flag[0] || game_over_flag[0] && byte_256B39 )
    fading = 2;

  return result;
}

void CPP_read_digistick(void) //FINAL
{
  u16 v1; // bx
  u16 v2; // si
  int v3; // ecx
  u8 v4; // al
  i16 v5; // ax
  i16 v6; // ax

//запрещаем джойстик, но кое-какие присвоения отсюда возьмём
/*
  if ( word_1A5502 )
  {
    v1 = 0;
    v2 = 0;
    outp(0x201u, a1);
    v3 = 10000;
    _disable();
    while ( 1 )
    {
      v4 = inp(0x201u);
      if ( (v4 & 3) == 0 )
        break;
      if ( (v4 & 1) != 0 )
        ++v1;
      if ( (v4 & 2) != 0 )
        ++v2;
      if ( !--v3 )
      {
        _enable();
        word_1A5502 = 0;
        goto LABEL_19;
      }
    }
    _enable();
    buttons = v4;
    v5 = 0;
    if ( v1 >= (u16)word_1A5504 )
    {
      if ( v1 > (u16)word_1A5508 )
        v5 = 1;
    }
    else
    {
      v5 = -1;
    }
    joyx = v5;
    v6 = 0;
    if ( v2 >= (u16)word_1A5506 )
    {
      if ( v2 > (u16)word_1A550A )
        v6 = 1;
    }
    else
    {
      v6 = -1;
    }
    joyy = v6;
  }
  else
  {
LABEL_19:
*/
    joyx = 0;
    joyy = 0;
    buttons = -1;

// }
}

void CPP_setup_addresses(void) //FINAL
{
  int v0; // eax
  int v1; // [esp+0h] [ebp-8h] BYREF
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; (u16)i < 0x800u; ++i )
  {
    v0 = CPP_check_anim(i, (u16 *)&v1);

    *(UA<i32> *)((char *) anim_addresses + 6 * (u16)i) = v0;

    word_2314BC[3 * (u16)i] = v1;
  }
}

int CPP_check_anim(u16 a1, u16 *a2) //FINAL
{
  int v3; // [esp+0h] [ebp-18h]
  int *i; // [esp+8h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-Ch]
  u16 j; // [esp+10h] [ebp-8h]
  char v7; // [esp+14h] [ebp-4h]

  v5 = 0;
  v7 = 0;
  for ( i = (int *)&array_list[0]; *i != -1 && !v7; ++i ) //fix [0] pointer
  {
    v3 = *i;
    for ( j = 0; *(UA<i16> *)(v3 + 2 * j) >= 0 && !v7; ++j )
    {
      if ( *(UA<i16> *)(v3 + 2 * j) == a1 )
      {
        v7 = 1;
        *a2 = j;
        v5 = v3;
      }
    }
  }
  return v5;
}

int CPP_setup_high_scores(void) //FINAL
{
  u16 *v0; // eax
  int result; // eax
  u16 *v2; // eax
  u16 *v3; // edx
  u16 *v4; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+4h] [ebp-8h]
  u16 i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]
  int k; // [esp+8h] [ebp-4h]

  memset((char*)tube_graphics, 0, 0x10000u);

  CPP_setup_vecs(WScreen, 0, 320, 320, 200);

  CPP_set_scroll((int)(u16)word_25677C[0] >> 5);

  v5 = level;
  game_mode = 2;
  hiscore_ticks = 0;
  hi_look = (int)&hiscore_lookup;
  level_line[0] = 987;

  if ( bodge )
    ++level_line[0];

  lastscroll[0] = 1;
  scrollpos[0] = 0;
  scrollsave[0] = 0;
  no_players = 0;

  for ( i = 0; i < 0x306u; ++i )
  {
    v0 = (u16 *)v5;
    v5 += 2;
    *v0 = 0;
  }

  result = high_scores;
  v6 = high_scores;

  for ( j = 0; (u16)j < 0x1A0u; ++j )
  {
    v2 = (u16 *)v6;
    v6 += 2;
    v3 = (u16 *)v5;
    v5 += 2;
    *v3 = *v2;
    result = j;
  }

  for ( k = 0; (u16)k < 0x27Au; ++k )
  {
    v4 = (u16 *)v5;
    v5 += 2;
    *v4 = 0;
    result = k;
  }

  return result;
}

int CPP_set_scroll(int a1) //FINAL
{
  int result; // eax
  int v2; // [esp+0h] [ebp-18h]
  int v3; // [esp+4h] [ebp-14h]

  v3 = ((320 - vec_window_width) / 2 * sintable[a1]) >> 16;
  v2 = ((200 - vec_window_height) / 2 * -costable[a1]) >> 16;
  scroll_x = vec_window_width / 2 - v3;
  scroll_y = vec_window_height / 2 - v2;
  tube_scroll_x = v3 + (320 - vec_window_width) / 2;
  result = v2 + (200 - vec_window_height) / 2;
  tube_scroll_y = result;
  return result;
}

unsigned int CPP_load_game(void) //FINAL
{
  unsigned int result; // eax
  i16 v1; // ax
  u16 *v2; // edx
  char v3[252]; // [esp+0h] [ebp-108h] BYREF
  u16 *v4; // [esp+FCh] [ebp-Ch]
  u16 *v5; // [esp+100h] [ebp-8h]
  int i; // [esp+104h] [ebp-4h]

  strcpy((char*)v3,(char*)aHighScoresNNjo); //CLIB

  if ( tabgen )
  {
    v4 = (u16 *)high_scores;
    v5 = (u16 *)high_scores;
    for ( i = 0; ; ++i )
    {
      result = strlen((char*)v3); //CLIB

      if ( (u16)i >= result )
        break;

      if ( v3[(u16)i] == 47 && v3[(u16)i + 1] == 110 )
      {
        v5 += 32;
        v4 = v5;
        ++i;
      }
      else
      {
        v1 = (u8)v3[(u16)i] + 1952;
        v2 = v4++;
        *v2 = v1;
      }
    }
  }
  else
  {
    result = CPP_LoadFileAt(aDataHiscoreDat, (char *)high_scores);

    if ( result != 832 )
      file_error = 1;
  }
  return result;
}

int CPP_init_tube(void) //FINAL
{
  u8 i; // [esp+0h] [ebp-4h]

  CPP_setup_stuff();

  vec_mode = 0;
  for ( i = 0; i < (u8)no_players; ++i )
  {
    scrollpos[i] = 0;
    level_line[i] = 28;
    laps[i] = 0;
    myvx[i] = 0;
    game_over_flag[i] = 0;
    lastscroll[i] = 1;
    flicker[i] = 127;
  }

  CPP_clear_tube();

  CPP_setup_tube_graphics(level + 63744);

  if ( tabgen )
  {
    CPP_tunnel_table();
  }
  else if ( CPP_LoadFileAt(aDataTunnelDat, tunnelmap) != 0x20000 )
  {
    file_error = 1;
  }
  return CPP_find_distant();
}

int CPP_tunnel_table(void) //FINAL
{
  u8 *v0; // eax
  u16 *v1; // edx
  u16 *v2; // eax
  u8 *v3; // edx
  int result; // eax
  int v5; // [esp+0h] [ebp-5Ch] BYREF
  int v6; // [esp+4h] [ebp-58h]
  int v7; // [esp+18h] [ebp-44h] BYREF
  int v8; // [esp+1Ch] [ebp-40h]
  int v9; // [esp+30h] [ebp-2Ch] BYREF
  int v10; // [esp+34h] [ebp-28h]
  u16 *v11; // [esp+48h] [ebp-14h]
  int v12; // [esp+4Ch] [ebp-10h]
  int v13; // [esp+50h] [ebp-Ch]
  int i; // [esp+54h] [ebp-8h]
  int j; // [esp+58h] [ebp-4h]

  v13 = 36; //0x24
  v12 = 64; //0x40

  int V[6]; //хранит координаты вершин треугольника

  for ( i = 0; i < 256 ; ++i )
  {
/*
    v5 =       8 * sintable[8 * (u8)(i + 1)] / (v12 * v13) + 160;
    v6 = 100 - 5 * costable[8 * (u8)(i + 1)] / (v12 * v13);
    v7 =       8 * sintable[8 * i] / (v12 * v13) + 160;
    v8 = 100 - 5 * costable[8 * i] / (v12 * v13);
    v9 = 160;
    v10 = 100;
    MEMORY[0x40000A](&v9, &v7, &v5);
*/
    vec_colour = i;

    V[0] = 160 + ((8 * sintable[8 * (u8)(i + 1)]) / (v12 * v13));
    V[1] = 100 - ((5 * costable[8 * (u8)(i + 1)]) / (v12 * v13));

    V[2] = 160 + ((8 * sintable[8 * i]) / (v12 * v13));
    V[3] = 100 - ((5 * costable[8 * i]) / (v12 * v13));

    V[4] = 160; //X
    V[5] = 100; //Y

    CPP_trig((int*)&V[4],(int*)&V[2],(int*)&V[0]); //рисует треугольник: 3 вершины - X,Y передаются попарно(структура?)
  }

  ToScreen(); //qmemcpy((void *)0xA0000, (const void *)WScreen, 0xFA00u);

  v11 = (u16 *) tunnelmap;
  plotat = WScreen;
  for ( i = 0; i < 0x10000; ++i )
  {
    v0 = (u8 *)plotat++;
    LOBYTE(v0) = *v0;
    v1 = v11++;
    *v1 = 255 - (u8)((int)v0); //??? mingw todo
  }

  for ( j = 0; j < 256; ++j )
  {
    vec_colour = j;
    for ( i = 0; i < 256; ++i )
    {
/*
      v7 =       8 * sintable[8 * i]                        / ((v13 + j) * v12) + 160;
      v8 = 100 - 5 * costable[8 * i]                        / ((v13 + j) * v12);
      v5 = 8       * sintable[8 * (u8)(i + 1)] / (v12 * (v13 + j)) + 160;
      v6 = 100 - 5 * costable[8 * (u8)(i + 1)] / ((v13 + j) * v12);
*/

      V[0] = 160 + 8 * sintable[8 * (u8)(i + 1)] / ((v13 + j) * v12);
      V[1] = 100 - 5 * costable[8 * (u8)(i + 1)] / ((v13 + j) * v12);

      V[2] = 160 + 8 * sintable[8 * i]                        / ((v13 + j) * v12);
      V[3] = 100 - 5 * costable[8 * i]                        / ((v13 + j) * v12);

      V[4] = 160;
      V[5] = 100;

      CPP_trig((int*)&V[4],(int*)&V[2],(int*)&V[0]); //рисует треугольник: 3 вершины - X,Y передаются попарно(структура?)
    }
  }

  ToScreen(); //qmemcpy((void *)0xA0000, (const void *)WScreen, 0xFA00u);

  v11 = (u16 *) tunnelmap;
  plotat = WScreen;

  for ( i = 0; i < 0x10000; ++i )
  {
    v2 = v11++;
    v3 = (u8 *)plotat++;
    *v2 += (255 - *v3) << 8;
  }

  result = CPP_SaveFileAt((int)aDataTunnelDat, (int) tunnelmap, 0x20000);

  if ( result != 0x20000 )
    file_error = 1;

  return result;
}

int CPP_find_distant(void) //FINAL
{
  u16 *v0; // eax
  u16 v1; // ax
  int result; // eax
  u16 *v3; // eax
  char *v4; // edx
  int v5; // [esp+0h] [ebp-24h]
  char *v6; // [esp+0h] [ebp-24h]
  int v7; // [esp+4h] [ebp-20h]
  u16 v8; // [esp+8h] [ebp-1Ch]
  u16 v9; // [esp+Ch] [ebp-18h]
  u16 v10; // [esp+10h] [ebp-14h]
  u16 i; // [esp+14h] [ebp-10h]
  int k; // [esp+14h] [ebp-10h]
  u16 j; // [esp+18h] [ebp-Ch]
  u16 l; // [esp+18h] [ebp-Ch]
  u16 v15; // [esp+1Ch] [ebp-8h]
  char v16; // [esp+20h] [ebp-4h]

  v10 = 319;
  v15 = 0;
  v9 = 199;
  v8 = 0;
  v5 = (int)tunnelmap; //2320192; //0x236740 HARDCODE !!!
  for ( i = 0; i < 0xC8u; ++i )
  {
    for ( j = 0; j < 0x140u; ++j )
    {
      v0 = (u16 *)v5;
      v5 += 2;
      if ( (int)*v0 >> 8 < 128 )
      {
        if ( j < v10 )
          v10 = j;
        if ( j > v15 )
          v15 = j;
        if ( i < v9 )
          v9 = i;
        if ( i > v8 )
          v8 = i;
      }
    }
  }
  v1 = v15 - v10 + 3;
  LOBYTE(v1) = v1 & 0xFC;
  fade_width = v1;
  fade_height = v8 - v9;
  fade_out = (int)malloc(v1 * (u16)(v8 - v9));
  fade_offset = 320 * v9 + v10;
  v6 = (char *) tunnelmap + 640 * v9 + 2 * v10;
  v7 = fade_out;

  for ( k = 0; ; ++k )
  {
    result = k;
    if ( (u16)k >= (u16)fade_height )
      break;
    for ( l = 0; l < (u16)fade_width; ++l )
    {
      v3 = (u16 *)v6;
      v6 += 2;
      v16 = (*v3 + 768) >> 10;
      if ( (u8)v16 > 0x20u )
        v16 = 32;
      v4 = (char *)v7++;
      *v4 = v16;
    }
    v6 += 2 * (320 - (u16)fade_width);
  }
  return result;
}

char CPP_setup_tube_graphics(int a1) //FINAL
{
  int v1; // eax
  u16 *v2; // eax
  u16 v3; // ax
  u8 *v4; // ebx
  int v6; // [esp+0h] [ebp-24h]
  unsigned int v7; // [esp+4h] [ebp-20h]
  int v8; // [esp+8h] [ebp-1Ch]
  int v9; // [esp+Ch] [ebp-18h]
  u8 k; // [esp+14h] [ebp-10h]
  u8 l; // [esp+18h] [ebp-Ch]
  u8 j; // [esp+1Ch] [ebp-8h]
  u8 i; // [esp+20h] [ebp-4h]

  LOBYTE(v1) = a1;
  v8 = a1;
  for ( i = 0; i < 0x20u; ++i )
  {
    for ( j = 0; j < 0x20u; ++j )
    {
      v2 = (u16 *)v8;
      v8 += 2;
      v3 = *v2;
      if ( level + 0x10000 == v8 )
        v8 = level;
      v9 = (v3 << 6) + block_data;
      for ( k = 0; k < 8u; ++k )
      {
        for ( l = 0; l < 8u; ++l )
        {
          v4 = (u8 *)v9++;
          *(u8 *)((i << 11) + 8 * j + (k << 8) + l + tube_graphics) = *v4;
        }
      }
    }
    LOBYTE(v1) = i;
  }
  v7 = 0;
  v6 = 0x10000;
  while ( v7 < 0x10000 )
  {
    *(UA<u32> *)(tube_graphics + v6) = *(UA<u32> *)(tube_graphics + v7);
    v1 = *(UA<u32> *)(tube_graphics + v7 + 4);
    *(UA<u32> *)(tube_graphics + v6 + 4) = v1;
    v7 += 8;
    v6 += 8;
  }
  return v1;
}

int CPP_clear_tube(void) //FINAL
{
  int result; // eax

  result = 0;
  memset((char *)tube_graphics, 0, 0x10000u); //CLIB
  return result;
}

int CPP_setup_stuff(void) //FINAL
{
  int result; // eax
  u16 i; // [esp+Ch] [ebp-Ch]
  int v2; // [esp+10h] [ebp-8h]
  int v3; // [esp+10h] [ebp-8h]
  u16 v4; // [esp+14h] [ebp-4h]
  u16 v5; // [esp+14h] [ebp-4h]

  if ( tabgen )
  {
    v4 = 0;
    v2 = 256;

    while ( v4 < 0x20u )
    {
      CPP_make_fade_table((u8 *)palette, (u8 *)&tables_start[256 * v4++], 0, 0, 0, v2, v2, v2);
      v2 -= 8;
    }
    v5 = 32;
    v3 = 0;

    while ( v5 < 0x40u )
    {
      CPP_make_fade_table((u8 *)palette, (u8 *)&tables_start[256 * v5++], 63, 63, 63, v3, v3, v3);
      v3 += 6;
    }

    for ( i = 0; i < 0x100u; ++i )
      CPP_make_fade_table(
        (u8 *)palette,
        (u8 *)&ghost[256 * i],
        *(u8 *)(3 * i + palette),
        *(u8 *)(3 * i + palette + 1),
        *(u8 *)(3 * i + palette + 2),
        85,
        85,
        85);

    result = CPP_SaveFileAt((int)aDataTablesDat, (int)tables_start, 82176);

    if ( result != 82176 )
      file_error = 1;
  }
  else
  {
    result = CPP_LoadFileAt(aDataTablesDat, tables_start);

    if ( result != 82176 )
      file_error = 1;
  }
  return result;
}

int CPP_SaveFileAt(int a1, int a2, int a3) //FINAL
{
  int result; // eax
  int v4; // ebx
  int v5; // esi

  result = CPP_MyOpen(a1, 546);

  v4 = result;
  if ( result != 0 /*-1*/ )
  {
    v5 = CPP_MyWrite(result, a2, a3);
    CPP_MyClose(v4);
    result = v5;
  }
  return result;
}

int CPP_MyWrite(int a1, int a2, int a3) //FINAL
{
 return fwrite((void*)a2,1,a3,(FILE*)a1);
//return write(a1, (void*)a2, a3); //CLIB
}

void CPP_make_fade_table(u8 *A2, u8 *A3, signed char a4, signed char a5, signed char a6, short a7, short a8, short a9) //FINAL
{
    struct s0
    {
     signed char f0;
     signed char f1;
     signed char f2;
    };

    struct s0* a2=(struct s0*)A2;
    signed char* a3=(signed char*)A3;

    struct s0* esi10;
    signed char* edi11;
    short v12;
    short ax13;
    signed char bl14;
    short ax15;
    signed char bh16;
    short ax17;
    signed char cl18;
    struct s0* v19;
    struct s0* esi20;
    short v21;
    signed char ch22;
    signed char al23;
    short ax24;
    signed char al25;
    short ax26;
    signed char al27;
    short dx28;
    signed char v29;

    esi10 = a2;
    edi11 = a3;
    v12 = 0x100;
    do {
        ax13 = (short)((signed char)(a4 - esi10->f0) * a7);
        bl14 = (signed char)(esi10->f0 + *(signed char*)((int)(&ax13) + 1));
        ax15 = (short)((signed char)(a5 - esi10->f1) * a8);
        bh16 = (signed char)(esi10->f1 + *(signed char*)((int)(&ax15) + 1));
        ax17 = (short)((signed char)(a6 - esi10->f2) * a9);
        cl18 = (signed char)(esi10->f2 + *(signed char*)((int)(&ax17) + 1));
        v19 = esi10;
        esi20 = a2;
        v21 = 0x7fff;
        ch22 = 0;
        do {
            al23 = (signed char)(esi20->f0 - bl14);
            ax24 = (short)(al23 * al23);
            al25 = (signed char)(esi20->f1 - bh16);
            ax26 = (short)(al25 * al25);
            al27 = (signed char)(esi20->f2 - cl18);
            dx28 = (short)((short)((short)(ax24 + ax24) + (short)(ax26 + ax26)) + (short)(al27 * al27));
            if (dx28 < v21) {
                v29 = ch22;
                v21 = dx28;
            }
            ++esi20;
            ch22 = (signed char)(ch22 + 1);
        } while (ch22);
        *edi11 = v29;
        ++edi11;
        esi10 = v19 + 1;
        v12 = (short)(v12 - 1);
    } while (v12);
    return;
}

//------------------

void CPP_LoadAllData(int a2) //FINAL
{
  int v2; // ebx
  i16 v3; // si
  int v4; // ebx
  i16 v5; // ax
  char v7[100]; // [esp+0h] [ebp-64h] BYREF

  CPP_SetupMemory(/*a2, a1*/ );

  v2 = a2;
  v3 = 0;
  if ( *(UA<u32> *)(a2 + 28) )
  {
    do
    {
      CPP_FreeData(v2);
      v2 += 44;
    }
    while ( *(UA<u32> *)(v2 + 28) );
    v4 = a2;
  }
  else
  {
    v4 = a2;
  }

  while ( *(UA<u32> *)(v4 + 28) )
  {
    v5 = CPP_LoadData(/*a2 , v3,*/ v4);
    if ( v5 >= 0 )
    {
      if ( v5 )
        goto LABEL_10;
      printf("ERROR: File %s.\n", (char*)v4);
    }
    else
    {
      printf("ERROR: Allocation %s.\n", (char*)v4);
    }
    printf("Press return to continue\n");
    ++v3;

    getch(); //gets(v7);

LABEL_10:
    v4 += 44;
  }

//  return v3;
}

void CPP_load_all_tmaps(void) //FINAL
{
//  unsigned int result; // eax
//  char v3[28]; // [esp+0h] [ebp-34h] BYREF

  char v3[28+16]={0}; // [esp+0h] [ebp-34h] BYREF

//  int *v4; // [esp+1Ch] [ebp-18h]
//  int v5; // [esp+20h] [ebp-14h]
//  int v6; // [esp+24h] [ebp-10h]
//  i16 v7; // [esp+28h] [ebp-Ch]
//  i16 v8; // [esp+2Ah] [ebp-Ah]
  unsigned int v9; // [esp+2Ch] [ebp-8h]
  int v10; // [esp+30h] [ebp-4h]

  v9 = 0;
  do
  {
      sprintf((char*)v3,(char*)aDataTex02dDat, v9);

//    v4 = &tmaps[v9];
//    v5 = 0;
//    v6 = 0;
//    v7 = 0;
//    v8 = 0;

   u32 esp=(u32)v3;
   *(u32*)(esp+0x1C)=(u32)&tmaps[v9];
   *(u32*)(esp+0x20)=0;
   *(u32*)(esp+0x24)=0;
   *(u16*)(esp+0x28)=0;
   *(u16*)(esp+0x2A)=0;

    v10 = CPP_LoadData(/*a1, a2, */ (int)v3);
    ++v9;
  }
  while ( (i16)v10 > 0 && v9 < 0x10 );

//  result = v9 - 1;
  no_tmaps = v9 - 1;

//  return result;
}

void CPP_load_all_3d_files(void) //FINAL
{
  int v0; // eax
  int i; // [esp+0h] [ebp-14h]
  unsigned int v3; // [esp+4h] [ebp-10h]
  u32 *v4; // [esp+8h] [ebp-Ch]
  unsigned int v5; // [esp+Ch] [ebp-8h]
  u16 v6; // [esp+10h] [ebp-4h]
  i16 v7; // [esp+10h] [ebp-4h]

  memset(object3ds, 0, 0x640 /*sizeof(object3ds)*/ );
  memset(point3ds, 0, 0x23280 /*120000*/ );
  memset(face3ds, 0, 0x249F0 /*sizeof(face3ds)*/ );

  if ( CPP_LoadFileAt(aData3dobsDat, object3ds) != -1 )
    no_object3ds = (unsigned int)CPP_RncFileLength((int)aData3dobsDat) >> 4;

  if ( CPP_LoadFileAt(aData3dpointsDa, point3ds) != -1 )
    no_point3ds = CPP_RncFileLength((int)aData3dpointsDa) / 0xCu;

  v0 = CPP_LoadFileAt(aData3dfacesDat, face3ds);

  if ( v0 != -1 )
  {
    v0 = CPP_RncFileLength((int)aData3dfacesDat) / 0xFu;
    no_face3ds = v0;
  }
  if ( no_object3ds )
  {
    selected_object = 65432;
    v5 = 0;
    v6 = 0;

//  for ( i = 2602400; ; i += 16 ) //HARDCODE!!! 2602400 = 0x27B5A0 => object3ds
    for ( i = (int)object3ds; ; i += 16 )
    {
      LOWORD(v0) = v6;
      if ( v6 == no_object3ds )
        break;
      if ( *(UA<u32> *)(i + 8) )
      {
        *(UA<u32> *)(i + 8) = (u32)&point3ds[*(UA<u32> *)(i + 8) - 1];
        if ( *(UA<u32> *)(i + 8) > v5 )
        {
          v5 = *(UA<u32> *)(i + 8);
          selected_object = v6;
        }
      }
      if ( *(UA<u32> *)(i + 12) )
        *(UA<u32> *)(i + 12) = (u32)&face3ds[*(UA<u32> *)(i + 12) - 1];
      ++v6;
    }
  }
  v7 = 256;
  v4 = sts;
  while ( v7 )
  {
    seed = (int)(9377 * (long long)seed + 9439); //fix
    v3 = seed % 0xFFu;
    *v4 = ((int)(160 * (seed % 0xFFu)) >> 8) + 160;
    v4[1] = ((int)(100 * v3) >> 8) + 100;
    v4 += 2;
    LOWORD(v0) = v7--;
  }

 // return v0;
}

void CPP_setup_host(void)
{
//  int v2; // eax
//  int result; // eax

//  CPP_FadePalette256(0, 0x10u, 0); //гашение DOS'овской консоли - здесь это не нужно

  ScreenMode = 1;

  /*v2 = */ CPP_SetupScreenMCGA((u8 *)WScreen);

//  CPP_OpenIKeyboard(/*v2, a2*/ );

//  result = 320;

  CPP_setup_vecs(WScreen, 0, 320, 320, 200);

//  return result;
}

void /*interrupt far*/ CPP_KInt(void) //SDL2
{
 SDL_Event Event;
 int sdlk;

 u8 index=0;

 while(SDL_PollEvent(&Event))
 {
  switch(Event.type)
  {
   case SDL_QUIT:
    quit_game=1;
   break;

   case SDL_KEYDOWN:
/*
          if(Event.key.keysym.sym==SDLK_1     )index= 2; //one player
     else if(Event.key.keysym.sym==SDLK_2     )index= 3; //two players
     else if(Event.key.keysym.sym==SDLK_ESCAPE)index= 1; //abort game, exit
     else if(Event.key.keysym.sym==SDLK_q     )index=16; //up
     else if(Event.key.keysym.sym==SDLK_a     )index=30; //down
     else if(Event.key.keysym.sym==SDLK_o     )index=24; //left
     else if(Event.key.keysym.sym==SDLK_p     )index=25; //right
     else if(Event.key.keysym.sym==SDLK_SPACE )index=57; //fire
     else if(Event.key.keysym.sym==SDLK_RETURN)index=28; //bomb
*/
     sdlk=Event.key.keysym.scancode;
     if((sdlk>=4)&&(sdlk<=44))index=in_al_60h[sdlk-4];

     KeyOn[index]=1;
     Inkey=index;
   break;

   case SDL_KEYUP:
/*
          if(Event.key.keysym.sym==SDLK_1     )index= 2; //one player
     else if(Event.key.keysym.sym==SDLK_2     )index= 3; //two players
     else if(Event.key.keysym.sym==SDLK_ESCAPE)index= 1; //abort game, exit
     else if(Event.key.keysym.sym==SDLK_q     )index=16; //up
     else if(Event.key.keysym.sym==SDLK_a     )index=30; //down
     else if(Event.key.keysym.sym==SDLK_o     )index=24; //left
     else if(Event.key.keysym.sym==SDLK_p     )index=25; //right
     else if(Event.key.keysym.sym==SDLK_SPACE )index=57; //fire
     else if(Event.key.keysym.sym==SDLK_RETURN)index=28; //bomb
*/
     sdlk=Event.key.keysym.scancode;
     if((sdlk>=4)&&(sdlk<=44))index=in_al_60h[sdlk-4];

     KeyOn[index]=0;
     Inkey=0x80;
   break;
  }
 }

#if 0

int index=0;

Inkey=inp(0x60);

if(oinkey!=0x0E0)goto loc_1FF7EB;
if(Inkey==0x2A)goto loc_1FF7D7;
if(Inkey!=0xAA)goto loc_1FF7EB;

loc_1FF7D7:

oinkey=Inkey;
Inkey=0x80;

goto loc_1FF82F;

loc_1FF7EB:

oinkey=Inkey;
             
index=Inkey&0x7F;

// Вторая раскладка игры: U,D,L,R,Ctrl,Alt ---------
/*
if(index==72)index=16; //Up
if(index==80)index=30; //Down
if(index==75)index=24; //Left
if(index==77)index=25; //Right
if(index==29)index=57; //Fire
if(index==56)index=28; //Bomb
*/
//--------------------------------------------------

if((unsigned)Inkey<=0x7F)goto loc_1FF812;

KeyOn[index]=0;

goto loc_1FF81C;

loc_1FF812:

KeyOn[index]=1;

loc_1FF81C:

if(index==0x2A)goto loc_1FF828;
if(index!=0x36)goto loc_1FF82F;

loc_1FF828:

Inkey=0x80;

loc_1FF82F:

Shift=0;

if(byte_2B37FA!=0)goto loc_1FF84A;
if(byte_2B3806==0)goto loc_1FF851;

loc_1FF84A:

Shift=1;

loc_1FF851:

char a=inp(0x61);
char b=a;
a|=0x80;
outp(0x61,a);
outp(0x61,b);

if(Inkey>0x80)goto loc_1FF87D;
if(IInkey!=0)goto loc_1FF87D;

IInkey=Inkey;

loc_1FF87D:

//if(debug_keyboard==0)goto loc_1FF89E;

/*
 xor     eax, eax
 mov     ax, word_2B3ECA
 push    eax

 mov     ebx, OldInt
 push    ebx

 call    near ptr _chain_intr
 add     esp, 8
*/

//loc_1FF89E:

outp(0x20,0x20); //EOI

#endif

}

#if 0
void CPP_OpenIKeyboard() //not need for Win32
{
  i16 i; // ax
//  int v3; // eax
  int A2;

  for ( i = 0; i < 128; ++i )
  {
    A2 = i;
    *(A2 + KeyOn) = 0; // *(a2 + 2832336) = 0; //HARDCODED !!! 002B37D0 KeyOn
  }

//  v3 = dos_getvect(9);
//  OldInt = v3;

  word_2B3ECA = A2;

  OldInt=_dos_getvect(9);

  _dos_setvect(9,CPP_KInt);
}
#endif

char CPP_FindColor(u8 *a1, u8 a2, u8 a3, u8 a4) //FINAL
{
  char v4; // cl
  i16 v6; // dx
  i16 v7; // si
  i16 i; // dx
  i16 v9; // di
  i16 v11; // [esp+4h] [ebp-8h]
  u16 v12; // [esp+8h] [ebp-4h]

  if ( (ScreenMode & 6) != 0 )
    v6 = 16;
  else
    v6 = 256;

  v7 = 9999;
  v12 = v6;
  for ( i = 0; i < (int)v12; ++i )
  {
    v11 = (a2 - *a1) * (a2 - *a1) + (a3 - a1[1]) * (a3 - a1[1]);
    v9 = a4 - a1[2];
    if ( (i16)(v11 + v9 * v9) < v7 )
    {
      v7 = v11 + v9 * v9;
      v4 = i;
    }
    a1 += 3;
  }
  return v4;
}

void CPP_InitMusic(void)
{
 MY_OpenMusic(0);

#if 0
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  char v6; // [esp+0h] [ebp-6h] BYREF
  char v7[32]; // [esp+64h] [ebp+5Eh] BYREF
  char v8; // [esp+84h] [ebp+7Eh] BYREF

  if ( MusicAble )
  {

/*
    v3 = getenv(aBfMusic);
    if ( v3 )
    {
      sscanf(v3, "%s %x",  musicboard, &MusicBaseAddress);
    }
    else
    {
*/
	//MUSIC = ADLIB 388 0 0

	MusicBaseAddress=0x388;
	musicboard[0]='A';
	musicboard[1]='D';
	musicboard[2]='L';
	musicboard[3]='I';
	musicboard[4]='B';
	musicboard[5]=0;

/*
      sprintf(v7, "%s%s", SoundInfoDirectory, SoundInfoFile); //конфиг в файле SNDSETUP.INF
      v4 = fopen(v7, &unk_21F340);
      if ( v4 )
      {
        fscanf(v4, "%s = %s %x %d %d", &v6, &v6, &v8, &v8, &v8);
        fscanf(v4, "%s = %s %x", &v6,  musicboard, &MusicBaseAddress);
        fclose(v4);
      }
      else
      {
        sprintf( musicboard, aNone);
      }
    }
    if ( !stricmp( musicboard, aNone) )
    {
      MusicAble = 0;
      MusicActive = 0;
    }
*/

    if ( MusicAble )
    {

      v5 = CPP_FindMusicType((int)music_table); //ADLIB

      //if ( v5 <= -1 ) while(1); //проверка

      if ( v5 <= -1 )
      {
        MusicAble = 0;
        MusicActive = 0;
      }
      else
      {
        OpenMusic(/*a1, a2, a3,*/ v5);
      }
    }
  }
#endif
}

void CPP_InitSound(void)
{
 MY_OpenSound();

#if 0

  int v3; // eax
  int v4; // ebx
  char v5; // [esp+0h] [ebp-84h] BYREF
  char v6[32]; // [esp+64h] [ebp-20h] BYREF

  if ( SoundAble )
  {

/*
    v3 = getenv(aBfSound);
    if ( v3 )
    {
      sscanf(v3, "%s %x %d %d",  soundboard, &BaseAddress, &IRQ, &DMA);
    }
    else
    {
      sprintf(v6, "%s%s", SoundInfoDirectory, SoundInfoFile);
      v4 = fopen(v6, &unk_21F38C);
      if ( v4 )
      {
        fscanf(v4, "%s = %s %x %d %d", &v5,  soundboard, &BaseAddress, &IRQ, &DMA);
        fclose(v4);
      }
      else
      {
        sprintf( soundboard, aNone_0);
      }
    }
    if ( !stricmp( soundboard, aNone_0) )
    {
      SoundAble = 0;
      SoundActive = 0;
    }
*/
     //SOUND = SBLAST 220 5 1

     BaseAddress=0x220;
     IRQ=5;
     DMA=1;
     soundboard[0]='S';
     soundboard[1]='B';
     soundboard[2]='L';
     soundboard[3]='A';
     soundboard[4]='S';
     soundboard[5]='T';
     soundboard[6]=0;

    if ( SoundAble )
      OpenSound(/*a1, a2, a3*/);
  }
#endif

}

void CPP_calibrate_digistick(void) //FINAL
{
 word_1A5502 = 0; //джойстик запрещён

/*
  u16 v1; // bx
  u16 v2; // si
  int v3; // ecx
  u8 v4; // al

  v1 = 0;
  v2 = 0;
  outp(0x201u, a1);
  v3 = 10000;
  _disable();
  while ( 1 )
  {
    v4 = inp(0x201u);
    if ( (v4 & 3) == 0 )
      break;
    if ( (v4 & 1) != 0 )
      ++v1;
    if ( (v4 & 2) != 0 )
      ++v2;
    if ( !--v3 )
    {
      _enable();
      word_1A5502 = 0;
      return a1;
    }
  }
  _enable();
  word_1A5502 = 1;
  word_1A5504 = v1 >> 1;
  word_1A5508 = v1 + (v1 >> 1);
  word_1A5506 = v2 >> 1;
  word_1A550A = v2 + (v2 >> 1);
  return a1;
*/
}

void CPP_setup_a_sprite(unsigned int a1, unsigned int a2, unsigned int a3) //FINAL
{
  unsigned int result; // eax

  while ( 1 )
  {
    result = a1;

    if ( a1 >= a2 )
      break;

    if ( ScreenMode && ((u16)ScreenMode <= 1u || ScreenMode == 16) ) // ScreenMode = 1
    {
      *(u8 *)(a1 + 4) *= 2;
      *(u8 *)(a1 + 5) *= 2;
    }

    if ( *(UA<u32> *)a1 < a3 )
      *(UA<u32> *)a1 += a3;

    a1 += 6;
  }
//  return result;
}

void CPP_fill_stack(void) //???
{
/*
 _asm
 {
  mov     eax, esp
  and     esp, 0xFFFFFFFC

  loc_2166F0:

  pushd   0x1BAD4BED
  cmp     esp, _STACKLOW
  jg      short loc_2166F0

  mov     esp, eax
  retn
 }
*/
}

int CPP_MyAlloc(int a2) //FINAL
{
  UA<i32> *v2; // eax
  unsigned int v3; // ecx
  UA<i32> *v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // edx

  CPP_SetupMemory(/*a1, a2*/);

  v2 = (UA<i32>*)&MemoryArenas;
  v3 = -1;
  v5 = a2 + 3;
  v4 = 0;
  LOWORD(v5) = (a2 + 3) & 0xFFFC;

  while ( v2 )
  {
    v6 = v2[1];
    if ( v5 <= v6 && v3 > v6 && !*((u8 *)v2 + 16) )
    {

//      a1 = *((u8 *)v2 + 17);

      if ( !dword_2B3F64[3 * *((u8 *)v2 + 17)] )
      {
        v4 = v2;
        v3 = v2[1];
      }
    }
    v2 = (UA<i32>*)(i32)v2[2];
  }

  if ( !v4 || !CPP_split_arena((int)v4, v5) )
    return CPP_MyLowAlloc(/*a1,*/ v5);

  CPP_CheckMemory();

  memset((char*)(i32)*v4, 0, v5);

  return *v4;
}

/*
int CPP_compare(const void *a1, const void *a2)
{
  return *(UA<u32> *)(((int)a1) + 4);
}
*/

/*
int CPP_compare(int a1) //FINAL
{
  return *(UA<u32> *)(a1 + 4);
}
*/

#if 0
void CPP_SetupMemory(void)
{
 i64 v2; // kr00_8
  i64 v3; // rax
  int v4; // ebx
  int i; // ebx
  signed int v6; // ebx
  int v7; // esi
  unsigned int v8; // eax
  int v9; // edx
  int v10; // edi
  int v11; // eax
  int j; // ebx
  int v13; // eax
  int l; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int m; // ebx
  int v20; // eax
  int v21; // eax
  int *v22; // [esp-Ch] [ebp-30h]
  char *v23; // [esp-Ch] [ebp-30h]
  int v24; // [esp+0h] [ebp-24h] BYREF
  int v25[3]; // [esp+4h] [ebp-20h] BYREF
  int v26; // [esp+10h] [ebp-14h]
  int v27; // [esp+14h] [ebp-10h]
  int k; // [esp+18h] [ebp-Ch]
  int v29; // [esp+1Ch] [ebp-8h]
  int v30; // [esp+20h] [ebp-4h]

 u8 DUP[0x100];
 u8 *StackFrame=(u8*)DUP;
 u64 r64;
 u32 t;

 u32 sf18,sf24,sf20;
 u32 sf4,sf8;        //селекторы SOS
 u32 sf1C,sf14;

 if(dword_2B3F68[0])return;

// r64=sosAllocateFarMem(0xF000,(int)&sf24);
// sf18=r64;
// sf8=*((u32*)&r64+1);

// r64=sosAllocateFarMem(0xA000,(int)&sf20);
// sf1C=r64;
// sf4=*((u32*)&r64+1);

 sf14=CPP_dos_alloc(0xFA00);

 if(sf14<256)
 {
  do memset((char*)&MemoryBlocks[3*i++],0,12);
  while(i<256);
 }

 for(i=0;i<256;++i)memset((char*)&MemoryArenas+18*i,0,18);

/*
 s32 c=0x10000;
 u32 s=0;
 u32 a,d,D;

 loc_202958:

 a=CPP_dos_alloc(c);
 c=a;
 d=a;

 if(a==0)goto loc_20299A;

 D=d&0xFFFF;
 a=s*3;
 d>>=0x10;
 D<<=4;

 dword_228F68[a]=c;
 dword_228F64[a]=d;
 MemoryBlocks[a]=D;

 s++;
 c+=0x400;

 loc_20299A:

 c-=0x400;
 if(c>0x400)goto loc_202958;
*/
    v6 = 0x10000;
    v7 = 0;

    while ( v6 >= 1024 )
    {
      v8 = CPP_dos_alloc(v6);
      if ( v8 )
      {
        v9 = (u16)v8;
        v10 = HIWORD(v8);
        v11 = 3 * v7;
        dword_2B3F68[v11] = v6;
        ++v7;
        dword_2B3F64[v11] = v10;
        v6 += 1024;
        MemoryBlocks[v11] = 16 * v9;
      }
      v6 -= 1024;
    }

    for ( j = 0x1000000; j >= 4096; j -= 4096 )
    {
      v13 = (int)malloc(j); //CLIB
      MemoryBlocks[3 * v7] = v13;
      if ( v13 )
      {
        for ( k = 4096; k > 0; k -= 16 )
        {
          v27 = j + k;
          if ( _expand((void*)MemoryBlocks[3 * v7], j + k) ) //CLIB
          {
            dword_2B3F68[3 * v7] = v27;
            dword_2B3F64[3 * v7] = 0;
            break;
          }
        }
        j += 4096;
        ++v7;
      }
    }

    for ( l = 4096; l >= 16; l -= 16 )
    {
      v15 = (int)malloc(l);  //CLIB
      v16 = 12 * v7;
      MemoryBlocks[3 * v7] = v15;
      if ( v15 )
      {
        ++v7;
//        *(UA<u32> *)(v16 + 2834280) = l; //2B3F68 HARDCODE !!!
          *(UA<u32> *)(v16 + ((int)dword_2B3F68)) = l;



        l += 4096;
//        *(UA<u32> *)(v16 + 2834276) = 0; //2B3F64 HARDCODE !!!
          *(UA<u32> *)(v16 + ((int)dword_2B3F64)) = 0;
      }
    }

    v17 = 0;
    qsort((void*)MemoryBlocks, v7, 12, CPP_compare); //CLIB

    do
    {
      v18 = 9 * v17++;
      *(UA<i32> *)((char *) dword_2B4B64 + 2 * v18) = 0;
    }
    while ( v17 < 256 );

    for ( m = 0; m < v7; ++m )
    {
      v20 = 18 * m;

//      *(UA<u32> *)(v20 + 2837344) = MemoryBlocks[3 * m]; //2B4B60 HARDCODE !!!
//      *(UA<u32> *)(v20 + 2837348) = dword_2B3F68[3 * m]; //2B4B64 HARDCODE !!!

      *(UA<u32> *)(v20 + ((int)&MemoryArenas)) = MemoryBlocks[3 * m]; //2B4B60 MemoryArenas
      *(UA<u32> *)(v20 + ((int) dword_2B4B64)) = dword_2B3F68[3 * m]; //2B4B64 dword_2B4B64


      if ( m )
        *(UA<i32> *)((char *) dword_2B4B6C + 18 * m) = (int)&MemoryArenas + 18 * m - 18;
      else
        dword_2B4B6C = 0;

      v21 = 9 * m;

      *(UA<i32> *)((char *) dword_2B4B68 + 2 * v21) = (int)&MemoryArenas + 18 * m + 18;
      byte_2B4B71[2 * v21] = m;
      byte_2B4B70[2 * v21] = 0;
    }

    *(UA<i32> *)((char *) dword_2B4B68 + 18 * v7 - 18) = 0;

//    sosFreeSelector(sf18,sf8&0xFFFF,(int)sf24);
//    sosFreeSelector(sf1C,sf4&0xFFFF,(int)sf20);

    CPP_dos_free((sf14>>0x10)&0xFFFF); //???
}
#endif

void CPP_SetupMemory(void)
{
 i64 v2; // kr00_8
  i64 v3; // rax
  int v4; // ebx
  int i; // ebx
  signed int v6; // ebx
  int v7; // esi
  unsigned int v8; // eax
  int v9; // edx
  int v10; // edi
  int v11; // eax
  int j; // ebx
  int v13; // eax
  int l; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int m; // ebx
  int v20; // eax
  int v21; // eax
  int *v22; // [esp-Ch] [ebp-30h]
  char *v23; // [esp-Ch] [ebp-30h]
  int v24; // [esp+0h] [ebp-24h] BYREF
  int v25[3]; // [esp+4h] [ebp-20h] BYREF
  int v26; // [esp+10h] [ebp-14h]
  int v27; // [esp+14h] [ebp-10h]
  int k; // [esp+18h] [ebp-Ch]
  int v29; // [esp+1Ch] [ebp-8h]
  int v30; // [esp+20h] [ebp-4h]

#if 0
 u8 DUP[0x100];
 u8 *StackFrame=(u8*)DUP;
 u64 r64;
 u32 t;

 u32 sf18,sf24,sf20;
 u32 sf4,sf8;        //селекторы SOS
 u32 sf1C,sf14;
#endif

 if(dword_2B3F68[0])return;

// r64=sosAllocateFarMem(0xF000,(int)&sf24);
// sf18=r64;
// sf8=*((u32*)&r64+1);

// r64=sosAllocateFarMem(0xA000,(int)&sf20);
// sf1C=r64;
// sf4=*((u32*)&r64+1);

i=0; //начальный инит - его не было!

#if 0
 sf14=CPP_dos_alloc(0xFA00);

 if(sf14<256)
 {
  do memset((char*)&MemoryBlocks[3*i++],0,12);
  while(i<256);
 }
#endif

 for(i=0;i<256;++i)memset((char*)&MemoryArenas+18*i,0,18);

#if 0
    v6 = 0x10000;
    v7 = 0;

    while ( v6 >= 1024 )
    {
      v8 = CPP_dos_alloc(v6);
      if ( v8 )
      {
printf("%x \n",v6);
getch();
        v9 = (u16)v8;
        v10 = HIWORD(v8);
        v11 = 3 * v7;
        dword_2B3F68[v11] = v6;
        ++v7;
        dword_2B3F64[v11] = v10;
        v6 += 1024;
        MemoryBlocks[v11] = 16 * v9;
      }
      v6 -= 1024;
    }
#endif

#if 0
    for ( j = 0x1000000; j >= 4096; j -= 4096 )
    {
      v13 = (int)malloc(j); //CLIB
      MemoryBlocks[3 * v7] = v13;
      if ( v13 )
      {
printf("%x \n",j);
getch();
        for ( k = 4096; k > 0; k -= 16 )
        {
          v27 = j + k;
          if ( _expand((void*)MemoryBlocks[3 * v7], j + k) ) //CLIB
          {
printf("! %x \n",v27);
getch();
            dword_2B3F68[3 * v7] = v27;
            dword_2B3F64[3 * v7] = 0;
            break;
          }
        }
        j += 4096;
        ++v7;
      }
    }

    for ( l = 4096; l >= 16; l -= 16 )
    {
      v15 = (int)malloc(l);  //CLIB
      v16 = 12 * v7;
      MemoryBlocks[3 * v7] = v15;
      if ( v15 )
      {
printf("%x \n",l);
getch();

        ++v7;
//        *(UA<u32> *)(v16 + 2834280) = l; //2B3F68 HARDCODE !!!
          *(UA<u32> *)(v16 + ((int)dword_2B3F68)) = l;

        l += 4096;
//        *(UA<u32> *)(v16 + 2834276) = 0; //2B3F64 HARDCODE !!!
          *(UA<u32> *)(v16 + ((int)dword_2B3F64)) = 0;
      }
    }

    v17 = 0;

for(int i=0;i<v7;i++)printf("@ %x\n",MemoryBlocks[3*i]);
getch();

 //   qsort((void*)MemoryBlocks, v7, 12, CPP_compare); //CLIB

printf("%x \n",v7);

for(int i=0;i<v7;i++)printf("@ %x\n",MemoryBlocks[3*i]);
getch();
#endif

v17=0; //!!! начальное значение

GlobalHeap=malloc(0x350+0x590+0xE70+0x43F0+0xF400+(0x10000*7)+0x561FC0 +0x100); //размер всех пулов + добавка на выравнивание

dword_2B3F68[3*0x0]=0x350;
dword_2B3F64[3*0x0]=(((u32)GlobalHeap)+0x100)&0xFFFFFF00; //выравнивание адреса на границу 256 байт
MemoryBlocks[3*0x0]=(((u32)GlobalHeap)+0x100)&0xFFFFFF00;

dword_2B3F68[3*0x1]=0x590;
dword_2B3F64[3*0x1]=MemoryBlocks[3*0x0]+0x350;
MemoryBlocks[3*0x1]=MemoryBlocks[3*0x0]+0x350;

dword_2B3F68[3*0x2]=0xE70;
dword_2B3F64[3*0x2]=MemoryBlocks[3*0x1]+0x590;
MemoryBlocks[3*0x2]=MemoryBlocks[3*0x1]+0x590;

dword_2B3F68[3*0x3]=0x43F0;
dword_2B3F64[3*0x3]=MemoryBlocks[3*0x2]+0xE70;
MemoryBlocks[3*0x3]=MemoryBlocks[3*0x2]+0xE70;

dword_2B3F68[3*0x4]=0xF400;
dword_2B3F64[3*0x4]=MemoryBlocks[3*0x3]+0x43F0;
MemoryBlocks[3*0x4]=MemoryBlocks[3*0x3]+0x43F0;

dword_2B3F68[3*0x5]=0x10000;
dword_2B3F64[3*0x5]=MemoryBlocks[3*0x4]+0xF400;
MemoryBlocks[3*0x5]=MemoryBlocks[3*0x4]+0xF400;

dword_2B3F68[3*0x6]=0x10000;
dword_2B3F64[3*0x6]=MemoryBlocks[3*0x5]+0x10000;
MemoryBlocks[3*0x6]=MemoryBlocks[3*0x5]+0x10000;

dword_2B3F68[3*0x7]=0x10000;
dword_2B3F64[3*0x7]=MemoryBlocks[3*0x6]+0x10000;
MemoryBlocks[3*0x7]=MemoryBlocks[3*0x6]+0x10000;

dword_2B3F68[3*0x8]=0x10000;
dword_2B3F64[3*0x8]=MemoryBlocks[3*0x7]+0x10000;
MemoryBlocks[3*0x8]=MemoryBlocks[3*0x7]+0x10000;

dword_2B3F68[3*0x9]=0x10000;
dword_2B3F64[3*0x9]=MemoryBlocks[3*0x8]+0x10000;
MemoryBlocks[3*0x9]=MemoryBlocks[3*0x8]+0x10000;

dword_2B3F68[3*0xA]=0x10000;
dword_2B3F64[3*0xA]=MemoryBlocks[3*0x9]+0x10000;
MemoryBlocks[3*0xA]=MemoryBlocks[3*0x9]+0x10000;

dword_2B3F68[3*0xB]=0x10000;
dword_2B3F64[3*0xB]=MemoryBlocks[3*0xA]+0x10000;
MemoryBlocks[3*0xB]=MemoryBlocks[3*0xA]+0x10000;

dword_2B3F68[3*0xC]=0x561FC0;
dword_2B3F64[3*0xC]=MemoryBlocks[3*0xB]+0x10000;
MemoryBlocks[3*0xC]=MemoryBlocks[3*0xB]+0x10000;

v7=0xD; //13 пулов

    do
    {
      v18 = 9 * v17++;
      *(UA<i32> *)((char *) dword_2B4B64 + 2 * v18) = 0;
    }
    while ( v17 < 256 );

    for ( m = 0; m < v7; ++m )
    {
      v20 = 18 * m;

//      *(UA<u32> *)(v20 + 2837344) = MemoryBlocks[3 * m]; //2B4B60 HARDCODE !!!
//      *(UA<u32> *)(v20 + 2837348) = dword_2B3F68[3 * m]; //2B4B64 HARDCODE !!!

      *(UA<u32> *)(v20 + ((int)&MemoryArenas)) = MemoryBlocks[3 * m]; //2B4B60 MemoryArenas
      *(UA<u32> *)(v20 + ((int) dword_2B4B64)) = dword_2B3F68[3 * m]; //2B4B64 dword_2B4B64


      if ( m )
        *(UA<i32> *)((char *) dword_2B4B6C + 18 * m) = (int)&MemoryArenas + 18 * m - 18;
      else
        dword_2B4B6C[0] = 0; //space fix

      v21 = 9 * m;

      *(UA<i32> *)((char *) dword_2B4B68 + 2 * v21) = (int)&MemoryArenas + 18 * m + 18;
      byte_2B4B71[2 * v21] = m;
      byte_2B4B70[2 * v21] = 0;
    }

    *(UA<i32> *)((char *) dword_2B4B68 + 18 * v7 - 18) = 0;

//    sosFreeSelector(sf18,sf8&0xFFFF,(int)sf24);
//    sosFreeSelector(sf1C,sf4&0xFFFF,(int)sf20);

//    CPP_dos_free((sf14>>0x10)&0xFFFF); //???
}

int CPP_MyLowAlloc(int a2) //FINAL
{
  UA<i32> *v2; // eax
  unsigned int v3; // edi
  UA<i32> *v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // edx

  CPP_SetupMemory(/*a1, a2*/);

  v2 = (UA<i32>*)&MemoryArenas;
  v3 = -1;
  v5 = a2 + 15;
  v4 = 0;
  LOWORD(v5) = (a2 + 15) & 0xFFF0;

  while ( v2 )
  {
    v6 = v2[1];
    if ( v5 <= v6 && v3 > v6 && !*((u8 *)v2 + 16) && dword_2B3F64[3 * *((u8 *)v2 + 17)] )
    {
      v4 = v2;
      v3 = v2[1];
    }
    v2 = (UA<i32>*)(i32)v2[2];
  }

  if ( !v4 || !CPP_split_arena((int)v4, v5) )
    return 0;

  CPP_CheckMemory();

  memset((char*)(i32)*v4, 0, v5);

  return *v4;
}

int *CPP_CheckMemory(void) //FINAL
{
  UA<i32> *result; // eax
  unsigned int v1; // edx
  int v2; // edx

  result = (UA<i32>*)&MemoryArenas;
  MemoryAvailable = 0;

  dword_2B5D64 = 0;
  dword_2B5D68 = 0;
  dword_2B5D6C = 0;
  dword_2B5D70 = -1;

  while ( result )
  {
    if ( *((u8 *)result + 16) )
    {
      v2 = result[1];
      dword_2B5D68 += v2;
      MemoryAvailable += v2;
    }
    else
    {
      v1 = result[1];
      dword_2B5D64 += v1;

      if ( v1 > dword_2B5D6C )
        dword_2B5D6C = v1;

      if ( (unsigned)result[1] < (unsigned int)dword_2B5D70 ) //unsigned fix
        dword_2B5D70 = result[1];

      MemoryAvailable += result[1];
    }

    result = (UA<i32>*)(i32)result[2];
  }
  LOBYTE(MemoryAvailable) = MemoryAvailable & 0xFC;
  LOBYTE(dword_2B5D64) = dword_2B5D64 & 0xFC;
  LOBYTE(dword_2B5D6C) = dword_2B5D6C & 0xFC;
  LOBYTE(dword_2B5D68) = dword_2B5D68 & 0xFC;
  LOBYTE(dword_2B5D70) = dword_2B5D70 & 0xFC;

  return (int*)result;
}

char CPP_split_arena(int a1, int a2) //FINAL
{
  char result; // al
  UA<i32> *i; // eax
  char v4; // bl
  int v5; // edi

  if ( (unsigned)a2 == *(UA<u32> *)(a1 + 4) ) //unsigned fix
  {
    result = 1;
    *(u8 *)(a1 + 16) = 1;
  }
  else
  {
    for ( i = (UA<i32>*)&MemoryArenas; i < (UA<i32>*)&MemoryAvailable && i[1]; i = (UA<i32>*)((char *)i + 18) )
      ;
    if ( i == (UA<i32>*)&MemoryAvailable )
    {
      result = 0;
    }
    else
    {
      i[1] = *(UA<u32> *)(a1 + 4) - a2;
      *i = a2 + *(UA<u32> *)a1;
      *(u8 *)(a1 + 16) = 1;
      v4 = *(u8 *)(a1 + 17);
      *(UA<u32> *)(a1 + 4) = a2;
      *((u8 *)i + 17) = v4;
      i[2] = *(UA<u32> *)(a1 + 8);
      i[3] = a1;
      v5 = *(UA<u32> *)(a1 + 8);

      if ( v5 )
        *(UA<u32> *)(v5 + 12) = (u32)i;

      *(UA<u32> *)(a1 + 8) = (u32)i;

      result = 1;
    }
  }
  return result;
}

int CPP_LoadData(int a3) //FINAL
{
  int v3; // edx
  int v5; // eax
  int v6; // edx
  u32 *v7; // ecx
  int (/*__cdecl*/ *v8)(int); // [esp+0h] [ebp-4h]

  CPP_SetupMemory(/*a1, a2*/);

  if ( (*(u8 *)(a3 + 40) & 1) != 0 )
    v8 = CPP_MyLowAlloc;
  else
    v8 = CPP_MyAlloc;

  CPP_FreeData(a3);

  if ( *(u8 *)a3 == 42 )
  {

    v3 = v8(*(UA<u32> *)(a3 + 36));

    **(u32 **)(a3 + 28) = v3;

    if ( !v3 )
      return 0;
  }
  else
  {
    v5 = CPP_RncFileLength(a3);
    *(UA<u32> *)(a3 + 36) = v5;

    if ( v5 <= 0 )
      return 0;

    v6 = v8(v5);

    **(u32 **)(a3 + 28) = v6;

    if ( !v6 )
      return -1;

    if ( (unsigned)CPP_LoadFileAt((const char *)a3, **(char ***)(a3 + 28)) != *(UA<u32> *)(a3 + 36) ) //unsigned fix
    {
      **(u32 **)(a3 + 28) = 0;
      **(u32 **)(a3 + 32) = 0;
      *(UA<u32> *)(a3 + 36) = 0;
      return 0;
    }

  }
  v7 = *(u32 **)(a3 + 32);

  if ( v7 )
    *v7 = *(UA<u32> *)(a3 + 36) + **(u32 **)(a3 + 28);

  return 1;
}

int *CPP_FreeData(int a1) //FINAL
{
/*
 u32 eax=*(u32*)(a1+0x1C);
 u32 edx=*(u32*)eax;
 if(edx==0)return (int*)eax;
 CPP_MyFree(edx);
 eax=*(u32*)(a1+0x1C);
 *(u32*)eax=0;
 return (int*)eax;
*/
  int *result; // eax
  result = *(int **)(a1 + 28);
  if ( *result )
  {
   CPP_MyFree(*result);
   result = *(int **)(a1 + 28);
   *result = 0;
  }
  return result;
}

int *CPP_MyFree(int a1) //FINAL
{
  UA<i32> *v1; // eax
  char v2; // bl
  UA<i32> *i; // ebx

  v1 = (UA<i32>*)&MemoryArenas;
  v2 = 0;

  while ( v1 )
  {
    if ( a1 == *v1 )
    {
      v2 = 1;
      *((u8 *)v1 + 16) = 0;
      break;
    }
    v1 = (UA<i32>*)(i32)v1[2];
  }

  if ( v2 == 1 )
  {
    for ( i = (UA<i32>*)&MemoryArenas; i; i = (UA<i32>*)(i32)i[2] )
    {
      if ( !*((u8 *)i + 16) )
        CPP_delete_arena((int)i);
    }
  }

  return CPP_CheckMemory();
}

int CPP_LoadFileAt(const char *a1, char *a2) //FINAL
{
  int result; // eax
  int v3; // ebx
  int v4; // esi

  result = CPP_MyOpen((int)a1, 512);
  v3 = result;

  if ( result != 0 /*-1*/ )
  {
    v4 = CPP_RncFileLength((int)a1);
    CPP_MyRead(v3, (int)a2, v4);
    CPP_MyClose(v3);

//    result = CPP_UnpackM1((int)a2, a2); 
//--------------------------------------
//    result = UnpackM1((int)a2, a2);
//   if(result!=0)while(1); //проверка
//--------------------------------------
result=0; //проверка показала, что распаковывать нечего - все файлы разжаты!

    if ( result >= 0 )
    {
      if ( !result )
        result = v4;
    }
    else
    {
      printf("ERROR decompressing %s\n", a1);
      result = -2;
    }
  }

  return result;
}

int CPP_RncFileLength(int a1) //FINAL
{
  int v1; // ebx
  int v2; // esi
  int v3; // ebx
  char v5[8]; // [esp+0h] [ebp-10h] BYREF
  char v6[8]; // [esp+8h] [ebp-8h] BYREF

  v6[1] = 78;
  v6[3] = 1;
  v6[2] = 67;
  v6[0] = 82;
  v6[4] = 0;
  v1 = CPP_MyOpen(a1, 512);
  v2 = v1;

  if ( v1 == /*<=*/ 0 )
    return -1;

  CPP_MyRead(v1, (int)v5, 8);

  if ( !strncmp((const char*)v5, (const char*)v6, 4) ) //CLIB
    v3 = (u8)v5[7]
       + (((u8)v5[6] + (((u8)v5[5] + ((u8)v5[4] << 8)) << 8)) << 8);
  else
    v3 = FileSize((FILE*)v1); //filelength(v1); //CLIB

  CPP_MyClose(v2);
  return v3;
}

int CPP_MyOpen(int a1, int a2) //FINAL
{
  int v2; // ebx

  char ffn[256]={0};

  #if defined(__linux__) || defined(__EMSCRIPTEN__)

  fixfilename(ffn,(const char*)a1);

  #else

  strcpy(ffn,(const char*)a1);

  #endif

  if ( a2 == 546 )
  {
   v2=(int)fopen(ffn,"w+b"); //создаёт двоичный файл для чтения-записи
   fclose((FILE*)v2);
/*
    v2 = creat((const char*)a1, 448); //CLIB
    setmode(v2, 512);    //CLIB
    close(v2);           //CLIB
*/
  }

  return (int)fopen(ffn,"r+b"); //открывает двоичный файл для чтения-записи
//return sopen((const char*)a1, a2, 64); //CLIB
}

int CPP_MyRead(int a1, int a2, int a3) //FINAL
{
   return fread((void*)a2,1,a3,(FILE*)a1); //CLIB
 //return read(a1, (void*)a2, a3); //CLIB
}

int CPP_MyClose(int a1) //FINAL
{
    return (int)fclose((FILE*)a1); //CLIB
  //return close(a1); //CLIB
}

int CPP_UnpackM1(int a1, char *a2) //NOT USED
{
#if 0
  unsigned int i; // ecx
  int *v3; // esi
  int v4; // eax
  int v5; // eax
  u16 *v6; // esi
  unsigned int v7; // edx
  char *v8; // ebx
  u32 *v9; // esi
  char *v10; // edi
  u32 *v11; // esi
  u16 *v12; // edi
  u8 *v13; // esi
  u8 *v14; // edi
  char *v15; // edi
  int v16; // eax
  i16 v17; // bx
  i16 v18; // ax
  i16 v19; // dx
  i16 v20; // ax
  u16 v22; // [esp-1Ah] [ebp-1Eh]

  if ( *(UA<u16> *)a1 != 20050 )
    return 0;

  v3 = (int *)(a1 + 4);

  if ( *(UA<u16> *)(a1 + 2) != 323 )
    return 0;

  LOBYTE(v4) = read_long(v3);

  dword_22D444 = v4;

  LOBYTE(v5) = read_long(v3);

  dword_22D448 = v5;
  byte_22D454 = *(u8 *)(a1 + 9);
  v6 = (u16 *)(a1 + 10);
  v7 = v5 + 18 + a1;

  if ( v7 > (unsigned int)a2 )
  {
    v8 = &a2[dword_22D444 + *(u8 *)(a1 + 16)];
    if ( (unsigned int)v8 > v7 )
    {
      v9 = (u32 *)(v7 - 4);
      v10 = v8 - 4;
      for ( i = (unsigned int)dword_22D448 >> 2; i; --i )
      {
        *(UA<u32> *)v10 = *v9--;
        v10 -= 4;
      }
      v11 = v9 + 1;

      v12 = (u16*)(v10 + 4);

      LOWORD(i) = dword_22D448 & 3;
      if ( (dword_22D448 & 3) != 0 )
      {
        v13 = (u8*)(((char *)v11) - 1); //(char *)v11 - 1;
        v14 = (u8*)(((char *)v12) - 1); //(char *)v12 - 1;
        while ( i )
        {
          *v14-- = *v13--;
          --i;
        }
        v12 = (u16*)(v14 + 1);
      }
      v6 = v12;
    }
  }

  v15 = a2;
  byte_22D455 = 0;
  word_22D450 = *v6;

  input_bits(2u, (int)v6);

  do
  {
    make_huftable((int)v6);
    make_huftable((int)v6);
    make_huftable((int)v6);
    word_22D44E = input_bits(0x10u, (int)v6);
    while ( 1 )
    {
      input_value(word_22D2C4, (int)v6);
      if ( (u16)i )
      {
        qmemcpy(v15, v6, i);
        v6 = (u16 *)((char *)v6 + i);
        v15 += i;
        i = (u8)byte_22D455;
        v17 = *v6;
        v18 = __ROL2__(*v6, byte_22D455);
        v19 = (1 << byte_22D455) - 1;
        word_22D450 &= v19;
        v20 = v18 & v19 | (v6[1] << byte_22D455);
        word_22D450 |= v17 << byte_22D455;
        word_22D452 = v20;
      }

      if ( !--word_22D44E )
        break;

      input_value(word_22D344, (int)v6);

      v22 = i;

      input_value(word_22D3C4, (int)v6);

      LOWORD(i) = i + 2;
      v16 = v22;
      LOWORD(v16) = v22 + 1;

      qmemcpy(v15, &v15[-v16], i);

      v15 += i;
      i = 0;
    }
    --byte_22D454;
  }
  while ( byte_22D454 );

  return dword_22D444;
#endif

 return 0;
}

int CPP_delete_arena(int a1) //FINAL
{
  int result; // eax
  int v2; // edx
  int v3; // ebx

  result = a1;
  if ( *(UA<u32> *)(a1 + 12) )
  {
    *(u8 *)(a1 + 16) = 0;
    v2 = *(UA<u32> *)(a1 + 12);

    if ( *(u8 *)(a1 + 17) == *(u8 *)(v2 + 17) && !*(u8 *)(v2 + 16) )
    {
      v3 = *(UA<u32> *)(a1 + 8);

      if ( v3 )
        *(UA<u32> *)(v3 + 12) = v2;

      *(UA<u32> *)(*(UA<u32> *)(a1 + 12) + 8) = *(UA<u32> *)(a1 + 8);
      *(UA<u32> *)(*(UA<u32> *)(a1 + 12) + 4) += *(UA<u32> *)(a1 + 4);
      *(UA<u32> *)(a1 + 4) = 0;
    }
  }

  return result;
}


void CPP_setup_vecs(int a1, int a2, int a3, int a4, int a5) //FINAL
{
  if ( a1 )
  {
    vec_screen = a1;
    dword_220C4C = a1 - a3;
  }
  if ( a2 )
    vec_map = a2;
  if ( a3 )
    vec_screen_width = a3;
  if ( a5 )
    vec_window_height = a5;
  if ( a4 )
    vec_window_width = a4;
}

void CPP_SetupScreenMCGA(u8 *a1) //SDL2
{
 if(SDL_Init(SDL_INIT_VIDEO)!=0)
 {
  printf("error!\n");
  exit(-1);
 }

 window=SDL_CreateWindow("Tube",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,320*SCALE,200*SCALE,SDL_WINDOW_SHOWN);
 if(!window)
 {
  printf("error!\n");
  exit(-1);
 }

 renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
 if(!renderer)
 {
  printf("error!\n");
  exit(-1);
 }

 texture=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGB565,SDL_TEXTUREACCESS_TARGET,320,200);
 if(!texture)
 {
  printf("error!\n");
  exit(-1);
 }

 SDL_SetRenderDrawColor(renderer,0,0,0,255);

 SDL_ShowCursor(SDL_DISABLE);

//  int v2[7]; // [esp+0h] [ebp-38h] BYREF
//  char v3[28]; // [esp+1Ch] [ebp-1Ch] BYREF

/*
  v2[0] = 3840;

  int386(16, v2, v3);

  if ( !OldVideoMode )
    OldVideoMode = (u8)v3[0];

  v2[0] = 19;
*/

//OldVideoMode =3; //text mode #3 при выходе из игры

  ScreenWidth = 320;
  ScreenHeight = 200;

//  int386(16, v2, v3);

/*
  _asm //320x200 256 color paletted
  {
   mov ax,13h
   int 10h
  }
*/

//  CPP_SetPalette256(a1); //не нужно

    memset(Palette,0,sizeof(Palette));
    memset(PAL16,0,sizeof(PAL16));

//  SetMouseLimits(); //не нужно

/*  return*/  CPP_SetGraphicsWindow(0, 0, 320, 200);
}

void CPP_SetGraphicsWindow(i16 a1, i16 a2, i16 a3, i16 a4) //FINAL
{
//  int result; // eax

  GraphicsWindowLeft = a1;
  GraphicsWindowTop = a2;
  GraphicsWindowWidth = a3;
  GraphicsWindowRight = a3 + a1;

//  result = a4;

  GraphicsWindowHeight = a4;
  GraphicsWindowBottom = a4 + a2;

//  return result;
}

void CPP_SetPalette256(u8 *a1) //SDL2
{
 for(int i=0;i<256*3;i+=3)
 {
  Palette[i+2]=*a1++;
  Palette[i+1]=*a1++;
  Palette[i  ]=*a1++;

  PAL16[i/3]=((Palette[i+2]>>1)<<11)|(Palette[i+1]<<5)|(Palette[i]>>1); //6:6:6 to 5:6:5
 }

 //ToScreen();

#if 0
  int v2; // ecx
  u8 v3; // al
  u8 *v4; // ebx
  u8 v5; // al
  u8 result; // al

  outp(0x3C6u, 0xFFu);
  v2 = 0;
  do
  {
    outp(0x3C8u, v2);
    v3 = *a1;
    v4 = a1 + 1;
    outp(0x3C9u, v3);
    v5 = *v4++;
    outp(0x3C9u, v5);
    ++v2;
    result = *v4;
    a1 = v4 + 1;
    outp(0x3C9u, result);
  }
  while ( (u16)v2 < 0x100u );

//  return result;
#endif
}

void CPP_GetPalette256(u8 *a1) //SDL2
{
 for(int i=0;i<256*3;i+=3)
 {
  *a1++=Palette[i+2];
  *a1++=Palette[i+1];
  *a1++=Palette[i  ];
 }

#if 0
//  int v3; // [esp+4h] [ebp-4h]

  outp(0x3C7u, 0);
  __inbytestring(0x3C9u, a1, 0x300u);

//  return v3;
#endif
}

void CPP_WaitVbi(void) //SDL2
{
 SDL_RenderPresent(renderer);

#if 0
  u8 result; // al

  do
    result = inp(0x3DAu);
  while ( (result & 8) == 0 );

//  return result;
#endif
}

i16 CPP_FadePalette256(u8 *a1, u8 a2, char a3) //FINAL
{
  u8 *v3; // ebx
  i16 j; // cx
  int v5; // esi
  int v6; // eax
  char v7; // dl
  i16 result; // ax
  i16 i; // cx
  int v10; // esi
  int v11; // eax
  char v12; // dl
  u8 v13[768]; // [esp+0h] [ebp-300h] BYREF

  v3 = a1;
  if ( a3 )
  {
    if ( fade_started )
    {
      if ( a2 == ++fade_count )
        fade_started = 0;
    }
    else
    {
      fade_count = 0;
      fade_started = 1;
      CPP_GetPalette256((u8 *)from);

      if ( !a1 )
        memset((char*) to_pal, 0, 768);
    }
    if ( !a1 )
      v3 = (u8 *) to_pal;
    for ( i = 0; i < 768; ++i )
    {
      v10 = i;

      int tmp=unk_2B3E5E; //sanitizer crash

      v11 = (i16)(v3[i] - (u8)from[i]) * ((int)tmp /*unk_2B3E5E*/ >> 16) / a2;
      v12 = from[i];
      v13[v10] = v12 + v11;
    }
    CPP_WaitVbi();
    CPP_SetPalette256(v13);
    result = fade_count;
  }
  else
  {
    CPP_GetPalette256((u8 *)from);
    if ( !a1 )
    {
      v3 = (u8 *) to_pal;
      memset((char*) to_pal, 0, 768);
    }
    for ( fade_count = 0; a2 >= fade_count; ++fade_count )
    {
      for ( j = 0; j < 768; ++j )
      {
        v5 = j;

        int tmp=unk_2B3E5E; //sanitizer crash

        v6 = (i16)(v3[j] - (u8)from[j]) * ((int)tmp /*unk_2B3E5E*/ >> 16) / a2;
        v7 = from[j];
        v13[v5] = v7 + v6;
      }
      CPP_WaitVbi();
      CPP_SetPalette256(v13);
    }
    fade_started = 0;
    result = fade_count;
  }
  return result;
}


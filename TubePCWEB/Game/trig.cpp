#include <string.h>

#include "Type.h"

#include "misc.h"

#include "DSEG3.h"
#include "DSEG4.h"

#include "defs.h"

const int dword_219523[16]={0,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1}; //лукап для треугольника

void CPP_trig(int *a1, int *a2, int *a3) //fixed pointers from _DWORD* to int*
{
  int *v3; // esi
  int *v4; // edi
  int *v5; // ecx
  int v6; // eax
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  int v13; // eax
  int v14; // ebx
  _BOOL1 v15; // zf
  char v16; // cc
  int v17; // ebx
  int v18; // ebx
  int v19; // eax
  int v20; // ebx
  int v21; // ecx
  int v22; // edx
  int v23; // esi
  int v24; // ebx
  int *v25; // edi
  int v26; // edi
  _BOOL1 v27; // of
  int v28; // edi
  unsigned int v29; // eax
  int v30; // eax
  int v31; // ebx
  _BOOL1 v32; // zf
  int v33; // ebx
  int v34; // ebx
  int v35; // eax
  int v36; // ebx
  int v37; // ecx
  int v38; // edx
  int v39; // ebx
  int *v40; // edi
  int v41; // edi
  int v42; // edi
  int v43; // eax
  int v44; // ebx
  _BOOL1 v45; // zf
  int v46; // ebx
  int v47; // eax
  int v48; // ebx
  int v49; // esi
  int v50; // ebx
  int *v51; // edi
  int v52; // edi
  int v53; // edi
  int v54; // eax
  int v55; // ebx
  int v56; // ebx
  int *v57; // edi
  int v58; // edi
  int v59; // edi
  int v60; // eax
  int v61; // ebx
  int v62; // ebx
  int v63; // ebx
  int v64; // eax
  int v65; // ebx
  _BOOL1 v66; // zf
  int v67; // ebx
  int v68; // ebx
  int v69; // eax
  int v70; // ebx
  int v71; // ecx
  int v72; // edx
  int v73; // esi
  int v74; // eax
  int *v75; // edi
  int v76; // edi
  int v77; // edi
  int v78; // eax
  int v79; // ebx
  _BOOL1 v80; // zf
  int v81; // ebx
  int v82; // ebx
  int v83; // eax
  int v84; // ebx
  int v85; // ecx
  int v86; // edx
  int v87; // eax
  int *v88; // edi
  int v89; // edi
  int v90; // edi
  int v91; // eax
  int v92; // ebx
  _BOOL1 v93; // zf
  int v94; // ebx
  int v95; // eax
  int v96; // ebx
  int v97; // esi
  int v98; // eax
  int *v99; // edi
  int v100; // edi
  int v101; // edi
  int v102; // eax
  int v103; // ebx
  int v104; // eax
  int *v105; // edi
  int v106; // edi
  int v107; // edi
  int v108; // eax
  int v109; // ebx
  int v110; // ebx
  int v111; // eax
  int v112; // ebx
  int v113; // ecx
  int v114; // edx
  int v115; // esi
  int v116; // edi
  int *v117; // edi
  int v118; // ebx
  int v119; // eax
  int v120; // ebx
  int v121; // ecx
  int v122; // edx
  int v123; // edi
  int *v124; // edi
  int v125; // eax
  int v126; // ebx
  int v127; // esi
  int v128; // edi
  int *v129; // edi
  int v130; // eax
  int v131; // ebx
  int v132; // edi
  int *v133; // edi
  int v134; // eax
  int v135; // ebx
  int v136; // ebx
  int v137; // eax
  int v138; // ebx
  int v139; // ecx
  int v140; // edx
  int v141; // esi
  int v142; // edi
  int *v143; // edi
  int v144; // ebx
  int v145; // eax
  int v146; // ebx
  int v147; // ecx
  int v148; // edx
  int v149; // edi
  int *v150; // edi
  int v151; // eax
  int v152; // ebx
  int v153; // esi
  int v154; // edi
  int *v155; // edi
  int v156; // eax
  int v157; // ebx
  int v158; // edi
  int *v159; // edi
  unsigned __int16 *v160; // esi
  char *v161; // edx
  char v162; // al
  int v163; // ebx
  signed int v164; // ecx
  char *v165; // edi
  unsigned __int16 *v166; // esi
  int v167; // eax
  int v168; // ebx
  int v169; // ecx
  _BYTE *v170; // edi
  int v171; // eax
  unsigned int v172; // eax
  int v173; // edx
  unsigned int v174; // eax
  int v175; // esi
  char v176; // al
  _BOOL1 v177; // cf
  int v178; // edx
  __int16 v179; // cx
  char v180; // al
  int v181; // edx
  __int16 v182; // cx
  char v183; // al
  int v184; // edx
  __int16 v185; // cx
  char v186; // al
  int v187; // edx
  __int16 v188; // cx
  char v189; // al
  int v190; // edx
  __int16 v191; // cx
  char v192; // al
  int v193; // edx
  __int16 v194; // cx
  char v195; // al
  int v196; // edx
  __int16 v197; // cx
  char v198; // al
  int v199; // edx
  __int16 v200; // cx
  char v201; // al
  int v202; // edx
  __int16 v203; // cx
  char v204; // al
  int v205; // edx
  __int16 v206; // cx
  char v207; // al
  int v208; // edx
  __int16 v209; // cx
  char v210; // al
  int v211; // edx
  __int16 v212; // cx
  char v213; // al
  int v214; // edx
  __int16 v215; // cx
  char v216; // al
  int v217; // edx
  __int16 v218; // cx
  char v219; // al
  int v220; // edx
  __int16 v221; // cx
  char v222; // al
  unsigned __int16 *v223; // esi
  int v224; // eax
  int v225; // ebx
  int v226; // ecx
  _BYTE *v227; // edi
  int v228; // eax
  unsigned int v229; // eax
  int v230; // edx
  unsigned int v231; // eax
  int v232; // esi
  char v233; // al
  int v234; // edx
  __int16 v235; // cx
  char v236; // al
  int v237; // edx
  __int16 v238; // cx
  char v239; // al
  int v240; // edx
  __int16 v241; // cx
  char v242; // al
  int v243; // edx
  __int16 v244; // cx
  char v245; // al
  int v246; // edx
  __int16 v247; // cx
  char v248; // al
  int v249; // edx
  __int16 v250; // cx
  char v251; // al
  int v252; // edx
  __int16 v253; // cx
  char v254; // al
  int v255; // edx
  __int16 v256; // cx
  char v257; // al
  int v258; // edx
  __int16 v259; // cx
  char v260; // al
  int v261; // edx
  __int16 v262; // cx
  char v263; // al
  int v264; // edx
  __int16 v265; // cx
  char v266; // al
  int v267; // edx
  __int16 v268; // cx
  char v269; // al
  int v270; // edx
  __int16 v271; // cx
  char v272; // al
  int v273; // edx
  __int16 v274; // cx
  char v275; // al
  int v276; // edx
  __int16 v277; // cx
  char v278; // al
  _WORD *i; // esi
  int v280; // ecx
  _BYTE *v281; // edi
  unsigned int v282; // eax
  __int16 v283; // bx
  __int16 v284; // bx
  __int16 v285; // bx
  __int16 v286; // cx
  __int16 v287; // bx
  __int16 v288; // cx
  __int16 v289; // bx
  __int16 v290; // cx
  __int16 v291; // bx
  __int16 v292; // cx
  __int16 v293; // bx
  __int16 v294; // cx
  __int16 v295; // bx
  __int16 v296; // cx
  __int16 v297; // bx
  __int16 v298; // cx
  __int16 v299; // bx
  __int16 v300; // cx
  __int16 v301; // bx
  __int16 v302; // cx
  __int16 v303; // bx
  __int16 v304; // cx
  __int16 v305; // bx
  __int16 v306; // cx
  __int16 v307; // bx
  __int16 v308; // cx
  __int16 v309; // bx
  __int16 v310; // cx
  __int16 v311; // bx
  __int16 v312; // cx
  __int16 v313; // bx
  __int16 v314; // cx
  unsigned int v315; // eax
  int v316; // ebx
  char *v317; // esi
  int v318; // ecx
  int v319; // edi
  int v320; // ecx
  int v321; // edx
  int v322; // ecx
  __int16 v323; // cx
  __int16 v324; // bp
  _BYTE *v325; // edi
  int v326; // ebp
  unsigned __int16 *v327; // esi
  unsigned int v328; // eax
  int v329; // ebx
  int v330; // ecx
  _BYTE *v331; // edi
  int v332; // ecx
  int v333; // edx
  int v334; // ecx
  __int16 v335; // cx
  int v336; // esi
  int v337; // edx
  int v338; // ecx
  int v339; // edx
  int v340; // ecx
  int v341; // edx
  int v342; // ecx
  int v343; // edx
  int v344; // ecx
  int v345; // edx
  int v346; // ecx
  int v347; // edx
  int v348; // ecx
  int v349; // edx
  int v350; // ecx
  int v351; // edx
  int v352; // ecx
  int v353; // edx
  int v354; // ecx
  int v355; // edx
  int v356; // ecx
  int v357; // edx
  int v358; // ecx
  int v359; // edx
  int v360; // ecx
  int v361; // edx
  int v362; // ecx
  int v363; // edx
  int v364; // ecx
  int v365; // edx
  int v366; // ecx
  unsigned __int16 *v367; // esi
  int v368; // eax
  int v369; // ebx
  int v370; // ecx
  _BYTE *v371; // edi
  int v372; // eax
  unsigned int v373; // eax
  int v374; // edx
  unsigned int v375; // eax
  int v376; // esi
  int v377; // edx
  __int16 v378; // cx
  int v379; // edx
  __int16 v380; // cx
  int v381; // edx
  __int16 v382; // cx
  int v383; // edx
  __int16 v384; // cx
  int v385; // edx
  __int16 v386; // cx
  int v387; // edx
  __int16 v388; // cx
  int v389; // edx
  __int16 v390; // cx
  int v391; // edx
  __int16 v392; // cx
  int v393; // edx
  __int16 v394; // cx
  int v395; // edx
  __int16 v396; // cx
  int v397; // edx
  __int16 v398; // cx
  int v399; // edx
  __int16 v400; // cx
  int v401; // edx
  __int16 v402; // cx
  int v403; // edx
  __int16 v404; // cx
  int v405; // edx
  __int16 v406; // cx
  unsigned __int16 *v407; // esi
  int v408; // eax
  int v409; // ebx
  int v410; // ecx
  _BYTE *v411; // edi
  int v412; // eax
  unsigned int v413; // eax
  int v414; // edx
  unsigned int v415; // eax
  int v416; // esi
  int v417; // edx
  __int16 v418; // cx
  int v419; // edx
  __int16 v420; // cx
  int v421; // edx
  __int16 v422; // cx
  int v423; // edx
  __int16 v424; // cx
  int v425; // edx
  __int16 v426; // cx
  int v427; // edx
  __int16 v428; // cx
  int v429; // edx
  __int16 v430; // cx
  int v431; // edx
  __int16 v432; // cx
  int v433; // edx
  __int16 v434; // cx
  int v435; // edx
  __int16 v436; // cx
  int v437; // edx
  __int16 v438; // cx
  int v439; // edx
  __int16 v440; // cx
  int v441; // edx
  __int16 v442; // cx
  int v443; // edx
  __int16 v444; // cx
  int v445; // edx
  __int16 v446; // cx
  unsigned __int16 *v447; // esi
  int v448; // eax
  int v449; // ebx
  int v450; // ecx
  _BYTE *v451; // edi
  int v452; // eax
  unsigned int v453; // eax
  int v454; // edx
  unsigned int v455; // eax
  int v456; // esi
  int v457; // edx
  __int16 v458; // cx
  int v459; // edx
  __int16 v460; // cx
  int v461; // edx
  __int16 v462; // cx
  int v463; // edx
  __int16 v464; // cx
  int v465; // edx
  __int16 v466; // cx
  int v467; // edx
  __int16 v468; // cx
  int v469; // edx
  __int16 v470; // cx
  int v471; // edx
  __int16 v472; // cx
  int v473; // edx
  __int16 v474; // cx
  int v475; // edx
  __int16 v476; // cx
  int v477; // edx
  __int16 v478; // cx
  int v479; // edx
  __int16 v480; // cx
  int v481; // edx
  __int16 v482; // cx
  int v483; // edx
  __int16 v484; // cx
  int v485; // edx
  __int16 v486; // cx
  unsigned __int16 *v487; // esi
  int v488; // eax
  int v489; // ebx
  int v490; // ecx
  _BYTE *v491; // edi
  int v492; // eax
  unsigned int v493; // eax
  int v494; // edx
  unsigned int v495; // eax
  int v496; // esi
  int v497; // edx
  __int16 v498; // cx
  int v499; // edx
  __int16 v500; // cx
  int v501; // edx
  __int16 v502; // cx
  int v503; // edx
  __int16 v504; // cx
  int v505; // edx
  __int16 v506; // cx
  int v507; // edx
  __int16 v508; // cx
  int v509; // edx
  __int16 v510; // cx
  int v511; // edx
  __int16 v512; // cx
  int v513; // edx
  __int16 v514; // cx
  int v515; // edx
  __int16 v516; // cx
  int v517; // edx
  __int16 v518; // cx
  int v519; // edx
  __int16 v520; // cx
  int v521; // edx
  __int16 v522; // cx
  int v523; // edx
  __int16 v524; // cx
  int v525; // edx
  __int16 v526; // cx
  unsigned __int16 *v527; // esi
  int v528; // eax
  int v529; // ebx
  int v530; // ecx
  _BYTE *v531; // edi
  int v532; // eax
  unsigned int v533; // eax
  int v534; // edx
  unsigned int v535; // eax
  int v536; // esi
  int v537; // edx
  __int16 v538; // cx
  int v539; // edx
  __int16 v540; // cx
  int v541; // edx
  __int16 v542; // cx
  int v543; // edx
  __int16 v544; // cx
  int v545; // edx
  __int16 v546; // cx
  int v547; // edx
  __int16 v548; // cx
  int v549; // edx
  __int16 v550; // cx
  int v551; // edx
  __int16 v552; // cx
  int v553; // edx
  __int16 v554; // cx
  int v555; // edx
  __int16 v556; // cx
  int v557; // edx
  __int16 v558; // cx
  int v559; // edx
  __int16 v560; // cx
  int v561; // edx
  __int16 v562; // cx
  int v563; // edx
  __int16 v564; // cx
  int v565; // edx
  __int16 v566; // cx
  unsigned __int16 *v567; // esi
  _BYTE *v568; // edx
  int v569; // eax
  int v570; // ebx
  int v571; // ecx
  _BYTE *j; // edi
  __int16 v573; // cx
  __int16 v574; // cx
  __int16 v575; // cx
  __int16 v576; // cx
  __int16 v577; // cx
  __int16 v578; // cx
  __int16 v579; // cx
  __int16 v580; // cx
  __int16 v581; // cx
  __int16 v582; // cx
  __int16 v583; // cx
  __int16 v584; // cx
  __int16 v585; // cx
  __int16 v586; // cx
  __int16 v587; // cx
  unsigned __int16 *v588; // esi
  _BYTE *v589; // edx
  int v590; // eax
  int v591; // ebx
  int v592; // ecx
  _BYTE *k; // edi
  __int16 v594; // cx
  __int16 v595; // cx
  __int16 v596; // cx
  __int16 v597; // cx
  __int16 v598; // cx
  __int16 v599; // cx
  __int16 v600; // cx
  __int16 v601; // cx
  __int16 v602; // cx
  __int16 v603; // cx
  __int16 v604; // cx
  __int16 v605; // cx
  __int16 v606; // cx
  __int16 v607; // cx
  __int16 v608; // cx
  unsigned __int16 *v609; // esi
  int v610; // edx
  int v611; // ecx
  _BYTE *v612; // edi
  unsigned int v613; // eax
  __int16 v614; // bx
  unsigned __int16 v615; // bx
  __int16 v616; // bx
  __int16 v617; // cx
  __int16 v618; // bx
  __int16 v619; // cx
  __int16 v620; // bx
  __int16 v621; // cx
  __int16 v622; // bx
  __int16 v623; // cx
  __int16 v624; // bx
  __int16 v625; // cx
  __int16 v626; // bx
  __int16 v627; // cx
  __int16 v628; // bx
  __int16 v629; // cx
  __int16 v630; // bx
  __int16 v631; // cx
  __int16 v632; // bx
  __int16 v633; // cx
  __int16 v634; // bx
  __int16 v635; // cx
  __int16 v636; // bx
  __int16 v637; // cx
  __int16 v638; // bx
  __int16 v639; // cx
  __int16 v640; // bx
  __int16 v641; // cx
  __int16 v642; // bx
  __int16 v643; // cx
  __int16 v644; // bx
  __int16 v645; // cx
  unsigned __int16 *v646; // esi
  int v647; // edx
  int v648; // ecx
  _BYTE *v649; // edi
  unsigned int v650; // eax
  __int16 v651; // bx
  unsigned __int16 v652; // bx
  __int16 v653; // bx
  __int16 v654; // cx
  __int16 v655; // bx
  __int16 v656; // cx
  __int16 v657; // bx
  __int16 v658; // cx
  __int16 v659; // bx
  __int16 v660; // cx
  __int16 v661; // bx
  __int16 v662; // cx
  __int16 v663; // bx
  __int16 v664; // cx
  __int16 v665; // bx
  __int16 v666; // cx
  __int16 v667; // bx
  __int16 v668; // cx
  __int16 v669; // bx
  __int16 v670; // cx
  __int16 v671; // bx
  __int16 v672; // cx
  __int16 v673; // bx
  __int16 v674; // cx
  __int16 v675; // bx
  __int16 v676; // cx
  __int16 v677; // bx
  __int16 v678; // cx
  __int16 v679; // bx
  __int16 v680; // cx
  __int16 v681; // bx
  __int16 v682; // cx
  unsigned __int16 *v683; // esi
  int v684; // eax
  int v685; // ebx
  int v686; // ecx
  _BYTE *v687; // edi
  int v688; // eax
  unsigned int v689; // eax
  int v690; // edx
  unsigned int v691; // eax
  int v692; // esi
  int v693; // edx
  __int16 v694; // cx
  int v695; // edx
  __int16 v696; // cx
  int v697; // edx
  __int16 v698; // cx
  int v699; // edx
  __int16 v700; // cx
  int v701; // edx
  __int16 v702; // cx
  int v703; // edx
  __int16 v704; // cx
  int v705; // edx
  __int16 v706; // cx
  int v707; // edx
  __int16 v708; // cx
  int v709; // edx
  __int16 v710; // cx
  int v711; // edx
  __int16 v712; // cx
  int v713; // edx
  __int16 v714; // cx
  int v715; // edx
  __int16 v716; // cx
  int v717; // edx
  __int16 v718; // cx
  int v719; // edx
  __int16 v720; // cx
  int v721; // edx
  __int16 v722; // cx
  unsigned __int16 *v723; // esi
  int v724; // eax
  int v725; // ebx
  int v726; // ecx
  _BYTE *v727; // edi
  int v728; // eax
  unsigned int v729; // eax
  int v730; // edx
  unsigned int v731; // eax
  int v732; // esi
  int v733; // edx
  __int16 v734; // cx
  int v735; // edx
  __int16 v736; // cx
  int v737; // edx
  __int16 v738; // cx
  int v739; // edx
  __int16 v740; // cx
  int v741; // edx
  __int16 v742; // cx
  int v743; // edx
  __int16 v744; // cx
  int v745; // edx
  __int16 v746; // cx
  int v747; // edx
  __int16 v748; // cx
  int v749; // edx
  __int16 v750; // cx
  int v751; // edx
  __int16 v752; // cx
  int v753; // edx
  __int16 v754; // cx
  int v755; // edx
  __int16 v756; // cx
  int v757; // edx
  __int16 v758; // cx
  int v759; // edx
  __int16 v760; // cx
  int v761; // edx
  __int16 v762; // cx
  unsigned __int16 *v763; // esi
  unsigned int v764; // eax
  int v765; // ebx
  int v766; // ecx
  _BYTE *v767; // edi
  int v768; // ecx
  int v769; // edx
  int v770; // ecx
  int v771; // esi
  int v772; // edx
  int v773; // ecx
  int v774; // edx
  int v775; // ecx
  int v776; // edx
  int v777; // ecx
  int v778; // edx
  int v779; // ecx
  int v780; // edx
  int v781; // ecx
  int v782; // edx
  int v783; // ecx
  int v784; // edx
  int v785; // ecx
  int v786; // edx
  int v787; // ecx
  int v788; // edx
  int v789; // ecx
  int v790; // edx
  int v791; // ecx
  int v792; // edx
  int v793; // ecx
  int v794; // edx
  int v795; // ecx
  int v796; // edx
  int v797; // ecx
  int v798; // edx
  int v799; // ecx
  int v800; // edx
  int v801; // ecx
  unsigned __int16 *v802; // esi
  unsigned int v803; // eax
  int v804; // ebx
  int v805; // ecx
  _BYTE *v806; // edi
  int v807; // ecx
  int v808; // edx
  int v809; // ecx
  int v810; // esi
  int v811; // edx
  int v812; // ecx
  int v813; // edx
  int v814; // ecx
  int v815; // edx
  int v816; // ecx
  int v817; // edx
  int v818; // ecx
  int v819; // edx
  int v820; // ecx
  int v821; // edx
  int v822; // ecx
  int v823; // edx
  int v824; // ecx
  int v825; // edx
  int v826; // ecx
  int v827; // edx
  int v828; // ecx
  int v829; // edx
  int v830; // ecx
  int v831; // edx
  int v832; // ecx
  int v833; // edx
  int v834; // ecx
  int v835; // edx
  int v836; // ecx
  int v837; // edx
  int v838; // ecx
  int v839; // edx
  int v840; // ecx
  unsigned __int16 *v841; // esi
  int v842; // eax
  int v843; // ebx
  int v844; // ecx
  _BYTE *v845; // edi
  int v846; // eax
  unsigned int v847; // eax
  int v848; // edx
  unsigned int v849; // eax
  int v850; // esi
  int v851; // edx
  __int16 v852; // cx
  int v853; // edx
  __int16 v854; // cx
  int v855; // edx
  __int16 v856; // cx
  int v857; // edx
  __int16 v858; // cx
  int v859; // edx
  __int16 v860; // cx
  int v861; // edx
  __int16 v862; // cx
  int v863; // edx
  __int16 v864; // cx
  int v865; // edx
  __int16 v866; // cx
  int v867; // edx
  __int16 v868; // cx
  int v869; // edx
  __int16 v870; // cx
  int v871; // edx
  __int16 v872; // cx
  int v873; // edx
  __int16 v874; // cx
  int v875; // edx
  __int16 v876; // cx
  int v877; // edx
  __int16 v878; // cx
  int v879; // edx
  __int16 v880; // cx
  unsigned __int16 *v881; // esi
  int v882; // eax
  int v883; // ebx
  int v884; // ecx
  _BYTE *v885; // edi
  int v886; // eax
  unsigned int v887; // eax
  int v888; // edx
  unsigned int v889; // eax
  int v890; // esi
  int v891; // edx
  __int16 v892; // cx
  int v893; // edx
  __int16 v894; // cx
  int v895; // edx
  __int16 v896; // cx
  int v897; // edx
  __int16 v898; // cx
  int v899; // edx
  __int16 v900; // cx
  int v901; // edx
  __int16 v902; // cx
  int v903; // edx
  __int16 v904; // cx
  int v905; // edx
  __int16 v906; // cx
  int v907; // edx
  __int16 v908; // cx
  int v909; // edx
  __int16 v910; // cx
  int v911; // edx
  __int16 v912; // cx
  int v913; // edx
  __int16 v914; // cx
  int v915; // edx
  __int16 v916; // cx
  int v917; // edx
  __int16 v918; // cx
  int v919; // edx
  __int16 v920; // cx
  unsigned __int16 *v921; // esi
  unsigned int v922; // eax
  int v923; // ebx
  int v924; // ecx
  _BYTE *v925; // edi
  int v926; // ecx
  int v927; // edx
  int v928; // ecx
  int v929; // esi
  int v930; // edx
  int v931; // ecx
  int v932; // edx
  int v933; // ecx
  int v934; // edx
  int v935; // ecx
  int v936; // edx
  int v937; // ecx
  int v938; // edx
  int v939; // ecx
  int v940; // edx
  int v941; // ecx
  int v942; // edx
  int v943; // ecx
  int v944; // edx
  int v945; // ecx
  int v946; // edx
  int v947; // ecx
  int v948; // edx
  int v949; // ecx
  int v950; // edx
  int v951; // ecx
  int v952; // edx
  int v953; // ecx
  int v954; // edx
  int v955; // ecx
  int v956; // edx
  int v957; // ecx
  int v958; // edx
  int v959; // ecx
  unsigned __int16 *v960; // esi
  unsigned int v961; // eax
  int v962; // ebx
  int v963; // ecx
  _BYTE *v964; // edi
  int v965; // ecx
  int v966; // edx
  int v967; // ecx
  int v968; // esi
  int v969; // edx
  int v970; // ecx
  int v971; // edx
  int v972; // ecx
  int v973; // edx
  int v974; // ecx
  int v975; // edx
  int v976; // ecx
  int v977; // edx
  int v978; // ecx
  int v979; // edx
  int v980; // ecx
  int v981; // edx
  int v982; // ecx
  int v983; // edx
  int v984; // ecx
  int v985; // edx
  int v986; // ecx
  int v987; // edx
  int v988; // ecx
  int v989; // edx
  int v990; // ecx
  int v991; // edx
  int v992; // ecx
  int v993; // edx
  int v994; // ecx
  int v995; // edx
  int v996; // ecx
  int v997; // edx
  int v998; // ecx
  unsigned __int16 *v999; // esi
  unsigned int v1000; // eax
  int v1001; // ebx
  int v1002; // ecx
  _BYTE *v1003; // edi
  int v1004; // ecx
  int v1005; // edx
  int v1006; // ecx
  int v1007; // esi
  char v1008; // al
  int v1009; // edx
  int v1010; // ecx
  char v1011; // al
  int v1012; // edx
  int v1013; // ecx
  char v1014; // al
  int v1015; // edx
  int v1016; // ecx
  char v1017; // al
  int v1018; // edx
  int v1019; // ecx
  char v1020; // al
  int v1021; // edx
  int v1022; // ecx
  char v1023; // al
  int v1024; // edx
  int v1025; // ecx
  char v1026; // al
  int v1027; // edx
  int v1028; // ecx
  char v1029; // al
  int v1030; // edx
  int v1031; // ecx
  char v1032; // al
  int v1033; // edx
  int v1034; // ecx
  char v1035; // al
  int v1036; // edx
  int v1037; // ecx
  char v1038; // al
  int v1039; // edx
  int v1040; // ecx
  char v1041; // al
  int v1042; // edx
  int v1043; // ecx
  char v1044; // al
  int v1045; // edx
  int v1046; // ecx
  char v1047; // al
  int v1048; // edx
  int v1049; // ecx
  char v1050; // al
  int v1051; // edx
  int v1052; // ecx
  char v1053; // al
  int v1054; // [esp+0h] [ebp-88h]
  int v1055; // [esp+4h] [ebp-84h]
  int v1056; // [esp+4h] [ebp-84h]
  int v1057; // [esp+4h] [ebp-84h]
  int v1058; // [esp+4h] [ebp-84h]
  int v1059; // [esp+8h] [ebp-80h]
  int v1060; // [esp+8h] [ebp-80h]
  int v1061; // [esp+8h] [ebp-80h]
  int v1062; // [esp+8h] [ebp-80h]
  int v1063; // [esp+Ch] [ebp-7Ch]
  int v1064; // [esp+Ch] [ebp-7Ch]
  int v1065; // [esp+10h] [ebp-78h]
  int v1066; // [esp+10h] [ebp-78h]
  int v1067; // [esp+10h] [ebp-78h]
  int v1068; // [esp+10h] [ebp-78h]
  int v1069; // [esp+14h] [ebp-74h]
  int v1070; // [esp+14h] [ebp-74h]
  int v1071; // [esp+18h] [ebp-70h]
  int v1072; // [esp+18h] [ebp-70h]
  int v1073; // [esp+1Ch] [ebp-6Ch]
  int v1074; // [esp+1Ch] [ebp-6Ch]
  int v1075; // [esp+20h] [ebp-68h]
  int v1076; // [esp+24h] [ebp-64h]
  int v1077; // [esp+28h] [ebp-60h]
  int v1078; // [esp+2Ch] [ebp-5Ch]
  int v1079; // [esp+30h] [ebp-58h]
  int v1080; // [esp+30h] [ebp-58h]
  int v1081; // [esp+30h] [ebp-58h]
  int v1082; // [esp+30h] [ebp-58h]
  int v1083; // [esp+30h] [ebp-58h]
  int v1084; // [esp+30h] [ebp-58h]
  int v1085; // [esp+30h] [ebp-58h]
  int v1086; // [esp+30h] [ebp-58h]
  int v1087; // [esp+34h] [ebp-54h]
  int v1088; // [esp+34h] [ebp-54h]
  int v1089; // [esp+34h] [ebp-54h]
  int v1090; // [esp+34h] [ebp-54h]
  int v1091; // [esp+34h] [ebp-54h]
  int v1092; // [esp+34h] [ebp-54h]
  int v1093; // [esp+34h] [ebp-54h]
  int v1094; // [esp+34h] [ebp-54h]
  int v1095; // [esp+38h] [ebp-50h]
  int v1096; // [esp+38h] [ebp-50h]
  int v1097; // [esp+38h] [ebp-50h]
  int v1098; // [esp+38h] [ebp-50h]
  int v1099; // [esp+38h] [ebp-50h]
  int v1100; // [esp+38h] [ebp-50h]
  int v1101; // [esp+38h] [ebp-50h]
  int v1102; // [esp+38h] [ebp-50h]
  int v1103; // [esp+3Ch] [ebp-4Ch]
  int v1104; // [esp+3Ch] [ebp-4Ch]
  int v1105; // [esp+40h] [ebp-48h]
  int v1106; // [esp+40h] [ebp-48h]
  int v1107; // [esp+44h] [ebp-44h]
  int v1108; // [esp+44h] [ebp-44h]
  int v1109; // [esp+48h] [ebp-40h]
  int v1110; // [esp+48h] [ebp-40h]
  int v1111; // [esp+48h] [ebp-40h]
  int v1112; // [esp+48h] [ebp-40h]
  int v1113; // [esp+48h] [ebp-40h]
  int v1114; // [esp+48h] [ebp-40h]
  int v1115; // [esp+48h] [ebp-40h]
  int v1116; // [esp+48h] [ebp-40h]
  int v1117; // [esp+48h] [ebp-40h]
  int v1118; // [esp+48h] [ebp-40h]
  int v1119; // [esp+48h] [ebp-40h]
  int v1120; // [esp+48h] [ebp-40h]
  int v1121; // [esp+48h] [ebp-40h]
  int v1122; // [esp+48h] [ebp-40h]
  int v1123; // [esp+48h] [ebp-40h]
  int v1124; // [esp+48h] [ebp-40h]
  int v1125; // [esp+4Ch] [ebp-3Ch]
  int v1126; // [esp+4Ch] [ebp-3Ch]
  int v1127; // [esp+4Ch] [ebp-3Ch]
  int v1128; // [esp+4Ch] [ebp-3Ch]
  int v1129; // [esp+4Ch] [ebp-3Ch]
  int v1130; // [esp+4Ch] [ebp-3Ch]
  int v1131; // [esp+4Ch] [ebp-3Ch]
  int v1132; // [esp+4Ch] [ebp-3Ch]
  int v1133; // [esp+4Ch] [ebp-3Ch]
  int v1134; // [esp+4Ch] [ebp-3Ch]
  int v1135; // [esp+4Ch] [ebp-3Ch]
  int v1136; // [esp+4Ch] [ebp-3Ch]
  int v1137; // [esp+4Ch] [ebp-3Ch]
  int v1138; // [esp+4Ch] [ebp-3Ch]
  int v1139; // [esp+4Ch] [ebp-3Ch]
  int v1140; // [esp+4Ch] [ebp-3Ch]
  int v1141; // [esp+4Ch] [ebp-3Ch]
  int v1142; // [esp+4Ch] [ebp-3Ch]
  int v1143; // [esp+50h] [ebp-38h]
  int v1144; // [esp+50h] [ebp-38h]
  int v1145; // [esp+50h] [ebp-38h]
  int v1146; // [esp+50h] [ebp-38h]
  int v1147; // [esp+50h] [ebp-38h]
  int v1148; // [esp+50h] [ebp-38h]
  int v1149; // [esp+50h] [ebp-38h]
  int v1150; // [esp+54h] [ebp-34h]
  int v1151; // [esp+54h] [ebp-34h]
  int v1152; // [esp+54h] [ebp-34h]
  int v1153; // [esp+54h] [ebp-34h]
  int v1154; // [esp+58h] [ebp-30h]
  int v1155; // [esp+58h] [ebp-30h]
  int v1156; // [esp+58h] [ebp-30h]
  int v1157; // [esp+58h] [ebp-30h]
  int v1158; // [esp+58h] [ebp-30h]
  int v1159; // [esp+58h] [ebp-30h]
  int v1160; // [esp+58h] [ebp-30h]
  int v1161; // [esp+58h] [ebp-30h]
  int v1162; // [esp+58h] [ebp-30h]
  int v1163; // [esp+58h] [ebp-30h]
  int v1164; // [esp+58h] [ebp-30h]
  int v1165; // [esp+58h] [ebp-30h]
  int v1166; // [esp+58h] [ebp-30h]
  int v1167; // [esp+58h] [ebp-30h]
  int v1168; // [esp+58h] [ebp-30h]
  int v1169; // [esp+58h] [ebp-30h]
  int v1170; // [esp+58h] [ebp-30h]
  int v1171; // [esp+58h] [ebp-30h]
  int v1172; // [esp+58h] [ebp-30h]
  int v1173; // [esp+58h] [ebp-30h]
  int v1174; // [esp+58h] [ebp-30h]
  int v1175; // [esp+58h] [ebp-30h]
  int v1176; // [esp+58h] [ebp-30h]
  int v1177; // [esp+58h] [ebp-30h]
  int v1178; // [esp+58h] [ebp-30h]
  int v1179; // [esp+58h] [ebp-30h]
  int v1180; // [esp+58h] [ebp-30h]
  int v1181; // [esp+58h] [ebp-30h]
  int v1182; // [esp+58h] [ebp-30h]
  int v1183; // [esp+58h] [ebp-30h]
  int v1184; // [esp+58h] [ebp-30h]
  int v1185; // [esp+58h] [ebp-30h]
  int v1186; // [esp+58h] [ebp-30h]
  int v1187; // [esp+58h] [ebp-30h]
  int v1188; // [esp+58h] [ebp-30h]
  int v1189; // [esp+58h] [ebp-30h]
  int v1190; // [esp+58h] [ebp-30h]
  int v1191; // [esp+58h] [ebp-30h]
  int v1192; // [esp+58h] [ebp-30h]
  int v1193; // [esp+58h] [ebp-30h]
  int v1194; // [esp+58h] [ebp-30h]
  int v1195; // [esp+58h] [ebp-30h]
  int v1196; // [esp+58h] [ebp-30h]
  int v1197; // [esp+58h] [ebp-30h]
  int v1198; // [esp+58h] [ebp-30h]
  int v1199; // [esp+58h] [ebp-30h]
  int v1200; // [esp+58h] [ebp-30h]
  int v1201; // [esp+58h] [ebp-30h]
  int v1202; // [esp+58h] [ebp-30h]
  int v1203; // [esp+58h] [ebp-30h]
  int v1204; // [esp+58h] [ebp-30h]
  int v1205; // [esp+58h] [ebp-30h]
  int v1206; // [esp+58h] [ebp-30h]
  int v1207; // [esp+58h] [ebp-30h]
  int v1208; // [esp+58h] [ebp-30h]
  int v1209; // [esp+58h] [ebp-30h]
  int v1210; // [esp+58h] [ebp-30h]
  int v1211; // [esp+58h] [ebp-30h]
  int v1212; // [esp+58h] [ebp-30h]
  int v1213; // [esp+58h] [ebp-30h]
  int v1214; // [esp+58h] [ebp-30h]
  int v1215; // [esp+58h] [ebp-30h]
  int v1216; // [esp+58h] [ebp-30h]
  int v1217; // [esp+58h] [ebp-30h]
  int v1218; // [esp+58h] [ebp-30h]
  int v1219; // [esp+58h] [ebp-30h]
  int v1220; // [esp+58h] [ebp-30h]
  int v1221; // [esp+58h] [ebp-30h]
  int v1222; // [esp+58h] [ebp-30h]
  int v1223; // [esp+58h] [ebp-30h]
  int v1224; // [esp+58h] [ebp-30h]
  int v1225; // [esp+58h] [ebp-30h]
  int v1226; // [esp+58h] [ebp-30h]
  int v1227; // [esp+58h] [ebp-30h]
  int v1228; // [esp+58h] [ebp-30h]
  int v1229; // [esp+58h] [ebp-30h]
  int v1230; // [esp+58h] [ebp-30h]
  int v1231; // [esp+58h] [ebp-30h]
  int v1232; // [esp+58h] [ebp-30h]
  int v1233; // [esp+58h] [ebp-30h]
  unsigned __int16 *v1234; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1235; // [esp+5Ch] [ebp-2Ch]
  char *v1236; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1237; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1238; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1239; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1240; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1241; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1242; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1243; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1244; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1245; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1246; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1247; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1248; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1249; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1250; // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v1251; // [esp+5Ch] [ebp-2Ch]
  __int16 v1252; // [esp+60h] [ebp-28h]
  char v1253; // [esp+62h] [ebp-26h]
  char v1254; // [esp+62h] [ebp-26h]
  char v1255; // [esp+62h] [ebp-26h]
  char v1256; // [esp+62h] [ebp-26h]
  char v1257; // [esp+63h] [ebp-25h]
  char v1258; // [esp+63h] [ebp-25h]
  _BOOL1 v1259; // [esp+63h] [ebp-25h]
  _BOOL1 v1260; // [esp+63h] [ebp-25h]
  _BOOL1 v1261; // [esp+64h] [ebp-24h]
  _BOOL1 v1262; // [esp+64h] [ebp-24h]

  v3 = a1;
  v4 = a2;
  v5 = a3;
  v6 = a1[1];
  v7 = a2[1];
  v8 = a3[1];
  if ( v6 == v7 )
  {
    if ( v6 == v8 )
      return;
    if ( v6 >= v8 )
    {
      if ( *a1 <= *a2 )
        return;
      v3 = a3;
      v4 = a1;
      v5 = a2;
      goto LABEL_225;
    }
    if ( *a2 <= *a1 )
      return;
LABEL_268:
    v134 = v3[1];
    v1153 = v134;
    if ( v134 >= 0 )
    {
      if ( v134 >= vec_window_height )
        return;
      v1054 = dword_220C4C + vec_screen_width * v134;
      v1256 = 0;
    }
    else
    {
      v1054 = dword_220C4C;
      v1256 = 1;
    }
    v135 = v5[1];
    v1260 = v135 > vec_window_height;
    v1068 = v135 - v134;
    v1075 = v135 - v134;
    v1058 = ((*v5 - *v3) SHL16) / (v135 - v134);
    v1062 = ((*v5 - *v4) SHL16) / (v135 - v134);
    switch ( vec_mode )
    {
      case 0:
      case 14:
      case 15:
        v156 = *v3 SHL16;
        v157 = *v4 SHL16;
        if ( v1256 )
        {
          v158 = -v1153;
          v1068 += v1153;
          v16 = v1075 <= -v1153;
          v1075 += v1153;
          if ( v16 )
            return;
          v156 += v1058 * v158;
          v157 += v158 * v1062;
          if ( v1260 )
          {
            v1075 = vec_window_height;
            v1068 = vec_window_height;
          }
        }
        else if ( v1260 )
        {
          v1075 = vec_window_height - v1153;
          v1068 = vec_window_height - v1153;
        }
        v159 = &polyscans;
        do
        {
          *v159 = v156;
          v156 += v1058;
          v159[1] = v157;
          v157 += v1062;
          v159 += 5;
          --v1068;
        }
        while ( v1068 );
        v29 = (unsigned __int8)vec_mode;
        switch ( vec_mode )
        {
          case 0:
            goto LABEL_309;
          case 1:
            return;
          case 2:
            goto LABEL_322;
          case 3:
            goto LABEL_353;
          case 4:
            goto LABEL_416;
          case 5:
            goto LABEL_445;
          case 6:
            goto LABEL_474;
          case 7:
          case 11:
            goto LABEL_537;
          case 8:
            goto LABEL_568;
          case 9:
          case 10:
            goto LABEL_631;
          case 12:
            goto LABEL_694;
          case 13:
            goto LABEL_725;
          case 14:
            goto LABEL_756;
          case 15:
            goto LABEL_785;
          case 16:
            goto LABEL_814;
          case 17:
            goto LABEL_843;
          case 18:
            goto LABEL_872;
          case 19:
            goto LABEL_903;
          case 20:
            goto LABEL_934;
          case 21:
            goto LABEL_965;
          case 22:
            goto LABEL_996;
          case 23:
            goto LABEL_1059;
          case 24:
            goto LABEL_1122;
          case 25:
            goto LABEL_1185;
          case 26:
            goto LABEL_1248;
        }
        return;
      case 1:
      case 4:
      case 16:
      case 17:
        v1078 = (v4[4] - v3[4]) / (*v4 - *v3);
        v1102 = (v5[4] - v3[4]) / v1075;
        v151 = *v3 SHL16;
        v152 = *v4 SHL16;
        v153 = v3[4];
        if ( v1256 )
        {
          v154 = -v1153;
          v1068 += v1153;
          v16 = v1075 <= -v1153;
          v1075 += v1153;
          if ( v16 )
            return;
          v151 += v1058 * v154;
          v152 += v154 * v1062;
          v153 += v154 * v1102;
          if ( v1260 )
          {
            v1075 = vec_window_height;
            v1068 = vec_window_height;
          }
        }
        else if ( v1260 )
        {
          v1075 = vec_window_height - v1153;
          v1068 = vec_window_height - v1153;
        }
        v155 = &polyscans;
        do
        {
          *v155 = v151;
          v151 += v1058;
          v155[1] = v152;
          v152 += v1062;
          v155[4] = v153;
          v153 += v1102;
          v155 += 5;
          --v1068;
        }
        while ( v1068 );
        v29 = (unsigned __int8)vec_mode;
        switch ( vec_mode )
        {
          case 0:
            goto LABEL_309;
          case 1:
            return;
          case 2:
            goto LABEL_322;
          case 3:
            goto LABEL_353;
          case 4:
            goto LABEL_416;
          case 5:
            goto LABEL_445;
          case 6:
            goto LABEL_474;
          case 7:
          case 11:
            goto LABEL_537;
          case 8:
            goto LABEL_568;
          case 9:
          case 10:
            goto LABEL_631;
          case 12:
            goto LABEL_694;
          case 13:
            goto LABEL_725;
          case 14:
            goto LABEL_756;
          case 15:
            goto LABEL_785;
          case 16:
            goto LABEL_814;
          case 17:
            goto LABEL_843;
          case 18:
            goto LABEL_872;
          case 19:
            goto LABEL_903;
          case 20:
            goto LABEL_934;
          case 21:
            goto LABEL_965;
          case 22:
            goto LABEL_996;
          case 23:
            goto LABEL_1059;
          case 24:
            goto LABEL_1122;
          case 25:
            goto LABEL_1185;
          case 26:
            goto LABEL_1248;
        }
        return;
      case 2:
      case 3:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 18:
      case 19:
      case 22:
      case 23:
        v144 = *v4 - *v3;
        v1076 = (v4[2] - v3[2]) / v144;
        v1077 = (v4[3] - v3[3]) / v144;
        v1086 = (v5[2] - v3[2]) / v1075;
        v1094 = (v5[3] - v3[3]) / v1075;
        v145 = *v3 SHL16;
        v146 = *v4 SHL16;
        v147 = v3[2];
        v148 = v3[3];
        if ( v1256 )
        {
          v149 = -v1153;
          v1068 += v1153;
          v16 = v1075 <= -v1153;
          v1075 += v1153;
          if ( v16 )
            return;
          v145 += v1058 * v149;
          v146 += v149 * v1062;
          v147 += v149 * v1086;
          v148 += v149 * v1094;
          if ( v1260 )
          {
            v1075 = vec_window_height;
            v1068 = vec_window_height;
          }
        }
        else if ( v1260 )
        {
          v1075 = vec_window_height - v1153;
          v1068 = vec_window_height - v1153;
        }
        v150 = &polyscans;
        do
        {
          *v150 = v145;
          v145 += v1058;
          v150[1] = v146;
          v146 += v1062;
          v150[2] = v147;
          v147 += v1086;
          v150[3] = v148;
          v148 += v1094;
          v150 += 5;
          --v1068;
        }
        while ( v1068 );
        v29 = (unsigned __int8)vec_mode;
        switch ( vec_mode )
        {
          case 0:
            goto LABEL_309;
          case 1:
            return;
          case 2:
            goto LABEL_322;
          case 3:
            goto LABEL_353;
          case 4:
            goto LABEL_416;
          case 5:
            goto LABEL_445;
          case 6:
            goto LABEL_474;
          case 7:
          case 11:
            goto LABEL_537;
          case 8:
            goto LABEL_568;
          case 9:
          case 10:
            goto LABEL_631;
          case 12:
            goto LABEL_694;
          case 13:
            goto LABEL_725;
          case 14:
            goto LABEL_756;
          case 15:
            goto LABEL_785;
          case 16:
            goto LABEL_814;
          case 17:
            goto LABEL_843;
          case 18:
            goto LABEL_872;
          case 19:
            goto LABEL_903;
          case 20:
            goto LABEL_934;
          case 21:
            goto LABEL_965;
          case 22:
            goto LABEL_996;
          case 23:
            goto LABEL_1059;
          case 24:
            goto LABEL_1122;
          case 25:
            goto LABEL_1185;
          case 26:
            goto LABEL_1248;
        }
        return;
      case 5:
      case 6:
      case 20:
      case 21:
      case 24:
      case 25:
      case 26:
        v136 = *v4 - *v3;
        v1076 = (v4[2] - v3[2]) / v136;
        v1077 = (v4[3] - v3[3]) / v136;
        v1078 = (v4[4] - v3[4]) / v136;
        v1085 = (v5[2] - v3[2]) / v1075;
        v1093 = (v5[3] - v3[3]) / v1075;
        v1101 = (v5[4] - v3[4]) / v1075;
        v137 = *v3 SHL16;
        v138 = *v4 SHL16;
        v139 = v3[2];
        v140 = v3[3];
        v141 = v3[4];
        if ( v1256 )
        {
          v142 = -v1153;
          v1068 += v1153;
          v16 = v1075 <= -v1153;
          v1075 += v1153;
          if ( v16 )
            return;
          v137 += v1058 * v142;
          v138 += v142 * v1062;
          v139 += v142 * v1085;
          v140 += v142 * v1093;
          v141 += v142 * v1101;
          if ( v1260 )
          {
            v1075 = vec_window_height;
            v1068 = vec_window_height;
          }
        }
        else if ( v1260 )
        {
          v1075 = vec_window_height - v1153;
          v1068 = vec_window_height - v1153;
        }
        v143 = &polyscans;
        do
        {
          *v143 = v137;
          v137 += v1058;
          v143[1] = v138;
          v138 += v1062;
          v143[2] = v139;
          v139 += v1085;
          v143[3] = v140;
          v140 += v1093;
          v143[4] = v141;
          v141 += v1101;
          v143 += 5;
          --v1068;
        }
        while ( v1068 );
        break;
    }
    v29 = (unsigned __int8)vec_mode;
    switch ( vec_mode )
    {
      case 0:
LABEL_309:
        v160 = (unsigned __int16 *)&polyscans;
        v161 = (char *)v1054;
        v162 = vec_colour;
        HIWORD(v163) = 0;
        while ( 1 )
        {
          LOWORD(v163) = v160[1];
          v164 = v160[3];
          v161 += vec_screen_width;
          if ( (v163 & 0x8000u) == 0 )
            break;
          if ( (__int16)v164 > 0 )
          {
            if ( v164 > vec_window_width )
              v164 = vec_window_width;
            v165 = v161;
LABEL_319:
            memset(v165, v162, v164);
          }
LABEL_320:
          v160 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v164 > vec_window_width )
          v164 = vec_window_width;
        v16 = (__int16)v164 <= (__int16)v163;
        LOWORD(v164) = v164 - v163;
        if ( v16 )
          goto LABEL_320;
        v165 = &v161[v163];
        goto LABEL_319;
      case 1:
        return;
      case 2:
LABEL_322:
        v166 = (unsigned __int16 *)&polyscans;
        v1125 = v1077 SHL16;
        HIWORD(v167) = 0;
        HIWORD(v168) = 0;
        while ( 1 )
        {
          LOWORD(v167) = v166[1];
          v169 = v166[3];
          v170 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v167 & 0x8000u) == 0 )
            break;
          if ( (__int16)v169 > 0 )
          {
            v171 = (unsigned __int16)-(__int16)v167;
            v173 = __ROL4__(*((int *)v166 + 3) + v1077 * v171, 16);
            BYTE1(v168) = v173;
            v172 = *((int *)v166 + 2) + v1076 * v171;
            LOWORD(v173) = v172;
            v174 = v172 >> 8;
            LOBYTE(v168) = BYTE1(v174);
            if ( v169 > vec_window_width )
              LOWORD(v169) = vec_window_width;
            v167 = (unsigned __int16)v174;
LABEL_332:
            v1234 = v166;
            v175 = vec_map;
            while ( 1 )
            {
              v176 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v173);
              LOWORD(v173) = v1076 + v173;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              *v170 = v176;
              v177 = __CFADD__(v1125, v173);
              v178 = v1125 + v173;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v179 = v169 - 1;
              if ( !v179 )
                break;
              v180 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v178);
              LOWORD(v178) = v1076 + v178;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[1] = v180;
              v177 = __CFADD__(v1125, v178);
              v181 = v1125 + v178;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v182 = v179 - 1;
              if ( !v182 )
                break;
              v183 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v181);
              LOWORD(v181) = v1076 + v181;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[2] = v183;
              v177 = __CFADD__(v1125, v181);
              v184 = v1125 + v181;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v185 = v182 - 1;
              if ( !v185 )
                break;
              v186 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v184);
              LOWORD(v184) = v1076 + v184;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[3] = v186;
              v177 = __CFADD__(v1125, v184);
              v187 = v1125 + v184;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v188 = v185 - 1;
              if ( !v188 )
                break;
              v189 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v187);
              LOWORD(v187) = v1076 + v187;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[4] = v189;
              v177 = __CFADD__(v1125, v187);
              v190 = v1125 + v187;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v191 = v188 - 1;
              if ( !v191 )
                break;
              v192 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v190);
              LOWORD(v190) = v1076 + v190;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[5] = v192;
              v177 = __CFADD__(v1125, v190);
              v193 = v1125 + v190;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v194 = v191 - 1;
              if ( !v194 )
                break;
              v195 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v193);
              LOWORD(v193) = v1076 + v193;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[6] = v195;
              v177 = __CFADD__(v1125, v193);
              v196 = v1125 + v193;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v197 = v194 - 1;
              if ( !v197 )
                break;
              v198 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v196);
              LOWORD(v196) = v1076 + v196;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[7] = v198;
              v177 = __CFADD__(v1125, v196);
              v199 = v1125 + v196;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v200 = v197 - 1;
              if ( !v200 )
                break;
              v201 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v199);
              LOWORD(v199) = v1076 + v199;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[8] = v201;
              v177 = __CFADD__(v1125, v199);
              v202 = v1125 + v199;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v203 = v200 - 1;
              if ( !v203 )
                break;
              v204 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v202);
              LOWORD(v202) = v1076 + v202;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[9] = v204;
              v177 = __CFADD__(v1125, v202);
              v205 = v1125 + v202;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v206 = v203 - 1;
              if ( !v206 )
                break;
              v207 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v205);
              LOWORD(v205) = v1076 + v205;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[10] = v207;
              v177 = __CFADD__(v1125, v205);
              v208 = v1125 + v205;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v209 = v206 - 1;
              if ( !v209 )
                break;
              v210 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v208);
              LOWORD(v208) = v1076 + v208;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[11] = v210;
              v177 = __CFADD__(v1125, v208);
              v211 = v1125 + v208;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v212 = v209 - 1;
              if ( !v212 )
                break;
              v213 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v211);
              LOWORD(v211) = v1076 + v211;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[12] = v213;
              v177 = __CFADD__(v1125, v211);
              v214 = v1125 + v211;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v215 = v212 - 1;
              if ( !v215 )
                break;
              v216 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v214);
              LOWORD(v214) = v1076 + v214;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[13] = v216;
              v177 = __CFADD__(v1125, v214);
              v217 = v1125 + v214;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v218 = v215 - 1;
              if ( !v218 )
                break;
              v219 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v217);
              LOWORD(v217) = v1076 + v217;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[14] = v219;
              v177 = __CFADD__(v1125, v217);
              v220 = v1125 + v217;
              BYTE1(v168) += BYTE2(v1077) + v177;
              v221 = v218 - 1;
              if ( !v221 )
                break;
              v222 = *(_BYTE *)(v168 + v175);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v220);
              LOWORD(v220) = v1076 + v220;
              LOBYTE(v168) = BYTE2(v1076) + v177 + v168;
              v170[15] = v222;
              v177 = __CFADD__(v1125, v220);
              v173 = v1125 + v220;
              BYTE1(v168) += BYTE2(v1077) + v177;
              LOWORD(v169) = v221 - 1;
              if ( !(_WORD)v169 )
                break;
              v170 += 16;
            }
            v166 = v1234;
          }
LABEL_351:
          v166 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v169 > vec_window_width )
          LOWORD(v169) = vec_window_width;
        v16 = (__int16)v169 <= (__int16)v167;
        LOWORD(v169) = v169 - v167;
        if ( v16 )
          goto LABEL_351;
        v170 += v167;
        v173 = __ROL4__(*((int *)v166 + 3), 16);
        BYTE1(v168) = v173;
        LOWORD(v173) = v166[4];
        LOBYTE(v168) = *((_BYTE *)v166 + 10);
        goto LABEL_332;
      case 3:
LABEL_353:
        v223 = (unsigned __int16 *)&polyscans;
        v1126 = v1077 SHL16;
        HIWORD(v224) = 0;
        HIWORD(v225) = 0;
        while ( 1 )
        {
          LOWORD(v224) = v223[1];
          v226 = v223[3];
          v227 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v224 & 0x8000u) == 0 )
            break;
          if ( (__int16)v226 > 0 )
          {
            v228 = (unsigned __int16)-(__int16)v224;
            v230 = __ROL4__(*((int *)v223 + 3) + v1077 * v228, 16);
            BYTE1(v225) = v230;
            v229 = *((int *)v223 + 2) + v1076 * v228;
            LOWORD(v230) = v229;
            v231 = v229 >> 8;
            LOBYTE(v225) = BYTE1(v231);
            if ( v226 > vec_window_width )
              LOWORD(v226) = vec_window_width;
            v224 = (unsigned __int16)v231;
LABEL_363:
            v1235 = v223;
            v232 = vec_map;
            while ( 1 )
            {
              v233 = *(_BYTE *)(v225 + v232);
              if ( v233 )
                *v227 = v233;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v230);
              LOWORD(v230) = v1076 + v230;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v230);
              v234 = v1126 + v230;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v235 = v226 - 1;
              if ( !v235 )
                break;
              v236 = *(_BYTE *)(v225 + v232);
              if ( v236 )
                v227[1] = v236;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v234);
              LOWORD(v234) = v1076 + v234;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v234);
              v237 = v1126 + v234;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v238 = v235 - 1;
              if ( !v238 )
                break;
              v239 = *(_BYTE *)(v225 + v232);
              if ( v239 )
                v227[2] = v239;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v237);
              LOWORD(v237) = v1076 + v237;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v237);
              v240 = v1126 + v237;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v241 = v238 - 1;
              if ( !v241 )
                break;
              v242 = *(_BYTE *)(v225 + v232);
              if ( v242 )
                v227[3] = v242;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v240);
              LOWORD(v240) = v1076 + v240;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v240);
              v243 = v1126 + v240;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v244 = v241 - 1;
              if ( !v244 )
                break;
              v245 = *(_BYTE *)(v225 + v232);
              if ( v245 )
                v227[4] = v245;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v243);
              LOWORD(v243) = v1076 + v243;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v243);
              v246 = v1126 + v243;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v247 = v244 - 1;
              if ( !v247 )
                break;
              v248 = *(_BYTE *)(v225 + v232);
              if ( v248 )
                v227[5] = v248;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v246);
              LOWORD(v246) = v1076 + v246;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v246);
              v249 = v1126 + v246;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v250 = v247 - 1;
              if ( !v250 )
                break;
              v251 = *(_BYTE *)(v225 + v232);
              if ( v251 )
                v227[6] = v251;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v249);
              LOWORD(v249) = v1076 + v249;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v249);
              v252 = v1126 + v249;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v253 = v250 - 1;
              if ( !v253 )
                break;
              v254 = *(_BYTE *)(v225 + v232);
              if ( v254 )
                v227[7] = v254;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v252);
              LOWORD(v252) = v1076 + v252;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v252);
              v255 = v1126 + v252;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v256 = v253 - 1;
              if ( !v256 )
                break;
              v257 = *(_BYTE *)(v225 + v232);
              if ( v257 )
                v227[8] = v257;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v255);
              LOWORD(v255) = v1076 + v255;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v255);
              v258 = v1126 + v255;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v259 = v256 - 1;
              if ( !v259 )
                break;
              v260 = *(_BYTE *)(v225 + v232);
              if ( v260 )
                v227[9] = v260;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v258);
              LOWORD(v258) = v1076 + v258;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v258);
              v261 = v1126 + v258;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v262 = v259 - 1;
              if ( !v262 )
                break;
              v263 = *(_BYTE *)(v225 + v232);
              if ( v263 )
                v227[10] = v263;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v261);
              LOWORD(v261) = v1076 + v261;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v261);
              v264 = v1126 + v261;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v265 = v262 - 1;
              if ( !v265 )
                break;
              v266 = *(_BYTE *)(v225 + v232);
              if ( v266 )
                v227[11] = v266;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v264);
              LOWORD(v264) = v1076 + v264;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v264);
              v267 = v1126 + v264;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v268 = v265 - 1;
              if ( !v268 )
                break;
              v269 = *(_BYTE *)(v225 + v232);
              if ( v269 )
                v227[12] = v269;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v267);
              LOWORD(v267) = v1076 + v267;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v267);
              v270 = v1126 + v267;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v271 = v268 - 1;
              if ( !v271 )
                break;
              v272 = *(_BYTE *)(v225 + v232);
              if ( v272 )
                v227[13] = v272;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v270);
              LOWORD(v270) = v1076 + v270;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v270);
              v273 = v1126 + v270;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v274 = v271 - 1;
              if ( !v274 )
                break;
              v275 = *(_BYTE *)(v225 + v232);
              if ( v275 )
                v227[14] = v275;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v273);
              LOWORD(v273) = v1076 + v273;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v273);
              v276 = v1126 + v273;
              BYTE1(v225) += BYTE2(v1077) + v177;
              v277 = v274 - 1;
              if ( !v277 )
                break;
              v278 = *(_BYTE *)(v225 + v232);
              if ( v278 )
                v227[15] = v278;
              v177 = __CFADD__((_WORD)v1076, (_WORD)v276);
              LOWORD(v276) = v1076 + v276;
              LOBYTE(v225) = BYTE2(v1076) + v177 + v225;
              v177 = __CFADD__(v1126, v276);
              v230 = v1126 + v276;
              BYTE1(v225) += BYTE2(v1077) + v177;
              LOWORD(v226) = v277 - 1;
              if ( !(_WORD)v226 )
                break;
              v227 += 16;
            }
            v223 = v1235;
          }
LABEL_414:
          v223 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v226 > vec_window_width )
          LOWORD(v226) = vec_window_width;
        v16 = (__int16)v226 <= (__int16)v224;
        LOWORD(v226) = v226 - v224;
        if ( v16 )
          goto LABEL_414;
        v227 += v224;
        v230 = __ROL4__(*((int *)v223 + 3), 16);
        BYTE1(v225) = v230;
        LOWORD(v230) = v223[4];
        LOBYTE(v225) = *((_BYTE *)v223 + 10);
        goto LABEL_363;
      case 4:
LABEL_416:
        for ( i = (_WORD*)&polyscans; ; i += 10 ) //FIX
        {
          LOWORD(v29) = i[1];
          v280 = (unsigned __int16)i[3];
          v281 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v29 & 0x8000u) == 0 )
            break;
          if ( (__int16)v280 > 0 )
          {
            v282 = v1078 * (unsigned __int16)-(__int16)v29;
            v283 = v282;
            v29 = v282 >> 8;
            v177 = __CFADD__(i[8], v283);
            v284 = i[8] + v283;
            BYTE1(v29) += *((_BYTE *)i + 18) + v177;
            if ( v280 > vec_window_width )
              LOWORD(v280) = vec_window_width;
            v29 = (unsigned __int16)v29;
            LOBYTE(v29) = vec_colour;
LABEL_426:
            while ( 1 )
            {
              *v281 = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v284);
              v285 = v1078 + v284;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v286 = v280 - 1;
              if ( !v286 )
                break;
              v281[1] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v285);
              v287 = v1078 + v285;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v288 = v286 - 1;
              if ( !v288 )
                break;
              v281[2] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v287);
              v289 = v1078 + v287;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v290 = v288 - 1;
              if ( !v290 )
                break;
              v281[3] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v289);
              v291 = v1078 + v289;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v292 = v290 - 1;
              if ( !v292 )
                break;
              v281[4] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v291);
              v293 = v1078 + v291;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v294 = v292 - 1;
              if ( !v294 )
                break;
              v281[5] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v293);
              v295 = v1078 + v293;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v296 = v294 - 1;
              if ( !v296 )
                break;
              v281[6] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v295);
              v297 = v1078 + v295;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v298 = v296 - 1;
              if ( !v298 )
                break;
              v281[7] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v297);
              v299 = v1078 + v297;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v300 = v298 - 1;
              if ( !v300 )
                break;
              v281[8] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v299);
              v301 = v1078 + v299;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v302 = v300 - 1;
              if ( !v302 )
                break;
              v281[9] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v301);
              v303 = v1078 + v301;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v304 = v302 - 1;
              if ( !v304 )
                break;
              v281[10] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v303);
              v305 = v1078 + v303;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v306 = v304 - 1;
              if ( !v306 )
                break;
              v281[11] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v305);
              v307 = v1078 + v305;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v308 = v306 - 1;
              if ( !v308 )
                break;
              v281[12] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v307);
              v309 = v1078 + v307;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v310 = v308 - 1;
              if ( !v310 )
                break;
              v281[13] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v309);
              v311 = v1078 + v309;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v312 = v310 - 1;
              if ( !v312 )
                break;
              v281[14] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v311);
              v313 = v1078 + v311;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v314 = v312 - 1;
              if ( !v314 )
                break;
              v281[15] = *(_BYTE *)(v29 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1078, v313);
              v284 = v1078 + v313;
              BYTE1(v29) += BYTE2(v1078) + v177;
              LOWORD(v280) = v314 - 1;
              if ( !(_WORD)v280 )
                break;
              v281 += 16;
            }
          }
LABEL_443:
          if ( !--v1075 )
            return;
        }
        if ( v280 > vec_window_width )
          LOWORD(v280) = vec_window_width;
        v16 = (__int16)v280 <= (__int16)v29;
        LOWORD(v280) = v280 - v29;
        if ( v16 )
          goto LABEL_443;
        v281 += v29;
        v29 = (unsigned __int8)vec_colour;
        v284 = i[8];
        BYTE1(v29) = *((_BYTE *)i + 18);
        goto LABEL_426;
      case 5:
LABEL_445:
        v1236 = (char *)&polyscans;
        v1127 = v1077 SHL16;
        v1143 = v1078 SHL16;
        HIWORD(v315) = 0;
        HIWORD(v316) = 0;
        while ( 1 )
        {
          v317 = v1236;
          v1236 += 20;
          LOWORD(v315) = *((_WORD *)v317 + 1);
          v318 = *((unsigned __int16 *)v317 + 3);
          v319 = vec_screen_width + v1054;
          v1054 += vec_screen_width;
          if ( (v315 & 0x8000u) == 0 )
            break;
          if ( (__int16)v318 > 0 )
          {
            v320 = (unsigned __int16)-(__int16)v315;
            v321 = __ROL4__(*((int *)v317 + 3) + v1077 * v320, 16);
            BYTE1(v316) = v321;
            LOWORD(v321) = *((_WORD *)v317 + 4) + v1076 * v320;
            v315 = (unsigned int)(*((int *)v317 + 2) + v1076 * v320) >> 8;
            LOBYTE(v316) = (unsigned int)(*((int *)v317 + 2) + v1076 * v320) >> 16;
            v322 = __ROL4__(*((int *)v317 + 4) + v1078 * v320, 16);
            BYTE1(v315) = v322;
            LOWORD(v322) = *((_WORD *)v317 + 3);
            v315 = (unsigned __int16)v315;
            if ( (__int16)v322 > (__int16)vec_window_width )
              LOWORD(v322) = vec_window_width;
LABEL_455:
            v325 = (_BYTE *)(dword_219523[v322 & 0xF] + v319);
            v326 = vec_map;
            switch ( v322 & 0xF )
            {
              case 0:
                goto LABEL_456;
              case 1:
                goto LABEL_471;
              case 2:
                goto LABEL_470;
              case 3:
                goto LABEL_469;
              case 4:
                goto LABEL_468;
              case 5:
                goto LABEL_467;
              case 6:
                goto LABEL_466;
              case 7:
                goto LABEL_465;
              case 8:
                goto LABEL_464;
              case 9:
                goto LABEL_463;
              case 0xA:
                goto LABEL_462;
              case 0xB:
                goto LABEL_461;
              case 0xC:
                goto LABEL_460;
              case 0xD:
                goto LABEL_459;
              case 0xE:
                goto LABEL_458;
              case 0xF:
                while ( 1 )
                {
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[1] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_458:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[2] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_459:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[3] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_460:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[4] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_461:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[5] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_462:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[6] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_463:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[7] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_464:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[8] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_465:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[9] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_466:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[10] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_467:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[11] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_468:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[12] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_469:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[13] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_470:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[14] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
LABEL_471:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  v325[15] = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
                  v325 += 16;
                  v16 = (__int16)v322 <= 16;
                  LOWORD(v322) = v322 - 16;
                  if ( v16 )
                    break;
LABEL_456:
                  v177 = __CFADD__((_WORD)v1076, (_WORD)v321);
                  LOWORD(v321) = v1076 + v321;
                  LOBYTE(v315) = *(_BYTE *)(v316 + v326);
                  LOBYTE(v316) = BYTE2(v1076) + v177 + v316;
                  v177 = __CFADD__(v1127, v321);
                  v321 += v1127;
                  BYTE1(v316) += BYTE2(v1077) + v177;
                  *v325 = *(_BYTE *)(v315 + ((u32) tables_start));
                  v177 = __CFADD__(v1143, v322);
                  v322 += v1143;
                  BYTE1(v315) += BYTE2(v1078) + v177;
                }
                break;
            }
          }
LABEL_472:
          if ( !--v1075 )
            return;
        }
        if ( v318 > vec_window_width )
          LOWORD(v318) = vec_window_width;
        v16 = (__int16)v318 <= (__int16)v315;
        v323 = v318 - v315;
        if ( v16 )
          goto LABEL_472;
        v319 += v315;
        LOBYTE(v316) = v317[10];
        v321 = __ROL4__(*((int *)v317 + 3), 16);
        v324 = v323;
        BYTE1(v316) = v321;
        LOWORD(v321) = *((_WORD *)v317 + 4);
        v322 = __ROL4__(*((int *)v317 + 4), 16);
        BYTE1(v315) = v322;
        LOWORD(v322) = v324;
        goto LABEL_455;
      case 6:
LABEL_474:
        v327 = (unsigned __int16 *)&polyscans;
        v1128 = v1077 SHL16;
        v1144 = v1078 SHL16;
        HIWORD(v328) = 0;
        HIWORD(v329) = 0;
        while ( 1 )
        {
          LOWORD(v328) = v327[1];
          v330 = v327[3];
          v331 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v328 & 0x8000u) == 0 )
            break;
          if ( (__int16)v330 > 0 )
          {
            v332 = (unsigned __int16)-(__int16)v328;
            v333 = __ROL4__(*((int *)v327 + 3) + v1077 * v332, 16);
            BYTE1(v329) = v333;
            LOWORD(v333) = v327[4] + v1076 * v332;
            v328 = (unsigned int)(*((int *)v327 + 2) + v1076 * v332) >> 8;
            LOBYTE(v329) = (unsigned int)(*((int *)v327 + 2) + v1076 * v332) >> 16;
            v334 = __ROL4__(*((int *)v327 + 4) + v1078 * v332, 16);
            BYTE1(v328) = v334;
            LOWORD(v334) = v327[3];
            if ( v334 > vec_window_width )
              v334 = vec_window_width;
            v328 = (unsigned __int16)v328;
LABEL_484:
            v1237 = v327;
            v336 = vec_map;
            while ( 1 )
            {
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                *v331 = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v333);
              LOWORD(v333) = v1076 + v333;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v333);
              v337 = v1128 + v333;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v334);
              v338 = v1144 + v334;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v338) = v338 - 1;
              if ( !(_WORD)v338 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[1] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v337);
              LOWORD(v337) = v1076 + v337;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v337);
              v339 = v1128 + v337;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v338);
              v340 = v1144 + v338;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v340) = v340 - 1;
              if ( !(_WORD)v340 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[2] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v339);
              LOWORD(v339) = v1076 + v339;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v339);
              v341 = v1128 + v339;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v340);
              v342 = v1144 + v340;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v342) = v342 - 1;
              if ( !(_WORD)v342 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[3] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v341);
              LOWORD(v341) = v1076 + v341;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v341);
              v343 = v1128 + v341;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v342);
              v344 = v1144 + v342;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v344) = v344 - 1;
              if ( !(_WORD)v344 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[4] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v343);
              LOWORD(v343) = v1076 + v343;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v343);
              v345 = v1128 + v343;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v344);
              v346 = v1144 + v344;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v346) = v346 - 1;
              if ( !(_WORD)v346 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[5] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v345);
              LOWORD(v345) = v1076 + v345;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v345);
              v347 = v1128 + v345;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v346);
              v348 = v1144 + v346;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v348) = v348 - 1;
              if ( !(_WORD)v348 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[6] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v347);
              LOWORD(v347) = v1076 + v347;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v347);
              v349 = v1128 + v347;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v348);
              v350 = v1144 + v348;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v350) = v350 - 1;
              if ( !(_WORD)v350 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[7] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v349);
              LOWORD(v349) = v1076 + v349;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v349);
              v351 = v1128 + v349;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v350);
              v352 = v1144 + v350;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v352) = v352 - 1;
              if ( !(_WORD)v352 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[8] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v351);
              LOWORD(v351) = v1076 + v351;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v351);
              v353 = v1128 + v351;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v352);
              v354 = v1144 + v352;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v354) = v354 - 1;
              if ( !(_WORD)v354 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[9] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v353);
              LOWORD(v353) = v1076 + v353;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v353);
              v355 = v1128 + v353;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v354);
              v356 = v1144 + v354;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v356) = v356 - 1;
              if ( !(_WORD)v356 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[10] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v355);
              LOWORD(v355) = v1076 + v355;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v355);
              v357 = v1128 + v355;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v356);
              v358 = v1144 + v356;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v358) = v358 - 1;
              if ( !(_WORD)v358 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[11] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v357);
              LOWORD(v357) = v1076 + v357;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v357);
              v359 = v1128 + v357;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v358);
              v360 = v1144 + v358;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v360) = v360 - 1;
              if ( !(_WORD)v360 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[12] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v359);
              LOWORD(v359) = v1076 + v359;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v359);
              v361 = v1128 + v359;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v360);
              v362 = v1144 + v360;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v362) = v362 - 1;
              if ( !(_WORD)v362 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[13] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v361);
              LOWORD(v361) = v1076 + v361;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v361);
              v363 = v1128 + v361;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v362);
              v364 = v1144 + v362;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v364) = v364 - 1;
              if ( !(_WORD)v364 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[14] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v363);
              LOWORD(v363) = v1076 + v363;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v363);
              v365 = v1128 + v363;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v364);
              v366 = v1144 + v364;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v366) = v366 - 1;
              if ( !(_WORD)v366 )
                break;
              LOBYTE(v328) = *(_BYTE *)(v329 + v336);
              if ( (_BYTE)v328 )
                v331[15] = *(_BYTE *)(v328 + ((u32) tables_start));
              v177 = __CFADD__((_WORD)v1076, (_WORD)v365);
              LOWORD(v365) = v1076 + v365;
              LOBYTE(v329) = BYTE2(v1076) + v177 + v329;
              v177 = __CFADD__(v1128, v365);
              v333 = v1128 + v365;
              BYTE1(v329) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1144, v366);
              v334 = v1144 + v366;
              BYTE1(v328) += BYTE2(v1078) + v177;
              LOWORD(v334) = v334 - 1;
              if ( !(_WORD)v334 )
                break;
              v331 += 16;
            }
            v327 = v1237;
          }
LABEL_535:
          v327 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v330 > vec_window_width )
          LOWORD(v330) = vec_window_width;
        v16 = (__int16)v330 <= (__int16)v328;
        v335 = v330 - v328;
        if ( v16 )
          goto LABEL_535;
        v331 += v328;
        v333 = __ROL4__(*((int *)v327 + 3), 16);
        BYTE1(v329) = v333;
        LOWORD(v333) = v327[4];
        LOBYTE(v329) = *((_BYTE *)v327 + 10);
        v1252 = v335;
        v334 = __ROL4__(*((int *)v327 + 4), 16);
        BYTE1(v328) = v334;
        LOWORD(v334) = v1252;
        goto LABEL_484;
      case 7:
      case 11:
LABEL_537:
        v367 = (unsigned __int16 *)&polyscans;
        v1129 = v1077 SHL16;
        HIWORD(v368) = 0;
        HIWORD(v369) = 0;
        while ( 1 )
        {
          LOWORD(v368) = v367[1];
          v370 = v367[3];
          v371 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v368 & 0x8000u) == 0 )
            break;
          if ( (__int16)v370 > 0 )
          {
            v372 = (unsigned __int16)-(__int16)v368;
            v374 = __ROL4__(*((int *)v367 + 3) + v1077 * v372, 16);
            BYTE1(v369) = v374;
            v373 = *((int *)v367 + 2) + v1076 * v372;
            LOWORD(v374) = v373;
            v375 = v373 >> 8;
            LOBYTE(v369) = BYTE1(v375);
            if ( v370 > vec_window_width )
              LOWORD(v370) = vec_window_width;
            v368 = (unsigned __int16)v375;
LABEL_547:
            v1238 = v367;
            v376 = vec_map;
            BYTE1(v368) = vec_colour;
            while ( 1 )
            {
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v374);
              LOWORD(v374) = v1076 + v374;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v374);
              v377 = v1129 + v374;
              *v371 = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v378 = v370 - 1;
              if ( !v378 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v377);
              LOWORD(v377) = v1076 + v377;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v377);
              v379 = v1129 + v377;
              v371[1] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v380 = v378 - 1;
              if ( !v380 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v379);
              LOWORD(v379) = v1076 + v379;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v379);
              v381 = v1129 + v379;
              v371[2] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v382 = v380 - 1;
              if ( !v382 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v381);
              LOWORD(v381) = v1076 + v381;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v381);
              v383 = v1129 + v381;
              v371[3] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v384 = v382 - 1;
              if ( !v384 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v383);
              LOWORD(v383) = v1076 + v383;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v383);
              v385 = v1129 + v383;
              v371[4] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v386 = v384 - 1;
              if ( !v386 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v385);
              LOWORD(v385) = v1076 + v385;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v385);
              v387 = v1129 + v385;
              v371[5] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v388 = v386 - 1;
              if ( !v388 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v387);
              LOWORD(v387) = v1076 + v387;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v387);
              v389 = v1129 + v387;
              v371[6] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v390 = v388 - 1;
              if ( !v390 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v389);
              LOWORD(v389) = v1076 + v389;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v389);
              v391 = v1129 + v389;
              v371[7] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v392 = v390 - 1;
              if ( !v392 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v391);
              LOWORD(v391) = v1076 + v391;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v391);
              v393 = v1129 + v391;
              v371[8] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v394 = v392 - 1;
              if ( !v394 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v393);
              LOWORD(v393) = v1076 + v393;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v393);
              v395 = v1129 + v393;
              v371[9] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v396 = v394 - 1;
              if ( !v396 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v395);
              LOWORD(v395) = v1076 + v395;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v395);
              v397 = v1129 + v395;
              v371[10] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v398 = v396 - 1;
              if ( !v398 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v397);
              LOWORD(v397) = v1076 + v397;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v397);
              v399 = v1129 + v397;
              v371[11] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v400 = v398 - 1;
              if ( !v400 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v399);
              LOWORD(v399) = v1076 + v399;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v399);
              v401 = v1129 + v399;
              v371[12] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v402 = v400 - 1;
              if ( !v402 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v401);
              LOWORD(v401) = v1076 + v401;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v401);
              v403 = v1129 + v401;
              v371[13] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v404 = v402 - 1;
              if ( !v404 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v403);
              LOWORD(v403) = v1076 + v403;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v403);
              v405 = v1129 + v403;
              v371[14] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              v406 = v404 - 1;
              if ( !v406 )
                break;
              LOBYTE(v368) = *(_BYTE *)(v369 + v376);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v405);
              LOWORD(v405) = v1076 + v405;
              LOBYTE(v369) = BYTE2(v1076) + v177 + v369;
              v177 = __CFADD__(v1129, v405);
              v374 = v1129 + v405;
              v371[15] = *(_BYTE *)(v368 + ((u32) tables_start));
              BYTE1(v369) += BYTE2(v1077) + v177;
              LOWORD(v370) = v406 - 1;
              if ( !(_WORD)v370 )
                break;
              v371 += 16;
            }
            v367 = v1238;
          }
LABEL_566:
          v367 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v370 > vec_window_width )
          LOWORD(v370) = vec_window_width;
        v16 = (__int16)v370 <= (__int16)v368;
        LOWORD(v370) = v370 - v368;
        if ( v16 )
          goto LABEL_566;
        v371 += v368;
        v374 = __ROL4__(*((int *)v367 + 3), 16);
        BYTE1(v369) = v374;
        LOWORD(v374) = v367[4];
        LOBYTE(v369) = *((_BYTE *)v367 + 10);
        goto LABEL_547;
      case 8:
LABEL_568:
        v407 = (unsigned __int16 *)&polyscans;
        v1130 = v1077 SHL16;
        HIWORD(v408) = 0;
        HIWORD(v409) = 0;
        while ( 1 )
        {
          LOWORD(v408) = v407[1];
          v410 = v407[3];
          v411 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v408 & 0x8000u) == 0 )
            break;
          if ( (__int16)v410 > 0 )
          {
            v412 = (unsigned __int16)-(__int16)v408;
            v414 = __ROL4__(*((int *)v407 + 3) + v1077 * v412, 16);
            BYTE1(v409) = v414;
            v413 = *((int *)v407 + 2) + v1076 * v412;
            LOWORD(v414) = v413;
            v415 = v413 >> 8;
            LOBYTE(v409) = BYTE1(v415);
            if ( v410 > vec_window_width )
              LOWORD(v410) = vec_window_width;
            v408 = (unsigned __int16)v415;
LABEL_578:
            v1239 = v407;
            v416 = vec_map;
            BYTE1(v408) = vec_colour;
            while ( 1 )
            {
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v414);
              LOWORD(v414) = v1076 + v414;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                *v411 = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v414);
              v417 = v1130 + v414;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v418 = v410 - 1;
              if ( !v418 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v417);
              LOWORD(v417) = v1076 + v417;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[1] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v417);
              v419 = v1130 + v417;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v420 = v418 - 1;
              if ( !v420 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v419);
              LOWORD(v419) = v1076 + v419;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[2] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v419);
              v421 = v1130 + v419;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v422 = v420 - 1;
              if ( !v422 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v421);
              LOWORD(v421) = v1076 + v421;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[3] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v421);
              v423 = v1130 + v421;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v424 = v422 - 1;
              if ( !v424 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v423);
              LOWORD(v423) = v1076 + v423;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[4] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v423);
              v425 = v1130 + v423;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v426 = v424 - 1;
              if ( !v426 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v425);
              LOWORD(v425) = v1076 + v425;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[5] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v425);
              v427 = v1130 + v425;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v428 = v426 - 1;
              if ( !v428 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v427);
              LOWORD(v427) = v1076 + v427;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[6] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v427);
              v429 = v1130 + v427;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v430 = v428 - 1;
              if ( !v430 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v429);
              LOWORD(v429) = v1076 + v429;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[7] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v429);
              v431 = v1130 + v429;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v432 = v430 - 1;
              if ( !v432 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v431);
              LOWORD(v431) = v1076 + v431;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[8] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v431);
              v433 = v1130 + v431;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v434 = v432 - 1;
              if ( !v434 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v433);
              LOWORD(v433) = v1076 + v433;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[9] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v433);
              v435 = v1130 + v433;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v436 = v434 - 1;
              if ( !v436 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v435);
              LOWORD(v435) = v1076 + v435;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[10] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v435);
              v437 = v1130 + v435;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v438 = v436 - 1;
              if ( !v438 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v437);
              LOWORD(v437) = v1076 + v437;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[11] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v437);
              v439 = v1130 + v437;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v440 = v438 - 1;
              if ( !v440 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v439);
              LOWORD(v439) = v1076 + v439;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[12] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v439);
              v441 = v1130 + v439;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v442 = v440 - 1;
              if ( !v442 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v441);
              LOWORD(v441) = v1076 + v441;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[13] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v441);
              v443 = v1130 + v441;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v444 = v442 - 1;
              if ( !v444 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v443);
              LOWORD(v443) = v1076 + v443;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[14] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v443);
              v445 = v1130 + v443;
              BYTE1(v409) += BYTE2(v1077) + v177;
              v446 = v444 - 1;
              if ( !v446 )
                break;
              LOBYTE(v408) = *(_BYTE *)(v409 + v416);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v445);
              LOWORD(v445) = v1076 + v445;
              LOBYTE(v409) = BYTE2(v1076) + v177 + v409;
              if ( (_BYTE)v408 )
                v411[15] = *(_BYTE *)(v408 + ((u32) tables_start));
              v177 = __CFADD__(v1130, v445);
              v414 = v1130 + v445;
              BYTE1(v409) += BYTE2(v1077) + v177;
              LOWORD(v410) = v446 - 1;
              if ( !(_WORD)v410 )
                break;
              v411 += 16;
            }
            v407 = v1239;
          }
LABEL_629:
          v407 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v410 > vec_window_width )
          LOWORD(v410) = vec_window_width;
        v16 = (__int16)v410 <= (__int16)v408;
        LOWORD(v410) = v410 - v408;
        if ( v16 )
          goto LABEL_629;
        v411 += v408;
        v414 = __ROL4__(*((int *)v407 + 3), 16);
        BYTE1(v409) = v414;
        LOWORD(v414) = v407[4];
        LOBYTE(v409) = *((_BYTE *)v407 + 10);
        goto LABEL_578;
      case 9:
      case 10:
LABEL_631:
        v447 = (unsigned __int16 *)&polyscans;
        v1131 = v1077 SHL16;
        HIWORD(v448) = 0;
        HIWORD(v449) = 0;
        while ( 1 )
        {
          LOWORD(v448) = v447[1];
          v450 = v447[3];
          v451 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v448 & 0x8000u) == 0 )
            break;
          if ( (__int16)v450 > 0 )
          {
            v452 = (unsigned __int16)-(__int16)v448;
            v454 = __ROL4__(*((int *)v447 + 3) + v1077 * v452, 16);
            BYTE1(v449) = v454;
            v453 = *((int *)v447 + 2) + v1076 * v452;
            LOWORD(v454) = v453;
            v455 = v453 >> 8;
            LOBYTE(v449) = BYTE1(v455);
            if ( v450 > vec_window_width )
              LOWORD(v450) = vec_window_width;
            v448 = (unsigned __int16)v455;
LABEL_641:
            v1240 = v447;
            v456 = vec_map;
            while ( 1 )
            {
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v454);
              LOWORD(v454) = v1076 + v454;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = *v451;
                *v451 = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v454);
              v457 = v1131 + v454;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v458 = v450 - 1;
              if ( !v458 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v457);
              LOWORD(v457) = v1076 + v457;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[1];
                v451[1] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v457);
              v459 = v1131 + v457;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v460 = v458 - 1;
              if ( !v460 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v459);
              LOWORD(v459) = v1076 + v459;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[2];
                v451[2] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v459);
              v461 = v1131 + v459;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v462 = v460 - 1;
              if ( !v462 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v461);
              LOWORD(v461) = v1076 + v461;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[3];
                v451[3] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v461);
              v463 = v1131 + v461;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v464 = v462 - 1;
              if ( !v464 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v463);
              LOWORD(v463) = v1076 + v463;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[4];
                v451[4] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v463);
              v465 = v1131 + v463;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v466 = v464 - 1;
              if ( !v466 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v465);
              LOWORD(v465) = v1076 + v465;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[5];
                v451[5] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v465);
              v467 = v1131 + v465;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v468 = v466 - 1;
              if ( !v468 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v467);
              LOWORD(v467) = v1076 + v467;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[6];
                v451[6] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v467);
              v469 = v1131 + v467;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v470 = v468 - 1;
              if ( !v470 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v469);
              LOWORD(v469) = v1076 + v469;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[7];
                v451[7] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v469);
              v471 = v1131 + v469;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v472 = v470 - 1;
              if ( !v472 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v471);
              LOWORD(v471) = v1076 + v471;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[8];
                v451[8] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v471);
              v473 = v1131 + v471;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v474 = v472 - 1;
              if ( !v474 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v473);
              LOWORD(v473) = v1076 + v473;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[9];
                v451[9] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v473);
              v475 = v1131 + v473;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v476 = v474 - 1;
              if ( !v476 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v475);
              LOWORD(v475) = v1076 + v475;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[10];
                v451[10] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v475);
              v477 = v1131 + v475;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v478 = v476 - 1;
              if ( !v478 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v477);
              LOWORD(v477) = v1076 + v477;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[11];
                v451[11] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v477);
              v479 = v1131 + v477;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v480 = v478 - 1;
              if ( !v480 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v479);
              LOWORD(v479) = v1076 + v479;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[12];
                v451[12] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v479);
              v481 = v1131 + v479;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v482 = v480 - 1;
              if ( !v482 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v481);
              LOWORD(v481) = v1076 + v481;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[13];
                v451[13] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v481);
              v483 = v1131 + v481;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v484 = v482 - 1;
              if ( !v484 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v483);
              LOWORD(v483) = v1076 + v483;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[14];
                v451[14] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v483);
              v485 = v1131 + v483;
              BYTE1(v449) += BYTE2(v1077) + v177;
              v486 = v484 - 1;
              if ( !v486 )
                break;
              BYTE1(v448) = *(_BYTE *)(v449 + v456);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v485);
              LOWORD(v485) = v1076 + v485;
              LOBYTE(v449) = BYTE2(v1076) + v177 + v449;
              if ( BYTE1(v448) )
              {
                LOBYTE(v448) = v451[15];
                v451[15] = *(_BYTE *)(v448 + ((u32) tables_start));
              }
              v177 = __CFADD__(v1131, v485);
              v454 = v1131 + v485;
              BYTE1(v449) += BYTE2(v1077) + v177;
              LOWORD(v450) = v486 - 1;
              if ( !(_WORD)v450 )
                break;
              v451 += 16;
            }
            v447 = v1240;
          }
LABEL_692:
          v447 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v450 > vec_window_width )
          LOWORD(v450) = vec_window_width;
        v16 = (__int16)v450 <= (__int16)v448;
        LOWORD(v450) = v450 - v448;
        if ( v16 )
          goto LABEL_692;
        v451 += v448;
        v454 = __ROL4__(*((int *)v447 + 3), 16);
        BYTE1(v449) = v454;
        LOWORD(v454) = v447[4];
        LOBYTE(v449) = *((_BYTE *)v447 + 10);
        goto LABEL_641;
      case 12:
LABEL_694:
        v487 = (unsigned __int16 *)&polyscans;
        v1132 = v1077 SHL16;
        HIWORD(v488) = 0;
        HIWORD(v489) = 0;
        while ( 1 )
        {
          LOWORD(v488) = v487[1];
          v490 = v487[3];
          v491 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v488 & 0x8000u) == 0 )
            break;
          if ( (__int16)v490 > 0 )
          {
            v492 = (unsigned __int16)-(__int16)v488;
            v494 = __ROL4__(*((int *)v487 + 3) + v1077 * v492, 16);
            BYTE1(v489) = v494;
            v493 = *((int *)v487 + 2) + v1076 * v492;
            LOWORD(v494) = v493;
            v495 = v493 >> 8;
            LOBYTE(v489) = BYTE1(v495);
            if ( v490 > vec_window_width )
              LOWORD(v490) = vec_window_width;
            v488 = (unsigned __int16)v495;
LABEL_704:
            v1241 = v487;
            v496 = vec_map;
            LOBYTE(v488) = vec_colour;
            while ( 1 )
            {
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v494);
              LOWORD(v494) = v1076 + v494;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v494);
              v497 = v1132 + v494;
              *v491 = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v498 = v490 - 1;
              if ( !v498 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v497);
              LOWORD(v497) = v1076 + v497;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v497);
              v499 = v1132 + v497;
              v491[1] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v500 = v498 - 1;
              if ( !v500 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v499);
              LOWORD(v499) = v1076 + v499;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v499);
              v501 = v1132 + v499;
              v491[2] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v502 = v500 - 1;
              if ( !v502 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v501);
              LOWORD(v501) = v1076 + v501;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v501);
              v503 = v1132 + v501;
              v491[3] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v504 = v502 - 1;
              if ( !v504 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v503);
              LOWORD(v503) = v1076 + v503;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v503);
              v505 = v1132 + v503;
              v491[4] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v506 = v504 - 1;
              if ( !v506 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v505);
              LOWORD(v505) = v1076 + v505;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v505);
              v507 = v1132 + v505;
              v491[5] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v508 = v506 - 1;
              if ( !v508 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v507);
              LOWORD(v507) = v1076 + v507;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v507);
              v509 = v1132 + v507;
              v491[6] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v510 = v508 - 1;
              if ( !v510 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v509);
              LOWORD(v509) = v1076 + v509;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v509);
              v511 = v1132 + v509;
              v491[7] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v512 = v510 - 1;
              if ( !v512 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v511);
              LOWORD(v511) = v1076 + v511;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v511);
              v513 = v1132 + v511;
              v491[8] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v514 = v512 - 1;
              if ( !v514 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v513);
              LOWORD(v513) = v1076 + v513;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v513);
              v515 = v1132 + v513;
              v491[9] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v516 = v514 - 1;
              if ( !v516 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v515);
              LOWORD(v515) = v1076 + v515;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v515);
              v517 = v1132 + v515;
              v491[10] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v518 = v516 - 1;
              if ( !v518 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v517);
              LOWORD(v517) = v1076 + v517;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v517);
              v519 = v1132 + v517;
              v491[11] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v520 = v518 - 1;
              if ( !v520 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v519);
              LOWORD(v519) = v1076 + v519;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v519);
              v521 = v1132 + v519;
              v491[12] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v522 = v520 - 1;
              if ( !v522 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v521);
              LOWORD(v521) = v1076 + v521;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v521);
              v523 = v1132 + v521;
              v491[13] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v524 = v522 - 1;
              if ( !v524 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v523);
              LOWORD(v523) = v1076 + v523;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v523);
              v525 = v1132 + v523;
              v491[14] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              v526 = v524 - 1;
              if ( !v526 )
                break;
              BYTE1(v488) = *(_BYTE *)(v489 + v496);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v525);
              LOWORD(v525) = v1076 + v525;
              LOBYTE(v489) = BYTE2(v1076) + v177 + v489;
              v177 = __CFADD__(v1132, v525);
              v494 = v1132 + v525;
              v491[15] = *(_BYTE *)(v488 + ((u32)ghost));
              BYTE1(v489) += BYTE2(v1077) + v177;
              LOWORD(v490) = v526 - 1;
              if ( !(_WORD)v490 )
                break;
              v491 += 16;
            }
            v487 = v1241;
          }
LABEL_723:
          v487 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v490 > vec_window_width )
          LOWORD(v490) = vec_window_width;
        v16 = (__int16)v490 <= (__int16)v488;
        LOWORD(v490) = v490 - v488;
        if ( v16 )
          goto LABEL_723;
        v491 += v488;
        v494 = __ROL4__(*((int *)v487 + 3), 16);
        BYTE1(v489) = v494;
        LOWORD(v494) = v487[4];
        LOBYTE(v489) = *((_BYTE *)v487 + 10);
        goto LABEL_704;
      case 13:
LABEL_725:
        v527 = (unsigned __int16 *)&polyscans;
        v1133 = v1077 SHL16;
        HIWORD(v528) = 0;
        HIWORD(v529) = 0;
        while ( 1 )
        {
          LOWORD(v528) = v527[1];
          v530 = v527[3];
          v531 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v528 & 0x8000u) == 0 )
            break;
          if ( (__int16)v530 > 0 )
          {
            v532 = (unsigned __int16)-(__int16)v528;
            v534 = __ROL4__(*((int *)v527 + 3) + v1077 * v532, 16);
            BYTE1(v529) = v534;
            v533 = *((int *)v527 + 2) + v1076 * v532;
            LOWORD(v534) = v533;
            v535 = v533 >> 8;
            LOBYTE(v529) = BYTE1(v535);
            if ( v530 > vec_window_width )
              LOWORD(v530) = vec_window_width;
            v528 = (unsigned __int16)v535;
LABEL_735:
            v1242 = v527;
            v536 = vec_map;
            BYTE1(v528) = vec_colour;
            while ( 1 )
            {
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v534);
              LOWORD(v534) = v1076 + v534;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v534);
              v537 = v1133 + v534;
              *v531 = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v538 = v530 - 1;
              if ( !v538 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v537);
              LOWORD(v537) = v1076 + v537;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v537);
              v539 = v1133 + v537;
              v531[1] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v540 = v538 - 1;
              if ( !v540 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v539);
              LOWORD(v539) = v1076 + v539;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v539);
              v541 = v1133 + v539;
              v531[2] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v542 = v540 - 1;
              if ( !v542 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v541);
              LOWORD(v541) = v1076 + v541;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v541);
              v543 = v1133 + v541;
              v531[3] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v544 = v542 - 1;
              if ( !v544 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v543);
              LOWORD(v543) = v1076 + v543;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v543);
              v545 = v1133 + v543;
              v531[4] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v546 = v544 - 1;
              if ( !v546 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v545);
              LOWORD(v545) = v1076 + v545;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v545);
              v547 = v1133 + v545;
              v531[5] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v548 = v546 - 1;
              if ( !v548 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v547);
              LOWORD(v547) = v1076 + v547;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v547);
              v549 = v1133 + v547;
              v531[6] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v550 = v548 - 1;
              if ( !v550 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v549);
              LOWORD(v549) = v1076 + v549;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v549);
              v551 = v1133 + v549;
              v531[7] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v552 = v550 - 1;
              if ( !v552 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v551);
              LOWORD(v551) = v1076 + v551;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v551);
              v553 = v1133 + v551;
              v531[8] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v554 = v552 - 1;
              if ( !v554 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v553);
              LOWORD(v553) = v1076 + v553;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v553);
              v555 = v1133 + v553;
              v531[9] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v556 = v554 - 1;
              if ( !v556 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v555);
              LOWORD(v555) = v1076 + v555;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v555);
              v557 = v1133 + v555;
              v531[10] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v558 = v556 - 1;
              if ( !v558 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v557);
              LOWORD(v557) = v1076 + v557;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v557);
              v559 = v1133 + v557;
              v531[11] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v560 = v558 - 1;
              if ( !v560 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v559);
              LOWORD(v559) = v1076 + v559;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v559);
              v561 = v1133 + v559;
              v531[12] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v562 = v560 - 1;
              if ( !v562 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v561);
              LOWORD(v561) = v1076 + v561;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v561);
              v563 = v1133 + v561;
              v531[13] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v564 = v562 - 1;
              if ( !v564 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v563);
              LOWORD(v563) = v1076 + v563;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v563);
              v565 = v1133 + v563;
              v531[14] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              v566 = v564 - 1;
              if ( !v566 )
                break;
              LOBYTE(v528) = *(_BYTE *)(v529 + v536);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v565);
              LOWORD(v565) = v1076 + v565;
              LOBYTE(v529) = BYTE2(v1076) + v177 + v529;
              v177 = __CFADD__(v1133, v565);
              v534 = v1133 + v565;
              v531[15] = *(_BYTE *)(v528 + ((u32)ghost));
              BYTE1(v529) += BYTE2(v1077) + v177;
              LOWORD(v530) = v566 - 1;
              if ( !(_WORD)v530 )
                break;
              v531 += 16;
            }
            v527 = v1242;
          }
LABEL_754:
          v527 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v530 > vec_window_width )
          LOWORD(v530) = vec_window_width;
        v16 = (__int16)v530 <= (__int16)v528;
        LOWORD(v530) = v530 - v528;
        if ( v16 )
          goto LABEL_754;
        v531 += v528;
        v534 = __ROL4__(*((int *)v527 + 3), 16);
        BYTE1(v529) = v534;
        LOWORD(v534) = v527[4];
        LOBYTE(v529) = *((_BYTE *)v527 + 10);
        goto LABEL_735;
      case 14:
LABEL_756:
        v567 = (unsigned __int16 *)&polyscans;
        v568 = (_BYTE *)v1054;
        HIWORD(v569) = 0;
        BYTE1(v569) = vec_colour;
        HIWORD(v570) = 0;
        while ( 1 )
        {
          LOWORD(v570) = v567[1];
          v571 = v567[3];
          v568 += vec_screen_width;
          if ( (v570 & 0x8000u) == 0 )
            break;
          if ( (__int16)v571 > 0 )
          {
            if ( v571 > vec_window_width )
              LOWORD(v571) = vec_window_width;
LABEL_766:
            for ( j = v568; ; j += 16 )
            {
              LOBYTE(v569) = *j;
              *j = *(_BYTE *)(v569 + ((u32)ghost));
              v573 = v571 - 1;
              if ( !v573 )
                break;
              LOBYTE(v569) = j[1];
              j[1] = *(_BYTE *)(v569 + ((u32)ghost));
              v574 = v573 - 1;
              if ( !v574 )
                break;
              LOBYTE(v569) = j[2];
              j[2] = *(_BYTE *)(v569 + ((u32)ghost));
              v575 = v574 - 1;
              if ( !v575 )
                break;
              LOBYTE(v569) = j[3];
              j[3] = *(_BYTE *)(v569 + ((u32)ghost));
              v576 = v575 - 1;
              if ( !v576 )
                break;
              LOBYTE(v569) = j[4];
              j[4] = *(_BYTE *)(v569 + ((u32)ghost));
              v577 = v576 - 1;
              if ( !v577 )
                break;
              LOBYTE(v569) = j[5];
              j[5] = *(_BYTE *)(v569 + ((u32)ghost));
              v578 = v577 - 1;
              if ( !v578 )
                break;
              LOBYTE(v569) = j[6];
              j[6] = *(_BYTE *)(v569 + ((u32)ghost));
              v579 = v578 - 1;
              if ( !v579 )
                break;
              LOBYTE(v569) = j[7];
              j[7] = *(_BYTE *)(v569 + ((u32)ghost));
              v580 = v579 - 1;
              if ( !v580 )
                break;
              LOBYTE(v569) = j[8];
              j[8] = *(_BYTE *)(v569 + ((u32)ghost));
              v581 = v580 - 1;
              if ( !v581 )
                break;
              LOBYTE(v569) = j[9];
              j[9] = *(_BYTE *)(v569 + ((u32)ghost));
              v582 = v581 - 1;
              if ( !v582 )
                break;
              LOBYTE(v569) = j[10];
              j[10] = *(_BYTE *)(v569 + ((u32)ghost));
              v583 = v582 - 1;
              if ( !v583 )
                break;
              LOBYTE(v569) = j[11];
              j[11] = *(_BYTE *)(v569 + ((u32)ghost));
              v584 = v583 - 1;
              if ( !v584 )
                break;
              LOBYTE(v569) = j[12];
              j[12] = *(_BYTE *)(v569 + ((u32)ghost));
              v585 = v584 - 1;
              if ( !v585 )
                break;
              LOBYTE(v569) = j[13];
              j[13] = *(_BYTE *)(v569 + ((u32)ghost));
              v586 = v585 - 1;
              if ( !v586 )
                break;
              LOBYTE(v569) = j[14];
              j[14] = *(_BYTE *)(v569 + ((u32)ghost));
              v587 = v586 - 1;
              if ( !v587 )
                break;
              LOBYTE(v569) = j[15];
              j[15] = *(_BYTE *)(v569 + ((u32)ghost));
              LOWORD(v571) = v587 - 1;
              if ( !(_WORD)v571 )
                break;
            }
          }
LABEL_783:
          v567 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v571 > vec_window_width )
          LOWORD(v571) = vec_window_width;
        v16 = (__int16)v571 <= (__int16)v570;
        LOWORD(v571) = v571 - v570;
        if ( v16 )
          goto LABEL_783;
        j = &v568[v570];
        goto LABEL_766;
      case 15:
LABEL_785:
        v588 = (unsigned __int16 *)&polyscans;
        v589 = (_BYTE *)v1054;
        v590 = (unsigned __int8)vec_colour;
        HIWORD(v591) = 0;
        while ( 1 )
        {
          LOWORD(v591) = v588[1];
          v592 = v588[3];
          v589 += vec_screen_width;
          if ( (v591 & 0x8000u) == 0 )
            break;
          if ( (__int16)v592 > 0 )
          {
            if ( v592 > vec_window_width )
              LOWORD(v592) = vec_window_width;
LABEL_795:
            for ( k = v589; ; k += 16 )
            {
              BYTE1(v590) = *k;
              *k = *(_BYTE *)(v590 + ((u32)ghost));
              v594 = v592 - 1;
              if ( !v594 )
                break;
              BYTE1(v590) = k[1];
              k[1] = *(_BYTE *)(v590 + ((u32)ghost));
              v595 = v594 - 1;
              if ( !v595 )
                break;
              BYTE1(v590) = k[2];
              k[2] = *(_BYTE *)(v590 + ((u32)ghost));
              v596 = v595 - 1;
              if ( !v596 )
                break;
              BYTE1(v590) = k[3];
              k[3] = *(_BYTE *)(v590 + ((u32)ghost));
              v597 = v596 - 1;
              if ( !v597 )
                break;
              BYTE1(v590) = k[4];
              k[4] = *(_BYTE *)(v590 + ((u32)ghost));
              v598 = v597 - 1;
              if ( !v598 )
                break;
              BYTE1(v590) = k[5];
              k[5] = *(_BYTE *)(v590 + ((u32)ghost));
              v599 = v598 - 1;
              if ( !v599 )
                break;
              BYTE1(v590) = k[6];
              k[6] = *(_BYTE *)(v590 + ((u32)ghost));
              v600 = v599 - 1;
              if ( !v600 )
                break;
              BYTE1(v590) = k[7];
              k[7] = *(_BYTE *)(v590 + ((u32)ghost));
              v601 = v600 - 1;
              if ( !v601 )
                break;
              BYTE1(v590) = k[8];
              k[8] = *(_BYTE *)(v590 + ((u32)ghost));
              v602 = v601 - 1;
              if ( !v602 )
                break;
              BYTE1(v590) = k[9];
              k[9] = *(_BYTE *)(v590 + ((u32)ghost));
              v603 = v602 - 1;
              if ( !v603 )
                break;
              BYTE1(v590) = k[10];
              k[10] = *(_BYTE *)(v590 + ((u32)ghost));
              v604 = v603 - 1;
              if ( !v604 )
                break;
              BYTE1(v590) = k[11];
              k[11] = *(_BYTE *)(v590 + ((u32)ghost));
              v605 = v604 - 1;
              if ( !v605 )
                break;
              BYTE1(v590) = k[12];
              k[12] = *(_BYTE *)(v590 + ((u32)ghost));
              v606 = v605 - 1;
              if ( !v606 )
                break;
              BYTE1(v590) = k[13];
              k[13] = *(_BYTE *)(v590 + ((u32)ghost));
              v607 = v606 - 1;
              if ( !v607 )
                break;
              BYTE1(v590) = k[14];
              k[14] = *(_BYTE *)(v590 + ((u32)ghost));
              v608 = v607 - 1;
              if ( !v608 )
                break;
              BYTE1(v590) = k[15];
              k[15] = *(_BYTE *)(v590 + ((u32)ghost));
              LOWORD(v592) = v608 - 1;
              if ( !(_WORD)v592 )
                break;
            }
          }
LABEL_812:
          v588 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v592 > vec_window_width )
          LOWORD(v592) = vec_window_width;
        v16 = (__int16)v592 <= (__int16)v591;
        LOWORD(v592) = v592 - v591;
        if ( v16 )
          goto LABEL_812;
        k = &v589[v591];
        goto LABEL_795;
      case 16:
LABEL_814:
        v609 = (unsigned __int16 *)&polyscans;
        HIWORD(v610) = 0;
        while ( 1 )
        {
          LOWORD(v29) = v609[1];
          v611 = v609[3];
          v612 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v29 & 0x8000u) == 0 )
            break;
          if ( (__int16)v611 > 0 )
          {
            v613 = v1078 * (unsigned __int16)-(__int16)v29;
            v614 = v613;
            v29 = v613 >> 8;
            v177 = __CFADD__(v609[8], v614);
            v615 = v609[8] + v614;
            BYTE1(v29) += *((_BYTE *)v609 + 18) + v177;
            if ( v611 > vec_window_width )
              LOWORD(v611) = vec_window_width;
            v29 = (unsigned __int16)v29;
            LOBYTE(v29) = vec_colour;
LABEL_824:
            while ( 1 )
            {
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = *v612;
              *v612 = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v615);
              v616 = v1078 + v615;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v617 = v611 - 1;
              if ( !v617 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[1];
              v612[1] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v616);
              v618 = v1078 + v616;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v619 = v617 - 1;
              if ( !v619 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[2];
              v612[2] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v618);
              v620 = v1078 + v618;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v621 = v619 - 1;
              if ( !v621 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[3];
              v612[3] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v620);
              v622 = v1078 + v620;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v623 = v621 - 1;
              if ( !v623 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[4];
              v612[4] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v622);
              v624 = v1078 + v622;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v625 = v623 - 1;
              if ( !v625 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[5];
              v612[5] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v624);
              v626 = v1078 + v624;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v627 = v625 - 1;
              if ( !v627 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[6];
              v612[6] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v626);
              v628 = v1078 + v626;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v629 = v627 - 1;
              if ( !v629 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[7];
              v612[7] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v628);
              v630 = v1078 + v628;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v631 = v629 - 1;
              if ( !v631 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[8];
              v612[8] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v630);
              v632 = v1078 + v630;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v633 = v631 - 1;
              if ( !v633 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[9];
              v612[9] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v632);
              v634 = v1078 + v632;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v635 = v633 - 1;
              if ( !v635 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[10];
              v612[10] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v634);
              v636 = v1078 + v634;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v637 = v635 - 1;
              if ( !v637 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[11];
              v612[11] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v636);
              v638 = v1078 + v636;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v639 = v637 - 1;
              if ( !v639 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[12];
              v612[12] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v638);
              v640 = v1078 + v638;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v641 = v639 - 1;
              if ( !v641 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[13];
              v612[13] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v640);
              v642 = v1078 + v640;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v643 = v641 - 1;
              if ( !v643 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[14];
              v612[14] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v642);
              v644 = v1078 + v642;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v645 = v643 - 1;
              if ( !v645 )
                break;
              BYTE1(v610) = *(_BYTE *)(v29 + ((u32) tables_start));
              LOBYTE(v610) = v612[15];
              v612[15] = *(_BYTE *)(v610 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v644);
              v615 = v1078 + v644;
              BYTE1(v29) += BYTE2(v1078) + v177;
              LOWORD(v611) = v645 - 1;
              if ( !(_WORD)v611 )
                break;
              v612 += 16;
            }
          }
LABEL_841:
          v609 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v611 > vec_window_width )
          LOWORD(v611) = vec_window_width;
        v16 = (__int16)v611 <= (__int16)v29;
        LOWORD(v611) = v611 - v29;
        if ( v16 )
          goto LABEL_841;
        v612 += v29;
        v29 = (unsigned __int8)vec_colour;
        v615 = v609[8];
        BYTE1(v29) = *((_BYTE *)v609 + 18);
        goto LABEL_824;
      case 17:
LABEL_843:
        v646 = (unsigned __int16 *)&polyscans;
        HIWORD(v647) = 0;
        while ( 1 )
        {
          LOWORD(v29) = v646[1];
          v648 = v646[3];
          v649 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v29 & 0x8000u) == 0 )
            break;
          if ( (__int16)v648 > 0 )
          {
            v650 = v1078 * (unsigned __int16)-(__int16)v29;
            v651 = v650;
            v29 = v650 >> 8;
            v177 = __CFADD__(v646[8], v651);
            v652 = v646[8] + v651;
            BYTE1(v29) += *((_BYTE *)v646 + 18) + v177;
            if ( v648 > vec_window_width )
              LOWORD(v648) = vec_window_width;
            v29 = (unsigned __int16)v29;
            LOBYTE(v29) = vec_colour;
LABEL_853:
            while ( 1 )
            {
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = *v649;
              *v649 = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v652);
              v653 = v1078 + v652;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v654 = v648 - 1;
              if ( !v654 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[1];
              v649[1] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v653);
              v655 = v1078 + v653;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v656 = v654 - 1;
              if ( !v656 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[2];
              v649[2] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v655);
              v657 = v1078 + v655;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v658 = v656 - 1;
              if ( !v658 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[3];
              v649[3] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v657);
              v659 = v1078 + v657;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v660 = v658 - 1;
              if ( !v660 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[4];
              v649[4] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v659);
              v661 = v1078 + v659;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v662 = v660 - 1;
              if ( !v662 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[5];
              v649[5] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v661);
              v663 = v1078 + v661;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v664 = v662 - 1;
              if ( !v664 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[6];
              v649[6] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v663);
              v665 = v1078 + v663;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v666 = v664 - 1;
              if ( !v666 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[7];
              v649[7] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v665);
              v667 = v1078 + v665;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v668 = v666 - 1;
              if ( !v668 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[8];
              v649[8] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v667);
              v669 = v1078 + v667;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v670 = v668 - 1;
              if ( !v670 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[9];
              v649[9] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v669);
              v671 = v1078 + v669;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v672 = v670 - 1;
              if ( !v672 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[10];
              v649[10] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v671);
              v673 = v1078 + v671;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v674 = v672 - 1;
              if ( !v674 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[11];
              v649[11] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v673);
              v675 = v1078 + v673;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v676 = v674 - 1;
              if ( !v676 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[12];
              v649[12] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v675);
              v677 = v1078 + v675;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v678 = v676 - 1;
              if ( !v678 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[13];
              v649[13] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v677);
              v679 = v1078 + v677;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v680 = v678 - 1;
              if ( !v680 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[14];
              v649[14] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v679);
              v681 = v1078 + v679;
              BYTE1(v29) += BYTE2(v1078) + v177;
              v682 = v680 - 1;
              if ( !v682 )
                break;
              LOBYTE(v647) = *(_BYTE *)(v29 + ((u32) tables_start));
              BYTE1(v647) = v649[15];
              v649[15] = *(_BYTE *)(v647 + ((u32)ghost));
              v177 = __CFADD__((_WORD)v1078, v681);
              v652 = v1078 + v681;
              BYTE1(v29) += BYTE2(v1078) + v177;
              LOWORD(v648) = v682 - 1;
              if ( !(_WORD)v648 )
                break;
              v649 += 16;
            }
          }
LABEL_870:
          v646 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v648 > vec_window_width )
          LOWORD(v648) = vec_window_width;
        v16 = (__int16)v648 <= (__int16)v29;
        LOWORD(v648) = v648 - v29;
        if ( v16 )
          goto LABEL_870;
        v649 += v29;
        v29 = (unsigned __int8)vec_colour;
        v652 = v646[8];
        BYTE1(v29) = *((_BYTE *)v646 + 18);
        goto LABEL_853;
      case 18:
LABEL_872:
        v683 = (unsigned __int16 *)&polyscans;
        v1134 = v1077 SHL16;
        HIWORD(v684) = 0;
        HIWORD(v685) = 0;
        while ( 1 )
        {
          LOWORD(v684) = v683[1];
          v686 = v683[3];
          v687 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v684 & 0x8000u) == 0 )
            break;
          if ( (__int16)v686 > 0 )
          {
            v688 = (unsigned __int16)-(__int16)v684;
            v690 = __ROL4__(*((int *)v683 + 3) + v1077 * v688, 16);
            BYTE1(v685) = v690;
            v689 = *((int *)v683 + 2) + v1076 * v688;
            LOWORD(v690) = v689;
            v691 = v689 >> 8;
            LOBYTE(v685) = BYTE1(v691);
            if ( v686 > vec_window_width )
              LOWORD(v686) = vec_window_width;
            v684 = (unsigned __int16)v691;
LABEL_882:
            v1243 = v683;
            v692 = vec_map;
            while ( 1 )
            {
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v690);
              LOWORD(v690) = v1076 + v690;
              LOBYTE(v684) = *v687;
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v690);
              v693 = v1134 + v690;
              *v687 = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v694 = v686 - 1;
              if ( !v694 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v693);
              LOWORD(v693) = v1076 + v693;
              LOBYTE(v684) = v687[1];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v693);
              v695 = v1134 + v693;
              v687[1] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v696 = v694 - 1;
              if ( !v696 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v695);
              LOWORD(v695) = v1076 + v695;
              LOBYTE(v684) = v687[2];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v695);
              v697 = v1134 + v695;
              v687[2] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v698 = v696 - 1;
              if ( !v698 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v697);
              LOWORD(v697) = v1076 + v697;
              LOBYTE(v684) = v687[3];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v697);
              v699 = v1134 + v697;
              v687[3] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v700 = v698 - 1;
              if ( !v700 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v699);
              LOWORD(v699) = v1076 + v699;
              LOBYTE(v684) = v687[4];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v699);
              v701 = v1134 + v699;
              v687[4] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v702 = v700 - 1;
              if ( !v702 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v701);
              LOWORD(v701) = v1076 + v701;
              LOBYTE(v684) = v687[5];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v701);
              v703 = v1134 + v701;
              v687[5] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v704 = v702 - 1;
              if ( !v704 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v703);
              LOWORD(v703) = v1076 + v703;
              LOBYTE(v684) = v687[6];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v703);
              v705 = v1134 + v703;
              v687[6] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v706 = v704 - 1;
              if ( !v706 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v705);
              LOWORD(v705) = v1076 + v705;
              LOBYTE(v684) = v687[7];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v705);
              v707 = v1134 + v705;
              v687[7] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v708 = v706 - 1;
              if ( !v708 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v707);
              LOWORD(v707) = v1076 + v707;
              LOBYTE(v684) = v687[8];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v707);
              v709 = v1134 + v707;
              v687[8] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v710 = v708 - 1;
              if ( !v710 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v709);
              LOWORD(v709) = v1076 + v709;
              LOBYTE(v684) = v687[9];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v709);
              v711 = v1134 + v709;
              v687[9] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v712 = v710 - 1;
              if ( !v712 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v711);
              LOWORD(v711) = v1076 + v711;
              LOBYTE(v684) = v687[10];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v711);
              v713 = v1134 + v711;
              v687[10] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v714 = v712 - 1;
              if ( !v714 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v713);
              LOWORD(v713) = v1076 + v713;
              LOBYTE(v684) = v687[11];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v713);
              v715 = v1134 + v713;
              v687[11] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v716 = v714 - 1;
              if ( !v716 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v715);
              LOWORD(v715) = v1076 + v715;
              LOBYTE(v684) = v687[12];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v715);
              v717 = v1134 + v715;
              v687[12] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v718 = v716 - 1;
              if ( !v718 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v717);
              LOWORD(v717) = v1076 + v717;
              LOBYTE(v684) = v687[13];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v717);
              v719 = v1134 + v717;
              v687[13] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v720 = v718 - 1;
              if ( !v720 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v719);
              LOWORD(v719) = v1076 + v719;
              LOBYTE(v684) = v687[14];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v719);
              v721 = v1134 + v719;
              v687[14] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              v722 = v720 - 1;
              if ( !v722 )
                break;
              BYTE1(v684) = *(_BYTE *)(v685 + v692);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v721);
              LOWORD(v721) = v1076 + v721;
              LOBYTE(v684) = v687[15];
              LOBYTE(v685) = BYTE2(v1076) + v177 + v685;
              v177 = __CFADD__(v1134, v721);
              v690 = v1134 + v721;
              v687[15] = *(_BYTE *)(v684 + ((u32)ghost));
              BYTE1(v685) += BYTE2(v1077) + v177;
              LOWORD(v686) = v722 - 1;
              if ( !(_WORD)v686 )
                break;
              v687 += 16;
            }
            v683 = v1243;
          }
LABEL_901:
          v683 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v686 > vec_window_width )
          LOWORD(v686) = vec_window_width;
        v16 = (__int16)v686 <= (__int16)v684;
        LOWORD(v686) = v686 - v684;
        if ( v16 )
          goto LABEL_901;
        v687 += v684;
        v690 = __ROL4__(*((int *)v683 + 3), 16);
        BYTE1(v685) = v690;
        LOWORD(v690) = v683[4];
        LOBYTE(v685) = *((_BYTE *)v683 + 10);
        goto LABEL_882;
      case 19:
LABEL_903:
        v723 = (unsigned __int16 *)&polyscans;
        v1135 = v1077 SHL16;
        HIWORD(v724) = 0;
        HIWORD(v725) = 0;
        while ( 1 )
        {
          LOWORD(v724) = v723[1];
          v726 = v723[3];
          v727 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v724 & 0x8000u) == 0 )
            break;
          if ( (__int16)v726 > 0 )
          {
            v728 = (unsigned __int16)-(__int16)v724;
            v730 = __ROL4__(*((int *)v723 + 3) + v1077 * v728, 16);
            BYTE1(v725) = v730;
            v729 = *((int *)v723 + 2) + v1076 * v728;
            LOWORD(v730) = v729;
            v731 = v729 >> 8;
            LOBYTE(v725) = BYTE1(v731);
            if ( v726 > vec_window_width )
              LOWORD(v726) = vec_window_width;
            v724 = (unsigned __int16)v731;
LABEL_913:
            v1244 = v723;
            v732 = vec_map;
            while ( 1 )
            {
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v730);
              LOWORD(v730) = v1076 + v730;
              BYTE1(v724) = *v727;
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v730);
              v733 = v1135 + v730;
              *v727 = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v734 = v726 - 1;
              if ( !v734 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v733);
              LOWORD(v733) = v1076 + v733;
              BYTE1(v724) = v727[1];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v733);
              v735 = v1135 + v733;
              v727[1] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v736 = v734 - 1;
              if ( !v736 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v735);
              LOWORD(v735) = v1076 + v735;
              BYTE1(v724) = v727[2];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v735);
              v737 = v1135 + v735;
              v727[2] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v738 = v736 - 1;
              if ( !v738 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v737);
              LOWORD(v737) = v1076 + v737;
              BYTE1(v724) = v727[3];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v737);
              v739 = v1135 + v737;
              v727[3] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v740 = v738 - 1;
              if ( !v740 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v739);
              LOWORD(v739) = v1076 + v739;
              BYTE1(v724) = v727[4];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v739);
              v741 = v1135 + v739;
              v727[4] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v742 = v740 - 1;
              if ( !v742 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v741);
              LOWORD(v741) = v1076 + v741;
              BYTE1(v724) = v727[5];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v741);
              v743 = v1135 + v741;
              v727[5] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v744 = v742 - 1;
              if ( !v744 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v743);
              LOWORD(v743) = v1076 + v743;
              BYTE1(v724) = v727[6];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v743);
              v745 = v1135 + v743;
              v727[6] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v746 = v744 - 1;
              if ( !v746 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v745);
              LOWORD(v745) = v1076 + v745;
              BYTE1(v724) = v727[7];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v745);
              v747 = v1135 + v745;
              v727[7] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v748 = v746 - 1;
              if ( !v748 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v747);
              LOWORD(v747) = v1076 + v747;
              BYTE1(v724) = v727[8];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v747);
              v749 = v1135 + v747;
              v727[8] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v750 = v748 - 1;
              if ( !v750 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v749);
              LOWORD(v749) = v1076 + v749;
              BYTE1(v724) = v727[9];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v749);
              v751 = v1135 + v749;
              v727[9] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v752 = v750 - 1;
              if ( !v752 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v751);
              LOWORD(v751) = v1076 + v751;
              BYTE1(v724) = v727[10];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v751);
              v753 = v1135 + v751;
              v727[10] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v754 = v752 - 1;
              if ( !v754 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v753);
              LOWORD(v753) = v1076 + v753;
              BYTE1(v724) = v727[11];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v753);
              v755 = v1135 + v753;
              v727[11] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v756 = v754 - 1;
              if ( !v756 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v755);
              LOWORD(v755) = v1076 + v755;
              BYTE1(v724) = v727[12];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v755);
              v757 = v1135 + v755;
              v727[12] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v758 = v756 - 1;
              if ( !v758 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v757);
              LOWORD(v757) = v1076 + v757;
              BYTE1(v724) = v727[13];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v757);
              v759 = v1135 + v757;
              v727[13] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v760 = v758 - 1;
              if ( !v760 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v759);
              LOWORD(v759) = v1076 + v759;
              BYTE1(v724) = v727[14];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v759);
              v761 = v1135 + v759;
              v727[14] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              v762 = v760 - 1;
              if ( !v762 )
                break;
              LOBYTE(v724) = *(_BYTE *)(v725 + v732);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v761);
              LOWORD(v761) = v1076 + v761;
              BYTE1(v724) = v727[15];
              LOBYTE(v725) = BYTE2(v1076) + v177 + v725;
              v177 = __CFADD__(v1135, v761);
              v730 = v1135 + v761;
              v727[15] = *(_BYTE *)(v724 + ((u32)ghost));
              BYTE1(v725) += BYTE2(v1077) + v177;
              LOWORD(v726) = v762 - 1;
              if ( !(_WORD)v726 )
                break;
              v727 += 16;
            }
            v723 = v1244;
          }
LABEL_932:
          v723 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v726 > vec_window_width )
          LOWORD(v726) = vec_window_width;
        v16 = (__int16)v726 <= (__int16)v724;
        LOWORD(v726) = v726 - v724;
        if ( v16 )
          goto LABEL_932;
        v727 += v724;
        v730 = __ROL4__(*((int *)v723 + 3), 16);
        BYTE1(v725) = v730;
        LOWORD(v730) = v723[4];
        LOBYTE(v725) = *((_BYTE *)v723 + 10);
        goto LABEL_913;
      case 20:
LABEL_934:
        v763 = (unsigned __int16 *)&polyscans;
        v1136 = v1077 SHL16;
        v1145 = v1078 SHL16;
        HIWORD(v764) = 0;
        HIWORD(v765) = 0;
        while ( 1 )
        {
          LOWORD(v764) = v763[1];
          v766 = v763[3];
          v767 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v764 & 0x8000u) == 0 )
            break;
          if ( (__int16)v766 > 0 )
          {
            if ( v766 > vec_window_width )
              v766 = vec_window_width;
            v1154 = v766;
            v768 = (unsigned __int16)-(__int16)v764;
            v769 = __ROL4__(*((int *)v763 + 3) + v1077 * v768, 16);
            BYTE1(v765) = v769;
            LOWORD(v769) = v763[4] + v1076 * v768;
            v764 = (unsigned int)(*((int *)v763 + 2) + v1076 * v768) >> 8;
            LOBYTE(v765) = (unsigned int)(*((int *)v763 + 2) + v1076 * v768) >> 16;
            v770 = __ROL4__(*((int *)v763 + 4) + v1078 * v768, 16);
            v764 = (unsigned __int16)v764;
LABEL_944:
            v1245 = v763;
            v771 = vec_map;
            while ( 1 )
            {
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v769);
              LOWORD(v769) = v1076 + v769;
              BYTE1(v764) = v770;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v769);
              v772 = v1136 + v769;
              LOBYTE(v764) = *v767;
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v770);
              v773 = v1145 + v770;
              *v767 = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v773) = BYTE2(v1078) + v177 + v773;
              v1155 = v1154 - 1;
              if ( !v1155 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v772);
              LOWORD(v772) = v1076 + v772;
              BYTE1(v764) = v773;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v772);
              v774 = v1136 + v772;
              LOBYTE(v764) = v767[1];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v773);
              v775 = v1145 + v773;
              v767[1] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v775) = BYTE2(v1078) + v177 + v775;
              v1156 = v1155 - 1;
              if ( !v1156 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v774);
              LOWORD(v774) = v1076 + v774;
              BYTE1(v764) = v775;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v774);
              v776 = v1136 + v774;
              LOBYTE(v764) = v767[2];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v775);
              v777 = v1145 + v775;
              v767[2] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v777) = BYTE2(v1078) + v177 + v777;
              v1157 = v1156 - 1;
              if ( !v1157 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v776);
              LOWORD(v776) = v1076 + v776;
              BYTE1(v764) = v777;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v776);
              v778 = v1136 + v776;
              LOBYTE(v764) = v767[3];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v777);
              v779 = v1145 + v777;
              v767[3] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v779) = BYTE2(v1078) + v177 + v779;
              v1158 = v1157 - 1;
              if ( !v1158 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v778);
              LOWORD(v778) = v1076 + v778;
              BYTE1(v764) = v779;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v778);
              v780 = v1136 + v778;
              LOBYTE(v764) = v767[4];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v779);
              v781 = v1145 + v779;
              v767[4] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v781) = BYTE2(v1078) + v177 + v781;
              v1159 = v1158 - 1;
              if ( !v1159 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v780);
              LOWORD(v780) = v1076 + v780;
              BYTE1(v764) = v781;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v780);
              v782 = v1136 + v780;
              LOBYTE(v764) = v767[5];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v781);
              v783 = v1145 + v781;
              v767[5] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v783) = BYTE2(v1078) + v177 + v783;
              v1160 = v1159 - 1;
              if ( !v1160 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v782);
              LOWORD(v782) = v1076 + v782;
              BYTE1(v764) = v783;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v782);
              v784 = v1136 + v782;
              LOBYTE(v764) = v767[6];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v783);
              v785 = v1145 + v783;
              v767[6] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v785) = BYTE2(v1078) + v177 + v785;
              v1161 = v1160 - 1;
              if ( !v1161 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v784);
              LOWORD(v784) = v1076 + v784;
              BYTE1(v764) = v785;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v784);
              v786 = v1136 + v784;
              LOBYTE(v764) = v767[7];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v785);
              v787 = v1145 + v785;
              v767[7] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v787) = BYTE2(v1078) + v177 + v787;
              v1162 = v1161 - 1;
              if ( !v1162 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v786);
              LOWORD(v786) = v1076 + v786;
              BYTE1(v764) = v787;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v786);
              v788 = v1136 + v786;
              LOBYTE(v764) = v767[8];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v787);
              v789 = v1145 + v787;
              v767[8] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v789) = BYTE2(v1078) + v177 + v789;
              v1163 = v1162 - 1;
              if ( !v1163 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v788);
              LOWORD(v788) = v1076 + v788;
              BYTE1(v764) = v789;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v788);
              v790 = v1136 + v788;
              LOBYTE(v764) = v767[9];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v789);
              v791 = v1145 + v789;
              v767[9] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v791) = BYTE2(v1078) + v177 + v791;
              v1164 = v1163 - 1;
              if ( !v1164 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v790);
              LOWORD(v790) = v1076 + v790;
              BYTE1(v764) = v791;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v790);
              v792 = v1136 + v790;
              LOBYTE(v764) = v767[10];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v791);
              v793 = v1145 + v791;
              v767[10] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v793) = BYTE2(v1078) + v177 + v793;
              v1165 = v1164 - 1;
              if ( !v1165 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v792);
              LOWORD(v792) = v1076 + v792;
              BYTE1(v764) = v793;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v792);
              v794 = v1136 + v792;
              LOBYTE(v764) = v767[11];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v793);
              v795 = v1145 + v793;
              v767[11] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v795) = BYTE2(v1078) + v177 + v795;
              v1166 = v1165 - 1;
              if ( !v1166 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v794);
              LOWORD(v794) = v1076 + v794;
              BYTE1(v764) = v795;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v794);
              v796 = v1136 + v794;
              LOBYTE(v764) = v767[12];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v795);
              v797 = v1145 + v795;
              v767[12] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v797) = BYTE2(v1078) + v177 + v797;
              v1167 = v1166 - 1;
              if ( !v1167 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v796);
              LOWORD(v796) = v1076 + v796;
              BYTE1(v764) = v797;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v796);
              v798 = v1136 + v796;
              LOBYTE(v764) = v767[13];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v797);
              v799 = v1145 + v797;
              v767[13] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v799) = BYTE2(v1078) + v177 + v799;
              v1168 = v1167 - 1;
              if ( !v1168 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v798);
              LOWORD(v798) = v1076 + v798;
              BYTE1(v764) = v799;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v798);
              v800 = v1136 + v798;
              LOBYTE(v764) = v767[14];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v799);
              v801 = v1145 + v799;
              v767[14] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v801) = BYTE2(v1078) + v177 + v801;
              v1169 = v1168 - 1;
              if ( !v1169 )
                break;
              LOBYTE(v764) = *(_BYTE *)(v765 + v771);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v800);
              LOWORD(v800) = v1076 + v800;
              BYTE1(v764) = v801;
              LOBYTE(v765) = BYTE2(v1076) + v177 + v765;
              BYTE1(v764) = *(_BYTE *)(v764 + ((u32) tables_start));
              v177 = __CFADD__(v1136, v800);
              v769 = v1136 + v800;
              LOBYTE(v764) = v767[15];
              BYTE1(v765) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1145, v801);
              v770 = v1145 + v801;
              v767[15] = *(_BYTE *)(v764 + ((u32)ghost));
              LOBYTE(v770) = BYTE2(v1078) + v177 + v770;
              v1154 = v1169 - 1;
              if ( !v1154 )
                break;
              v767 += 16;
            }
            v763 = v1245;
          }
LABEL_963:
          v763 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v766 > vec_window_width )
          v766 = vec_window_width;
        v16 = (__int16)v766 <= (__int16)v764;
        LOWORD(v766) = v766 - v764;
        if ( v16 )
          goto LABEL_963;
        v767 += v764;
        v769 = __ROL4__(*((int *)v763 + 3), 16);
        BYTE1(v765) = v769;
        LOWORD(v769) = v763[4];
        LOBYTE(v765) = *((_BYTE *)v763 + 10);
        v1154 = v766;
        v770 = __ROL4__(*((int *)v763 + 4), 16);
        goto LABEL_944;
      case 21:
LABEL_965:
        v802 = (unsigned __int16 *)&polyscans;
        v1137 = v1077 SHL16;
        v1146 = v1078 SHL16;
        HIWORD(v803) = 0;
        HIWORD(v804) = 0;
        while ( 1 )
        {
          LOWORD(v803) = v802[1];
          v805 = v802[3];
          v806 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v803 & 0x8000u) == 0 )
            break;
          if ( (__int16)v805 > 0 )
          {
            if ( v805 > vec_window_width )
              v805 = vec_window_width;
            v1170 = v805;
            v807 = (unsigned __int16)-(__int16)v803;
            v808 = __ROL4__(*((int *)v802 + 3) + v1077 * v807, 16);
            BYTE1(v804) = v808;
            LOWORD(v808) = v802[4] + v1076 * v807;
            v803 = (unsigned int)(*((int *)v802 + 2) + v1076 * v807) >> 8;
            LOBYTE(v804) = (unsigned int)(*((int *)v802 + 2) + v1076 * v807) >> 16;
            v809 = __ROL4__(*((int *)v802 + 4) + v1078 * v807, 16);
            v803 = (unsigned __int16)v803;
LABEL_975:
            v1246 = v802;
            v810 = vec_map;
            while ( 1 )
            {
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v808);
              LOWORD(v808) = v1076 + v808;
              BYTE1(v803) = v809;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v808);
              v811 = v1137 + v808;
              BYTE1(v803) = *v806;
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v809);
              v812 = v1146 + v809;
              *v806 = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v812) = BYTE2(v1078) + v177 + v812;
              v1171 = v1170 - 1;
              if ( !v1171 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v811);
              LOWORD(v811) = v1076 + v811;
              BYTE1(v803) = v812;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v811);
              v813 = v1137 + v811;
              BYTE1(v803) = v806[1];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v812);
              v814 = v1146 + v812;
              v806[1] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v814) = BYTE2(v1078) + v177 + v814;
              v1172 = v1171 - 1;
              if ( !v1172 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v813);
              LOWORD(v813) = v1076 + v813;
              BYTE1(v803) = v814;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v813);
              v815 = v1137 + v813;
              BYTE1(v803) = v806[2];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v814);
              v816 = v1146 + v814;
              v806[2] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v816) = BYTE2(v1078) + v177 + v816;
              v1173 = v1172 - 1;
              if ( !v1173 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v815);
              LOWORD(v815) = v1076 + v815;
              BYTE1(v803) = v816;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v815);
              v817 = v1137 + v815;
              BYTE1(v803) = v806[3];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v816);
              v818 = v1146 + v816;
              v806[3] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v818) = BYTE2(v1078) + v177 + v818;
              v1174 = v1173 - 1;
              if ( !v1174 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v817);
              LOWORD(v817) = v1076 + v817;
              BYTE1(v803) = v818;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v817);
              v819 = v1137 + v817;
              BYTE1(v803) = v806[4];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v818);
              v820 = v1146 + v818;
              v806[4] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v820) = BYTE2(v1078) + v177 + v820;
              v1175 = v1174 - 1;
              if ( !v1175 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v819);
              LOWORD(v819) = v1076 + v819;
              BYTE1(v803) = v820;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v819);
              v821 = v1137 + v819;
              BYTE1(v803) = v806[5];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v820);
              v822 = v1146 + v820;
              v806[5] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v822) = BYTE2(v1078) + v177 + v822;
              v1176 = v1175 - 1;
              if ( !v1176 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v821);
              LOWORD(v821) = v1076 + v821;
              BYTE1(v803) = v822;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v821);
              v823 = v1137 + v821;
              BYTE1(v803) = v806[6];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v822);
              v824 = v1146 + v822;
              v806[6] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v824) = BYTE2(v1078) + v177 + v824;
              v1177 = v1176 - 1;
              if ( !v1177 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v823);
              LOWORD(v823) = v1076 + v823;
              BYTE1(v803) = v824;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v823);
              v825 = v1137 + v823;
              BYTE1(v803) = v806[7];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v824);
              v826 = v1146 + v824;
              v806[7] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v826) = BYTE2(v1078) + v177 + v826;
              v1178 = v1177 - 1;
              if ( !v1178 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v825);
              LOWORD(v825) = v1076 + v825;
              BYTE1(v803) = v826;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v825);
              v827 = v1137 + v825;
              BYTE1(v803) = v806[8];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v826);
              v828 = v1146 + v826;
              v806[8] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v828) = BYTE2(v1078) + v177 + v828;
              v1179 = v1178 - 1;
              if ( !v1179 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v827);
              LOWORD(v827) = v1076 + v827;
              BYTE1(v803) = v828;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v827);
              v829 = v1137 + v827;
              BYTE1(v803) = v806[9];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v828);
              v830 = v1146 + v828;
              v806[9] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v830) = BYTE2(v1078) + v177 + v830;
              v1180 = v1179 - 1;
              if ( !v1180 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v829);
              LOWORD(v829) = v1076 + v829;
              BYTE1(v803) = v830;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v829);
              v831 = v1137 + v829;
              BYTE1(v803) = v806[10];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v830);
              v832 = v1146 + v830;
              v806[10] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v832) = BYTE2(v1078) + v177 + v832;
              v1181 = v1180 - 1;
              if ( !v1181 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v831);
              LOWORD(v831) = v1076 + v831;
              BYTE1(v803) = v832;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v831);
              v833 = v1137 + v831;
              BYTE1(v803) = v806[11];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v832);
              v834 = v1146 + v832;
              v806[11] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v834) = BYTE2(v1078) + v177 + v834;
              v1182 = v1181 - 1;
              if ( !v1182 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v833);
              LOWORD(v833) = v1076 + v833;
              BYTE1(v803) = v834;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v833);
              v835 = v1137 + v833;
              BYTE1(v803) = v806[12];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v834);
              v836 = v1146 + v834;
              v806[12] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v836) = BYTE2(v1078) + v177 + v836;
              v1183 = v1182 - 1;
              if ( !v1183 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v835);
              LOWORD(v835) = v1076 + v835;
              BYTE1(v803) = v836;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v835);
              v837 = v1137 + v835;
              BYTE1(v803) = v806[13];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v836);
              v838 = v1146 + v836;
              v806[13] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v838) = BYTE2(v1078) + v177 + v838;
              v1184 = v1183 - 1;
              if ( !v1184 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v837);
              LOWORD(v837) = v1076 + v837;
              BYTE1(v803) = v838;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v837);
              v839 = v1137 + v837;
              BYTE1(v803) = v806[14];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v838);
              v840 = v1146 + v838;
              v806[14] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v840) = BYTE2(v1078) + v177 + v840;
              v1185 = v1184 - 1;
              if ( !v1185 )
                break;
              LOBYTE(v803) = *(_BYTE *)(v804 + v810);
              v177 = __CFADD__((_WORD)v1076, (_WORD)v839);
              LOWORD(v839) = v1076 + v839;
              BYTE1(v803) = v840;
              LOBYTE(v804) = BYTE2(v1076) + v177 + v804;
              LOBYTE(v803) = *(_BYTE *)(v803 + ((u32) tables_start));
              v177 = __CFADD__(v1137, v839);
              v808 = v1137 + v839;
              BYTE1(v803) = v806[15];
              BYTE1(v804) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1146, v840);
              v809 = v1146 + v840;
              v806[15] = *(_BYTE *)(v803 + ((u32)ghost));
              LOBYTE(v809) = BYTE2(v1078) + v177 + v809;
              v1170 = v1185 - 1;
              if ( !v1170 )
                break;
              v806 += 16;
            }
            v802 = v1246;
          }
LABEL_994:
          v802 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v805 > vec_window_width )
          v805 = vec_window_width;
        v16 = (__int16)v805 <= (__int16)v803;
        LOWORD(v805) = v805 - v803;
        if ( v16 )
          goto LABEL_994;
        v806 += v803;
        v808 = __ROL4__(*((int *)v802 + 3), 16);
        BYTE1(v804) = v808;
        LOWORD(v808) = v802[4];
        LOBYTE(v804) = *((_BYTE *)v802 + 10);
        v1170 = v805;
        v809 = __ROL4__(*((int *)v802 + 4), 16);
        goto LABEL_975;
      case 22:
LABEL_996:
        v841 = (unsigned __int16 *)&polyscans;
        v1138 = v1077 SHL16;
        HIWORD(v842) = 0;
        HIWORD(v843) = 0;
        while ( 1 )
        {
          LOWORD(v842) = v841[1];
          v844 = v841[3];
          v845 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v842 & 0x8000u) == 0 )
            break;
          if ( (__int16)v844 > 0 )
          {
            v846 = (unsigned __int16)-(__int16)v842;
            v848 = __ROL4__(*((int *)v841 + 3) + v1077 * v846, 16);
            BYTE1(v843) = v848;
            v847 = *((int *)v841 + 2) + v1076 * v846;
            LOWORD(v848) = v847;
            v849 = v847 >> 8;
            LOBYTE(v843) = BYTE1(v849);
            if ( v844 > vec_window_width )
              LOWORD(v844) = vec_window_width;
            v842 = (unsigned __int16)v849;
LABEL_1006:
            v1247 = v841;
            v850 = vec_map;
            while ( 1 )
            {
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = *v845;
                *v845 = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v848);
              LOWORD(v848) = v1076 + v848;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v848);
              v851 = v1138 + v848;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v852 = v844 - 1;
              if ( !v852 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[1];
                v845[1] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v851);
              LOWORD(v851) = v1076 + v851;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v851);
              v853 = v1138 + v851;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v854 = v852 - 1;
              if ( !v854 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[2];
                v845[2] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v853);
              LOWORD(v853) = v1076 + v853;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v853);
              v855 = v1138 + v853;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v856 = v854 - 1;
              if ( !v856 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[3];
                v845[3] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v855);
              LOWORD(v855) = v1076 + v855;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v855);
              v857 = v1138 + v855;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v858 = v856 - 1;
              if ( !v858 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[4];
                v845[4] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v857);
              LOWORD(v857) = v1076 + v857;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v857);
              v859 = v1138 + v857;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v860 = v858 - 1;
              if ( !v860 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[5];
                v845[5] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v859);
              LOWORD(v859) = v1076 + v859;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v859);
              v861 = v1138 + v859;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v862 = v860 - 1;
              if ( !v862 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[6];
                v845[6] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v861);
              LOWORD(v861) = v1076 + v861;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v861);
              v863 = v1138 + v861;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v864 = v862 - 1;
              if ( !v864 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[7];
                v845[7] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v863);
              LOWORD(v863) = v1076 + v863;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v863);
              v865 = v1138 + v863;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v866 = v864 - 1;
              if ( !v866 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[8];
                v845[8] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v865);
              LOWORD(v865) = v1076 + v865;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v865);
              v867 = v1138 + v865;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v868 = v866 - 1;
              if ( !v868 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[9];
                v845[9] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v867);
              LOWORD(v867) = v1076 + v867;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v867);
              v869 = v1138 + v867;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v870 = v868 - 1;
              if ( !v870 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[10];
                v845[10] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v869);
              LOWORD(v869) = v1076 + v869;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v869);
              v871 = v1138 + v869;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v872 = v870 - 1;
              if ( !v872 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[11];
                v845[11] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v871);
              LOWORD(v871) = v1076 + v871;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v871);
              v873 = v1138 + v871;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v874 = v872 - 1;
              if ( !v874 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[12];
                v845[12] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v873);
              LOWORD(v873) = v1076 + v873;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v873);
              v875 = v1138 + v873;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v876 = v874 - 1;
              if ( !v876 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[13];
                v845[13] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v875);
              LOWORD(v875) = v1076 + v875;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v875);
              v877 = v1138 + v875;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v878 = v876 - 1;
              if ( !v878 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[14];
                v845[14] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v877);
              LOWORD(v877) = v1076 + v877;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v877);
              v879 = v1138 + v877;
              BYTE1(v843) += BYTE2(v1077) + v177;
              v880 = v878 - 1;
              if ( !v880 )
                break;
              BYTE1(v842) = *(_BYTE *)(v843 + v850);
              if ( BYTE1(v842) )
              {
                LOBYTE(v842) = v845[15];
                v845[15] = *(_BYTE *)(v842 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v879);
              LOWORD(v879) = v1076 + v879;
              LOBYTE(v843) = BYTE2(v1076) + v177 + v843;
              v177 = __CFADD__(v1138, v879);
              v848 = v1138 + v879;
              BYTE1(v843) += BYTE2(v1077) + v177;
              LOWORD(v844) = v880 - 1;
              if ( !(_WORD)v844 )
                break;
              v845 += 16;
            }
            v841 = v1247;
          }
LABEL_1057:
          v841 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v844 > vec_window_width )
          LOWORD(v844) = vec_window_width;
        v16 = (__int16)v844 <= (__int16)v842;
        LOWORD(v844) = v844 - v842;
        if ( v16 )
          goto LABEL_1057;
        v845 += v842;
        v848 = __ROL4__(*((int *)v841 + 3), 16);
        BYTE1(v843) = v848;
        LOWORD(v848) = v841[4];
        LOBYTE(v843) = *((_BYTE *)v841 + 10);
        goto LABEL_1006;
      case 23:
LABEL_1059:
        v881 = (unsigned __int16 *)&polyscans;
        v1139 = v1077 SHL16;
        HIWORD(v882) = 0;
        HIWORD(v883) = 0;
        while ( 1 )
        {
          LOWORD(v882) = v881[1];
          v884 = v881[3];
          v885 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v882 & 0x8000u) == 0 )
            break;
          if ( (__int16)v884 > 0 )
          {
            v886 = (unsigned __int16)-(__int16)v882;
            v888 = __ROL4__(*((int *)v881 + 3) + v1077 * v886, 16);
            BYTE1(v883) = v888;
            v887 = *((int *)v881 + 2) + v1076 * v886;
            LOWORD(v888) = v887;
            v889 = v887 >> 8;
            LOBYTE(v883) = BYTE1(v889);
            if ( v884 > vec_window_width )
              LOWORD(v884) = vec_window_width;
            v882 = (unsigned __int16)v889;
LABEL_1069:
            v1248 = v881;
            v890 = vec_map;
            while ( 1 )
            {
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = *v885;
                *v885 = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v888);
              LOWORD(v888) = v1076 + v888;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v888);
              v891 = v1139 + v888;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v892 = v884 - 1;
              if ( !v892 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[1];
                v885[1] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v891);
              LOWORD(v891) = v1076 + v891;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v891);
              v893 = v1139 + v891;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v894 = v892 - 1;
              if ( !v894 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[2];
                v885[2] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v893);
              LOWORD(v893) = v1076 + v893;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v893);
              v895 = v1139 + v893;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v896 = v894 - 1;
              if ( !v896 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[3];
                v885[3] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v895);
              LOWORD(v895) = v1076 + v895;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v895);
              v897 = v1139 + v895;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v898 = v896 - 1;
              if ( !v898 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[4];
                v885[4] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v897);
              LOWORD(v897) = v1076 + v897;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v897);
              v899 = v1139 + v897;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v900 = v898 - 1;
              if ( !v900 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[5];
                v885[5] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v899);
              LOWORD(v899) = v1076 + v899;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v899);
              v901 = v1139 + v899;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v902 = v900 - 1;
              if ( !v902 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[6];
                v885[6] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v901);
              LOWORD(v901) = v1076 + v901;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v901);
              v903 = v1139 + v901;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v904 = v902 - 1;
              if ( !v904 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[7];
                v885[7] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v903);
              LOWORD(v903) = v1076 + v903;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v903);
              v905 = v1139 + v903;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v906 = v904 - 1;
              if ( !v906 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[8];
                v885[8] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v905);
              LOWORD(v905) = v1076 + v905;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v905);
              v907 = v1139 + v905;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v908 = v906 - 1;
              if ( !v908 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[9];
                v885[9] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v907);
              LOWORD(v907) = v1076 + v907;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v907);
              v909 = v1139 + v907;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v910 = v908 - 1;
              if ( !v910 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[10];
                v885[10] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v909);
              LOWORD(v909) = v1076 + v909;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v909);
              v911 = v1139 + v909;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v912 = v910 - 1;
              if ( !v912 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[11];
                v885[11] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v911);
              LOWORD(v911) = v1076 + v911;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v911);
              v913 = v1139 + v911;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v914 = v912 - 1;
              if ( !v914 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[12];
                v885[12] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v913);
              LOWORD(v913) = v1076 + v913;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v913);
              v915 = v1139 + v913;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v916 = v914 - 1;
              if ( !v916 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[13];
                v885[13] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v915);
              LOWORD(v915) = v1076 + v915;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v915);
              v917 = v1139 + v915;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v918 = v916 - 1;
              if ( !v918 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[14];
                v885[14] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v917);
              LOWORD(v917) = v1076 + v917;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v917);
              v919 = v1139 + v917;
              BYTE1(v883) += BYTE2(v1077) + v177;
              v920 = v918 - 1;
              if ( !v920 )
                break;
              LOBYTE(v882) = *(_BYTE *)(v883 + v890);
              if ( (_BYTE)v882 )
              {
                BYTE1(v882) = v885[15];
                v885[15] = *(_BYTE *)(v882 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v919);
              LOWORD(v919) = v1076 + v919;
              LOBYTE(v883) = BYTE2(v1076) + v177 + v883;
              v177 = __CFADD__(v1139, v919);
              v888 = v1139 + v919;
              BYTE1(v883) += BYTE2(v1077) + v177;
              LOWORD(v884) = v920 - 1;
              if ( !(_WORD)v884 )
                break;
              v885 += 16;
            }
            v881 = v1248;
          }
LABEL_1120:
          v881 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v884 > vec_window_width )
          LOWORD(v884) = vec_window_width;
        v16 = (__int16)v884 <= (__int16)v882;
        LOWORD(v884) = v884 - v882;
        if ( v16 )
          goto LABEL_1120;
        v885 += v882;
        v888 = __ROL4__(*((int *)v881 + 3), 16);
        BYTE1(v883) = v888;
        LOWORD(v888) = v881[4];
        LOBYTE(v883) = *((_BYTE *)v881 + 10);
        goto LABEL_1069;
      case 24:
LABEL_1122:
        v921 = (unsigned __int16 *)&polyscans;
        v1140 = v1077 SHL16;
        v1147 = v1078 SHL16;
        HIWORD(v922) = 0;
        HIWORD(v923) = 0;
        while ( 1 )
        {
          LOWORD(v922) = v921[1];
          v924 = v921[3];
          v925 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v922 & 0x8000u) == 0 )
            break;
          if ( (__int16)v924 > 0 )
          {
            if ( v924 > vec_window_width )
              v924 = vec_window_width;
            v1186 = v924;
            v926 = (unsigned __int16)-(__int16)v922;
            v927 = __ROL4__(*((int *)v921 + 3) + v1077 * v926, 16);
            BYTE1(v923) = v927;
            LOWORD(v927) = v921[4] + v1076 * v926;
            v922 = (unsigned int)(*((int *)v921 + 2) + v1076 * v926) >> 8;
            LOBYTE(v923) = (unsigned int)(*((int *)v921 + 2) + v1076 * v926) >> 16;
            v928 = __ROL4__(*((int *)v921 + 4) + v1078 * v926, 16);
            v922 = (unsigned __int16)v922;
LABEL_1132:
            v1249 = v921;
            v929 = vec_map;
            while ( 1 )
            {
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v928;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = *v925;
                *v925 = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v927);
              LOWORD(v927) = v1076 + v927;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v927);
              v930 = v1140 + v927;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v928);
              v931 = v1147 + v928;
              LOBYTE(v931) = BYTE2(v1078) + v177 + v931;
              v1187 = v1186 - 1;
              if ( !v1187 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v931;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[1];
                v925[1] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v930);
              LOWORD(v930) = v1076 + v930;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v930);
              v932 = v1140 + v930;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v931);
              v933 = v1147 + v931;
              LOBYTE(v933) = BYTE2(v1078) + v177 + v933;
              v1188 = v1187 - 1;
              if ( !v1188 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v933;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[2];
                v925[2] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v932);
              LOWORD(v932) = v1076 + v932;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v932);
              v934 = v1140 + v932;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v933);
              v935 = v1147 + v933;
              LOBYTE(v935) = BYTE2(v1078) + v177 + v935;
              v1189 = v1188 - 1;
              if ( !v1189 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v935;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[3];
                v925[3] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v934);
              LOWORD(v934) = v1076 + v934;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v934);
              v936 = v1140 + v934;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v935);
              v937 = v1147 + v935;
              LOBYTE(v937) = BYTE2(v1078) + v177 + v937;
              v1190 = v1189 - 1;
              if ( !v1190 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v937;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[4];
                v925[4] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v936);
              LOWORD(v936) = v1076 + v936;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v936);
              v938 = v1140 + v936;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v937);
              v939 = v1147 + v937;
              LOBYTE(v939) = BYTE2(v1078) + v177 + v939;
              v1191 = v1190 - 1;
              if ( !v1191 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v939;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[5];
                v925[5] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v938);
              LOWORD(v938) = v1076 + v938;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v938);
              v940 = v1140 + v938;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v939);
              v941 = v1147 + v939;
              LOBYTE(v941) = BYTE2(v1078) + v177 + v941;
              v1192 = v1191 - 1;
              if ( !v1192 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v941;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[6];
                v925[6] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v940);
              LOWORD(v940) = v1076 + v940;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v940);
              v942 = v1140 + v940;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v941);
              v943 = v1147 + v941;
              LOBYTE(v943) = BYTE2(v1078) + v177 + v943;
              v1193 = v1192 - 1;
              if ( !v1193 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v943;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[7];
                v925[7] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v942);
              LOWORD(v942) = v1076 + v942;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v942);
              v944 = v1140 + v942;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v943);
              v945 = v1147 + v943;
              LOBYTE(v945) = BYTE2(v1078) + v177 + v945;
              v1194 = v1193 - 1;
              if ( !v1194 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v945;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[8];
                v925[8] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v944);
              LOWORD(v944) = v1076 + v944;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v944);
              v946 = v1140 + v944;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v945);
              v947 = v1147 + v945;
              LOBYTE(v947) = BYTE2(v1078) + v177 + v947;
              v1195 = v1194 - 1;
              if ( !v1195 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v947;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[9];
                v925[9] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v946);
              LOWORD(v946) = v1076 + v946;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v946);
              v948 = v1140 + v946;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v947);
              v949 = v1147 + v947;
              LOBYTE(v949) = BYTE2(v1078) + v177 + v949;
              v1196 = v1195 - 1;
              if ( !v1196 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v949;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[10];
                v925[10] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v948);
              LOWORD(v948) = v1076 + v948;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v948);
              v950 = v1140 + v948;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v949);
              v951 = v1147 + v949;
              LOBYTE(v951) = BYTE2(v1078) + v177 + v951;
              v1197 = v1196 - 1;
              if ( !v1197 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v951;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[11];
                v925[11] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v950);
              LOWORD(v950) = v1076 + v950;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v950);
              v952 = v1140 + v950;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v951);
              v953 = v1147 + v951;
              LOBYTE(v953) = BYTE2(v1078) + v177 + v953;
              v1198 = v1197 - 1;
              if ( !v1198 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v953;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[12];
                v925[12] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v952);
              LOWORD(v952) = v1076 + v952;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v952);
              v954 = v1140 + v952;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v953);
              v955 = v1147 + v953;
              LOBYTE(v955) = BYTE2(v1078) + v177 + v955;
              v1199 = v1198 - 1;
              if ( !v1199 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v955;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[13];
                v925[13] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v954);
              LOWORD(v954) = v1076 + v954;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v954);
              v956 = v1140 + v954;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v955);
              v957 = v1147 + v955;
              LOBYTE(v957) = BYTE2(v1078) + v177 + v957;
              v1200 = v1199 - 1;
              if ( !v1200 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v957;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[14];
                v925[14] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v956);
              LOWORD(v956) = v1076 + v956;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v956);
              v958 = v1140 + v956;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v957);
              v959 = v1147 + v957;
              LOBYTE(v959) = BYTE2(v1078) + v177 + v959;
              v1201 = v1200 - 1;
              if ( !v1201 )
                break;
              LOBYTE(v922) = *(_BYTE *)(v923 + v929);
              if ( (_BYTE)v922 )
              {
                BYTE1(v922) = v959;
                BYTE1(v922) = *(_BYTE *)(v922 + ((u32) tables_start));
                LOBYTE(v922) = v925[15];
                v925[15] = *(_BYTE *)(v922 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v958);
              LOWORD(v958) = v1076 + v958;
              LOBYTE(v923) = BYTE2(v1076) + v177 + v923;
              v177 = __CFADD__(v1140, v958);
              v927 = v1140 + v958;
              BYTE1(v923) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1147, v959);
              v928 = v1147 + v959;
              LOBYTE(v928) = BYTE2(v1078) + v177 + v928;
              v1186 = v1201 - 1;
              if ( !v1186 )
                break;
              v925 += 16;
            }
            v921 = v1249;
          }
LABEL_1183:
          v921 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v924 > vec_window_width )
          v924 = vec_window_width;
        v16 = (__int16)v924 <= (__int16)v922;
        LOWORD(v924) = v924 - v922;
        if ( v16 )
          goto LABEL_1183;
        v925 += v922;
        v927 = __ROL4__(*((int *)v921 + 3), 16);
        BYTE1(v923) = v927;
        LOWORD(v927) = v921[4];
        LOBYTE(v923) = *((_BYTE *)v921 + 10);
        v1186 = v924;
        v928 = __ROL4__(*((int *)v921 + 4), 16);
        goto LABEL_1132;
      case 25:
LABEL_1185:
        v960 = (unsigned __int16 *)&polyscans;
        v1141 = v1077 SHL16;
        v1148 = v1078 SHL16;
        HIWORD(v961) = 0;
        HIWORD(v962) = 0;
        while ( 1 )
        {
          LOWORD(v961) = v960[1];
          v963 = v960[3];
          v964 = (_BYTE *)(vec_screen_width + v1054);
          v1054 += vec_screen_width;
          if ( (v961 & 0x8000u) == 0 )
            break;
          if ( (__int16)v963 > 0 )
          {
            if ( v963 > vec_window_width )
              v963 = vec_window_width;
            v1202 = v963;
            v965 = (unsigned __int16)-(__int16)v961;
            v966 = __ROL4__(*((int *)v960 + 3) + v1077 * v965, 16);
            BYTE1(v962) = v966;
            LOWORD(v966) = v960[4] + v1076 * v965;
            v961 = (unsigned int)(*((int *)v960 + 2) + v1076 * v965) >> 8;
            LOBYTE(v962) = (unsigned int)(*((int *)v960 + 2) + v1076 * v965) >> 16;
            v967 = __ROL4__(*((int *)v960 + 4) + v1078 * v965, 16);
            v961 = (unsigned __int16)v961;
LABEL_1195:
            v1250 = v960;
            v968 = vec_map;
            while ( 1 )
            {
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v967;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = *v964;
                *v964 = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v966);
              LOWORD(v966) = v1076 + v966;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v966);
              v969 = v1141 + v966;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v967);
              v970 = v1148 + v967;
              LOBYTE(v970) = BYTE2(v1078) + v177 + v970;
              v1203 = v1202 - 1;
              if ( !v1203 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v970;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[1];
                v964[1] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v969);
              LOWORD(v969) = v1076 + v969;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v969);
              v971 = v1141 + v969;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v970);
              v972 = v1148 + v970;
              LOBYTE(v972) = BYTE2(v1078) + v177 + v972;
              v1204 = v1203 - 1;
              if ( !v1204 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v972;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[2];
                v964[2] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v971);
              LOWORD(v971) = v1076 + v971;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v971);
              v973 = v1141 + v971;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v972);
              v974 = v1148 + v972;
              LOBYTE(v974) = BYTE2(v1078) + v177 + v974;
              v1205 = v1204 - 1;
              if ( !v1205 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v974;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[3];
                v964[3] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v973);
              LOWORD(v973) = v1076 + v973;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v973);
              v975 = v1141 + v973;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v974);
              v976 = v1148 + v974;
              LOBYTE(v976) = BYTE2(v1078) + v177 + v976;
              v1206 = v1205 - 1;
              if ( !v1206 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v976;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[4];
                v964[4] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v975);
              LOWORD(v975) = v1076 + v975;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v975);
              v977 = v1141 + v975;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v976);
              v978 = v1148 + v976;
              LOBYTE(v978) = BYTE2(v1078) + v177 + v978;
              v1207 = v1206 - 1;
              if ( !v1207 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v978;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[5];
                v964[5] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v977);
              LOWORD(v977) = v1076 + v977;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v977);
              v979 = v1141 + v977;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v978);
              v980 = v1148 + v978;
              LOBYTE(v980) = BYTE2(v1078) + v177 + v980;
              v1208 = v1207 - 1;
              if ( !v1208 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v980;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[6];
                v964[6] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v979);
              LOWORD(v979) = v1076 + v979;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v979);
              v981 = v1141 + v979;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v980);
              v982 = v1148 + v980;
              LOBYTE(v982) = BYTE2(v1078) + v177 + v982;
              v1209 = v1208 - 1;
              if ( !v1209 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v982;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[7];
                v964[7] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v981);
              LOWORD(v981) = v1076 + v981;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v981);
              v983 = v1141 + v981;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v982);
              v984 = v1148 + v982;
              LOBYTE(v984) = BYTE2(v1078) + v177 + v984;
              v1210 = v1209 - 1;
              if ( !v1210 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v984;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[8];
                v964[8] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v983);
              LOWORD(v983) = v1076 + v983;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v983);
              v985 = v1141 + v983;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v984);
              v986 = v1148 + v984;
              LOBYTE(v986) = BYTE2(v1078) + v177 + v986;
              v1211 = v1210 - 1;
              if ( !v1211 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v986;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[9];
                v964[9] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v985);
              LOWORD(v985) = v1076 + v985;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v985);
              v987 = v1141 + v985;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v986);
              v988 = v1148 + v986;
              LOBYTE(v988) = BYTE2(v1078) + v177 + v988;
              v1212 = v1211 - 1;
              if ( !v1212 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v988;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[10];
                v964[10] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v987);
              LOWORD(v987) = v1076 + v987;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v987);
              v989 = v1141 + v987;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v988);
              v990 = v1148 + v988;
              LOBYTE(v990) = BYTE2(v1078) + v177 + v990;
              v1213 = v1212 - 1;
              if ( !v1213 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v990;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[11];
                v964[11] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v989);
              LOWORD(v989) = v1076 + v989;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v989);
              v991 = v1141 + v989;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v990);
              v992 = v1148 + v990;
              LOBYTE(v992) = BYTE2(v1078) + v177 + v992;
              v1214 = v1213 - 1;
              if ( !v1214 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v992;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[12];
                v964[12] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v991);
              LOWORD(v991) = v1076 + v991;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v991);
              v993 = v1141 + v991;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v992);
              v994 = v1148 + v992;
              LOBYTE(v994) = BYTE2(v1078) + v177 + v994;
              v1215 = v1214 - 1;
              if ( !v1215 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v994;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[13];
                v964[13] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v993);
              LOWORD(v993) = v1076 + v993;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v993);
              v995 = v1141 + v993;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v994);
              v996 = v1148 + v994;
              LOBYTE(v996) = BYTE2(v1078) + v177 + v996;
              v1216 = v1215 - 1;
              if ( !v1216 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v996;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[14];
                v964[14] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v995);
              LOWORD(v995) = v1076 + v995;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v995);
              v997 = v1141 + v995;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v996);
              v998 = v1148 + v996;
              LOBYTE(v998) = BYTE2(v1078) + v177 + v998;
              v1217 = v1216 - 1;
              if ( !v1217 )
                break;
              LOBYTE(v961) = *(_BYTE *)(v962 + v968);
              if ( (_BYTE)v961 )
              {
                BYTE1(v961) = v998;
                LOBYTE(v961) = *(_BYTE *)(v961 + ((u32) tables_start));
                BYTE1(v961) = v964[15];
                v964[15] = *(_BYTE *)(v961 + ((u32)ghost));
              }
              v177 = __CFADD__((_WORD)v1076, (_WORD)v997);
              LOWORD(v997) = v1076 + v997;
              LOBYTE(v962) = BYTE2(v1076) + v177 + v962;
              v177 = __CFADD__(v1141, v997);
              v966 = v1141 + v997;
              BYTE1(v962) += BYTE2(v1077) + v177;
              v177 = __CFADD__(v1148, v998);
              v967 = v1148 + v998;
              LOBYTE(v967) = BYTE2(v1078) + v177 + v967;
              v1202 = v1217 - 1;
              if ( !v1202 )
                break;
              v964 += 16;
            }
            v960 = v1250;
          }
LABEL_1246:
          v960 += 10;
          if ( !--v1075 )
            return;
        }
        if ( v963 > vec_window_width )
          v963 = vec_window_width;
        v16 = (__int16)v963 <= (__int16)v961;
        LOWORD(v963) = v963 - v961;
        if ( v16 )
          goto LABEL_1246;
        v964 += v961;
        v966 = __ROL4__(*((int *)v960 + 3), 16);
        BYTE1(v962) = v966;
        LOWORD(v966) = v960[4];
        LOBYTE(v962) = *((_BYTE *)v960 + 10);
        v1202 = v963;
        v967 = __ROL4__(*((int *)v960 + 4), 16);
        goto LABEL_1195;
      case 26:
LABEL_1248:
        v999 = (unsigned __int16 *)&polyscans;
        v1142 = v1077 SHL16;
        v1149 = v1078 SHL16;
        HIWORD(v1000) = 0;
        HIWORD(v1001) = 0;
        break;
    }
    while ( 1 )
    {
      LOWORD(v1000) = v999[1];
      v1002 = v999[3];
      v1003 = (_BYTE *)(vec_screen_width + v1054);
      v1054 += vec_screen_width;
      if ( (v1000 & 0x8000u) == 0 )
        break;
      if ( (__int16)v1002 > 0 )
      {
        if ( v1002 > vec_window_width )
          v1002 = vec_window_width;
        v1218 = v1002;
        v1004 = (unsigned __int16)-(__int16)v1000;
        v1005 = __ROL4__(*((int *)v999 + 3) + v1077 * v1004, 16);
        BYTE1(v1001) = v1005;
        LOWORD(v1005) = v999[4] + v1076 * v1004;
        v1000 = (unsigned int)(*((int *)v999 + 2) + v1076 * v1004) >> 8;
        LOBYTE(v1001) = (unsigned int)(*((int *)v999 + 2) + v1076 * v1004) >> 16;
        v1006 = __ROL4__(*((int *)v999 + 4) + v1078 * v1004, 16);
        v1000 = (unsigned __int16)v1000;
LABEL_1258:
        v1251 = v999;
        v1007 = vec_map;
        while ( 1 )
        {
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1005);
          LOWORD(v1005) = v1076 + v1005;
          BYTE1(v1000) = v1006;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1008 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = *v1003;
            v1008 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1005);
          v1009 = v1142 + v1005;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1006);
          v1010 = v1149 + v1006;
          *v1003 = v1008;
          LOBYTE(v1010) = BYTE2(v1078) + v177 + v1010;
          v1219 = v1218 - 1;
          if ( !v1219 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1009);
          LOWORD(v1009) = v1076 + v1009;
          BYTE1(v1000) = v1010;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1011 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[1];
            v1011 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1009);
          v1012 = v1142 + v1009;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1010);
          v1013 = v1149 + v1010;
          v1003[1] = v1011;
          LOBYTE(v1013) = BYTE2(v1078) + v177 + v1013;
          v1220 = v1219 - 1;
          if ( !v1220 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1012);
          LOWORD(v1012) = v1076 + v1012;
          BYTE1(v1000) = v1013;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1014 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[2];
            v1014 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1012);
          v1015 = v1142 + v1012;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1013);
          v1016 = v1149 + v1013;
          v1003[2] = v1014;
          LOBYTE(v1016) = BYTE2(v1078) + v177 + v1016;
          v1221 = v1220 - 1;
          if ( !v1221 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1015);
          LOWORD(v1015) = v1076 + v1015;
          BYTE1(v1000) = v1016;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1017 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[3];
            v1017 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1015);
          v1018 = v1142 + v1015;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1016);
          v1019 = v1149 + v1016;
          v1003[3] = v1017;
          LOBYTE(v1019) = BYTE2(v1078) + v177 + v1019;
          v1222 = v1221 - 1;
          if ( !v1222 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1018);
          LOWORD(v1018) = v1076 + v1018;
          BYTE1(v1000) = v1019;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1020 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[4];
            v1020 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1018);
          v1021 = v1142 + v1018;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1019);
          v1022 = v1149 + v1019;
          v1003[4] = v1020;
          LOBYTE(v1022) = BYTE2(v1078) + v177 + v1022;
          v1223 = v1222 - 1;
          if ( !v1223 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1021);
          LOWORD(v1021) = v1076 + v1021;
          BYTE1(v1000) = v1022;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1023 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[5];
            v1023 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1021);
          v1024 = v1142 + v1021;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1022);
          v1025 = v1149 + v1022;
          v1003[5] = v1023;
          LOBYTE(v1025) = BYTE2(v1078) + v177 + v1025;
          v1224 = v1223 - 1;
          if ( !v1224 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1024);
          LOWORD(v1024) = v1076 + v1024;
          BYTE1(v1000) = v1025;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1026 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[6];
            v1026 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1024);
          v1027 = v1142 + v1024;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1025);
          v1028 = v1149 + v1025;
          v1003[6] = v1026;
          LOBYTE(v1028) = BYTE2(v1078) + v177 + v1028;
          v1225 = v1224 - 1;
          if ( !v1225 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1027);
          LOWORD(v1027) = v1076 + v1027;
          BYTE1(v1000) = v1028;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1029 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[7];
            v1029 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1027);
          v1030 = v1142 + v1027;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1028);
          v1031 = v1149 + v1028;
          v1003[7] = v1029;
          LOBYTE(v1031) = BYTE2(v1078) + v177 + v1031;
          v1226 = v1225 - 1;
          if ( !v1226 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1030);
          LOWORD(v1030) = v1076 + v1030;
          BYTE1(v1000) = v1031;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1032 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[8];
            v1032 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1030);
          v1033 = v1142 + v1030;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1031);
          v1034 = v1149 + v1031;
          v1003[8] = v1032;
          LOBYTE(v1034) = BYTE2(v1078) + v177 + v1034;
          v1227 = v1226 - 1;
          if ( !v1227 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1033);
          LOWORD(v1033) = v1076 + v1033;
          BYTE1(v1000) = v1034;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1035 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[9];
            v1035 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1033);
          v1036 = v1142 + v1033;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1034);
          v1037 = v1149 + v1034;
          v1003[9] = v1035;
          LOBYTE(v1037) = BYTE2(v1078) + v177 + v1037;
          v1228 = v1227 - 1;
          if ( !v1228 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1036);
          LOWORD(v1036) = v1076 + v1036;
          BYTE1(v1000) = v1037;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1038 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[10];
            v1038 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1036);
          v1039 = v1142 + v1036;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1037);
          v1040 = v1149 + v1037;
          v1003[10] = v1038;
          LOBYTE(v1040) = BYTE2(v1078) + v177 + v1040;
          v1229 = v1228 - 1;
          if ( !v1229 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1039);
          LOWORD(v1039) = v1076 + v1039;
          BYTE1(v1000) = v1040;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1041 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[11];
            v1041 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1039);
          v1042 = v1142 + v1039;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1040);
          v1043 = v1149 + v1040;
          v1003[11] = v1041;
          LOBYTE(v1043) = BYTE2(v1078) + v177 + v1043;
          v1230 = v1229 - 1;
          if ( !v1230 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1042);
          LOWORD(v1042) = v1076 + v1042;
          BYTE1(v1000) = v1043;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1044 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[12];
            v1044 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1042);
          v1045 = v1142 + v1042;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1043);
          v1046 = v1149 + v1043;
          v1003[12] = v1044;
          LOBYTE(v1046) = BYTE2(v1078) + v177 + v1046;
          v1231 = v1230 - 1;
          if ( !v1231 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1045);
          LOWORD(v1045) = v1076 + v1045;
          BYTE1(v1000) = v1046;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1047 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[13];
            v1047 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1045);
          v1048 = v1142 + v1045;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1046);
          v1049 = v1149 + v1046;
          v1003[13] = v1047;
          LOBYTE(v1049) = BYTE2(v1078) + v177 + v1049;
          v1232 = v1231 - 1;
          if ( !v1232 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1048);
          LOWORD(v1048) = v1076 + v1048;
          BYTE1(v1000) = v1049;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1050 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[14];
            v1050 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1048);
          v1051 = v1142 + v1048;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1049);
          v1052 = v1149 + v1049;
          v1003[14] = v1050;
          LOBYTE(v1052) = BYTE2(v1078) + v177 + v1052;
          v1233 = v1232 - 1;
          if ( !v1233 )
            break;
          LOBYTE(v1000) = *(_BYTE *)(v1001 + v1007);
          v177 = __CFADD__((_WORD)v1076, (_WORD)v1051);
          LOWORD(v1051) = v1076 + v1051;
          BYTE1(v1000) = v1052;
          LOBYTE(v1001) = BYTE2(v1076) + v177 + v1001;
          if ( (unsigned __int8)v1000 >= 0xCu )
          {
            v1053 = *(_BYTE *)(v1000 + ((u32) tables_start));
          }
          else
          {
            LOBYTE(v1000) = *(_BYTE *)(v1000 + ((u32) tables_start));
            BYTE1(v1000) = v1003[15];
            v1053 = *(_BYTE *)(v1000 + ((u32)ghost));
          }
          v177 = __CFADD__(v1142, v1051);
          v1005 = v1142 + v1051;
          BYTE1(v1001) += BYTE2(v1077) + v177;
          v177 = __CFADD__(v1149, v1052);
          v1006 = v1149 + v1052;
          v1003[15] = v1053;
          LOBYTE(v1006) = BYTE2(v1078) + v177 + v1006;
          v1218 = v1233 - 1;
          if ( !v1218 )
            break;
          v1003 += 16;
        }
        v999 = v1251;
      }
LABEL_1325:
      v999 += 10;
      if ( !--v1075 )
        return;
    }
    if ( v1002 > vec_window_width )
      v1002 = vec_window_width;
    v16 = (__int16)v1002 <= (__int16)v1000;
    LOWORD(v1002) = v1002 - v1000;
    if ( v16 )
      goto LABEL_1325;
    v1003 += v1000;
    v1005 = __ROL4__(*((int *)v999 + 3), 16);
    BYTE1(v1001) = v1005;
    LOWORD(v1005) = v999[4];
    LOBYTE(v1001) = *((_BYTE *)v999 + 10);
    v1218 = v1002;
    v1006 = __ROL4__(*((int *)v999 + 4), 16);
    goto LABEL_1258;
  }
  if ( v6 <= v7 )
  {
    if ( v6 != v8 )
    {
      if ( v6 >= v8 )
      {
        v3 = a3;
        v4 = a1;
        v5 = a2;
        goto LABEL_24;
      }
      if ( v7 != v8 )
      {
        if ( v7 <= v8 )
        {
LABEL_24:
          v9 = v3[1];
          v1150 = v9;
          if ( v9 >= 0 )
          {
            if ( v9 >= vec_window_height )
              return;
            v1054 = dword_220C4C + vec_screen_width * v9;
            v1253 = 0;
          }
          else
          {
            v1054 = dword_220C4C;
            v1253 = 1;
          }
          v10 = v5[1];
          v1261 = v10 > vec_window_height;
          v1065 = v10 - v9;
          v1075 = v10 - v9;
          v11 = v4[1];
          v1257 = v11 > vec_window_height;
          v12 = v11 - v9;
          v1069 = v12;
          v1055 = ((*v5 - *v3) SHL16) / v1065;
          if ( ((*v4 - *v3) SHL16) / v12 <= v1055 )
            return;
          v1059 = ((*v4 - *v3) SHL16) / v12;
          v1063 = ((*v5 - *v4) SHL16) / (v5[1] - v4[1]);
          v1071 = v5[1] - v4[1];
          v1073 = *v4 SHL16;
          switch ( vec_mode )
          {
            case 0:
            case 14:
            case 15:
              v54 = *v3 SHL16;
              v55 = v54;
              if ( v1253 )
              {
                v16 = v1075 <= -v1150;
                v1075 += v1150;
                if ( v16 )
                  return;
                v1115 = -v1150;
                if ( -v1150 - v1069 >= 0 )
                {
                  v1071 -= v1115 - v1069;
                  v1116 = v1115 - v1069;
                  v54 += v1055 * v1116 + v1069 * v1055;
                  v56 = v1063 * v1116 + v1073;
                  if ( v1261 )
                  {
                    v1071 = vec_window_height;
                    v1075 = vec_window_height;
                  }
                  v57 = &polyscans;
                  goto LABEL_119;
                }
                v1069 += v1150;
                v54 += v1055 * v1115;
                v55 += v1115 * v1059;
                if ( v1261 )
                {
                  v1075 = vec_window_height;
                  if ( v1257 )
                  {
                    v1069 = vec_window_height;
                  }
                  else
                  {
                    v1257 = vec_window_height <= v1069;
                    v1071 = vec_window_height - v1069;
                  }
                }
              }
              else if ( v1261 )
              {
                v58 = vec_window_height - v1150;
                v1075 = vec_window_height - v1150;
                if ( v1257 )
                {
                  v1069 = vec_window_height - v1150;
                }
                else
                {
                  v27 = __OFSUB__(v58, v1069);
                  v59 = v58 - v1069;
                  v1257 = (v59 < 0) ^ v27 | (v59 == 0);
                  v1071 = v59;
                }
              }
              v57 = &polyscans;
              do
              {
                *v57 = v54;
                v54 += v1055;
                v57[1] = v55;
                v55 += v1059;
                v57 += 5;
                --v1069;
              }
              while ( v1069 );
              v56 = v1073;
LABEL_119:
              if ( v1257 )
              {
                v29 = (unsigned __int8)vec_mode;
                switch ( vec_mode )
                {
                  case 0:
                    goto LABEL_309;
                  case 1:
                    return;
                  case 2:
                    goto LABEL_322;
                  case 3:
                    goto LABEL_353;
                  case 4:
                    goto LABEL_416;
                  case 5:
                    goto LABEL_445;
                  case 6:
                    goto LABEL_474;
                  case 7:
                  case 11:
                    goto LABEL_537;
                  case 8:
                    goto LABEL_568;
                  case 9:
                  case 10:
                    goto LABEL_631;
                  case 12:
                    goto LABEL_694;
                  case 13:
                    goto LABEL_725;
                  case 14:
                    goto LABEL_756;
                  case 15:
                    goto LABEL_785;
                  case 16:
                    goto LABEL_814;
                  case 17:
                    goto LABEL_843;
                  case 18:
                    goto LABEL_872;
                  case 19:
                    goto LABEL_903;
                  case 20:
                    goto LABEL_934;
                  case 21:
                    goto LABEL_965;
                  case 22:
                    goto LABEL_996;
                  case 23:
                    goto LABEL_1059;
                  case 24:
                    goto LABEL_1122;
                  case 25:
                    goto LABEL_1185;
                  case 26:
                    goto LABEL_1248;
                }
              }
              else
              {
                do
                {
                  *v57 = v54;
                  v54 += v1055;
                  v57[1] = v56;
                  v56 += v1063;
                  v57 += 5;
                  --v1071;
                }
                while ( v1071 );
                v29 = (unsigned __int8)vec_mode;
                switch ( vec_mode )
                {
                  case 0:
                    goto LABEL_309;
                  case 1:
                    return;
                  case 2:
                    goto LABEL_322;
                  case 3:
                    goto LABEL_353;
                  case 4:
                    goto LABEL_416;
                  case 5:
                    goto LABEL_445;
                  case 6:
                    goto LABEL_474;
                  case 7:
                  case 11:
                    goto LABEL_537;
                  case 8:
                    goto LABEL_568;
                  case 9:
                  case 10:
                    goto LABEL_631;
                  case 12:
                    goto LABEL_694;
                  case 13:
                    goto LABEL_725;
                  case 14:
                    goto LABEL_756;
                  case 15:
                    goto LABEL_785;
                  case 16:
                    goto LABEL_814;
                  case 17:
                    goto LABEL_843;
                  case 18:
                    goto LABEL_872;
                  case 19:
                    goto LABEL_903;
                  case 20:
                    goto LABEL_934;
                  case 21:
                    goto LABEL_965;
                  case 22:
                    goto LABEL_996;
                  case 23:
                    goto LABEL_1059;
                  case 24:
                    goto LABEL_1122;
                  case 25:
                    goto LABEL_1185;
                  case 26:
                    goto LABEL_1248;
                }
              }
              return;
            case 1:
            case 4:
            case 16:
            case 17:
              v43 = v12 * (__int64)(*v3 - *v5) / v1065;
              v44 = *v4 - *v3;
              v45 = v43 + v44 == 0;
              v16 = (v43 + v44 < 0) ^ __OFADD__(v43, v44);
              v46 = v43 + v44;
              if ( v16 )
                return;
              if ( !v45 )
                v1078 = (int)(v4[4] + v1069 * (__int64)(v3[4] - v5[4]) / v1065 - v3[4]) / (v46 + 1);
              v1096 = (v5[4] - v3[4]) / v1065;
              v47 = *v3 SHL16;
              v48 = v47;
              v49 = v3[4];
              if ( v1253 )
              {
                v16 = v1075 <= -v1150;
                v1075 += v1150;
                if ( v16 )
                  return;
                v1113 = -v1150;
                if ( -v1150 - v1069 >= 0 )
                {
                  v1071 -= v1113 - v1069;
                  v1114 = v1113 - v1069;
                  v47 += v1055 * v1114 + v1069 * v1055;
                  v50 = v1063 * v1114 + v1073;
                  v49 += v1114 * v1096 + v1069 * v1096;
                  if ( v1261 )
                  {
                    v1071 = vec_window_height;
                    v1075 = vec_window_height;
                  }
                  v51 = &polyscans;
LABEL_98:
                  if ( v1257 )
                  {
                    v29 = (unsigned __int8)vec_mode;
                    switch ( vec_mode )
                    {
                      case 0:
                        goto LABEL_309;
                      case 1:
                        return;
                      case 2:
                        goto LABEL_322;
                      case 3:
                        goto LABEL_353;
                      case 4:
                        goto LABEL_416;
                      case 5:
                        goto LABEL_445;
                      case 6:
                        goto LABEL_474;
                      case 7:
                      case 11:
                        goto LABEL_537;
                      case 8:
                        goto LABEL_568;
                      case 9:
                      case 10:
                        goto LABEL_631;
                      case 12:
                        goto LABEL_694;
                      case 13:
                        goto LABEL_725;
                      case 14:
                        goto LABEL_756;
                      case 15:
                        goto LABEL_785;
                      case 16:
                        goto LABEL_814;
                      case 17:
                        goto LABEL_843;
                      case 18:
                        goto LABEL_872;
                      case 19:
                        goto LABEL_903;
                      case 20:
                        goto LABEL_934;
                      case 21:
                        goto LABEL_965;
                      case 22:
                        goto LABEL_996;
                      case 23:
                        goto LABEL_1059;
                      case 24:
                        goto LABEL_1122;
                      case 25:
                        goto LABEL_1185;
                      case 26:
                        goto LABEL_1248;
                    }
                  }
                  else
                  {
                    do
                    {
                      *v51 = v47;
                      v47 += v1055;
                      v51[1] = v50;
                      v50 += v1063;
                      v51[4] = v49;
                      v49 += v1096;
                      v51 += 5;
                      --v1071;
                    }
                    while ( v1071 );
                    v29 = (unsigned __int8)vec_mode;
                    switch ( vec_mode )
                    {
                      case 0:
                        goto LABEL_309;
                      case 1:
                        return;
                      case 2:
                        goto LABEL_322;
                      case 3:
                        goto LABEL_353;
                      case 4:
                        goto LABEL_416;
                      case 5:
                        goto LABEL_445;
                      case 6:
                        goto LABEL_474;
                      case 7:
                      case 11:
                        goto LABEL_537;
                      case 8:
                        goto LABEL_568;
                      case 9:
                      case 10:
                        goto LABEL_631;
                      case 12:
                        goto LABEL_694;
                      case 13:
                        goto LABEL_725;
                      case 14:
                        goto LABEL_756;
                      case 15:
                        goto LABEL_785;
                      case 16:
                        goto LABEL_814;
                      case 17:
                        goto LABEL_843;
                      case 18:
                        goto LABEL_872;
                      case 19:
                        goto LABEL_903;
                      case 20:
                        goto LABEL_934;
                      case 21:
                        goto LABEL_965;
                      case 22:
                        goto LABEL_996;
                      case 23:
                        goto LABEL_1059;
                      case 24:
                        goto LABEL_1122;
                      case 25:
                        goto LABEL_1185;
                      case 26:
                        goto LABEL_1248;
                    }
                  }
                  return;
                }
                v1069 += v1150;
                v47 += v1055 * v1113;
                v48 += v1113 * v1059;
                v49 += v1113 * v1096;
                if ( v1261 )
                {
                  v1075 = vec_window_height;
                  if ( v1257 )
                  {
                    v1069 = vec_window_height;
                  }
                  else
                  {
                    v1257 = vec_window_height <= v1069;
                    v1071 = vec_window_height - v1069;
                  }
                }
              }
              else if ( v1261 )
              {
                v52 = vec_window_height - v1150;
                v1075 = vec_window_height - v1150;
                if ( v1257 )
                {
                  v1069 = vec_window_height - v1150;
                }
                else
                {
                  v27 = __OFSUB__(v52, v1069);
                  v53 = v52 - v1069;
                  v1257 = (v53 < 0) ^ v27 | (v53 == 0);
                  v1071 = v53;
                }
              }
              v51 = &polyscans;
              do
              {
                *v51 = v47;
                v47 += v1055;
                v51[1] = v48;
                v48 += v1059;
                v51[4] = v49;
                v49 += v1096;
                v51 += 5;
                --v1069;
              }
              while ( v1069 );
              v50 = v1073;
              goto LABEL_98;
            case 2:
            case 3:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 18:
            case 19:
            case 22:
            case 23:
              v30 = v12 * (__int64)(*v3 - *v5) / v1065;
              v31 = *v4 - *v3;
              v32 = v30 + v31 == 0;
              v16 = (v30 + v31 < 0) ^ __OFADD__(v30, v31);
              v33 = v30 + v31;
              if ( v16 )
                return;
              if ( !v32 )
              {
                v34 = v33 + 1;
                v1076 = (int)(v4[2] + v1069 * (__int64)(v3[2] - v5[2]) / v1065 - v3[2]) / v34;
                v1077 = (int)(v4[3] + v1069 * (__int64)(v3[3] - v5[3]) / v1065 - v3[3]) / v34;
              }
              v1080 = (v5[2] - v3[2]) / v1065;
              v1088 = (v5[3] - v3[3]) / v1065;
              v35 = *v3 SHL16;
              v36 = v35;
              v37 = v3[2];
              v38 = v3[3];
              if ( v1253 )
              {
                v16 = v1075 <= -v1150;
                v1075 += v1150;
                if ( v16 )
                  return;
                v1111 = -v1150;
                if ( -v1150 - v1069 >= 0 )
                {
                  v1071 -= v1111 - v1069;
                  v1112 = v1111 - v1069;
                  v35 += v1055 * v1112 + v1069 * v1055;
                  v39 = v1063 * v1112 + v1073;
                  v37 += v1112 * v1080 + v1069 * v1080;
                  v38 += v1112 * v1088 + v1069 * v1088;
                  if ( v1261 )
                  {
                    v1071 = vec_window_height;
                    v1075 = vec_window_height;
                  }
                  v40 = &polyscans;
LABEL_74:
                  if ( v1257 )
                  {
                    v29 = (unsigned __int8)vec_mode;
                    switch ( vec_mode )
                    {
                      case 0:
                        goto LABEL_309;
                      case 1:
                        return;
                      case 2:
                        goto LABEL_322;
                      case 3:
                        goto LABEL_353;
                      case 4:
                        goto LABEL_416;
                      case 5:
                        goto LABEL_445;
                      case 6:
                        goto LABEL_474;
                      case 7:
                      case 11:
                        goto LABEL_537;
                      case 8:
                        goto LABEL_568;
                      case 9:
                      case 10:
                        goto LABEL_631;
                      case 12:
                        goto LABEL_694;
                      case 13:
                        goto LABEL_725;
                      case 14:
                        goto LABEL_756;
                      case 15:
                        goto LABEL_785;
                      case 16:
                        goto LABEL_814;
                      case 17:
                        goto LABEL_843;
                      case 18:
                        goto LABEL_872;
                      case 19:
                        goto LABEL_903;
                      case 20:
                        goto LABEL_934;
                      case 21:
                        goto LABEL_965;
                      case 22:
                        goto LABEL_996;
                      case 23:
                        goto LABEL_1059;
                      case 24:
                        goto LABEL_1122;
                      case 25:
                        goto LABEL_1185;
                      case 26:
                        goto LABEL_1248;
                    }
                  }
                  else
                  {
                    do
                    {
                      *v40 = v35;
                      v35 += v1055;
                      v40[1] = v39;
                      v39 += v1063;
                      v40[2] = v37;
                      v37 += v1080;
                      v40[3] = v38;
                      v38 += v1088;
                      v40 += 5;
                      --v1071;
                    }
                    while ( v1071 );
                    v29 = (unsigned __int8)vec_mode;
                    switch ( vec_mode )
                    {
                      case 0:
                        goto LABEL_309;
                      case 1:
                        return;
                      case 2:
                        goto LABEL_322;
                      case 3:
                        goto LABEL_353;
                      case 4:
                        goto LABEL_416;
                      case 5:
                        goto LABEL_445;
                      case 6:
                        goto LABEL_474;
                      case 7:
                      case 11:
                        goto LABEL_537;
                      case 8:
                        goto LABEL_568;
                      case 9:
                      case 10:
                        goto LABEL_631;
                      case 12:
                        goto LABEL_694;
                      case 13:
                        goto LABEL_725;
                      case 14:
                        goto LABEL_756;
                      case 15:
                        goto LABEL_785;
                      case 16:
                        goto LABEL_814;
                      case 17:
                        goto LABEL_843;
                      case 18:
                        goto LABEL_872;
                      case 19:
                        goto LABEL_903;
                      case 20:
                        goto LABEL_934;
                      case 21:
                        goto LABEL_965;
                      case 22:
                        goto LABEL_996;
                      case 23:
                        goto LABEL_1059;
                      case 24:
                        goto LABEL_1122;
                      case 25:
                        goto LABEL_1185;
                      case 26:
                        goto LABEL_1248;
                    }
                  }
                  return;
                }
                v1069 += v1150;
                v35 += v1055 * v1111;
                v36 += v1111 * v1059;
                v37 += v1111 * v1080;
                v38 += v1111 * v1088;
                if ( v1261 )
                {
                  v1075 = vec_window_height;
                  if ( v1257 )
                  {
                    v1069 = vec_window_height;
                  }
                  else
                  {
                    v1257 = vec_window_height <= v1069;
                    v1071 = vec_window_height - v1069;
                  }
                }
              }
              else if ( v1261 )
              {
                v41 = vec_window_height - v1150;
                v1075 = vec_window_height - v1150;
                if ( v1257 )
                {
                  v1069 = vec_window_height - v1150;
                }
                else
                {
                  v27 = __OFSUB__(v41, v1069);
                  v42 = v41 - v1069;
                  v1257 = (v42 < 0) ^ v27 | (v42 == 0);
                  v1071 = v42;
                }
              }
              v40 = &polyscans;
              do
              {
                *v40 = v35;
                v35 += v1055;
                v40[1] = v36;
                v36 += v1059;
                v40[2] = v37;
                v37 += v1080;
                v40[3] = v38;
                v38 += v1088;
                v40 += 5;
                --v1069;
              }
              while ( v1069 );
              v39 = v1073;
              goto LABEL_74;
            case 5:
            case 6:
            case 20:
            case 21:
            case 24:
            case 25:
            case 26:
              v13 = v12 * (__int64)(*v3 - *v5) / v1065;
              v14 = *v4 - *v3;
              v15 = v13 + v14 == 0;
              v16 = (v13 + v14 < 0) ^ __OFADD__(v13, v14);
              v17 = v13 + v14;
              if ( v16 )
                return;
              if ( !v15 )
              {
                v18 = v17 + 1;
                v1076 = (int)(v4[2] + v1069 * (__int64)(v3[2] - v5[2]) / v1065 - v3[2]) / v18;
                v1077 = (int)(v4[3] + v1069 * (__int64)(v3[3] - v5[3]) / v1065 - v3[3]) / v18;
                v1078 = (int)(v4[4] + v1069 * (__int64)(v3[4] - v5[4]) / v1065 - v3[4]) / v18;
              }
              v1079 = (v5[2] - v3[2]) / v1065;
              v1087 = (v5[3] - v3[3]) / v1065;
              v1095 = (v5[4] - v3[4]) / v1065;
              v19 = *v3 SHL16;
              v20 = v19;
              v21 = v3[2];
              v22 = v3[3];
              v23 = v3[4];
              if ( v1253 )
              {
                v16 = v1075 <= -v1150;
                v1075 += v1150;
                if ( v16 )
                  return;
                v1109 = -v1150;
                if ( -v1150 - v1069 >= 0 )
                {
                  v1071 -= v1109 - v1069;
                  v1110 = v1109 - v1069;
                  v19 += v1055 * v1110 + v1069 * v1055;
                  v24 = v1063 * v1110 + v1073;
                  v21 += v1110 * v1079 + v1069 * v1079;
                  v22 += v1110 * v1087 + v1069 * v1087;
                  v23 += v1110 * v1095 + v1069 * v1095;
                  if ( v1261 )
                  {
                    v1071 = vec_window_height;
                    v1075 = vec_window_height;
                  }
                  v25 = &polyscans;
LABEL_50:
                  if ( v1257 )
                  {
                    v29 = (unsigned __int8)vec_mode;
                    switch ( vec_mode )
                    {
                      case 0:
                        goto LABEL_309;
                      case 1:
                        return;
                      case 2:
                        goto LABEL_322;
                      case 3:
                        goto LABEL_353;
                      case 4:
                        goto LABEL_416;
                      case 5:
                        goto LABEL_445;
                      case 6:
                        goto LABEL_474;
                      case 7:
                      case 11:
                        goto LABEL_537;
                      case 8:
                        goto LABEL_568;
                      case 9:
                      case 10:
                        goto LABEL_631;
                      case 12:
                        goto LABEL_694;
                      case 13:
                        goto LABEL_725;
                      case 14:
                        goto LABEL_756;
                      case 15:
                        goto LABEL_785;
                      case 16:
                        goto LABEL_814;
                      case 17:
                        goto LABEL_843;
                      case 18:
                        goto LABEL_872;
                      case 19:
                        goto LABEL_903;
                      case 20:
                        goto LABEL_934;
                      case 21:
                        goto LABEL_965;
                      case 22:
                        goto LABEL_996;
                      case 23:
                        goto LABEL_1059;
                      case 24:
                        goto LABEL_1122;
                      case 25:
                        goto LABEL_1185;
                      case 26:
                        goto LABEL_1248;
                    }
                  }
                  else
                  {
                    do
                    {
                      *v25 = v19;
                      v19 += v1055;
                      v25[1] = v24;
                      v24 += v1063;
                      v25[2] = v21;
                      v21 += v1079;
                      v25[3] = v22;
                      v22 += v1087;
                      v25[4] = v23;
                      v23 += v1095;
                      v25 += 5;
                      --v1071;
                    }
                    while ( v1071 );
                    v29 = (unsigned __int8)vec_mode;
                    switch ( vec_mode )
                    {
                      case 0:
                        goto LABEL_309;
                      case 1:
                        return;
                      case 2:
                        goto LABEL_322;
                      case 3:
                        goto LABEL_353;
                      case 4:
                        goto LABEL_416;
                      case 5:
                        goto LABEL_445;
                      case 6:
                        goto LABEL_474;
                      case 7:
                      case 11:
                        goto LABEL_537;
                      case 8:
                        goto LABEL_568;
                      case 9:
                      case 10:
                        goto LABEL_631;
                      case 12:
                        goto LABEL_694;
                      case 13:
                        goto LABEL_725;
                      case 14:
                        goto LABEL_756;
                      case 15:
                        goto LABEL_785;
                      case 16:
                        goto LABEL_814;
                      case 17:
                        goto LABEL_843;
                      case 18:
                        goto LABEL_872;
                      case 19:
                        goto LABEL_903;
                      case 20:
                        goto LABEL_934;
                      case 21:
                        goto LABEL_965;
                      case 22:
                        goto LABEL_996;
                      case 23:
                        goto LABEL_1059;
                      case 24:
                        goto LABEL_1122;
                      case 25:
                        goto LABEL_1185;
                      case 26:
                        goto LABEL_1248;
                    }
                  }
                  return;
                }
                v1069 += v1150;
                v19 += v1055 * v1109;
                v20 += v1109 * v1059;
                v21 += v1109 * v1079;
                v22 += v1109 * v1087;
                v23 += v1109 * v1095;
                if ( v1261 )
                {
                  v1075 = vec_window_height;
                  if ( v1257 )
                  {
                    v1069 = vec_window_height;
                  }
                  else
                  {
                    v1257 = vec_window_height <= v1069;
                    v1071 = vec_window_height - v1069;
                  }
                }
              }
              else if ( v1261 )
              {
                v26 = vec_window_height - v1150;
                v1075 = vec_window_height - v1150;
                if ( v1257 )
                {
                  v1069 = vec_window_height - v1150;
                }
                else
                {
                  v27 = __OFSUB__(v26, v1069);
                  v28 = v26 - v1069;
                  v1257 = (v28 < 0) ^ v27 | (v28 == 0);
                  v1071 = v28;
                }
              }
              v25 = &polyscans;
              do
              {
                *v25 = v19;
                v19 += v1055;
                v25[1] = v20;
                v20 += v1059;
                v25[2] = v21;
                v21 += v1079;
                v25[3] = v22;
                v22 += v1087;
                v25[4] = v23;
                v23 += v1095;
                v25 += 5;
                --v1069;
              }
              while ( v1069 );
              v24 = v1073;
              goto LABEL_50;
          }
        }
        goto LABEL_124;
      }
      if ( *a2 <= *a3 )
        return;
LABEL_225:
      v108 = v3[1];
      v1152 = v108;
      if ( v108 >= 0 )
      {
        if ( v108 >= vec_window_height )
          return;
        v1054 = dword_220C4C + vec_screen_width * v108;
        v1255 = 0;
      }
      else
      {
        v1054 = dword_220C4C;
        v1255 = 1;
      }
      v109 = v5[1];
      v1259 = v109 > vec_window_height;
      v1067 = v109 - v108;
      v1075 = v109 - v108;
      v1057 = ((*v5 - *v3) SHL16) / (v109 - v108);
      v1061 = ((*v4 - *v3) SHL16) / (v109 - v108);
      switch ( vec_mode )
      {
        case 0:
        case 14:
        case 15:
          v130 = *v3 SHL16;
          v131 = v130;
          if ( v1255 )
          {
            v132 = -v1152;
            v1067 += v1152;
            v16 = v1075 <= -v1152;
            v1075 += v1152;
            if ( v16 )
              return;
            v130 += v1057 * v132;
            v131 += v132 * v1061;
            if ( v1259 )
            {
              v1075 = vec_window_height;
              v1067 = vec_window_height;
            }
          }
          else if ( v1259 )
          {
            v1075 = vec_window_height - v1152;
            v1067 = vec_window_height - v1152;
          }
          v133 = &polyscans;
          do
          {
            *v133 = v130;
            v130 += v1057;
            v133[1] = v131;
            v131 += v1061;
            v133 += 5;
            --v1067;
          }
          while ( v1067 );
          v29 = (unsigned __int8)vec_mode;
          switch ( vec_mode )
          {
            case 0:
              goto LABEL_309;
            case 1:
              return;
            case 2:
              goto LABEL_322;
            case 3:
              goto LABEL_353;
            case 4:
              goto LABEL_416;
            case 5:
              goto LABEL_445;
            case 6:
              goto LABEL_474;
            case 7:
            case 11:
              goto LABEL_537;
            case 8:
              goto LABEL_568;
            case 9:
            case 10:
              goto LABEL_631;
            case 12:
              goto LABEL_694;
            case 13:
              goto LABEL_725;
            case 14:
              goto LABEL_756;
            case 15:
              goto LABEL_785;
            case 16:
              goto LABEL_814;
            case 17:
              goto LABEL_843;
            case 18:
              goto LABEL_872;
            case 19:
              goto LABEL_903;
            case 20:
              goto LABEL_934;
            case 21:
              goto LABEL_965;
            case 22:
              goto LABEL_996;
            case 23:
              goto LABEL_1059;
            case 24:
              goto LABEL_1122;
            case 25:
              goto LABEL_1185;
            case 26:
              goto LABEL_1248;
          }
        case 1:
        case 4:
        case 16:
        case 17:
          v1078 = (v4[4] - v5[4]) / (*v4 - *v5);
          v1100 = (v5[4] - v3[4]) / v1075;
          v125 = *v3 SHL16;
          v126 = v125;
          v127 = v3[4];
          if ( v1255 )
          {
            v128 = -v1152;
            v1067 += v1152;
            v16 = v1075 <= -v1152;
            v1075 += v1152;
            if ( v16 )
              return;
            v125 += v1057 * v128;
            v126 += v128 * v1061;
            v127 += v128 * v1100;
            if ( v1259 )
            {
              v1075 = vec_window_height;
              v1067 = vec_window_height;
            }
          }
          else if ( v1259 )
          {
            v1075 = vec_window_height - v1152;
            v1067 = vec_window_height - v1152;
          }
          v129 = &polyscans;
          do
          {
            *v129 = v125;
            v125 += v1057;
            v129[1] = v126;
            v126 += v1061;
            v129[4] = v127;
            v127 += v1100;
            v129 += 5;
            --v1067;
          }
          while ( v1067 );
          v29 = (unsigned __int8)vec_mode;
          switch ( vec_mode )
          {
            case 0:
              goto LABEL_309;
            case 1:
              return;
            case 2:
              goto LABEL_322;
            case 3:
              goto LABEL_353;
            case 4:
              goto LABEL_416;
            case 5:
              goto LABEL_445;
            case 6:
              goto LABEL_474;
            case 7:
            case 11:
              goto LABEL_537;
            case 8:
              goto LABEL_568;
            case 9:
            case 10:
              goto LABEL_631;
            case 12:
              goto LABEL_694;
            case 13:
              goto LABEL_725;
            case 14:
              goto LABEL_756;
            case 15:
              goto LABEL_785;
            case 16:
              goto LABEL_814;
            case 17:
              goto LABEL_843;
            case 18:
              goto LABEL_872;
            case 19:
              goto LABEL_903;
            case 20:
              goto LABEL_934;
            case 21:
              goto LABEL_965;
            case 22:
              goto LABEL_996;
            case 23:
              goto LABEL_1059;
            case 24:
              goto LABEL_1122;
            case 25:
              goto LABEL_1185;
            case 26:
              goto LABEL_1248;
          }
        case 2:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 18:
        case 19:
        case 22:
        case 23:
          v118 = *v4 - *v5;
          v1076 = (v4[2] - v5[2]) / v118;
          v1077 = (v4[3] - v5[3]) / v118;
          v1084 = (v5[2] - v3[2]) / v1075;
          v1092 = (v5[3] - v3[3]) / v1075;
          v119 = *v3 SHL16;
          v120 = v119;
          v121 = v3[2];
          v122 = v3[3];
          if ( v1255 )
          {
            v123 = -v1152;
            v1067 += v1152;
            v16 = v1075 <= -v1152;
            v1075 += v1152;
            if ( v16 )
              return;
            v119 += v1057 * v123;
            v120 += v123 * v1061;
            v121 += v123 * v1084;
            v122 += v123 * v1092;
            if ( v1259 )
            {
              v1075 = vec_window_height;
              v1067 = vec_window_height;
            }
          }
          else if ( v1259 )
          {
            v1075 = vec_window_height - v1152;
            v1067 = vec_window_height - v1152;
          }
          v124 = &polyscans;
          do
          {
            *v124 = v119;
            v119 += v1057;
            v124[1] = v120;
            v120 += v1061;
            v124[2] = v121;
            v121 += v1084;
            v124[3] = v122;
            v122 += v1092;
            v124 += 5;
            --v1067;
          }
          while ( v1067 );
          v29 = (unsigned __int8)vec_mode;
          switch ( vec_mode )
          {
            case 0:
              goto LABEL_309;
            case 1:
              return;
            case 2:
              goto LABEL_322;
            case 3:
              goto LABEL_353;
            case 4:
              goto LABEL_416;
            case 5:
              goto LABEL_445;
            case 6:
              goto LABEL_474;
            case 7:
            case 11:
              goto LABEL_537;
            case 8:
              goto LABEL_568;
            case 9:
            case 10:
              goto LABEL_631;
            case 12:
              goto LABEL_694;
            case 13:
              goto LABEL_725;
            case 14:
              goto LABEL_756;
            case 15:
              goto LABEL_785;
            case 16:
              goto LABEL_814;
            case 17:
              goto LABEL_843;
            case 18:
              goto LABEL_872;
            case 19:
              goto LABEL_903;
            case 20:
              goto LABEL_934;
            case 21:
              goto LABEL_965;
            case 22:
              goto LABEL_996;
            case 23:
              goto LABEL_1059;
            case 24:
              goto LABEL_1122;
            case 25:
              goto LABEL_1185;
            case 26:
              goto LABEL_1248;
          }
        case 5:
        case 6:
        case 20:
        case 21:
        case 24:
        case 25:
        case 26:
          v110 = *v4 - *v5;
          v1076 = (v4[2] - v5[2]) / v110;
          v1077 = (v4[3] - v5[3]) / v110;
          v1078 = (v4[4] - v5[4]) / v110;
          v1083 = (v5[2] - v3[2]) / v1075;
          v1091 = (v5[3] - v3[3]) / v1075;
          v1099 = (v5[4] - v3[4]) / v1075;
          v111 = *v3 SHL16;
          v112 = v111;
          v113 = v3[2];
          v114 = v3[3];
          v115 = v3[4];
          if ( v1255 )
          {
            v116 = -v1152;
            v1067 += v1152;
            v16 = v1075 <= -v1152;
            v1075 += v1152;
            if ( v16 )
              return;
            v111 += v1057 * v116;
            v112 += v116 * v1061;
            v113 += v116 * v1083;
            v114 += v116 * v1091;
            v115 += v116 * v1099;
            if ( v1259 )
            {
              v1075 = vec_window_height;
              v1067 = vec_window_height;
            }
          }
          else if ( v1259 )
          {
            v1075 = vec_window_height - v1152;
            v1067 = vec_window_height - v1152;
          }
          v117 = &polyscans;
          do
          {
            *v117 = v111;
            v111 += v1057;
            v117[1] = v112;
            v112 += v1061;
            v117[2] = v113;
            v113 += v1083;
            v117[3] = v114;
            v114 += v1091;
            v117[4] = v115;
            v115 += v1099;
            v117 += 5;
            --v1067;
          }
          while ( v1067 );
          v29 = (unsigned __int8)vec_mode;
          switch ( vec_mode )
          {
            case 0:
              goto LABEL_309;
            case 1:
              return;
            case 2:
              goto LABEL_322;
            case 3:
              goto LABEL_353;
            case 4:
              goto LABEL_416;
            case 5:
              goto LABEL_445;
            case 6:
              goto LABEL_474;
            case 7:
            case 11:
              goto LABEL_537;
            case 8:
              goto LABEL_568;
            case 9:
            case 10:
              goto LABEL_631;
            case 12:
              goto LABEL_694;
            case 13:
              goto LABEL_725;
            case 14:
              goto LABEL_756;
            case 15:
              goto LABEL_785;
            case 16:
              goto LABEL_814;
            case 17:
              goto LABEL_843;
            case 18:
              goto LABEL_872;
            case 19:
              goto LABEL_903;
            case 20:
              goto LABEL_934;
            case 21:
              goto LABEL_965;
            case 22:
              goto LABEL_996;
            case 23:
              goto LABEL_1059;
            case 24:
              goto LABEL_1122;
            case 25:
              goto LABEL_1185;
            case 26:
              goto LABEL_1248;
          }
      }
      return;
    }
    if ( *a1 <= *a3 )
      return;
    v3 = a3;
    v4 = a1;
    v5 = a2;
    goto LABEL_268;
  }
  if ( v6 == v8 )
  {
    if ( *a3 <= *a1 )
      return;
    v3 = a2;
    v4 = a3;
    v5 = a1;
    goto LABEL_225;
  }
  if ( v6 >= v8 )
  {
    if ( v7 != v8 )
    {
      if ( v7 < v8 )
      {
        v3 = a2;
        v4 = a3;
        v5 = a1;
        goto LABEL_24;
      }
      v3 = a3;
      v4 = a1;
      v5 = a2;
      goto LABEL_124;
    }
    if ( *a3 <= *a2 )
      return;
    v3 = a2;
    v4 = a3;
    v5 = a1;
    goto LABEL_268;
  }
  v3 = a2;
  v4 = a3;
  v5 = a1;
LABEL_124:
  v60 = v3[1];
  v1151 = v60;
  if ( v60 >= 0 )
  {
    if ( v60 >= vec_window_height )
      return;
    v1054 = dword_220C4C + vec_screen_width * v60;
    v1254 = 0;
  }
  else
  {
    v1054 = dword_220C4C;
    v1254 = 1;
  }
  v61 = v5[1];
  v1258 = v61 > vec_window_height;
  v1066 = v61 - v60;
  v62 = v4[1];
  v1262 = v62 > vec_window_height;
  v63 = v62 - v60;
  v1070 = v63;
  v1075 = v63;
  v1056 = ((*v5 - *v3) SHL16) / v1066;
  if ( ((*v4 - *v3) SHL16) / v63 <= v1056 )
    return;
  v1060 = ((*v4 - *v3) SHL16) / v63;
  v1064 = ((*v4 - *v5) SHL16) / (v4[1] - v5[1]);
  v1072 = v4[1] - v5[1];
  v1074 = *v5 SHL16;
  switch ( vec_mode )
  {
    case 0:
    case 14:
    case 15:
      v102 = *v3 SHL16;
      v103 = v102;
      if ( v1254 )
      {
        v16 = v1075 <= -v1151;
        v1075 += v1151;
        if ( v16 )
          return;
        v1123 = -v1151;
        if ( -v1151 - v1066 >= 0 )
        {
          v1124 = v1123 - v1066;
          v1072 -= v1124;
          v104 = v1064 * v1124 + v1074;
          v103 += v1124 * v1060 + v1066 * v1060;
          if ( v1262 )
          {
            v1072 = vec_window_height;
            v1075 = vec_window_height;
          }
          v105 = &polyscans;
          goto LABEL_219;
        }
        v1066 += v1151;
        v102 += v1056 * v1123;
        v103 += v1123 * v1060;
        if ( v1262 )
        {
          v1075 = vec_window_height;
          if ( v1258 )
          {
            v1066 = vec_window_height;
          }
          else
          {
            v1258 = vec_window_height <= v1066;
            v1072 = vec_window_height - v1066;
          }
        }
      }
      else if ( v1262 )
      {
        v106 = vec_window_height - v1151;
        v1075 = vec_window_height - v1151;
        if ( v1258 )
        {
          v1066 = vec_window_height - v1151;
        }
        else
        {
          v27 = __OFSUB__(v106, v1066);
          v107 = v106 - v1066;
          v1258 = (v107 < 0) ^ v27 | (v107 == 0);
          v1072 = v107;
        }
      }
      v105 = &polyscans;
      do
      {
        *v105 = v102;
        v102 += v1056;
        v105[1] = v103;
        v103 += v1060;
        v105 += 5;
        --v1066;
      }
      while ( v1066 );
      v104 = v1074;
LABEL_219:
      if ( v1258 )
      {
        v29 = (unsigned __int8)vec_mode;
        switch ( vec_mode )
        {
          case 0:
            goto LABEL_309;
          case 1:
            return;
          case 2:
            goto LABEL_322;
          case 3:
            goto LABEL_353;
          case 4:
            goto LABEL_416;
          case 5:
            goto LABEL_445;
          case 6:
            goto LABEL_474;
          case 7:
          case 11:
            goto LABEL_537;
          case 8:
            goto LABEL_568;
          case 9:
          case 10:
            goto LABEL_631;
          case 12:
            goto LABEL_694;
          case 13:
            goto LABEL_725;
          case 14:
            goto LABEL_756;
          case 15:
            goto LABEL_785;
          case 16:
            goto LABEL_814;
          case 17:
            goto LABEL_843;
          case 18:
            goto LABEL_872;
          case 19:
            goto LABEL_903;
          case 20:
            goto LABEL_934;
          case 21:
            goto LABEL_965;
          case 22:
            goto LABEL_996;
          case 23:
            goto LABEL_1059;
          case 24:
            goto LABEL_1122;
          case 25:
            goto LABEL_1185;
          case 26:
            goto LABEL_1248;
        }
      }
      else
      {
        do
        {
          *v105 = v104;
          v104 += v1064;
          v105[1] = v103;
          v103 += v1060;
          v105 += 5;
          --v1072;
        }
        while ( v1072 );
        v29 = (unsigned __int8)vec_mode;
        switch ( vec_mode )
        {
          case 0:
            goto LABEL_309;
          case 1:
            return;
          case 2:
            goto LABEL_322;
          case 3:
            goto LABEL_353;
          case 4:
            goto LABEL_416;
          case 5:
            goto LABEL_445;
          case 6:
            goto LABEL_474;
          case 7:
          case 11:
            goto LABEL_537;
          case 8:
            goto LABEL_568;
          case 9:
          case 10:
            goto LABEL_631;
          case 12:
            goto LABEL_694;
          case 13:
            goto LABEL_725;
          case 14:
            goto LABEL_756;
          case 15:
            goto LABEL_785;
          case 16:
            goto LABEL_814;
          case 17:
            goto LABEL_843;
          case 18:
            goto LABEL_872;
          case 19:
            goto LABEL_903;
          case 20:
            goto LABEL_934;
          case 21:
            goto LABEL_965;
          case 22:
            goto LABEL_996;
          case 23:
            goto LABEL_1059;
          case 24:
            goto LABEL_1122;
          case 25:
            goto LABEL_1185;
          case 26:
            goto LABEL_1248;
        }
      }
      return;
    case 1:
    case 4:
    case 16:
    case 17:
      v91 = v1066 * (__int64)(*v4 - *v3) / v63;
      v92 = *v3 - *v5;
      v93 = v91 + v92 == 0;
      v16 = (v91 + v92 < 0) ^ __OFADD__(v91, v92);
      v94 = v91 + v92;
      if ( v16 )
        return;
      if ( !v93 )
        v1078 = (int)(v3[4] + v1066 * (__int64)(v4[4] - v3[4]) / v1070 - v5[4]) / (v94 + 1);
      v1098 = (v5[4] - v3[4]) / v1066;
      v1108 = (v4[4] - v5[4]) / v1072;
      v95 = *v3 SHL16;
      v96 = v95;
      v97 = v3[4];
      if ( v1254 )
      {
        v16 = v1075 <= -v1151;
        v1075 += v1151;
        if ( v16 )
          return;
        v1121 = -v1151;
        if ( -v1151 - v1066 >= 0 )
        {
          v1122 = v1121 - v1066;
          v1072 -= v1122;
          v98 = v1064 * v1122 + v1074;
          v96 += v1122 * v1060 + v1066 * v1060;
          v97 += v1122 * v1108 + v1066 * v1098;
          if ( v1262 )
          {
            v1072 = vec_window_height;
            v1075 = vec_window_height;
          }
          v99 = &polyscans;
LABEL_198:
          if ( v1258 )
          {
            v29 = (unsigned __int8)vec_mode;
            switch ( vec_mode )
            {
              case 0:
                goto LABEL_309;
              case 1:
                return;
              case 2:
                goto LABEL_322;
              case 3:
                goto LABEL_353;
              case 4:
                goto LABEL_416;
              case 5:
                goto LABEL_445;
              case 6:
                goto LABEL_474;
              case 7:
              case 11:
                goto LABEL_537;
              case 8:
                goto LABEL_568;
              case 9:
              case 10:
                goto LABEL_631;
              case 12:
                goto LABEL_694;
              case 13:
                goto LABEL_725;
              case 14:
                goto LABEL_756;
              case 15:
                goto LABEL_785;
              case 16:
                goto LABEL_814;
              case 17:
                goto LABEL_843;
              case 18:
                goto LABEL_872;
              case 19:
                goto LABEL_903;
              case 20:
                goto LABEL_934;
              case 21:
                goto LABEL_965;
              case 22:
                goto LABEL_996;
              case 23:
                goto LABEL_1059;
              case 24:
                goto LABEL_1122;
              case 25:
                goto LABEL_1185;
              case 26:
                goto LABEL_1248;
            }
          }
          else
          {
            do
            {
              *v99 = v98;
              v98 += v1064;
              v99[1] = v96;
              v96 += v1060;
              v99[4] = v97;
              v97 += v1108;
              v99 += 5;
              --v1072;
            }
            while ( v1072 );
            v29 = (unsigned __int8)vec_mode;
            switch ( vec_mode )
            {
              case 0:
                goto LABEL_309;
              case 1:
                return;
              case 2:
                goto LABEL_322;
              case 3:
                goto LABEL_353;
              case 4:
                goto LABEL_416;
              case 5:
                goto LABEL_445;
              case 6:
                goto LABEL_474;
              case 7:
              case 11:
                goto LABEL_537;
              case 8:
                goto LABEL_568;
              case 9:
              case 10:
                goto LABEL_631;
              case 12:
                goto LABEL_694;
              case 13:
                goto LABEL_725;
              case 14:
                goto LABEL_756;
              case 15:
                goto LABEL_785;
              case 16:
                goto LABEL_814;
              case 17:
                goto LABEL_843;
              case 18:
                goto LABEL_872;
              case 19:
                goto LABEL_903;
              case 20:
                goto LABEL_934;
              case 21:
                goto LABEL_965;
              case 22:
                goto LABEL_996;
              case 23:
                goto LABEL_1059;
              case 24:
                goto LABEL_1122;
              case 25:
                goto LABEL_1185;
              case 26:
                goto LABEL_1248;
            }
          }
          return;
        }
        v1066 += v1151;
        v95 += v1056 * v1121;
        v96 += v1121 * v1060;
        v97 += v1121 * v1098;
        if ( v1262 )
        {
          v1075 = vec_window_height;
          if ( v1258 )
          {
            v1066 = vec_window_height;
          }
          else
          {
            v1258 = vec_window_height <= v1066;
            v1072 = vec_window_height - v1066;
          }
        }
      }
      else if ( v1262 )
      {
        v100 = vec_window_height - v1151;
        v1075 = vec_window_height - v1151;
        if ( v1258 )
        {
          v1066 = vec_window_height - v1151;
        }
        else
        {
          v27 = __OFSUB__(v100, v1066);
          v101 = v100 - v1066;
          v1258 = (v101 < 0) ^ v27 | (v101 == 0);
          v1072 = v101;
        }
      }
      v99 = &polyscans;
      do
      {
        *v99 = v95;
        v95 += v1056;
        v99[1] = v96;
        v96 += v1060;
        v99[4] = v97;
        v97 += v1098;
        v99 += 5;
        --v1066;
      }
      while ( v1066 );
      v98 = v1074;
      goto LABEL_198;
    case 2:
    case 3:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 18:
    case 19:
    case 22:
    case 23:
      v78 = v1066 * (__int64)(*v4 - *v3) / v63;
      v79 = *v3 - *v5;
      v80 = v78 + v79 == 0;
      v16 = (v78 + v79 < 0) ^ __OFADD__(v78, v79);
      v81 = v78 + v79;
      if ( v16 )
        return;
      if ( !v80 )
      {
        v82 = v81 + 1;
        v1076 = (int)(v3[2] + v1066 * (__int64)(v4[2] - v3[2]) / v1070 - v5[2]) / v82;
        v1077 = (int)(v3[3] + v1066 * (__int64)(v4[3] - v3[3]) / v1070 - v5[3]) / v82;
      }
      v1082 = (v5[2] - v3[2]) / v1066;
      v1090 = (v5[3] - v3[3]) / v1066;
      v1104 = (v4[2] - v5[2]) / v1072;
      v1106 = (v4[3] - v5[3]) / v1072;
      v83 = *v3 SHL16;
      v84 = v83;
      v85 = v3[2];
      v86 = v3[3];
      if ( v1254 )
      {
        v16 = v1075 <= -v1151;
        v1075 += v1151;
        if ( v16 )
          return;
        v1119 = -v1151;
        if ( -v1151 - v1066 >= 0 )
        {
          v1120 = v1119 - v1066;
          v1072 -= v1120;
          v87 = v1064 * v1120 + v1074;
          v84 += v1120 * v1060 + v1066 * v1060;
          v85 += v1120 * v1104 + v1066 * v1082;
          v86 += v1120 * v1106 + v1066 * v1090;
          if ( v1262 )
          {
            v1072 = vec_window_height;
            v1075 = vec_window_height;
          }
          v88 = &polyscans;
LABEL_174:
          if ( v1258 )
          {
            v29 = (unsigned __int8)vec_mode;
            switch ( vec_mode )
            {
              case 0:
                goto LABEL_309;
              case 1:
                return;
              case 2:
                goto LABEL_322;
              case 3:
                goto LABEL_353;
              case 4:
                goto LABEL_416;
              case 5:
                goto LABEL_445;
              case 6:
                goto LABEL_474;
              case 7:
              case 11:
                goto LABEL_537;
              case 8:
                goto LABEL_568;
              case 9:
              case 10:
                goto LABEL_631;
              case 12:
                goto LABEL_694;
              case 13:
                goto LABEL_725;
              case 14:
                goto LABEL_756;
              case 15:
                goto LABEL_785;
              case 16:
                goto LABEL_814;
              case 17:
                goto LABEL_843;
              case 18:
                goto LABEL_872;
              case 19:
                goto LABEL_903;
              case 20:
                goto LABEL_934;
              case 21:
                goto LABEL_965;
              case 22:
                goto LABEL_996;
              case 23:
                goto LABEL_1059;
              case 24:
                goto LABEL_1122;
              case 25:
                goto LABEL_1185;
              case 26:
                goto LABEL_1248;
            }
          }
          else
          {
            do
            {
              *v88 = v87;
              v87 += v1064;
              v88[1] = v84;
              v84 += v1060;
              v88[2] = v85;
              v85 += v1104;
              v88[3] = v86;
              v86 += v1106;
              v88 += 5;
              --v1072;
            }
            while ( v1072 );
            v29 = (unsigned __int8)vec_mode;
            switch ( vec_mode )
            {
              case 0:
                goto LABEL_309;
              case 1:
                return;
              case 2:
                goto LABEL_322;
              case 3:
                goto LABEL_353;
              case 4:
                goto LABEL_416;
              case 5:
                goto LABEL_445;
              case 6:
                goto LABEL_474;
              case 7:
              case 11:
                goto LABEL_537;
              case 8:
                goto LABEL_568;
              case 9:
              case 10:
                goto LABEL_631;
              case 12:
                goto LABEL_694;
              case 13:
                goto LABEL_725;
              case 14:
                goto LABEL_756;
              case 15:
                goto LABEL_785;
              case 16:
                goto LABEL_814;
              case 17:
                goto LABEL_843;
              case 18:
                goto LABEL_872;
              case 19:
                goto LABEL_903;
              case 20:
                goto LABEL_934;
              case 21:
                goto LABEL_965;
              case 22:
                goto LABEL_996;
              case 23:
                goto LABEL_1059;
              case 24:
                goto LABEL_1122;
              case 25:
                goto LABEL_1185;
              case 26:
                goto LABEL_1248;
            }
          }
          return;
        }
        v1066 += v1151;
        v83 += v1056 * v1119;
        v84 += v1119 * v1060;
        v85 += v1119 * v1082;
        v86 += v1119 * v1090;
        if ( v1262 )
        {
          v1075 = vec_window_height;
          if ( v1258 )
          {
            v1066 = vec_window_height;
          }
          else
          {
            v1258 = vec_window_height <= v1066;
            v1072 = vec_window_height - v1066;
          }
        }
      }
      else if ( v1262 )
      {
        v89 = vec_window_height - v1151;
        v1075 = vec_window_height - v1151;
        if ( v1258 )
        {
          v1066 = vec_window_height - v1151;
        }
        else
        {
          v27 = __OFSUB__(v89, v1066);
          v90 = v89 - v1066;
          v1258 = (v90 < 0) ^ v27 | (v90 == 0);
          v1072 = v90;
        }
      }
      v88 = &polyscans;
      do
      {
        *v88 = v83;
        v83 += v1056;
        v88[1] = v84;
        v84 += v1060;
        v88[2] = v85;
        v85 += v1082;
        v88[3] = v86;
        v86 += v1090;
        v88 += 5;
        --v1066;
      }
      while ( v1066 );
      v87 = v1074;
      goto LABEL_174;
    case 5:
    case 6:
    case 20:
    case 21:
    case 24:
    case 25:
    case 26:
      v64 = v1066 * (__int64)(*v4 - *v3) / v63;
      v65 = *v3 - *v5;
      v66 = v64 + v65 == 0;
      v16 = (v64 + v65 < 0) ^ __OFADD__(v64, v65);
      v67 = v64 + v65;
      if ( v16 )
        return;
      if ( !v66 )
      {
        v68 = v67 + 1;
        v1076 = (int)(v3[2] + v1066 * (__int64)(v4[2] - v3[2]) / v1070 - v5[2]) / v68;
        v1077 = (int)(v3[3] + v1066 * (__int64)(v4[3] - v3[3]) / v1070 - v5[3]) / v68;
        v64 = (int)(v3[4] + v1066 * (__int64)(v4[4] - v3[4]) / v1070 - v5[4]) / v68;
      }
      v1078 = v64;
      v1081 = (v5[2] - v3[2]) / v1066;
      v1089 = (v5[3] - v3[3]) / v1066;
      v1097 = (v5[4] - v3[4]) / v1066;
      v1103 = (v4[2] - v5[2]) / v1072;
      v1105 = (v4[3] - v5[3]) / v1072;
      v1107 = (v4[4] - v5[4]) / v1072;
      v69 = *v3 SHL16;
      v70 = v69;
      v71 = v3[2];
      v72 = v3[3];
      v73 = v3[4];
      if ( !v1254 )
      {
        if ( v1262 )
        {
          v76 = vec_window_height - v1151;
          v1075 = vec_window_height - v1151;
          if ( v1258 )
          {
            v1066 = vec_window_height - v1151;
          }
          else
          {
            v27 = __OFSUB__(v76, v1066);
            v77 = v76 - v1066;
            v1258 = (v77 < 0) ^ v27 | (v77 == 0);
            v1072 = v77;
          }
        }
        goto LABEL_147;
      }
      v16 = v1075 <= -v1151;
      v1075 += v1151;
      if ( v16 )
        return;
      v1117 = -v1151;
      if ( -v1151 - v1066 < 0 )
      {
        v1066 += v1151;
        v69 += v1056 * v1117;
        v70 += v1117 * v1060;
        v71 += v1117 * v1081;
        v72 += v1117 * v1089;
        v73 += v1117 * v1097;
        if ( v1262 )
        {
          v1075 = vec_window_height;
          if ( v1258 )
          {
            v1066 = vec_window_height;
          }
          else
          {
            v1258 = vec_window_height <= v1066;
            v1072 = vec_window_height - v1066;
          }
        }
LABEL_147:
        v75 = &polyscans;
        do
        {
          *v75 = v69;
          v69 += v1056;
          v75[1] = v70;
          v70 += v1060;
          v75[2] = v71;
          v71 += v1081;
          v75[3] = v72;
          v72 += v1089;
          v75[4] = v73;
          v73 += v1097;
          v75 += 5;
          --v1066;
        }
        while ( v1066 );
        v74 = v1074;
        goto LABEL_150;
      }
      v1118 = v1117 - v1066;
      v1072 -= v1118;
      v74 = v1064 * v1118 + v1074;
      v70 += v1118 * v1060 + v1066 * v1060;
      v71 += v1118 * v1103 + v1066 * v1081;
      v72 += v1118 * v1105 + v1066 * v1089;
      v73 += v1118 * v1107 + v1066 * v1097;
      if ( v1262 )
      {
        v1072 = vec_window_height;
        v1075 = vec_window_height;
      }
      v75 = &polyscans;
LABEL_150:
      if ( v1258 )
      {
        v29 = (unsigned __int8)vec_mode;
        switch ( vec_mode )
        {
          case 0:
            goto LABEL_309;
          case 1:
            return;
          case 2:
            goto LABEL_322;
          case 3:
            goto LABEL_353;
          case 4:
            goto LABEL_416;
          case 5:
            goto LABEL_445;
          case 6:
            goto LABEL_474;
          case 7:
          case 11:
            goto LABEL_537;
          case 8:
            goto LABEL_568;
          case 9:
          case 10:
            goto LABEL_631;
          case 12:
            goto LABEL_694;
          case 13:
            goto LABEL_725;
          case 14:
            goto LABEL_756;
          case 15:
            goto LABEL_785;
          case 16:
            goto LABEL_814;
          case 17:
            goto LABEL_843;
          case 18:
            goto LABEL_872;
          case 19:
            goto LABEL_903;
          case 20:
            goto LABEL_934;
          case 21:
            goto LABEL_965;
          case 22:
            goto LABEL_996;
          case 23:
            goto LABEL_1059;
          case 24:
            goto LABEL_1122;
          case 25:
            goto LABEL_1185;
          case 26:
            goto LABEL_1248;
        }
      }
      else
      {
        do
        {
          *v75 = v74;
          v74 += v1064;
          v75[1] = v70;
          v70 += v1060;
          v75[2] = v71;
          v71 += v1103;
          v75[3] = v72;
          v72 += v1105;
          v75[4] = v73;
          v73 += v1107;
          v75 += 5;
          --v1072;
        }
        while ( v1072 );
        v29 = (unsigned __int8)vec_mode;
        switch ( vec_mode )
        {
          case 0:
            goto LABEL_309;
          case 1:
            return;
          case 2:
            goto LABEL_322;
          case 3:
            goto LABEL_353;
          case 4:
            goto LABEL_416;
          case 5:
            goto LABEL_445;
          case 6:
            goto LABEL_474;
          case 7:
          case 11:
            goto LABEL_537;
          case 8:
            goto LABEL_568;
          case 9:
          case 10:
            goto LABEL_631;
          case 12:
            goto LABEL_694;
          case 13:
            goto LABEL_725;
          case 14:
            goto LABEL_756;
          case 15:
            goto LABEL_785;
          case 16:
            goto LABEL_814;
          case 17:
            goto LABEL_843;
          case 18:
            goto LABEL_872;
          case 19:
            goto LABEL_903;
          case 20:
            goto LABEL_934;
          case 21:
            goto LABEL_965;
          case 22:
            goto LABEL_996;
          case 23:
            goto LABEL_1059;
          case 24:
            goto LABEL_1122;
          case 25:
            goto LABEL_1185;
          case 26:
            goto LABEL_1248;
        }
      }
      return;
  }
}

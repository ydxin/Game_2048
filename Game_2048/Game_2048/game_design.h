#ifndef _GAME_DESIGN_H_
#define _GAME_DESIGN_H_

#include "game_main.h"

#define GAME_DESIGN_X		(GAME_BOX_X+4)	
#define GAME_DESIGN_Y		(GAME_BOX_Y+3)
#define NUM_INTERVAL			LINE_INTERVAL

#define COLOR_NUM_2			14
#define COLOR_NUM_4			2
#define COLOR_NUM_8			3
#define COLOR_NUM_16		4
#define COLOR_NUM_32		5
#define COLOR_NUM_64		6
#define COLOR_NUM_128		7
#define COLOR_NUM_256		8
#define COLOR_NUM_512		9
#define COLOR_NUM_1024	10
#define COLOR_NUM_2048	11

#define NUM_2			2
#define NUM_4			4
#define NUM_8			8
#define NUM_16			16
#define NUM_32			32
#define NUM_64			64
#define NUM_128		128
#define NUM_256		256
#define NUM_512		512
#define NUM_1024		1024
#define NUM_2048		2048

#define KEY_UP				 72
#define KEY_DOWN		 80
#define KEY_LEFT		  	 75
#define KEY_RIGHT		     77
#define KEY_ESC				 27
#define HORIZONTAL		 1
#define VERITICAL			 0

void Close();
void Replay();
void Regulation();
int GetBoxMaxNum();
void KeyProduction();
void RandomNum();
void TraversalBox();
int* NumAdd(int* item);
int IfUp();
int IfDown();
int IfLeft();
int IfRight();
int Judge_2n(int x);
int IfMove(int* item);
void TextColors(int num);
int DataPro(int(*item)[GAME_BOX_SIZE], int isHorizontal);
int KeyUp();
int KeyDown();
int KeyLeft();
int KeyRight();
void KeyEsc();
int	KeyControl(int key);
int GameWin();
int GameFailed();
void PlayGame();



#endif // !_GAME_DESIGN_H_

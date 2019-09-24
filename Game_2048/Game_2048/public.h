#ifndef  _PUBLIC_
#define _PUBLIC_
#include <Windows.h>

/*******宏  定  义*******/
#define GAME_FRAME_X	30		//全局游戏X轴坐标
#define GAME_FRAME_Y		2		//全局游戏Y轴坐标

extern int step;
extern int score;
extern long int time;
extern int box[4][4];
extern HANDLE hOut;

typedef enum WordColor
{
	BLACK,
	DEEP_BLUE,
	DEEP_GREEN,
	DEEP_BLUE_GREEN,
	DEEP_RED,
	PURPLE,
	DULL_YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_BLUE_GREEN,
	RED,
	PINK,
	YELLOW,
	LIGHT_WHITE
}WordColor;

void Color(int c);
void GotoXY(int x, int y);


#endif // ! _PUBLIC_

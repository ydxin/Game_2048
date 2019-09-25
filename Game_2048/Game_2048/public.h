#ifndef  _PUBLIC_
#define _PUBLIC_
#include <Windows.h>

/*******��  ��  ��*******/
#define GAME_FRAME_X	30		//ȫ����ϷX������
#define GAME_FRAME_Y		2		//ȫ����ϷY������
#define GAME_BOX_SIZE	4     //��Ϸ��������Ŀ
extern int step;
extern int score;
extern long int Time;
extern int box[GAME_BOX_SIZE][GAME_BOX_SIZE];
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

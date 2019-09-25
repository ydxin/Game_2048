#include "public.h"
#include <windows.h>//控制dos界面（获取控制台上坐标位置、设置字体颜色）

/*******定  义  全  局  变  量*******/
int step = 0;				//已执行步数
int score = 0;			//存储游戏分数
long int Time;			//游戏运行时间
int box[GAME_BOX_SIZE][GAME_BOX_SIZE] = {0};
HANDLE hOut;			//控制台句柄

void Color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
void GotoXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#include "game_main.h"
#include <stdio.h>
#include "public.h"
#include <windows.h>//控制dos界面（获取控制台上坐标位置、设置字体颜色）
#include <time.h>
void DrawLine(int x,int y,int len,int isHorizontal)
{
	if (isHorizontal)
	{
		for (int i = 0; i < len; i++)
		{
			GotoXY(x+i,y);
			printf("-");
		}
	
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			GotoXY(x , y+i);
			printf("|");
		}
	}
}

void DrawGameInfo()
{
	GotoXY(GAME_BOX_X, GAME_BOX_Y-1);   			//屏幕坐标位置
	Color(LIGHT_BLUE_GREEN);      								//淡浅绿色
	printf("游戏分数: %ld", score);
	Color(PINK);      														//粉色
	GotoXY(GAME_BOX_X+24, GAME_BOX_Y - 1);   	//屏幕坐标位置
	printf("执行步数: %d\n", step);
	GotoXY(GAME_BOX_X+20, GAME_BOX_Y+21);
	Color(LIGHT_GREEN);												 //绿色
	printf("已用时：%d s", time(NULL) - Time);				//输出游戏运行时间
}	

void DrawGameBox()
{
	system("cls");
	Color(YELLOW);
	for (int i = 0; i < LINE_NUMS; i++)
	{
		DrawLine(GAME_FRAME_X, GAME_FRAME_Y+i* LINE_INTERVAL/2, LINE_LENGTH, HORIZONTAL);
		DrawLine(GAME_FRAME_X + i * LINE_INTERVAL, GAME_FRAME_Y + 1, LINE_LENGTH / 2, VERITICAL);
	}
	DrawLine(GAME_FRAME_X, GAME_FRAME_Y + LINE_NUMS * LINE_INTERVAL / 2, LINE_LENGTH, HORIZONTAL);
	DrawLine(GAME_FRAME_X + LINE_NUMS * LINE_INTERVAL, GAME_FRAME_Y + 1, LINE_LENGTH / 2, VERITICAL);
	DrawGameInfo();
};


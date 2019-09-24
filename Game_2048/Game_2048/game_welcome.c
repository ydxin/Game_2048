#include "game_welcome.h"
#include "public.h"
#include <stdio.h>
void SetTitle()
{
	
	Color(LIGHT_BLUE_GREEN);          //浅淡绿色
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y);
	printf("■■■   ■■■■   ■  ■     ■■■■"); //输出2048字符画
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+1);
	printf("    ■   ■    ■   ■  ■     ■    ■");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+2);
	printf("■■■   ■    ■   ■  ■     ■■■■");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+3);
	printf("■       ■    ■   ■■■■   ■    ■");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+4);
	printf("■■■   ■■■■       ■     ■■■■");
	
}

void DrawRecFrame(int x, int y, int height, int width, int color)
{
	GotoXY(x, y);
	Color(color);
	printf("╔");
	GotoXY(x, y + height);
	printf("╚");
	GotoXY(x + width, y + height);
	printf("╝");
	GotoXY(x + width, y);
	printf("╗");
	int i = 0;
	for (i = 1; i < width; i += 1)
	{
		GotoXY(x + i, y);
		printf("═");         //打印上横框
	}
	for (i = 1; i < width; i += 1)
	{
		GotoXY(x + i, y + height);
		printf("═");         //打印下横框
	}
	for (i = 1; i < height; i++)
	{
		GotoXY(x, y + i);
		printf("║");         //打印左竖框
	}
	for (i = 1; i < height; i++)
	{
		GotoXY(x + width, y + i);
		printf("║");         //打印右竖框
	}
}

void ChoiceFrame()
{
	int n;
	DrawRecFrame(CHOICE_FRAME_X, CHOICE_FRAME_Y,
							 CHOICE_FRAME_HEIGHT, CHOICE_FRAME_WIDTH
							,RED);
	Color(PINK);
	GotoXY(25, 12);
	printf("1.开始游戏");
	GotoXY(40, 12);
	printf("2.游戏规则");
	GotoXY(25, 16);
	printf("3.按键说明");
	GotoXY(40, 16);
	printf("4.退出");
	GotoXY(21, 22);
	Color(DEEP_BLUE);
	printf("请选择[1 2 3 4]:[ ]\b\b");
	scanf("%d", &n);    //输入选项
	switch (n)
	{
	case 1:
		         //游戏开始函数
		break;
	case 2:
		     	//游戏规则函数
		break;
	case 3:
		     	//按键说明函数
		break;
	case 4:
		   		//关闭游戏函数
		break;
	}
}

void WelcomeGame()
{
	SetTitle();
	ChoiceFrame();
}
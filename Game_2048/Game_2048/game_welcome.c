#include "game_welcome.h"
#include "public.h"
#include <stdio.h>
#include "game_design.h"
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
	GotoXY(CHOICE_FRAME_X+10, CHOICE_FRAME_Y+4);
	printf("1.开始游戏");
	GotoXY(CHOICE_FRAME_X+35, CHOICE_FRAME_Y + 4);
	printf("2.游戏规则");
	GotoXY(CHOICE_FRAME_X + 10, CHOICE_FRAME_Y + 10);
	printf("3.按键说明");
	GotoXY(CHOICE_FRAME_X + 35, CHOICE_FRAME_Y + 10);
	printf("4.退出");
	GotoXY(CHOICE_FRAME_X+16, CHOICE_FRAME_Y + 13);
	Color(YELLOW);
	printf("请选择[1 2 3 4]:[ ]\b\b");
	scanf("%d", &n);    //输入选项
	switch (n)
	{
	case 1:
		PlayGame();         //游戏开始函数
		break;
	case 2:
		Regulation();     	//游戏规则函数
		break;
	case 3:
		KeyProduction();  //按键说明函数
		break;
	case 4:
		Close();			   		//关闭游戏函数
		break;
	}
}

void PlotRabbit()
{
	Color(LIGHT_BLUE);
	GotoXY(RABBIT_X, RABBIT_Y);//70 12
	printf("┏-┓  ┏-┓");
	GotoXY(RABBIT_X, RABBIT_Y+1);
	printf("┃ ┃  ┃ ┃");
	GotoXY(RABBIT_X, RABBIT_Y+2);
	printf("┃ ┃  ┃ ┃");
	GotoXY(RABBIT_X-1, RABBIT_Y+3);
	printf("_┃");
	GotoXY(RABBIT_X+7, RABBIT_Y+3);
	printf("┃_");
	GotoXY(RABBIT_X-2, RABBIT_Y+4);
	printf("┃");
	GotoXY(RABBIT_X+9, RABBIT_Y+4);
	printf("┃");
	GotoXY(RABBIT_X-2, RABBIT_Y+5);
	printf("┃");
	GotoXY(RABBIT_X+9, RABBIT_Y+5);
	printf("┃");
	GotoXY(RABBIT_X-2, RABBIT_Y + 6);
	printf("┃          ┃");
	GotoXY(RABBIT_X-2, RABBIT_Y + 7);
	printf("┗━┳━━━━━━┳━┛");
	GotoXY(RABBIT_X-2, RABBIT_Y + 8);
	printf("┏━┫      ┣━┓");
	Color(LIGHT_GREEN);
	GotoXY(RABBIT_X-3, RABBIT_Y + 9);
	printf("—┺┻┻┻┻━┻┻┻┻┹—");
	Color(DULL_YELLOW);
	GotoXY(RABBIT_X+1, RABBIT_Y + 3);
	printf("~  ＇ ~");
	Color(LIGHT_GREEN);
	GotoXY(RABBIT_X+1, RABBIT_Y + 4);
	printf("○   ○");
	Color(RED);
	GotoXY(RABBIT_X, RABBIT_Y + 6);
	printf("〃");
	GotoXY(RABBIT_X+7, RABBIT_Y + 6);
	printf("〃");
	Color(YELLOW);
	GotoXY(RABBIT_X+4, RABBIT_Y + 6);
	printf("┻");

}


void WelcomeGame()
{
	system("cls");
	SetTitle();
	PlotRabbit();
	ChoiceFrame();
	
}
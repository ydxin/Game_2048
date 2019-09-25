#include "game_main.h"
#include <stdio.h>
#include "public.h"
#include <windows.h>//����dos���棨��ȡ����̨������λ�á�����������ɫ��
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
	GotoXY(GAME_BOX_X, GAME_BOX_Y-1);   			//��Ļ����λ��
	Color(LIGHT_BLUE_GREEN);      								//��ǳ��ɫ
	printf("��Ϸ����: %ld", score);
	Color(PINK);      														//��ɫ
	GotoXY(GAME_BOX_X+24, GAME_BOX_Y - 1);   	//��Ļ����λ��
	printf("ִ�в���: %d\n", step);
	GotoXY(GAME_BOX_X+20, GAME_BOX_Y+21);
	Color(LIGHT_GREEN);												 //��ɫ
	printf("����ʱ��%d s", time(NULL) - Time);				//�����Ϸ����ʱ��
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


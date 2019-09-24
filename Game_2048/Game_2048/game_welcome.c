#include "game_welcome.h"
#include "public.h"
#include <stdio.h>
void SetTitle()
{
	
	Color(LIGHT_BLUE_GREEN);          //ǳ����ɫ
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y);
	printf("������   ��������   ��  ��     ��������"); //���2048�ַ���
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+1);
	printf("    ��   ��    ��   ��  ��     ��    ��");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+2);
	printf("������   ��    ��   ��  ��     ��������");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+3);
	printf("��       ��    ��   ��������   ��    ��");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+4);
	printf("������   ��������       ��     ��������");
	
}

void DrawRecFrame(int x, int y, int height, int width, int color)
{
	GotoXY(x, y);
	Color(color);
	printf("�X");
	GotoXY(x, y + height);
	printf("�^");
	GotoXY(x + width, y + height);
	printf("�a");
	GotoXY(x + width, y);
	printf("�[");
	int i = 0;
	for (i = 1; i < width; i += 1)
	{
		GotoXY(x + i, y);
		printf("�T");         //��ӡ�Ϻ��
	}
	for (i = 1; i < width; i += 1)
	{
		GotoXY(x + i, y + height);
		printf("�T");         //��ӡ�º��
	}
	for (i = 1; i < height; i++)
	{
		GotoXY(x, y + i);
		printf("�U");         //��ӡ������
	}
	for (i = 1; i < height; i++)
	{
		GotoXY(x + width, y + i);
		printf("�U");         //��ӡ������
	}
}

void ChoiceFrame()
{

}

#include "game_welcome.h"
#include "public.h"
#include <stdio.h>
#include "game_design.h"
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
	int n;
	DrawRecFrame(CHOICE_FRAME_X, CHOICE_FRAME_Y,
							 CHOICE_FRAME_HEIGHT, CHOICE_FRAME_WIDTH
							,RED);
	Color(PINK);
	GotoXY(CHOICE_FRAME_X+10, CHOICE_FRAME_Y+4);
	printf("1.��ʼ��Ϸ");
	GotoXY(CHOICE_FRAME_X+35, CHOICE_FRAME_Y + 4);
	printf("2.��Ϸ����");
	GotoXY(CHOICE_FRAME_X + 10, CHOICE_FRAME_Y + 10);
	printf("3.����˵��");
	GotoXY(CHOICE_FRAME_X + 35, CHOICE_FRAME_Y + 10);
	printf("4.�˳�");
	GotoXY(CHOICE_FRAME_X+16, CHOICE_FRAME_Y + 13);
	Color(YELLOW);
	printf("��ѡ��[1 2 3 4]:[ ]\b\b");
	scanf("%d", &n);    //����ѡ��
	switch (n)
	{
	case 1:
		PlayGame();         //��Ϸ��ʼ����
		break;
	case 2:
		Regulation();     	//��Ϸ������
		break;
	case 3:
		KeyProduction();  //����˵������
		break;
	case 4:
		Close();			   		//�ر���Ϸ����
		break;
	}
}

void PlotRabbit()
{
	Color(LIGHT_BLUE);
	GotoXY(RABBIT_X, RABBIT_Y);//70 12
	printf("��-��  ��-��");
	GotoXY(RABBIT_X, RABBIT_Y+1);
	printf("�� ��  �� ��");
	GotoXY(RABBIT_X, RABBIT_Y+2);
	printf("�� ��  �� ��");
	GotoXY(RABBIT_X-1, RABBIT_Y+3);
	printf("_��");
	GotoXY(RABBIT_X+7, RABBIT_Y+3);
	printf("��_");
	GotoXY(RABBIT_X-2, RABBIT_Y+4);
	printf("��");
	GotoXY(RABBIT_X+9, RABBIT_Y+4);
	printf("��");
	GotoXY(RABBIT_X-2, RABBIT_Y+5);
	printf("��");
	GotoXY(RABBIT_X+9, RABBIT_Y+5);
	printf("��");
	GotoXY(RABBIT_X-2, RABBIT_Y + 6);
	printf("��          ��");
	GotoXY(RABBIT_X-2, RABBIT_Y + 7);
	printf("�����ש������������ש���");
	GotoXY(RABBIT_X-2, RABBIT_Y + 8);
	printf("������      �ǩ���");
	Color(LIGHT_GREEN);
	GotoXY(RABBIT_X-3, RABBIT_Y + 9);
	printf("���ީߩߩߩߩ��ߩߩߩߩݡ�");
	Color(DULL_YELLOW);
	GotoXY(RABBIT_X+1, RABBIT_Y + 3);
	printf("~  �� ~");
	Color(LIGHT_GREEN);
	GotoXY(RABBIT_X+1, RABBIT_Y + 4);
	printf("��   ��");
	Color(RED);
	GotoXY(RABBIT_X, RABBIT_Y + 6);
	printf("��");
	GotoXY(RABBIT_X+7, RABBIT_Y + 6);
	printf("��");
	Color(YELLOW);
	GotoXY(RABBIT_X+4, RABBIT_Y + 6);
	printf("��");

}


void WelcomeGame()
{
	system("cls");
	SetTitle();
	PlotRabbit();
	ChoiceFrame();
	
}
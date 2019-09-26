#include "game_design.h"
#include "public.h"
#include "game_main.h"
#include <time.h>
#include	<stdio.h>
#include "game_welcome.h"
#include <conio.h>  //Ϊ�˶�ȡ�����
#include <math.h>
void Close()
{
	exit(0);
}
void Regulation()
{
	unsigned int reguX = GAME_BOX_X+10;  //34
	unsigned int reguY = GAME_BOX_Y;  //3
	int i = 1;
	int j = 1;
	system("cls");
	Color(PINK);
	GotoXY(reguX, reguY+2);
	printf("��Ϸ����");
	Color(DEEP_GREEN);
	for (i = reguY + 3; i <= reguY + 15; i++)   //������±߿�===
	{
		for (j = reguX - 22; j <= reguX + 36; j++)  //������ұ߿�||
		{
			GotoXY(j, i);
			if (i == reguY + 3 || i == reguY + 15) printf("=");
			else if (j == reguX - 22 || j == reguX + 35) printf("||");
		}
	}
	Color(RED);
	GotoXY(reguX - 18, reguY + 4);
	printf("tip1: ��ҿ���ͨ���� �� �� ����������ƶ�����");
	Color(DEEP_BLUE_GREEN);
	GotoXY(reguX - 18, reguY + 6);
	printf("tip2: ��ESC�˳���Ϸ");
	Color(LIGHT_WHITE);
	GotoXY(reguX - 18, reguY + 8);
	printf("tip3: ���ѡ��ķ�����,������ͬ��������ϲ�");
	Color(YELLOW);
	GotoXY(reguX - 18, reguY + 10);
	printf("tip4: ÿ�ƶ�һ������λ�������һ��2��4");
	Color(LIGHT_BLUE_GREEN);
	GotoXY(reguX - 18, reguY + 12);
	printf("tip5: ���̱������������޷�������Ч�ƶ�����Ϸʧ��");
	Color(LIGHT_GREEN);
	GotoXY(reguX - 18, reguY + 14);
	printf("tip6: �����ϳ���2048����Ϸʤ��");
	getch();                //�����������������
	system("cls");
	WelcomeGame();
}
void KeyProduction()
{
	unsigned int keyProX = GAME_BOX_X + 19;  //32
	unsigned int keyProY = GAME_BOX_Y;			//3
	system("cls");
	Color(PINK);
	GotoXY(keyProX, keyProY+2);
	printf("����˵��");
	Color(DEEP_BLUE_GREEN);
	GotoXY(keyProX - 14, keyProY + 4);
	printf("�١��������������������������Ϸ������");
	Color(LIGHT_GREEN);
	GotoXY(keyProX - 14, keyProY + 10);
	printf("�ڡ�ESC���˳���Ϸ");
	getch();							//�����������������
	WelcomeGame();
}

void TraversalBox()
{
	for (int i = 0; i < GAME_BOX_SIZE; i++)         //������������
	{
		for (int j = 0; j < GAME_BOX_SIZE; j++)
		{
			if (box[i][j] == 0)      //����������п�λ���ͼ�����ȥ
			{
				continue;
			}
			GotoXY(GAME_DESIGN_X + j * NUM_INTERVAL, GAME_DESIGN_Y + i * NUM_INTERVAL / 2);  //����������ʾλ��
			int c = box[i][j];  //���������box[i][j]�ϵ�����
			TextColors(c);  //�������ӵ���ɫ����ͬ������ʾ��ͬ��ɫ
			printf("%d", c);    //��ӡ����	
		}
	}
}

void RandomNum()
{
	int a = 0;
	int b = 0;
	do
	{
		a = rand() % GAME_BOX_SIZE;               //���4*4�����е������λ��
		b = rand() % GAME_BOX_SIZE;
	} while (box[a][b] != 0);
	if (rand() % GAME_BOX_SIZE == 0)      		//2��4��������ڿո�(�ʼ�����������ϵ�2��4)
	{
		box[a][b] = 4;
	}
	else
	{
		box[a][b] = 2;
	}
}

void TextColors(int num)
{
	switch (num)
	{
	case NUM_2:
		Color(COLOR_NUM_2);
		break;
	case NUM_4:
		Color(COLOR_NUM_4);
		break;
	case NUM_8:
		Color(COLOR_NUM_8);
		break;
	case NUM_16:
		Color(COLOR_NUM_16);
		break;
	case NUM_32:
		Color(COLOR_NUM_32);
		break;
	case NUM_64:
		Color(COLOR_NUM_64);
		break;
	case NUM_128:
		Color(COLOR_NUM_128);
		break;
	case NUM_256:
		(COLOR_NUM_256);
		break;
	case  NUM_512:
		Color(COLOR_NUM_512);
		break;
	case NUM_1024:
		Color(COLOR_NUM_1024);
		break;
	case  NUM_2048:
		Color(COLOR_NUM_2048);
		break;
	default:
		break;
	}
}

int* NumAdd(int *input)
{
	int i = 0;
	int j = 0;
	int temp[GAME_BOX_SIZE] = { 0 };
	int out[GAME_BOX_SIZE] = { 0 };
	for (i = 0; i < GAME_BOX_SIZE; i++)
	{
		if (input[i] != 0)
			temp[j++] = input[i];
	}
	for (i = 0; i < GAME_BOX_SIZE; i++)
	{
		if (temp[i] == temp[i + 1])
		{
			temp[i] *= 2;
			temp[i + 1] = 0;
			score = score + temp[i];
		}
	}
	j = 0;
	for ( i = 0; i < GAME_BOX_SIZE; i++)
	{
		if (temp[i]!=0)
			out[j++] = temp[i];
	}
	memset(input, 0, GAME_BOX_SIZE * sizeof(int));
	memcpy(input, out, GAME_BOX_SIZE * sizeof(int));
	return input;
}

int IfMove(int *item)
{
	for (int i  = GAME_BOX_SIZE - 1; i > 0 ; i -- )
	{
		if (item[i] != 0 && item[i] == item[i - 1])
		{
			return 1;
		}
		if (item[i] != 0 && item[i - 1] == 0)
		{
			return 1;
		}
	}
	return 0;
}


int	KeyControl(int key)
{
	int ret = 0;
	switch (key)
	{
	case KEY_UP:
		ret= KeyUp();
		break;
	case KEY_DOWN:
		ret = KeyDown();
		break;
	case KEY_LEFT:
		ret = KeyLeft();
		break;
	case KEY_RIGHT:
		ret = KeyRight();
		break;
	case KEY_ESC:
		KeyEsc();
		break;
	default:
		return ret;
	}
	return ret;
}

int	DataPro(int (*item)[GAME_BOX_SIZE],int isHorizontal)
{
	int j = 0;
	int tp[GAME_BOX_SIZE] = { 0 };
	int* p = &tp;
	for (int i = 0; i < GAME_BOX_SIZE; i++)
	{
		for (int k = 0; k < GAME_BOX_SIZE; k++)
		{
			if (isHorizontal)
				tp[k] = item[i][k];  //�����ƶ�������Ĭ������LEFT
			else 
				tp[k] = item[k][i];  //�����ƶ�������Ĭ������UP
		}
		p = NumAdd(tp);
		if (IfMove(tp))
		{
			j++;
		}
		for (int k = 0; k < GAME_BOX_SIZE; k++)
		{
			if (isHorizontal)
				item[i][k] = p[k];
			else
				item[k][i] = p[k];
		}
	}
	return (j != 4);
}

int  KeyUp()
{
	int temp[GAME_BOX_SIZE][GAME_BOX_SIZE] = { 0 };
	int ret = 0;
	memcpy(temp, box, GAME_BOX_SIZE * GAME_BOX_SIZE * sizeof(int));
	ret = DataPro(temp, VERITICAL);
	memcpy(box, temp, sizeof(temp));
	return ret;
}

int KeyDown()
{
	int temp[GAME_BOX_SIZE][GAME_BOX_SIZE] = { 0 };
	int ret = 0;
	for (int i = 0; i < GAME_BOX_SIZE; i++)
	{
		for (int  j  = 0;  j < GAME_BOX_SIZE; j++)
		{
			temp[GAME_BOX_SIZE - 1 - i][j] = box[i][j];
		}
	}
	ret = DataPro(temp, VERITICAL);
	for (int i = 0; i < GAME_BOX_SIZE; i++)
	{
		for (int j = 0; j < GAME_BOX_SIZE; j++)
		{
			box[GAME_BOX_SIZE - 1 - i][j] = temp[i][j];
		}
	}
	return ret;

}

int KeyLeft()
{

	int temp[GAME_BOX_SIZE][GAME_BOX_SIZE] = { 0 };
	int ret = 0;
	memcpy(temp, box, sizeof(box));
	ret = DataPro(temp, HORIZONTAL);
	memcpy(box, temp, sizeof(temp));
	return ret;
}

int KeyRight()
{
	int temp[GAME_BOX_SIZE][GAME_BOX_SIZE] = { 0 };
	int ret = 0;
	for (int i = 0; i < GAME_BOX_SIZE; i++)
	{
		for (int j = 0; j < GAME_BOX_SIZE; j++)
		{
			temp[i][GAME_BOX_SIZE - 1 - j] = box[i][j];
		}
	}
	ret = DataPro(temp, HORIZONTAL);
	for (int i = 0; i < GAME_BOX_SIZE; i++)
	{
		for (int j = 0; j < GAME_BOX_SIZE; j++)
		{
			box[i][GAME_BOX_SIZE - 1 - j] = temp[i][j];
		}
	}
	return ret;
}

int Judge_2n(int x)
{
	for (int n = 1; n <= COLOR_NUM_2048; n++)		//2��11�η���2048����ϷĿ���Ǵﵽ2048
	{
		if (x == pow(2, n))       //����2��n�η�
		{
			return 1;
		}
	}
	return 0;
}

int IfUp()
{
	int flag = 0;           //�����־������ֻ��0��1
	for (int j = 0; j < GAME_BOX_SIZE; j++)
		for (int i = GAME_BOX_SIZE - 1; i > 0; i--)
		{
			if ((Judge_2n(box[i][j] + box[i - 1][j]) == 1) )
			{
				return 1;
			}
		}
	return 0;
}

int IfDown()
{

	for (int j = 0; j < GAME_BOX_SIZE; j++)
	{
		for (int i = 0; i < GAME_BOX_SIZE - 1; i++)
		{
			if ((Judge_2n(box[i][j] + box[i + 1][j]) == 1) )
				return 1;
		}
	}
	return 0;
}

int IfLeft()
{
	int flag = 0;           //�����־������ֻ��0��1
	for (int j = 0; j < GAME_BOX_SIZE; j++)
	{
		for (int i = GAME_BOX_SIZE - 1; i > 0; i--)
		{
			if ((Judge_2n(box[j][i] == box[j][i - 1]) == 1) )
			{
				return 1;
			}
		}
	}
	return 0;
}

int IfRight()
{
	int flag = 0;           //�����־������ֻ��0��1
	for (int j = 0; j < GAME_BOX_SIZE; j++)
	{
		for (int i = 0; i < GAME_BOX_SIZE - 1; i++)
		{
			if ((Judge_2n(box[j][i] == box[j][i + 1]) == 1) )
			{
				return 1;
			}
		}
	}
	return 0;
}

void KeyEsc()
{
	WelcomeGame();
}

int GameWin()
{
	int flag = 0;
	unsigned int winX = GAME_FRAME_X - 20;
	unsigned int winY = GAME_FRAME_Y + 4;
	if (GetBoxMaxNum() == NUM_2048)            //��������е����ֵΪ2048���ﵽĿ�꣬����Ϸʤ��
	{
		system("cls");
		GotoXY(winX, winY);
		Color(RED);   //����ɫ
		printf("     ��             ��             ��       ����������       ��          ��  \n");  //���ʤ��win���ַ���
		GotoXY(winX, winY+1);
		printf("      ��           ����           ��            ��           �� ��       ��  \n");
		GotoXY(winX, winY+2);
		printf("       ��         ��  ��         ��             ��           ��  ��      ��  \n");
		GotoXY(winX, winY + 3);
		printf("        ��       ��    ��       ��              ��           ��   ��     ��   \n");
		GotoXY(winX, winY + 4);
		printf("         ��     ��      ��     ��               ��           ��    ��    ��  \n");
		GotoXY(winX, winY + 5);
		printf("          ��   ��        ��   ��                ��           ��     ��   �� \n");
		GotoXY(winX, winY + 6);
		printf("           �� ��          �� ��                 ��           ��      ��  ��    \n");
		GotoXY(winX, winY + 7);
		printf("            ����          ����                  ��           ��       �� ��  \n");
		GotoXY(winX, winY + 8);
		printf("             ��            ��               ����������       ��          ��   \n");
		GotoXY(winX +25, winY + 11);
		Color(YELLOW);
		printf("ʤ�����������������");
		flag = 1;
	}
	return flag;                //flag��ֵ������0������1���ʾ��Ϸʤ��
}

int GameFailed()
{
	int flag = 0;
	int max;
	unsigned int failedX = GAME_FRAME_X + 4;
	unsigned int failedY = GAME_FRAME_Y + 1;
	if (IfUp() || IfDown() || IfLeft() || IfRight())
		return flag;
	else
	{
		system("cls");
		GotoXY(failedX, failedY);
		Color(LIGHT_GREEN);
		printf("�ϲ�����������ǣ�");
		GotoXY(failedX + 18, failedY);
		Color(PINK);
		max = GetBoxMaxNum();
		printf("%d", max);
		GotoXY(failedX - 15, failedY + 3);
		Color(DEEP_RED);   //����ɫ
		printf("     ����������    ��         ��    ����     \n");  //���end�ַ���
		GotoXY(failedX - 15, failedY + 4);
		printf("     ��            ����       ��    ��  ��   \n");
		GotoXY(failedX - 15, failedY + 5);
		printf("     ��            �� ��      ��    ��    ��   \n");
		GotoXY(failedX - 15, failedY + 6);
		printf("     ��            ��  ��     ��    ��     ��  \n");
		GotoXY(failedX - 15, failedY + 7);
		printf("     ��������      ��   ��    ��    ��      ��  \n");
		GotoXY(failedX - 15, failedY + 8);
		printf("     ��            ��    ��   ��    ��     ��  \n");
		GotoXY(failedX - 15, failedY + 9);
		printf("     ��            ��     ��  ��    ��    ��   \n");
		GotoXY(failedX - 15, failedY + 10);
		printf("     ��            ��      �� ��    ��  ��  \n");
		GotoXY(failedX - 15, failedY + 11);
		printf("     ����������    ��       ����    ����     \n");
		GotoXY(failedX, failedY + 14);
		Color(YELLOW);
		printf("�޷��ƶ�����Ϸʧ�ܣ�");                             //��ʾ����
		GotoXY(failedX, failedY + 16);
		Color(LIGHT_BLUE_GREEN);
		printf("��ķ����ǣ�%d����ʱ��%d s����ִ�У�%d ��", score, Time, step);
		flag = 1;
		return flag;                //flag��ֵ������0������1���ʾ��Ϸʧ��
	}
}

int GetBoxMaxNum()
{
	int max = box[0][0];       	 	//��ʼ��box����
	int i, j;
	for (i = 0; i < GAME_BOX_SIZE; i++)      	//������������
	{
		for (j = 0; j < GAME_BOX_SIZE; j++)
		{
			if (box[i][j] > max) 	//�������������ֵ����max��ֵ
			{
				max = box[i][j];    //�������е�ֵ��ֵ��max�������ҳ������е������
			}
		}
	}
	return max;                     //����max��ֵ��Ҳ���ǵ�ǰ�����е����ֵ
}

void PlayGame()
{
	//��ʼ��box����
	memset(box, 0, GAME_BOX_SIZE * GAME_BOX_SIZE * sizeof(int));
	int a = 0;
	int b = 0;
	Time = time(NULL);
	DrawGameBox();
	srand(time(NULL));
	RandomNum();
	TraversalBox();
	while (1)
	{
		while (kbhit())
		{
			int ch = getch();
			ch = getch();
			if (!KeyControl(ch))  //������µİ���������keyboardControl()�����ж���ģ���û�з�Ӧ��һֱ�����¶���İ���Ϊֹ
			{
				continue;
			}
			RandomNum();
			DrawGameBox();       		//��������
			TraversalBox();					//ѭ������������
			step++;                 //���мƲ�
		}
	
		if (GameFailed() + GameWin() != 0)  //ֻҪGamefaile()����Gamewin()����һ����������1��Ҳ���ǳɹ�����ʧ�ܶ���������������
		{
			int n;
			int x = (GAME_BOX_X - 22);
			int y = (GAME_BOX_Y + 17);
			GotoXY(x, y);
			Color(YELLOW);
			printf("������1��2��");
			GotoXY(x, y+2);
			Color(LIGHT_GREEN);
			printf("1: ��Ҫ������һ��");
			GotoXY(x, y+4);
			Color(PINK);
			printf("2: �����ˣ��˳���\n");
			GotoXY(x, y+6);
			Color(RED);
			printf("��ѡ�񡿣�");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				Replay();         //������Ϸ����
				break;
			case 2:
				Close();    		//�ر���Ϸ����
				break;
			}
		}
	
	}
}

void Replay()
{
	//����
	system("cls");                  
	 //��������������
	score = 0;
	step = 0;                
	//��ʼ��Ϸ
	PlayGame();                         
}
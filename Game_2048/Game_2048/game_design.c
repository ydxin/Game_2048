#include "game_design.h"
#include "public.h"
#include "game_main.h"
#include <time.h>
#include	<stdio.h>
#include "game_welcome.h"
#include <conio.h>  //为了读取方向键
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
	printf("游戏规则");
	Color(DEEP_GREEN);
	for (i = reguY + 3; i <= reguY + 15; i++)   //输出上下边框===
	{
		for (j = reguX - 22; j <= reguX + 36; j++)  //输出左右边框||
		{
			GotoXY(j, i);
			if (i == reguY + 3 || i == reguY + 15) printf("=");
			else if (j == reguX - 22 || j == reguX + 35) printf("||");
		}
	}
	Color(RED);
	GotoXY(reguX - 18, reguY + 4);
	printf("tip1: 玩家可以通过↑ ↓ ← →方向键来移动方块");
	Color(DEEP_BLUE_GREEN);
	GotoXY(reguX - 18, reguY + 6);
	printf("tip2: 按ESC退出游戏");
	Color(LIGHT_WHITE);
	GotoXY(reguX - 18, reguY + 8);
	printf("tip3: 玩家选择的方向上,若有相同的数字则合并");
	Color(YELLOW);
	GotoXY(reguX - 18, reguY + 10);
	printf("tip4: 每移动一步，空位随机出现一个2或4");
	Color(LIGHT_BLUE_GREEN);
	GotoXY(reguX - 18, reguY + 12);
	printf("tip5: 棋盘被数字填满，无法进行有效移动，游戏失败");
	Color(LIGHT_GREEN);
	GotoXY(reguX - 18, reguY + 14);
	printf("tip6: 棋盘上出现2048，游戏胜利");
	getch();                //按任意键返回主界面
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
	printf("按键说明");
	Color(DEEP_BLUE_GREEN);
	GotoXY(keyProX - 14, keyProY + 4);
	printf("①、↑、↓、←、→方向键进行游戏操作！");
	Color(LIGHT_GREEN);
	GotoXY(keyProX - 14, keyProY + 10);
	printf("②、ESC键退出游戏");
	getch();							//按任意键返回主界面
	WelcomeGame();
}

void TraversalBox()
{
	for (int i = 0; i < GAME_BOX_SIZE; i++)         //遍历整个网格
	{
		for (int j = 0; j < GAME_BOX_SIZE; j++)
		{
			if (box[i][j] == 0)      //如果网格中有空位，就继续下去
			{
				continue;
			}
			GotoXY(GAME_DESIGN_X + j * NUM_INTERVAL, GAME_DESIGN_Y + i * NUM_INTERVAL / 2);  //设置棋子显示位置
			int c = box[i][j];  //获得棋盘上box[i][j]上的数字
			TextColors(c);  //设置棋子的颜色，不同数字显示不同颜色
			printf("%d", c);    //打印棋子
			step++;                 //进行计步
		}
	}
}

void RandomNum()
{
	int a = 0;
	int b = 0;
	do
	{
		a = rand() % GAME_BOX_SIZE;               //获得4*4棋盘中的随机空位置
		b = rand() % GAME_BOX_SIZE;
	} while (box[a][b] != 0);
	if (rand() % GAME_BOX_SIZE == 0)      		//2或4随机出现在空格处(最开始出现在棋盘上的2或4)
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
				tp[k] = item[i][k];  //左右移动，这里默认向左LEFT
			else 
				tp[k] = item[k][i];  //上下移动，这里默认向上UP
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
	for (int n = 1; n <= COLOR_NUM_2048; n++)		//2的11次方是2048，游戏目标是达到2048
	{
		if (x == pow(2, n))       //计算2的n次方
		{
			return 1;
		}
	}
	return 0;
}

int IfUp()
{
	int flag = 0;           //定义标志变量，只有0或1
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
	int flag = 0;           //定义标志变量，只有0或1
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
	int flag = 0;           //定义标志变量，只有0或1
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
	if (GetBoxMaxNum() == NUM_2048)            //如果棋盘中的最大值为2048，达到目标，则游戏胜利
	{
		system("cls");
		GotoXY(winX, winY);
		Color(RED);   //暗绿色
		printf("     ■             ■             ■       ■■■■■       ■          ■  \n");  //输出胜利win的字符画
		GotoXY(winX, winY+1);
		printf("      ■           ■■           ■            ■           ■ ■       ■  \n");
		GotoXY(winX, winY+2);
		printf("       ■         ■  ■         ■             ■           ■  ■      ■  \n");
		GotoXY(winX, winY + 3);
		printf("        ■       ■    ■       ■              ■           ■   ■     ■   \n");
		GotoXY(winX, winY + 4);
		printf("         ■     ■      ■     ■               ■           ■    ■    ■  \n");
		GotoXY(winX, winY + 5);
		printf("          ■   ■        ■   ■                ■           ■     ■   ■ \n");
		GotoXY(winX, winY + 6);
		printf("           ■ ■          ■ ■                 ■           ■      ■  ■    \n");
		GotoXY(winX, winY + 7);
		printf("            ■■          ■■                  ■           ■       ■ ■  \n");
		GotoXY(winX, winY + 8);
		printf("             ■            ■               ■■■■■       ■          ■   \n");
		GotoXY(winX +25, winY + 11);
		Color(YELLOW);
		printf("胜利啦，你真棒！！！");
		flag = 1;
	}
	return flag;                //flag的值正常是0，返回1则表示游戏胜利
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
		printf("合并出的最大数是：");
		GotoXY(failedX + 18, failedY);
		Color(PINK);
		max = GetBoxMaxNum();
		printf("%d", max);
		GotoXY(failedX - 15, failedY + 3);
		Color(DEEP_RED);   //暗红色
		printf("     ■■■■■    ■         ■    ■■     \n");  //输出end字符画
		GotoXY(failedX - 15, failedY + 4);
		printf("     ■            ■■       ■    ■  ■   \n");
		GotoXY(failedX - 15, failedY + 5);
		printf("     ■            ■ ■      ■    ■    ■   \n");
		GotoXY(failedX - 15, failedY + 6);
		printf("     ■            ■  ■     ■    ■     ■  \n");
		GotoXY(failedX - 15, failedY + 7);
		printf("     ■■■■      ■   ■    ■    ■      ■  \n");
		GotoXY(failedX - 15, failedY + 8);
		printf("     ■            ■    ■   ■    ■     ■  \n");
		GotoXY(failedX - 15, failedY + 9);
		printf("     ■            ■     ■  ■    ■    ■   \n");
		GotoXY(failedX - 15, failedY + 10);
		printf("     ■            ■      ■ ■    ■  ■  \n");
		GotoXY(failedX - 15, failedY + 11);
		printf("     ■■■■■    ■       ■■    ■■     \n");
		GotoXY(failedX, failedY + 14);
		Color(YELLOW);
		printf("无法移动，游戏失败！");                             //提示文字
		flag = 1;
		return flag;                //flag的值正常是0，返回1则表示游戏失败
	}
}

int GetBoxMaxNum()
{
	int max = box[0][0];       	 	//初始化box数组
	int i, j;
	for (i = 0; i < GAME_BOX_SIZE; i++)      	//遍历整个数组
	{
		for (j = 0; j < GAME_BOX_SIZE; j++)
		{
			if (box[i][j] > max) 	//如果数组中有数值大于max的值
			{
				max = box[i][j];    //将数组中的值赋值给max，这样找出数组中的最大数
			}
		}
	}
	return max;                     //返回max的值。也就是当前棋盘中的最大值
}

void PlayGame()
{
	//初始化box数组
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
			if (!KeyControl(ch))  //如果按下的按键不是在keyboardControl()方法中定义的，会没有反应，一直到按下定义的按键为止
			{
				continue;
			}
			DrawGameBox();       		//绘制棋盘
			TraversalBox();					//循环整个的棋盘
			RandomNum();
		}
	
		if (GameFailed() + GameWin() != 0)  //只要Gamefaile()或者Gamewin()任意一个函数返回1，也就是成功或是失败都会出现下面的内容
		{
			//getch();
			Replay();         //重新游戏函数
		}
	
	}
}

void Replay()
{
	//清屏
	system("cls");                  
	 //分数、步数归零
	score = 0;
	step = 0;                
	//开始游戏
	PlayGame();                         
}
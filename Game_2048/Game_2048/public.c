#include "public.h"
#include <windows.h>//����dos���棨��ȡ����̨������λ�á�����������ɫ��

/*******��  ��  ȫ  ��  ��  ��*******/
int step = 0;				//��ִ�в���
int score = 0;			//�洢��Ϸ����
long int time;			//��Ϸ����ʱ��
int box[4][4] = {0};
HANDLE hOut;			//����̨���

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
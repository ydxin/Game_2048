#include "game_welcome.h"
#include "public.h"
#include <stdio.h>
void SetTitle()
{
	
	Color(LIGHT_BLUE_GREEN);          //Ç³µ­ÂÌÉ«
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y);
	printf("¡ö¡ö¡ö   ¡ö¡ö¡ö¡ö   ¡ö  ¡ö     ¡ö¡ö¡ö¡ö"); //Êä³ö2048×Ö·û»­
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+1);
	printf("    ¡ö   ¡ö    ¡ö   ¡ö  ¡ö     ¡ö    ¡ö");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+2);
	printf("¡ö¡ö¡ö   ¡ö    ¡ö   ¡ö  ¡ö     ¡ö¡ö¡ö¡ö");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+3);
	printf("¡ö       ¡ö    ¡ö   ¡ö¡ö¡ö¡ö   ¡ö    ¡ö");
	GotoXY(WELCOME_TITLE_X, WELCOME_TITLE_Y+4);
	printf("¡ö¡ö¡ö   ¡ö¡ö¡ö¡ö       ¡ö     ¡ö¡ö¡ö¡ö");
	
}

void DrawRecFrame(int x, int y, int height, int width, int color)
{
	GotoXY(x, y);
	Color(color);
	printf("¨X");
	GotoXY(x, y + height);
	printf("¨^");
	GotoXY(x + width, y + height);
	printf("¨a");
	GotoXY(x + width, y);
	printf("¨[");
	int i = 0;
	for (i = 1; i < width; i += 1)
	{
		GotoXY(x + i, y);
		printf("¨T");         //´òÓ¡ÉÏºá¿ò
	}
	for (i = 1; i < width; i += 1)
	{
		GotoXY(x + i, y + height);
		printf("¨T");         //´òÓ¡ÏÂºá¿ò
	}
	for (i = 1; i < height; i++)
	{
		GotoXY(x, y + i);
		printf("¨U");         //´òÓ¡×óÊú¿ò
	}
	for (i = 1; i < height; i++)
	{
		GotoXY(x + width, y + i);
		printf("¨U");         //´òÓ¡ÓÒÊú¿ò
	}
}

void ChoiceFrame()
{

}

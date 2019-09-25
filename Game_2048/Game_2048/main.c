#include <stdio.h>
#include "public.h"
int main()
{
	
	WelcomeGame();

	Color(RED);
	GotoXY(GAME_FRAME_X, GAME_FRAME_Y);
	//printf("¡ö");
	getchar();
	return 0;
}
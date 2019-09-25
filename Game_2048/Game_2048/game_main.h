#ifndef  _GAME_MAIN_H_
#define _GAME_MAIN_H_

#include "public.h"

#define GAME_BOX_X			30
#define GAME_BOX_Y			2

#define HORIZONTAL			1
#define VERITICAL				0
#define LINE_INTERVAL		10
#define LINE_NUMS			GAME_BOX_SIZE
#define LINE_LENGTH			(GAME_BOX_SIZE*LINE_INTERVAL)



void DrawLine();
void DrawGameInfo();
void DrawGameBox();
void Close();
void Regulation();
void KeyProduction();

#endif // ! _GAME_MAIN_H_

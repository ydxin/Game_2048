#ifndef _GAME_WELCOME_H_
#define _GAME_WELCOME_H_

#include "public.h"

#define WELCOME_TITLE_X  GAME_FRAME_X   //welcome�����X�������
#define WELCOME_TITLE_Y  GAME_FRAME_Y	   //welcome�����Y�������

#define CHOICE_FRAME_X				 (GAME_FRAME_X-6)
#define CHOICE_FRAME_Y				 (WELCOME_TITLE_Y+6)
#define CHOICE_FRAME_HEIGHT	 15
#define CHOICE_FRAME_WIDTH	 50


void SetTitle();
void DrawRecFrame();
void ChoiceFrame();
void WelcomeGame();
#endif
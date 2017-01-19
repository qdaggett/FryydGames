#include "spritelib\spritelib.h"
#include <iostream>
using namespace spritelib;

//rev.1 = game loop and window settings #GABBY

enum eGameState { NEW_GAME, PAUSE, QUIT, INSTRUCT, SETTINGS };
enum mGameState { OPENING, MENU };

int main()
{
	// window definition

	Window& myGame = Window::get_game_window();
	myGame.init("Codename: CAJUN", 1280.0f, 720.0f, false)
		.set_window_style(true, true);

	//text settings: insert below

	while (myGame.update(30)) // main game loop 
	{
		mGameState main = OPENING; // the opening cutscene for the game 
		switch (main)
		{
		case OPENING: // the opening cutscene for the game 
		{

		}
		break;

		case MENU: //main menu 
		{

		}
		break;
		}
	}

	return 0;
}
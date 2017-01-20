#include "spritelib\spritelib.h"
#include <iostream>
using namespace spritelib;

//rev.1 = game loop and window settings #GABBY

enum eGameState { NEW_GAME, PAUSE, QUIT, INSTRUCT, SETTINGS, M_STATION }; // M_STATION is just the menu in stationary position
enum mGameState { OPENING, MENU };

int main()
{
	// window definition

	Window& myGame = Window::get_game_window();
	myGame.init("Codename: CAJUN", 1280, 720, false)
		.set_window_style(true, true);

	//text settings: insert below

	while (myGame.update(30)) // main game loop 
	{
		mGameState main = OPENING; // the opening cutscene for the game 
		switch (main)
		{
			case OPENING: // the opening cutscene for the game 
				{

					mGameState main = MENU; // once the opening is complete, main has been set to menu, there for changing the switch case
				}
				break;

			case MENU: //main menu 
				{
					eGameState gamestate = M_STATION;

				}
				break;
		}
	}

	return 0;
}
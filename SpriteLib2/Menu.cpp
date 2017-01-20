#include "spritelib\spritelib.h"
#include "Menu.h"
#include <iostream>
using namespace spritelib;

void Menu::drawMenu()
{
	Text::load_font("assets/times.ttf", "basic");

	// background + animation frames

	//button sprite loading 
	Sprite gameButton,pauseButton,quitButton,setButton,instructButton;
	
	gameButton.load_sprite_image("assets/images/menu_button.png")// <- path is needed from assets to load
		.set_sprite_frame_size(400,200); //size of button (width and height needed)

}


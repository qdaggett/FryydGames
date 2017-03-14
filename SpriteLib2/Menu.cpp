#include "spritelib\spritelib.h"
#include "Buttons.h"
#include "Menu.h"
#include <iostream>

using namespace spritelib;
using namespace std;

Sprite comLogo, gameLogo, menuBackground, gameButton, creditButton, setButton;

void Menu::drawMenu()
{
	Menu menu;
	Sprite comLogo, gameLogo, menuBackground;

	Text::load_font("assets/times.ttf", "basic");

	//background

	// game logo

	// company logo 
	comLogo.load_sprite_image("assets/images/companyLogo.png")
		.set_sprite_frame_size(656, 874)
		.set_scale(275, 275)
		.set_position(250, 170)
		.set_center(0, 0);

	comLogo.draw();
	
	//
	//button sprite loading 
	menu.drawGameButton();
	menu.drawCreditButton();
	menu.drawSetButton();
}

void Menu::drawGameButton() const
{
	gameButton.load_sprite_image("assets/images/start.png")// <- path is needed from assets to load
		.set_sprite_frame_size(800, 500) //size of button in the png file (width and height needed)
		.set_scale(100, 50)
		.set_position(50, 80);

	gameButton.draw();

}

void Menu::drawSetButton() const
{
	setButton.load_sprite_image("assets/images/setting.png")// <- path is needed from assets to load
		.set_sprite_frame_size(800, 500) //size of button in the png file (width and height needed)
		.set_scale(100, 50)
		.set_position(525, 80);

	setButton.draw();

}

void Menu::drawCreditButton() const
{
	creditButton.load_sprite_image("assets/images/credit.png")// <- path is needed from assets to load
		.set_sprite_frame_size(800, 500) //size of button in the png file (width and height needed)
		.set_scale(100, 50)
		.set_position(650, 80);

	creditButton.draw();

}

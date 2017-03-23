#include "spritelib\spritelib.h"
#include "Buttons.h"
#include "Menu.h"
#include <iostream>

using namespace spritelib;
using namespace std;

Sprite comLogo, gameLogo, menuBackground, gameButton, creditButton, setButton;

//pointers needed for music 
Sound *audio = new Sound(); //pointer to audio class and will create a new Sound object
FMOD::Sound *menuMusic; //pointer to sound, is needed
FMOD::Channel *menuChan; // pointer to channel (not eveyrthing needs a channel and if thats the case just put 0 there)

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
		.set_scale(100, 50)
		.set_position(50, 80);

	gameButton.draw();

}

void Menu::drawSetButton() const
{
	setButton.load_sprite_image("assets/images/setting.png")// <- path is needed from assets to load
		.set_scale(100, 50)
		.set_position(525, 80);

	setButton.draw();

}

void Menu::drawCreditButton() const
{
	creditButton.load_sprite_image("assets/images/credit.png")// <- path is needed from assets to load
		.set_scale(100, 50)
		.set_position(650, 80);

	creditButton.draw();

}

void Menu::playmMusic()
{
	audio->createSound(&menuMusic, "assets/music/menu.ogg"); // first parameter is FMOD variable, second if the just the name of the file 
	audio->playSound(menuMusic, menuChan, false, false);
	menuChan->setVolume(0.05f); // 1 is default volume and everything else is multiples
}

void Menu::pausemMusic() //ERRORSSSSSS
{
	audio->playSound(menuMusic, menuChan, true, false);
}


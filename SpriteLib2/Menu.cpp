#include "spritelib\spritelib.h"
#include "Menu.h"
#include <iostream>
using namespace spritelib;

void Menu::drawMenu()
{
	Menu menu;
	Text::load_font("assets/times.ttf", "basic");

	// background + animation frames

	//button sprite loading 
	menu.drawGameButton();
}

void Menu::MouseFunc(Window::Button a_button, Window::EventType a_eventType)
{
	switch (a_button && a_eventType)
	{
	case Window::Button::LeftButton && Window::EventType::MouseButtonPressed && Window::EventType::MouseButtonReleased:
		{
			
		}
	}
}

void Menu::drawGameButton()
{
	Sprite gameButton;

	gameButton.load_sprite_image("assets/images/menu_button.png")// <- path is needed from assets to load
		.set_sprite_frame_size(435, 200); //size of button in the png file (width and height needed)

	gameButton.draw()
		.set_scale(200, 100)
		.set_position(100, 100);
}

void Menu::checkMenu()
{

}
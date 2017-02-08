#pragma once
#include "spritelib\spritelib.h"
#include <iostream>
using namespace spritelib;

class Menu
{
	public:
		void drawMenu();
		void checkMenu();
		void MouseFunc(Window::Button a_button, Window::EventType a_eventType);

	private:
		void drawGameButton();
		void drawPauseButton();
		void drawQuitButton();
		void drawSetButton();
		void drawInstructButton();
};
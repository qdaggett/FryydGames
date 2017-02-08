#pragma once
#include "spritelib\spritelib.h"
#include <iostream>
using namespace spritelib;

class Menu
{
	public:
		void drawMenu();
		void checkMenu();

	private:
		void drawGameButton();
		void drawPauseButton();
		void drawQuitButton();
		void drawSetButton();
		void drawInstructButton();
};
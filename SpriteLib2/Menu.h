#pragma once
#include "spritelib\spritelib.h"
#include <iostream>
using namespace spritelib;

class Menu
{
	public:
		void drawMenu();

	private:
		void drawGameButton() const;
		void drawPauseButton() const;
		void drawQuitButton() const;
		void drawCreditButton() const;
		void drawSetButton() const;
		void drawInstructButton() const;
};
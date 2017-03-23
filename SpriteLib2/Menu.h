#pragma once
#include "spritelib\spritelib.h"
#include <iostream>
#include "audio.h"
using namespace spritelib;

class Menu
{
	public:
		void drawMenu();
		void pausemMusic();
		void playmMusic();

	private:
		void drawGameButton() const;
		void drawQuitButton() const;
		void drawCreditButton() const;
		void drawSetButton() const;
		void drawInstructButton() const;
};
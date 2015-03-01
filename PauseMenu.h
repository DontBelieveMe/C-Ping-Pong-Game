#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include "FontManager.h"

namespace blesbok
{

	class PauseMenu
	{
	private:
		FontManager* f_manager;
		unsigned int window_width;
		unsigned int window_height;

		sf::Texture t_resume;
		sf::Sprite sprite_resume;

		sf::Texture t_abort;
		sf::Sprite sprite_abort;

		bool is_pressed(sf::Sprite sprite,
			sf::RenderWindow* display,
			int x_offset, int y_offset);

	public:
		PauseMenu(FontManager* f_mana,
			unsigned int ww,
			unsigned int wh);

		~PauseMenu();

		void draw(sf::RenderWindow* display);
		void tick();

		bool paused = false;
	};
};

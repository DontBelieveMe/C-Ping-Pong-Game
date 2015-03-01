#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include "FontManager.h"

namespace blesbok
{

	class MainMenu
	{
	private:
		FontManager* f_manager;
		unsigned int window_width;
		unsigned int window_height;

		sf::Texture play_button_text;
		sf::Sprite play_button_sprite;

		sf::Texture exit_text;
		sf::Sprite exit_sprite;

		bool is_pressed(sf::Sprite sprite,
						sf::RenderWindow* display, 
						int x_offset, int y_offset);

	public:
		MainMenu(FontManager* f_mana,
				 unsigned int ww,
				 unsigned int wh);

		~MainMenu();

		void draw(sf::RenderWindow* display);
		void tick();

		bool game_running = false;
	};
};	


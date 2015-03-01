
#pragma once
#include<iostream>
#include<stdexcept>
#include<SFML\Graphics.hpp>

namespace blesbok
{

	class FontManager
	{
	private:
		sf::Font courier_new;
		int font_size = 24;
		sf::Color text_colour = sf::Color::White;
		int tStyle = sf::Text::Bold;

	public:
		FontManager();
		~FontManager();

		void draw_text_s(const std::string& text, 
						 sf::RenderWindow* rendererable, 
						 int x, int y);

		void set_font_colour(sf::Color colour) 
		{ text_colour = colour; }

		void set_font_size(int w, int h) 
		{ tdraw.setScale((float)w, (float)h); }
		
		sf::Text tdraw;
	};
}


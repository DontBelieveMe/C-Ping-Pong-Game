#include "FontManager.h"

/*
Loads in the font and sets some inital attributes
*/
blesbok::FontManager::FontManager()
{
	if (!courier_new.loadFromFile("courier_new.ttf"))
	{
		std::cerr << "Error loading font!" << std::endl;
		throw std::runtime_error("Error loading font");
	}

	tdraw.setFont(courier_new);
	tdraw.setCharacterSize(font_size);
	tdraw.setColor(text_colour);
	tdraw.setStyle(tStyle);
}


/*
Draws the Text
*/
void blesbok::FontManager::draw_text_s(const std::string& text, sf::RenderWindow* renderable, int x, int y)
{
	tdraw.setColor(text_colour);
	tdraw.setPosition(x, y);
	tdraw.setString(text);
	renderable->draw(tdraw);
}

blesbok::FontManager::~FontManager()
{
}


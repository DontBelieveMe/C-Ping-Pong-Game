#include "MainMenu.h"

/*
Loads all the textures and sets them to the appropriate sprite
*/
blesbok::MainMenu::MainMenu(FontManager* f_mana, unsigned int ww, unsigned wh)
{
	f_manager = f_mana;

	play_button_text.loadFromFile("play_button_sprite.png");
	play_button_text.setSmooth(true);

	play_button_sprite.setTexture(play_button_text);
	play_button_sprite.setPosition(ww / 2 - play_button_text.getSize().x / 2, wh / 2 - play_button_text.getSize().y / 2);

	exit_text.loadFromFile("exit_button_sprite.png");
	exit_text.setSmooth(true);

	exit_sprite.setTexture(exit_text);
	exit_sprite.setPosition(ww / 2 - exit_text.getSize().x / 2, wh / 2 - exit_text.getSize().y / 2 + 100);

}

blesbok::MainMenu::~MainMenu()
{
}

/*
Renders the sprites
*/
void blesbok::MainMenu::draw(sf::RenderWindow* display)
{
	if (is_pressed(play_button_sprite, display, 100, 75)) game_running = true;
	if (is_pressed(exit_sprite, display, -75, 25)) display->close();


	display->draw(exit_sprite);
	display->draw(play_button_sprite);
}

/*
Checks if the a Sprite has been pressed -> For buttons
*/
bool blesbok::MainMenu::is_pressed(sf::Sprite sprite, sf::RenderWindow* display,
								   int x_offset = 0, int y_offset = 0)
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(*display);

	if (mouse_position.x + sprite.getTexture()->getSize().x + x_offset > sprite.getPosition().x)
	{
		if (mouse_position.x < sprite.getPosition().x + sprite.getTexture()->getSize().x)
		{
			if (mouse_position.y + sprite.getTexture()->getSize().y - y_offset > sprite.getPosition().y)
			{
				if (mouse_position.y < sprite.getPosition().y + sprite.getTexture()->getSize().y)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						return true;
					}
				}
			}

		}
	}
	return false;
}

/*
Un-used
*/
void blesbok::MainMenu::tick()
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) game_running = true;
}

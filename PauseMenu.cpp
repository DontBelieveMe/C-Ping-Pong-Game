#include "PauseMenu.h"

/*
Load in pause menu resources
*/
blesbok::PauseMenu::PauseMenu(FontManager* f_mana, unsigned int ww, unsigned int wh)
{
	t_resume.loadFromFile("resume_button_sprite.png");
	sprite_resume.setTexture(t_resume);
	sprite_resume.setPosition((float)ww / 2 - (t_resume.getSize().x / 2), (float)wh / 2 - (t_resume.getSize().y / 2));

	t_abort.loadFromFile("abort_button_sprite.png");
	sprite_abort.setTexture(t_abort);
	sprite_abort.setPosition((float)ww / 2 - (t_resume.getSize().x / 2) + 10, (float) wh / 2 - (t_resume.getSize().y / 2) + 75);
}


blesbok::PauseMenu::~PauseMenu()
{
}

/*
Poll Inputs -> Use Enter to return to games
*/
void blesbok::PauseMenu::tick()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) paused = false;
}

/*
Check Pause Menu Buttons
Draw the buttons
*/
void blesbok::PauseMenu::draw(sf::RenderWindow* display)
{
	if (is_pressed(sprite_resume, display, -100, 0)) paused = false;
	if (is_pressed(sprite_abort, display, 0, 20)) display->close();

	display->draw(sprite_abort);
	display->draw(sprite_resume);
}

/*
Check Button Collisions
*/
bool blesbok::PauseMenu::is_pressed(sf::Sprite sprite, sf::RenderWindow* display,
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

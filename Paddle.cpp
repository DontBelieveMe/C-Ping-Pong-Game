#include "Paddle.h"
#include<iostream>

/*
Sets the paddles inital attributes
*/
blesbok::Paddle::Paddle(const float _w, const float _h, float i_x,
			   float i_y, bool is_ai) : width(_w), height(_h)
{
	std::cout << "Creating Paddle" << std::endl;

	Paddle::x = i_x;
	Paddle::y = i_y;
	Paddle::is_ai = is_ai;

	sprite.setFillColor(sf::Color::White);
	sprite.setSize(sf::Vector2f(width, height));
	sprite.setPosition(sf::Vector2f(x, y));
}
blesbok::Paddle::~Paddle() {}

/*
Draws the sprite
*/
void blesbok::Paddle::draw(sf::RenderWindow* display)
{
	display->draw(sprite);
}

/*
Handles Keyboard input for the player paddle as well as
wall collisions for both paddles
*/
void blesbok::Paddle::tick(int window_width, int window_height)
{
	if (!is_ai)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			vel_x = -player_speed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			vel_x = player_speed;
		}
		else
		{
			vel_x = 0.0f;
		}
	} 

	float p_loc_x = x + vel_x;
	if (p_loc_x < 0) vel_x = 0.0f;
	if (p_loc_x + width > window_width) vel_x = 0.0f;

	x += vel_x;
	sprite.setPosition(sf::Vector2f(x, y));
}

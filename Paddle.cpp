#include "Paddle.h"
#include<iostream>

blesbok::Paddle::Paddle(const float _w, const float _h, float i_x,
			   float i_y) : width(_w), height(_h)
{
	std::cout << "Creating Paddle" << std::endl;

	Paddle::x = i_x;
	Paddle::y = i_y;

	sprite.setFillColor(sf::Color::White);
	sprite.setSize(sf::Vector2f(width, height));
	sprite.setPosition(sf::Vector2f(x, y));
}
blesbok::Paddle::~Paddle() {}

void blesbok::Paddle::draw(sf::RenderWindow* display)
{
	display->draw(sprite);
}

void blesbok::Paddle::tick(int window_width, int window_height)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	{
		vel_x = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		vel_x = speed;
	}
	else
	{
		vel_x = 0.0f;
	}

	float p_loc_x = x + vel_x;
	if (p_loc_x < 0) vel_x = 0.0f;
	if (p_loc_x + width > window_width) vel_x = 0.0f;

	x += vel_x;
	sprite.setPosition(sf::Vector2f(x, y));
}

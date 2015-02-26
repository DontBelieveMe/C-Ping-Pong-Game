#include "Ball.h"

blesbok::Ball::Ball(float radius, float i_x, float i_y, AudioManager& s_manager) : radius(radius), s_manager(s_manager)
{
	Ball::x = i_x;
	Ball::y = i_y;

	sprite.setRadius(radius);
	sprite.setPosition(sf::Vector2f(x, y));
}

blesbok::Ball::~Ball()
{
}

void blesbok::Ball::draw(sf::RenderWindow* display)
{
	display->draw(sprite);
}

void blesbok::Ball::tick(int window_width, int window_height, Paddle& player, Paddle& _cpu)
{
	float p_loc_x = x + vel_x;
	float p_loc_y = y + vel_y;

	if (p_loc_x < 0)
	{
		s_manager.play_hit_wall();
		vel_x = -vel_x;
	}
	if (p_loc_x + (radius * 2) > window_width)
	{
		s_manager.play_hit_wall();
		vel_x = -vel_x; 
	}
	if (p_loc_y < 0)
	{
		s_manager.play_hit_wall();
		vel_y = -vel_y; 
	}
	if (p_loc_y + (radius * 2) > window_height)
	{
		s_manager.play_hit_wall();
		vel_y = -vel_y; 
	}
	
	if (has_collided(player) || has_collided(_cpu))
	{
		s_manager.play_hit_player();
		vel_y = -vel_y;
	}

	x += vel_x;
	y += vel_y;

	sprite.setPosition(sf::Vector2f(x, y));
}

bool blesbok::Ball::has_collided(Paddle& entity)
{
	bool collided = false;

	if (sprite.getPosition().y + (radius * 2) > entity.sprite.getPosition().y)
	{
		if(sprite.getPosition().y < entity.sprite.getPosition().y + entity.get_height())
		{
			if (sprite.getPosition().x + (radius * 2) > entity.sprite.getPosition().x)
			{
				if (sprite.getPosition().x < entity.sprite.getPosition().x + entity.get_width())
				{
					collided = true;
				}
			}

		}
	}

	return collided;
}
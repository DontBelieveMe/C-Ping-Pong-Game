#include "Ball.h"

/*
Sets Inital Size (Radius) and Position of the ball
*/
blesbok::Ball::Ball(float radius, float i_x, float i_y, AudioManager& s_manager) : radius(radius), s_manager(s_manager)
{
	Ball::x = i_x;
	Ball::y = i_y;
	Ball::inital_x = i_x;
	Ball::initial_y = i_y;

	sprite.setRadius(radius);
	sprite.setPosition(sf::Vector2f(x, y));
}

blesbok::Ball::~Ball() { }

/*
Renders the Sprite
*/
void blesbok::Ball::draw(sf::RenderWindow* display)
{
	display->draw(sprite);
}

/*
Sets the Balls position back to its original
*/
void blesbok::Ball::reset()
{
	sprite.setPosition(sf::Vector2f(inital_x, initial_y));
}

/*
Checks for:
	Wall collisions,
	Bat collisions
Also handles enemy AI
and Ball movment/tragectories
*/
void blesbok::Ball::tick(int window_width, int window_height, Paddle& player,
						Paddle& _cpu, int& p_one_s, int& p_two_s)
{
	float p_loc_x = x + (vel_x + 5);
	float p_loc_y = y + (vel_y + 5);

	//Wall collisions for the ball 
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
		s_manager.play_gain_point();
		vel_y = -vel_y;
		p_one_s++;

	}
	if (p_loc_y + (radius * 2) > window_height)
	{
		s_manager.play_gain_point();
		vel_y = -vel_y;
		p_two_s++;
	}
	
	if (has_collided(player))
	{
		if (vel_y > 0)
		{
			vel_y = min_vel + (float)(rand() % (max_vel - min_vel + 1));
	
			s_manager.play_hit_player();
			vel_y = -vel_y;
		}
		vel_x = min_vel + (float)(rand() % (max_vel - min_vel + 1));

	}

	if (has_collided(_cpu))
	{
		if (vel_y < 0)
		{
			vel_y =  -(min_vel + (rand() % (max_vel - min_vel + 1)));
			

			s_manager.play_hit_player();
			vel_y = -vel_y;
		}
		vel_x = -(min_vel + (rand() % (max_vel - min_vel + 1)));
	}

	if (sprite.getPosition().y < window_height / 2)
	{
		if (sprite.getPosition().x + radius > _cpu.sprite.getPosition().x + (_cpu.get_width() / 2))
		{
			_cpu.vel_x = 4.0f;
		}
		if (sprite.getPosition().x + radius < _cpu.sprite.getPosition().x + (_cpu.get_width() / 2))
		{
			_cpu.vel_x = -4.0f;
		}
	}

	x += vel_x;
	y += vel_y;
	sprite.setPosition(sf::Vector2f(x, y));
}

/*
Checks for collisions with a paddle, player or AI
*/
bool blesbok::Ball::has_collided(Paddle& entity)
{
	bool collided = false;

	if (sprite.getPosition().y + (radius * 2) > entity.sprite.getPosition().y)
	{
		if(sprite.getPosition().y < entity.sprite.getPosition().y + entity.get_height())
		{
			if (sprite.getPosition().x + (radius * 2) + 5 > entity.sprite.getPosition().x)
			{
				if (sprite.getPosition().x < entity.sprite.getPosition().x + entity.get_width() + 5)
				{
					collided = true;
				}
			}

		}
	}

	return collided;
}
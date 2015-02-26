#pragma once
#include<SFML\Graphics.hpp>

#include "Paddle.h"
#include "AudioManager.h"

namespace blesbok
{
	class Ball
	{
	private:
		const float radius;
		float x, y;
		const float avg_speed = 2.0f;
		float vel_x = avg_speed, vel_y = avg_speed;

		sf::CircleShape sprite;
		AudioManager& s_manager;

		bool has_collided(Paddle& entity);
	public:
		Ball(float radius, float i_x, float i_y, AudioManager& s_manager);
		~Ball();

		void tick(int window_width, int window_height, Paddle& player, 
				  Paddle& _cpu);
		void draw(sf::RenderWindow* display);
	};
};


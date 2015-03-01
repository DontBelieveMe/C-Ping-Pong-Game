
#include<SFML\Graphics.hpp>

#include "AudioManager.h"
#include "Paddle.h"
#include<random>

namespace blesbok
{
	class Ball
	{
	private:
		const float radius;
		float x, y;
		const float avg_speed = 5.0f;
		float vel_x = -avg_speed, vel_y = 3.0f;

		sf::CircleShape sprite;
		AudioManager& s_manager;

		int min_vel = 3;
		int max_vel = 5;

		float inital_x, initial_y;

		bool has_collided(Paddle& entity);
	public:
		Ball(float radius, float i_x, float i_y, AudioManager& s_manager);
		~Ball();

		void tick(int window_width, int window_height, Paddle& player, 
				  Paddle& _cpu, int& p_one_s, int& p_two_s);
		void draw(sf::RenderWindow* display);
		void reset();
	};
};

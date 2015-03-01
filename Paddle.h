#ifndef FILE_H
#define FILE_H

#include<SFML\Graphics.hpp>

namespace blesbok
{
	class Paddle
	{
	private:
		const float width;
		const float height;

		const float player_speed = 5.0f;
		const float ai_speed = 5.0f;

		bool is_ai = false;

	public:
		Paddle(const float _w, const float _h, float i_x,
			float i_y, bool is_ai);
		~Paddle();

		sf::RectangleShape sprite;
		void tick(int window_width, int window_height);
		void draw(sf::RenderWindow* display);
		void reset();

		float get_width() const { return width; }
		float get_height() const { return height; }
		float get_ai_speed() const { return ai_speed; }

		float x, y;
		float vel_x = 0.0f;

		float get_x() { return x; }
		float get_y() { return y; }
	};
};

#endif
#pragma once
#include<SFML\Graphics.hpp>

namespace blesbok
{
	class Paddle
	{
	private:
		const float width;
		const float height;

		float x, y;
		float vel_x = 0.0f;
		const float speed = 5.0f;
	public:
		Paddle(const float _w, const float _h, float i_x,
			float i_y);
		~Paddle();

		sf::RectangleShape sprite;
		void tick(int window_width, int window_height);
		void draw(sf::RenderWindow* display);

		float get_width() const { return width; }
		float get_height() const { return height; }

		float get_x() { return x; }
		float get_y() { return y; }
	};
};
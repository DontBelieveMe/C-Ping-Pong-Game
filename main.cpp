/*
TODO:
	- Add Sound Effects
	-Add AI
*/

#include "System.h"
#include "Paddle.h"
#include "Ball.h"
#include "AudioManager.h"

#define WIDTH 500
#define HEIGHT 600

int main()
{
	using namespace blesbok;
	System system(WIDTH, HEIGHT, "Pong Port");
	AudioManager s_manager;

	Paddle& r_player = Paddle(125, 25, WIDTH / 2 - (125 / 2), (HEIGHT - 25) - 20);
	Paddle& r_cpu = Paddle(125, 25, WIDTH / 2 - (125 / 2) , 20);

	
	Ball& r_ball = Ball(15, 10, 10, s_manager);

	while (system.get_instance()->isOpen())
	{
		sf::Event event;
		while (system.get_instance()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) system.get_instance()->close();
		}
		system.clearToBlack();

		r_player.tick(WIDTH, HEIGHT);
		r_cpu.tick(WIDTH, HEIGHT);

		r_ball.tick(WIDTH, HEIGHT, r_player, r_cpu);

		r_player.draw(system.get_instance());
		r_cpu.draw(system.get_instance());
		r_ball.draw(system.get_instance());

		system.flip();
	}

	return 0;

}


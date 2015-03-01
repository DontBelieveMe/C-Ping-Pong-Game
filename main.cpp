/*
TODO:
	- Create Git Stuff
		- Repo
		- Push to git
		- etc...
*/

#include "System.h"
#include "MainMenu.h"
#include "PauseMenu.h"

#include "AudioManager.h"
#include "FontManager.h"
#include "ScoreManager.h"

#include "Paddle.h"
#include "Ball.h"

#define WIDTH 500
#define HEIGHT 600
#define WIN_SCORE 5
using namespace blesbok;

int main()
{
	srand(time_t(NULL));

	System system(WIDTH, HEIGHT, "Pong Clone");
	AudioManager s_manager;
	FontManager f_manager;
	ScoreManager hs_manager;

	Paddle& r_player = Paddle(125, 25, WIDTH / 2 - (125 / 2), (HEIGHT - 25) - 20, false);
	Paddle& r_cpu = Paddle(125, 25, WIDTH / 2 - (125 / 2), 20, true);
	Ball& r_ball = Ball(15, 10, 10, s_manager);

	MainMenu main_menu(&f_manager, WIDTH, HEIGHT);
	PauseMenu pause_menu(&f_manager, WIDTH, HEIGHT);

	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(0, HEIGHT / 2)),
		sf::Vertex(sf::Vector2f(WIDTH, HEIGHT / 2))
	};
	sf::CircleShape middle_circle(50);
	middle_circle.setOutlineThickness(2);
	middle_circle.setPosition(WIDTH / 2 - 50, HEIGHT / 2 - 50);
	middle_circle.setFillColor(sf::Color::Black);
	middle_circle.setOutlineColor(sf::Color::White);

	int p_s =  0;
	int ai_s = 0;
	int& ai_score = ai_s;
	int& player_score = p_s;

	while (system.get_instance()->isOpen())
	{
		sf::Event event;
		while (system.get_instance()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) system.get_instance()->close();
		}
		system.clearToBlack();

		if (!main_menu.game_running)
		{
			main_menu.tick();
			main_menu.draw(system.get_instance());
		}
		if (main_menu.game_running)
		{
			if (pause_menu.paused)
			{
				pause_menu.draw(system.get_instance());
				pause_menu.tick();
			}
			if (!pause_menu.paused)
			{
				if (p_s < WIN_SCORE && ai_s < WIN_SCORE)
				{
					r_ball.tick(WIDTH, HEIGHT, r_player, r_cpu, player_score, ai_score);
					r_player.tick(WIDTH, HEIGHT);
					r_cpu.tick(WIDTH, HEIGHT);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) pause_menu.paused = true;

					f_manager.draw_text_s("You: " + std::to_string(p_s), system.get_instance(), 0, HEIGHT - 27);
					f_manager.draw_text_s("CPU: " + std::to_string(ai_s), system.get_instance(), 0, 0);

					r_player.draw(system.get_instance());
					r_cpu.draw(system.get_instance());
					r_ball.draw(system.get_instance());

					system.get_instance()->draw(middle_circle);
					system.get_instance()->draw(line, 2, sf::Lines);
				}
				else
				{
					f_manager.draw_text_s("END GAME", system.get_instance(), WIDTH / 2 - 50, HEIGHT / 2 - 24);

					if (ai_score == WIN_SCORE)
					{
						f_manager.set_font_colour(sf::Color::Red);
						f_manager.draw_text_s("CPU Wins!", system.get_instance(), WIDTH / 2 - 50, HEIGHT / 2 + 25);
					}
					else
					{
						f_manager.set_font_colour(sf::Color::Yellow);
						f_manager.draw_text_s("You Win!", system.get_instance(), WIDTH / 2 - 50, HEIGHT / 2 + 25);
					}

					f_manager.draw_text_s("Esc To Quit", system.get_instance(), WIDTH / 2 - 75, HEIGHT / 2 + 200);
					f_manager.draw_text_s("Enter To Play Again", system.get_instance(), WIDTH / 2 - 140, HEIGHT / 2 + 225);


					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) system.get_instance()->close();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
					{
						hs_manager.append(std::to_string(player_score));
						p_s = 0;
						ai_s = 0;

						r_ball.reset();
						f_manager.set_font_colour(sf::Color::White);
					}
				}
			}
		}
		
		system.flip();
	}

	return 0;
}
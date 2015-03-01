#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include<iostream>
#include<stdexcept>

namespace blesbok
{
	class System
	{
	private:
		const unsigned int width;
		const unsigned int height;
		const std::string& title;

		const unsigned int FPSCAP = 120;

		sf::RenderWindow* display;
	public:
		System(const unsigned int width, const unsigned int height, 
			   const std::string& title);
		~System();

		void quit();
		void tick();

		void clearToBlack() { display->clear();  }
		void flip();

		unsigned int get_width() const {
			return width;
		}

		unsigned int get_height() const {
			return height;
		}

		const std::string& get_title() const {
			return title;
		}

		sf::RenderWindow* get_instance() const {
			return display;
		}
	};
}
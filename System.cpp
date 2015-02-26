#include "System.h"

blesbok::System::System(const unsigned int width, const unsigned int height, 
						const std::string& title)
						: width(width), height(height), title(title)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	display = new sf::RenderWindow;
	display->create(sf::VideoMode(width, height), title, 
				    sf::Style::Close | sf::Style::Titlebar, settings);
	display->setFramerateLimit(FPSCAP);
}

blesbok::System::~System()
{
	if (this->display != NULL) display->close();
	delete display;
}

void blesbok::System::quit()
{
	this->~System();
}

void blesbok::System::tick()
{
}

void blesbok::System::flip()
{
	display->display();
}
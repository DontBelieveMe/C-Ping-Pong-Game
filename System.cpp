#include "System.h"

/*
Creates the Window
*/
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
/*
Destroys the window
*/
blesbok::System::~System()
{
	std::cout << "Destructing System" << std::endl;
	if (this->display != NULL) display->close();
	delete display;
}


/*
Swaps the window buffers
*/
void blesbok::System::flip()
{
	display->display();
}


/*
Quits the window -> Invokes the destructor
*/
void blesbok::System::quit()
{
	this->~System();
}

/*
Un-used
*/
void blesbok::System::tick()
{
}
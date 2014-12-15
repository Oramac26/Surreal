#include <SFML/Graphics.hpp>
#include <iostream>
#include "screens.hpp"

int main(int argc, char** argv)
{
    sf::RenderWindow win( sf::VideoMode( 1280, 720, 32 ), "Surreal" );
	std::vector<cScreen*> Screens;

	int screen = 0;
	MenuScr Menu;
	Screens.push_back(&Menu);
	GameScr Game;
	Screens.push_back(&Game);

		while (screen >= 0)
			{
		    screen = Screens[screen]->Run(win);
			}

	return EXIT_SUCCESS;
}
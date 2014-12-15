#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class GameScr:public cScreen{

public:
	virtual int Run(sf::RenderWindow &win);

	bool CorrectM(sf::Sprite &s, const sf::RenderWindow &w)
	{
	if (
	sf::Mouse::getPosition(w).x > s.getGlobalBounds().left &&
	sf::Mouse::getPosition(w).y > s.getGlobalBounds().top &&
	sf::Mouse::getPosition(w).x < s.getGlobalBounds().left + s.getGlobalBounds().width &&
	sf::Mouse::getPosition(w).y < s.getGlobalBounds().top + s.getGlobalBounds().height
	)
	return 1;
	else
	return 0;
	}
};
int GameScr::Run(sf::RenderWindow &win){
 
	bool Running=true;

    sf::Texture obr1;
    obr1.loadFromFile( "gametest.png" );

    sf::Sprite bg;
    bg.setTexture( obr1 );	

	sf::Event zdarzenie;
	while (Running){

        while( win.pollEvent( zdarzenie ) )
        {
			if( zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::Escape ) return (0);
		}
		
	win.draw(bg);
	win.display();
	}

	return (-1);
}
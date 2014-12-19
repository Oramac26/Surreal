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

    sf::Texture obr1,obr2,obr3,obr4;
    obr1.loadFromFile( "gametest.png" );
	obr2.loadFromFile( "Inventoryclc.png" );
	obr3.loadFromFile( "Goclc.png" );
	obr4.loadFromFile( "Hideoutclc.png" );

    sf::Sprite bg,inv,go,hide;
    bg.setTexture( obr1 );	
	inv.setTexture( obr2 );
	go.setTexture( obr3 );
	hide.setTexture( obr4 );

	inv.setPosition(781,627);
	go.setPosition(505,574);
	hide.setPosition(199,626);

	sf::Event zdarzenie;
	while (Running){

        while( win.pollEvent( zdarzenie ) )
        {
			if( zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::Escape ) return (0);
		}
win.draw(bg);

	if (CorrectM(inv, win)) {
				win.draw( inv );
			}
	if (CorrectM(go, win)) {
				win.draw( go );
			}
	if (CorrectM(hide, win)) {
				win.draw( hide );
			}
	

	win.display();
	}

	return (-1);
}
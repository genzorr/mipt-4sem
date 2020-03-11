#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "charge.h"

using namespace std;

#define X 1440
#define Y 900

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;

	sf::RenderWindow window(sf::VideoMode(X, Y), "SFML", sf::Style::Close | sf::Style::Resize, settings);
//	window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);
	window.clear();
	window.clear(sf::Color::White);

	sf::Clock clock;
	sf::Time time = clock.restart();
	sf::Event event;

	vector<Charge> charges;

	int left = 0, right = 0;

    while (window.isOpen())
    {
    	while (window.pollEvent(event))
    	{
    		if (event.type == sf::Event::Closed)
					window.close();

//			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//				left = 1;
////				CreateUpdateFields(window, charges, 1);
//			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
//				right = 1;
////				CreateUpdateFields(window, charges, -1);
    	}

    	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and (time.asMilliseconds() > 500))
    	{
    		CreateUpdateFields(window, charges, 1);
    		clock.restart();
    	}

    	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) and (time.asMilliseconds() > 500))
    	{
    		CreateUpdateFields(window, charges, -1);
    		clock.restart();
    	}

    	window.display();
    	time = clock.getElapsedTime();
    }

    return 0;
}

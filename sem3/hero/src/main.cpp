#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "hero.h"
#include "charge.h"

using namespace std;

class Hero;

//void moveShape(sf::Sprite& sprite, float speed, float dt = 1.0f);

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;

	sf::RenderWindow window(sf::VideoMode(X, Y), "SFML", sf::Style::Close | sf::Style::Resize, settings);
    window.setFramerateLimit(60);
	window.clear();

	sf::Event event;
	sf::Clock clock;
	sf::Clock clock_charge;
	sf::Time time = clock.restart();
	sf::Time time_charge = clock_charge.restart();

	sf::Texture texture;
	texture.loadFromFile("Black-Smiley-18-256.png");
	Hero hero(texture, sf::Vector2f(100, 100));

	vector<Charge> charges;

    while (window.isOpen())
    {
    	clock.restart();
    	window.clear(sf::Color(50, 50, 50));

    	while (window.pollEvent(event))
    	{
    		switch (event.type)
    		{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
    		}
    	}

    	float dt = ((float)time.asMicroseconds())/1000000;

    	hero.rotateHero(window);
    	hero.moveHero(500.0, dt);

    	hero.shootLaser(window);

    	time_charge = clock_charge.getElapsedTime();
    	if (time_charge.asMilliseconds() > 100)
    	{
    		hero.shootParticle(window, charges);
    		clock_charge.restart();
    	}
    	for (auto& charge: charges)
    	{
    		charge.updatePosition(dt);
    		window.draw(charge.charge);
    	}

    	window.draw(hero.sprite);

    	window.display();
    	time = clock.getElapsedTime();
    }

    return 0;
}

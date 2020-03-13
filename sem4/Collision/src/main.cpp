#include <iostream>
#include <SFML/Graphics.hpp>
#include "global.h"
#include "particle.h"

using namespace std;

int main()
{
    srand(unsigned(std::time(0)));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;

    sf::RenderWindow window(sf::VideoMode(X, Y), "SFML", sf::Style::Close | sf::Style::Resize, settings);
    window.setFramerateLimit(60);
    window.clear(sf::Color::White);

    sf::Clock clock_mouse;
    sf::Time time_mouse = clock_mouse.restart();
    sf::Clock clock;
    sf::Time time = clock.restart();
    sf::Event event;

    vector<Ball> balls;

    while (window.isOpen())
    {
        window.clear(sf::Color::White);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and (time_mouse.asMilliseconds() > 200))
        {
            AddBall(window, balls);
            clock_mouse.restart();
        }

        float dt = time.asMicroseconds()/1000000.0f;
        UpdateBalls(window, balls, dt);

        window.display();
        time = clock.getElapsedTime();
        clock.restart();
        time_mouse = clock_mouse.getElapsedTime();
    }

    return 0;
}

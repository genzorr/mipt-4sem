#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <cmath>


float angle = 45*M_PI/180;


void DragonCurve(sf::RenderWindow& window, int depth, float x0, float y0, float x1, float y1, int k)
{
	if (depth == 0)
	{
		sf::Vertex line[] = {
			sf::Vertex(sf::Vector2f(x0, y0), sf::Color::Red),
			sf::Vertex(sf::Vector2f(x1, y1), sf::Color::Red)
		};
		window.draw(line, 2, sf::Lines);
		window.display();
	}
	else
	{
		float angle_new = angle*k;
		float acf = cosf(angle_new);
		float asf = sinf(angle_new);
		float xn = acf * ((x1-x0)*acf - (y1-y0)*asf) + x0;
		float yn = acf * ((x1-x0)*asf + (y1-y0)*acf) + y0;

		DragonCurve(window, depth-1, x0, y0, xn, yn, 1);
		DragonCurve(window, depth-1, xn, yn, x1, y1, -1);
	}
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");
    window.setFramerateLimit(30);
	window.clear();

	float xs = 700;
	DragonCurve(window, 14, xs, 540, 1920-xs, 540, 1);

    while (window.isOpen())
    {
//    	window.clear();

    	sf::Event event;
    	while (window.pollEvent(event))
    	{
    		if (event.type == sf::Event::Closed)
    			window.close();
    	}

//        window.display();
    }

    return 0;
}

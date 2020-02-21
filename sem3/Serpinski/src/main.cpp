#include <SFML/Graphics.hpp>
#include <unistd.h>


sf::Vector2f getMiddle(const sf::Vertex& a, const sf::Vertex& b)
{
	return sf::Vector2f((a.position.x + b.position.x)/2, (a.position.y + b.position.y)/2);
}


void PlotSerpinskiTriangle(sf::RenderWindow& window, const sf::Vertex tri[], int depth)
{
	if (depth == 0)
		return;

	sf::Vertex tri0[] = {
		sf::Vertex(tri[0].position, sf::Color::Red),
		sf::Vertex(getMiddle(tri[0], tri[1]), sf::Color::Red),
		sf::Vertex(getMiddle(tri[0], tri[2]), sf::Color::Red),
		sf::Vertex(tri[0].position, sf::Color::Red)

	};

	sf::Vertex tri1[] = {
		sf::Vertex(tri[1].position, sf::Color::Red),
		sf::Vertex(getMiddle(tri[0], tri[1]), sf::Color::Red),
		sf::Vertex(getMiddle(tri[1], tri[2]), sf::Color::Red),
		sf::Vertex(tri[1].position, sf::Color::Red)

	};

	sf::Vertex tri2[] = {
		sf::Vertex(tri[2].position, sf::Color::Red),
		sf::Vertex(getMiddle(tri[2], tri[1]), sf::Color::Red),
		sf::Vertex(getMiddle(tri[0], tri[2]), sf::Color::Red),
		sf::Vertex(tri[2].position, sf::Color::Red)
	};

	window.draw(tri0, 4, sf::LineStrip);
	window.display();
	window.draw(tri1, 4, sf::LineStrip);
	window.display();
	window.draw(tri2, 4, sf::LineStrip);
	window.display();

	usleep(1000);

	depth--;
	PlotSerpinskiTriangle(window, tri0, depth);
	depth++;
	depth--;
	PlotSerpinskiTriangle(window, tri1, depth);
	depth++;
	depth--;
	PlotSerpinskiTriangle(window, tri2, depth);
	depth++;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    window.setFramerateLimit(30);

	window.clear();
    sf::Vertex triangle[] = {
		sf::Vertex(sf::Vector2f(200, 400), sf::Color::Red),
		sf::Vertex(sf::Vector2f(400, 100), sf::Color::Red),
		sf::Vertex(sf::Vector2f(600, 400), sf::Color::Red),
		sf::Vertex(sf::Vector2f(200, 400), sf::Color::Red)

	};
	window.draw(triangle, 4, sf::LineStrip);
	PlotSerpinskiTriangle(window, triangle, 6);

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

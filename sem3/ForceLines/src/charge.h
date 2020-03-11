#ifndef CHARGE_H_
#define CHARGE_H_

#define VELO 500
#define offset 10
#define DEF_SIZE 2000

#include "vector2.h"

class Charge
{
public:
	int lines_number;
	int sign;

	sf::Color color;
	sf::CircleShape charge;
	std::vector<Vector2> vectors;
	std::vector<sf::VertexArray> lines_vertex;

	Charge();
	Charge(sf::Vector2i position, sf::Color color, int sign_);

	void ReplotForceLines(sf::RenderWindow& window);
	void CountField(sf::RenderWindow& window, std::vector<Charge>& charges);
};

void Plot(sf::RenderWindow& window, std::vector<Charge>& charges);
void CreateUpdateFields(sf::RenderWindow& window, std::vector<Charge>& charges, int sign);

#endif /* CHARGE_H_ */

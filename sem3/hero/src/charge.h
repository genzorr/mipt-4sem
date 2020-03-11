#ifndef CHARGE_H_
#define CHARGE_H_

#define VELO 500

class Charge
{
public:
	sf::CircleShape charge;
	sf::Vector2f direction;

	Charge();
	Charge(float r, sf::Vector2f, sf::Vector2f position);

	void updatePosition(float dt);
};



#endif /* CHARGE_H_ */

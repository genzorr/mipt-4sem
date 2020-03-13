#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "global.h"
#include "vector2.h"
#include "particle.h"

class MaterialPoint
{
public:
    MaterialPoint(Vector2 position);
    virtual ~MaterialPoint() {};
    virtual void UpdatePosition(float dt);

    Vector2 GetImpulse() const;

    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
};

class Ball : public MaterialPoint
{
public:
    Ball(Vector2 position);
    void UpdatePosition(float dt);
    void place();

    float radius;
    int type;
    float mass;

    sf::Color color;
    sf::CircleShape particle;
};

void AddBall(sf::RenderWindow& window, vector<Ball>& balls);
void UpdateBalls(sf::RenderWindow& window, vector<Ball>& balls, float dt);
void ResolveCollision(Ball& ball1, Ball& ball2);
void ResolveCollisions(vector<Ball>& balls, float dt);

#endif /* PARTICLE_H_ */

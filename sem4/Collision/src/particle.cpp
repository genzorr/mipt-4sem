#include "particle.h"

int RADIUS = 50;
float VELO_MAX = 10.0f;
float ACCEL_MAX = 100.0f;


MaterialPoint::MaterialPoint(Vector2 position_)
{
    float rval1 = (float)rand() / RAND_MAX - 0.5;
    float rval2 = (float)rand() / RAND_MAX - 0.5;
    float rval3 = (float)rand() / RAND_MAX - 0.5;
    float rval4 = (float)rand() / RAND_MAX - 0.5;
    float rval5 = (float)rand() / RAND_MAX + 0.5;

    position = position_;
    velocity = Vector2(rval1 * VELO_MAX, rval2 * VELO_MAX);
//    acceleration = Vector2(rval3 * ACCEL_MAX, rval4 * ACCEL_MAX);
    acceleration = Vector2(0, ACCEL_MAX);
}

void MaterialPoint::UpdatePosition(float dt)
{
    position += velocity * dt + (acceleration / 2) * dt * dt;
    velocity += acceleration * dt;
}

Ball::Ball(Vector2 position) : MaterialPoint(position)
{
    type = 0;
    color = sf::Color(rand()%256, rand()%256, rand()%256);

    int rad = rand() % RADIUS;
    radius = (float)(rad + 30);
    mass = radius * radius;

    particle = sf::CircleShape(radius);
    particle.setPosition(sf::Vector2f(position.x, position.y));
    particle.setFillColor(color);
    particle.setOutlineColor(sf::Color::Black);
    particle.setOutlineThickness(2);
    particle.setOrigin(radius, radius);
}

void Ball::place()
{
    particle.setPosition(position.x, position.y);
}

void Ball::UpdatePosition(float dt) {
    MaterialPoint::UpdatePosition(dt);

    //  Update position if out-of-bounds
    float x = position.x, y = position.y;

    if (x < radius) {
        position = Vector2(radius, y);
        velocity.x *= -1;
    }
    else if (x > X - radius) {
        position = Vector2(X - radius, y);
        velocity.x *= -1;
    }

    if (y < radius) {
        position = Vector2(x, radius);
        velocity.y *= -1;
    }
    else if (y > Y - radius) {
        position = Vector2(x, Y - radius);
        velocity.y *= -1;
    }
    this->place();
}

void AddBall(sf::RenderWindow& window, std::vector<Ball>& balls)
{
    Ball ball(sf::Mouse::getPosition(window));
    balls.push_back(ball);
}

void UpdateBalls(sf::RenderWindow& window, std::vector<Ball>& balls, float dt)
{
    for (auto& ball: balls) {
        ball.UpdatePosition(dt);
//        window.draw(ball.particle);
    }
    ResolveCollisions(balls, dt);
    for (auto& ball: balls) {
//        ball.UpdatePosition(dt);
        window.draw(ball.particle);
    }
}

void ResolveCollision(Ball& b1, Ball& b2)
{
    Vector2 dist = b1.position - b2.position;
    float dist_len = dist.len();
    float delta = dist_len - b1.radius - b2.radius;
    if (delta > 0)
        return;
    else {
        delta *= 0.5f;
        b1.position -= delta * dist / dist_len;
        dist = b1.position - b2.position;
        b2.position += delta * dist / dist_len;

        dist = b1.position - b2.position;
        dist_len = dist.len();

        Vector2 n = dist / dist_len;
        Vector2 k = b1.velocity - b2.velocity;
        float p = 2.0 * (n * k) / (b1.mass + b2.mass);
        b1.velocity -= p * b2.mass * n;
        b2.velocity += p * b1.mass * n;
    }
}

void ResolveCollisions(vector<Ball>& balls, float dt)
{
    int size = balls.size();
    for (int i = 0; i < size; i++) {
//        balls[i].UpdatePosition(dt);
        for (int k = i+1; k < size; k++) {
            ResolveCollision(balls[i], balls[k]);
        }
        balls[i].place();
    }
}
#ifndef INCLUDE_VECTOR2_H_
#define INCLUDE_VECTOR2_H_


class Vector2
{
public:
	float x, y;

	Vector2() : x(0), y(0) {};
	Vector2(float x_, float y_) : x(x_), y(y_) {};
	Vector2(sf::Vector2f v) : x(v.x), y(v.y) {};
    Vector2(sf::Vector2i v) : x(v.x), y(v.y) {};
	~Vector2() {};

	Vector2 operator+(const Vector2&) const;
	Vector2& operator+=(const Vector2&);
	Vector2 operator-(const Vector2&) const;
	Vector2& operator-=(const Vector2&);

	float operator*(const Vector2&) const;
	float operator^(const Vector2&) const;

	Vector2 operator*(float k);
	Vector2 operator/(float k);

	float len() const;
	float squareLen() const;
	Vector2 norm();

	Vector2 tangent() const;

	Vector2 operator-() const;

	Vector2& rotate(float);
	Vector2 getRotate(float) const;
};

std::ostream& operator<<(std::ostream& stream, const Vector2& v);
std::istream& operator>>(std::istream& stream, Vector2& v);

Vector2 operator*(float k, Vector2& v);


#endif /* INCLUDE_VECTOR2_H_ */

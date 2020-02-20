#include <iostream>
#include <cmath>

#include "vector2.h"


Vector2::Vector2(float x1 = 0, float y1 = 0)
{
	x = x1;
	y = y1;
}

Vector2::Vector2(Vector2& v)
{
	x = v.x;
	y = v.y;
}

Vector2::~Vector2()
{
	x = 0;
	y = 0;
}


std::ostream& operator<<(std::ostream& stream, const Vector2& v)
{
	stream << v.x << " " << v.y;
	return stream;
}

std::istream& operator>>(std::istream& stream, Vector2& v)
{
	stream >> v.x >> v.y;
	return stream;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return {x + other.x, y + other.y};
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return {x - other.x, y - other.y};
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

float Vector2::operator*(const Vector2& other) const
{
	return (x * other.x + y * other.y);
}

float Vector2::operator^(const Vector2& other) const
{
	return (x * other.y - y * other.x);
}

Vector2 Vector2::operator*(float k)
{
	return {x*k, y*k};
}

Vector2 operator*(float k, Vector2& v)
{
	return {v.x*k, v.y*k};
}

Vector2 Vector2::operator/(float k)
{
	return {x/k, y/k};
}

float Vector2::len() const
{
	return sqrt(x*x + y*y);
}

float Vector2::squareLen() const
{
	return (x*x + y*y);
}

Vector2 Vector2::norm()
{
	float len = this->len();
	return {this->x / len, this->y / len};
}

Vector2 Vector2::vertical() const
{
	return {y, -x};
}

Vector2 Vector2::operator-() const
{
	return {-x, -y};
}

Vector2& Vector2::rotate(float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	float _x = x*c - y*s;
	float _y = x*s + y*c;
	x = _x, y = _y;
	return *this;
}

Vector2 Vector2::getRotate(float angle) const
{
	float s = sin(angle);
	float c = cos(angle);
	return {x*c - y*s, x*s + y*c};
}

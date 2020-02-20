#include <iostream>

#include "vector2.h"

using namespace std;

int main()
{
	Vector2 a(1, 1), b(2, 2), c(3, 1);
//	cout << "Vector 1: "; cin >> a;
//	cout << "Vector 2: "; cin >> b;

	cout << "a + b = " << (a + b) << endl;
	cout << "a - b = " << (a - b) << endl;

	a += c;	cout << "a += c: " << a << endl;
	b -= c; cout << "b -= c: " << b << endl;

	cout << "a * b = " << (a * b) << endl;
	cout << "a ^ b = " << (a ^ b) << endl;

	cout << "Len, square len: " << a.len() << " " << a.squareLen() << endl;
	cout << "Norm: " << a.norm() << ", len = " << a.norm().len() << endl;

	cout << "Vertical: " << a.vertical() << endl;

	cout << "-a = " << (-a) << endl;
	cout << "Multiply by k: a*k = " << (a * 2) << " = " << (2*a) << " = k*a" << endl;
	cout << "a = " << a << endl;


	a.rotate(30); cout << "Rotate 30 degr: " << a << endl;
	a.rotate(-30);
	cout << "GetRotated: " << a.getRotate(30) << endl;
	cout << "a = " << a << endl;

	return 0;
}

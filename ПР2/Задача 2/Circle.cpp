#define _USE_MATH_DEFINES
#include <iostream>
#include "Circle.h"
#include <cmath>

using namespace std;

void Circle::show()
{
	cout << "ќкружность радиуса " << radius
		<< " с координатой центра " << "(" << x_center << ";" << y_center << ")" << endl;
}

Circle::Circle()
{
	radius = 1;
	x_center = 0;
	y_center = 0;
}

Circle::Circle(float r=1, float x=0, float y=0)
{
	radius = r;
	x_center = x;
	y_center = y;
	show();
}

Circle::~Circle()
{
	cout << "”ничтожение объекта Circle" << endl;
}

void Circle::set_circle(float radius, float x_center, float y_center)
{
	this->radius = radius;
	this->x_center = x_center;
	this->y_center = y_center;
}

float Circle::square()
{
	return M_PI * pow(radius, 2);
}

bool Circle::triangle_around(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	float s = sqrt(p * (p - a) * (p - b) * (p - c));
	float r_around = (a * b * c) / (4 * s);
	if (radius == r_around) return true;
	return false;
}

bool Circle::triangle_in(float a, float b, float c)
{
	float r_in = (a + b - c) / 2;
	if (radius == r_in) return true;
	return false;
}

bool Circle::check_circle(float r, float x_cntr, float y_cntr)
{
	float d = sqrt(pow((abs(x_center - x_cntr)), 2) + pow((abs(y_center - y_cntr)), 2));
	if (d == 0 && radius == r) return true;
	else if (d > (radius + r)) return false;
	else if (d < abs(radius - r)) return false;
	else return true;
}

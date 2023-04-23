#include <iostream>
#include <cmath>
#include "Dot.h"

using namespace std;

Dot::Dot()
{
	x = 0;
	y = 0;
}

Dot::Dot(int x, int y)
{
	this->x = x;
	this->y = y;
}

Dot::~Dot()
{
	// Destruction of Dot object
}

double Dot::Radius(int x, int y)
{
	return sqrt((x * x) + (y * y));
}

bool Dot::operator>(Dot& obj)
{
	if (Radius(x, y) > obj.Radius(obj.x, obj.y)) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& stream, Dot obj)
{
	stream << "(" << obj.x << "; ";
	stream << obj.y << ")";
	return stream;
}

std::istream& operator>>(std::istream& stream, Dot& obj)
{
	stream >> obj.x;
	stream >> obj.y;
	return stream;
}

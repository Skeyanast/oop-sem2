#include <iostream>
#include <cmath>
#include "Cone.h"

using namespace std;

const double pi = 3.14159265;

Cone::Cone()
{
	x = y = z = r = h = 0;
}

Cone::Cone(double r , double h)
{
	x = y = z = 0;
	this->r = r;
	this->h = h;
}

Cone::Cone(double x, double y, double z, double r, double h)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->r = r;
	this->h = h;
}

Cone::~Cone()
{
	//cout << "”ничтожение конуса" << endl;
}

void Cone::setCoordinate(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Cone::setRadius(double r)
{
	this->r = r;
}

void Cone::setHeight(double h)
{
	this->h = h;
}

double Cone::getRadius()
{
	return r;
}

double Cone::getHeight()
{
	return h;
}

double Cone::area()
{
	double l = sqrt(h * h + r * r);
	return pi * r * (r + l);
}

double Cone::volume()
{
	return pi * r * r * h / 3;
}

ostream& operator<<(ostream& stream, Cone obj)
{
	stream << "(" << obj.x << "; ";
	stream << obj.y << "; ";
	stream << obj.z << ") ";
	stream << "r=" << obj.r << " ";
	stream << "h=" << obj.h << endl;
	return stream;
}

istream& operator>>(istream& stream, Cone& obj)
{
	stream >> obj.x;
	stream >> obj.y;
	stream >> obj.z;
	stream >> obj.r;
	stream >> obj.h;
	return stream;
}

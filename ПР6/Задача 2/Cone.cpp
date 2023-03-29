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

Cone::Cone(Cone& T)
{
	x = T.x;
	y = T.y;
	z = T.z;
	r = T.r;
	h = T.h;
}

Cone::~Cone()
{
	//cout << "Конус уничтожен" << endl;
}

void Cone::Out()
{
	cout << "I am Cone:" << endl;
	cout << x << " " << y << " " << z << " " << r << " " << h << endl;
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

bool Cone::operator>(Cone& B)
{
	if (r != B.r && h != B.h) {
		if (r > B.r && h > B.h) return true;
		else if ((r < B.r && h > B.h) ||
			(r > B.r && h < B.h)) {
			if (area() > B.area()) return true;
			else return false;
		}
	}
	else {
		if (r == B.r && h > B.h) return true;
		else return false;
		if (r > B.r && h == B.h) return true;
		else return false;
	}
	return false;
}

bool Cone::operator==(Cone& B)
{
	if (this->x == B.x &&
		this->y == B.y &&
		this->z == B.z &&
		this->r == B.r &&
		this->h == B.h) return true;
	return false;
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

#include <iostream>
#include <cmath>
#include "Truncone.h"

using namespace std;

const double pi = 3.14159265;

Truncone::Truncone()
{
	x = y = z = r = nh = 0;
}

Truncone::Truncone(double x, double y, double z, double r, double h, double nh) :
	Cone(x, y, z, r, h)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->r = r;
	this->nh = nh;
}

Truncone::Truncone(Cone& T, double nh) :
	Cone(T)
{
	this->x = Cone::x;
	this->y = Cone::y;
	this->z = Cone::z;
	this->r = Cone::r;
	this->nh = nh;
}

Truncone::~Truncone()
{
	//cout << "Усеченный конус уничтожен" << endl;
}

void Truncone::Out()
{
	cout << "I am Truncone:" << endl;
	cout << x << " " << y << " " << z << " " << r << " " << nh << endl;
}

void Truncone::Out_my_Cone()
{
	Out();
	cout << "My Cone:" << endl;
	Cone::Out();
}

double Truncone::area()
{
	double l = sqrt(r * r + nh * nh);
	double kusokr = sqrt(l * l - nh * nh);
	double r1 = r - 2 * kusokr;
	return pi * (r + r1) * l + (pi * r * r) + (pi * r1 * r1);
}

double Truncone::volume()
{
	double l = sqrt(r * r + nh * nh);
	double kusokr = sqrt(l * l - nh * nh);
	double r1 = r - 2 * kusokr;
	return pi * nh * ((r * r) + (r1 * r1) + (r * r1)) / 3;
}

bool Truncone::operator>(Truncone& B)
{
	if (r != B.r && nh != B.nh) {
		if (r > B.r && nh > B.nh) return true;
		else if ((r < B.r && nh > B.nh) ||
			(r > B.r && nh < B.nh)) {
			if (area() > B.area()) return true;
			else return false;
		}
	}
	else {
		if (r == B.r && nh > B.nh) return true;
		else return false;
		if (r > B.r && nh == B.nh) return true;
		else return false;
	}
	return false;
}

bool Truncone::operator==(Truncone& B)
{
	if (x == B.x &&
		y == B.y &&
		z == B.z &&
		r == B.r &&
		nh == B.nh) return true;
	return false;
}

std::ostream& operator<<(std::ostream& stream, Truncone obj)
{
	stream << "(" << obj.x << "; ";
	stream << obj.y << "; ";
	stream << obj.z << ") ";
	stream << "r=" << obj.r << " ";
	stream << "nh=" << obj.nh << endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Truncone obj)
{
	stream >> obj.x;
	stream >> obj.y;
	stream >> obj.z;
	stream >> obj.r;
	stream >> obj.nh;
	return stream;
}

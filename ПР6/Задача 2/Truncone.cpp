#include <iostream>
#include <cmath>
#include "Truncone.h"

using namespace std;

const double pi = 3.14159265;

Truncone::Truncone()
{
	xx = yy = zz = rr = nh = 0;
}

Truncone::Truncone(double x, double y, double z, double r, double h, double nh) :
	Cone(x, y, z, r, h)
{
	xx = x;
	yy = y;
	zz = z;
	rr = r;
	this->nh = nh;
}

Truncone::Truncone(Cone& T, double nh) :
	Cone(T)
{
	xx = x;
	yy = y;
	zz = z;
	rr = r;
	this->nh = nh;
}

Truncone::~Truncone()
{
	//cout << "Усеченный конус уничтожен" << endl;
}

void Truncone::Out()
{
	cout << "I am Truncone:" << endl;
	cout << xx << " " << yy << " " << zz << " " << rr << " " << nh << endl;
}

void Truncone::Out_my_Cone()
{
	Out();
	cout << "My Cone:" << endl;
	Cone::Out();
}

double Truncone::area()
{
	double l = sqrt(rr * rr + nh * nh);
	double kusokr = sqrt(l * l - nh * nh);
	double r1 = rr - 2 * kusokr;
	return pi * (rr + r1) * l + (pi * rr * rr) + (pi * r1 * r1);
}

double Truncone::volume()
{
	double l = sqrt(rr * rr + nh * nh);
	double kusokr = sqrt(l * l - nh * nh);
	double r1 = rr - 2 * kusokr;
	return pi * nh * ((rr * rr) + (r1 * r1) + (rr * r1)) / 3;
}

bool Truncone::operator>(Truncone& B)
{
	if (rr != B.rr && nh != B.nh) {
		if (rr > B.rr && nh > B.nh) return true;
		else if ((rr < B.rr && nh > B.nh) ||
			(rr > B.rr && nh < B.nh)) {
			if (area() > B.area()) return true;
			else return false;
		}
	}
	else {
		if (rr == B.rr && nh > B.nh) return true;
		else return false;
		if (rr > B.rr && nh == B.nh) return true;
		else return false;
	}
	return false;
}

bool Truncone::operator==(Truncone& B)
{
	if (this->xx == B.xx &&
		this->yy == B.yy &&
		this->zz == B.zz &&
		this->rr == B.rr &&
		this->nh == B.nh) return true;
	return false;
}

std::ostream& operator<<(std::ostream& stream, Truncone obj)
{
	stream << "(" << obj.xx << "; ";
	stream << obj.yy << "; ";
	stream << obj.zz << ") ";
	stream << "r=" << obj.rr << " ";
	stream << "h=" << obj.nh << endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Truncone obj)
{
	stream >> obj.xx;
	stream >> obj.yy;
	stream >> obj.zz;
	stream >> obj.rr;
	stream >> obj.nh;
	return stream;
}

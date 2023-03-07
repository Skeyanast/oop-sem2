#include <iostream>
#include "eq2.h"
#include <cmath>

using namespace std;

eq2::eq2()
{
	a = 1;
	b = 1;
	c = 1;
	D = b * b - 4 * a * c;
}

eq2::eq2(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
	D = b * b - 4 * a * c;
}

eq2::~eq2()
{
	cout << "Уничтожение объекта eq2" << endl << endl;
}

double eq2::get_D()
{
	return D;
}

void eq2::set(double a, double b , double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
	D = b * b - 4 * a * c;
}

void eq2::out()
{
	cout << a << "*x^2 (+) " << b << "*x (+) " << c << " = 0" << endl;
}

double eq2::find_X()
{
	if (D < 0) {
		cout << "Корней нет" << endl;
		return 0;
	}
	else {
		if (D == 0) {
			cout << "Корень один: " << endl;
			double x = (-b - sqrt(D)) / (2 * a);
			cout << x << endl;
			return x;
		}
		else {
			cout << "Корней 2, наибольший: " << endl;
			double x1 = (-b - sqrt(D)) / (2 * a);
			double x2 = (-b + sqrt(D)) / (2 * a);
			if (x1 > x2) {
				cout << x1 << endl;
				return x1;
			}
			else {
				cout << x2 << endl;
				return x2;
			}
		}
	}
}

double eq2::find_Y(double x)
{
	return a * x * x + b * x + c;
}

void Inc(eq2&A)
{
	A.a+=1;
	A.b+=1;
	A.c+=1;
	A.set(A.a, A.b, A.c);
}

eq2 eq2::operator+(eq2 &E)
{
	eq2 temp;
	temp.a = this->a + E.a;
	temp.b = this->b + E.b;
	temp.c = this->c + E.c;
	return temp;
}
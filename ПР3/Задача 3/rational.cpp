#include <iostream>
#include "rational.h"
#include <cmath>

using namespace std;

rational::rational()
{
	a = 0;
	b = 1;
}

rational::rational(int a, int b)
{
	if (b != 0) {
		this->b = b;
	}
	else {
		while (b == 0) {
			cout << "¬ведите знаменатель, отличный от нул€" << endl;
			cin >> b;
		}
		this->b = b;
	}

	if (a > b) {
		a = a % b;
		this->a = a % b;
	}
	else if (a == b) {
		this->a = 1;
		this->b = 1;
	}
	else this->a = a;

	if (a < b) {
		for (int i = 1; i < a + 1; i++) {
			if ((a % i == 0) && (b % i == 0) && (i != 1)) {
				a = a / i;
				b = b / i;
				i = 1;
			}
		}
		this->a = a;
		this->b = b;
	}
}

rational::~rational()
{
	//cout << "\n”ничтожение объекта rational" << endl;
}

void rational::set(int a, int b)
{
	if (b != 0) {
		this->b = b;
	}
	else {
		while (b == 0) {
			cout << "¬ведите знаменатель, отличный от нул€" << endl;
			cin >> b;
		}
		this->b = b;
	}

	if (a > b) {
		a = a % b;
		this->a = a % b;
	}
	else if (a == b) {
		this->a = 1;
		this->b = 1;
	}
	else this->a = a;

	if (a < b) {
		for (int i = 1; i < a+1; i++) {
			if ((a % i == 0) && (b % i == 0) && (i != 1)) {
				a = a / i;
				b = b / i;
				i = 1;
			}
		}
		this->a = a;
		this->b = b;
	}
}

void rational::show()
{
	cout << a << "/" << b << endl;
}

rational rational::operator+(rational &B)
{
	rational temp;
	int a1 = a;
	int a2 = B.a;
	int b1 = b;
	int b2 = B.b;
	
	if (b1 != b2) {
		if (b1 % b2 == 0) {
			int k = b1 / b2;
			a2 = a2 * k;
			b2 = b2 * k;
			temp.a = a1 + a2;
			temp.b = b1;
		}
		else if (b2 % b1 == 0) {
			int k = b2 / b1;
			a1 = a1 * k;
			b1 = b1 * k;
			temp.a = a1 + a2;
			temp.b = b2;
		}
		else {
			temp.a = a1 * b2 + a2 * b1;
			temp.b = b1 * b2;
		}
	}
	else {
		temp.a = a1 + a2;
		temp.b = b1;
	}

	if (temp.a == temp.b) {
		temp.a = 1;
		temp.b = 1;
	}

	return temp;
}

rational& rational::operator++()
{
	a++;
	return *this;
}

rational& rational::operator++(const int)
{
	rational temp = *this;
	a++;
	return temp;
}

bool rational::operator==(rational &B)
{
	rational temp = *this;
	temp.set(a, b);
	B.set(B.a, B.b);
	if (a == B.a && b == B.b) return true;
	return false;
}

bool rational::operator>(rational &B)
{
	rational temp = *this;
	temp.set(a, b);
	B.set(B.a, B.b);
	if (a == B.a && b == B.b) return false;
	else if (a == B.a && b != B.b) {
		if (b < B.b) return true;
		else return false;
	}
	else if (a != B.a && b == B.b) {
		if (a > B.a) return true;
		else return false;
	}
	else {
		double c1, c2;
		c1 = a / b;
		c2 = B.a / B.b;
		if (c1 > c2) return true;
		else return false;
	}
}

rational& rational::operator=(rational const &B)
{
	a = B.a;
	b = B.b;
	return *this;
}

rational operator-(rational &A, rational &B)
{
	rational temp;
	int a1 = A.a;
	int a2 = B.a;
	int b1 = A.b;
	int b2 = B.b;

	if (b1 != b2) {
		if (b1 % b2 == 0) {
			int k = b1 / b2;
			a2 = a2 * k;
			b2 = b2 * k;
			temp.a = a1 - a2;
			temp.b = b1;
		}
		else if (b2 % b1 == 0) {
			int k = b2 / b1;
			a1 = a1 * k;
			b1 = b1 * k;
			temp.a = a1 - a2;
			temp.b = b2;
		}
		else {
			temp.a = a1 * b2 - a2 * b1;
			temp.b = b1 * b2;
		}
	}
	else {
		temp.a = a1 - a2;
		temp.b = b1;
	}

	if (temp.a == temp.b) {
		temp.a = 1;
		temp.b = 1;
	}

	return temp;
}


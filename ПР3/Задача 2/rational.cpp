#include <iostream>
#include "rational.h"
#include <cmath>

using namespace std;

rational::rational()
{
	a = 666;
	b = 777;
}

rational::rational(int a, int b)
{
	if (b != 0) {
		this->b = b;
	}
	else {
		while (b == 0) {
			cout << "Ââåäèòå çíàìåíàòåëü, îòëè÷íûé îò íóëÿ" << endl;
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
	cout << "\nÓíè÷òîæåíèå îáúåêòà rational" << endl;
}

void rational::set(int a, int b)
{
	if (b != 0) {
		this->b = b;
	}
	else {
		while (b == 0) {
			cout << "Ââåäèòå çíàìåíàòåëü, îòëè÷íûé îò íóëÿ" << endl;
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

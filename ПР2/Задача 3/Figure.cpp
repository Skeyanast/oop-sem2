#define _USE_MATH_DEFINES
#include <iostream>
#include "Figure.h"
#include <cmath>

using namespace std;

Figure::Figure()
{
	x1 = 0;
	y1 = 0;
	x2 = 1;
	y2 = 0;
	x3 = 1;
	y3 = 1;
	x4 = 0;
	y4 = 1;
	p = perimeter(x1, y1, x2, y2, x3, y3, x4, y4);
	s = square(x1, y1, x2, y2, x3, y3, x4, y4);
}

Figure::Figure(float x1=3, float y1=2, float x2=0, float y2=5, float x3=-3, float y3=2, float x4=0, float y4=-1)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->x4 = x4;
	this->y4 = y4;
	p = perimeter(x1, y1, x2, y2, x3, y3, x4, y4);
	s = square(x1, y1, x2, y2, x3, y3, x4, y4);
}

Figure::~Figure()
{
	cout << "Уничтожение объекта Figure" << endl;
}

void Figure::set(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->x4 = x4;
	this->y4 = y4;
	p = perimeter(x1, y1, x2, y2, x3, y3, x4, y4);
	s = square(x1, y1, x2, y2, x3, y3, x4, y4);
}

void Figure::show()
{
	cout << "Четырехугольник заданный координатами "
		<< "(" << x1 << ";" << y1 << ")" << ", "
		<< "(" << x2 << ";" << y2 << ")" << ", "
		<< "(" << x3 << ";" << y3 << ")" << ", "
		<< "(" << x4 << ";" << y4 << ")" << "; "
		<< "P = " << p << "; "
		<< "S = " << s << "." << endl;
}

void Figure::show_par()
{
	if (is_special()) {
		if (is_square()) {
			cout << "Четырехугольник - квадрат;" << endl;
		}
		else if (is_prug()) {
			cout << "Четырехугольник - прямоугольник;" << endl;
		}
		else {
			cout << "Четырехугольник - ромб;" << endl;
		}
	}
	else cout << "Четырехугольник произвольной формы;" << endl;
	if (is_in_circle())
		cout << "Четырехугольник можно вписать в окружность;" << endl;
	else
		cout << "Четырехугольник нельзя вписать в окружность;" << endl;
	if (is_out_circle())
		cout << "В четырехугольник можно вписать окружность." << endl;
	else
		cout << "В четырехугольник нельзя вписать окружность." << endl;
}

float Figure::line_length(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(abs(x2 - x1), 2) + (pow(abs(y2 - y1), 2)));
}

float Figure::perimeter(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	return line_length(x1, y1, x2, y2) + line_length(x2, y2, x3, y3) + line_length(x3, y3, x4, y4) + line_length(x4, y4, x1, y1);
}

float Figure::square(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	float d1, d2, co, si;
	d1 = line_length(x1, y1, x3, y3);
	d2 = line_length(x2, y2, x4, y4);
	co = abs(((x3 - x1) * (x4 - x2)) + ((y3 - y1) * (y4 - y2))) / (d1 * d2);
	si = sqrt(1 - pow(co, 2));
	return (d1 * d2 * si) / 2;
}

bool Figure::is_special()
{
	if (line_length(x1, y1, x2, y2) == line_length(x3, y3, x4, y4)) {
		if (line_length(x2, y2, x3, y3) == line_length(x4, y4, x1, y1))
			return true;
	}
	return false;
}

bool Figure::is_square()
{
	if (is_special()) {
		if (line_length(x1, y1, x2, y2) == line_length(x2, y2, x3, y3)) {
			if (line_length(x1, y1, x3, y3) == line_length(x2, y2, x4, y4))
				return true;
		}
	}
	return false;
}

bool Figure::is_prug()
{
	if (is_special()) {
		if (line_length(x1, y1, x2, y2) != line_length(x2, y2, x3, y3)) {
			if (line_length(x1, y1, x3, y3) == line_length(x2, y2, x4, y4))
				return true;
		}
	}
	return false;
}

bool Figure::is_romb()
{
	if (is_special()) {
		if (line_length(x1, y1, x2, y2) == line_length(x2, y2, x3, y3)) {
			if (line_length(x1, y1, x3, y3) != line_length(x2, y2, x4, y4))
				return true;
		}
	}
	return false;
}

bool Figure::is_in_circle()
{
	float a, b, c, d, d1, d2;
	a = line_length(x1, y1, x2, y2);
	b = line_length(x2, y2, x3, y3);
	c = line_length(x3, y3, x4, y4);
	d = line_length(x4, y4, x1, y1);
	d1 = line_length(x1, y1, x3, y3);
	d2 = line_length(x2, y2, x4, y4);
	if (round(d1 * d2) == round((a * c) + (b * d)))
		return true;
	return false;
}

bool Figure::is_out_circle()
{
	if (is_special()) return true;
	return false;
}
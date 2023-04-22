#include <iostream>
#include <string>
#include "My_class.h"
#include "Templates.h"

using namespace std;

My_class::My_class()
{
	name = "NONE";
	number = 0;
}

My_class::My_class(string name, int number)
{
	this->name = name;
	this->number = number;
}

My_class::~My_class()
{
	//cout << "Destruction of My_class object"
}

bool My_class::operator>(My_class& obj)
{
	if (name > obj.name) return true;
	if (name == obj.name) {
		if (number > obj.number) {
			return true;
		}
		else return false;
	}
	else return false;
}

ostream& operator<<(ostream& stream, My_class obj)
{
	stream << obj.name << " ";
	stream << obj.number << " ";
	return stream;
}

istream& operator>>(istream& stream, My_class& obj)
{
	stream >> obj.name;
	stream >> obj.number;
	return stream;
}
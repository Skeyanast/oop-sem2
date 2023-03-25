#include <iostream>
#include "Cone.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	static Cone c1(0, 0, 0, 45, 32);
	cout << "Конус 1: " << c1;
	cout << "Площадь: " << c1.area() << endl
		<< "Объем: " << c1.volume() << endl << endl;

	static Cone c2(80, -39, 298, 92, 7);
	cout << "Конус 2: " << c2;
	cout << "Площадь: " << c2.area() << endl
		<< "Объем: " << c2.volume() << endl << endl;

	Cone* c3 = new Cone();
	c3->setCoordinate(25, 56, 22);
	c3->setHeight(34);
	c3->setRadius(98);
	cout << "Конус 3: ";
	cout << "Площадь: " << c3->area() << endl
		<< "Объем: " << c3->volume() << endl << endl;

	Cone cmas[3] = {
		Cone(1, 2, 3, 4, 5),
		Cone(2, 3, 4, 5, 6),
		Cone(3, 4, 5, 6, 7)};
	for (int i = 0; i < 3; i++) {
		cout << "Конус " << i + 1 << " из массива: " << cmas[i];
	}

	return 0;
}
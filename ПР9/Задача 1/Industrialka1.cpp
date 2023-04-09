#include <iostream>
#include "My_class.h"
#include "templates.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int x = 1;
	int y = 2;
	cout << "ints before" << endl;
	OutXY(x, y);

	float x1 = 1.5;
	float y1 = 5.9;
	cout << "floats before" << endl;
	OutXY(x1, y1);
	Swap(x1, y1);
	cout << "after swap" << endl;
	OutXY(x1, y1);

	My_class t1(1, 1.5), t2(2, 9.9);
	cout << "classes before" << endl;
	t1.Out();
	t2.Out();
	Swap(t1, t2);
	cout << "after swap" << endl;
	t1.Out();
	t2.Out();

	return 0;
}
#include <iostream>
#include "Cone.h"
#include "Truncone.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Cone A(1, 2, 3, 4, 5);
	Truncone B(2, 3, 4, 5, 6, 7);
	Truncone C(A, 384);
	Truncone D(A, 98);
	Truncone E(A, 270);
	cout << A;
	cout << A.area() << " " << A.volume() << endl;
	cout << B;
	cout << B.area() << " " << B.volume() << endl;
	cout << C;
	cout << D;
	cout << E;
	A.Out();
	B.Out();
	B.Out_my_Cone();
	if (C > E) cout << "yes";
	else cout << "no";

	return 0;
}
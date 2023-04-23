#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	My_Array A;
	A.Input();
	A.Output();
	int S = A.Sum();
	cout << "Sum = " << S << endl;
	My_Array B(5);
	B.Input();
	B.Output();
	B.Sort();
	B.Output();
	B[4] = 123;
	B.Output();
	B[5298754] = 666;
	B.Output();


	return 0;
}
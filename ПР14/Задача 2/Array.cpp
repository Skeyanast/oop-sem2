#include <iostream>
#include "Array.h"

using namespace std;

My_Array::My_Array()
{
	len = LEN_MAX;
	a = new int[len];
	for (int i = 0; i < len; i++)
		a[i] = 0;
}

My_Array::My_Array(int L)
{
	len = (L < LEN_MAX) ? L : LEN_MAX;
	a = new int[len];
	for (int i = 0; i < len; i++)
		a[i] = 0;
}

My_Array::~My_Array()
{
	delete[] a;
}

void My_Array::Input()
{
	cout << "Input " << len << " elements\n";
	for (int i = 0; i < len; i++)
		cin >> a[i];
}

void My_Array::Output()
{
	cout << "Is elements\n";
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}

int My_Array::Sum()
{
	int S = 0;
	for (int i = 0; i < len; i++)
		S += a[i];
		return S;
}

void My_Array::Sort()
{
	int flag;
	int tmp;
	do
	{
		flag = 1;
		for (int i = 0; i < len - 1; i++)
			if (a[i] > a[i + 1]) {
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = 0;
				break;
			}
	} while (flag != 1);
}

int My_Array::Add(int T) {
	if (len < LEN_MAX) {
		a[len++] = T;
		return 1;
	}
	else
		return 0;
}

My_Array& My_Array::operator = (My_Array& Right)
{
	len = 0;
	for (int i = 0; i < Right.len; i++)
		Add(Right.a[i]);
	return *this;
}

int& My_Array::operator[](int n)
{
	try {
		if (n < 0 || n > len - 1) {
			throw runtime_error("Try to take unexisted element\n");
		}
		return a[n];
	}
	catch (runtime_error& e) {
		cout << "Exception caught!" << endl
			<< e.what();
		exit(1);
	}
	return a[n];
}
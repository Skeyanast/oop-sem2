#include <iostream>
#include <string>
#include "Set.hpp"
#include "Dot.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Set <int> myset(6);
	cout << myset.Is_Empty() << endl;
	for (int i = 0; i < 6; i++) {
		myset[i] = 7 - i;
	}
	cout << myset.Is_Full() << endl;

	myset.Print();
	myset.Sort();
	cout << myset.In_Set(4) << endl;
	
	myset.Print();


	return 0;
}
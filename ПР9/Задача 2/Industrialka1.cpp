#include <iostream>
#include <string>
#include "Templates.h"
#include "My_class.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");


	int len = 5;

	int* list1 = new int[len];
	for (int i = 0; i < len; i++) {
		cin >> list1[i];
	}
	list1 = sort(list1, len);
	cout << "Ints after sort" << endl;
	for (int i = 0; i < len; i++) {
		cout << list1[i] << "\t";
	}
	cout << endl;

	float* list2 = new float[len];
	for (int i = 0; i < len; i++) {
		cin >> list2[i];
	}
	list2 = sort(list2, len);
	cout << "Floats after sort" << endl;
	for (int i = 0; i < len; i++) {
		cout << list2[i] << "\t";
	}
	cout << endl;
	
	string* list3 = new string[len];
	for (int i = 0; i < len; i++) {
		cin >> list3[i];
	}
	list3 = sort(list3, len);
	cout << "Strings after sort" << endl;
	for (int i = 0; i < len; i++) {
		cout << list3[i] << "\t";
	}
	cout << endl;

	My_class* list4 = new My_class[len];
	for (int i = 0; i < len; i++) {
		cin >> list4[i];
	}
	list4 = sort(list4, len);
	cout << "My_classes after sort" << endl;
	for (int i = 0; i < len; i++) {
		cout << list4[i];
	}

	return 0;
}
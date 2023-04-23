#pragma once

#define LEN_MAX 5

class My_Array {
	int* a;
	int len;
public:
	My_Array();
	My_Array(int);
	~My_Array();
	void Input();
	void Output();
	int Sum();
	void Sort();
	int Add(int);
	My_Array& operator=(My_Array&);
	int& operator[](int);
};
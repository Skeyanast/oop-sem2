#pragma once
#include <iostream>

using namespace std;

// template class Set specification

template<typename Atype>
class Set {
private:
	Atype* a;
	int len;
public:
	Set(int);
	~Set();
	bool Is_Empty();
	bool Is_Full();
	void Add(Atype);
	bool In_Set(Atype);
	Atype Get(Atype);
	void Sort();
	void Print();
	Atype& operator[](int);
};

// template class Set methods realization

template<typename Atype>
Set<Atype>::Set(int size)
{
	len = size;
	a = new Atype[len];
	for (int i = 0; i < len; i++) {
		a[i] = 0;
	}
}

template<typename Atype>
Set<Atype>::~Set()
{
	delete[] a;
	//cout << "Destruction Set object";
}

template<typename Atype>
bool Set<Atype>::Is_Empty()
{
	bool empty = true;
	for (int i = 0; i < len; i++) {
		if (a[i] != 0) {
			bool empty = false;
			return empty;
		}
	}
	return empty;
}

template<typename Atype>
bool Set<Atype>::Is_Full()
{
	bool full = true;
	for (int i = 0; i < len; i++) {
		if (a[i] == 0) {
			bool full = false;
			return full;
		}
	}
	return full;
}

template<typename Atype>
void Set<Atype>::Add(Atype x)
{
	if (!Is_Full()) {
		if (!In_Set(x)) {
			for (int i = 0; i < len; i++) {
				if (a[i] == 0) {
					a[i] = x;
					Sort();
					return;
				}
			}
		}
	}
	else cout << "Множество заполнено, вставка невозможна" << endl;
}

template<typename Atype>
bool Set<Atype>::In_Set(Atype x)
{
	bool same = false;
	for (int i = 0; i < len; i++) {
		if (a[i] == x) {
			bool same = true;
			return same;
		}
	}
	return same;
}

template<typename Atype>
Atype Set<Atype>::Get(Atype x)
{
	if (!Is_Empty()) {
		if (In_Set(x)) {
			for (int i = 0; i < len; i++) {
				if (a[i] == x) {
					a[i] == 0;
				}
			}
		}
	}
}

template<typename Atype>
void Set<Atype>::Sort()
{
	bool execution = true;
	for (int j = 0; j < len - 1; j++) {
		if (execution == true) {
			bool exchange = false;
			for (int i = 0; i < len - 1; i++) {
				if (a[i] > a[i + 1]) {
					swap(a[i], a[i + 1]);
					exchange = true;
				}
			}
			if (exchange == false) execution = false;
		}
	}
}

template<typename Atype>
void Set<Atype>::Print()
{
	for (int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

template<typename Atype>
Atype& Set<Atype>::operator[](int n)
{
	if (n < 0 || n > len - 1) {
		cout << "Unexisted number element";
		exit(1);
	}
	return a[n];
}
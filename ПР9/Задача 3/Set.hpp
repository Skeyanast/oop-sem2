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
	bool Add(Atype);
	bool In_Set(Atype);
	Atype Get(Atype);
	Atype& operator[](int);
};

// template class Set methods realization
template<typename Atype>
Set<Atype>::Set(int size)
{
	a = new Atype[size];
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
	return false;
}

template<typename Atype>
bool Set<Atype>::Is_Full()
{
	return false;
}

template<typename Atype>
bool Set<Atype>::Add(Atype)
{
	return false;
}

template<typename Atype>
bool Set<Atype>::In_Set(Atype)
{
	return false;
}

template<typename Atype>
Atype Set<Atype>::Get(Atype)
{
	return Atype();
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
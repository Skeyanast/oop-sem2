#pragma once
#include "Cone.h"

class Truncone : public Cone {
protected:
	double xx, yy, zz;
	double rr;
	double nh;

public:
	Truncone();
	Truncone(double, double, double, double, double, double);
	Truncone(Cone&, double);
	~Truncone();
	void Out();
	void Out_my_Cone();
	double area();
	double volume();
	bool operator>(Truncone&);
	bool operator==(Truncone&);
	friend std::ostream& operator<<(std::ostream&, Truncone);
	friend std::istream& operator>>(std::istream&, Truncone);
};
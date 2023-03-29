#pragma once

class Cone {
protected:
	double x, y, z;
	double r;
	double h;
	
public:
	Cone();
	Cone(double, double);
	Cone(double, double, double, double, double);
	Cone(Cone&);
	~Cone();
	void Out();
	void setCoordinate(double, double, double);
	void setRadius(double);
	void setHeight(double);
	double getRadius();
	double getHeight();
	double area();
	double volume();
	bool operator>(Cone&);
	bool operator==(Cone&);
	friend std::ostream& operator<<(std::ostream&, Cone);
	friend std::istream& operator>>(std::istream&, Cone&);
};
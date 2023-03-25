class Cone {
private:
	double x, y, z;
	double r;
	double h;
	
public:
	Cone();
	Cone(double, double);
	Cone(double, double, double, double, double);
	~Cone();
	void setCoordinate(double, double, double);
	void setRadius(double);
	void setHeight(double);
	double getRadius();
	double getHeight();
	double area();
	double volume();
	friend std::ostream& operator<<(std::ostream&, Cone);
	friend std::istream& operator>>(std::istream&, Cone&);
};
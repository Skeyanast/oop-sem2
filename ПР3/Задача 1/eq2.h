class eq2 {
private:
	double a, b, c;
	double D;
	friend void Inc(eq2&);
public:
	eq2();
	eq2(double, double, double);
	~eq2();
	double get_D();
	void set(double, double, double);
	void out();
	double find_X();
	double find_Y(double);
	eq2 operator+(eq2 &E);
};
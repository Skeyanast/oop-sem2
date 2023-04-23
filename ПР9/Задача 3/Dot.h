#pragma once

class Dot {
private:
	int x;
	int y;
public:
	Dot();
	Dot(int, int);
	~Dot();
	double Radius(int, int);
	bool operator>(Dot&);
	friend std::ostream& operator<<(std::ostream&, Dot);
	friend std::istream& operator>>(std::istream&, Dot&);
};
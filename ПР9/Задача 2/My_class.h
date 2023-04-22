#pragma once

class My_class {
private:
	std::string name;
	int number;
public:
	My_class();
	My_class(std::string, int);
	~My_class();
	bool operator>(My_class&);
	friend std::ostream& operator<<(std::ostream&, My_class);
	friend std::istream& operator>>(std::istream&, My_class&);
};
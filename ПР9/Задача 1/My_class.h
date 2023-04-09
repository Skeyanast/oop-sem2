#pragma once

class My_class {
private:
	int a;
	float b;
public:
	My_class(int, float);
	void Out();
	My_class operator=(My_class&);
};
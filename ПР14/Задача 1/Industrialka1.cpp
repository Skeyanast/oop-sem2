#include <iostream>

using namespace std;

float Division(float num, float den)
{
	if (den == 0) {
		throw runtime_error("Math error: Attempted to divivde by Zero\n");
	}
	return (num / den);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	float num, denom, result;
	num = 12.5;
	denom = 0;
	try {
		result = Division(num, denom);
		cout << "The quotient is "
			<< result << endl;
	}
	catch (runtime_error& e) {
		cout << "Exception occurred" << endl
			<< e.what();
	}

	return 0;
}
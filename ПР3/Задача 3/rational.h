class rational {
private:
	int a, b;
public:
	rational();
	rational(int, int);
	~rational();
	void set(int, int);
	void show();
	rational operator+(rational&);
	rational& operator++();
	rational& operator++(const int);
	bool operator==(rational&);
	bool operator>(rational&);
	rational& operator=(rational const&);
	friend rational operator-(rational&, rational&);
	friend ostream& operator<<(ostream&, rational);
	friend istream& operator>>(istream&, rational&);
};
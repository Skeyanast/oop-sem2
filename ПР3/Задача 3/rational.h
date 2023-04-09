class rational {
private:
	int a, b;
	friend rational operator-(rational&, rational&);
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
	rational& operator=(rational const &);
};
class Figure {
private:
	float x1, x2, x3, x4;
	float y1, y2, y3, y4;
	float p;
	float s;
public:
	Figure();
	Figure(float, float, float, float, float, float, float, float);
	~Figure();
	void set(float, float, float, float, float, float, float, float);
	void show();
	void show_par();
	float line_length(float, float, float, float);
	float perimeter(float, float, float, float, float, float, float, float);
	float square(float, float, float, float, float, float, float, float);
	bool is_special();
	bool is_prug();
	bool is_square();
	bool is_romb();
	bool is_in_circle();
	bool is_out_circle();
};
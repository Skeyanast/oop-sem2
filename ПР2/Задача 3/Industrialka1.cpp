#include <iostream>
#include "Figure.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");

    Figure mas[3];
    float x1, y1, x2, y2, x3, y3, x4, y4;
    for (int i = 0; i < 3; i++) {
        cout << "Введите координаты четырех точек, задающих четырехугольник" << endl;
        cout << "Все координаты вводить последовательно через пробел в формате: Xn Yn" << endl;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        mas[i].set(x1, y1, x2, y2, x3, y3, x4, y4);
        mas[i].show();
        mas[i].show_par();
        cout << endl;
    }

    return 0;
}

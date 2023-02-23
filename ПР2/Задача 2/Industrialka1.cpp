#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");

    Circle mas[3];
    float r, x, y;
    for (int i = 0; i < 3; i++) {
        cout << "Введите значения радиуса и координат центра окружности №" << i + 1 << " через пробел: " << endl;
        cin >> r >> x >> y;
        mas[i].set_circle(r, x, y);
        mas[i].show();
    }

    for (int i = 0; i < 3; i++) {
        cout << "Площадь круга №" << i + 1 << ": " << mas[i].square() << endl;
    }

    cout << "Задайте длины сторон треугольника: " << endl;
    float a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) {
        if (mas[i].triangle_around(a, b, c))
            cout << "Вокруг треугольника с заданными сторонами можно описать окружность №" << i + 1 << endl;
        else
            cout << "Вокруг треугольника с заданными сторонами нельзя описать окружность №" << i + 1 << endl;
        if (mas[i].triangle_in(a, b, c))
            cout << "Треугольник с заданными сторонами можно вписать в окружность №" << i + 1 << endl;
        else
            cout << "Треугольник с заданными сторонами нельзя вписать в окружность №" << i + 1 << endl;
        cout << endl;
    }

    cout << "Введите значения радиуса и координат центра окружности через пробел: " << endl;
    float r1, x1, y1;
    cin >> r1 >> x1 >> y1;
    for (int i = 0; i < 3; i++) {
        if (mas[i].check_circle(r1, x1, y1))
            cout << "Заданная окружность пересекается с окружностью №" << i + 1 << endl;
        else
            cout << "Заданная окружность не пересекается с окружностью №" << i + 1 << endl;
    }
    return 0;
}

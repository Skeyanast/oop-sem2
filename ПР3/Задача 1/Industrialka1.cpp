#include <iostream>
#include "eq2.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");

    eq2 t1(1, 2, 3);
    t1.out();
    Inc(t1);
    t1.out();
    cout << t1.find_X() << endl;
    cout << "Значение от x = 7: " << t1.find_Y(7) << endl;

    double a, b, c;
    cout << "Введите значения коэффициентов ур-ия" << endl;
    cin >> a >> b >> c;
    eq2 t2(a, b, c);
    t2.out();
    cout << "Введите значения коэффициентов ур-ия" << endl;
    cin >> a >> b >> c;
    t2.set(a, b, c);
    t2.out();
    eq2 t3;
    t3 = t1 + t2;
    cout << "Сумма первых двух уравнений: " << endl;
    t3.out();

    return 0;
}

#include <iostream>
#include "eq2.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");

    eq2 t0(1, 2, 3);
    cout << "Первое уравнение:" << endl;
    t0.out();
    cout << "Дискриминант: " << t0.get_D() << endl;
    t0.find_X();
    cout << endl;

    eq2 t1(0, -5, 3);
    cout << "Второе уравнение:" << endl;
    t1.out();
    cout << "Дискриминант: " << t1.get_D() << endl;
    Inc(t1);
    cout << "После операции инкремента:" << endl;
    t1.out();
    cout << "Дискриминант: " << t1.get_D() << endl;
    t1.find_X();
    cout << "Значение от x = 7: " << t1.find_Y(7) << endl << endl;

    double a, b, c;
    cout << "Введите значения коэффициентов ур-ия" << endl;
    cin >> a >> b >> c;
    eq2 t2(a, b, c);
    t2.out();
    cout << "Введите значения коэффициентов ур-ия" << endl;
    cin >> a >> b >> c;
    t2.set(a, b, c);
    t2.out();
    t2.find_X();
    eq2 t3;
    t3 = t1 + t2;
    cout << "Сумма первых двух уравнений: " << endl;
    t3.out();
    t3.find_X();
    cout << "Значение от x = 3: " << t3.find_Y(3) << endl << endl;

    return 0;
}

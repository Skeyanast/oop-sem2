#include <iostream>
#include "rational.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество объектов: ";
    cin >> n;
    rational* mas = new rational[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        cout << "Введите числитель и знаменатель " << i + 1 << " дроби:" << endl;
        cin >> a >> b;
        mas[i].set(a, b);
    }

    cout << "Все введенные дроби:" << endl;
    for (int i = 0; i < n; i++) {
        mas[i].show();
    }

    //Демонстрация всех возможностей программы

    rational summa1;
    rational summa2;
    for (int i = 0; i < n; i++) {
        rational temp = mas[i];
        if (i % 2 == 0) {
            summa1 = summa1 + temp;
            summa2 = summa2 + temp;
        }
        else {
            summa1 = summa1 + temp;
            summa2 = summa2 - temp;
        }
    }

    cout << "\nСложение дробей по 2 принципам:\n" 
        << "Принцип 1: простое сложение всех дробей\n"
        << "Принцип 2: сложение дробей с четным номером и вычитание всех с нечетным (+-+-+...)" << endl;
    cout << "Итоговое значение сложения по 1 принципу:" << endl;
    summa1.show();
    cout << "Итоговое значение сложения по 2 принципу:" << endl;
    summa2.show();

    if (summa1 == summa2) {
        cout << "Итоговые значения равны" << endl;
    }
    else {
        if (summa1 > summa2) {
            cout << "Итоговое значение по первому принципу больше" << endl;
        }
        else cout << "Итоговое значение по второму принципу больше" << endl;
    }

    delete[] mas;

    return 0;
 }

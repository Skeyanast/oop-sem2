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
        cout << "Введите числитель и знаменатель " << i+1 << " дроби:" << endl;
        cin >> a >> b;
        mas[i].set(a, b);
    }

    cout << "Все введенные дроби:" << endl;
    for (int i = 0; i < n; i++) {
        mas[i].show();
    }

    delete[] mas;

    return 0;
 }

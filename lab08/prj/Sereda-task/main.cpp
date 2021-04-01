#include <iostream>
#include <windows.h>
#include <iomanip>
#include <clocale>
#include "ModulesSereda.h"

using namespace std;

void copyright_info();

int main()
{
    float x, z;
    char a, b;

    copyright_info();

    cout << "Введіть числа х та z." << endl;
    if(cin >> x >> z)
    {
        cout << "Введіть символи a та b." << endl;
        cin >> a >> b;

        cout << "Результат логічного виразу = " << bool(a + 7 < abs(b - 5)) << endl;
        cout << "Результат S в дестковій системі числення = " << s_calculation(x,z);
        cout << ", та у шістнадцятковій = " << hexfloat << s_calculation(x,z);
    }
    else cout << "Помилка! Невірно введені дані." << endl;
    system("pause");
    return 0;
}

void copyright_info()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    cout << "Розробник: Студент ЦНТУ факультету комп'ютерої інженерії Cереда Єгор" << endl;
    cout << "---------------------(б) All rights reserved--------------------------" << endl;
}

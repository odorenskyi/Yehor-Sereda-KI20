#include <iostream>
#include <windows.h>
#include <iomanip>
#include <wchar.h>
#include "ModulesSereda.h"
#include <fcntl.h>
#include <cmath>

using namespace std;

void copyright_info();


int main()
{
    float x, z;
    char a, b;


    copyright_info();
    wcout << L"Введiть 2 числа, будь-ласка." << endl;
    cin >> x >> z;
    while(isnan(s_calculation(x,z)) || x == NULL || z == NULL)
    {
        cin.clear();
        fflush(stdin);
        wcout << L"Помилка! невiрнi вхiднi данi. Будь-ласка, введiть числа," << endl;
        wcout << L"перше з яких бiльше -1 та не дорiвнює 0, а друге бiльше, або дорiвнює 0" << endl;
        cin >> x >> z;
    }
    wcout << L"Введiть два символа для порiвняння" << endl;
    cin >> a >> b;
    wcout << L"Результат логiчного виразу = " << bool(a + 7 < abs(b - 5)) << endl;
    wcout << L"Результат обчислення S у десятковому форматi= " << s_calculation(x,z) << endl;
    wcout << L"У шiстнадцятковому = " << hex << (int)s_calculation(x,z) << endl;
    system("pause");
    return 0;
}

void copyright_info()
{
    _wsetlocale(LC_ALL,L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);

    wcout << L"Розробник застосунка: студент ЦНТУ Середа Єгор Вiталiйович" << endl;
    wcout << L"----------------(с) All rights reserved-------------------" << endl;
}

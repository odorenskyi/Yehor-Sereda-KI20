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
    int x, z;
    unsigned char a, b;


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
    wcout << L"Результат логiчного виразу = ";
    wcout << bool(a + 7 < abs(b - 5)) << endl;
    wcout << L"Перше число в шiстнадцятковiй системi= " << hex << x << endl;
    wcout << L"Друге число в шiстнадцятковiй системi= " << hex << z << endl;
    wcout << L"Результат обчислення S = " << s_calculation(x,z) << endl;
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

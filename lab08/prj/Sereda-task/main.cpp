#include <iostream>
#include <windows.h>
#include <iomanip>
#include <clocale>
#include <wchar.h>
#include "ModulesSereda.h"
#include <io.h>
#include <fcntl.h>

using namespace std;

void copyright_info();

int main()
{
    float x, z;
    char a, b;

    copyright_info();

    wcout << L"Введіть 2 числа, будь-ласка." << endl;
    if(cin >> x >> z)
    {
        wcout << L"Введіть два символа для порівняння" << endl;
        cin >> a >> b;
        wcout << L"Результат логічного виразу = " << bool(a + 7 < abs(b - 5)) << endl;
        wcout << L"Результат обчислення S у десятковому форматі= " << s_calculation(x,z);
        wcout << L" У шістнадцятковому = " << hexfloat << s_calculation(x,z);
    }
    else cout << "Помилка! невірні вхідні дані." << endl;
    system("pause");
    return 0;
}

void copyright_info()
{
    _wsetlocale(LC_ALL,L" ");
    _setmode(_fileno(stdout), _O_U8TEXT);

    wcout << L"Розробник застосунка: студент ЦНТУ Середа Єгор Віталійович" << endl;
    wcout << L"----------------(с) All rights reserved-------------------" << endl;
}

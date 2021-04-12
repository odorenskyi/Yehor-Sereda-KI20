#include <iostream>
#include <math.h>
#include "ModulesSereda.h"
#include <wchar.h>
#include <fcntl.h>

using namespace std;

void copyright_info();
void clean_input();
void input_funct1();
void input_funct2();
void input_funct3();
void input_funct4();

int main()
{
    copyright_info();

    wchar_t sym;

    wcout << L"Вітаю! Будь-ласка, введіть символ для вибору операції:" << endl;
    do
    {
        wcout << L"Виконання функції s_calculation()(z)." << endl;
        wcout << L"Виконання функції для розрахунку надбавки заробітної плати працівникам(r)." << endl;
        wcout << L"Виконання функції для розрахунку надбавки температури за шкалою Цельсія та Фаренгейта(s)." << endl;
        wcout << L"Виконання функції для розрахунку кількості бітових чисел(t)." << endl;
        wcout << L"Вихiд з програми(q/Q)." << endl;
        wcin >> sym;
        if(sym == 'q' || sym == 'Q') return 0;
        else
            switch(sym)
            {
                case 'z':
                    wcout << L"Ви обрали функцію s_calculation()" << endl;
                    input_funct1();
                    break;
                case 'r':
                    input_funct2();
                    break;
                case 's':
                    input_funct3();
                    break;
                case 't':
                    input_funct4();
                    break;
                default:
                    wcout << L"Невiрно введений ключ, будь-ласка використайте запропонованi!\a";
                    clean_input();
                    break;
            }
    }
    while(true);

    return 0;
}

void copyright_info()
{
    _wsetlocale(LC_ALL,L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);

    wcout << L"Розробник застосунка: студент ЦНТУ Середа Єгор Вiталiйович" << endl;
    wcout << L"----------------(с) All rights reserved-------------------" << endl;
}

void clean_input()
{
    fflush(stdin);
    wcin.clear();
}

void input_funct1()
{
    float x,z;

    wcout << L"Введіть число, що включно більше -1 та не дорівнює 0" << endl;
    while(!(wcin >> x))
    {
        wcout << L"Помилка, невірні вхідні дані. Будь-ласка спробуйте ще раз." << endl;
        clean_input();
    }
    wcout << L"Введіть число, що більше 0 включно" << endl;
    while(!(wcin >> z))
    {
        wcout << L"Помилка, невірні вхідні дані. Будь-ласка спробуйте ще раз." << endl;
        clean_input();
    }
    if(!isnan(s_calculation(x,z)))
        wcout << L"Результат = " << s_calculation(x,z) << endl;
    else
    {
        wcout << L"Помилка, невалідні вхідні дані для роботи функції. Будь-ласка спробуйте ще раз." << endl;
        input_funct1();
    }
}

void input_funct2()
{
    float x, z;
    int y;
    wcout << L"Ви обрали функцію для розрахунку надбавки працівникам" << endl;
    wcout << L"Введіть число в інтервалі від 1 до 10347" << endl;
    while(!(wcin >> x))
    {
        wcout << L"Помилка, невірні вхідні дані. Будь-ласка спробуйте ще раз." << endl;
        clean_input();
    }
    wcout << L"Введіть число в інтервалі від 1 до 29999" << endl;
    while(!(wcin >> z))
    {
        wcout << L"Помилка, невірні вхідні дані. Будь-ласка спробуйте ще раз." << endl;
        clean_input();
    }
    wcout << L"Введіть число в інтервалі включно від 0 до 50" << endl;
    while(!(wcin >> y))
    {
        wcout << L"Введіть число в інтервалі від 1 до 29999" << endl;
        clean_input();
    }
    if(income_eval(x,z,y) != -1)
        wcout << L"Результат = " << income_eval(x,z,y) << endl;
    else
    {
        wcout << L"Помилка, невалідні вхідні дані для роботи функції. Будь-ласка спробуйте ще раз." << endl;
        input_funct2();
    }
}

void input_funct3()
{
    float arr[6];

    wcout << L"Введіть температури за градусами";
    wcout << L"Цельсія в інтервалі від -100 до 100 градусів о 00:00 04:00 08:00 12:00 16:00 20:00 годинах";
    for(int i = 0; i < 6; i++)
    {
        while(!(wcin >> arr[i]))
        {
            clean_input();
            wcout << L"Помилка! Будь-ласка, введіть заново 6 натуральних чисел\n";
            i = 0;
        }
    }
    if(!isnan(mid_temperature_celsius(arr)))
    {
        wcout << L"Результат за Цельсiєм = " << mid_temperature_celsius(arr) << endl;
        wcout << L"Результат за Фаренгейтом = " << mid_temperature_farengates(arr) << endl;
    }
    else
    {
        wcout << L"Помилка, невалідні вхідні дані для роботи функції. Будь-ласка спробуйте ще раз." << endl;
        input_funct3();
    }
}

void input_funct4()
{
    int N;

    wcout << L"Ви обрали функцію розрахунку кількості бітових чисел." << endl;
    wcout << L"Будь-ласка, введіть число в інтервалі від 0 до 10008000";
    wcout << L"для підрахунку бітових чисел залежно від 11 біту." << endl;
    while(!(wcin >> N))
    {
        wcout << L"Помилка, невірні вхідні дані. Будь-ласка спробуйте ще раз." << endl;
        clean_input();
    }
    if(bit_counter(N) != -1)
        wcout << bit_counter(N);
    else
    {
        wcout << L"Помилка, невалідні вхідні дані для роботи функції. Будь-ласка спробуйте ще раз." << endl;
        input_funct4();
    }
}

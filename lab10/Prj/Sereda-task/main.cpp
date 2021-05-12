#include <iostream>
#include "ModulesSereda.h"
#include <math.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

void clean_input();
void first_funct();
void second_funct();
void third_funct();

int main()
{
    wchar_t key;
    localisation();
    wcout << L"Вас вiтає програма обробки файлiв!";
    do
    {
        wcout << L"Будь-ласка, оберiть функцiю для обробки файлiв." << endl;
        wcout << L"1.Функцiя пiдрахунку кiлькостi приголосних та входження слова в краплинку.(a)" << endl;
        wcout << L"2.Функцiя додання дати до вхiдного файлу.(s)" << endl;
        wcout << L"3.Функцiя додання результату арифметичного обчислення.(d)" << endl;
        wcout << L"Для виходу натиснiть e/E" << endl;

        while(!(wcin >> key))
        {
            wcout << L"Помилка, невiрно введений ключ! Будь-ласка, спробуйте ще раз.";
            clean_input();
        }
        if(key == 'e' || key == 'E') return 0;
        switch(key)
        {
            case 'a':
                first_funct();
                break;
            case 's':
                second_funct();
                break;
            case 'd':
                third_funct();
                break;
            default:
                wcout << L"Невiрно введений ключ, будь-ласка використайте запропонованi!" << endl;
                break;
        }
    }
    while(true);
}

void clean_input()
{
    fflush(stdin);
    wcin.clear();
}

void first_funct()
{
    wchar_t input_file[100];
    wchar_t output_file[100];
    char conv1[100], conv2[100];

    wcout << L"Введiть назву вхiдного файлу з розширенням .txt" << endl;
    wcin >> input_file;
    const wchar_t * flag1 = input_file;
    wcstombs(conv1,flag1,sizeof(conv1));

    wcout << L"Введiть назву вихiдного файлу з розширенням .txt" << endl;
    wcin >> output_file;
    const wchar_t * flag2 = output_file;
    wcstombs(conv2,flag2,sizeof(conv2));
    create_file(conv1, conv2);
}

void second_funct()
{
    wchar_t input_file[100];
    char conv[100];

    wcout << L"Введiть назву вхiдного файлу з розширенням .txt" << endl;
    wcin >> input_file;
    const wchar_t * flag = input_file;
    wcstombs(conv, flag, sizeof(conv));

    input_time(conv);
}

void third_funct()
{
    wchar_t output_file[100];
    char conv[100];

    float x,z;
    int binary_int;

    wcout << L"Введiть число, що включно бiльше -1 та не дорiвнює 0" << endl;
    while(!(wcin >> x))
    {
        wcout << L"Помилка, невiрнi вхiднi данi. Будь-ласка спробуйте ще раз." << endl;
        clean_input();
    }
    wcout << L"Введiть число, що бiльше 0 включно" << endl;
    while(!(wcin >> z))
    {
        wcout << L"Помилка, невiрнi вхiднi данi. Будь-ласка спробуйте ще раз." << endl;
        clean_input();
    }
    if(isnan(s_calculation(x,z)))
    {
        wcout << L"Помилка, невалiднi вхiднi данi для роботи функцiї. Будь-ласка спробуйте ще раз." << endl;
        second_funct();
    }
    wcout << L"Введiть цiле число." << endl;
    while(!(wcin >> binary_int))
    {
        wcout << L"Помилка, невiрнi вхiднi данi. Будь-ласка спробуйте ще раз." << endl;
        clean_input();
    }
    wcout << L"Введiть назву вихiдного файлу з розширенням .txt" << endl;
    wcin >> output_file;
    const wchar_t * flag = output_file;
    wcstombs(conv, flag, sizeof(conv));
    calculation_write(x, z, binary_int, conv);
}

#include <math.h>
#include "ModulesSereda.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <codecvt>
#include <clocale>
#include <sstream>
#include <chrono>
#include <bitset>

using namespace std;

void testing_first_funct();
void wofstream_adder(char * input, char * output, wstring result, int key, wstring context = L" ");

void testing_second_funct();
void wofstream_adder2(char * f_name, wstring result, wstring context);

void testing_third_funct();
void wofstream_adder3(float x, float z, int binary_number , char * f_name, wstring context, wstring result);

int main()
{
    testing_first_funct();
    testing_second_funct();
    testing_third_funct();
}

///
///
///

char * input_file[8] = {"in_file1.txt", "In_file1.txt", "In_file2.txt", "In_file3.txt",
                        "In_file4.txt", "In_file5.txt", "In_file6.txt", "In_file7.txt"};

char * output_file[8] = {"Out_f1.txt", "Out_f2.txt", "Out_f3.txt", "Out_f4.txt",
                         "Out_f5.txt", "Out_f6.txt", "Out_f7.txt", "Out_f8.txt"};

wstring expected_res[8] ={L" ", L" ",
L"Розробник: Середа ЄгорЦентральноукраїнський національний технічний університетМісто Кропивницький, Україна 2021Кількість приголосних у слові: 4Входження слова у краплинку: не належитьУ файлі In_file2.txt міститься 6 символів.",
L"Розробник: Середа ЄгорЦентральноукраїнський національний технічний університетМісто Кропивницький, Україна 2021Кількість приголосних у слові: 20Входження слова у краплинку: не належитьУ файлі In_file3.txt міститься 30 символів.",
L" ", L" ",
L"Розробник: Середа ЄгорЦентральноукраїнський національний технічний університетМісто Кропивницький, Україна 2021Кількість приголосних у слові: 2Входження слова у краплинку: належитьУ файлі In_file6.txt міститься 4 символів.",
L"Розробник: Середа ЄгорЦентральноукраїнський національний технічний університетМісто Кропивницький, Україна 2021Кількість приголосних у слові: 0Входження слова у краплинку: не належитьУ файлі In_file7.txt міститься 3 символів."};

void testing_first_funct()
{
    for(int i = 0; i < 8; i++)
   {
       if(create_file(input_file[i], output_file[i]))
       {
           wifstream resulting_file (output_file[i]);
           resulting_file.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

           wstring data;
           wstring file_contents;

           while(getline(resulting_file, data))
           {
               file_contents += data;
           }
           resulting_file.close();
           wofstream_adder(input_file[i], output_file[i], expected_res[i], 1, file_contents);
       }
       else
       {
           wofstream_adder(input_file[i], output_file[i], expected_res[i], 0, L" ");
       }
   }
}

void wofstream_adder(char * input, char * output, wstring result, int key, wstring context)
{
    wofstream file;
    if(key)
    {
        file.open(output, ios::app);
        file.clear();
    }
    else
    {
        file.open(output);
    }
    file.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    file << L"\nВхідні параметри\n" << "1." << input << "\n2.";
    file << output << L"\nРезультат тестування: ";

    if(result == context)
        file << "Passed";
    else
        file << "Failed";
    file.close();
}

///
///
///

char * output_file2[2] = {"Out_f21.txt", "Out_f22.txt"};

wstring expected_res2[2] ={L"себеКількість символів у файлі: 4Дата:Sun May 10 14:18:52 2021",
L"Кількість символів у файлі: 0Дата:Sun May 10 14:18:52 2021"};

void testing_second_funct()
{
   for(int i = 0; i < 2; i++)
   {
           input_time(output_file2[i]);
           wifstream resulting_file (output_file2[i]);
           resulting_file.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

           wstring data;
           wstring file_contents;

           while(getline(resulting_file, data))
           {
               file_contents += data;
           }
           resulting_file.close();
           wofstream_adder2(output_file2[i], expected_res2[i], file_contents);
   }
}

void wofstream_adder2(char * f_name, wstring result, wstring context)
{
    wofstream file;
    file.open(f_name, ios::app);

    file.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    file << L"\nВхідні параметри\n" << L"\nFile: " <<  f_name;
    file << L"\nРезультат тестування: ";

    if(result == context)
        file << "Passed";
    else
        file << "Failed";
    file.close();
}


///
///
///


float x[8] = {1, 71, 25};

float z[8] = {1, 100, 25};

int  binary_num[8] = {100, -1, 5};

char * output_file3[8] = {"Out_f11.txt", "Out_f12.txt", "Out_f13.txt"};

wstring expected_res3[8] ={L"Результат виконання функцiї s_calculation: 1Число b у двiйковому форматі: 01100100",
L"Результат виконання функцiї s_calculation: 10Число b у двiйковому форматі: 11111111",
L"Результат виконання функцiї s_calculation: 5Число b у двiйковому форматі: 00000101"};

void testing_third_funct()
{
   for(int i = 0; i < 3; i++)
   {
           calculation_write(x[i], z[i], binary_num[i], output_file3[i], 1);
           wifstream resulting_file (output_file3[i]);
           resulting_file.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

           wstring data;
           wstring file_contents;

           while(getline(resulting_file, data))
           {
               file_contents += data;
           }
           resulting_file.close();
           wofstream_adder3(x[i], z[i], binary_num[i], output_file3[i], file_contents, expected_res3[i]);
   }
}

void wofstream_adder3(float x, float z, int binary_number , char * f_name, wstring context, wstring result)
{
    wofstream file;
    file.open(f_name, ios::app);


    file.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    file << L"\nВхідні параметри\n" << L"x = " << x << L"\nz = " << z;
    file << L"\nBinary_num = " << binary_number << L"\nFile: " <<  f_name << L"\nРезультат тестування: ";

    if(result == context)
        file << "Passed";
    else
        file << "Failed";
    file.close();
}

#include <math.h>
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

float s_calculation(float x, float z)
{
    float S;
    const float pi = 3.14;
    /* Валідація. Якщо x більше -1 та не дроівнює нулю та z більше або дорівнює 0,
    то тоді проводиться обчислення, інакше повертається значення помилки */
    if(x > -1 && x != 0 && z >= 0)
    {
        // формула, за якою обчислюється результат
        S =  round(sqrt(z) - (sqrt(1 + x) - 3 * cos(x)) / (pow(x,2) + sin(pi * x)));
        return (int)S;
    }
    else
    {
        return nan("");         // значення помилки, якщо валідація не пройшла успішно
    }
}

float income_eval(float x, float z, int y)
{
    if(x > 0 && x < 10348 && z > 0 && z < 30000 && y >= 0 && y <= 50)
    {
        if (y >= 3 && y < 5) x = x * 10 / 100;
        else if (y >= 5 && y < 7) x = x * 15 / 100;
        else if (y >= 7 && y < 15) x = x * 20 / 100;
        else if (y >= 15) x = x * 25 / 100;
        else x = 0;

        return z + x;
    }
    return -1;
}

float mid_temperature_celsius(float t_arr[6])
{
    float result;

    for(int i = 0; i < 6; i++)
        if(t_arr[i] >= -100 && t_arr[i] <= 100) result += t_arr[i];
        else return nan("");

    result /= 6;
    result = result*100 + 0.5;
    result = int(result);
    result /= 100;
    return result;
}

float mid_temperature_farengates(float t_arr[6])
{
    float result = 0;
    result = mid_temperature_celsius(t_arr) / 5 * 9 + 32;
    return result;
}

int bit_counter(int N)
{
    if(N < 0 || N > 10008000) return -1;
    else
    {
        bool D11 = (N>>11)&1? 1: 0;
        int count_bites = 0;
        while(N != 0)
        {
            if((N & 1) == D11) ++count_bites;
            N >>= 1;
        }
        return count_bites;
    }
}


void localisation()
{
    setlocale(LC_ALL,"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

int validation(wstring check)
{
    if(check.length() < 1)
    {
        wcout << L"Помилка! Пустий файл." << endl;
        return 0;
    }
    else if(check.length() > 30)
    {
        wcout << L"Помилка! Занадто довге речення." << endl;
        return 0;
    }
    for(int i = 0; check[i] != '\0'; i++)
    {
        if(iswalpha(check[i]) == 0 && check[i] != '`')
        {
            wcout << L"Помилка! Слово мiстить невiрнi символи." << endl;
            return 0;
        }
    }
    return 1;
}

int create_file(char * exist_file, char * output_file)
{
    localisation();

    int iter = 0;
    wstring word, check_word , data;

    wchar_t symbols[] = { L'ц', L'к', L'н', L'г', L'ш', L'щ', L'з', L'х', L'ф', L'в', L'п',
                        L'р', L'л', L'д', L'ж', L'ч', L'с', L'м', L'т', L'б'};

    wchar_t kraplinka[] = L"Про себе не кажи недобрих слів,\nБо має сказане таємну силу.\nКажи: «Я сильний, впевнений, щасливий!»\nІ буде саме так, як ти хотів!";

    wifstream stream;
    stream.open(exist_file);
    if(stream.is_open())
    {
        stream.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
        while(getline(stream, word))
        {
            if(iter == 0)
            {
                check_word = word;
                iter++;
            }
            data += word;
        }
        stream.close();

        if(!validation(check_word))
            return 0;

        iter = 0;
        for(int i = 0; check_word[i] != '\0'; i++)
            for(int j = 0; j < 20; j++)
                if(check_word[i] == symbols[j]) iter++;
    }
    else
    {
        wcout << L"Помилка вiдкриття файлу!" << endl;
        return 0;
    }
    wofstream input;
    input.open(output_file);
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input << L"Розробник: Середа Єгор\n"
          << L"Центральноукраїнський національний технічний університет\n"
          << L"Місто Кропивницький, Україна 2021\n"
          << L"Кількість приголосних у слові: " << iter << "\n";

    if(wcsstr(kraplinka,word.c_str())) input << L"Входження слова у краплинку: належить";
    else input << L"Входження слова у краплинку: не належить";

    input << L"\nУ файлі " << exist_file << L" міститься " << data.length() << L" символів.\n";
    input.close();
    wcout << L"Файл був успiшно оброблений. Завершення виконання функцiї create_file." << endl;
    return 1;
}

int input_time(char *exist_file)
{
    localisation();

    wifstream stream;
    wofstream output;
    wstring word;

    time_t cur_date = time(0);

    stream.open(exist_file);
    if(stream.is_open())
    {
       stream.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
       getline(stream, word);
       stream.close();

       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << word << L"\nКількість символів у файлі: " << word.length() << L"\nДата:" << ctime(&cur_date);
       output.close();
    }
    else
    {
       output.open(exist_file);
       output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

       output << word << L"\nКількість символів у файлі: " << word.length() << L"\nДата:" << ctime(&cur_date);
       output.close();
    }
    wcout << L"Файл був успiшно оброблений. Завершення виконання функцiї input_time." << endl;
    return 1;
}

int calculation_write(float x, float z, int b, char * exist_file, int clear_file = 0)
{
    localisation();

    wofstream input;
    if(clear_file)
        input.open(exist_file);
    else
        input.open(exist_file, ios::app);

    if(input.is_open())
    {
        input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
        input << L"Результат виконання функцiї s_calculation: " << s_calculation(x, z) << L"\nЧисло b у двiйковому форматі: " <<  bitset<8>(b).to_string().c_str();
        input.close();
        wcout << L"Файл був успiшно оброблений. Завершення виконання функцiї calculation_write." << endl;
    }
    else
    {
        wcout << L"Помилка вiдкриття файлу!" << endl;
        return 0;
    }
    return 1;
}


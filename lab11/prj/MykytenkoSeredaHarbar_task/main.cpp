#include <vector>
#include <iostream>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <clocale>
#include <windows.h>
#include <codecvt>
#include <cctype>
#include <ctime>
#include <math.h>
using namespace std;

wstring stages[5] = {L"Розділ 1; Живі тварини; продукти тваринного походження",
                     L"Розділ 2; Продукти рослинного походження",
                     L"Розділ 3; Жири та олії тваринного або рослинного походження; продукти їх розщеплення; готові харчові жири; воски тваринного або рослинного походження",
                     L"Розділ 4; Готові харчові продукти; алкогольні та безалкогольні напої і оцет; тютюн та його замінники",
                     L"Розділ 5; Мінеральні продукти"};

wstring section01[5] = {L"\tГрупа 1 - Живі тварини", L"\tГрупа 2 - М\'ясо та їстівні субпродукти", L"\tГрупа 3 - Риба та їстівні субпродукти",
                        L"\tГрупа 4 - Молоко та молочні продукти; їстівні продукти тваринного походження, в іншому  місці не зазначені",
                        L"\tГрупа 5 - Інші продукти тваринного походження, в іншому місці не зазначені"};

wstring section02[6] = {L"\tГрупа 6 - Живі дерева та інші рослини; цибулини, коріння та інші аналогічні частини рослин",
                        L"\tГрупа 7 - Овочі та деякі їстівні коренеплоди і бульби",
                        L"\tГрупа 8 - Їстівні плоди та горіхи; шкірки цитрусових або динь",
                        L"\tГрупа 9 - Кава, чай, мате, або парагвайський чай, прянощі",
                        L"\tГрупа 10 - Зернові культури",
                        L"\tГрупа 11 - Продукція борошномельно-круп\'яної промисловості; солод, крохмалі; інулін; пшенична клейковина"};

wstring section03[1] = {L"\tГрупа 12 - Жири та олії тваринного або рослинного походження; продукти їх розщеплення; готові харчові жири; воски тваринного або рослинного походження"};

wstring section04[9] = {L"\tГрупа 13 - Готові харчові продукти з м'яса, риби або ракоподібних, молюсків або інших водяних безхребетних",
                        L"\tГрупа 14 - Цукор і кондитерські вироби з цукру; Какао та продукти з нього",
                        L"\tГрупа 15 - Готові продукти із зерна зернових культур, борошна, крохмалю або молока; борошняні кондитерські вироби",
                        L"\tГрупа 16 - Продукти переробки овочів, плодів або інших частин рослин",
                        L"\tГрупа 17 - Різні харчові продукти; Алкогольні і безалкогольні напої та оцет",
                        L"\tГрупа 18 - Залишки і відходи харчової промисловості; готові корми для тварин",
                        L"\tГрупа 19 - Тютюн і промислові замінники тютюну"};

wstring section05[3] = {L"\tГрупа 20 - Сіль; сірка; землі та каміння; штукатурні матеріали, вапно та цемент",
                        L"\tГрупа 21 - Руди, шлаки та зола",
                        L"\tГрупа 22 - Палива мінеральні; нафта та продукти її перегонки; бітумінозні речовини; воски мінеральні"};

struct product //глобальная переменная структуры с товаром
{
    int code;
    wstring name;
};

struct section //глобальная переменная структуры с разделами
{
    wstring groupName;
    int groupPos;
    vector<struct product> groups;
};

vector<struct section> sections; //глобальная переменная вектора разделов
vector<wstring> section1;
vector<wstring> section2;
vector<int> groupsAmount;

wstring nameGetter(wstring place) //возвращаем имя группы или имя товара(в зависимости от аргумента)
{
    wstring name;
    wcout << L"Введіть назву " << place << L": ";
    wcin >> name;
    return name;
}

int posGetter(wstring place) //возвращаем код группы или позицию товара(в зависимости от аргумента)
{
    int position;
    wcout << L"Введіть номер " << place << L": ";
    wcin >> position;
    return position;
}
product productsGetter(int iter) //возвращаем структуру
{
    product example;
    example.code = iter;
    example.name = nameGetter(L"товару");
    return example;
}

product defaultGroup(wstring name, int iter)
{
    product example;
    example.code = iter;
    example.name = name;
    return example;
}

void clean_input()
{
    fflush(stdin);
    wcin.clear();
}

wstring find_group_by_code(int code) //костыль тот же, но это работает правильно, теперь точно
{
    /*Входной параметр функции - код группы.
      Поиск осуществляется по функции поиска подстроки.*/
    wifstream output;
    output.open("result.txt");
    output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>)); //локализация файлового потока
    wstring line;
    if(code == 1)
    {
        for(int i = 0; i < 2; i++)
            getline(output, line);
        return line;
    }
    while(getline(output, line))
    {
        if(wcsstr(line.c_str(), to_wstring(code).c_str())) break;  //Если номер группы присутствует в строке, тогда присвоить его результирующему стрингу
    }
    output.close();
    return line;
}

int defaultFiller(int iterator)
{
    wofstream output; //создание объекта для записи в файл
    output.open("result.txt");
    output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>)); //локализация файлового потока

    for(int i = 0; i < 5; i++)
    {
        section1.push_back(section01[i]);
    }
    for(int i = 0; i < 6; i++)
    {
        section2.push_back(section02[i]);
    }
    section A;
    A.groupName = stages[0];
    A.groupPos = groupsAmount.size() + 1;
    for(unsigned long long i = 0; i < section1.size(); i++) //инициализация раздела 1 дефолтными значениями
    {
        iterator++;
        A.groups.push_back(defaultGroup(section1[i], iterator));
    }
    sections.push_back(A); //возвращаем структуру раздела 1 в вектор
    groupsAmount.push_back(groupsAmount.size()+1);
    output << A.groupName << endl;

    for(unsigned long long i = 0; i < section1.size(); i++)
        output << section01[i] << endl;

    section B; //структура раздела 2
    B.groupName = stages[1];
    B.groupPos = groupsAmount.size()+1;

    for(unsigned long long i = 0; i < section2.size(); i++) //инициализация раздела 1 дефолтными значениями
    {
        iterator++; //итератор мы тоже не трогаем, он работает как надо
        B.groups.push_back(defaultGroup(section2[i], iterator));
    }
    sections.push_back(B); //возвращаем структуру раздела 2 в вектор
    groupsAmount.push_back(groupsAmount.size()+1);
    output << B.groupName << endl;
    for(unsigned long long i = 0; i < section2.size(); i++)
        output << section02[i] << endl;
    return iterator;
}

int indexGetter(int a) // функция для определения индекса строки(для итерационного поиска, не трогай, всё работает)
{
    wifstream input;
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input.open("result.txt");
    wstring cop;
    int index = 0;
    while(getline(input,cop))
    {
        index++;
        if(cop == find_group_by_code(a))
            break;
    }
    return index;
}

void delete_string(int a) //функция ясночего(не трогай, всё работает)
{
    wifstream input;
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input.open("result.txt");

    wofstream memory;
    memory.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    memory.open("temp.txt");

    wstring cop, group_str = L"\tГрупа ";

    for(int i = 0; getline(input,cop); i++)
    {
       for(int j=0;j<5;j++)
           if(cop==stages[j]){
               memory<<cop<<endl;
               continue;
           }
       if(wcsstr(cop.c_str(),group_str.c_str()))
           if(i!=indexGetter(a)-1)
               memory<<cop<<endl;
    }
    input.close();
    memory.close();
    remove("result.txt");
    rename("temp.txt","result.txt");
}

wstring show_file()    //функция вывода содержимого файла
{
    wifstream input;
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input.open("result.txt");
    wstring line;
    wstring copys;
    if(!input.is_open()){
        wcout<<L"Файл не існує, або не вдалося знайти";
    }
    while (getline(input, line))
    {
        copys+=line;
        copys.push_back('\n');
    }
    input.close();
    return copys;
}
wstring add_group_to_section(wstring data, wstring *groups, int size_of_arr)    //функция добавления группы к новому раздел
{
    int number_of_group = 0, stored_values[size_of_arr], iter = 0, flag = 0;
    wchar_t key;

    do
    {
        for(int i = 0; i < size_of_arr; i++)
        {
            if(i != stored_values[i]) wcout << groups[i] << endl;
        }
        wcout << L"Введіть номер групи, що ви бажаєте додати від 1 до " + to_wstring(size_of_arr) + L':';
        wcin >> number_of_group;    //нужна валидация
        for(int i = 0; i < size_of_arr; i++)
        {
            if(number_of_group == stored_values[i])
            {
                wcout << L"Помилка додавання групи! Дана група вже присутня у файлі." << endl;
                flag++;
                break;
            }
        }
        if(iter < size_of_arr && flag == 0)
        {
            if(!(wcsstr(data.c_str(), groups[number_of_group - 1].c_str())))
            {
                stored_values[iter] += number_of_group;
                data += L'\n' + groups[number_of_group - 1];
                wcout << L"Група була успішно добавлена!" << endl;
            }
            else
            {
                wcout << L"Помилка додавання групи! Дана група вже присутня у файлі." << endl;
            }
        }
        wcout << L"Чи бажаєте ви додати ще одну группу?(y = так, n = ні):";
        wcin >> key; //нужна валидация
        iter++;
    }
    while(key != L'n');
    return data;
}

int add_section()   //функция добавления раздела
{
    wstring line, data;
    int number;
    wcout << L"Введіть номер розділу, що ви бажаєте додати до файлу:";
    while(!(wcin >> number) || (number < 1 || number > 5))
    {
        wcout << L"Помилка додавання розділу. Будь-ласка, введіть число від 1 до 5" << endl;
        clean_input();
    }
    wifstream input;
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>)); //локализация файлового потока
    input.open("result.txt");

    while(getline(input, line))
    {
        data += line;
        data.push_back(L'\n');
    }
    input.close();

    if(!(wcsstr(data.c_str(), stages[number-1].c_str())))
    {
        data += stages[number-1];
    }
    else
    {
        wcout << L"Помилка додавання розділу! Даний розділ вже присутній у файлі.";
        return 0;
    }
    switch(number)
    {
    case 1: data = L'\n' + add_group_to_section(data, section01, 5) + L'\n'; break;
    case 2: data = L'\n' + add_group_to_section(data, section02, 6) + L'\n'; break;
    case 3: data = L'\n' + add_group_to_section(data, section03, 1) + L'\n'; break;
    case 4: data = L'\n' + add_group_to_section(data, section04, 9) + L'\n'; break;
    case 5: data = L'\n' + add_group_to_section(data, section05, 3) + L'\n'; break;
    default: break;
    }
    wofstream output;
    output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    output.open("result.txt");
    output << data;
    output.close();
    return 1;
}

void add_group() // функция добавления группы в файл
{
    int number, number_of_group, size_arr, occurrences = 0;
    wstring *arr, line, data;
    wstring::size_type pos = 0;
    wcout << L"Введіть номер розділу, з якого ви бажаєте взяти группу:";
    while(!(wcin >> number) || (number < 1 || number > 5))
    {
        wcout << L"Помилка додавання розділу. Будь-ласка, введіть число від 1 до 5" << endl;
        clean_input();  //функция очистки буфера от хлама
    }
    switch(number)
    {
    case 1: arr = section01; size_arr = 5; break;
    case 2: arr = section02; size_arr = 6; break;
    case 3: arr = section03; size_arr = 1; break;
    case 4: arr = section04; size_arr = 9; break;
    case 5: arr = section05; size_arr = 3; break;
    default: break;
    }
    wcout << L"Введіть номер группи від 1 до " + to_wstring(size_arr) + L':';
    while(!(wcin >> number_of_group) || (number_of_group < 1 || number_of_group > size_arr))
    {
        wcout << L"Помилка! Невірні вхідні дані. Введіть номер групи, що ви бажаєте додати від 1 до " + to_wstring(size_arr) + L':';
        clean_input();
    }
    wifstream input;
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input.open("result.txt");
    while(getline(input, line))
    {
        data += line;
        if(line == arr[number_of_group-2])
        {
            data.push_back(L'\n');
            data += arr[number_of_group-1];
        }

        data.push_back(L'\n');
    }
    input.close();
    while ((pos = data.find(arr[number_of_group-1], pos )) != string::npos)
    {
        ++ occurrences;
        pos += arr[number_of_group-1].length();
        wcout << occurrences;
    }
    if(occurrences == 1)
    {
        wofstream output;
        output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
        output.open("result.txt");
        output << data;
        output.close();
    }
    else
        wcout << L"Помилка, дана група вже присутня в файлі!" << endl;
}

void delete_section()
{
    wstring data, line, delete_str, *arr;
    int size_arr, number;

    wifstream input;
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input.open("result.txt");

    wcout << L"Введіть номер розділу, який ви бажаєте видалити:";
    while(!(wcin >> number) || (number < 1 || number > 5))
    {
        wcout << L"Помилка додавання розділу. Будь-ласка, введіть число від 1 до 5:";
        clean_input();  //функция очистки буфера от хлама
    }
    switch(number)
    {
    case 1: arr = section01; size_arr = 5; break;
    case 2: arr = section02; size_arr = 6; break;
    case 3: arr = section03; size_arr = 1; break;
    case 4: arr = section04; size_arr = 9; break;
    case 5: arr = section05; size_arr = 3; break;
    default: break;
    }
    while(getline(input, line))
    {
        data += line;
        data.push_back(L'\n');
    }
    input.close();

    data.erase(data.find(stages[number - 1] + L'\n'), delete_str.size());
    for(int i = 0; i < size_arr; i++)
    {
        delete_str = arr[i] + L'\n';
        data.erase(data.find(arr[i]), delete_str.size());
    }

    wofstream output;
    output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    output.open("result.txt");
    output << data;
    output.close();
}
void fullfillDefault()
{
    wofstream output; //создание объекта для записи в файл
    output.open("result.txt");
    output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>)); //локализация файлового потока

    output << stages[0] << endl;
    output << section01[0] << endl << section01[1] << endl << section01[2] << endl << section01[3] << endl << section01[4] << endl;

    output << stages[1] << endl;
    output << section02[0] << endl << section02[1] << endl << section02[2] << endl << section02[3] << endl << section02[4] << endl << section02[5] << endl;

    output << stages[2] << endl;
    output << section03[0] << endl;

    output << stages[3] << endl;
    output << section04[0] << endl << section04[1] << endl << section04[2] << endl << section04[3] << endl << section04[4] << endl << section04[5] << endl << section04[6] << endl << section04[7] << endl << section04[8];

    output << stages[4] << endl;
    output << section05[0] << endl << section05[1] << endl << section05[2] << endl;

    output.close();
}


int main()
{
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    wchar_t checkbox;
    wcout<<L"Електроний довідник версія 1.0\nРозробники:Гарбар Вадим, Микитенко Даниїл,Єгор Середа.\n";
    while(true){
        wcout<<L"---------Виберіть дію----------\n";
        wcout<<L"Введіть a для відображення довідника\n";
        wcout<<L"Введіть b для видалення вмісту розділу\n";
        wcout<<L"Для додавання групи до розділу введіть с\n";
        wcout<<L"Введіть e для повного заповнення\n";
        wcout<<L"Введіть q для повернення до початкового стану\n";
        wcout<<L"Введіть d для додавання розділу із групами\n";
        wcout<<L"Введіть v для пошуку групи\n";
        wcout<<L"Введіть r для видалення групи\n";
        wcout<<L"Введіть x для виходу із программи\n";
        wcout<<L"==========>";
        wcin>>checkbox;
        switch (checkbox) {
        case 'a':
        {
            wcout<<show_file();
            break;
        }
        case 'b':
        {
            delete_section();
            break;
        }
        case 'c':
        {
            add_group();
            break;
        }
        case 'q':
        {
            int iterator = defaultFiller(0);
            break;
        }
        case 'd':
        {
            add_section();
            break;
        }
        case 'e':
        {
            fullfillDefault();
            break;
        }
        case 'r':
        {
            int a=0;
            wcout<<L"====>";
            wcin>>a;
            delete_string(a);
            break;
        }
        case 'v':
        {
            int a=0;
            wcout<<L"====>";
            wcin>>a;
           wcout<<find_group_by_code(a);
           break;
        }
        case 'x':
        {
            return 0;
            break;
        }
        }
    }
    system("pause");
    return 0;
}

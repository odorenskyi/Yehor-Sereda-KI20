#include <cmath>
#include "ModulesSereda.h"

float s_calculation(float x, float z)
{
    float S;
    const float pi = 3.14;
    /* Якщо x більше -1 та не дроівнює нулю та z більше або дорівнює 0,
    то тоді проводиться обчислення */
    if(x > -1 && x != 0 && z >= 0)
    {
        S =  sqrt(z) - (sqrt(1 + x) - 3 * cos(x)) / (pow(x,2) + sin(pi * x));
        S = (int)(S * 1000);            // приведення результату до тисячної частини
        return S / 1000;
    }
    else
    {
        return nan("");         // значення помилки, якщо валідація не пройшла успішно
    }
}



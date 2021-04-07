#include <cmath>
#include "ModulesSereda.h"

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
        return S;
    }
    else
    {
        return nan("");         // значення помилки, якщо валідація не пройшла успішно
    }
}



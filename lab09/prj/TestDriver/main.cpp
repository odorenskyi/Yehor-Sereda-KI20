#include <iostream>
#include <math.h>
#include <iomanip>
#include "ModulesSereda.h"

using namespace std;

void TestDriver(float result, float exp_result);

int main()
{
    float x_val[] = {2500, 2500, 500, 2500, 3065, 10347, 5000, 5000,  8000, 10000};
    float z_val[] = {3678, 3678, 1275, 3000, 1480, 1480, 7000, 27000, 10000, 29999};
    int y_val[] = {3, 5, 2, 4, 1, 6, 20, 7, 15,  16};

    float exp_result1[] = {3928, 4053, 1275, 3250, 1480, 3032.05, 8250, 28000, 12000, 32499};

    cout << "*income_eval funct test*" << endl;
    for(int i = 0; i < 10; i++)
    {
        float result = income_eval(x_val[i], z_val[i], y_val[i]);
        cout << i+1 << '.' << "x = " << x_val[i] << ", z = " << z_val[i] << ", y = " << y_val[i];
        TestDriver(result, exp_result1[i]);
        cout << "Result = " << result << endl;
    }

    int N[8] = {125, 3000, 3100, 1, 10008000, 213126};
    int exp_result3[8] = {1, 5, 5, 0, 10, 12};

    cout << "\n*bit_counter funct test*" << endl;
    for(int i = 0; i < 6; i++)
    {
        int result = bit_counter(N[i]);
        cout << i+1 << '.' << "N = " << N[i];
        TestDriver(result, exp_result3[i]);
        cout << "Result = " << result << endl;
    }

    float temp[5][6] = { {25, 32.7, 35.5, 36.7, 30.8, 29 },
                       {-3, -1, 0.5, 3.6, 3.4, 3},
                       {10, 10, 10, 10, 10, 10},
                       {25, 64, 99.9, 27, 17, 2},
                       {-25, -100, -36, -57, -17, 0} };
    float exp_result2[5][2] = { {31.62, 88.916},
        {1.08, 33.944}, {10, 50}, {39.15, 102.47}, {-39.16, -38.488}};

    for(int i = 0; i < 5; i++)
    {
        float result1 = mid_temperature_celsius(temp[i]);
        float result2 = mid_temperature_farengates(temp[i]);
        cout << i+1 << '.' <<  "Input" << endl;
        cout << "Temperature " << 1 << " = " << temp[i][0];
        for(int j = 1; j < 6; j++)
            cout  << ", " << j+1 << " = " << temp[i][j];

        cout << endl;
        cout << "Tc = " << mid_temperature_celsius(temp[i]);
        TestDriver(result1, exp_result2[i][0]);

        cout << "Tf = " << mid_temperature_farengates(temp[i]);
        TestDriver(result2, exp_result2[i][1]);
    }
    getchar();
    return 0;
}

void TestDriver(float result, float  exp_result)
{
    if(result == exp_result)
            cout  << ": Passed" << endl;
    else
            cout << ": Failed" << endl;
}

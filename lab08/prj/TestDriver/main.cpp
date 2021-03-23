#include <iostream>

#include "ModulesSereda.h"

using namespace std;

int main()
{
    float x_val[] = {1,8,0,-1,17,25,71,-0.9};
    float z_val[] = {1,4,3,25,-5,25,100,16};

    float S[] = {1.206,1.946,0,0,0,4.996,9.998,7.099};

    for(int i = 0; i < 8; i++)
    {
        float result = s_calculation(x_val[i],z_val[i]);
        cout << i+1 << '.' << "x = " << x_val[i] << ", y = " << z_val[i];
        if(result == S[i] || (result != result && S[i] == 0))
        {
            cout  << ": Passed" << endl;
        }
        else
        {
            cout << ": Failed" << endl;
        }
        cout << "Result = " << s_calculation(x_val[i],z_val[i]) << endl;
    }
    getchar();
    return 0;
}

#include <iostream>

#include "ModulesSereda.h"

using namespace std;

int main()
{
    float x_val[] = {1,8,0,-1,17,25,71,-0.9};
    float z_val[] = {1,4,3,25,-5,25,100,16};

    int S[] = {1,2,0,0,0,5,10,7};

    for(int i = 0; i < 8; i++)
    {
        int result = s_calculation(x_val[i],z_val[i]);
        cout << i+1 << '.' << "x = " << x_val[i] << ", y = " << z_val[i];
        if(result == S[i] || (result != S[i] && S[i] == 0))
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

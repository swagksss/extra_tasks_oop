#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x=1;
    float array[10];
    for (int i = 1; i < 10; i++)
    {
        array[i] = exp(x) - pow(x, 3);
        x += 2;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << " y = "<< array[i] << endl;
    }
    }



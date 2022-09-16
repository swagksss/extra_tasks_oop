#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int array[3][3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Ряд : " << i + 1 << endl;
        for (int j = 0; j < 3; j++)
        {
            cin >> array[i][j];
        }
    }

    cout << endl << "Матрица" << endl << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "   "<< array[i][j];
        }
        cout << endl << endl;
    }

    
    int minor[4];
    int index, minor_value, algebra;
    for (int p = 0; p < 3; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            cout << " Элемент номер : " << p + 1 << q + 1  << endl;
            index = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i == p)
                    continue;

                for (int j = 0; j < 3; j++)
                {
                    if (j == q)
                    {
                        continue;
                    }
                    minor[index] = array[i][j];
                    index++;

                }
            }
            minor_value = minor[0] * minor[3] - minor[1] * minor[2];
            algebra = pow(-1, (p + q)) * minor_value;
            cout << " Минор : " << minor_value << endl;
            cout << " Алгебраическое дополнение : " << algebra << endl << endl;
        }
    }
    return 0;
}

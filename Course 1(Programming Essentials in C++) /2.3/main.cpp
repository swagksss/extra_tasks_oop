#include <iostream>
using namespace std;
int getint(char *s)
{
    int res = 0;
    while (*s) {
        res = 10;
        res += *s++ - '0';
    }

    return res;
}
int main() {
int sum = 0;
int size = 0;
char* arr = new char[size];
cout << "Введите числа : " << endl;
while (true)
{
char *a = new char;
cin >> a;
if (*a == 'x')
    break;
arr[size - 1] = *a;
size++;
sum += getint(a);
}
cout << " ----------------------- " << endl;
cout <<"Сумма : "<< sum << endl;
delete[]arr;
return 0;
}

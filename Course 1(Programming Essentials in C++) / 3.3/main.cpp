//Написать функцию, заполняющую массив случайными числами. Написать функцию, удаляющую из массива все значения больше среднего арифметического числа в массиве. Задействовать две функции. Вывести массив.

#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
 
using namespace std;

double ArithmeticalMean(int a[], int count)
{
    double sum = 0 ;
    int sred;
    for (int i = 0; i < count; i++)
       sum = sum + a[i];
    sred = sum / count;
    cout<<"\nСреднее арифметическое :"<<sred << endl;
    
    int temp = 0;
    for (int i = 0; i < count; i++)
        {
            if (a[i] <= sred)
            {
            
                temp++;
            }
        }
    cout <<"Количество чисел в массиве меньше СА : " << temp << endl;
    cout << "Новый массив : ";
    for (int i = 0; i < count; i++)
        {
            if (a[i] <= sred)
            {
                cout << a[i] << " " ;
            }
            
        }
    

    delete []a;
    return 0;
}
 

//генерируем целый случайный массив
void int_massiv()
{

    int n;
    cout <<"Введите размерность массива: ";
    cin >> n;
    

    int* a = new int[n];

    cout <<"Массив со случайными числами: ";
    
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа //srand - Это инициализация генератора случайных чисел, time - возвращает текущее календарное время системы, в качестве аргумента она принимает указатель на переменную типа time_t, которой и будет присвоено календарное время.//static_cast — это шаблон функции, в которой необходимо явно указать  тип данных для преобразования, то есть задать параметр шаблона.
    
    
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100;
            cout << a[i] << " ";
        }
    cout << endl;
    
    cout<<ArithmeticalMean(a, n)<<endl;
}
 
int main()
{
   int_massiv();
   cout<<"\n";
}

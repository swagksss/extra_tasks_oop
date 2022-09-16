#include <iostream>
using namespace std;

int main() {

    int mas[12];
    cout << "Введите числа :" << endl;
    for (int j = 0; j < 12; j++) {
        
        cin >>  mas[j];
    }
    int size = 0;
    int* din = new int[size];//*din-это указатель на выделеный участок памяти под массив динамически выделяем память под массив .Используем оператор new[] для выделения массива
    for (int i = 0; i < 12; i++) {
        if (mas[i] >  (- 5)) {
            din[++size - 1] = mas[i]; // увеличен размер массива , -1 это занятое место массивом одновымерным.
        }
    }
    cout << " ------------------------------" << endl;
    cout << "Числа больше ( - 5 ) :  ";
    for (int i = 0; i < size; i++) {
        cout << din[i] <<" ; ";
        
    }
    cout << endl<<endl;
    delete[] din; // используем оператор delete[] для освобождения выделенной массиву памяти
    return 0;
}

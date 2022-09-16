
#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
 
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
        int q =rand()%5;
        int w =rand()%5;
        int e =rand()%5;
        int r =rand()%5;
        int t =rand()%5;
    cout << q<<" "<<w<<" "<<e<<" "<<r<<" "<<t<<endl;
       
    int k;
    char a[1000]; //масив для записи предложений
    int size =1000;//размер динамического масива
    char* arr[5]; // создаем масив в который будем записывать слова из предложений
    string *vivod1= new string[size]; //создаем динамический масив из строк в который будем записывать ответ
    string *vivod2= new string[size];
    string *vivod3= new string[size];
    string *vivod4= new string[size];
    string *vivod5= new string[size];
    string *predlogeniye= new string[size];
    char* str ;// указатель а символ в строке
    
    for ( int i =0 ; i <5 ;i ++){
    cout << "Введите строку из слов:" << endl;
    cin.getline(a, 100);
    str = strtok(a, " ,.-"); //Функция strtok выполняет поиск лексем в строке string. Последовательность вызовов этой функции разбивают строку string на лексемы, которые представляют собой последовательности символов, разделенных символами разделителями.Здесь знаки, отделяющие слова
    k = 0;
    while (str != NULL)//выполняем пока есть лексемы // NULL - нулевой указатель
    {
        arr[k] = str;
        k++;
        str = strtok(NULL, " ,.-");//В последующих вызовах функция ожидает нулевой указатель и использует позицию сразу после окончания последнего токена в качестве нового начального места для сканирования.
        
    }

        vivod1[i] = arr[0];
        vivod2[i] = arr[1];
        vivod3[i] = arr[2];
        vivod4[i] = arr[3];
        vivod5[i] = arr[4];
        
        predlogeniye[0]= vivod1[q];
        predlogeniye[1]= vivod2[w];
        predlogeniye[2]= vivod3[e];
        predlogeniye[3]= vivod4[r];
        predlogeniye[4]= vivod5[t];
    }
    cout << "Новое предложение : ";
    for (int i=0;i<5;i++){
        cout << predlogeniye[i] << " " ;
       
    }
    cout <<endl << endl;
    delete [] vivod1;
    delete [] vivod2;
    delete [] vivod3;
    delete [] vivod4;
    delete [] vivod5;
    delete [] predlogeniye;
    return 0;
}

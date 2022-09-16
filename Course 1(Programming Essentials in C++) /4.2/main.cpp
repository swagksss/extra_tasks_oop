#include <iostream>
using namespace std;

class Car{
protected:
    string mark;
    int cylinders;
    int power;
public:
    Car(string m = "None", int c = 0, int p = 0){
        mark = m;
        cylinders = c;
        power = p;
    }
    string getMark(){
        return mark;
    }
    int getCylinders(){
        return cylinders;
    }
    int getPower(){
        return power;
    }
    void setPower(int pow){
        power = pow;
    }
    void print(){
        cout << "Марка авто : " << mark << endl;
        cout << "Количество цилиндров : " << cylinders << endl;
        cout << "Мощность : " << power << endl;
    }
};

class Lorry: public Car{
    int weight;
    
public:
    Lorry(string m = "None", int c = 0, int p = 0, int w = 0){
        mark = m;
        cylinders = c;
        power = p;
        weight = w;
    }
    void setWeight(int a = -1){
        weight = a;
    }
    
    int getWeight(){
        return weight;
    }
    
    void print(){
        Car::print();
        cout << "Грузоподъемность : " << weight << endl;
        
        cout << "\n";
    }
};

const int n = 10;
Lorry Cars[n];
void input(int n){
    for (int i = 0; i < n; ++i) {
        string mark;
        int c, p, w;
        cout << "Введите данные : ";
        cin >> mark;
        cin >> c;
        cin >> p;
        cin >> w;
        
        Cars[i] = Lorry(mark, c, p, w);
    }
}

void search(int poisk){

        for (int i = 0; i < n; ++i) {
            if(Cars[i].getCylinders() == poisk || Cars[i].getPower() == poisk || Cars[i].getWeight() == poisk ){
                cout << "Класс : Lorry\n";
                Cars[i].print();
            }
        }
    }

int main() {
    input(n);
    int num;
    cout << "Число для поиска  : ";
    cin >> num;
    search(num);
    return 0;
}

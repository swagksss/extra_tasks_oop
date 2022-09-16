#include <iostream>
using namespace std;

class Car{
    protected:
        string mark;
        int cylinders;
        int power;
    public:
    Car(string m ="None" , int c = 0 , int p = 0 ){
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
            cout << "Марка автомобиля : " << mark << endl;
            cout << "Количество цилиндров : " << cylinders << endl;
            cout << "Мощность: " << power << endl;
        }
};

class Lorry: public Car{
    int weight;
   
    public:
        Lorry(string m , int c , int p , int w ){
            mark = m;
            cylinders = c;
            power = p;
            weight = w;
            
        }
        void setWeight(int w ){
            weight = w;
        }
        
        int getWeight(){
            return weight;
        }
        void setMark(string m){
            mark = m;
        }
        
        void print(){
            Car::print();
            cout << "Грузоподъемность :  " << weight << endl;
           
        }
};



int main() {
    Car ford("Ford", 4, 100);
    Lorry nissan("Nissan", 8, 500, 3000);
    ford.print();
    ford.setPower(50);
    cout << "\n";
    ford.print();
    cout << "\n";
    nissan.print();
    cout << "\n";
    nissan.setWeight(2500);
    nissan.setMark("Volvo");
    nissan.print();
    cout << endl;
    return 0;
}

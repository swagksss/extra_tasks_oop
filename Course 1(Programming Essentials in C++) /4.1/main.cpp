#include <iostream>
 #include <string>
using namespace std;

 
class Car
{
protected:
    
    
    
    string _tradeMark;
    unsigned int _enginePower;
    unsigned int _numberOfCylinders;
 
public:
    Car(string tradeMark, unsigned int enginePower, unsigned int numberOfCylinders);
 
    string GetTradeMark() const;
    void SetTradeMark(string name);
 
    unsigned int GetEnginePower()  const;
    void SetEnginePower(int power);
    unsigned int GetNumberOfCylinders();
};

class Lorry :
    public Car
{
protected:
    unsigned int _weight_CarryingAbility;
 
public:
    Lorry(string tradeMark, unsigned int enginePower, unsigned int numberOfCylinders, unsigned int weight_CarryingAbility);
 
 
    unsigned int GetWeight_CarryingAbility() const;
    void SetWeight_CarryingAbility(unsigned int weight);
};

 
void DisplayCarInfo(Car cars[], int length);
void DisplayCarInfo(Car * car);
 
int main(int argc, char* argv[])
{
 
    const int arrayLength = 2;
    Car cars[arrayLength] = { Car("Ford", 330, 8), Lorry("Nissan", 750, 12, 30000) };
    DisplayCarInfo(cars, arrayLength);
 
    return 0;
}
 
void DisplayCarInfo(Car cars[], int length)
{
    for (int i = 0; i < length; i++)
    {
        DisplayCarInfo(&cars[i]);
    }
}
 
void DisplayCarInfo(Car* car)
{
    cout << "  Торговая марка: " << car->GetTradeMark() << " " << "  Мощность: " << car->GetEnginePower() << "  Цилиндры : " << car->GetNumberOfCylinders() << "\n" << endl; // -> Обращение к члену структуры
    
    
}



 
Car::Car(string tradeMark, unsigned int enginePower,unsigned int numberOfCylinders)//оператор разрешения контекста (области видимости)  ИмяКласса::Идентификатор
{
    _tradeMark = tradeMark;
    _enginePower = enginePower;
    _numberOfCylinders = numberOfCylinders;
}
 

string Car::GetTradeMark() const
{
    return _tradeMark;
}
 
void Car::SetTradeMark(string name)
{
    _tradeMark = name;
}
 
unsigned int Car::GetEnginePower() const
{
    return _enginePower;
}

void Car::SetEnginePower( int power)
{
    _enginePower = power;
}

unsigned int  Car::GetNumberOfCylinders()
{
    return _numberOfCylinders;
}

 
Lorry::Lorry(string tradeMark, unsigned int enginePower, unsigned int numberOfCylinders, unsigned int weight_CarryingAbility)
   
: Car(tradeMark, enginePower, numberOfCylinders)
{
    _weight_CarryingAbility = weight_CarryingAbility;
}
 

 
unsigned int Lorry::GetWeight_CarryingAbility() const

{
    return _weight_CarryingAbility;
}
 
void Lorry::SetWeight_CarryingAbility(unsigned int weight)
{
    _weight_CarryingAbility = weight;
}




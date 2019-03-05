#include "car.hpp"

string CAR::vehicleType = "car";

CAR::CAR()
{
    cout << "In CAR::constructor() default" << endl;
}

CAR::CAR(const string name, 
         int height, 
         int weight, 
         const string color) : VEHICLE (name,
                                        height,
                                        weight,
                                        color)
{
    cout << "In CAR::constructor() #1" << endl;
}

CAR::~CAR()
{
    cout << "In CAR::destructor()" << endl;
}

string
CAR::getType(void)
{
    return (CAR::vehicleType);
}

VEHICLE *
CAR::createCar(void)
{
    VEHICLE *ptrRet = NULL;
    string name;
    int height;
    int weight;
    string color;
    
    cout << "Enter model : ";
    cin >> name;
    cout << "Enter height : ";
    cin >> height;
    cout << "Enter weight : ";
    cin >> weight;
    cout << "Enter color : ";
    cin >> color;

    ptrRet = new CAR(name, height, weight, color);

    return (ptrRet);
}

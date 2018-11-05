#include "truck.hpp"

string TRUCK::vehicleType = "truck";

TRUCK::TRUCK()
{
    cout << "In TRUCK::constructor()" << endl;
}

TRUCK::TRUCK(const string name, 
             int height, 
             int weight, 
             const string color) : VEHICLE (TRUCK::vehicleType,
                                            name,
                                            height,
                                            weight,
                                            color)
{
    cout << "In TRUCK::constructor() #1" << endl;
}

TRUCK::~TRUCK()
{
    cout << "In TRUCK::destructor()" << endl;
}

string
TRUCK::getType (void)
{
    return (TRUCK::vehicleType);
}

VEHICLE *
TRUCK::createTruck(void)
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

    ptrRet = new TRUCK(name, height, weight, color);

    return (ptrRet);
}

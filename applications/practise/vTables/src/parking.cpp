
#include "parking.hpp"

PARKING::PARKING ()
{
    cout << "In PARKING::constructor() default" << endl;
}

PARKING::PARKING (char type[])
{
    cout << "In PARKING::constructor() #1" << endl;
    this->name.assign(type);
    this->name.append(" parking lot");
}

PARKING::~PARKING ()
{
    delete &lot;
}

void
PARKING::park (VEHICLE *ptrVehicle)
{
    string park_id;
    park_id = this->makeParkingId(ptrVehicle);
    this->lot.insert(_ENTRY(park_id, ptrVehicle));
    return;
}

void
PARKING::unpark (VEHICLE *ptrVehicle)
{
    string park_id;
    park_id = this->makeParkingId(ptrVehicle);
    this->lot.erase(park_id);
    return;
}

string
PARKING::makeParkingId (VEHICLE *ptrVehicle)
{
    string park_id;
    string name, color;
    name = ptrVehicle->getName();
    color = ptrVehicle->getColor();
    park_id = color + " " + name;

    return (park_id);
}

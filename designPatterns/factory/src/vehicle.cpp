#include "vehicle.hpp"
#include "car.hpp"
#include "truck.hpp"

VEHICLE::VEHICLE()
{
    cout << "In VEHICLE::constructor() default" << endl;
    this->vehicle_type.assign("none");
    this->name.assign("none");
    this->height = 0;
    this->weight = 0;
    this->color.assign("black");
}

VEHICLE::VEHICLE(const string vehicleType,
                 const string name, 
                 int height, 
                 int weight, 
                 const string color)
{
    cout << "In VEHICLE::constructor() ver#1" << endl;
    this->vehicle_type = vehicleType;
    this->name = name;
    this->height = height;
    this->weight = weight;
    this->color = color;
}

VEHICLE::VEHICLE(const VEHICLE& rhs)
{
    cout << "In VEHICLE::copy-constructor()" << endl;
    name.assign(rhs.getName());
    height = rhs.getHeight();
    weight = rhs.getWeight();
    color.assign(rhs.getColor());
}

VEHICLE::~VEHICLE()
{
    cout << "In VEHICLE::destructor()" << endl;
}

void 
VEHICLE::getRecord(void) const
{
    cout << "--------------------------" << endl;
    cout << "Record for Vehicle ~ " << this->vehicle_type << endl; 
    cout << "Model : " << this->name << endl;
    cout << "Color  : " << this->color << endl;
    cout << "Height : " << this->height << endl;
    cout << "Weight : " << this->weight << endl;

    return;
}

string
VEHICLE::getName(void) const
{
    return (this->name);
}

string
VEHICLE::getColor(void) const
{
    return (this->color);
}

int
VEHICLE::getHeight(void) const
{
    return (this->height);
}

int
VEHICLE::getWeight(void) const
{
    return (this->weight);
}

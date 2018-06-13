#ifndef _CAR_HPP
#define _CAR_HPP

using namespace std;

#include <iostream>
#include <string>
#include "vehicle.hpp"

class CAR : public VEHICLE
{
    public:
        static string vehicleType;
    public:
        // < CONSTRUCTOR : default >
        CAR ();

        // < CONSTRUCTOR : overloaded ver#1 >
        CAR(const string name, int height, int weight, const string color);

        // < DESTRUCTOR >
        ~CAR();

        // < METHODS >
        static string getType (void);
        static VEHICLE * createCar(void);
};

#endif

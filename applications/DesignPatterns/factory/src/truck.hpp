#ifndef _TRUCK_HPP
#define _TRUCK_HPP

#include <iostream>
#include <string>
#include "vehicle.hpp"

using namespace std;

class TRUCK : public VEHICLE
{
    public:
        static string vehicleType;
    public:
        // < CONSTRUCTOR : default >
        TRUCK ();

        // < CONSTRUCTOR : overloaded ver#1 >
        TRUCK(const string name, int height, int weight, const string color);

        // < DESTRUCTOR >
        ~TRUCK();

        // < METHODS >
        static string getType (void);
        static VEHICLE * createTruck(void);
};

#endif

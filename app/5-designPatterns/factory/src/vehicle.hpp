#ifndef _VEHICLE_HPP
#define _VEHICLE_HPP

#include <iostream>
#include <string>

using namespace std;

class VEHICLE
{
    protected:
        string vehicle_type;
        string name;
        int height;
        int weight;
        string color;
    public:

        // < CONSTRUCTOR : default >
        VEHICLE ();

        // < CONSTRUCTOR : overloaded ver#1 >
        VEHICLE(const string vehicleType,
                const string name, 
                int height, 
                int weight, 
                const string color);

        // < COPY CONSTRUCTOR >
        VEHICLE(const VEHICLE& rhs);

        // < DESTRUCTOR >
        virtual ~VEHICLE();

        //  < METHODS >
        void getRecord(void) const;
        string getName(void) const;
        string getColor(void) const;
        int getHeight(void) const;
        int getWeight(void) const;
};

#endif

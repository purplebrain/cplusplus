#ifndef _VEHICLE_FACT_HPP
#define _VEHICLE_FACT_HPP

#include <iostream>
#include <string>
#include <map>
#include "vehicle.hpp"

using namespace std;

typedef VEHICLE * (*ptrFunc)(void);

class dpFactoryVEHICLE
{
    public:
        static dpFactoryVEHICLE *ptrFactory;
    private:
        static map<string, ptrFunc> *ptrMapRegistry;

    public:
        // < CONSTRUCTOR : ver#0 >
        dpFactoryVEHICLE();

        // < COPY CONSTRUCTOR >
        dpFactoryVEHICLE(const dpFactoryVEHICLE&);

        // < COPY ASSIGNMENT OPERATOR >
        dpFactoryVEHICLE& operator=(const dpFactoryVEHICLE&);

        // < DESTRUCTOR >>
        ~dpFactoryVEHICLE();
        
        // < METHODS >
        static dpFactoryVEHICLE * getInstance(void);
        static VEHICLE * createVehicle(string type);
};

#endif

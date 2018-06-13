#ifndef _VEHICLE_FACT_HPP
#define _VEHICLE_FACT_HPP

#include <iostream>
#include <string>
#include <map>
#include "vehicle.hpp"
#include "car.hpp"
#include "truck.hpp"

typedef VEHICLE * (*ptrFunc)(void);

class dpFACTORY_VEHICLE
{
    public:
        static dpFACTORY_VEHICLE *ptrFactory;
    private:
        map<string, ptrFunc> *ptrMapRegistry;

    public:
        // < CONSTRUCTOR : ver#0 >
        dpFACTORY_VEHICLE();

        // < COPY CONSTRUCTOR >
        dpFACTORY_VEHICLE(const dpFACTORY_VEHICLE&);

        // < COPY ASSIGNMENT OPERATOR >
        dpFACTORY_VEHICLE& operator=(const dpFACTORY_VEHICLE&);

        // < DESTRUCTOR >>
        ~dpFACTORY_VEHICLE();
        
        // < METHODS >
        static dpFACTORY_VEHICLE * getInstance(void);
        void registration(string type, VEHICLE * (*ptrFunc)(void));
        VEHICLE * createVehicle(string type);
};

#endif

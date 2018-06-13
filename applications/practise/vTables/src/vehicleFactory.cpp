#include "vehicleFactory.hpp"

dpFACTORY_VEHICLE * dpFACTORY_VEHICLE::ptrFactory = NULL;

dpFACTORY_VEHICLE::dpFACTORY_VEHICLE()
{
    ptrMapRegistry = new map<string, ptrFunc>;
    registration("car", CAR::createCar);
    registration("truck", TRUCK::createTruck);
}

dpFACTORY_VEHICLE::dpFACTORY_VEHICLE(const dpFACTORY_VEHICLE& rhs)
{
    // Do nothing, as there is only one copy of Factory class
}

dpFACTORY_VEHICLE&
dpFACTORY_VEHICLE::operator=(const dpFACTORY_VEHICLE&)
{   
    return (*this);
}

dpFACTORY_VEHICLE::~dpFACTORY_VEHICLE()
{
    delete ptrMapRegistry;
}

dpFACTORY_VEHICLE * 
dpFACTORY_VEHICLE::getInstance(void)
{
   if (!ptrFactory) {
        ptrFactory = new dpFACTORY_VEHICLE();
   }

   return (ptrFactory);
}

void
dpFACTORY_VEHICLE::registration(string type, ptrFunc func)
{
    (*ptrMapRegistry)[type] = func;
}

VEHICLE * 
dpFACTORY_VEHICLE::createVehicle(string type)
{
    map<string, ptrFunc>::iterator itr = ptrMapRegistry->find(type);
    if (itr != ptrMapRegistry->end()) {
        return (itr->second());
    } else {
        return (NULL);
    }
}

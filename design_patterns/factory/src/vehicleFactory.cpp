#include "vehicleFactory.hpp"
#include "car.hpp"
#include "truck.hpp"

dpFactoryVEHICLE * dpFactoryVEHICLE::ptrFactory = NULL;
map<string, ptrFunc> *dpFactoryVEHICLE::ptrMapRegistry = NULL;

dpFactoryVEHICLE::dpFactoryVEHICLE()
{
    ptrMapRegistry = new map<string, ptrFunc>;
    (*ptrMapRegistry)["car"] = CAR::createCar;
    (*ptrMapRegistry)["truck"] = TRUCK::createTruck;
}

dpFactoryVEHICLE::dpFactoryVEHICLE(const dpFactoryVEHICLE& rhs)
{
    // Do nothing, as there is only one copy of Factory class
}

dpFactoryVEHICLE&
dpFactoryVEHICLE::operator=(const dpFactoryVEHICLE&)
{   
    return (*this);
}

dpFactoryVEHICLE::~dpFactoryVEHICLE()
{
    delete ptrMapRegistry;
}

dpFactoryVEHICLE * 
dpFactoryVEHICLE::getInstance(void)
{
   if (!ptrFactory) {
        ptrFactory = new dpFactoryVEHICLE();
   }

   return (ptrFactory);
}

VEHICLE * 
dpFactoryVEHICLE::createVehicle(string type)
{
    map<string, ptrFunc>::iterator itr = ptrMapRegistry->find(type);
    if (itr != ptrMapRegistry->end()) {
        return (itr->second());
    } else {
        return (NULL);
    }
}

#include <iostream>
#include <string>
#include <vector>
#include "vehicleFactory.hpp"
#include "vehicle.hpp"
#include "car.hpp"
#include "truck.hpp"


int
main (int argc, char *argv[])
{
    string type;
    vector<VEHICLE *> vecVehicle;
    VEHICLE *ptrVehicle = NULL;

    while (1)
    {
        cout << "Enter type of vehicle to create" << endl;
        cout << "Enter [car|truck|quit] : ";
        cin >> type;

        if (type.compare("quit") == 0) {
            break;
        } else {
            ptrVehicle = dpFACTORY_VEHICLE::getInstance()->createVehicle(type);
        }
        
        vecVehicle.push_back(ptrVehicle);
    }

    vector<VEHICLE *>::iterator itr;
    for (itr = vecVehicle.begin(); itr != vecVehicle.end(); itr++) {
        (*itr)->getRecord();
    }

    return (0);
}
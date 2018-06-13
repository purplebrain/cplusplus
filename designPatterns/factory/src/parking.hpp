#ifndef _PARKING_HPP
#define _PARKING_HPP

using namespace std;

#include <iostream>
#include <string>
#include <map>
#include "vehicle.hpp"

typedef pair<string, VEHICLE *> _ENTRY;

class PARKING
{
    private:
        string name;
        map<string, VEHICLE *> lot;
    public:
        PARKING();
        PARKING(char type[]);
        ~PARKING();
        void park(VEHICLE *);
        void unpark(VEHICLE *);
        void display(void);
    private:
        string makeParkingId(VEHICLE *);
};


#endif

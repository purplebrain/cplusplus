#include <iostream>
#include <cstring>

#include "base.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
    BASE *ptrBase1 = new BASE(2, 2);
    BASE *ptrBase2 = new BASE(4, 12);
    BASE A(*ptrBase1);
    BASE B(*ptrBase2);

    BASE C = *ptrBase1;
    C = A;

    BASE D;
    D = *ptrBase2;

		BASE *ptrA = new BASE(*ptrBase1);

    return (0);
}

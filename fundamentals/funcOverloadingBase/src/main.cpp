#include <iostream>
#include <string>
#include <typeinfo>
#include "base.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
    int inputInt;
    string inputStr;
    while (1) {
        cout << "Enter [quit|int] : ";
        cin >> inputStr;
        if (inputStr.compare("quit") == 0) {
            break;
        } else {
            cout << "Integer : ";
            cin >> inputInt; 
            BASE *ptrObj = new BASE(inputInt);
            ptrObj->printMembers(ptrObj);
        }
    }

    return (0);
}

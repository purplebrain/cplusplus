#ifndef __MY_PRINT_HPP
#define __MY_PRINT_HPP

using namespace std;
#include <iostream>
#include <cstdlib>
#include <cstddef>

#include "MyList.hpp"

class MyPrintUtils
{
    public:
        void static print_array(int *inputArr, int Asize);
        void static print_list(MyListNode *ptrListHead);

};

#endif // __MY_PRINT_HPP

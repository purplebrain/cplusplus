#ifndef __MY_LIST_UTILS_HPP
#define __MY_LIST_UTILS_HPP

//
//  < DESCRIPTION >
//
//	This file consists of utils required to operate on linked lists
//






using namespace std;

#include <iostream>
#include <cstddef>

#include "MyList.hpp"

class MyListUtils
{
    public:
        static MyListNode * reverse_list (MyListNode *ptrListHead);
};

#endif //__MY_LIST_UTILS_HPP

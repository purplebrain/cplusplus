#ifndef __MY_SEARCH_UTILS_HPP
#define __MY_SEARCH_UTILS_HPP

//
//  < DESCRIPTION >
//
//	This file consists of all the sorting algorithms
//






using namespace std;

#include <iostream>
#include <cstddef>

class MySearchUtils
{
    private:
        static bool binary_search_helper (int *inputArr, int idxStart, int idxEnd, int value);

    public:
        static bool binary_search (int *inputArr, int Asize, int value);

};





#endif // __MY_SEARCH_UTILS_HPP

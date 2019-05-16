#ifndef __MY_SEARCH_UTILS_HPP
#define __MY_SEARCH_UTILS_HPP

//
//  < DESCRIPTION >
//
//	This file consists of all the sorting algorithms
//

#include <iostream>
#include <cstddef>

using namespace std;

class MySearchArrayUtils
{
    private:
        static bool binary_search_helper (int *inputArr, int idxStart, int idxEnd, int value);

    public:
        static bool binary_search (int *inputArr, int Asize, int value);

};





#endif // __MY_SEARCH_UTILS_HPP

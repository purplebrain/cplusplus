#ifndef __MY_SORT_UTILS_HPP
#define __MY_SORT_UTILS_HPP

//
//  < DESCRIPTION >
//
//	This file consists of all the sorting algorithms
//






using namespace std;

#include <iostream>
#include <cstddef>

class MySortUtils
{
    private:
        static void merge_sort_conquer (int *inputArr, int idxLeft, int idxMid, int idxRight);
        static void merge_sort_divide (int *inputArr, int idxLeft, int idxRight);
    public:
        static void selection_sort(int *inputArr, int Asize);
        static void merge_sort(int *inputArr, int Asize);
};





#endif // __MY_SORT_UTILS_HPP

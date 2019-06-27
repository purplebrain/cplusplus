#include <iostream>
#include <cstddef>
#include "MyPrintArrayUtils.hpp"
#include "MySortArrayUtils.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
    int inputArr[8] = {10, 5, 6, 4, 7, 3, 2, 1};

    cout << "Input array is : " << endl;
    MyPrintArrayUtils::print_array(inputArr, sizeof(inputArr)/sizeof(inputArr[0]));

    cout << "Doing Selection Sort" << endl;
    MySortArrayUtils::selection_sort(inputArr, sizeof(inputArr)/sizeof(inputArr[0]));

    cout << "Sorted array is : " << endl;
    MyPrintArrayUtils::print_array(inputArr, sizeof(inputArr)/sizeof(inputArr[0]));

    return (0);
}

using namespace std;

#include <iostream>
#include <cstddef>

#include "MyPrintUtils.hpp"
#include "MySortUtils.hpp"

int
main (int argc, char *argv[])
{
    int inputArr[8] = {10, 5, 6, 4, 7, 3, 2, 1};

    cout << "Input array is : " << endl;
    MyPrintUtils::print_array(inputArr, sizeof(inputArr)/sizeof(inputArr[0]));

    cout << "Doing Selection Sort" << endl;
    MySortUtils::selection_sort(inputArr, sizeof(inputArr)/sizeof(inputArr[0]));

    cout << "Sorted array is : " << endl;
    MyPrintUtils::print_array(inputArr, sizeof(inputArr)/sizeof(inputArr[0]));

    return (0);
}

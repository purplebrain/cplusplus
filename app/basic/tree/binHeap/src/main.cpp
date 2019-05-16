#include <iostream>
#include <cstddef>
#include "MyTreeUtils.hpp"
#include "MyBinHeap.hpp"

using namespace std;

uint *arr;
uint arrSize;

int
main (int argc, char *argv[])
{
    MyBinHeap binHeap;

    cout << "Enter the size of array to be converted into a Heap : ";
    cin >> arrSize;

    arr = new uint[arrSize];

    cout << "Enter array elements" << endl;
    for (uint i = 0; i < arrSize; i++) {
        cout << "Element-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;

    binHeap.buildHeapFromArray(arr, arrSize, MAXHEAP);

    MyTreeUtils::print_in_order(binHeap.ptrRoot);

    cout << endl;
    return (0);
}

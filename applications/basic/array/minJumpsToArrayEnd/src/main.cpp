/*
 *  < PROBLEM DESCRIPTION >
 *  Given an array such that each array-element represents the number of jumps that can be made the next
 *  elements, calculate the minimum number of jumps required to reach the end.
 */

#include <iostream>
#include "TwoDMatrix.hpp"

using namespace std;

int inputArrSize;
int *inputArr;
int *memo;
int maxJumpValue;

int
findMinJumps2ArrayEnd (int arrSize)
{
    int minJumps = 0;
    int idxLast = (arrSize - 1);
 

    return minJumps;
}

int
main (int argc, char *argv[])
{
    int result;
    int maxArrValue = 0;

    cout << "Enter the size of the array : ";
    cin >> inputArrSize;
    inputArr = new int[inputArrSize];
    
    cout << "Enter integer array elements" << endl;
    for (int i = 0; i < inputArrSize; i++)
    {
        cout << "element-" << i << " : ";
        cin >> inputArr[i];
        if (inputArr[i] > maxArrValue) {
            maxArrValue = inputArr[i];
        }
    }
    maxJumpValue = maxArrValue + inputArrSize;

    // create memoize-table
    memo = new int[inputArrSize];

    for (int i = 1; i <= inputArrSize; i++) {
        result += findMinJumps2ArrayEnd(i);
    }

    cout << "Min jumps needed to reach array-end is : " << result << endl;

    return (0);
}

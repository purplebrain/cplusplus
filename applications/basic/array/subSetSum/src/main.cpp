/*
 *  < PROBLEM DESCRIPTION >
 *  This program finds if there is a subSet in the given array, whose elements
 *  sum up to a given sum.
 */

#include <iostream>
#include "TwoDMatrix.hpp"

using namespace std;

int inputArrSize;
int *inputArr;
int inputSum;
TwoDMatrix *memo;

bool
isSubSetFound (int *arr, int length, int sum)
{
    bool retVal = false;
    int idxLast = length-1;

    if (memo->get(sum-1, length-1)) {
        return true;
    }

    if (length <= 0) {
        return false;
    }

    if (sum == 0) {
        return true;
    }

    if (arr[idxLast] > sum) {
        retVal = isSubSetFound(arr, length-1, sum);
    } else if (arr[idxLast] < sum) {
        memo->set(sum-1, length-1);
        retVal = isSubSetFound(arr, length-1, sum - arr[idxLast]) || 
                                                isSubSetFound(arr, length-1, sum);
    } else {
        retVal = true;
    }

    return retVal;
}

int
main (int argc, char *argv[])
{
    cout << "Enter the size of the array : ";
    cin >> inputArrSize;

    inputArr = new int[inputArrSize];
    
    cout << "Enter integer array elements" << endl;
    for (int i = 0; i < inputArrSize; i++)
    {
        cout << "element-" << i << " : ";
        cin >> inputArr[i];    
    }

    cout << "Enter the sum to match to : ";
    cin >> inputSum;

    // create memoize-table
    memo = new TwoDMatrix(inputSum, inputArrSize);

    cout << "Finding subset in the array : [";
    for (int j = 0; j < inputArrSize; j++) {
        cout << inputArr[j];
        if (j == inputArrSize-1) {
            cout << "]";
        } else {
            cout << ", ";
        }
    }
    cout << " whose sum-of-elements is " << inputSum << endl;

    // find sub-array
    if (isSubSetFound(inputArr, inputArrSize, inputSum)) {
        cout << "A subset with sum of elements equal to " << inputSum << " is found" << endl;
    } else {
        cout << "No subset(s) found" << endl;
    }

    return (0);
}

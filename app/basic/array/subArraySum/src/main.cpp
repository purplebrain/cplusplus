/*
 *  < PROBLEM DESCRIPTION >
 *  Find a subarray in the given array such that the sum of it's elements
 *  is equal to a given sum.
 */

#include <iostream>

using namespace std;

int inputArrSize;
int *inputArr;
int *inputPfxSumArr;
int inputSum;
int idxSubArrayStart, idxSubArrayEnd;

bool
findSubArraySum (void)
{
    bool retVal = false;
    // find the array of prefix sum
    for (int k = 0; k < inputArrSize; k++) {
        if (k == 0) {
            inputPfxSumArr[k] = inputArr[k];
        } else {
            inputPfxSumArr[k] = inputPfxSumArr[k-1] + inputArr[k];
        }
    }

    // now search for the subarray
    int idxStart = 0;
    int idxEnd = (inputArrSize - 1);
    if (inputPfxSumArr[idxEnd] == inputSum) {
        idxSubArrayStart = idxStart;
        idxSubArrayEnd = idxEnd;
        return true;
    }

    do {
        if (idxStart == idxEnd) {
            if (inputPfxSumArr[idxStart] == inputSum) {
                return true;
            } else {
                return false;
            }
        } else {
            if ((inputPfxSumArr[idxEnd] - inputPfxSumArr[idxStart]) > inputSum) {
                idxStart++;
                idxEnd--;
            } else if ((inputPfxSumArr[idxEnd] - inputPfxSumArr[idxStart]) < inputSum) {
                idxStart--;
                idxEnd++;
            } else {
                // subarray with sum-of-elements equal to inputSum is found
                idxSubArrayStart = idxStart + 1;
                idxSubArrayEnd = idxEnd;
                return true;
            }
        }
    } while (idxStart != idxEnd);

    return retVal;
}

int
main (int argc, char *argv[])
{
    cout << "Enter the size of the array : ";
    cin >> inputArrSize;

    inputArr = new int[inputArrSize];
    inputPfxSumArr = new int[inputArrSize];
    
    cout << "Enter integer array elements" << endl;
    for (int i = 0; i < inputArrSize; i++)
    {
        cout << "element-" << i << " : ";
        cin >> inputArr[i];    
    }

    cout << "Enter the sum to match to : ";
    cin >> inputSum;

    cout << "Finding subarray in the array : [";
    for (int j = 0; j < inputArrSize; j++) {
        cout << inputArr[j];
        if (j == inputArrSize-1) {
            cout << "]";
        } else {
            cout << ", ";
        }
    }
    cout << " whose sum-of-elements is " << inputSum << endl;

    if (findSubArraySum()) {
        cout << "The subarray is : [";
        for (int j = idxSubArrayStart; j <= idxSubArrayEnd; j++) {
            cout << inputArr[j];
            if (j == idxSubArrayEnd) {
                cout << "]";
            } else {
                cout << ", ";
            }
        }
    } else {
        cout << "No such subarray found" << endl;
    }

		return(0);
}

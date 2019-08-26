//
//  < PROBLEM STATEMENT >
//
//  Given an array of n positive integers and a positive integer k, 
//  the task is to find the maximum subarray size such that all subarrays of that size have sum of elements less than k.
//

#include <iostream>

using namespace std;

int gArrSize;
int *gArrInput;
int *gArrPrefix;
int gK;

int
getMaxSubArraySize (void)
{
  int retVal = -1;

  // Find the max sub-array on this prefix-array
  for (int winSize = 1; winSize <= gArrSize; winSize++) {
    bool isWinSizeGood = false;
    for (int i = 0; i < gArrSize; i++) {
      if (i+winSize-1 >= gArrSize) {
        break;
      } else {
        if (((gArrPrefix[i+winSize-1] - gArrPrefix[i]) + gArrInput[i]) < gK) {
          isWinSizeGood = true;       
        } else {
          isWinSizeGood = false;       
        }
      }
    }
    if (isWinSizeGood) {
      retVal = winSize;
    }
  }

  return (retVal);
}

int
main (int argc, char *argv[])
{
  while (1) {
    cout << "\n\n=====================";
    cout << "\nEnter array-size : ";
    cin >> gArrSize;
    cout << "\nEnter elements of the array:\n";
    gArrInput = new int [gArrSize];
    fill_n(gArrInput, gArrSize, 0);
    for (int i = 0; i < gArrSize; i++) {
      cout << "Element-" << i << " : ";
      cin >> gArrInput[i];
    }
    cout << "\nEnter value of 'K' : ";
    cin >> gK;
    // Print input-array
    cout << "\nInputArray = [";
    for (int i = 0; i < gArrSize; i++) {
      cout << " " << gArrInput[i];
    }
    cout << " ]" << endl;
    // Build the prefix-array
    gArrPrefix = new int[gArrSize];
    fill_n(gArrPrefix, gArrSize, 0);
    for (int i = 0; i < gArrSize; i++) {
      if (i == 0) {
        gArrPrefix[i] = gArrInput[i];
      } else {
        gArrPrefix[i] = gArrPrefix[i-1] + gArrInput[i];     
      }
    }
    // Print prefix-array
    cout << "\nPrefixArray = [";
    for (int i = 0; i < gArrSize; i++) {
      cout << " " << gArrPrefix[i];
    }
    cout << " ]" << endl;
  
    cout << "\nMax sub-array size : " << getMaxSubArraySize();
    delete [] gArrInput;
    delete [] gArrPrefix;
    gArrSize = 0;
  }
  return (0);
}

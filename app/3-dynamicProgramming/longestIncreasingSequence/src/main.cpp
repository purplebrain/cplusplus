/*
 * The Longest Increasing Subsequence (LIS) problem is to find the 
 * length of the longest subsequence of a given sequence such that 
 * all elements of the subsequence are sorted in increasing order. 
 * For example, 
 * length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 
 * and LIS is {10, 22, 33, 50, 60, 80}.
 */

#include <iostream>

using namespace std;

int sequence[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
int sequenceLength;
int *arrLIS;

int
calculateLIS(int idx)
{
    for (int j = 0; j < idx; j++)
    {
        if (sequence[j] < sequence[idx]) {
            int tmp = arrLIS[j] + 1;
            arrLIS[idx] = (arrLIS[idx] >= tmp) ? arrLIS[idx] : tmp;
        }
    }

    return arrLIS[idx];
}

int
getLIS (int length)
{
    int retVal = 0;

    for (int i = 0; i < length; i++)
    {
        retVal = calculateLIS(i);
    }

    return retVal;
}

int
main (int argc, char *argv[])
{
    sequenceLength = sizeof(sequence)/sizeof(sequence[0]);
    arrLIS = new int[sequenceLength];
    // initialize LIS array to all 1s.
    for (int i = 0; i < sequenceLength; i++) {
        arrLIS[i] = 1;
    }

    cout << "Length of LIS is : " << getLIS(sequenceLength) << endl;

    return (0);
}


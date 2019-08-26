/*
 < PROBLEM STATEMENT >
 Given a set of non-negative integers, and a value sum, 
 determine if there is a subset of the given set with sum equal to given sum.
 */

#include <iostream>

using namespace std;

unsigned int gInputSize;
unsigned int *gInputArr;
unsigned int gInputSum;

bool **gArrTabulate;

void
init (void)
{
  gInputArr = new unsigned int[gInputSize];
  gArrTabulate = new bool*[gInputSize+1];
  for (int i = 0; i < (gInputSize+1); i++) {
    gArrTabulate[i] = new bool[gInputSum+1];
    fill_n(gArrTabulate[i], (gInputSum+1), false);
  }
  return;
}

void
cleanup (void)
{
  delete [] gInputArr;
  for (int i = 0; i < (gInputSize+1); i++) {
    delete [] gArrTabulate[i];
  }
  return;
}

bool
isSubsetSum (unsigned int N, int SUM_LEFT)
{
  for (int i = 0; i < (gInputSize+1); i++) {
    for (int j = 0; j < (gInputSum+1); j++) {
      if (j == 0) {
        // BASE CONDTION (if sum-left is zero)
        gArrTabulate[i][j] = true;
      } else if ((j != 0) && (i == 0)) {
        // BASE CONDITION (if sum-left is non-zero and nothing in input-set)
        gArrTabulate[i][j] = false;
      } else if (j < gInputArr[i-1]) {
        // GENERIC CONDITION (based on Recursive Formula)
        gArrTabulate[i][j] = gArrTabulate[i-1][j];
      } else if (j >= gInputArr[i-1]) {
        // GENERIC CONDITION (based on Recursive Formula)
        gArrTabulate[i][j] = gArrTabulate[i-1][j] || 
                             gArrTabulate[i][j-gInputArr[i-1]];  
      }
    }
  }

  return (gArrTabulate[N][SUM_LEFT]);
}

int 
main (int argc, char *argv[])
{
  while(1) {
    cout << endl;
    cout << "==========================" << endl;
    cout << "Enter size of input array : ";
    cin >> gInputSize;
    init(); 
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < gInputSize; i++) {
      cout << "element-" <<  i << " : ";
      cin >> gInputArr[i];
    }	
    cout << "Input Array is : [";
    for (int j=0; j < gInputSize; j++) {
      cout << gInputArr[j] << " ";
    }
    cout << "]" << endl;
    cout << "Enter the of 'subset-sum' : ";
    cin >> gInputSum;

    if (isSubsetSum(gInputSize, gInputSum)) {
      cout << "Subset sum found" << endl;
    } else {
      cout << "Subset sum not found" << endl;
    }

    cleanup();
  }

  return (0);
}

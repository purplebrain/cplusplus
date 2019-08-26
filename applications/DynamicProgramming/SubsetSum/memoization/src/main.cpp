/*
 < PROBLEM STATEMENT >
 Given a set of non-negative integers, and a sum, 
 determine if there is a subset of the given set with sum equal to given sum.
 */

#include <iostream>

using namespace std;

unsigned int gInputSize;
unsigned int *gInputArr;
unsigned int gInputSum;

bool **gArrMemoize;

void
cleanup (void)
{
  for (int i = 0; i < (gInputSize+1); i++) {
    delete [] gArrMemoize[i];
  }
}

void
init (void)
{
  gInputArr = new unsigned int[gInputSize];
  gArrMemoize = new bool*[gInputSize+1];
  for (int i = 0; i < (gInputSize+1); i++) {
    gArrMemoize[i] = new bool[gInputSum+1];
    for (int j = 0; j < (gInputSum+1); j++) {
      gArrMemoize[i][j] = false;
    }
  }
}

bool
isSubsetSum (int N, int SUM_LEFT)
{
  bool retVal = false;
  
  if (!gArrMemoize[N][SUM_LEFT]) {
    // BASE CONDITION
    if (SUM_LEFT==0) {
      gArrMemoize[N][SUM_LEFT] = true;
      return (gArrMemoize[N][SUM_LEFT]);
    } else if ((SUM_LEFT!=0) && (N==0)) {
      gArrMemoize[N][SUM_LEFT] = false;
      return (gArrMemoize[N][SUM_LEFT]);
    } else if ((N==1) && (gInputArr[N-1] == SUM_LEFT)) {
      gArrMemoize[N][SUM_LEFT] = true;
      return (gArrMemoize[N][SUM_LEFT]);
    } 
    // GENERIC CONDITION (use Recursive Formula)
    if (SUM_LEFT < gInputArr[N-1]) { 
      // LESS THAN
      gArrMemoize[N][SUM_LEFT] = isSubsetSum(N-1, SUM_LEFT);
      return (gArrMemoize[N][SUM_LEFT]);
    } else if (SUM_LEFT >= gInputArr[N-1]) { 
      // GREATER THAN
      gArrMemoize[N][SUM_LEFT] = isSubsetSum(N-1,SUM_LEFT) ||
                                 isSubsetSum(N-1, SUM_LEFT-gInputArr[N-1]);
      return (gArrMemoize[N][SUM_LEFT]);
    }
  } else {
    // MEMOIZED VALUE
    return (gArrMemoize[N][SUM_LEFT]);
  }

  return (retVal);
}

int
main (int argc, char *argv[])
{
  while (1) {
    cout << endl;
    cout << "======================" << endl;
    cout << "Enter the size of the array : ";
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
    cout << "Enter the 'subset-sum' : ";
    cin >> gInputSum;

    if (isSubsetSum(gInputSize, gInputSum)) {
      cout << "Subset sum found" << endl;
    } else {
      cout << "Subset sum not found" << endl;
    }

    delete [] gInputArr;
    cleanup();
  }

  return (0);
}

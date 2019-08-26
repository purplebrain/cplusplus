/*
  < PROBLEM STATEMENT >
  Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value 
  in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and 
  weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find 
  out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
  You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
  Putting everything together, an entry in row i, column j represents the maximum value that can be obtained with 
  items 1, 2, 3 … i, in a knapsack that can hold j weight units.\
 */

#include <iostream>

using namespace std;

unsigned int gInputSize;
unsigned int *gInputValArr;
unsigned int *gInputWeightArr;
unsigned int gInputCapacity;

unsigned int **gArrMemoize;

void
printMemoizationArr (void)
{
  for (int i = 0; i < (gInputSize + 1); i++) {
    for (int j = 0; j < (gInputCapacity + 1); j++) {
      cout << "\t" << gArrMemoize[i][j];
    }
    cout << endl;
  }

  return;
}

int
MAX (unsigned int a, unsigned int b)
{
  return ((a>b)?a:b);
}

void
init (void)
{
  gInputValArr = new unsigned int[gInputSize];
  gInputWeightArr = new unsigned int[gInputSize];
  gArrMemoize = new unsigned int*[gInputSize+1];
  for (int i = 0; i < (gInputSize+1); i++) {
    gArrMemoize[i] = new unsigned int[gInputCapacity+1];
    fill_n(gArrMemoize[i], (gInputCapacity+1), 0);
  }

  return;
}

void
cleanup (void)
{
  delete [] gInputValArr;
  delete [] gInputWeightArr;
  for (int i = 0; i < (gInputSize+1); i++) {
    delete [] gArrMemoize[i];
  }
  return;
}

unsigned int
Knapsack (unsigned int SIZE, unsigned int CAPACITY)
{
  unsigned int retVal = 0;

  if (!gArrMemoize[SIZE][CAPACITY]) {
    if ((SIZE == 0) || (CAPACITY == 0)) {
      // BASE CONDITION
      gArrMemoize[SIZE][CAPACITY] = 0;
      return (gArrMemoize[SIZE][CAPACITY]);
    } else if (gInputWeightArr[SIZE-1] <= CAPACITY) {
      // GENERIC CONDITION (use Recursive Formula)
      gArrMemoize[SIZE][CAPACITY] = MAX(Knapsack(SIZE-1, CAPACITY),
                                        gInputValArr[SIZE-1] + Knapsack(SIZE-1, CAPACITY-gInputWeightArr[SIZE-1]));
      return (gArrMemoize[SIZE][CAPACITY]);
    } else if (gInputWeightArr[SIZE-1] > CAPACITY) {
      // GENERIC CONDITION (use Recursive Formula)
      gArrMemoize[SIZE][CAPACITY] = Knapsack(SIZE-1, CAPACITY);
      return (gArrMemoize[SIZE][CAPACITY]);
    }
  } else {
    // MEMOIZED VALUE
    return (gArrMemoize[SIZE][CAPACITY]);
  } 
  
  return (retVal);
}

int 
main (int argc, char *argv[])
{
  while(1) {
    cout << endl;
    cout << "==========================" << endl;
    cout << "Enter Knapsack Capacity : ";
    cin >> gInputCapacity;
    cout << "Enter size of input : ";
    cin >> gInputSize;
    init(); 
    cout << "Enter the elements of the ValueArray : " << endl;
    for (int i = 0; i < gInputSize; i++) {
      cout << "element-" <<  i << " : ";
      cin >> gInputValArr[i];
    }	
    cout << "Enter the elements of the WeightArray : " << endl;
    for (int i = 0; i < gInputSize; i++) {
      cout << "element-" <<  i << " : ";
      cin >> gInputWeightArr[i];
    }	
    cout << "Input Value Array is  : [";
    for (int j=0; j < gInputSize; j++) {
      cout << gInputValArr[j] << "\t";
    }
    cout << "]" << endl;
    cout << "Input Weight Array is : [";
    for (int j=0; j < gInputSize; j++) {
      cout << gInputWeightArr[j] << "\t";
    }
    cout << "]" << endl;

    int VAL = Knapsack(gInputSize, gInputCapacity);
    if (VAL) {
      cout << "For Knapsack Capacity " << gInputCapacity << " we can fill with items of value " << VAL << endl;
    } else {
      cout << "Can't fill the given Knapsack" << endl;
    }

    printMemoizationArr();

    cleanup();
  }

  return (0);
}

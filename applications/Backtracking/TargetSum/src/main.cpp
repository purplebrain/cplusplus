#include <iostream>
#include <vector>
 
using namespace std;

int *gInputArr;
int gSizeInput;
int gTargetSum;
int gStats = 0;

void combinate (void);
void combinate(int idxInput, vector<int> vecPartial);

void
printVecPartialSum (int idxInput, vector<int>& vecPartial)
{
	cout << "STACK - " << idxInput << " : [";
	for (vector<int>::iterator itr = vecPartial.begin(); itr != vecPartial.end(); itr++) {
			cout << *itr << " ";
	}	
	cout << "]" << endl;
}

void
init (void)
{
	gStats = 0;

	if (gInputArr) {
		delete [] gInputArr;
	}
}

void
processCombination (vector<int>& vecPartial)
{
  for (vector<int>::iterator itr = vecPartial.begin(); itr != vecPartial.end(); itr++) {
    cout << *itr << " ";
  }	
  cout << endl;
  gStats++;

  return;
}

int
getPartialSum (vector<int>& vecPartial)
{	
  int retSum = 0;

  for (vector<int>::iterator itr = vecPartial.begin(); itr != vecPartial.end(); itr++) {
    retSum += *itr;
  }	

  return (retSum);
}

bool
isTargetMet (vector<int>& vecPartial) 
{
  bool ret = false;
  if (getPartialSum(vecPartial) == gTargetSum) {
    ret = true;
  }

  return (ret);
}

bool
isConstraintSatisfied (vector<int>& vecPartial)
{
  bool retVal = false;

  // Check if a combination can be processed
  if (isTargetMet(vecPartial)) {
    processCombination(vecPartial);
    retVal = true;
  } else if (getPartialSum(vecPartial) > gTargetSum) {
    retVal = true;
  } else {
    retVal = false;
  }

  return (retVal);
}

void
combinate(int idx, vector<int> vecPartial)
{
  // When no more elements are there to put in vecPartial[]
  if (idx >= gSizeInput) {
    return;
  }

  // Update partial sum
  vecPartial.push_back(gInputArr[idx]);
  //printVecPartialSum(idxInput, vecPartial);

  // Constraint check
  if (isConstraintSatisfied(vecPartial)) {
    return;
  }

  for (int i = idx; i < gSizeInput; i++) {
    combinate(i+1, vecPartial);
  }
}
 
void
combinate (void)
{
	vector<int> vecPartial;
	for (int idx = 0; idx < gSizeInput; idx++) {
			combinate(idx, vecPartial);
	}
}

int
main (int argc, char *argv[])
{
  while (1) {
    cout << endl;
    cout << "============================" << endl;
    cout << "Enter the size of the array : ";
    cin >> gSizeInput;
    init();
    gInputArr = new int[gSizeInput];
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < gSizeInput; i++) {
      cout << "element-" <<  i << " : ";
      cin >> gInputArr[i];
    }	
    cout << "Input Array is : [";
    for (int j=0; j < gSizeInput; j++) {
      cout << gInputArr[j] << " ";
    }
    cout << "]" << endl;
    cout << "Enter a new Target Sum = ";
    cin >> gTargetSum;
    gStats = 0;

    combinate();

    if (gStats) {
      cout << "There are " << gStats << " sets that meet gTargetSum" << endl;
    } else {
      cout << "No set of elements met gTargetSum" << endl;
    }
  }

  return 0;
}

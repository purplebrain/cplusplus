#include <iostream>
#include <vector>
 
using namespace std;

int *gInputArr;
int gSizeInput;
int gTargetSum;
int gStats = 0;

void target_sum (void);
void target_sum (int idxInput, vector<int> vecPartial);

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
target_sum (int cur_idx, vector<int> vecPartial)
{
	// [ EXIT CONDITION ]
  if (cur_idx >= gSizeInput) {
    return;
  }

	// [ UPDATE PARTIALS ]
  vecPartial.push_back(gInputArr[cur_idx]);
  //printVecPartialSum(idxInput, vecPartial);

	// [ CONSTRAINT CHECK ]
  if (isConstraintSatisfied(vecPartial)) {
    // SUCCESS! PROBLEM SOLVED 
    // (go exit gracefully)
    return;
  } else {
    // FAILURE! 
    // (go to next state)
    for (int next_idx = cur_idx; next_idx < gSizeInput; next_idx++) {
      // CONDITION CHECK TO PICK NEXT STATE FROM THE LIST OF
      // NEXT_STATE(s) OF THE CURRENT_STATE.
      target_sum(next_idx+1, vecPartial);
    }
  }

  // [ BACKTRACK ]
  // (If here, it means that none of the next_state(s) of
  // of the current_state is valid. So we have to backtrack
  // from the current_state itself.)
  vecPartial.pop_back();
}
 
void
target_sum (void)
{
	vector<int> vecPartial;
  // [ LOOP OVER BASE STATES ]
	for (int base_idx = 0; base_idx < gSizeInput; base_idx++) {
			target_sum(base_idx, vecPartial);
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

    target_sum();

    if (gStats) {
      cout << "There are " << gStats << " sets that meet gTargetSum" << endl;
    } else {
      cout << "No set of elements met gTargetSum" << endl;
    }
  }

  return 0;
}

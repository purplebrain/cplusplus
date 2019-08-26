/* 
  < PROBLEM STATEMENT >
		Print all combinations of a given string and group size.
    NOTE:
    In Combination, order doesn't matter.
    So,
      [1, 2, 3]
      [2, 3, 1]
      [3, 2, 1]
    All the above are considered as a single combination.
 */

// TODO

#include <iostream>
#include <vector>
 
using namespace std;

int *gInputArr;
int gSizeInput;
int gSizeGrp;
int gStats = 0;

void combinate (void);
void combinate (int idxInput, vector<int> vecPartial);

void
init (void)
{
	gStats = 0;

	if (gInputArr) {
		delete [] gInputArr;
	}

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

bool
isConstraintSatisfied (vector<int>& vecPartial)
{
  bool retVal = false;

	// Check if a combination can be processed
  if (vecPartial.size() == gSizeGrp) {
			processCombination(vecPartial);
      retVal = true;
  }

  return (retVal);
}

void
combinate (int cur_idx, vector<int> vecPartial)
{
	// [ EXIT CONDITION ]
  if (cur_idx >= gSizeInput) {
    return;
  }

	// [ UPDATE PARTIALS ]
  vecPartial.push_back(gInputArr[cur_idx]);

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
      combinate(next_idx+1, vecPartial);
    }
  }

  // [ BACKTRACK ]
  // (If here, it means that none of the next_state(s) of
  // of the current_state is valid. So we have to backtrack
  // from the current_state itself.)
  vecPartial.pop_back();
}
 
void
combinate (void)
{
	vector<int> vecPartial;
  // [ LOOP OVER BASE STATES ]
	for (int base_idx = 0; base_idx < gSizeInput; base_idx++) {
			combinate(base_idx, vecPartial);
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
    cout << "Enter the value of 'sizeGrp' i.e. group size : ";
    cin >> gSizeGrp;

    combinate();

    if (gStats) {
      cout << "There are " << gStats << " combinations possible" << endl;
    } else {
      cout << "No combinations possible" << endl;
    }
  }

  return 0;
}

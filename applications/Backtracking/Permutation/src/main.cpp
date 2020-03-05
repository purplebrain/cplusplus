/* 
  < PROBLEM STATEMENT >
		Print all permutations of a given string and group size.
		NOTE:
    In Permutation, order matters.
    So,
      [1, 2, 3]
      [2, 3, 1]
      [3, 2, 1]
		Each of them is considered a unique permutation.
*/

#include <iostream>
#include <vector>
#include <set>
 
using namespace std;

int *gInputArr;
int gSizeInput;
int gSizeGrp;
int gStats = 0;

void permutate (void);
void permutate(int idxInput, vector<int> vecPartial);

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
}

void
processPermutation (vector<int>& vecPartial)
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
		processPermutation(vecPartial);
    retVal = true;
  }

  return (retVal);
}

void
permutate (int cur_idx, set<int> setPartial, vector<int> vecPartial)
{
	// [ EXIT CONDITION ]
  if (cur_idx >= gSizeInput) {
    return;
  }

	// [ UPDATE PARTIALS ]
  vecPartial.push_back(gInputArr[cur_idx]);
  setPartial.insert(cur_idx);

	// [ CONSTRAINT CHECK ]
  if (isConstraintSatisfied(vecPartial)) {
    // SUCCESS! PROBLEM SOLVED 
    // (go exit gracefully)
    return;
	} else {
    // FAILURE! 
    // (go to next state)
		for (int next_idx = 0; next_idx < gSizeInput; next_idx++) {
      // CONDITION CHECK TO PICK NEXT STATE FROM THE LIST OF
      // NEXT_STATE(s) OF THE CURRENT_STATE.
			if (setPartial.find(next_idx) == setPartial.end()) {
        // VALID NEXT STATE (so considering)
				permutate(next_idx, setPartial, vecPartial);
			} else {
        // INVALID NEXT STATE (so pruning)
        continue;
      }
		} 
	}

  // [ BACKTRACK ]
  // (If here, it means that none of the next_state(s) of
  // of the current_state is valid. So we have to backtrack
  // from the current_state itself.)
  vecPartial.pop_back();
  setPartial.erase(cur_idx);
}

void
permutate (void)
{
  set<int> setPartial;
  vector<int> vecPartial;
  // [ LOOP OVER BASE STATES ]
  for (int base_idx = 0; base_idx < gSizeInput; base_idx++) {
    permutate(base_idx, setPartial, vecPartial);
  }

  return;
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
    cout << "]" << endl;
    cout << "Enter the value of 'sizeGrp' i.e. group size : ";
    cin >> gSizeGrp;

    permutate();

    if (gStats) {
      cout << "There are " << gStats << " combinations possible" << endl;
    } else {
      cout << "No combinations possible" << endl;
    }
  }

  return 0;
}


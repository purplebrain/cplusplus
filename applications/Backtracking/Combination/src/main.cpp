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
void combinate(int idxInput, vector<int> vecPartial);

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
combinate(int idx, vector<int> vecPartial)
{
	// [ EXIT CONDITION ]
  if (idx >= gSizeInput) {
    return;
  }

	// [ UPDATE PARTIALS ]
  vecPartial.push_back(gInputArr[idx]);

	// [ CONSTRAINT CHECK ]
  if (isConstraintSatisfied(vecPartial)) {
    // SUCCESS
    return;
  } else {
    // FAILURE (go to next state)
    // CONDITION CHECK TO PICK NEXT STATE (none for this problem)
    for (int i = idx; i < gSizeInput; i++) {
      // GO TO NEXT STATE
      combinate(i+1, vecPartial);
    }
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

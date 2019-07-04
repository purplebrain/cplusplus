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
printVecPartialSum (int idxInput, vector<int>& vecPartial)
{
	cout << "STACK - " << idxInput << " : [";
	for (vector<int>::iterator itr = vecPartial.begin(); itr != vecPartial.end(); itr++) {
			cout << *itr << " ";
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
combinate(int idxInput, vector<int> vecPartial)
{
    // When no more elements are there to put in vecPartial[]
    if (idxInput >= gSizeInput) {
        return;
    }
		
		// Update partial sum
		vecPartial.push_back(gInputArr[idxInput]);
		//printVecPartialSum(idxInput, vecPartial);

    // Constraint check
    if (isConstraintSatisfied(vecPartial)) {
        return;
    }
 
		for (int i = idxInput; i < gSizeInput; i++) {
				combinate(i+1, vecPartial);
		}
}
 
void
combinate (void)
{
	vector<int> vecPartial;
	for (int i = 0; i < gSizeInput; i++) {
			combinate(i, vecPartial);
	}
}

int
main (int argc, char *argv[])
{
	cout << "Enter the size of the array : ";
	cin >> gSizeInput;

	gInputArr = new int[gSizeInput];

	cout << "Enter the elements of the array : " << endl;
	for (int i = 0; i < gSizeInput; i++) {
		cout << "element-" <<  i << " : ";
		cin >> gInputArr[i];
	}	

  while (1) {
		cout << endl << endl;
    cout << "-----------------------------------------" << endl << endl;
    cout << "Input Array is : [";
    for (int j=0; j < gSizeInput; j++) {
        cout << gInputArr[j] << " ";
    }
    cout << "]" << endl;

    cout << "Enter the value of 'sizeGrp' i.e. group size : ";
    cin >> gSizeGrp;
    gStats = 0;

    combinate();

		if (gStats) {
				cout << "There are " << gStats << " combinations possible" << endl;
		} else {
				cout << "No combinations possible" << endl;
		}
  }

  return 0;
}

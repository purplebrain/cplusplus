#include <iostream>
#include <vector>
 
using namespace std;

int *inputSet;
int sizeInput;
vector<int> vecCombination;
int sizeGrp;
int stats = 0;

void
processCombination (void)
{

    for (int j=0; j<sizeGrp; j++) {
        cout << vecCombination[j] << " ";
    }
    cout << endl;
    
    return;
}

void combinate(int inputSet[], int idxInput, vector<int>& vecCombination, int idxCombo)
{
    // Current cobination is ready, print it
    if (idxCombo == sizeGrp) {
        processCombination();
			  stats++;
        return;
    }
 
    // When no more elements are there to put in vecCombination[]
    if (idxInput >= sizeInput) {
        return;
    }
 
    // current is included, put next at next location
    vecCombination[idxCombo] = inputSet[idxInput];
    combinate(inputSet, idxInput+1, vecCombination, idxCombo+1);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinate(inputSet, idxInput+1, vecCombination, idxCombo);
}
 
int
main (int argc, char *argv[])
{
	cout << "Enter the size of the array : ";
	cin >> sizeInput;

	inputSet = new int[sizeInput];

	cout << "Enter the elements of the array : " << endl;
	for (int i = 0; i < sizeInput; i++) {
		cout << "element-" <<  i << " : ";
		cin >> inputSet[i];
	}	

  cout << "Input Array is : [";
  for (int j=0; j<sizeInput; j++) {
      cout << inputSet[j] << " ";
  }
  cout << "]" << endl;

  while (1) {
    cout << "Enter the value of 'sizeGrp' i.e. group size : ";
    cin >> sizeGrp;
		if (vecCombination.size()) {
		    vecCombination.clear();
        stats = 0;
		}
    vecCombination.assign(sizeGrp, 0);
    int idxInput = 0, idxCombo = 0;
    combinate(inputSet, idxInput, vecCombination, idxCombo);
		cout << "STATS : " << stats << " combinations" << endl;
    cout << "-----------------------------------------" << endl;
  }

  return 0;
}

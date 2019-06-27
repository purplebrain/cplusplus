#include <iostream>
#include <vector>
#include <string>

using namespace std;

int *inputSet;
int sizeInput;
bool *inputPickerSet;
int sizeGrp;
vector<int> vecPermutation;
int stats = 0;

void
permutate (int *arrInput, bool *arrPicker, vector<int>& vecPermutation)
{	
	if (vecPermutation.size() == sizeGrp) {
		for (int i = 0; i < sizeGrp; i++) {
			cout << " " << vecPermutation[i];
		}
		cout << endl;
		stats++;
		return;
	}

	for (int i = 0; i < sizeInput; i++) {
		if (!inputPickerSet[i]) {
			inputPickerSet[i] = true;
			vecPermutation.push_back(inputSet[i]);
			permutate(inputSet, inputPickerSet, vecPermutation);
			inputPickerSet[i] = false;
			vecPermutation.pop_back();
		}
	}

	return;
}


int
main (int argc, char *argv[])
{
	cout << "Enter the size of the array : ";
	cin >> sizeInput;

	inputSet = new int[sizeInput];
	inputPickerSet = new bool[sizeInput];

	cout << "Enter the elements of the array : " << endl;
	for (int i = 0; i < sizeInput; i++) {
		cout << "element-" <<  i << " : ";
		cin >> inputSet[i];
		inputPickerSet[i] = false;
	}	

  cout << "Input Array is : [";
  for (int j=0; j<sizeInput; j++) {
      cout << inputSet[j] << " ";
  }
  cout << "]" << endl;

  while (1) {
    cout << "Enter the value of 'sizeGrp' i.e. group size : ";
    cin >> sizeGrp;
		if (vecPermutation.size()) {
				vecPermutation.clear();
				for (int i = 0; i < sizeInput; i++) {
					inputPickerSet[i] = false;
				}	
		}
		permutate(inputSet, inputPickerSet, vecPermutation);
		cout << "STATS : " << stats << " permutations" << endl;
    cout << "-----------------------------------------" << endl;
  }

	return 0;
}

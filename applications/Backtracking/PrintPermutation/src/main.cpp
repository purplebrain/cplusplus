#include <iostream>
#include <vector>
#include <string>

using namespace std;

int *gInputArr;
int gSizeInput;
bool *gInputPickerArr;
int gSizeGrp;
//vector<int> vecPermutation;
int gStats = 0;

void
processPermutation (vector<int>& vecPermutation)
{
    for (int j=0; j<gSizeGrp; j++) {
        cout << vecPermutation[j] << " ";
    }
    cout << endl;

		gStats++;
    
    return;
}

void
permutate (vector<int>& vecPermutation)
{	
	if (vecPermutation.size() == gSizeGrp) {
			processPermutation(vecPermutation);
			return;
	}

	for (int i = 0; i < gSizeInput; i++) {
			if (!gInputPickerArr[i]) {
					gInputPickerArr[i] = true;
					vecPermutation.push_back(gInputArr[i]);
					permutate(vecPermutation);
					gInputPickerArr[i] = false;
					vecPermutation.pop_back();
			}
	}

	return;
}

void
permutate (void)
{
	vector<int> vecPermutation;
	permutate(vecPermutation);

	return;
}

int
main (int argc, char *argv[])
{
	cout << "Enter the size of the array : ";
	cin >> gSizeInput;

	gInputArr = new int[gSizeInput];
	gInputPickerArr = new bool[gSizeInput];

	cout << "Enter the elements of the array : " << endl;
	for (int i = 0; i < gSizeInput; i++) {
		cout << "element-" <<  i << " : ";
		cin >> gInputArr[i];
		gInputPickerArr[i] = false;
	}	

  while (1) {
		cout << endl << endl;
    cout << "-----------------------------------------" << endl;
  	cout << "Input Array is : [";
  	for (int j=0; j<gSizeInput; j++) {
  	    cout << gInputArr[j] << " ";
  	}
  	cout << "]" << endl;

    cout << "Enter the value of 'gSizeGrp' i.e. group size : ";
    cin >> gSizeGrp;

		gStats = 0;
		for (int i = 0; i < gSizeInput; i++) {
			gInputPickerArr[i] = false;
		}	

		permutate();

		cout << "STATS : " << gStats << " permutations" << endl;
  }

	return 0;
}

#include <iostream>
 
using namespace std;

int sizeSet;
int *set;
int sizeGrp;
int *data;

void
processCombination (void)
{

    for (int j=0; j<sizeGrp; j++) {
        cout << data[j] << " ";
    }
    cout << endl;
    
    return;
}

void combine(int set[], int sizeSet, int sizeGrp, int idxSet, int data[], int idxData)
{
    // Current cobination is ready, print it
    if (idxData == sizeGrp)
    {
        processCombination();
        return;
    }
 
    // When no more elements are there to put in data[]
    if (idxSet >= sizeSet) {
        return;
    }
 
    // current is included, put next at next location
    data[idxData] = set[idxSet];
    combine(set, sizeSet, sizeGrp, idxSet+1, data, idxData+1);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combine(set, sizeSet, sizeGrp, idxSet+1, data, idxData);
}
 
int
main (int argc, char *argv[])
{
	cout << "Enter the size of the array : ";
	cin >> sizeSet;

	set = new int[sizeSet];
	data = new int[sizeGrp];

	cout << "Enter the elements of the array : " << endl;
	for (int i = 0; i < sizeSet; i++) {
		cout << "element-" <<  i << " : ";
		cin >> set[i];
	}	

    cout << "Input Array is : [";
    for (int j=0; j<sizeSet; j++) {
        cout << set[j] << " ";
    }
    cout << "]" << endl;

    while (1) {
      cout << "Enter the value of 'sizeGrp' i.e. group size : ";
      cin >> sizeGrp;
      int idxSet = 0, idxData = 0;
      combine(set, sizeSet, sizeGrp, idxSet, data, idxData);
      cout << "-----------------------------------------" << endl;
    }

    return 0;
}

using namespace std;

#include <iostream>
 
void printCombination(int arr[], int n, int k, int idxCurArr,
                      int data[], int idxCurData)
{
    // Current cobination is ready, print it
    if (idxCurData == k)
    {
        for (int j=0; j<k; j++)
            cout << data[j] << " ";
        cout << endl;

        return;
    }
 
    // When no more elements are there to put in data[]
    if (idxCurArr >= n)
        return;
 
    // current is included, put next at next location
    data[idxCurData] = arr[idxCurArr];
    printCombination(arr, n, k, idxCurArr+1, data, idxCurData+1);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    printCombination(arr, n, k, idxCurArr+1, data, idxCurData);
}
 
int
main (int argc, char *argv[])
{
    int n;
    int *arr;
    int k;
    int *data;

	  cout << "Enter the size of the array : ";
	  cin >> n;

	  arr = new int[n];
	  data = new int[k];

	  cout << "Enter the elements of the array : " << endl;
	  for (int i = 0; i < n; i++) {
	  	cout << "element-" <<  " : ";
	  	cin >> arr[i];
	  }	

    cout << "Input Array is : [";
    for (int j=0; j<n; j++) {
        cout << arr[j] << " ";
    }
    cout << "]" << endl;

    while (1) {
      cout << "Enter the value of 'k' i.e. group size : ";
      cin >> k;
      printCombination(arr, n, k, 0, data, 0);
      cout << "-----------------------------------------" << endl;
    }

    return 0;
}

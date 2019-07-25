#include <iostream>

using namespace std;

bool
isSubsetSum(int *arr, int n, int sum)
{
	bool retVal;

	if (sum == 0) {
		return true;
	}

	if ((n == 0) && (sum != 0)) {
		return false;
	}

	if (arr[n-1] > sum) {
		retVal = isSubsetSum(arr, (n-1), sum);
	} else {
		retVal = isSubsetSum(arr, (n-1), sum) || 
											isSubsetSum(arr, (n-1), sum-arr[n-1]);
	}

	return retVal;
}


int
main (int argc, char *argv[])
{
	int *set;
	int n;
	int sum;

	cout << "Enter the size of the array : ";
	cin >> n;

	set = new int[n];

	cout << "Enter the elements of the array : " << endl;
	for (int i = 0; i < n; i++) {
		cout << "element-" <<  " : ";
		cin >> set[i];
	}	

	cout << "Enter the subset sum : ";
	cin >> sum;

	if (isSubsetSum(set, n, sum)) {
		cout << "Array has subset whose sum is : " << sum << endl;
	} else {
		cout << "Array does not have a subset whose sum is : " << sum << endl;
	}

	return (0);
}

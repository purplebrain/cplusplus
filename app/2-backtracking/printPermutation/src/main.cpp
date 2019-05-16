
#include <iostream>

using namespace std;

int *set;
int n;

void swap (int p, int q)
{
	int tmp = set[p];
	set[p] = set[q];
	set[q] = tmp;

	return;
}

void
printPermutation (int r)
{
	cout << endl;
	for (int i = (r-n+1); i <= r; i++) {
		cout << set[i] << " ";
	}
}

void
permute (int l, int r)
{
	if (l == r) {
		// process the constraint
		printPermutation(r);
	} else {
	    for (int i = l; i <= r; i++) {
	    	// swap
	    	swap(l, i);

	    	// try-out
	    	permute(l+1, r);

	    	// re-swap
	    	swap(l, i);
	    }
	}

	return;
}

int
main (int argc, char *argv[])
{
	cout << "Enter the size of the array : ";
	cin >> n;
	int adjLen = (n - 1);

	set = new int[n];

	cout << "Enter the elements of the array : " << endl;
	for (int i = 0; i < n; i++) {
		cout << "element-" <<  " : ";
		cin >> set[i];
	}	

	permute (0, adjLen);
	
	cout << endl;
	return (0);
}

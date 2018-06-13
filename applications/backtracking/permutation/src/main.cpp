using namespace std;

#include <iostream>

int *set;
int sizeSet;
int sizeGrp;

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
	for (int i = (r-sizeGrp+1); i <= r; i++) {
		cout << set[i] << " ";
	}

    return;
}

void
permute (int l, int r)
{
	if ((r-l+1) == sizeGrp) {
		// process the constraint
		printPermutation(l+sizeGrp-1);
	} else {
	    for (int i = l; i < (l+sizeGrp); i++) {
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
	cin >> sizeSet;
	set = new int[sizeSet];
	cout << "Enter the elements of the array : " << endl;
	for (int i = 0; i < sizeSet; i++) {
		cout << "element-" <<  " : ";
		cin >> set[i];
	}	

	cout << "Enter the size of group : ";
	cin >> sizeGrp;

	permute(0, (sizeSet-1));
	
	cout << endl;
	return (0);
}

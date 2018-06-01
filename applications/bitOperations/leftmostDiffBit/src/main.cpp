using namespace std;

#include <iostream>
#include <cstdlib>
#include <cmath>

unsigned int
leftmostSetBit (unsigned int X)
{
	int word_len = sizeof(int);
	word_len = word_len/2;
	
	X = X | (X >> 1);
	X = X | (X >> 2);
	X = X | (X >> 4);
	X = X | (X >> 8);
	X = X | (X >> 16);
  
	if (word_len > 16) {
		X = X | (X >> 32);
	}

	X = X + 1;
	X = X >> 1;

	return (X);

}

int
main (int argc, char *argv[])
{
	unsigned int X;
	float lmsBit;

	cout << "Enter integer value : ";
	cin >> X;
	cout << endl;

	lmsBit = log2((float)leftmostSetBit(X));
	cout << "Leftmost set-bit is : " << (int)lmsBit << endl; 

	return (0);
}

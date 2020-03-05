#include <iostream>
#include<string>
#include<boost/multiprecision/cpp_int.hpp>
#include<chrono>

using namespace std::chrono;
using namespace boost::multiprecision;
using namespace std;

unsigned int gInputN;
int1024_t *gArrMemoize; // for Memoization

void
printDebug (void)
{
	#if(DEBUG)
	cout << endl << "[ MEMOIZATION TABLE ]" << endl;
	for (int i = 0; i < gInputN; i++) {
		cout << gArrMemoize[i] << " ";
	}
	cout << endl;
	#endif
	return;
}

void
init (void)
{
	gArrMemoize = new int1024_t[gInputN+1];
	fill_n(gArrMemoize, gInputN+1, 0);
}

int1024_t
fibonacci (unsigned int N)
{
	printDebug();

	if (!gArrMemoize[N]) {
		if ((N == 0) || (N == 1)) {
			// BASE CONDITION
			gArrMemoize[N] = N;
			return (gArrMemoize[N]);
		} else if (N == 2) {
			// BASE CONDITION
			gArrMemoize[N] = 1;
			return (gArrMemoize[N]);
		} else {
			// GENERIC CONDITION (use Recursive Formula)
			gArrMemoize[N] = fibonacci(N-1) + fibonacci(N-2);
			return (gArrMemoize[N]);
		}
	} else {
    // MEMOIZED VALUE
		return (gArrMemoize[N]);
	}
}

int
main (int argc, char *argv[])
{
	while (1) {
		cout << endl;
		cout << "===================" << endl;
		cout << "Enter value of N = ";
		cin >> gInputN;

		init();

		cout << "Nth fibonacci number is : " << fibonacci(gInputN) << endl;

		delete [] gArrMemoize;
	}
	return (0);
}

#include <iostream>

using namespace std;

unsigned int gInputN;
unsigned int *gArrFib;

void
init (void)
{
  #if(DEBUG)
  cout << endl << "init() start" << endl;
  #endif
	gArrFib = new unsigned int[gInputN+1];
	fill_n(gArrFib, gInputN+1, 0);
  #if(DEBUG)
  cout << "init() end" << endl;
  #endif
}

unsigned int
fibonacci (int N)
{
  for (int i = 0; i < (gInputN+1); i++) {
    if (i == 0) {
      // BASE CONDITION
      gArrFib[i] = 0;
    } else if (i == 1) {
      // BASE CONDITION
      gArrFib[i] = 1;
    } else {
      // GENERIC CONDITION (based on Recursive Formula)
      gArrFib[i] = gArrFib[i-1] + gArrFib[i-2];
    }
  }

  return (gArrFib[N]);
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

		delete [] gArrFib;
	}
  return (0);
}

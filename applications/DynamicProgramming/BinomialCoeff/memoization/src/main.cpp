#include <iostream>

using namespace std;

int gN, gK;
int **gArrMemoize; // for Memoization

void
init (void)
{
  #if(DEBUG)
  cout << endl << "init() start" << endl;
  #endif
  gArrMemoize = new int*[gN+1];
  for (int i = 0; i < (gN+1); i++) {
    gArrMemoize[i] = new int[gK+1];
    fill_n(gArrMemoize[i], (gK+1), 0);
  }
  #if(DEBUG)
  cout << "init() end" << endl;
  #endif
}

unsigned int
findBinomialCoeff (int N, int K)
{
  if (!gArrMemoize[N][K]) {
    // BASE CONDITION
    if ((N==K) || (K==0)) {
      gArrMemoize[N][K] = 1;
      return (gArrMemoize[N][K]);
    } else if (K == 1) {
      gArrMemoize[N][K] = N;
      return (gArrMemoize[N][K]);
    } else {
      // GENERIC CONDITION (use Recursive Formula)
      gArrMemoize[N][K] = findBinomialCoeff(N-1,K-1) + findBinomialCoeff(N-1,K);
      return (gArrMemoize[N][K]);
    }
  } else {
    // MEMOIZED VALUE
    return (gArrMemoize[N][K]);
  }
}

int
main (int argc, char *argv[])
{
  while (1) {
    unsigned int retVal = 0;
    cout << endl;
    cout << "======================" << endl;
    cout << "Enter value for C(N,K)" << endl;
    cout << "N = "; cin >> gN;
    cout << "K = "; cin >> gK;

    init();

    retVal = findBinomialCoeff(gN,gK);

    cout << "Binomial Coefficient of C(N,K) = " << retVal << endl;

    for (int i = 0; i < (gN+1); i++) {
      delete [] gArrMemoize[i];
    }
  }
  return (0);
}

#include <iostream>

using namespace std;

int gN, gK;
int **gArrTabulate;

void
printDebug (void) 
{
  #if(DEBUG)
  cout << endl;
  cout << "[ TABULATION RESULT ]" << endl;
  for (int i = 0; i < (gN+1); i++) {
    for (int j = 0; j < (gK+1); j++) {
      cout << gArrTabulate[i][j] << " ";
    } 
    cout << endl;
  }
  cout << endl;
  #endif
  return;
}

void
init (void)
{
  #if(DEBUG)
  cout << endl << "init() start" << endl;
  #endif
  gArrTabulate = new int*[gN+1];
  for (int i = 0; i < gN+1; i++) {
    gArrTabulate[i] = new int[gK+1];
    fill_n(gArrTabulate[i], (gK+1), 0);
  }
  #if(DEBUG)
  cout << "init() end" << endl;
  #endif
}

unsigned int
findBinomialCoeff (int N, int K) 
{
  for (int i = 0; i < (gN+1); i++) {
    for (int j = 0; j < (gK+1); j++) {
      if ((i==j) || (j == 0)) {
        // BASE CONDITION
        gArrTabulate[i][j] = 1;
      } else if (i > j) {
        // GENERIC CONDITION (based on Recursive Formula)
        gArrTabulate[i][j] = gArrTabulate[i-1][j-1] + gArrTabulate[i-1][j];
      }
    }
  }

  printDebug();

  return (gArrTabulate[N][K]);
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

    retVal = findBinomialCoeff(gN, gK);

    cout << "Binomial Coefficient of C(N,K) = " << retVal << endl;

    for (int i = 0; i < (gN+1); i++) {
      delete [] gArrTabulate[i];
    }
  }
  return (0);
}

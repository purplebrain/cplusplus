/*  
  Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} 
  valued coins, how many ways can we make the change? The order of coins doesn’t matter.
*/

#include <iostream>

using namespace std;

unsigned int gInputChange;
unsigned int gInputNumCoins;
unsigned int *gInputArrCoins;

unsigned int **gArrMemoize;

void
printTabulationArr (void)
{
  for (int i = 0; i < (gInputNumCoins + 1); i++) {
    for (int j = 0; j < (gInputChange + 1); j++) {
      cout << "\t" << gArrMemoize[i][j];
    }
    cout << endl;
  }

  return;
}

void
init (void)
{
  gInputArrCoins = new unsigned int[gInputNumCoins];
  gArrMemoize = new unsigned int*[gInputNumCoins+1];
  for (int i = 0; i < (gInputNumCoins+1); i++) {
    gArrMemoize[i] = new unsigned int[gInputChange+1];
    fill_n(gArrMemoize[i], (gInputChange+1), 0);
  }
  return;
}

void
cleanup (void)
{
  delete [] gInputArrCoins;
  for (int i = 0; i < (gInputNumCoins+1); i++) {
    delete [] gArrMemoize[i];
  }
  return;
}

unsigned int
CoinChange (unsigned int COINS, unsigned int CHANGE_LEFT)
{
  unsigned int retVal = 0;

  if (!gArrMemoize[COINS][CHANGE_LEFT]) {
    if ((COINS == 0) || (CHANGE_LEFT == 0)) {
      // BASE CONDITION
      gArrMemoize[COINS][CHANGE_LEFT] = 0;
      return (gArrMemoize[COINS][CHANGE_LEFT]);
    } else if (CHANGE_LEFT < gInputArrCoins[COINS-1]) {
      // GENERIC CONDITION (based on Recursive Formula)
      gArrMemoize[COINS][CHANGE_LEFT] = CoinChange(COINS-1, CHANGE_LEFT);
      return (gArrMemoize[COINS][CHANGE_LEFT]);
    } else if (CHANGE_LEFT == gInputArrCoins[COINS-1]) {
      // GENERIC CONDITION (based on Recursive Formula)
      gArrMemoize[COINS][CHANGE_LEFT] = 1 + CoinChange(COINS-1, CHANGE_LEFT);
      return (gArrMemoize[COINS][CHANGE_LEFT]);
    } else if (CHANGE_LEFT > gInputArrCoins[COINS-1]) {
      // GENERIC CONDITION (based on Recursive Formula)
      gArrMemoize[COINS][CHANGE_LEFT] = CoinChange(COINS, CHANGE_LEFT-gInputArrCoins[COINS-1])
                                        +
                                        CoinChange(COINS-1, CHANGE_LEFT);
      return (gArrMemoize[COINS][CHANGE_LEFT]);
    }
  } else {
    // MEMOIZED VALUE
    return (gArrMemoize[COINS][CHANGE_LEFT]);
  }

  return (retVal);
}

int
main (int argc, char *argv[])
{
  while (1) {
    cout << endl;
    cout << "=======================" << endl;
    cout << "Enter change : "; 
    cin >> gInputChange;
    cout << "Enter number of coins : "; 
    cin >> gInputNumCoins;
    init();
    cout << "Enter coin values" << endl;
    for (int i = 0; i < gInputNumCoins; i++) {
      cout << "element-" << i << " : ";
      cin >> gInputArrCoins[i];    
    }
    cout << "Input Coins are : [";
    for (int j = 0; j < gInputNumCoins; j++) {
      cout << gInputArrCoins[j] << " "; 
    }
    cout << "]" << endl;
    int VAL = CoinChange(gInputNumCoins, gInputChange);
    if (VAL) {
      cout << VAL << " combinations possible" << endl;
    } else {  
      cout << "No combinations possible" << endl;
    }
    printTabulationArr();
    cleanup();
  }
  return (0);
}

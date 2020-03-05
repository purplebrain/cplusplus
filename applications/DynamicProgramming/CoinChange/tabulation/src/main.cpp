/*  
  Given a value N, if we want to make change for N cents, 
	and we have infinite supply of each of S = { S1, S2, .. , Sm} 
  valued coins, how many ways can we make the change? The order of 
	coins doesn’t matter.
*/

#include <iostream>

using namespace std;

unsigned int gInputChange;
unsigned int gInputNumCoins;
unsigned int *gInputArrCoins;

unsigned int **gArrTabulate;

void
printTabulationArr (void)
{
  for (int i = 0; i < (gInputNumCoins + 1); i++) {
    for (int j = 0; j < (gInputChange + 1); j++) {
      cout << "\t" << gArrTabulate[i][j];
    }
    cout << endl;
  }

  return;
}

void
init (void)
{
  gInputArrCoins = new unsigned int[gInputNumCoins];
  gArrTabulate = new unsigned int*[gInputNumCoins+1];
  for (int i = 0; i < (gInputNumCoins+1); i++) {
    gArrTabulate[i] = new unsigned int[gInputChange+1];
    fill_n(gArrTabulate[i], (gInputChange+1), 0);
  }
  return;
}

void
cleanup (void)
{
  delete [] gInputArrCoins;
  for (int i = 0; i < (gInputNumCoins+1); i++) {
    delete [] gArrTabulate[i];
  }
  return;
}

unsigned int
CoinChange (unsigned int COINS, unsigned int CHANGE_LEFT)
{
  for (int coin = 0; coin < (gInputNumCoins+1); coin++) {
    for (int cLeft = 0; cLeft < (gInputChange+1); cLeft++) {
      //cout << "[COIN, C_LEFT] = [" << coin << ", " << cLeft << "]" << endl;
      if ((coin == 0) || (cLeft == 0)){
        // BASE CONDITION
        gArrTabulate[coin][cLeft] = 0;
      } else if (cLeft < gInputArrCoins[coin-1]) {
        // GENERIC CONDITION (based on Recursive Formula)
        gArrTabulate[coin][cLeft] = gArrTabulate[coin-1][cLeft];
      } else if (cLeft == gInputArrCoins[coin-1]) {
        // GENERIC CONDITION (based on Recursive Formula)
        gArrTabulate[coin][cLeft] = gArrTabulate[coin-1][cLeft] + 1;
      } else if (cLeft > gInputArrCoins[coin-1]) {
        // GENERIC CONDITION (based on Recursive Formula)
        gArrTabulate[coin][cLeft] = gArrTabulate[coin][cLeft - gInputArrCoins[coin-1]]
                                    +
                                    gArrTabulate[coin-1][cLeft];
      }
    }
  }
  return (gArrTabulate[COINS][CHANGE_LEFT]);
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

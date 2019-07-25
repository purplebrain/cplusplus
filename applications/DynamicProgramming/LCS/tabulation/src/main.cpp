#include <iostream>

using namespace std;

string gInputStr1;
unsigned int gInputLen1;
string gInputStr2;
unsigned int gInputLen2;

int **gArr;

void
init (void)
{
   #if(DEBUG)
   cout << endl << "init() start" << endl;
   #endif
   gInputLen1 = gInputStr1.size();
   gInputLen2 = gInputStr2.size();

   gArr = new int*[gInputLen1+1];
   for (int i = 0; i < (gInputLen1+1); i++) {
      gArr[i] = new int[gInputLen2+1];
      fill_n(gArr[i], (gInputLen2+1), 0);
   }
   #if(DEBUG)
   cout << "init() end" << endl;
   #endif
}

unsigned int
LCS (int gInputLen1, int gInputLen2)
{
  for (int i = 0; i < (gInputLen1+1); i++) {
    for (int j = 0; j < (gInputLen2+1); j++) {
      if ((i==0) || (j==0)) {
        // BASE CONDITION
        gArr[i][j] = 0;
      } else if (gInputStr1[i-1] == gInputStr2[j-1]) {
        // GENERIC CONDITION (based on Recursive Formula)
        gArr[i][j] = 1 + gArr[i-1][j-1];
      } else {
        // GENERIC CONDITION (based on Recursive Formula)
        gArr[i][j] = (gArr[i][j-1] > gArr[i-1][j]) ? gArr[i][j-1] : gArr[i-1][j];
      }
    }
  }
  return (gArr[gInputLen1][gInputLen2]);
}

int
main (int argc, char *argv[])
{
  while (1) {
    unsigned int lcsLen = 0;
    cout << endl << endl;
    cout << "===========================" << endl;
    cout << "Enter the first string : "; cin >> gInputStr1;
    cout << "Enter the second string: "; cin >> gInputStr2;     

    init();

    lcsLen = LCS(gInputLen1, gInputLen2);

    cout << "Longest Common Subsequence length is : " << lcsLen;
  }
  return (0);
}

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
LCS (unsigned int idx1, unsigned int idx2)
{
  unsigned int retTmp1 = 0, retTmp2 = 0, max = 0;
  
  if (!gArr[idx1][idx2]) {
    // BASE CONDITION
    // (none)

    // GENERIC CONDITION (use Recursive Formula)
    if ((idx1 != 0) && (idx2 != 0)) {
      if (gInputStr1[idx1-1] == gInputStr2[idx2-1]) {
        gArr[idx1][idx2] = 1 + LCS(idx1-1, idx2-1);
        return (gArr[idx1][idx2]);
      } else {
        if (idx2 !=0) {
          retTmp1 = LCS(idx1, idx2-1);
        }
        if (idx1 != 0) {
          retTmp2 = LCS(idx1-1, idx2);
        }
        max = (retTmp1 > retTmp2) ? retTmp1 : retTmp2;
        gArr[idx1][idx2] = max;
        return (gArr[idx1][idx2]);
      }
    } else {
        gArr[idx1][idx2] = 0;
        return (gArr[idx1][idx2]);
    } 
  } else {
    // MEMOIZED VALUE
    return (gArr[idx1][idx2]);
  }
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

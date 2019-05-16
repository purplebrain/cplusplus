#include <iostream>
#include <string>
 
#include "TwoDMatrix.hpp"

using namespace std;

int result = 0;
TwoDMatrix *memo;

int 
max(int a, int b)
{
    return (a > b)? a : b;
}
 
void
lcs( char *X, char *Y, int m, int n )
{
    bool is_mLeaf = false;
    bool is_nLeaf = false;
    
    if (!m || !n) {
        return;
    }

    if (memo->get(m-1, n-1) == 1) {
        return;
    } else {
        if (X[m-1] == Y[n-1]) {
            result++;
            memo->set(m-1, n-1);
            lcs(X, Y, m-1, n-1);
        }
        else {
            lcs(X, Y, m, n-1);
            lcs(X, Y, m-1, n);
        }
    }

    return;
}
 
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
 
    int m = strlen(X);
    int n = strlen(Y);

    // Initialize memoization array
    memo = new TwoDMatrix(m, n);

    lcs(X, Y, m, n);
    
    cout << "Length of LCS is " << result << endl;
 
    return 0;
}

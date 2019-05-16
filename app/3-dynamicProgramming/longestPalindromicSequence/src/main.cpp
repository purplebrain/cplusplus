#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>

#include "TwoDMatrix.hpp"

using namespace std;

string strSequence;
int strLen;
char *strRaw;

TwoDMatrix *memo;

int
max (int p, int q)
{
	return ((p>=q)?p:q);
}

int
LPS (int i, int j)
{
	int retVal;

	if (i > j) {
		return 0;
	}

	if (i == j) {
		return 1;
	}

	if (strRaw[i] == strRaw[j]) {
		retVal = 2 + LPS(i+1, j-1);
	} else {
		retVal = max(LPS(i, j-1), LPS(i+1, j));
	}

	return (retVal);
}

int
main (int argc, char *argv[])
{
	cout << "Enter the string : ";
	cin >> strSequence;

	strLen = strSequence.length();

	strRaw = new char[strLen];
	memcpy(strRaw, strSequence.c_str(), strLen);

	memo = new TwoDMatrix(strLen, strLen);

	cout << "Longest Palindromic Sequence size : " << LPS(0, (strLen - 1)) << endl;

	return (0);
}

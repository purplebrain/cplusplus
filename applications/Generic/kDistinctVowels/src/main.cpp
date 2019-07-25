
/*
 * Given a string s we have to find the length of the longest 
 * substring of s which contain exactly K distinct vowels.
 * 
 * LINK
 * https://www.geeksforgeeks.org/longest-substring-having-_K-distinct-vowels/
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string _INPUT_STR;
char *ptrInputStr;
int _K;

set<char> gSetVowels;

void
init (void)
{
	gSetVowels.insert('a');
	gSetVowels.insert('e');
	gSetVowels.insert('i');
	gSetVowels.insert('o');
	gSetVowels.insert('u');
}

bool
isVowel (char x)
{
	bool retVal = false;

	if (gSetVowels.find(x) != gSetVowels.end()) {
			retVal = true;
	}

	return (retVal);
}

int
findKDistinctVowels (char *ptrInputStr, int inputLen, int _K)
{
	int retVal = 0;
	int idxStart = 0;
	int idxEnd = -1;	
	vector<int> vecIdxVowels;
	set<char> lSetVowels;

	for (int i = 0; i < inputLen; i++) {
			char x = ptrInputStr[i];
			if (isVowel(x)) {
					if (lSetVowels.find(x) == lSetVowels.end()) {
							if (lSetVowels.size() == _K) {
									lSetVowels.erase(ptrInputStr[*vecIdxVowels.begin()]);
									vecIdxVowels.erase(vecIdxVowels.begin());
									idxStart = *vecIdxVowels.begin() + 1;
									vecIdxVowels.push_back(i);
							} else {
									lSetVowels.insert(x);
									vecIdxVowels.push_back(i);
							}
					} 
			} 

			idxEnd++;
	}

	if (lSetVowels.size() == _K) {
			retVal = idxEnd - idxStart + 1;
	}

	return (retVal);
}

int
main (int argc, char *argv[])
{
	int output = 0;

	init();

	while (1) {
		cout << endl << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter input string : ";
		cin >> _INPUT_STR;
		cout << "Enter K : ";
		cin >> _K;

		ptrInputStr = new char[_INPUT_STR.size()];
		strcpy(ptrInputStr, _INPUT_STR.c_str());
		output = findKDistinctVowels(ptrInputStr, _INPUT_STR.size(), _K);
		cout << "Longest substring with K distinct vowels is of lenght --> " << output << endl;
	}

	return (0);
}

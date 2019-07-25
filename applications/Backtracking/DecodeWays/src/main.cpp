/*
  < PROBLEM STATEMENT >
    A message containing letters from A-Z is being encoded to numbers using the following mapping:
    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given a non-empty string containing only digits, determine the total number of ways to decode it.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define DEBUG 0

#define COUT(str)   \
  do {              \
    if (DEBUG) {    \
      cout << str;  \
    }               \
  } while (0);

map<unsigned int, string> gMapNum2Alpha;
string gInputStr;
unsigned int gInputSize;

void
init (void)
{
  // Fill up the map
  for (int i = 0; i < 26; i++) {
    char asciiSymbol = 'A' + i;
    string strTmp(1, asciiSymbol);
    gMapNum2Alpha.insert(make_pair((i+1), strTmp));
  }

  gInputSize = gInputStr.size();
}

void
processDecodedWays (vector<string>& vecPartial)
{
  vector<string>::iterator itr;
  cout << "[";
  for (itr = vecPartial.begin(); itr != vecPartial.end(); itr++) {
    cout << *itr << " ";
  }
  cout << "]" << endl;
  return;
}

bool
isConstraintSatisfied (int idx, int wSize)
{
  if ((idx+wSize) == gInputSize) {
    return (true);
  }
  return (false);
}

void
DecodeWays (int idx, int wSize, vector<string> vecPartial)
{
  if ((idx+wSize) > gInputSize) {
    COUT(" len limit exceeded" << endl);
    return;
  }

  // Update partials
  string strTmp;
  strTmp.append(gInputStr, idx, wSize);
  unsigned int uintTmp = stoi(strTmp);
  map<unsigned int, string>::iterator itr = gMapNum2Alpha.find(uintTmp);
  if (itr != gMapNum2Alpha.end()) {
    string val = itr->second;
    COUT(" val inserted = " << val << endl);
    vecPartial.push_back(val);
  } else {
    return;
  } 

  // Constraint check
  if (isConstraintSatisfied(idx, wSize)) {
    COUT(" process partial" << endl);
    processDecodedWays(vecPartial);
    return;
  } 

  for (int w = 1; w <= 2; w++) {
    DecodeWays(idx+wSize, w, vecPartial);
  }
}

void
DecodeWays (void)
{
  vector<string> vecPartial;
  for (int wSize = 1; wSize <= 2; wSize++) {
    DecodeWays(0, wSize, vecPartial);
  }
}

int
main (int argc, char *argv[])
{
  while (1) {
    cout << endl;
    cout << "=================================" << endl;
    cout << "Enter a numeric string to decode : ";
    cin >> gInputStr;
    init();
    DecodeWays();
  }

  return (0);
} 

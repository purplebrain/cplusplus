using namespace std;

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
#include <queue>
#include <bits/stdc++.h>

string _INPUT_STR;
uint _K;
uint maxLength = 0;

typedef unsigned int uint;
typedef struct _vPos
{
  int lPos;
  uint rPos;
  char x;
} vPos_t;

#define V_SET_SIZE 5
int vMapArr[V_SET_SIZE];
queue<vPos_t> qVowels;


bool
isKDistVowels (void) 
{
  bool retVal = false;
  uint cnt = 0;

  for (int v=0; v < V_SET_SIZE; v++) {
    if (vMapArr[v] != 0) {
      cnt++;
    }
    if (cnt == _K) {
      retVal = true;
    }
  }

  return retVal;
}

int
getVIdxInMap (char x)
{
  switch (x) {
    case 'a':
      return 0;
      break;
    case 'A':
      return 0;
      break;
    case 'e':
      return 1;
      break;
    case 'E':
      return 1;
      break;
    case 'i':
      return 2;
      break;
    case 'I':
      return 2;
      break;
    case 'o':
      return 3;
      break;
    case 'O':
      return 3;
      break;
    case 'u':
      return 4;
      break;
    case 'U':
      return 4;
      break;
    default:
      return (-1);
      break;
  }
}

bool
isVowel (char x)
{
  if ((x == 'a') || (x == 'A') ||
      (x == 'e') || (x == 'E') ||
      (x == 'i') || (x == 'I') ||
      (x == 'o') || (x == 'O') ||
      (x == 'u') || (x == 'U')) {
    return true;
  }

  return false;
}

int
main (int argc, char *argv[])
{
  cout << "Enter the input string : ";
  cin >> _INPUT_STR;
  cout << endl;
  uint strLen = _INPUT_STR.length();
  char str[strLen];
  strcpy(str, _INPUT_STR.c_str());

  cout << "Enter the value of '_K' : ";
  cin >> _K;
  cout << endl;

  uint pos1 = 0;
  uint pos2 = 0;
  uint diff = 0;
  vPos_t V;

  for (uint i = 0; i < strLen; i++)
  {
    if (isVowel(str[i])) {
      V.lPos = (i-1);
      V.rPos = (i+1);
      V.x = str[i];
      vMapArr[getVIdxInMap(str[i])]++;
      qVowels.push(V);
    }
    if (qVowels.size() > _K) {
      V = qVowels.front();
      pos1 = V.rPos;
      pos2 = i;
      vMapArr[getVIdxInMap(str[i])]--;
      qVowels.pop();
      if (isKDistVowels()) {
        diff = (pos2 - pos1) + 1;
        if (maxLength < diff) {
          maxLength = diff;
        }
      }
    }
  }

  if (isKDistVowels()) {
    V = qVowels.back();
    if(V.rPos < (strLen - 1)) {
      pos2 = (strLen - 1);
    }
    diff = (pos2 - pos1) + 1;
    if (maxLength < diff) {
      maxLength = diff;
    }
  }
  

  cout << "Longest substring having '_K' distinct vowels is : " << maxLength << endl;

  return (0);
}

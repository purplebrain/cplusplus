#include <iostream>
#include <utility>
#include <functional>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<string>> gVecResult;
vector<string> gInputVecWordList;
string gStrAlphabetList = "abcdefghijklmnopqrstuvwxyz";
unordered_set<string> gDictionary;
unsigned int gInputNumWords;
string gInputBeginWord;
string gInputEndWord;

bool
is_diff_one (string strX, string strY)
{
  bool retVal = false;
  unsigned int numDiff = 0;
  for (int i = 0; i < strX.size(); i++) {
    if (strX[i] != strY[i]) {
      numDiff++;
    }
    if (numDiff > 1) {
      return (false);
    }
  }
  if (numDiff == 1) {
    return (true);
  }

  return (retVal);
}

vector<vector<string>> 
findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
  vector<vector<string>> gVecResult;
  priority_queue<int, vector<int>, greater<int>> pqPathSize;
  pqPathSize.push(9999);

  // Insert all the words in the wordlist into a hash table.
  for (auto word : wordList) {
    gDictionary.insert(word);
  }

  string strParent = beginWord;
  queue<vector<string>> qPaths;
  {
    vector<string> tmp;
    tmp.push_back(strParent);
    qPaths.push(tmp);
  }
  while (!qPaths.empty()) {
    vector<string> curPath = qPaths.front();
    qPaths.pop();
    strParent = curPath[curPath.size() - 1];
    for (int pos = 0; pos < strParent.size(); pos++) {
      string strNeighbor = strParent;
      for (int alphabet=0; alphabet < gStrAlphabetList.size(); alphabet++) {
        if (alphabet == (strParent[pos] - 'a')) {
          continue;
        }
        strNeighbor.replace(pos, 1, gStrAlphabetList.substr(alphabet,1));
        if (gDictionary.find(strNeighbor) != gDictionary.end()) {
          // Neighbor differs from Parent by 1 alphabet. So, found a valid neighbor
          if ((curPath.size()+1) > pqPathSize.top()) {
            continue;
          } else {
            if (strNeighbor == endWord) {
              curPath.push_back(endWord);
              pqPathSize.push(curPath.size());
              gVecResult.push_back(curPath);
              break;
            } else if (strNeighbor != endWord) {
              curPath.push_back(strNeighbor);
              qPaths.push(curPath);
              curPath.pop_back();
            }
          }
        }
      }
    }
  }
  return (gVecResult);
}

int
main (int argc, char *argv[])
{ 
	while (1) {
		gVecResult.clear();
		gInputVecWordList.clear();
		cout << "\n\n==================";
		cout << "\nEnter number of words in word-list : ";
		cin >> gInputNumWords;
		cout << "Enter words in word-list\n";
		string strTmp;
		for (int i = 0; i < gInputNumWords; i++) {
			cout << "Word-" << i << " : ";
			cin >> strTmp;
			gInputVecWordList.push_back(strTmp);
		}
		cout << "Enter beginWord = ";
		cin >> gInputBeginWord;
		cout << "Enter endWord = ";
		cin >> gInputEndWord;
    cout << "\nResult";
    findLadders(gInputBeginWord, gInputEndWord, gInputVecWordList);
    if (gVecResult.size()) {
      for (auto& itr1 : gVecResult) {
        cout << "\n[ ";
        for (auto itr2 : itr1) {
          cout << itr2 << ", ";
        }
        cout << "]";
      }
    } else {
      cout << "\nNo word ladder";
    }
	}

	return (0);
}


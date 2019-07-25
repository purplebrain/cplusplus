#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string gStrInputPhrase;
unordered_set<string> gDict;

void
printDebugs(string strPartialRemainingPhrase,
            int idx, 
            vector<string> vecPartialWordList, 
            string strPartialWord,
            string strOperation)
{
  #if(DEBUG)
  cout << "DEBUG : [" << strOperation << "] "; 
  cout << "StrRemaining = " << strPartialRemainingPhrase << ", ";
  cout << "Index = " << idx << ", ";
  cout << "WordList = "; 
  for (vector<string>::iterator itr = vecPartialWordList.begin();
       itr != vecPartialWordList.end();
       itr++) {
       cout << " " << *itr;
  }
  cout << ", ";
  cout << "PartialWord = " << strPartialWord << endl;
  #endif
  return;
}

void
printResult(vector<string> vecPartialWordList)
{
  vector<string>::iterator itr;
  cout << "SENTENCE : ";
  for (itr = vecPartialWordList.begin(); 
       itr != vecPartialWordList.end();
       itr++) {
    cout << " " << *itr;
  }
  cout << endl;
}

unordered_set<string>::iterator
isWordInDict (string& strPartialWord)
{
  return (gDict.find(strPartialWord));
}

void
breakWords (string strPartialRemainingPhrase, vector<string> vecPartialWordList)
{
  if ((strPartialRemainingPhrase.size() == 0) && 
      vecPartialWordList.size()) {
    printResult(vecPartialWordList);
    return;
  }

  string strPartialWord;
  for (int i = 0; i < strPartialRemainingPhrase.size(); i++) {
    strPartialWord.insert(strPartialWord.size(), 1, strPartialRemainingPhrase[i]);
    printDebugs(strPartialRemainingPhrase, i, vecPartialWordList, strPartialWord, "APPEND");
    if (isWordInDict(strPartialWord) != gDict.end()) {
      vecPartialWordList.push_back(strPartialWord);
      printDebugs(strPartialRemainingPhrase, i, vecPartialWordList, strPartialWord, "PUSH");
      int idxExtract = i + 1;
      int lenExtractLen = strPartialRemainingPhrase.size() - idxExtract;
      string strRemainingPhrase = strPartialRemainingPhrase.substr(idxExtract, lenExtractLen);
      breakWords(strRemainingPhrase, vecPartialWordList);
      vecPartialWordList.pop_back();
      printDebugs(strPartialRemainingPhrase, i, vecPartialWordList, strPartialWord, "POP");
    }
  }

  return;
}

void 
breakWords (void) 
{
  vector<string> vecPartialWordList;
  string strPartialWord;
  breakWords(gStrInputPhrase, vecPartialWordList);

  return;
}

int
main (int argc, char *argv[])
{
  while (1) {
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter the phrase to be broken : ";
    cin >> gStrInputPhrase;
    cout << "Enter words in dictionary ('zzz' to finish entrying)" << endl;
    while (1) {
      string strTmp;
      cout << "Dictionary Word : ";
      cin >> strTmp;
      if (!strTmp.compare("zzz")) {
        break;
      } else {
        gDict.insert(strTmp);
      }
    }

    breakWords();
  }
}

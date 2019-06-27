#include <iostream>
#include <string>

using namespace std;

bool
CheckPalindrome (string str, int idxBegin, int idxEnd)
{
  if (idxBegin >= idxEnd) {
    return true;
  }

  if (str[idxBegin] == str[idxEnd]) {
    return CheckPalindrome(str, ++idxBegin, --idxEnd);
  }

  return false;
}


int
main (int argc, char *argv[])
{
  int inputChoice;
  string inputString;
  int inputStringLen;
  bool isExit = false;

  while (1) {
    cout << endl;
    cout << "----------------------------" << endl;
    cout << "Pick an option : " << endl;
    cout << "0] Exit" << endl;
    cout << "1] Palindrome-check" << endl;
    
    cin >> inputChoice;
    
    switch (inputChoice) {
    case 0:
      isExit = true;
      break;
    case 1:
      cout << "Enter a new string for Palindrome-check : ";
      cin >> inputString;
      inputStringLen = inputString.size();
      if (CheckPalindrome(inputString, 0, inputStringLen-1)) {
        cout << "RESULT: Palindrome" << endl;
      } else {
        cout << "RESULT: Not a Palindrome" << endl;
      }
      break;
     default:
       break;
    } 
    
    if (isExit) {
      break;
    }
  }

  return 0;
}

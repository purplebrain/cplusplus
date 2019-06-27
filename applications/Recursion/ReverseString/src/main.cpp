#include <iostream>
#include <string>

using namespace std;

#define BEGIN 0

void
ReverseString (string& resultStr, string str, int idx)
{
  if (idx == str.size()) {
    return;
  }
  ReverseString (resultStr, str, idx+1);
  resultStr.append(str, idx, 1);
  return;
}

int
main (int argc, char *argv[])
{
  int inputChoice = 0;
  string inputStr;
  string resultStr;
  bool isExit = false;

  while (1) {
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "Pick an option : " << endl;
    cout << "0] Exit" << endl;
    cout << "1] Reverse String" << endl;
    
    cin >> inputChoice;

    switch (inputChoice) {
    case 0:
      isExit = true;
      break;
    case 1:
      cout << "Enter a new string to Reverse : ";
      cin >> inputStr;
      resultStr.erase();
      ReverseString(resultStr, inputStr, BEGIN);
      cout << "RESULT : " << resultStr << endl;
      cin.clear();
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

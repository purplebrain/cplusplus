#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, string> num_to_char; 
vector<string> result;

void
init (void)
{
  num_to_char['2'] = "abc"; 
  num_to_char['3'] = "def"; 
  num_to_char['4'] = "ghi"; 
  num_to_char['5'] = "jkl"; 
  num_to_char['6'] = "mno"; 
  num_to_char['7'] = "pqrs"; 
  num_to_char['8'] = "tuv"; 
  num_to_char['9'] = "wxyz"; 
}

void 
letterCombinations(string digits, 
                   int idx,
                   string& combination)
{
  if (idx == digits.length()) {
    return;
  }

  if (combination.length() == digits.length()){
      result.push_back(combination);
      return;
  }
  
  string mappedStr = num_to_char[digits[idx]];
  for (int i = 0; i < mappedStr.size(); i++) {
      combination[idx] = mappedStr[i];
      letterCombinations(digits, idx+1, combination);
  }
}

void
letterCombinations(string digits) 
{
  string combination(digits.length(), ' ');
  letterCombinations(digits, 0, combination); 
                    // (input, picker, partial_output)
  return;
}
    
int
main (int argc, char *argv[])
{
  bool isExit = false;
  int cmd_option;

  while (1) {
    string digits;
	  cout << endl;
	  cout << "########### COMMAND LINE ###########" << endl;
    cout << "0] Exit" << endl;
    cout << "1] Keypad" << endl;
    cin >> cmd_option;
    switch (cmd_option) {
    case 0:
      isExit = true;
      break;
    case 1:
	    cout << "Punch a number in the range [2..9] on the keypad : ";
      cin >> digits;
      if (digits.empty()) {
        cout << "Enter a valid input" << endl;
        continue;
      }
      if (!result.empty()) {
        result.clear();
      }
      letterCombinations(digits);
      for (vector<string>::iterator itr = result.begin(); itr != result.end(); itr++) {
        cout << *itr << endl;
      }
      break;
    default:
      cout << "Enter a valid command line option" << endl;
      break;
    }

    if (isExit) {
      break;
    }
  }

  return 0;
}

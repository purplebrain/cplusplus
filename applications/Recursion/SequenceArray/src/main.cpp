#include <iostream>
#include <string>

using namespace std;

int *gArray;
int arrSize;

bool
IsSequenceArray(int *arr, int idx) {
  if (idx == arrSize-1) {
    return true;
  }

  if ((gArray[idx] + 1) == gArray[idx+1]) {
    return (IsSequenceArray(arr, idx+1));
  }

  return false;
}


int
main (int argc, char *argv[])
{
  bool isExit = false;
  int inputChoice;
  
  while (1) {
    cout << endl;
    cout << "########## COMMAND LINE #########" << endl;
    cout << "Pick a choice" << endl;
    cout << "0] Exit" << endl;
    cout << "1] Sequence Array check" << endl;
    cin >> inputChoice;
    switch (inputChoice) {
    case 0:
      isExit = true;
      break;
    case 1:
      cout << "Enter size of array : ";
      cin >> arrSize;
      if (gArray) {
        delete [] gArray;
      }
      gArray = new int[arrSize];
      for (int i=0; i<arrSize; i++) {
        cout << "Enter array element - " << i << " : ";
        cin >> gArray[i];
      }
      if (IsSequenceArray(gArray, 0)) {
        cout << "RESULT: Sequence Array" << endl;
      } else {
        cout << "RESULT: Non-Sequence Array" << endl;
      }
    default:
      break;
    }

    if (isExit) {
      break;
    }
  }

  return (0);
}

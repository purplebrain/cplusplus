#include "MyPrintArrayUtils.hpp"

void
MyPrintArrayUtils::print_array_helper (int *inputArr, int size)
{
  if (size > 1) {
      for (int i = 0; i < size; i++) {
        if (i == 0) {
            cout << "[ " << inputArr[i] << " ";
        } else if (i == (size-1)) {
            cout << ", " << inputArr[i] << " ]" << endl;
        } else {
            cout << ", " << inputArr[i];
        }
      }
  } else if (size == 1) {
      cout << "[ " << inputArr[0] << " ]" << endl;
  } else {
      cout << "[ NONE ]" << endl;
  }
}

void
MyPrintArrayUtils::print_array (int *inputArr, int size) 
{
  print_array_helper(inputArr, size);
}

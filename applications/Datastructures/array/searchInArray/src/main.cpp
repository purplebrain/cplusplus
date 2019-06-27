#include <iostream>
#include <cstddef>
#include "MyPrintArrayUtils.hpp"
#include "MySearchArrayUtils.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
	int inputArr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
	string inputStr;
	int inputValue;

	while (1) {
  	cout << endl;
    cout << "------------------------------------------------------" << endl;
	  cout << "Enter type of search: " << endl;
    cout << "1 for linear search" << endl;
    cout << "2 for binary search" << endl;
    cout << "3 for jump search" << endl;
    cout << "4 for interpolation search" << endl;
    cout << "5 for exponential search" << endl;
    cout << "6 for fibonacci search" << endl;
    cout << "exit to quit" << endl;

	  cin >> inputStr;
		if (!inputStr.compare("exit")) {
        cout << "quitting..." << endl;
        break;
		} else if (!inputStr.compare("2")) {
        cout << "Doing binary search, enter int value to be searched " << endl;
        cout << "value> ";
        cin >> inputStr;
        inputValue = stoi(inputStr, NULL, 10);
        if (MySearchArrayUtils::binary_search(inputArr, 8, inputValue)) {
            cout << "value : " << inputValue << " found in the array" << endl;
        } else {
            cout << "value : " << inputValue << " not found" << endl;
        }
    } else {
        cout << "invalid input" << endl;
        continue;
    }
	}

	return (0);
}

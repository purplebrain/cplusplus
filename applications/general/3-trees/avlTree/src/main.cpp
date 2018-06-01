using namespace std;

#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

#include "MyTreeUtils.hpp"
#include "MyBinSearchTree.hpp"

int
main (int argc, char *argv[])
{
	MyBinSearchTree myBst;
	string inputStr;
	int inputValue;

	while (1) {
        cout << endl;
        cout << "------------------------------------------------------" << endl;
	    cout << "Enter the following: " << endl;
        cout << "insert     --> to insert a node" << endl;
        cout << "delete     --> to delete a node" << endl;
        cout << "treedump   --> to print tree in InOrder" << endl;
        cout << "exit       --> to exit and print final tree in InOrder" << endl;
	    cin >> inputStr;
		if (!inputStr.compare("treedump")) {
			MyTreeUtils::print_in_order(myBst.ptrRoot);
            continue;
		} else if (!inputStr.compare("insert")) {
            cout << "Enter integer : ";
            cin >> inputStr;
            inputValue = stoi(inputStr, NULL, 10);
		    myBst.insert_avl(inputValue);
            continue;
        } else if (!inputStr.compare("delete")) {
            cout << "Enter integer : ";
            cin >> inputStr;
            inputValue = stoi(inputStr, NULL, 10);
            myBst.delete_avl(inputValue);
            continue;
        } else if (!inputStr.compare("stop")) {
            break;
        }
	}

	MyTreeUtils::print_in_order(myBst.ptrRoot);
}


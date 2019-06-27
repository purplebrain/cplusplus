#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

#include "MyTreeUtils.hpp"
#include "MyBinSearchTree.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
	MyBinSearchTree myBst;
	string inputStr;
	int inputValue;

	while (1) {
	    cout << "Enter integer value to insert, -1 to stop" << endl;
	    cin >> inputValue;
		if (inputValue == -1) {
			break;
		} else {
			myBst.insert(inputValue);
		}
	}

	MyTreeUtils::print_in_order(myBst.ptrRoot);

	//	Get the max node in the BST
	MyTreeNode *ptrMaxNode = MyTreeUtils::getMaxNodeInBst(myBst.ptrRoot);
	if (ptrMaxNode) {
		cout << "max-node is : " << ptrMaxNode->data << endl;
	} else {
		cout << "No max-node" << endl;
	}

	//	Get the min node in the BST
	MyTreeNode *ptrMinNode = MyTreeUtils::getMinNodeInBst(myBst.ptrRoot);
	if (ptrMinNode) {
		cout << "min-node is : " << ptrMinNode->data << endl;
	} else {
		cout << "No min-node" << endl;
	}
	
	while (1) {
	    cout << "Enter integer value to be deleted, 'treedump' to display current tree" << endl;
	    cin >> inputStr;
		if (!inputStr.compare("treedump")) {
			MyTreeUtils::print_in_order(myBst.ptrRoot);
			cout << "Do you want to exit?[y/n]" << endl;
			cin >> inputStr;
			if (inputStr == "y") {
				break;
			} else {
				continue;
			}
		} else {
			myBst.deleteNode(stoi(inputStr, NULL, 10));
		}
	}

    return (0);
}

#include <iostream>
#include <cstddef>

#include "MyTreeUtils.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
    MyTreeNode *ptrRoot = NULL;

	ptrRoot = new MyTreeNode(10);
	ptrRoot->ptrLeft = new MyTreeNode(3);
	ptrRoot->ptrRight = new MyTreeNode(7);
	ptrRoot->ptrRight->ptrLeft = new MyTreeNode(6);
	ptrRoot->ptrRight->ptrRight = new MyTreeNode(1);
	ptrRoot->ptrRight->ptrLeft->ptrRight = new MyTreeNode(4);
	ptrRoot->ptrRight->ptrLeft->ptrLeft = new MyTreeNode(2);

    /*
    if (MyTreeUtils::isSumPropertyBinTree(binTree.ptrRoot)) {
        cout << "Is a sum property binary tree" << endl;
    } else {
        cout << "Not a sum property binary tree" << endl;
    }*/
    
    int ht = MyTreeUtils::getHeight(ptrRoot);
    cout << "Height of tree : " << ht << endl;

    int sum2 = MyTreeUtils::sumOfTree(ptrRoot);
    cout << "Sum of the tree : " << sum2 << endl;

    int sum1 = MyTreeUtils::sumOfChildren(ptrRoot);
    cout << "Sum of all children : " << sum1 << endl;

    if (MyTreeUtils::isBalanced(ptrRoot)) {
        cout << "Tree is balanced" << endl;
    } else {
        cout << "Tree is not balanced" << endl;
    }

    return (0);
}

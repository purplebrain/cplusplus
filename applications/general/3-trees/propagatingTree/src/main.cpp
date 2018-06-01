using namespace std;

#include <iostream>
#include <cstdlib>
#include <string>

#include "MyTreeNode.hpp"
#include "MyBinTreeNode.hpp"

/*
    foo (Base derived_obj)
        Upcasting -> This will result in object slicing
    foo (Derived base_obj)
        Downcasting -> this needs explicit typecast
 */

void
print_in_order (MyTreeNode *ptrCurNode) 
{
    if (!ptrCurNode) {
        return;
    }

    // traverse left
    print_in_order(ptrCurNode->ptrLeft);

    // process root
    cout << ptrCurNode->data << "(" << ptrCurNode->height << ")" << " "; 
    //cout << ptrCurNode->data << "(" + ptrCurNode->height + ")" << " "; 

    // traverse right
    print_in_order(ptrCurNode->ptrRight);
}

int
MyBinSearchTree::getTHeight (void)
{
    return (this->THeight);
}

MyTreeNode *
MyBinSearchTree::getInOrderSuccessor (MyTreeNode *ptrCurNode)
{
    MyTreeNode *ptrRetNode = NULL;

    while (ptrCurNode) {
        ptrRetNode = ptrCurNode;
        ptrCurNode = ptrCurNode->ptrLeft;
    }
 
    return (ptrRetNode);
}

MyTreeNode *
MyBinSearchTree::find (MyTreeNode *ptrCurNode, int value)
{
    MyTreeNode *ptrRetNode = NULL;

    while (ptrCurNode) {
        if (value < ptrCurNode->data) {
            ptrCurNode = ptrCurNode->ptrLeft;
        } else if (value > ptrCurNode->data) {
            ptrCurNode = ptrCurNode->ptrRight;
        } else {
            ptrRetNode = ptrCurNode;
            cout << "Key found" << endl;
            break;
        }
    }
 
    return (ptrRetNode);
}

MyTreeNode *
MyBinSearchTree::remove (MyTreeNode *ptrCurNode, int value)
{
    int htLeft = 0;
    int htRight = 0;
    bool isCurNodeTarget = false;

    if (!ptrCurNode) {
        cout << "Key not found, nothing to remove" << endl;
        return NULL;
    } 

    if (value == ptrCurNode->data) {
        // CASE: ptrCurNode is leaf-node
        if (!ptrCurNode->ptrLeft && !ptrCurNode->ptrRight) {
            delete ptrCurNode;
            return NULL;
        }

        // CASE: ptrCurNode has only one child
        if (!ptrCurNode->ptrLeft) {
            // has only right child
            MyTreeNode *ptrTmpNode = ptrCurNode->ptrRight;
            delete ptrCurNode;
            return (ptrTmpNode);
        } else if (!ptrCurNode->ptrRight) {
            // has only left child
            MyTreeNode *ptrTmpNode = ptrCurNode->ptrLeft;
            delete ptrCurNode;
            return (ptrTmpNode);
        }

        // CASE: ptrCurNode has both children
        MyTreeNode *ptrIoSucNode = getInOrderSuccessor(ptrCurNode->ptrRight);
        ptrCurNode->data = ptrIoSucNode->data;
        ptrCurNode->ptrRight = remove(ptrCurNode->ptrRight, ptrIoSucNode->data);
        isCurNodeTarget = true;
    }

    if (!isCurNodeTarget) {
        if (value < ptrCurNode->data) {
            ptrCurNode->ptrLeft = remove(ptrCurNode->ptrLeft, value);
        } else if (value > ptrCurNode->data) {
            ptrCurNode->ptrRight = remove(ptrCurNode->ptrRight, value);
        } else {
            cout << "Key already exists, not inserting" << endl;
        }
    }

    if (ptrCurNode->ptrLeft) {
        htLeft = ptrCurNode->ptrLeft->height;
    }

    if (ptrCurNode->ptrRight) {
        htRight = ptrCurNode->ptrRight->height;
    }

    ptrCurNode->height = 1 + ((htLeft >= htRight) ? htLeft : htRight);

    if (ptrCurNode == this->ptrRoot) {
        this->THeight = ptrCurNode->height;
    }
    
    return (ptrCurNode);
}

MyTreeNode *
MyBinSearchTree::insert (MyTreeNode *ptrCurNode, int value)
{
    int htLeft = 0;
    int htRight = 0;

    if (!ptrCurNode) {
        ptrCurNode = new MyTreeNode(value);
        if (this->Tsize == 0) {
            cout << "Inserting first key in tree" << endl;
            this->ptrRoot = ptrCurNode;
        }
        this->Tsize++;
        ptrCurNode->secretNum = (rand() % (2*this->Tsize));
				ptrCurNode->height = 1;
        this->THeight = ptrCurNode->height;
        return (ptrCurNode);
    }

    if (value < ptrCurNode->data) {
        ptrCurNode->ptrLeft = insert(ptrCurNode->ptrLeft, value);
    } else if (value > ptrCurNode->data) {
        ptrCurNode->ptrRight = insert(ptrCurNode->ptrRight, value);
    } else {
        cout << "Key already exists, not inserting" << endl;
    }

    //  Evaluate Height 
    if (ptrCurNode->ptrLeft) {
        htLeft = ptrCurNode->ptrLeft->height;
    }
    if (ptrCurNode->ptrRight) {
        htRight = ptrCurNode->ptrRight->height;
    }
    ptrCurNode->height = 1 + ((htLeft >= htRight) ? htLeft : htRight);
    if (ptrCurNode == this->ptrRoot) {
        this->THeight = ptrCurNode->height;
    }

    //  Evaluate [min, max] subtree values
    if (!ptrCurNode->minSubTreeValue || (value < ptrCurNode->minSubTreeValue)) {
        ptrCurNode->minSubTreeValue = value;
    }
    if (!ptrCurNode->maxSubTreeValue || (value > ptrCurNode->maxSubTreeValue)) {
        ptrCurNode->maxSubTreeValue = value;
    }

    return (ptrCurNode);
}

void
predefine_bst(MyBinSearchTree *ptrBst) 
{
    ptrBst->insert(ptrBst->ptrRoot, 25);
    ptrBst->insert(ptrBst->ptrRoot, 15);
    ptrBst->insert(ptrBst->ptrRoot, 10);
    ptrBst->insert(ptrBst->ptrRoot, 20);
    ptrBst->insert(ptrBst->ptrRoot, 35);
    ptrBst->insert(ptrBst->ptrRoot, 40);
    ptrBst->insert(ptrBst->ptrRoot, 30);

    return;
}

int
main (int argc, char *argv[])
{
    string inputStr;
    int inputVal;
    MyBinSearchTree bst;
    MyTreeNode *ptrNode;

    predefine_bst(&bst);

    while(1) {
        cout << endl;
        cout << "---------------------" << endl;
        cout << "Enter the following: " << endl;
        cout << "ins\t to insert" << endl;
        cout << "del\t to delete" << endl;
        cout << "print\t to print in order" << endl;
        cout << "find\t to search" << endl;
        cout << "quit\t to exit" << endl;
        cin >> inputStr;
        if (!inputStr.compare("ins")) {
            cout << "Enter integer to insert : ";
            cin >> inputVal;
            bst.insert(bst.ptrRoot, inputVal);
        } else if (!inputStr.compare("del")) {
            cout << "Enter integer to remove : ";
            cin >> inputVal;
            bst.remove(bst.ptrRoot, inputVal);
        } else if (!inputStr.compare("print")) {
            cout << "Printing in InOrder" << endl;
            print_in_order(bst.ptrRoot);
            cout << endl;
            cout << "Height of the tree is : " << bst.getTHeight() << endl;
        } else if (!inputStr.compare("find")) {
            cout << "Enter integer key to find in tree : ";
            cin >> inputVal;
            ptrNode = bst.find(bst.ptrRoot, inputVal);
            if (ptrNode) {
                cout << "Key node found @ " << ptrNode << endl;
                cout << "SubTree Height     : " << ptrNode->height << endl;
                cout << "SubTree [min, max] : " << "[" << ptrNode->minSubTreeValue \
                                                << ", " << ptrNode->maxSubTreeValue << "]" << endl;
                cout << "Secret Number      : " << ptrNode->secretNum << endl;
            }
        } else if (!inputStr.compare("quit")) {
            cout << "Exiting!" << endl;
            break;
        } else {
            cout << "Invalid input" << endl;
            continue;
        }
    }

    return (0);
}

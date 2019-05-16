#include <iostream>
#include <stack>

#include "MyTreeNode.hpp"

using namespace std;

int
main (int argc, char *argv[])
{

    MyTreeNode *ptrRoot = NULL;
    MyTreeNode *ptrCurNode = NULL;
    stack<MyTreeNode *> stackTreeNode;

    ptrRoot = new MyTreeNode(10);
    ptrRoot->ptrLeft = new MyTreeNode(17);
    ptrRoot->ptrRight = new MyTreeNode(20);

    ptrRoot->ptrLeft->ptrLeft = new MyTreeNode(14);
    ptrRoot->ptrLeft->ptrRight = new MyTreeNode(16);

    ptrRoot->ptrRight->ptrLeft = new MyTreeNode(32);
    ptrRoot->ptrRight->ptrRight = new MyTreeNode(36);

    ptrRoot->ptrLeft->ptrRight->ptrLeft = new MyTreeNode(21);
    ptrRoot->ptrLeft->ptrRight->ptrRight = new MyTreeNode(23);

    cout << "Iterative in-order traversal" << endl;
    ptrCurNode = ptrRoot;
    stackTreeNode.push(ptrCurNode);
    while (1) {
        // traverse left
        if (ptrCurNode->ptrLeft) {
            stackTreeNode.push(ptrCurNode->ptrLeft);
            ptrCurNode = ptrCurNode->ptrLeft;
            continue;
        }

        // process root
        if (stackTreeNode.size()) {
            ptrCurNode = stackTreeNode.top();
            stackTreeNode.pop();
            cout << ptrCurNode->data << " ";
        } else {
            break;
        }

        // traverse right
        if (ptrCurNode->ptrRight) {
            stackTreeNode.push(ptrCurNode->ptrRight);
            ptrCurNode = ptrCurNode->ptrRight;
            continue;
        }
    }
    cout << endl;

    cout << "Iterative pre-order traversal" << endl;
    ptrCurNode = ptrRoot;
    stackTreeNode.push(ptrCurNode);
    while (1) {
        // process root
        if (stackTreeNode.size()) {
            ptrCurNode = stackTreeNode.top();
            stackTreeNode.pop();
            cout << ptrCurNode->data << " ";
        } else {
            break;
        }

        // traverse left, so push right into stack before going left
        if (ptrCurNode->ptrRight) {
            stackTreeNode.push(ptrCurNode->ptrRight);
        }

        // traverse right
        if (ptrCurNode->ptrLeft) {
            stackTreeNode.push(ptrCurNode->ptrLeft);
        }
    }
    cout << endl;

    cout << "Iterative post-order traversal" << endl;
    MyTreeNode *ptrPrevNode = NULL;
    ptrCurNode = ptrRoot;
    do {
        if (ptrCurNode) {
            stackTreeNode.push(ptrCurNode);
            if (!ptrPrevNode || 
                (ptrCurNode->ptrLeft != ptrPrevNode)) {
                ptrCurNode = ptrCurNode->ptrLeft;
            } else {
                ptrCurNode = NULL;
            }
        } else {
            ptrCurNode = stackTreeNode.top();
            if (ptrCurNode->ptrRight && 
                (ptrCurNode->ptrRight != ptrPrevNode)) {
                ptrCurNode = ptrCurNode->ptrRight;
                continue;
            } else {
                cout << ptrCurNode->data << " ";
                stackTreeNode.pop();
                ptrPrevNode = ptrCurNode;
                ptrCurNode = NULL;
            }
        }
    } while (stackTreeNode.size());
    cout << endl;

    return (0);
}

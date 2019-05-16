#include <iostream>
#include <cstddef>

#include "MyTreeUtils.hpp"
#include "MyBinTree.hpp"
#include "MyStackTreeNode.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
    MyBinTree binTree;
    MyTreeNode *ptrNode = NULL;

	binTree.ptrRoot = new MyTreeNode(1);
	binTree.ptrRoot->ptrLeft = new MyTreeNode(2);
	binTree.ptrRoot->ptrRight = new MyTreeNode(3);
	binTree.ptrRoot->ptrRight->ptrLeft = new MyTreeNode(4);
	binTree.ptrRoot->ptrRight->ptrRight = new MyTreeNode(5);
	//binTree.ptrRoot->ptrRight->ptrRight = new MyTreeNode(7);

    MyStackTreeNodeNode *ptrStackNode3;
    MyStackTreeNode stack3;
    ptrNode = binTree.ptrRoot;
    cout << "Iterative PostOrder traversal using a single stack" << endl;
    do {
        while (ptrNode) {
            if (ptrNode->ptrRight) {
                stack3.push(ptrNode->ptrRight);
            }
            stack3.push(ptrNode);
            ptrNode = ptrNode->ptrLeft;
        }
        ptrStackNode3 = stack3.pop();
        ptrNode = ptrStackNode3->ptrDataTreeNode;
        if (stack3.getSize() &&
            ptrNode->ptrRight &&
            (ptrNode->ptrRight == stack3.ptrTOS->ptrDataTreeNode)) {
            stack3.pop(); // pop ptrRight
            stack3.push(ptrNode); // push ptrRoot
            ptrNode = ptrNode->ptrRight;
        } else {
            cout << ptrNode->data << " ";
            ptrNode = NULL;
        }
    } while (stack3.getSize());
    cout << endl;
/*
    MyStackTreeNodeNode *ptrStackNode;
    MyStackTreeNode stack;
    MyTreeNode *ptrCurTask, *ptrTask2, *ptrTask3;
    ptrCurTask = binTree.ptrRoot;
    cout << "Iterative PostOrder traversal using a single stack ver-2" << endl;
    do {
        // In total there are three tasks
        // Task-1: traverse left
        // Task-2: traverse right
        // Task-3: print root

        while (ptrCurTask) {
            // Store Task-3
            stack.push(ptrCurTask);

            // Store Task-2
            stack.push(ptrCurTask->ptrRight);

            // Execute Task-1
            ptrCurTask = ptrCurTask->ptrLeft;
        }

        // Get Task-2
        ptrStackNode = stack.pop();
        if (ptrStackNode) {
            ptrTask2 = ptrStackNode->ptrDataTreeNode;
        }
        // Execute Task-2
        if (ptrTask2) {
            if (MyTreeUtils::isLeafNode(ptrTask2)) {
                cout << ptrTask2->data << " ";
            } else {
                if (ptrTask2->ptrLeft) {
                    ptrCurTask = ptrTask2->ptrLeft;
                } else if (ptrTask2->ptrRight) {
                    ptrCurTask = ptrTask2->ptrRight;
                }
                continue;
            }
        }
   
        // Get Task-3
        ptrStackNode = stack.pop();
        if (ptrStackNode) {
            ptrTask3 = ptrStackNode->ptrDataTreeNode;
        }
        // Execute Task-3 (for which Task-2 should be fully done)
        if (ptrTask3) {
            cout << ptrTask3->data << " ";
        }

        ptrCurTask = NULL;

    } while (stack.getSize());
    cout << endl;
*/
    return (0);
}

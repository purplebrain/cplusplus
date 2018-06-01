
#include "MyBinTree.hpp"

MyTreeNode *
MyBinTree::insert_helper (MyTreeNode **ptrNode, int value)
{
    // Since there is no ordering, we randomly generate a
    // value to determine if we take left or right direction
    // and insert it.
/*
    int direction; 

    // initialize random seed
    srand (time(NULL));

    // generate either 0 (for left) or 1 (for right)
    direction = rand() % 2;

	if (this->Tsize == 0) {
		  cout << "inserting first node in the tree" << endl;
	}

    if (!(*ptrNode)) {
        *ptrNode = new MyTreeNode(value);
        this->Tsize++;
    } else {
        // pick a direction and insert there
        if (direction) {
            // insert to the right-side
            insert_helper(&(*ptrNode)->ptrRight, value);
        } else {
            // insert to the left-side
            insert_helper(&(*ptrNode)->ptrLeft, value);
        }
    }
*/
    return (*ptrNode);
}

void
MyBinTree::insert (int value)
{
	if (this->Tsize == 0) {
		cout << "inserting first node in the tree" << endl;
	}

    insert_helper(&(this->ptrRoot), value);
}

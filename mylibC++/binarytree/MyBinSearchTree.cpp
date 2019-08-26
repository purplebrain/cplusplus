#include "MyStackTreeNode.hpp"
#include "MyStack.hpp"
#include "MyTreeUtils.hpp"
#include "MyBinSearchTree.hpp"

                    /*
                     * -----------------------
                     *   Binary Search Trees
                     * -----------------------
                     */
/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::deleteNode_helper ()
 *  DESCRIPTION     This method deletes a node in a binary tree.
 *                  (the tree may not be balanced)
 * -------------------------------------------------------------------------
 */
MyTreeNode *
MyBinSearchTree::deleteNode_helper (MyTreeNode *ptrNode, int value)
{
	MyTreeNode *ptrInOrderSuccessor = NULL;
    MyTreeNode *ptrTmpNode = NULL;

	if (!ptrNode) {
		return NULL;
	}

	if (value == ptrNode->data) {
        //  Case-1: target-node is a leaf-node
        if (MyTreeUtils::isLeafNode(ptrNode)) {
            delete ptrNode;
            return NULL;
        }

        //  Case-2: target-node has only one child
        if (!ptrNode->ptrLeft) {
            ptrTmpNode = ptrNode->ptrRight;
            delete ptrNode;
            return ptrTmpNode;
        } else if (!ptrNode->ptrRight) {
            ptrTmpNode = ptrNode->ptrLeft;
            delete ptrNode;
            return ptrTmpNode;
        }

        //  Case-3: target-node has two children
		ptrInOrderSuccessor = 
                    MyTreeUtils::getMinNodeInBst(ptrNode->ptrRight);
        ptrNode->data = ptrInOrderSuccessor->data;
		ptrNode->ptrRight = 
                    deleteNode_helper(ptrNode->ptrRight, 
                                      ptrInOrderSuccessor->data);
		return ptrNode;
	} else {
		// Continue traversing the BST
		if (value < ptrNode->data) {
			ptrNode->ptrLeft = deleteNode_helper(ptrNode->ptrLeft, value);
		    return (ptrNode);	 
		} 
		if (value > ptrNode->data) {
			ptrNode->ptrRight = deleteNode_helper(ptrNode->ptrRight, value);
            return (ptrNode);
		} 
	}

    return (NULL);
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::deleteNode ()
 *  DESCRIPTION     This method deletes a node in a binary tree.
 *                  (the tree may not be balanced)
 * -------------------------------------------------------------------------
 */
void
MyBinSearchTree::deleteNode (int value)
{
	if (!this->ptrRoot) {
		cout << "Tree is empty" << endl;
		return;
	}

	this->deleteNode_helper(this->ptrRoot, value);

	return;
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::insert_helper ()
 *  DESCRIPTION     This method inserts a new node in a binary tree.
 *                  (the tree may not be balanced)
 * -------------------------------------------------------------------------
 */
MyTreeNode *
MyBinSearchTree::insert_helper (MyTreeNode **ptrNode, int value)
{
	if (this->Tsize == 0) {
	    cout << "inserting first node in the tree" << endl;
	}

	if (!(*ptrNode)) {
		*ptrNode = new MyTreeNode(value);
		this->Tsize++;
		return (*ptrNode);
	} 

	if (value < (*ptrNode)->data) {
		// Traverse left child
		(*ptrNode)->ptrLeft = insert_helper(&((*ptrNode)->ptrLeft), value);
	}

	if (value > (*ptrNode)->data) {
		// Traverse right child
		(*ptrNode)->ptrRight = insert_helper(&((*ptrNode)->ptrRight), value);
	}

	return (*ptrNode);	// (is this needed??)
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::insert ()
 *  DESCRIPTION     This method inserts a new node in a binary tree.
 *                  (the tree may not be balanced)
 * -------------------------------------------------------------------------
 */
void
MyBinSearchTree::insert (int value)
{
	this->insert_helper(&(this->ptrRoot), value);
}

                    /*
                     * ----------------------
                     *       AVL Trees
                     * ----------------------
                     */

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::balance ()
 *  DESCRIPTION     This function does the balancing of the binary
 *                  search tree. The expectation is that a node was 
 *                  inserted into an already balanced tree and it became
 *                  unbalanced. Now the path of the inserted node from the
 *                  'root' should be stored in 'this->stackPath4Avl' member
 *                  of this class. Then this function will balance the tree
 *                  along with the newly inserted node.
 *  -------------------------------------------------------------------------
 */
void
MyBinSearchTree::balance ()
{
    MyStackTreeNode stackPathXYZ;
    bool isBalanceReqd = false;
    bool isRootOneSided = false;
    MyTreeNode *ptrNode = NULL;
    MyTreeNode *ptrParentOfUnBalNode = NULL;
    MyTreeNode *ptrZ = NULL;
    MyTreeNode *ptrY = NULL;
    MyTreeNode *ptrX = NULL;
    MyStackTreeNodeNode *ptrStackNode;
    
    // At this point 'stackPath4Avl' TOS has the node just inserted.
    // Start from TOS to check if the tree/sub-tree is unbalanced.
    // ptrZ --> first unbalanced in the path from inserted node to root
    // ptrY --> child of ptrZ along the path to inserted node
    // ptrX --> child of ptrY along the path to inserted node

    if (!(this->ptrRecentTargetNode == this->stackPath4Avl.ptrTOS->ptrDataTreeNode)) {
        cout << "Something wrong here, top of path-stack is not the inserted node" << endl;
        return;
    }

    while (this->stackPath4Avl.getSize()) {
        ptrStackNode = this->stackPath4Avl.pop();
        ptrNode = ptrStackNode->ptrDataTreeNode;
        stackPathXYZ.push(ptrNode);
        if (!MyTreeUtils::isBalanced(ptrNode)) {
            isBalanceReqd = true;
            if (this->stackPath4Avl.getSize()) {
                // This is the case where a 'non-root' node in the tree is
                // unbalanced node.
                cout << "A non-root node is unbalanced, balancing now" << endl;
                ptrStackNode = this->stackPath4Avl.pop(); // pop the parent of 
                                                          // non-root unbalanced node
                ptrParentOfUnBalNode = ptrStackNode->ptrDataTreeNode;
                ptrStackNode = stackPathXYZ.pop();
                ptrZ = ptrStackNode->ptrDataTreeNode;
            } else {
                // This is the case where the 'root' of the tree is
                // unbalanced node.
                cout << "The root node is unbalanced. balancing now" << endl;
                ptrStackNode = stackPathXYZ.pop(); // pop the root itself
                ptrParentOfUnBalNode = ptrStackNode->ptrDataTreeNode; // make parent of root as root itself
                ptrZ = ptrParentOfUnBalNode;
            }

            if (stackPathXYZ.getSize()) {
                ptrStackNode = stackPathXYZ.pop();
                ptrY = ptrStackNode->ptrDataTreeNode;
            } else if (!ptrY) {
                if (ptrZ->ptrLeft) {
                    ptrY = ptrZ->ptrLeft;
                } else if (ptrZ->ptrRight) {
                    ptrY = ptrZ->ptrRight;
                }
                isRootOneSided = true;
            }

            if (stackPathXYZ.getSize()) {
                ptrStackNode = stackPathXYZ.pop();
                ptrX = ptrStackNode->ptrDataTreeNode;
            } else {
                if (!isRootOneSided) {
                    ptrX = this->ptrRecentTargetNode;
                } else {
                    if (ptrY->ptrLeft) {
                        ptrX = ptrY->ptrLeft;
                    } else if (ptrY->ptrRight) {
                        ptrX = ptrY->ptrRight; 
                    }
                }
            }

            break;
        }
    }

    if (isBalanceReqd) {
        if ((ptrX == NULL) || (ptrY == NULL)) {
            cout << "Something wrong here, ptrX and/or ptrY is null" << endl;
            return;
        }

        // Now there are four possiblities
        // So we have to identify the scenario
        if ((ptrX->data < ptrY->data) && (ptrY->data < ptrZ->data)) {
        // 1>   Left-Left case      X < Y and Y < Z
            if (ptrParentOfUnBalNode != ptrZ) {
                if (ptrParentOfUnBalNode->ptrLeft == ptrZ) {
                    ptrParentOfUnBalNode->ptrLeft = ptrY;
                } else if (ptrParentOfUnBalNode->ptrRight == ptrZ) {
                    ptrParentOfUnBalNode->ptrRight = ptrY;
                }
                ptrZ->ptrLeft = ptrY->ptrRight;
                ptrY->ptrLeft = ptrX;
                ptrY->ptrRight = ptrZ;
            } else {
                // Root is unbalanced (i.e. ptrZ is 'root')
                ptrZ->ptrLeft = ptrY->ptrRight;
                ptrY->ptrLeft = ptrX;
                ptrY->ptrRight = ptrZ;
                this->ptrRoot = ptrY;
            }
        } else if ((ptrY->data < ptrX->data) && (ptrX->data < ptrZ->data)) {
        // 2>   Left Right case     Y < X and X < Z 
            if (ptrParentOfUnBalNode != ptrZ) {
                if (ptrParentOfUnBalNode->ptrLeft == ptrZ) {
                    ptrParentOfUnBalNode->ptrLeft = ptrX;
                } else if (ptrParentOfUnBalNode->ptrRight == ptrZ) {
                    ptrParentOfUnBalNode->ptrRight = ptrX;
                }
                ptrZ->ptrLeft = ptrX->ptrRight;
                ptrY->ptrRight = ptrX->ptrLeft;
                ptrX->ptrLeft = ptrY;
                ptrX->ptrRight = ptrZ;
            } else {
                // Root is unbalanced (i.e. ptrZ is 'root')
                ptrZ->ptrLeft = ptrX->ptrRight;
                ptrY->ptrRight = ptrX->ptrLeft;
                ptrX->ptrLeft = ptrY;
                ptrX->ptrRight = ptrZ;
                this->ptrRoot = ptrX;
            }
        } else if ((ptrZ->data < ptrY->data) && (ptrY->data < ptrX->data)) {
        // 3>   Right Right case    Z < Y and Y < X 
            if (ptrParentOfUnBalNode != ptrZ) {
                if (ptrParentOfUnBalNode->ptrLeft == ptrZ) {
                    ptrParentOfUnBalNode->ptrLeft = ptrY;
                } else if (ptrParentOfUnBalNode->ptrRight == ptrZ) {
                    ptrParentOfUnBalNode->ptrRight = ptrY;
                }
                ptrZ->ptrRight = ptrY->ptrLeft;
                ptrY->ptrLeft = ptrZ;
                ptrY->ptrRight = ptrX;
            } else {
                // Root is unbalanced (i.e. ptrZ is 'root')
                ptrZ->ptrRight = ptrY->ptrLeft;
                ptrY->ptrLeft = ptrZ;
                ptrY->ptrRight = ptrX;
                this->ptrRoot = ptrY;
            }
        } else if ((ptrZ->data < ptrX->data) && (ptrX->data < ptrY->data)) {
        // 4>   Right Left case     Z < X and X < Y
            if (ptrParentOfUnBalNode != ptrZ) {
                if (ptrParentOfUnBalNode->ptrLeft == ptrZ) {
                    ptrParentOfUnBalNode->ptrLeft = ptrX;
                } else if (ptrParentOfUnBalNode->ptrRight == ptrZ) {
                    ptrParentOfUnBalNode->ptrRight = ptrX;
                }
                ptrZ->ptrRight = ptrX->ptrLeft;
                ptrY->ptrLeft = ptrX->ptrRight;
                ptrX->ptrLeft = ptrZ;
                ptrX->ptrRight = ptrY;
            } else {
                // Root is unbalanced (i.e. ptrZ is 'root')
                ptrZ->ptrRight = ptrX->ptrLeft;
                ptrY->ptrLeft = ptrX->ptrRight;
                ptrX->ptrLeft = ptrZ;
                ptrX->ptrRight = ptrY;
                this->ptrRoot = ptrX;
            }
        } else {
            cout << "Something wrong here, invalid AVL-case" << endl;
            return;
        }
    } else {
        cout << "Binary Tree is still balanced after operation" << endl;
    }

    return;
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::insert_avl_helper()
 *  DESCRIPTION     This function inserts a new node into an already balanced
 *                  binary tree. During insertion this function also follows/
 *                  tracks the path to the newly inserted node in the member
 *                  'this->stackPath4Avl' 
 *  -------------------------------------------------------------------------
 */
MyTreeNode *
MyBinSearchTree::insert_avl_helper (MyTreeNode **ptrNode, 
                                    int value,
                                    bool *isRootInsert)
{
	if (this->Tsize == 0) {
	    cout << "inserting first node (root) in the tree" << endl;
        cout << "tree is balanced" << endl;
        *isRootInsert = true;
	}

	if (!(*ptrNode)) {
		*ptrNode = new MyTreeNode(value);
		this->Tsize++;
        this->stackPath4Avl.push((*ptrNode));
        this->ptrRecentTargetNode = *ptrNode;
		return (*ptrNode);
	} 

    if (value == (*ptrNode)->data) {
        cout << "value already exists" << endl;
        this->ptrRecentTargetNode = NULL;
        return (*ptrNode);
    }

	if (value < (*ptrNode)->data) {
		// Traverse left child
        this->stackPath4Avl.push((*ptrNode));
		(*ptrNode)->ptrLeft = insert_avl_helper(&((*ptrNode)->ptrLeft), value, isRootInsert);
	}

	if (value > (*ptrNode)->data) {
		// Traverse right child
        this->stackPath4Avl.push((*ptrNode));
		(*ptrNode)->ptrRight = insert_avl_helper(&((*ptrNode)->ptrRight), value, isRootInsert);
	}

	return (*ptrNode);	// (is this needed??)
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::insert_avl()
 *  DESCRIPTION     This function inserts a new node into an already balanced
 *                  tree and also cleans up the member 'this->stackPath4Avl' 
 *                  so that a new path will be updated by the method 
 *                  'insert_avl_helper()'
 *  -------------------------------------------------------------------------
 */
MyTreeNode *
MyBinSearchTree::insert_avl (int value)
{
    bool isRootInsert = false;

    this->stackPath4Avl.clean();
    this->ptrRecentTargetNode = NULL;
    this->insert_avl_helper(&(this->ptrRoot), value, &isRootInsert);

    if (!this->ptrRecentTargetNode) {
        return NULL;
    }

    if (isRootInsert) {
        return (this->ptrRoot);
    }

    this->balance();

    return (this->ptrRecentTargetNode);
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::delete_avl_helper()
 *  DESCRIPTION     This method deletes a new node from a already balanced
 *                  binary tree.
 *                  For this it follows pre-order traversal.
 *  -------------------------------------------------------------------------
 */
MyTreeNode *
MyBinSearchTree::delete_avl_helper (MyTreeNode *ptrNode, int value)
{
    MyTreeNode *ptrNodeTmp;
    MyTreeNode *ptrInOrderSuccessor;

    if (value == ptrNode->data) {

        // Do a normal BST-delete operation
        
        // Case-1:  ptrNode is a leaf-node
        if (MyTreeUtils::isLeafNode(ptrNode)) {
            delete ptrNode;
            this->ptrRecentTargetNode = this->stackPath4Avl.ptrTOS->ptrDataTreeNode;;
            return (NULL);
        }
    
        // Case-2:  ptrNode has one child
        if (!ptrNode->ptrLeft) {
            // has only right-child
            ptrNodeTmp = ptrNode->ptrRight;
            delete ptrNode;
            this->stackPath4Avl.push(ptrNodeTmp);
            this->ptrRecentTargetNode = ptrNodeTmp;
            return (ptrNodeTmp);
        } else if (!ptrNode->ptrRight) {
            // has only left-child
            ptrNodeTmp = ptrNode->ptrLeft;
            delete ptrNode;
            this->stackPath4Avl.push(ptrNodeTmp);
            this->ptrRecentTargetNode = ptrNodeTmp;
            return (ptrNodeTmp);
        }

        // Case-3: ptrNode has both children
        ptrInOrderSuccessor = MyTreeUtils::getMinNodeInBst(ptrNode->ptrRight);
        ptrNode->data = ptrInOrderSuccessor->data;
        ptrNode->ptrRight = deleteNode_helper(ptrNode->ptrRight,
                                              ptrInOrderSuccessor->data);
        this->stackPath4Avl.push(ptrNode);
        this->ptrRecentTargetNode = ptrNode;
        return (ptrNode);
    }

    if (value < ptrNode->data) {
        this->stackPath4Avl.push(ptrNode);
        ptrNode->ptrLeft = delete_avl_helper(ptrNode->ptrLeft, value);
        return (ptrNode);
    }

    if (value > ptrNode->data) {
        this->stackPath4Avl.push(ptrNode);
        ptrNode->ptrRight = delete_avl_helper(ptrNode->ptrRight, value);
        return (ptrNode);
    }

    return (NULL);
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyBinSearchTree::delete_avl()
 *  DESCRIPTION     This method deletes a new node from a already balanced
 *                  binary tree. Further it balances the tree again if needed.
 *  -------------------------------------------------------------------------
 */
void
MyBinSearchTree::delete_avl (int value)
{
    if (!this->ptrRoot) {
        cout << "tree is empty, nothing to delete" << endl;
        return;
    }

    this->stackPath4Avl.clean();
    delete_avl_helper(this->ptrRoot, value);

    // now that 'ptrStack4Avl' is ready, call the method balance()
    this->balance();

    return;
}

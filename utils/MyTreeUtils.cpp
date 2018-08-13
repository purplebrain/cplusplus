
#include "MyTreeUtils.hpp"

                    /* 
                     *  ----------------------
                     *        Generic APIs
                     *  ----------------------
                     */
/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyTreeUtils::isLeafNode ()
 *  DESCRIPTION     This method determines if a given node is a leaf-node. 
 *                  
 * -------------------------------------------------------------------------
 */
bool
MyTreeUtils::isLeafNode (MyTreeNode *ptrNode)
{
    if (!ptrNode) {
        return false;
    }

    if ((!ptrNode->ptrLeft) && (!ptrNode->ptrRight)) {
        return true;
    }

    return false;
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyTreeUtils::getHeight ()
 *  DESCRIPTION     This method prints the height of the tree.
 *                  It follows Post-Order traversal for this purpose.
 * -------------------------------------------------------------------------
 */
int
MyTreeUtils::getHeight (MyTreeNode *ptrRoot)
{
    int htLeft, htRight;
    int retVal;

    if (!ptrRoot) {
        return 0;
    }

    // Traverse left
    htLeft = getHeight(ptrRoot->ptrLeft);
    
    // Traverse right
    htRight = getHeight(ptrRoot->ptrRight);

    // Process root
    retVal = 1 + ((htLeft > htRight) ? htLeft : htRight);

    return (retVal);
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyTreeUtils::getMinNodeInBst ()
 *  DESCRIPTION     This method does a left traversal and gives the min-node
 *                  in BST.
 * -------------------------------------------------------------------------
 */
MyTreeNode *
MyTreeUtils::getMinNodeInBst (MyTreeNode *ptrCurrent)
{
    MyTreeNode *ptrNode = NULL;

    if (!ptrCurrent) {
        return NULL;
    }

    ptrNode = ptrCurrent;

    while (ptrNode->ptrLeft != NULL) {
        ptrNode = ptrNode->ptrLeft; 
    }

    return (ptrNode);
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyTreeUtils::getMaxNodeInBst ()
 *  DESCRIPTION     This method does a right traversal and gives the max-node
 *                  in BST.
 * -------------------------------------------------------------------------
 */
MyTreeNode *
MyTreeUtils::getMaxNodeInBst (MyTreeNode *ptrCurrent)
{
    MyTreeNode *ptrNode = NULL;

    if (!ptrCurrent) {
        return NULL;
    }

    ptrNode = ptrCurrent;

    while (ptrNode->ptrRight != NULL) {
        ptrNode = ptrNode->ptrRight; 
    }

    return (ptrNode);
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyTreeUtils::sumOfTree ()
 *  DESCRIPTION      
 *  
 * -------------------------------------------------------------------------
 */
int
MyTreeUtils::sumOfTree (MyTreeNode *ptrNode) 
{
    int sumLeft, sumRight;
    int retVal;

    if (isLeafNode(ptrNode)) {
        return (ptrNode->data);
    }

    // Traverse left
    sumLeft = sumOfTree(ptrNode->ptrLeft);

    // Traverse left
    sumRight = sumOfTree(ptrNode->ptrRight);

    // Process root
    retVal = ptrNode->data + sumLeft + sumRight;
    
    return (retVal);
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyTreeUtils::sumOfChildren ()
 *  DESCRIPTION      
 *  
 * -------------------------------------------------------------------------
 */
int
MyTreeUtils::sumOfChildren (MyTreeNode *ptrNode) 
{
    return (sumOfTree(ptrNode) - ptrNode->data);
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MyTreeUtils::isSumPropertyBinTree ()
 *  DESCRIPTION      
 *  
 * -------------------------------------------------------------------------
 */
bool
MyTreeUtils::isSumPropertyBinTree (MyTreeNode *ptrRoot)
{
    if (!ptrRoot) {
        cout << "Tree is empty" << endl;
        return false;
    }

    if (ptrRoot->data == sumOfChildren(ptrRoot)) 
        return true;

    return false;
}

                    /* 
                     *  --------------------------
                     *     Tree delete & removal 
                     *  --------------------------
                     */
void
MyTreeUtils::destroyTree_helper (MyTreeNode *ptrSubRoot)
{
    if (!ptrSubRoot) {
        return;
    }
    //  Traverse Left and destroy
    if (ptrSubRoot->ptrLeft) {
        destroyTree_helper (ptrSubRoot->ptrLeft);
    }

    //  Traverse Right and destroy
    if (ptrSubRoot->ptrRight) {
          destroyTree_helper (ptrSubRoot->ptrRight);
    }

    //  Destroy root
   delete ptrSubRoot;
}

void
MyTreeUtils::destroyTree (MyTreeNode *ptrRoot)
{
    cout << "Completely destroying the current tree" << endl;
    destroyTree_helper(ptrRoot);
}


                    /* 
                     *  -----------------------
                     *    Search Tree APIs
                     *  -----------------------
                     */
bool
MyTreeUtils::isBinSearchTree_helper (MyTreeNode *ptrNode, int min, int max)
{
    bool retVal = true;

    if (ptrNode->ptrLeft) {
        if (!((min <= ptrNode->ptrLeft->data) && 
              (ptrNode->ptrLeft->data <= ptrNode->data))) {
           return false;
        } else {
            // go to next level down and check
        }
    } else {
        return true;
    }

    if (ptrNode->ptrRight) {
        if (!((ptrNode->data <= ptrNode->ptrRight->data) && 
              (ptrNode->ptrRight->data <= max))) {
            return false;
        } else {
            // go to next level down and check
        }
    } else {
        return true;
    }

    if (isBinSearchTree_helper(ptrNode->ptrLeft, min, (ptrNode->data - 1)) &&
        isBinSearchTree_helper(ptrNode->ptrRight, (ptrNode->data + 1), max)) {
        return true;
    } else {
        return false;
    }

    return retVal;
}

bool
MyTreeUtils::isBinSearchTree (MyTreeNode *ptrRoot)
{
	bool retVal;
	retVal = isBinSearchTree_helper(ptrRoot, INT_MIN, INT_MAX);
	return retVal;
}


                    /* 
                     *  ----------------------
                     *    Balanced Tree APIs
                     *  ----------------------
                     */
bool
MyTreeUtils::isBalanced_helper (MyTreeNode *ptrSubRoot)
{
    int htLeft;
    int htRight;

    // Traverse left
    htLeft = getHeight(ptrSubRoot->ptrLeft);

    // Traverse right
    htRight = getHeight(ptrSubRoot->ptrRight);
 
    // Process root
    if (abs(htLeft - htRight) <= 1) {
        return true;
    }

    return false;
}

bool
MyTreeUtils::isBalanced (MyTreeNode *ptrRoot)
{
    bool retVal;

    if (!ptrRoot) {
        cout << "Empty binary tree" << endl;
        return true;
    } 

    retVal = isBalanced_helper(ptrRoot);

    return (retVal);
}

                    /* 
                     *  -----------------------
                     *    Tree Traversal APIs
                     *  -----------------------
                     */
void
MyTreeUtils::print_in_order_helper (MyTreeNode *ptrSubRoot)
{
	if (!ptrSubRoot) {
		return;
	}

	//	Traverse Left
	print_in_order_helper (ptrSubRoot->ptrLeft);	

	//	Process Node
	cout << ptrSubRoot->data << " " << endl;

	//	Traverse Right
	print_in_order_helper (ptrSubRoot->ptrRight);	
}

void
MyTreeUtils::print_in_order (MyTreeNode *ptrRoot)
{
	cout << "Printing in InOrder" << endl;
	MyTreeUtils::print_in_order_helper (ptrRoot);
}

void
MyTreeUtils::print_pre_order_helper (MyTreeNode *ptrSubRoot)
{
	if (!ptrSubRoot) {
		return;
	}

	//	Process Node
	cout << ptrSubRoot->data << " " << endl;

	//	Traverse Left
	print_pre_order_helper (ptrSubRoot->ptrLeft);	

	//	Traverse Right
	print_pre_order_helper (ptrSubRoot->ptrRight);	
}

void
MyTreeUtils::print_pre_order (MyTreeNode *ptrRoot)
{
	cout << "Printing in PreOrder" << endl;
	MyTreeUtils::print_pre_order_helper (ptrRoot);
}

void
MyTreeUtils::print_post_order_helper (MyTreeNode *ptrSubRoot)
{
	if (!ptrSubRoot) {
		return;
	}

	//	Traverse Left
	print_post_order_helper (ptrSubRoot->ptrLeft);	

	//	Traverse Right
	print_post_order_helper (ptrSubRoot->ptrRight);	

	//	Process Node
	cout << ptrSubRoot->data << " " << endl;
}

void
MyTreeUtils::print_post_order (MyTreeNode *ptrRoot)
{
	cout << "Printing in PostOrder" << endl;
	MyTreeUtils::print_post_order_helper (ptrRoot);
}

void
MyTreeUtils::print_level (MyTreeNode *ptrSubRoot, int level)
{
	if (!ptrSubRoot) {
		return;
	}

	if (level == 1) {
		cout << ptrSubRoot->data << " ";
		return;
	} else {
		print_level(ptrSubRoot->ptrLeft, (level-1));
		print_level(ptrSubRoot->ptrRight, (level-1));
	}
	
	return;
}

void
MyTreeUtils::print_level_order (MyTreeNode *ptrRoot)
{
	int height;

	cout << "Printing in LevelOrder" << endl;

	if (!ptrRoot) {
		 cout << "Empty Tree" << endl;
		 return;
	}	

	height = getHeight(ptrRoot);
	cout << "Height of the tree is : " << height << endl;	

	for (int level = 1; level <= height; level++) {
		print_level(ptrRoot, level);
		cout << endl;
	}
}

void
MyTreeUtils::print_tree_boundary_helper (MyTreeNode *ptrSubRoot, 
                                         MY_SCAN_TYPE_T type)
{
	if (!ptrSubRoot) {
	    return;
	}
	
	if (type == SCAN_LEFT) {
	    if (ptrSubRoot->ptrLeft) {
	        cout << ptrSubRoot->data << " ";
	        print_tree_boundary_helper(ptrSubRoot->ptrLeft, type);
	    } else if (ptrSubRoot->ptrRight) {
	        cout << ptrSubRoot->data << " ";
	        print_tree_boundary_helper(ptrSubRoot->ptrRight, type);
	    } 
	}
	
	if (type == SCAN_LEAF) {
	    // this is just like InOrder traversal
	    print_tree_boundary_helper(ptrSubRoot->ptrLeft, type);
	    if (isLeafNode(ptrSubRoot)) {
	         cout << ptrSubRoot->data << " ";
	         return;
	    }
	    print_tree_boundary_helper(ptrSubRoot->ptrRight, type);
	}
	
	if (type == SCAN_RIGHT) {
	    if (ptrSubRoot->ptrRight) {
	        print_tree_boundary_helper(ptrSubRoot->ptrRight, type);
	        cout << ptrSubRoot->data << " ";
	    } else if (ptrSubRoot->ptrLeft) {
	        print_tree_boundary_helper(ptrSubRoot->ptrLeft, type);
	        cout << ptrSubRoot->data << " ";
	    }
	}

	return;
}

void
MyTreeUtils::print_tree_boundary (MyTreeNode *ptrRoot)
{
	cout << "Printing Tree Boundary" << endl;
	if (!ptrRoot) {
	    cout << "Tree is empty" << endl;
	    return;
	} else {
	    cout << ptrRoot->data << " ";
	    MyTreeUtils::print_tree_boundary_helper (ptrRoot->ptrLeft, 
	                                             SCAN_LEFT);
	    MyTreeUtils::print_tree_boundary_helper (ptrRoot,
	                                             SCAN_LEAF);
	    MyTreeUtils::print_tree_boundary_helper (ptrRoot->ptrRight, 
	                                             SCAN_RIGHT);
	    cout << " " << endl;
	}
	
	return;
}

void
MyTreeUtils::print_vertical_order_helper (MyTreeNode *ptrNode, int line, int dist)
{
    if (!ptrNode) {
        return;
    }

    if (dist == line) {
        cout << ptrNode->data << " ";
    }

    print_vertical_order_helper(ptrNode->ptrLeft, line, dist-1);
    print_vertical_order_helper(ptrNode->ptrRight, line, dist+1);
}

void
MyTreeUtils::print_vertical_order (MyTreeNode *ptrRoot)
{
    MyTreeNode *ptrNode;
    if (!ptrRoot) {
        cout << "Tree is empty" << endl;
        return;
    }
    
    // Find the min-width of the tree
    ptrNode = ptrRoot;
    int min_width = 1;
    while (ptrNode) {
        min_width--;
        ptrNode = ptrNode->ptrLeft;
    }

    // Find the max-width of the tree
    ptrNode = ptrRoot;
    int max_width = -1;
    while (ptrNode) {
        max_width++;
        ptrNode = ptrNode->ptrRight;
    }
    
    cout << "Min-Width : " << min_width << endl;
    cout << "Max-Width : " << max_width << endl;

    for (int line = min_width; line <= max_width; line++)
    {
        cout << endl;
        print_vertical_order_helper(ptrRoot, line, 0); 
    }
}

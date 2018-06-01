#ifndef __MY_TREE_NODE_HPP
#define __MY_TREE_NODE_HPP

using namespace std;
#include <iostream>
#include <cstddef>

// 
//	<CLASS>	MyTreeNode
//			This is a concrete class that implements a tree node
//			that will be used to build the tree.
class MyTreeNode
{
    public:
    	int data;
    	MyTreeNode *ptrLeft;
    	MyTreeNode *ptrRight;
	
    public:
    	MyTreeNode (int value)
    	{
    	    this->data = value;
    	    this->ptrLeft = NULL;
    	    this->ptrRight = NULL;
    	}
};

#endif // __MY_TREE_NODE_HPP

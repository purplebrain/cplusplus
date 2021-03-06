#ifndef __MY_TREE_NODE_HPP
#define __MY_TREE_NODE_HPP

#include <iostream>
#include <cstddef>

using namespace std;

// 
//	<CLASS>	MyTreeNode
//	This is a concrete class that implements a tree node
//	that will be used to build the tree.
//
class MyTreeNode
{
    public:
    	int data;
    	MyTreeNode *ptrLeft;
    	MyTreeNode *ptrRight;
      int height;
      int maxSubTreeValue;
      int minSubTreeValue;
      int secretNum;
    public:
			// Constructor
    	MyTreeNode (int value)
    	{
    	    this->data = value;
    	    this->ptrLeft = NULL;
    	    this->ptrRight = NULL;
          this->height = 1;
          this->maxSubTreeValue = value;
          this->minSubTreeValue = value;
          this->secretNum = 0;
    	}

			// Destructor
			~MyTreeNode() =default;

			// Copy Semantics
			MyTreeNode(const MyTreeNode&) =default;
			MyTreeNode& operator=(const MyTreeNode&) =default;

			// Move Semantics
			MyTreeNode(MyTreeNode&&) =default;
			MyTreeNode& operator=(MyTreeNode&&) =default;
};

#endif // __MY_TREE_NODE_HPP

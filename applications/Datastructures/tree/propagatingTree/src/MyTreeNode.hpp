#ifndef __MY_TREE_NODE_HPP
#define __MY_TREE_NODE_HPP

#include <cstdlib>

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
};

#endif


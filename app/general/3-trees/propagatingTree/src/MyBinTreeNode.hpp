#ifndef __MY_BINSEARCH_TREE_HPP
#define __MY_BINSEARCH_TREE_HPP

#include "MyTreeNode.hpp"

class MyBinSearchTree
{
    public:
        MyTreeNode *ptrRoot;
        int Tsize;
        int THeight;

    private:
        MyTreeNode * getInOrderSuccessor (MyTreeNode *ptrNode);

    public:
        MyBinSearchTree() 
        {
            this->ptrRoot = NULL;
            this->Tsize = 0;
            this->THeight = 0;
        }
        MyTreeNode * insert (MyTreeNode *ptrCurNode, int value);
        MyTreeNode * remove (MyTreeNode *ptrCurNode, int value);
        MyTreeNode * find (MyTreeNode *ptrCurNode, int value);
        int getTHeight (void);
};
#endif

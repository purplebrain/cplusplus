#ifndef __MYSTACK_TREE_NODE_HPP
#define __MYSTACK_TREE_NODE_HPP

#include <iostream>
#include <cstdio>
#include <cstddef>
#include <cstring>

#include "MyBinTree.hpp"

class MyStackTreeNodeNode 
{
    public:
		MyTreeNode *ptrDataTreeNode;
        MyStackTreeNodeNode *ptrNext;

    public:
        MyStackTreeNodeNode (MyTreeNode *ptrTreeNode)
        {
            this->ptrDataTreeNode = ptrTreeNode;
            this->ptrNext = NULL;
        }

        ~MyStackTreeNodeNode ()
        {
            delete this->ptrDataTreeNode;
            this->ptrNext = NULL;
        }
};

class MyStackTreeNode
{
    public:
        int Ssize;
        MyStackTreeNodeNode *ptrTOS;
    
    public:
        MyStackTreeNode ();
        ~MyStackTreeNode ();
        
        int getSize ();

        void push(MyTreeNode *ptrNode);
        MyStackTreeNodeNode * pop (void);

        void clean ();
};

#endif

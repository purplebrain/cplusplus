#ifndef __MY_BIN_TREE_HPP
#define __MY_BIN_TREE_HPP

//
//  < DESCRIPTION >
//
//  This is just a pure BinTree which may be unbalanced, incomplete
//  and out-of-order.
//






using namespace std;

#include <iostream>
#include <cstddef>
#include <ctime>

#include "MyTreeNode.hpp"
#include "MyTreeUtils.hpp"

class MyBinTree
{
    public:
      int Tsize;
      MyTreeNode *ptrRoot;

    private:
      MyTreeNode * insert_helper (MyTreeNode **ptrNode, int value);

    public:
      MyBinTree()
      {
        this->Tsize = 0;
        this->ptrRoot = NULL;
      }

      ~MyBinTree() 
      {

      }
    
      void insert (int value);
};

#endif // __MY_BIN_TREE_HPP

#ifndef __MY_BIN_TREE_HPP
#define __MY_BIN_TREE_HPP

#include <iostream>
#include <cstddef>
#include <ctime>

#include "MyTreeNode.hpp"
#include "MyTreeUtils.hpp"

using namespace std;

//
//  <CLASS> MyBinTree
//  This is just a pure BinTree which may be unbalanced, incomplete
//  and out-of-order.
//
class MyBinTree
{
  public:
    int Tsize;
    MyTreeNode *ptrRoot;
  public:
    // Constructor
    MyBinTree()
    {
      this->Tsize = 0;
      this->ptrRoot = NULL;
    }

    // Destructor
    ~MyBinTree() =default;

  // Other Methods
  private:
    MyTreeNode * insert_helper (MyTreeNode **ptrNode, int value);
  public:
    void insert (int value);
};

#endif // __MY_BIN_TREE_HPP

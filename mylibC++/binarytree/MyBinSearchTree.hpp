#ifndef __MY_BIN_SEARCH_TREE_HPP
#define __MY_BIN_SEARCH_TREE_HPP

//
//  < DESCRIPTION >
//
//	A BinSearchTree may or may not be a complete binary tree,
//	but it has ordering with left-child value being always less
//	than parent and right-child value being greater than parent.
//





using namespace std;

#include <iostream>
#include <cstddef>

#include "MyTreeNode.hpp"
#include "MyTreeUtils.hpp"
#include "MyStackTreeNode.hpp"

enum DeleteNodeType_t
{
    NONE = 0,
    LEFT = 1,
    RIGHT = 2
};

class MyBinSearchTree
{
    public:
			int Tsize;
			MyTreeNode *ptrRoot;
      MyStackTreeNode stackPath4Avl;
      MyTreeNode *ptrRecentTargetNode;
      DeleteNodeType_t delNodeDir;

    private:
			int traversalCounter;
			MyTreeNode * insert_helper (MyTreeNode **ptrNode, int value);
			MyTreeNode * deleteNode_helper (MyTreeNode *ptrNode, int value);
      void balance ();
      MyTreeNode * insert_avl_helper (MyTreeNode **ptrNode, int value, bool *isTreeInsert);
      MyTreeNode * delete_avl_helper (MyTreeNode *ptrNode, int value);

    public:
			MyBinSearchTree ()
			{
			    this->Tsize = 0;
			    this->ptrRoot = NULL;
			    this->ptrRecentTargetNode = NULL;
				  this->traversalCounter = this->Tsize;
			}

			~MyBinSearchTree () 
			{

			}

      // Binary Search Tree
			void insertAndRetAddr (int value);
			void insert (int value);
      void deleteNode (int value);
 
      // Avl Tree
      MyTreeNode * insert_avl (int value);
      void delete_avl (int value);
};

#endif // __MY_BIN_SEARCH_TREE_HPP

#ifndef __MY_BIN_HEAP_HPP
#define __MY_BIN_HEAP_HPP

#include <iostream>
#include <cstddef>
#include <queue>
#include <vector>

#include "MyTreeNode.hpp"
#include "MyTreeUtils.hpp"

using namespace std;

typedef unsigned int uint;

enum HEAP_TYPE_T
{
  NONE = 0,
  MINHEAP = 1,
  MAXHEAP = 2
};

class MyBinHeap
{
	public:
		uint Tsize;
		MyTreeNode *ptrRoot;

	private:
    // Auxiliary Queue for Heap
    queue<MyTreeNode *> qHeap;
    bool isBuiltFromQueue;

    // Auxiliary Array for Heap
	  vector<MyTreeNode *> vecHeapNode;
    bool isBuiltFromArray;

    // Helper methods
    MyTreeNode * insert_helper (uint value);
		MyTreeNode * buildHeap (uint i);
    void buildMaxHeap (uint i);
    void buildMinHeap (uint i);
    int extractMin (void);
    int getMin (void);

	public:
		//
		//	Constructor
		//
		MyBinHeap ()
		{
			this->Tsize = 0;
			this->ptrRoot = NULL;
            this->isBuiltFromQueue = false;
            this->isBuiltFromArray = false;
		}

		//
		//	Destructor
		//
		~MyBinHeap ()
		{

		}

		//
		//	Method to insert an integer value into the BinHeap
		//	(which is a Complete Binary Tree) using Queue.
		//
		void
		insert (uint value);

		//
		//	Method to insert an integer value into the BinHeap
		//	(which is a Complete Binary Tree) using Queue and
		//	return the address of the inserted node for further
		//	operations.
		//
		MyTreeNode *
		insertAndRetAddr (uint value);

		//
		//	Method to build a BinHeap (which is a Complete Binary
		//	Tree) from a given array.
		//
		MyTreeNode *
		buildHeapFromArray (uint arr[], uint arrSize, HEAP_TYPE_T type);

};

#endif // __MY_BIN_HEAP_HPP

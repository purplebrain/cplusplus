#ifndef __MY_BIN_HEAP_HPP
#define __MY_BIN_HEAP_HPP

//
//  < DESCRIPTION >
//
//  A BinHeap is a complete binary tree with some ordering property
//  like minHeap or maxHeap
//






using namespace std;

#include <iostream>
#include <cstddef>

#include "MyQueueTreeNode.hpp"
#include "MyTreeNode.hpp"
#include "MyTreeUtils.hpp"

enum HEAP_TYPE_T
{
  NONE = 0,
  MINHEAP = 1,
  MAXHEAP = 2
};

class MyBinHeap
{
	public:
		int Tsize;
		MyTreeNode *ptrRoot;
		MyQueue *ptrQueue;
		int Asize;
		int ptrArr[];

	private:
        MyTreeNode * insert_helper (int value);
		MyTreeNode * buildHeap_helper (int i);
        MyTreeNode * buildMaxHeap (int i);
        MyTreeNode * buildMinHeap (int i);

	public:
		//
		//	Constructor
		//
		MyBinHeap ()
		{
			this->Tsize = 0;
			this->ptrRoot = NULL;
			this->ptrQueue = new MyQueue();
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
		insert (int value);

		//
		//	Method to insert an integer value into the BinHeap
		//	(which is a Complete Binary Tree) using Queue and
		//	return the address of the inserted node for further
		//	operations.
		//
		MyTreeNode *
		insertAndRetAddr (int value);

		//
		//	Method to build a BinHeap (which is a Complete Binary
		//	Tree) from a given array.
		//
		MyTreeNode *
		buildHeapFromArray (int arrInput[], int arrSize);

    //
    //  Method to either make a min-heap or max-heap. It assumes
    //  that the BinHeap has an associated array for it.
    //
    MyTreeNode *
    heapifyUsingArray (HEAP_TYPE_T type);

};

#endif // __MY_BIN_HEAP_HPP

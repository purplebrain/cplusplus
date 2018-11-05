#ifndef __MY_QUEUE_HPP
#define __MY_QUEUE_HPP

//
//  < DESCRIPTION >
//
//  A queue has a ptrQHead and ptrQTail pointing to the 'NULL' initially
//  when the queue is empty.
//  When the first element in inserted ptrQHead and ptrQTrail will point
//  to that very element.
//  Further when an new element in enqueued, ptrQHead remains at the same
//  place, but ptrQTail will move backwards. ptrQHead will only move when
//  we deque.
//  NOTE:
//        This Queue is implemented specifically for MyTreeNode class.

using namespace std;

#include <iostream>
#include <cstddef>

#include "MyBinTree.hpp"

//
//  < QueueNode >
//
class MyQueueNode
{
	public:
		MyTreeNode *ptrDataTreeNode;
		MyQueueNode *ptrPrev;

	public:
		MyQueueNode ()
		{
			this->ptrDataTreeNode = NULL;
			this->ptrPrev = NULL;
		}

		MyQueueNode (MyTreeNode *ptrTreeNode)
		{
			this->ptrDataTreeNode = ptrTreeNode;
			this->ptrPrev = NULL;
		}

		~MyQueueNode ()
		{

		}
};

//
//  < Queue >
//
class MyQueue
{
	public:
		int Qsize;
		MyQueueNode *ptrQHead; // this moves as we 'enque'
		MyQueueNode *ptrQTail; // this moves as we 'deque'

	public:
		MyQueue ()
		{
			this->Qsize = 0;
			this->ptrQHead = this->ptrQTail = NULL;
		}

		~MyQueue ()
		{

		}
		
	private:
		void
		enque_helper (MyTreeNode *ptrTreeNode);

		MyQueueNode *
		deque_helper (void);

	public:
		MyQueueNode *
		peek (void);

		void
		enque (MyTreeNode *ptrTreeNode);

		MyQueueNode *
		deque (void);
};


#endif // __MY_QUEUE_HPP


#include "MyQueueTreeNode.hpp"

MyQueueNode *
MyQueue::peek (void)
{
	return (this->ptrQHead);
}

void
MyQueue::enque_helper (MyTreeNode *ptrTreeNode)
{
  MyQueueNode *ptrQNodeTmp;

	if (Qsize == 0) {
		cout << "Enqueing first element in queue" << endl;
    ptrQNodeTmp = new MyQueueNode(ptrTreeNode);
		this->ptrQHead = ptrQNodeTmp;
    this->ptrQTail = ptrQNodeTmp;
    ptrQNodeTmp->ptrPrev = ptrQNodeTmp;
    this->Qsize++;
		return;
	}

  ptrQNodeTmp = new MyQueueNode(ptrTreeNode);
	this->ptrQTail->ptrPrev = ptrQNodeTmp;
	this->ptrQTail = ptrQNodeTmp;
	this->Qsize++;
}

void
MyQueue::enque (MyTreeNode *ptrTreeNode)
{
	if (!ptrTreeNode) {
		cout << "NULL tree node, not enqueing" << endl;
	}
	enque_helper (ptrTreeNode);
	return;
}

MyQueueNode *
MyQueue::deque_helper (void)
{
	if (Qsize == 1) {
		  cout << "Dequeing last element in queue" << endl;
	}

	MyQueueNode *ptrRetNode = this->ptrQHead;
	this->ptrQHead = this->ptrQHead->ptrPrev;
	this->Qsize--;

	return (ptrRetNode);
}

MyQueueNode *
MyQueue::deque (void)
{
	if (!Qsize) {
		cout << "Queue is empty, nothing to deque" << endl;
	}
	return (deque_helper());
}

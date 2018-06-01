
#include "MyBinHeap.hpp"

MyTreeNode *
MyBinHeap::insert_helper (int value)
{
	MyTreeNode *ptrNode;
	MyQueueNode *ptrQueueHead;
    MyTreeNode *ptrQueueHeadTreeNode;

	if (this->Tsize == 0) {
		cout << "Inserting first tree node" << endl;
		ptrNode = new MyTreeNode(value);
		ptrQueue->enque(ptrNode);
		this->ptrRoot = ptrNode;
		this->Tsize++;
		return (ptrNode);
	}

	ptrQueueHead = this->ptrQueue->peek();
	if (ptrQueueHead) {
  		ptrQueueHeadTreeNode = ptrQueueHead->ptrDataTreeNode;
	}
	if (ptrQueueHeadTreeNode) {
		if (!ptrQueueHeadTreeNode->ptrLeft) {
		  	ptrNode = new MyTreeNode(value);
		  	ptrQueueHeadTreeNode->ptrLeft = ptrNode;
    		this->Tsize++;
			this->ptrQueue->enque(ptrNode);
		} else if (!ptrQueueHeadTreeNode->ptrRight) {
			ptrNode = new MyTreeNode(value);
			ptrQueueHeadTreeNode->ptrRight = ptrNode;
        	this->Tsize++;
			this->ptrQueue->enque(ptrNode);
			this->ptrQueue->deque();
		}
	}

	return (ptrNode);
}

void
MyBinHeap::insert (int value)
{
	insert_helper(value);
}

MyTreeNode *
MyBinHeap::buildHeap_helper (int i)
{
    MyTreeNode *ptrSubRoot = NULL;
    int idxLeft, idxRight;
    
    if (i < this->Asize) {
 		idxLeft = (2*i + 1);
 		idxRight = (2*i + 2);
 		ptrSubRoot = new MyTreeNode(ptrArr[i]);
 		if (i == 0) {
 			this->ptrRoot = ptrSubRoot;
 		}
    } else {
		cout << "ERROR: " << "array index out-of-bound" << endl;
		return NULL;
    }
   
    if ((idxLeft != 0) && (idxLeft < this->Asize)) {
   		ptrSubRoot->ptrLeft = buildHeap_helper(idxLeft);
    }

    if ((idxRight != 0) && (idxRight < this->Asize)) {
   		ptrSubRoot->ptrRight = buildHeap_helper(idxRight);
    }
   
    return (ptrSubRoot);
}

MyTreeNode *
MyBinHeap::buildHeapFromArray (int arrInput[], int arrSize)
{
	MyTreeNode *ptrRetNode = NULL;

	// First copy the input array into object's array
	this->Asize = arrSize;
	for (int i = 0; i < arrSize; i++) {
		this->ptrArr[i] = arrInput[i];
	}
	
	// Now build a Heap/CompleteBinTree using this array
	ptrRetNode = buildHeap_helper (0);

	return (ptrRetNode);
}

MyTreeNode *
MyBinHeap::buildMinHeap (int i)
{
	MyTreeNode *ptrRoot = NULL;
	int idxLeft = (2*i + 1);
	int idxRight = (2*i + 2);
	int idxSmall;

	if (i < this->Tsize) {
		idxSmall = i;
		if ((idxLeft < this->Tsize) && (idxRight < this->Tsize)) {
			if (this->ptrArr[idxLeft] < this->ptrArr[idxSmall]) {
				idxSmall = idxLeft;
			}

			if (this->ptrArr[idxRight] < this->ptrArr[idxSmall]) {
				idxSmall = idxRight;
			}

			if (idxSmall != i) {
				// Swap
				int tmp = this->ptrArr[idxSmall];
				this->ptrArr[idxSmall] = this->ptrArr[i];
				this->ptrArr[i] = tmp;
			}
		}

		//	Destroy the existing BinHeap
		MyTreeUtils::destroyTree(this->ptrRoot);

		ptrRoot = buildHeap_helper(0);
	}
	
	return (ptrRoot);
}

MyTreeNode *
MyBinHeap::buildMaxHeap (int i)
{
	MyTreeNode *ptrRoot = NULL;
	int idxLeft = (2*i + 1);
	int idxRight = (2*i + 2);
	int idxBig;

	if (i < this->Tsize) {
		idxBig = i;
		if ((idxLeft < this->Tsize) && (idxRight < this->Tsize)) {
			if (this->ptrArr[idxLeft] < this->ptrArr[idxBig]) {
					idxBig = idxLeft;
			}

			if (this->ptrArr[idxRight] < this->ptrArr[idxBig]) {
					idxBig = idxRight;
			}

			if (idxBig != i) {
					// Swap
					int tmp = this->ptrArr[idxBig];
					this->ptrArr[idxBig] = this->ptrArr[i];
					this->ptrArr[i] = tmp;
			}
		}

		//	Destroy the existing BinHeap
		MyTreeUtils::destroyTree(this->ptrRoot);

		//	Build the new BinHeap using re-organised array	
		ptrRoot = buildHeap_helper(0);
	}
	
	return (ptrRoot);
}

MyTreeNode *
MyBinHeap::heapifyUsingArray (HEAP_TYPE_T type)
{ 
	MyTreeNode *ptrNode;

	if (type == MINHEAP) {
		for (int i = (this->Tsize/2 -1); i >= 0; i--) {
	 		ptrNode = buildMinHeap(i);
		}
	} else if (type == MAXHEAP) {
		for (int i = (this->Tsize/2 -1); i >= 0; i--) {
			ptrNode = buildMaxHeap(i);
		}
	}

	return (ptrNode);
}

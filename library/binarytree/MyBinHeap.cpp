
#include "MyBinHeap.hpp"

int
getMin (void)
{
    return (this->ptrRoot->data);
}

int
extractMin (void)
{
    int retVal;
    uint sizeVecAdj = this->vecHeapNode.size() - 1;

    retVal = this->ptrRoot->data;
    this->vecHeapNode[0] = this->vecHeap[sizeVecAdj];
    this->vecHeapNode.erase(this->vecHeap.begin() + sizeVecAdj); 
    this->buildMinHeap(0)
    for (int i = (vecSize/2-1); i >= 0; i--) {
        buildMinHeap(i);
    }

    return (retVal);
}

                            // --------------------------
                            //
                            //     HEAP USING ARRAY
                            //
                            // --------------------------

void
MyBinHeap::buildMinHeap (uint i)
{
	uint idxLeft = (2*i + 1);
	uint idxRight = (2*i + 2);
	uint idxSmall;

	if (i < this->vecHeapNode.size()) {
		idxSmall = i;
		if ((idxLeft < this->vecHeapNode.size()) && (idxRight < this->vecHeap.size())) {
			if (this->vecHeapNode[idxLeft] < this->vecHeap[idxSmall]) {
				idxSmall = idxLeft;
			}

			if (this->vecHeapNode[idxRight] < this->vecHeap[idxSmall]) {
				idxSmall = idxRight;
			}

			if (idxSmall != i) {
				// Swap
				uint tmp = this->vecHeapNode[idxSmall];
				this->vecHeapNode[idxSmall] = this->vecHeap[i];
				this->vecHeapNode[i] = tmp;
                this->buildMinHeap(idxSmall);
			}
		}
	}
	
	return;
}

void
MyBinHeap::buildMaxHeap (uint i)
{
	uint idxLeft = (2*i + 1);
	uint idxRight = (2*i + 2);
	uint idxBig;

	if (i < this->vecHeapNode.size()) {
		idxBig = i;
		if ((idxLeft < this->vecHeapNode.size()) && (idxRight < this->vecHeap.size())) {
			if (this->vecHeapNode[idxLeft] > this->vecHeap[idxBig]) {
				idxBig = idxLeft;
			}

			if (this->vecHeapNode[idxRight] > this->vecHeap[idxBig]) {
				idxBig = idxRight;
			}

			if (idxBig != i) {
				// Swap
				uint tmp = this->vecHeapNode[idxBig];
				this->vecHeapNode[idxBig] = this->vecHeap[i];
				this->vecHeapNode[i] = tmp;
                this->buildMaxHeap(idxBig);
			}
		}
	}
	
	return;
}

MyTreeNode *
MyBinHeap::buildHeap (uint i)
{
    MyTreeNode *ptrSubRoot = NULL;
    uint idxLeft, idxRight;
    
    if (i < this->vecHeapNode.size()) {
 		idxLeft = (2*i + 1);
 		idxRight = (2*i + 2);
 		ptrSubRoot = new MyTreeNode(this->vecHeapNode[i]);
 		if (i == 0) {
 			this->ptrRoot = ptrSubRoot;
 		}
    } else {
		return NULL;
    }
   
   	ptrSubRoot->ptrLeft = buildHeap(idxLeft);

   	ptrSubRoot->ptrRight = buildHeap(idxRight);
   
    return (ptrSubRoot);
}

MyTreeNode *
MyBinHeap::buildHeapFromArray (uint arr[], uint arrSize, HEAP_TYPE_T type)
{
	MyTreeNode *ptrRetNode = NULL;
	MyTreeNode *ptrNode = NULL;

    if (!this->isBuiltFromArray) {
	    // First copy the input array into heap's vector
        for (uint i = 0; i < arrSize; i++) {
            ptrNode = new MyTreeNode
            this->vecHeapNode.push_back(arr[i]);
        }
        this->isBuiltFromArray = true;
    }

    uint vecSize = this->vecHeapNode.size();
    switch (type) {
    case NONE:
        // build the heap
	    ptrRetNode = buildHeap (0);
        break;
    case MINHEAP:
        // re-arragne the vector elements
        for (int i = (vecSize/2-1); i >= 0; i--) {
            buildMinHeap(i);
        }
        // build the heap
        ptrRetNode = buildHeap(0);
        break;
    case MAXHEAP:
        // re-arragne the vector elements
        for (int i = (vecSize/2-1); i >= 0; i--) {
            buildMaxHeap(i);
        }
        // build the heap
        ptrRetNode = buildHeap(0);
        break;
    default:
        break;
    }

	return (ptrRetNode);
}

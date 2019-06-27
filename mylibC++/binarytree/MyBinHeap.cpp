#include "MyBinHeap.hpp"

int
MyBinHeap::getMin (void)
{
    return (this->ptrRoot->data);
}

int
MyBinHeap::extractMin (void)
{
    int retVal;
    uint sizeVecAdj = this->vecHeapNode.size() - 1;

    retVal = this->ptrRoot->data;
    uint vecSize = this->vecHeapNode.size();
    this->vecHeapNode[0] = this->vecHeapNode[sizeVecAdj];
    this->vecHeapNode.erase(this->vecHeapNode.begin() + sizeVecAdj); 
    this->buildMinHeap(0);
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
		  if ((idxLeft < this->vecHeapNode.size()) && (idxRight < this->vecHeapNode.size())) {
		  	  if (this->vecHeapNode[idxLeft]->data < this->vecHeapNode[idxSmall]->data) {
		  	  	  idxSmall = idxLeft;
		  	  }

		  	  if (this->vecHeapNode[idxRight]->data < this->vecHeapNode[idxSmall]->data) {
		  	  	  idxSmall = idxRight;
		  	  }

		  	  if (idxSmall != i) {
		  	  	  // Swap
		  	  	  uint tmp = this->vecHeapNode[idxSmall]->data;
		  	  	  this->vecHeapNode[idxSmall]->data = this->vecHeapNode[i]->data;
		  	  	  this->vecHeapNode[i]->data = tmp;
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
		  if ((idxLeft < this->vecHeapNode.size()) && (idxRight < this->vecHeapNode.size())) {
		  	  if (this->vecHeapNode[idxLeft]->data > this->vecHeapNode[idxBig]->data) {
		  	  	  idxBig = idxLeft;
		  	  }

		  	  if (this->vecHeapNode[idxRight]->data > this->vecHeapNode[idxBig]->data) {
		  	  	  idxBig = idxRight;
		  	  }

		  	  if (idxBig != i) {
		  	  	  // Swap
		  	  	  uint tmp = this->vecHeapNode[idxBig]->data;
		  	  	  this->vecHeapNode[idxBig]->data = this->vecHeapNode[i]->data;
		  	  	  this->vecHeapNode[i]->data = tmp;
              this->buildMaxHeap(idxBig);
		  	  }
		  }
	}
	
	return;
}

// Build heap from vector in Pre-order fashion.
MyTreeNode *
MyBinHeap::buildHeap (uint i)
{
    MyTreeNode *ptrSubRoot = NULL;
    uint idxLeft, idxRight;
    
    if (i < this->vecHeapNode.size()) {
 		    idxLeft = (2*i + 1);
 		    idxRight = (2*i + 2);
 		    ptrSubRoot = new MyTreeNode(this->vecHeapNode[i]->data);
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
          ptrNode = new MyTreeNode(arr[i]);
          this->vecHeapNode.push_back(ptrNode);
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

#include <iostream>
#include <cstddef>
#include <queue>
#include "MyTreeUtils.hpp"
#include "MyBinTree.hpp"

using namespace std;

typedef struct 
{
  MyTreeNode *ptrNode;
  int depth;
} NODE;

class MyComparator
{
  public:
    bool
    operator() (const NODE& node1, const NODE& node2)
    {
      return (node1.depth < node2.depth);
    }
};

// Global priority_queue to represent a MaxHeap. It operatest on the NODE object
// and stores according to the value of 'depth' element.
priority_queue<NODE, vector<NODE>, MyComparator> gPQueue;

MyTreeNode *
getDeepestNode (MyTreeNode *ptrSubTree, int depth)
{
  if (!ptrSubTree) {
    return NULL;
  } else {
    // LEFT
    if (!getDeepestNode(ptrSubTree->ptrLeft, depth+1)) {
      NODE tmpNode;
      tmpNode.ptrNode = ptrSubTree;
      tmpNode.depth = depth;
      gPQueue.push(tmpNode);
    }
    // ROOT
    if (!ptrSubTree->ptrLeft && !ptrSubTree->ptrRight) {
      NODE tmpNode;
      tmpNode.ptrNode = ptrSubTree;
      tmpNode.depth = depth;
      gPQueue.push(tmpNode);
    }
    // RIGHT
    if (!getDeepestNode(ptrSubTree->ptrRight, depth+1)) {
      NODE tmpNode;
      tmpNode.ptrNode = ptrSubTree;
      tmpNode.depth = depth;
      gPQueue.push(tmpNode);
    }
  }
  
  return (ptrSubTree);
}

int
main (int argc, char *argv[])
{
	MyBinTree binTree;

	binTree.ptrRoot = new MyTreeNode(100);
	binTree.ptrRoot->ptrLeft = new MyTreeNode(10);
	binTree.ptrRoot->ptrRight = new MyTreeNode(5);
	binTree.ptrRoot->ptrLeft->ptrLeft = new MyTreeNode(4);
	binTree.ptrRoot->ptrLeft->ptrRight = new MyTreeNode(3);
	binTree.ptrRoot->ptrRight->ptrLeft = new MyTreeNode(6);
	binTree.ptrRoot->ptrRight->ptrRight = new MyTreeNode(7);
	binTree.ptrRoot->ptrRight->ptrRight->ptrRight = new MyTreeNode(50);
	binTree.ptrRoot->ptrRight->ptrLeft->ptrLeft = new MyTreeNode(40);
	binTree.ptrRoot->ptrRight->ptrLeft->ptrLeft->ptrLeft = new MyTreeNode(99);

 	MyTreeUtils::print_in_order(binTree.ptrRoot);

  getDeepestNode(binTree.ptrRoot, 0);

  // Get the deepest node by getting the highest value from the Max Heap
  NODE node = gPQueue.top();
  cout << "\nDeepest Node is : " << node.ptrNode->data << " at a depth of : " << node.depth;

	cout << endl;
	return (0);
}

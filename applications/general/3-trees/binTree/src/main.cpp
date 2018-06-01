using namespace std;
#include <iostream>
#include <cstddef>
#include <string>
#include "MyTreeUtils.hpp"
#include "MyBinTree.hpp"

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

 	MyTreeUtils::print_in_order(binTree.ptrRoot);

 	MyTreeUtils::print_level_order(binTree.ptrRoot);

	cout << endl;

	return (0);
}

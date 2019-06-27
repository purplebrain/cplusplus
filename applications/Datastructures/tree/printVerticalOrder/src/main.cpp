#include <iostream>
#include <cstdlib>
#include <cstddef>

#include "MyTreeNode.hpp"
#include "MyTreeUtils.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
    MyTreeNode *ptrRoot;

    ptrRoot = new MyTreeNode(10);

    ptrRoot->ptrLeft = new MyTreeNode(5);
    ptrRoot->ptrRight = new MyTreeNode(2);

    ptrRoot->ptrLeft->ptrRight = new MyTreeNode(15);
    ptrRoot->ptrLeft->ptrRight->ptrLeft = new MyTreeNode(9);
    ptrRoot->ptrLeft->ptrRight->ptrLeft->ptrLeft = new MyTreeNode(35);

    ptrRoot->ptrRight->ptrLeft = new MyTreeNode(25);
    ptrRoot->ptrRight->ptrLeft->ptrRight = new MyTreeNode(20);
    ptrRoot->ptrRight->ptrLeft->ptrRight->ptrRight = new MyTreeNode(45);
    ptrRoot->ptrRight->ptrLeft->ptrRight->ptrRight->ptrLeft = new MyTreeNode(55);
    ptrRoot->ptrRight->ptrLeft->ptrRight->ptrRight->ptrLeft->ptrRight = new MyTreeNode(65);
    ptrRoot->ptrRight->ptrLeft->ptrRight->ptrRight->ptrLeft->ptrRight->ptrRight = new MyTreeNode(75);

    MyTreeUtils::print_vertical_order(ptrRoot);

    cout << endl;
    return (0);
}

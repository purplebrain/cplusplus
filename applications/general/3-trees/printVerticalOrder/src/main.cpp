using namespace std;

#include <iostream>
#include <cstdlib>
#include <cstddef>

#include "MyTreeNode.hpp"
#include "MyTreeUtils.hpp"

int
main (int argc, char *argv[])
{
    MyTreeNode *ptrRoot;

    ptrRoot = new MyTreeNode(10);
    ptrRoot->ptrLeft = new MyTreeNode(5);
    ptrRoot->ptrRight = new MyTreeNode(2);
    ptrRoot->ptrLeft->ptrLeft = new MyTreeNode(9);
    ptrRoot->ptrLeft->ptrRight = new MyTreeNode(15);
    ptrRoot->ptrRight->ptrRight = new MyTreeNode(20);
    ptrRoot->ptrRight->ptrLeft = new MyTreeNode(25);

    MyTreeUtils::print_vertical_order(ptrRoot);

    cout << endl;
    return (0);
}

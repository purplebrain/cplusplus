
#include "MyStackTreeNode.hpp"

MyStackTreeNode::MyStackTreeNode () 
{
    this->Ssize = 0;
    this->ptrTOS = NULL;
}

MyStackTreeNode::~MyStackTreeNode ()
{
    MyStackTreeNodeNode *ptrStackNode = NULL;

    if (this->Ssize) {
        for (int i = 0; i < this->Ssize; i++) {
            ptrStackNode = this->pop();
        }
    }
    
    //delete ptrStackNode;
}

int
MyStackTreeNode::getSize () 
{
    return (this->Ssize);
}

void
MyStackTreeNode::push (MyTreeNode *ptrTreeNode)
{
    if (this->Ssize == 0) {
        //cout << "Pushing the first element into stack" << endl;
    }
    
    MyStackTreeNodeNode *ptrStackNode = new MyStackTreeNodeNode(ptrTreeNode);
    ptrStackNode->ptrNext = this->ptrTOS;
    this->ptrTOS = ptrStackNode;
    this->Ssize++;

    return;
}

MyStackTreeNodeNode *
MyStackTreeNode::pop (void)
{
    MyStackTreeNodeNode *ptrStackNodeTmp = NULL;

    if (this->Ssize == 0) {
        //cout << "Stack empty, nothing to pop()" << endl;
        return NULL;
    }

    ptrStackNodeTmp = this->ptrTOS;
    this->ptrTOS = (this->ptrTOS)->ptrNext;
    this->Ssize--;

    return (ptrStackNodeTmp);
}

void 
MyStackTreeNode::clean ()
{
    while (this->Ssize) {
        this->pop();
    }

    return;
}

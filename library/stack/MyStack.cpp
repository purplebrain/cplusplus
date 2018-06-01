
#include "MyStack.hpp"

template <typename T>
MyStack<T>::MyStack () 
{
  this->ptrTOS = NULL;
  this->size = 0;
}

template <typename T>
MyStack<T>::~MyStack () 
{
  MyStackNode<T> *ptrStackNode;

  if (this->size) {
    for (int i = 1; i <= this->size; i++) {
      ptrStackNode = this->pop();
    }
  }

  this->ptrTOS = NULL;
  this->size = 0;
}

template <typename T>
int 
MyStack<T>::getSize () 
{
  return (this->size);
}

template <typename T>
void
MyStack<T>::push (T value) 
{
  MyStackNode<T> *ptrNode = new MyStackNode<T>(value);
  if (!ptrNode) {
    LIB_ERR(STACK, "%s", "could not allocate StackNode");
  }

  ptrNode->ptrNext = ptrTOS;
  this->ptrTOS = ptrNode;
  this->size++;

  return;
}

template <typename T>
MyStackNode<T> *
MyStack<T>::pop() 
{
  MyStackNode<T> *ptrTmpNode = NULL;

  // Sanity check
  if (!this->size) {
    LIB_LOG(STACK, "%s", "Stack is empty, nothing to pop.");
    return NULL;
  }

  ptrTmpNode = ptrTOS;
  ptrTOS = ptrTOS->ptrNext;
  this->size--;

  return (ptrTmpNode);
}

template <typename T>
void
MyStack<T>::dump() 
{
  MyStackNode<T> *ptrTmp;

  if (!this->size) {
      LIB_LOG(STACK, "%s", "Stack is empty, nothing to dump.");
  } else {
      ptrTmp = ptrTOS;
      for (int i = 1; i <= this->size; i++) {
        std::cout << ptrTmp->data << std::endl;
        ptrTmp = ptrTmp->ptrNext;
      }
  }
}


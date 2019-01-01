#ifndef __MYSTACK_HPP
#define __MYSTACK_HPP

#include <iostream>
#include <cstdio>
#include <cstddef>
#include <cstring>

template <typename T>
class MyStackNode {

  public:
    T data;
    MyStackNode<T> *ptrNext;

  public:
    MyStackNode () {
      this->data = 0;
      this->ptrNext = NULL;
    }

    MyStackNode (T value) {
      this->data = value;
      this->ptrNext = NULL;
    }

    ~MyStackNode () {
      this->ptrNext = NULL; 
    }
};

template <typename T>
class MyStack {

	private:
    MyStackNode<T> *ptrTOS;
    int size;

	public:
		// Constructor
    MyStack ();

	// Destructor 
	~MyStack ();

	//	METHOD:				getSize()
	//	DESCRIPTION:	This method returns the current size of the stack
	int getSize ();
	
	//	METHOD:				push()
	//	DESCRIPTION:	This method pushes the given value into stack
	void push (T value);

	//	METHOD:				pop()
	//	DESCRIPTION:	This method pops TOS value out of stack
	MyStackNode<T> * pop ();

	//	METHOD:				dump()
	//	DESCRIPTION:	This method dumps/prints all the values starting from TOS
	void dump ();
};

#endif // __MYSTACK_HPP

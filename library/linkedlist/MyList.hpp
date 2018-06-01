#ifndef __MY_LIST_HPP
#define __MY_LIST_HPP

#include <iostream>
#include <cstdio>
#include <cstddef>
#include <cstring>

class MyListNode
{
    public:
        int data;
        MyListNode *ptrNext;

    public:
        MyListNode (int value) {
            this->data = value;
            this->ptrNext = NULL;
        }
};

class MyList
{
    public:
        MyListNode *ptrListHead;
        int Lsize;

    public:
        MyList (int *arr, int size);
        MyListNode * insert (int value);
        int getSize ();
};

#endif // __MY_LIST_HPP

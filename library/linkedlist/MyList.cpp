
#include "MyList.hpp"

MyList::MyList (int *arr, int size)
{
    MyListNode *ptrListNodeTmp = NULL;

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            this->ptrListHead = new MyListNode(arr[i]);
            this->Lsize++;
        } else {
            ptrListNodeTmp = ptrListHead;
            ptrListHead = new MyListNode(arr[i]);
            ptrListHead->ptrNext = ptrListNodeTmp;
            this->Lsize++;
        }
    }
}

int
MyList::getSize ()
{
    return (this->Lsize);
}

MyListNode *
MyList::insert (int value)
{

    return NULL;
}

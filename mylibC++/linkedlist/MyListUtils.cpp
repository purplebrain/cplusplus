#include "MyListUtils.hpp"

MyListNode *
MyListUtils::reverse_list (MyListNode *ptrListHead)
{
    MyListNode *ptrPrev = NULL;
    MyListNode *ptrCur = ptrListHead;
    MyListNode *ptrNext = NULL;

    while (1) {
        if (ptrCur != NULL) {
            ptrNext = ptrCur->ptrNext;
            ptrCur->ptrNext = ptrPrev;
            ptrPrev = ptrCur;
            ptrCur = ptrNext;
        } else {
            ptrListHead = ptrPrev;
            break;
        }
    }

    return ptrListHead;
}


#include "MyPrintUtils.hpp"

void
MyPrintUtils::print_array (int *inputArr, int Asize)
{
    for (int i=0; i < Asize; i++) {
        cout << inputArr[i] << " ";
    }
    cout << endl;
    return;
}


void 
MyPrintUtils::print_list(MyListNode *ptrListHead)
{
    MyListNode *ptrListNode = ptrListHead;
    while (1) {
        if (ptrListNode != NULL) {
            cout << ptrListNode->data << ", ";
            ptrListNode = ptrListNode->ptrNext;
        } else {
            cout << endl;
            break;
        }
    }

    return;
}

#include "MyPrintListUtils.hpp"

void
MyPrintListUtils::print_list_helper (MyListNode *ptrListNode)
{
  MyListNode *ptrTmpListNode = ptrListNode;
  cout << "[ ";
  while (ptrTmpListNode) {
    cout << " " << ptrTmpListNode->data << " ->";
    ptrTmpListNode = ptrTmpListNode->ptrNext;
  }
  cout << " ]" << endl;
}

void
MyPrintListUtils::print_list (MyListNode *ptrListNode)
{
  print_list_helper(ptrListNode);
}

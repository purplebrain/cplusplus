#ifndef __MY_PRINT_LIST_UTILS_HPP
#define __MY_PRINT_LIST_UTILS_HPP

#include <iostream>
#include <cstddef>
#include "MyList.hpp"

using namespace std;

class MyPrintListUtils
{
  private:
    static void print_list_helper (MyListNode *ptrListNode);
  public:
    static void print_list (MyListNode *ptrListNode);
};

#endif // __MY_PRINT_LIST_UTILS_HPP

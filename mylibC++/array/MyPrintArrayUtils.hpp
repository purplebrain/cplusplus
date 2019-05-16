#ifndef __MY_PRINT_ARRAY_UTILS_HPP
#define __MY_PRINT_ARRAY_UTILS_HPP

#include <iostream>
#include <cstddef>

using namespace std;

class MyPrintArrayUtils
{
  private:
    static void print_array_helper (int *inputArr, int size);
  public:
    static void print_array (int *inputArr, int size);
};

#endif // __MY_PRINT_ARRAY_UTILS_HPP

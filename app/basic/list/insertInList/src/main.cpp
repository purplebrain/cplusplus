#include <iostream>
#include <cstddef>
#include "MyPrintListUtils.hpp"
#include "MyListUtils.hpp"
#include "MyList.hpp"

using namespace std;

int
main (int argc, char *argv[])
{
    int inputArr[8] = {5, 8, 6, 7, 9, 2, 3, 1}; 
    MyList list(inputArr, 8);

    // Print the linked list by walking
    cout << "Current linked list is : " << endl;
    MyPrintListUtils::print_list(list.ptrListHead);

    //  Reverse the linked list and print it
    list.ptrListHead = MyListUtils::reverse_list(list.ptrListHead);
    cout << "Reversed linked list is : " << endl;
    MyPrintListUtils::print_list(list.ptrListHead);

    return (0);
}

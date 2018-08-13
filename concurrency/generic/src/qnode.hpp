#ifndef _QNODE_HPP
#define _QNODE_HPP

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class QNODE
{
  public:
    // constructor
    QNODE(int _data=0);
    // destructor
    ~QNODE() =default;
    // copy semantics
    QNODE(const QNODE& rhs) =default;
    QNODE& operator=(const QNODE& rhs) =default;
    // move semantics
    QNODE(QNODE&& rhs) =default;
    QNODE& operator=(QNODE&& rhs) =default;
  public:
    int m_data;
    QNODE* m_ptrNext;
};

#endif

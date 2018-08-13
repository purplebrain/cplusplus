#ifndef _QUEUE_HPP
#define _QUEUE_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <mutex>
#include <condition_variable>
#include "qnode.hpp"

using namespace std;

class QUEUE
{
  // < class-special-methods >
  public:
    // constructor
    QUEUE();
    QUEUE(int _max_size);
    // destructor
    ~QUEUE();
    // copy semantics
    QUEUE(const QUEUE& rhs) =default;
    QUEUE& operator=(const QUEUE& rhs) =default;
    // move semantics
    QUEUE(QUEUE&& rhs) =default;
    QUEUE& operator=(QUEUE&& rhs) =default;

  // < class-methods >
  public:
    int getOperationCnt(void) const;
    int getSize(void) const;
    void push(int _x);
    QNODE* pop(void);
  
  // < class-members >
  private:
    // members
    int m_size;
    int m_size_threshold;
    int m_operation_cnt;
    QNODE* m_ptrQ;
    QNODE* m_ptrHead;
    QNODE* m_ptrTail;
    // synchronization primitives
    mutable mutex m_mutex_Q;
    mutable condition_variable m_cond_Q;
    mutable mutex m_mutex_OperCnt;
    mutable mutex m_mutex_TH;
};

#endif

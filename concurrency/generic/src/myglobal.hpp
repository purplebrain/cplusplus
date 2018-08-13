#ifndef _MY_GLOBAL_HPP
#define _MY_GLOBAL_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <mutex>
#include <condition_variable>

using namespace std;

template <class T>
class MY_GLOBAL
{
  // < class-special-methods >
  public:
    // constructor
    MY_GLOBAL() =default;
    MY_GLOBAL(T _data);
    // destructor
    ~MY_GLOBAL() =default;
  
  // < class-methods >
  public:
    void set(T _data);
    T get(void);  

  // < class-members >
  private:
    // members
    T m_data;
    // synchronization primitives
    mutex m_mutex_data;
};

template <class T>
MY_GLOBAL<T>::MY_GLOBAL(T _data)
{
  this->m_data = _data;
}

template <class T>
void
MY_GLOBAL<T>::set(T _data)
{
  unique_lock<mutex> uLock_data(this->m_mutex_data);
  this->m_data = _data;
}

template <class T>
T
MY_GLOBAL<T>::get(void)
{
  unique_lock<mutex> uLock_data(this->m_mutex_data);
  return (this->m_data);
}

#endif // _MY_GLOBAL_HPP

#ifndef _AUTO_PTR_HPP
#define _AUTO_PTR_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <memory>

using namespace std;

template<class T>
class Auto_ptr3
{
  private:
	  T* m_ptr;
	public:
	  // Constructor
    Auto_ptr3(T* ptr = nullptr);

    // Destructor
    ~Auto_ptr3();

		// Copy constructor
		Auto_ptr3(const Auto_ptr3& );
 
		// Copy assignment
		Auto_ptr3& operator=(const Auto_ptr3& );
 
    // Operators
		T& operator*() const { return *m_ptr; }
		T* operator->() const { return m_ptr; }

    // Methods
		bool isNull() const; 
};

#endif // _AUTO_PTR_HPP

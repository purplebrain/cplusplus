#ifndef _BASE_HPP
#define _BASE_HPP

#include <iostream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

class BASE
{
  // special members
  public:
		// constructor & destructor
    BASE();
    BASE(int _size);
    BASE(int _size, string _name);
    ~BASE();
		// copy-semantics
    BASE(const BASE& rhs);
    BASE& operator=(const BASE& rhs);
		// move-semantics
    BASE(BASE&& rhs);
    BASE& operator=(BASE&& rhs);

  // methods
  public:
    void printDetails(void) const;

  // members
  public:
    int* m_ptrArr;
    int m_size;
    string m_name;
};

#endif

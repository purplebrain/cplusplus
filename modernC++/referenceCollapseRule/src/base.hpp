#include <iostream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

class BASE
{
  // special members
  public:
    BASE();
    BASE(int _size);
    ~BASE();

    BASE(const BASE& rhs);
    BASE& operator=(const BASE& rhs);

    BASE(BASE&& rhs);
    BASE& operator=(BASE&& rhs);

  // methods
  public:
    void printDetails(void) const;

  // members
  public:
    int* m_ptrArr;
    int m_size;
};

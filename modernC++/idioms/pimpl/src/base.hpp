#include <iostream>
#include <string>
#include <cstring>
#include <memory>

using namespace std;

struct Impl
{

  Impl() {
    cout << "Impl->Constructor#1" << endl;
    m_size = 0;
    m_arr = nullptr;
  }

  Impl(int _size) {
    cout << "Impl->Constructor#2" << endl;
    m_size = _size;
    m_arr = (_size ? new int[_size] : 0);
  }

  int m_size;
  int *m_arr;
};

class BASE
{
  public:
    BASE();
    BASE(int);
    ~BASE();
    BASE(const BASE&);
    BASE& operator=(const BASE&);

  public:
    void printGrp(void);

  private:
    unique_ptr<Impl> pimpl;
};


#include "base.hpp"

BASE::BASE()
{
  cout << "BASE->Constructor#1" << endl;
  this->pimpl = make_unique<Impl>(Impl());
}

BASE::BASE(int _size)
{
  cout << "BASE->Constructor#2" << endl;
  this->pimpl = make_unique<Impl>(Impl(_size));
  for (int i = 0; i < _size; i++) {
    this->pimpl->m_arr[i] = i;
  }
}

BASE::~BASE()
{
  cout << "BASE->Destructor" << endl;
  //delete [] this->pimpl->m_arr;
}

BASE::BASE(const BASE& rhs)
{
  cout << "BASE->CopyConstructor" << endl; 
  this->pimpl = make_unique<Impl>(Impl(*rhs.pimpl));
}

BASE&
BASE::operator=(const BASE& rhs)
{
  cout << "BASE->AssignmentOperator" << endl; 
  if (this != &rhs) {
    delete [] this->pimpl->m_arr;
    this->pimpl->m_size = 0;
    this->pimpl = make_unique<Impl>(*rhs.pimpl);
  }
  return (*this);
}

void
BASE::printGrp(void)
{
  cout << "Group Elements : ";
  if (pimpl->m_size) {
    for (int i = 0; i < pimpl->m_size; i++) {
      cout << pimpl->m_arr[i] << " ";
    }
  } else {
    cout << "none";
  }
  cout << endl;

  return;
}

#include "base.hpp"

BASE::BASE()
{
  cout << "Constructor#1" << endl;
  this->m_name = "dummy";
  this->m_size = 0;
  this->m_ptrArr = nullptr;
}

BASE::BASE(int _size) : m_size(_size)
{
  cout << "Constructor#2" << endl;
  this->m_name = "dummy";
  this->m_ptrArr = (m_size ? (new int [m_size]) : nullptr);
  assert(this->m_size != 0);
  if (m_ptrArr) {
    for (int i = 0; i < this->m_size; i++) {
      this->m_ptrArr[i] = i;
    }
  }
}

BASE::BASE(int _size, string _name) : m_size(_size), m_name(_name)
{
  cout << "Constructor#3" << endl;
  this->m_ptrArr = (m_size ? (new int [m_size]) : nullptr);
  assert(this->m_size != 0);
  if (m_ptrArr) {
    for (int i = 0; i < this->m_size; i++) {
      this->m_ptrArr[i] = i;
    }
  }
}

BASE::~BASE()
{
  cout << "obj-" << this->m_name << " ,Destructor" << endl;
  delete [] this->m_ptrArr;
}

BASE::BASE(const BASE& rhs)
{
  cout << "CopyConstructor" << endl;
  this->m_size = rhs.m_size;
  this->m_ptrArr = (rhs.m_size ? (new int [rhs.m_size]) : nullptr);
  for (int i = 0; i < this->m_size; i++) {
    this->m_ptrArr[i] = rhs.m_ptrArr[i];
  }
}

BASE&
BASE::operator=(const BASE& rhs)
{
  cout << "CopyAssignment" << endl;
  if (this != &rhs) {
    this->m_name = rhs.m_name;
    this->m_size = rhs.m_size;
    this->m_ptrArr = (rhs.m_size ? (new int [rhs.m_size]) : nullptr);
    for (int i = 0; i < this->m_size; i++) {
      this->m_ptrArr[i] = rhs.m_ptrArr[i];
    }
  }
  return (*this);
}

BASE::BASE(BASE&& rhs)
{
  cout << "MoveConstructor" << endl;
  this->m_name = rhs.m_name;
  this->m_size = rhs.m_size;
  this->m_ptrArr = rhs.m_ptrArr;
  rhs.m_name = nullptr;
  rhs.m_size = 0;
  rhs.m_ptrArr = nullptr;
}

BASE&
BASE::operator=(BASE&& rhs)
{
  cout << "MoveAssignment" << endl;
  if (this != &rhs) {
    this->m_size = rhs.m_size;
    this->m_ptrArr = rhs.m_ptrArr;
    rhs.m_size = 0;
    rhs.m_ptrArr = nullptr;
  }

  return (*this);
}

void
BASE::printDetails() const
{
  if (this->m_size) {
    cout << "obj-" << this->m_name;
    cout << " ,resource : ";
    for (int i = 0; i < this->m_size; i++) {
      cout << this->m_ptrArr[i] << " ";
    }
  } else {
    cout << "resource is empty" << endl;
  }

  cout << endl;
  return;
}

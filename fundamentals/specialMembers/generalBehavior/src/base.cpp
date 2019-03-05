#include "base.hpp"

/* 
 *  ---------------
 *  SPECIAL MEMBERS
 *  ---------------
 */

BASE::BASE(int count, string _name)
{
  this->m_name = _name;
  if ((count == -1) || (count == 0)) {
    this->m_ptrArrElements = nullptr;
    this->m_size = 0;
  } else {
    this->m_ptrArrElements = new int[count];
    this->m_size = count;
    for (int i=0; i < count; i++) {
      this->m_ptrArrElements[i] = i;
    }
  }

  cout << "Constructor#1 -> " << "m_name=" << this->m_name << 
                                 " ,size=" << this->m_size << endl;
}

BASE::BASE(const BASE& rhs)
{
  if ((rhs.m_size != -1) && (rhs.m_size != 0)) {
    this->m_ptrArrElements = new int [rhs.m_size];
    for (int i = 0; i < rhs.m_size; i++) {
      this->m_ptrArrElements[i] = rhs.m_ptrArrElements[i];
      this->m_size = rhs.m_size;
      this->m_name = rhs.m_name;
    }
  } else {
    this->m_ptrArrElements = nullptr;
    this->m_size = 0;
    this->m_name = "anonymous";
  }
  cout << "CopyConstructor -> " << "m_name=" << this->m_name <<
                                   " ,size=" << this->m_size << endl;
}

BASE&
BASE::operator=(const BASE& rhs)
{
  if (this == &rhs) {
    return (*this);
  }

  if ((rhs.m_size != -1) && (rhs.m_size != 0)) {
    delete [] this->m_ptrArrElements;
    this->m_ptrArrElements = new int [rhs.m_size];
    for (int i = 0; i < rhs.m_size; i++) {
      this->m_ptrArrElements[i] = rhs.m_ptrArrElements[i];
      this->m_size = rhs.m_size;
      this->m_name = rhs.m_name;
    }
  } else {
    this->m_ptrArrElements = nullptr;
    this->m_size = 0;
    this->m_name = "anonymous";
  }

  cout << "CopyAssignment" << endl;

  return (*this);
}

BASE::BASE(BASE&& rhs)
{
  this->m_ptrArrElements = rhs.m_ptrArrElements;
  this->m_size = rhs.m_size;
  this->m_name = rhs.m_name;

  rhs.m_ptrArrElements = nullptr;
  rhs.m_size = -1;
  rhs.m_name.append("-moved");

  cout << "MoveConstructor -> " << "m_name=" << this->m_name <<
                                   " ,size=" << this->m_size << endl;
}

BASE&
BASE::operator=(BASE&& rhs)
{
  if (&rhs == this)
  {
    cout << "RvalueReference of the same object" << endl;
    return (*this);
  }

  delete [] this->m_ptrArrElements;

  this->m_ptrArrElements = rhs.m_ptrArrElements;
  this->m_size = rhs.m_size;
  this->m_name = rhs.m_name;

  rhs.m_ptrArrElements = nullptr;
  rhs.m_size = -1;
  rhs.m_name.append("-moved");

  cout << "MoveAssignment" << endl;

  return (*this);
}

BASE::~BASE()
{
  cout << "Destructor -> " << "m_name=" << this->m_name << 
                              " ,size=" << this->m_size << endl;

  delete [] this->m_ptrArrElements;
}

/* 
 *  ---------------------
 *  USER DEFINED MEMEBERS
 *  ---------------------
 */

BASE& 
BASE::operator+=(const BASE& rhs)
{
  cout << "Overloaded '+=' Operator" << endl;

  int count = (rhs.m_size > this->m_size)? rhs.m_size : this->m_size;

  int *ptrArrElementsTmp = new int [count];

  bool isThisInRange = false;
  bool isRhsInRange = false;
  if (this->m_ptrArrElements && this->m_size <= count) {
    isThisInRange = true;
  }
  if (rhs.m_ptrArrElements && rhs.m_size <= count) {
    isRhsInRange = true;
  }

  for (int i=0; i < count; i++)
  {
    if (isThisInRange && isRhsInRange) {
      ptrArrElementsTmp[i] = this->m_ptrArrElements[i] + rhs.m_ptrArrElements[i];
    } else if (isRhsInRange) {
      ptrArrElementsTmp[i] = rhs.m_ptrArrElements[i];
    } else if (isThisInRange) {
      ptrArrElementsTmp[i] = this->m_ptrArrElements[i];
    }
  }

  delete [] this->m_ptrArrElements;
  this->m_ptrArrElements = ptrArrElementsTmp;
  this->m_size = count;

  return (*this);
}

BASE
BASE::operator+(const BASE& rhs)
{
  BASE tmp(*this);
  tmp += rhs;

  cout << "Overloaded '+' Operator" << endl;

  return (tmp);
}

int&
BASE::operator[](int idx)
{
  cout << "Overloaded '[]' Operator" << endl;

  return (this->m_ptrArrElements[idx]);
}

bool
BASE::operator==(const BASE& rhs)
{
  bool retVal = true;
  if (rhs.m_size == this->m_size) {
    for (int i = 0; i < this->m_size; i++) {
      if (rhs.m_ptrArrElements[i] == this->m_ptrArrElements[i]) {
        continue;
      } else {
        retVal = false;
        break;
      }
    }
  } else {
    retVal = false;
  }

  return (retVal);
}

int
BASE::getElement(int idx)
{
  return (this->m_ptrArrElements[idx]);
}

int
BASE::getGrpSize(void)
{
  return (this->m_size);
}

void
BASE::printGrp(void)
{
  cout << "Group Elements : ";
  if (this->m_size) {
    for (int i = 0; i < this->m_size; i++) {
      cout << this->m_ptrArrElements[i] << " ";
    }
  } else {
    cout << "none";
  }
  cout << endl;

  return;
}

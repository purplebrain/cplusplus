#include "base.hpp"

/* 
 *  ---------------
 *  SPECIAL MEMBERS
 *  ---------------
 */

BASE::BASE(int count)
{
  cout << "Constructor#1" << endl;

  if ((count == -1) || (count == 0)) {
    this->ptrArrElements = nullptr;
    this->numElements = 0;
  } else {
    this->ptrArrElements = new int[count];
    this->numElements = count;
    for (int i=0; i < count; i++) {
      this->ptrArrElements[i] = i;
    }
  }
}

BASE::BASE(const BASE& rhs)
{
  cout << "CopyConstructor" << endl;

  if ((rhs.numElements != -1) && (rhs.numElements != 0)) {
    this->ptrArrElements = new int [rhs.numElements];
    for (int i = 0; i < rhs.numElements; i++) {
      this->ptrArrElements[i] = rhs.ptrArrElements[i];
      this->numElements = rhs.numElements;
    }
  } else {
    this->ptrArrElements = nullptr;
    this->numElements = 0;
  }
}

BASE&
BASE::operator=(const BASE& rhs)
{
  cout << "CopyAssignment" << endl;

  // self-assignment check
  if (this == &rhs) {
    return (*this);
  }

  if ((rhs.numElements != -1) && (rhs.numElements != 0)) {
    // destroy the existing content in the resource
    delete [] this->ptrArrElements;
    // assign new contents in the resource
    this->ptrArrElements = new int [rhs.numElements];
    for (int i = 0; i < rhs.numElements; i++) {
      this->ptrArrElements[i] = rhs.ptrArrElements[i];
      this->numElements = rhs.numElements;
    }
  } else {
    this->ptrArrElements = nullptr;
    this->numElements = 0;
  }

  return (*this);
}

BASE::BASE(BASE&& rhs)
{
  cout << "MoveConstructor" << endl;

  this->ptrArrElements = rhs.ptrArrElements;
  this->numElements = rhs.numElements;

  rhs.ptrArrElements = nullptr;
  rhs.numElements = -1;
}

BASE&
BASE::operator=(BASE&& rhs)
{
  cout << "MoveAssignment" << endl;

  if (&rhs == this)
  {
    cout << "RvalueReference of the same object" << endl;
    return (*this);
  }

  delete [] this->ptrArrElements;

  this->ptrArrElements = rhs.ptrArrElements;
  this->numElements = rhs.numElements;

  rhs.ptrArrElements = nullptr;
  rhs.numElements = -1;

  return (*this);
}

BASE::~BASE()
{
  cout << "Destructor" << endl;

  delete [] this->ptrArrElements;
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

  int count = (rhs.numElements > this->numElements)? rhs.numElements : 
                                                     this->numElements;

  int *ptrArrElementsTmp = new int [count];

  bool isThisInRange = false;
  bool isRhsInRange = false;
  if (this->ptrArrElements && this->numElements <= count) {
    isThisInRange = true;
  }
  if (rhs.ptrArrElements && rhs.numElements <= count) {
    isRhsInRange = true;
  }

  for (int i=0; i < count; i++)
  {
    if (isThisInRange && isRhsInRange) {
      ptrArrElementsTmp[i] = this->ptrArrElements[i] + rhs.ptrArrElements[i];
    } else if (isRhsInRange) {
      ptrArrElementsTmp[i] = rhs.ptrArrElements[i];
    } else if (isThisInRange) {
      ptrArrElementsTmp[i] = this->ptrArrElements[i];
    }
  }

  delete [] this->ptrArrElements;
  this->ptrArrElements = ptrArrElementsTmp;
  this->numElements = count;

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
/*
int&
BASE::operator[](int idx)
{
  cout << "Overloaded '[]' Operator" << endl;

  return (this->ptrArrElements[idx]);
}
*/
bool
BASE::operator==(const BASE& rhs)
{
  bool retVal = true;
  if (rhs.numElements == this->numElements) {
    for (int i = 0; i < this->numElements; i++) {
      if (rhs.ptrArrElements[i] == this->ptrArrElements[i]) {
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
  return (this->ptrArrElements[idx]);
}

int
BASE::getGrpSize(void)
{
  return (this->numElements);
}

void
BASE::printGrp(void)
{
  cout << "Group Elements : ";
  if (this->numElements) {
    for (int i = 0; i < this->numElements; i++) {
      cout << this->ptrArrElements[i] << " ";
    }
  } else {
    cout << "none";
  }
  cout << endl;

  return;
}

void 
swapObj(BASE& A, BASE& B)
{
  swap(A.numElements, B.numElements);
  swap(A.ptrArrElements, B.ptrArrElements);
}

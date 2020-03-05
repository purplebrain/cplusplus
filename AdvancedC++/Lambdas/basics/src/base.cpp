#include "base.hpp"

BASE::BASE(string _name="tmpObj") : name(_name)
{
  cout << "Constructor#1 : " << this->name << endl;
  this->a = -1;
  this->b = -1;
  this->c = -1;
}

BASE::BASE(string _name="tmpObj", int _a=-1, int _b=-1) : name(_name), a(_a), b(_b)
{
  cout << "Constructor#2 : " << this->name << endl;
	this->c = _a + _b;
}

BASE::~BASE()
{
  cout << "Destructor : " << this->name << endl;
}

BASE::BASE(const BASE& rhs)
{
  this->name = rhs.name;
  cout << "CopyConstructor : " << this->name << " to " << rhs.name << endl;
  this->a = rhs.a;
  this->b = rhs.b;
  this->c = rhs.c;
}

BASE&
BASE::operator=(const BASE& rhs)
{
  if (this != &rhs) {
    this->name = rhs.name;
    cout << "CopyAssignment : " << this->name << " to " << rhs.name << endl;
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
  } 
  
  return (*this);
}

BASE::BASE(BASE&& rhs)
{
  if (&rhs != this) {
    this->name = rhs.name;
    cout << "MoveConstructor : " << this->name << " to " << rhs.name << endl;
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
    rhs.a = -1;
    rhs.b = -1;
    rhs.c = -1;
  }
}

BASE&
BASE::operator=(BASE&& rhs)
{
  if (this != &rhs) {
    this->name = rhs.name;
    cout << "MoveAssignment : " << this->name << " to " << rhs.name << endl;
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
    rhs.name = "";
    rhs.a = -1;
    rhs.b = -1;
    rhs.c = -1;
  } 
    
  return (*this);
}

BASE&
BASE::operator+(const BASE& rhs)
{
  cout << "+Operator" << endl;

  this->a += rhs.a;
  this->b += rhs.b;
  this->c = this->a + this->b;    

  return (*this);
}

void
BASE::printABC(void)
{
  cout << "[a, b, c] = " << "[" << this->a << ", " << this->b << ", " << this->c << "]" << endl;
  return;
}

int
BASE::getC(void)
{
  return (this->c);
}

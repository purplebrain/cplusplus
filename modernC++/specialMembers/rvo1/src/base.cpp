#include "base.hpp"

BASE::BASE(string _name) : name(_name)
{
  cout << "Constructor#1 : " << this->name << endl;
  this->a = -1;
  this->b = -1;
  this->c = -1;
}

BASE::BASE(string _name, int _a, int _b) : name(_name), a(_a), b(_b)
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
  cout << "CopyConstructor : " << rhs.name << " to " << this->name << endl;
  this->a = rhs.a;
  this->b = rhs.b;
  this->c = rhs.c;
}

BASE&
BASE::operator=(const BASE& rhs)
{
  cout << "CopyAssignment : " << rhs.name << " to " << this->name << endl;
  if (this != &rhs) {
    this->name = rhs.name;
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
  } 
  
  return (*this);
}

BASE::BASE(BASE&& rhs)
{
  cout << "MoveConstructor : " << rhs.name << " to " << this->name << endl;
  if (this != &rhs) {
    this->name = rhs.name;
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
    rhs.name = "null";
    rhs.a = -1;
    rhs.b = -1;
    rhs.c = -1;
  }
}

BASE&
BASE::operator=(BASE&& rhs)
{
  cout << "MoveAssignment : " << rhs.name << " to " << this->name << endl;
  if (this != &rhs) {
    this->name = rhs.name;
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

#include "base.hpp"

uint g_cnt = 0;

BASE::BASE()
{
  this->a = -1;
  this->b = -1;
  this->c = -1;
  if (!g_cnt) {
    this->name = "vanilla";
  } else if (g_cnt == 1) {
    this->name = "silver";
  } else if (g_cnt == 2) {
    this->name = "gold";
  }
  cout << "Constructor#1 : " << this->name << endl;
  g_cnt++;
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
  cout << "CopyConstructor : from " << rhs.name;
  this->name = rhs.name;
  this->a = rhs.a;
  this->b = rhs.b;
  this->c = rhs.c;
  if (!g_cnt) {
    this->name = "vanilla";
  } else if (g_cnt == 1) {
    this->name = "silver";
  } else if (g_cnt == 2) {
    this->name = "gold";
  }
  cout << " to " << this->name << endl;
  g_cnt++;
}

BASE&
BASE::operator=(const BASE& rhs)
{
  if (this != &rhs) {
    cout << "CopyAssignment : " << this->name << " to " << rhs.name << endl;
    this->name = rhs.name;
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
  } 
  
  return (*this);
}

BASE::BASE(BASE&& rhs)
{
  cout << "MoveConstructor : from " << rhs.name;
  if (&rhs != this) {
    this->name = rhs.name;
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
    rhs.a = -1;
    rhs.b = -1;
    rhs.c = -1;
  }
  if (!g_cnt) {
    this->name = "vanilla";
  } else if (g_cnt == 1) {
    this->name = "silver";
  } else if (g_cnt == 2) {
    this->name = "gold";
  }
  cout << " to " << this->name << endl;
  g_cnt++;
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

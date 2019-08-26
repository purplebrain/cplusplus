#include "data.hpp"

DATA::DATA()
{
  cout << "Constructor#1" << endl;
  this->m_x = 0;
  this->m_y = 0;
  this->m_op = NONE;
}

DATA::DATA(int _x, int _y, OPCODE _op)
{
  cout << "Constructor#2" << endl;
  this->m_x = _x;
  this->m_y = _y;
  this->m_op = _op;
}

DATA::DATA(const DATA& rhs)
{
  cout << "CopyConstructor" << endl;
  this->m_x = rhs.m_x;
  this->m_y = rhs.m_y;
  this->m_op = rhs.m_op;
}

DATA&
DATA::operator=(const DATA& rhs)
{
  cout << "CopyAssignment" << endl;
  if (this != &rhs) {
    this->m_x = rhs.m_x;
    this->m_y = rhs.m_y;
    this->m_op = rhs.m_op;
  } 

  return (*this);
}

DATA::DATA(DATA&& rhs)
{
  cout << "MoveConstructor" << endl;
  this->m_x = rhs.m_x;
  this->m_y = rhs.m_y;
  this->m_op = rhs.m_op;
  rhs.m_x = 0;
  rhs.m_y = 0;
  rhs.m_op = NONE;
}

DATA&
DATA::operator=(DATA&& rhs)
{
  cout << "MoveAssignment" << endl;
  if (this != &rhs) {
    this->m_x = rhs.m_x;
    this->m_y = rhs.m_y;
    this->m_op = rhs.m_op;
    rhs.m_x = 0;
    rhs.m_y = 0;
    rhs.m_op = NONE;
  }

  return (*this);
}

DATA
DATA::operator+(const DATA& rhs)
{
  cout << "+Operator" << endl;
  return (DATA(this->m_x + rhs.m_x,
               this->m_y + rhs.m_y,
               (this->m_op >= rhs.m_op) ? this->m_op : rhs.m_op));
}

DATA
DATA::operator-(const DATA& rhs)
{
  cout << "-Operator" << endl;
  return (DATA(this->m_x - rhs.m_x,
               this->m_y - rhs.m_y,
               (this->m_op >= rhs.m_op) ? this->m_op : rhs.m_op));
}

DATA
DATA::operator*(const DATA& rhs)
{
  cout << "*Operator" << endl;
  return (DATA(this->m_x * rhs.m_x,
               this->m_y * rhs.m_y,
               (this->m_op >= rhs.m_op) ? this->m_op : rhs.m_op));
}

DATA
DATA::operator/(const DATA& rhs)
{
  cout << "/Operator" << endl;
  return (DATA(this->m_x / rhs.m_x,
               this->m_y / rhs.m_y,
               (this->m_op >= rhs.m_op) ? this->m_op : rhs.m_op));
}

void 
DATA::printDetails(void)
{
  cout << "[x,y,opcode] = [" << this->m_x << 
                          "," << this->m_y <<
                          "," << this->getOpcode(this->m_op) <<
                          "]" << endl;
  return;
}

string 
DATA::getOpcode(OPCODE op)
{
  switch (op) {
    case ADD:
      return ("ADD");
    case SUB:
      return ("SUB");
    case MULT:
      return ("MULT");
    case DIV:
      return ("DIV");
    default:
      return ("NONE");
  }
}

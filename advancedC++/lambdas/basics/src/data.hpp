#ifndef _DATA_HPP
#define _DATA_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <type_traits>
#include <typeinfo>

using namespace std;

enum OPCODE
{
  NONE,
  ADD,
  SUB,
  MULT,
  DIV,
  INVALID
};

struct DATA
{
  public:
    DATA();
    DATA(int _x, int _y, OPCODE _op=NONE);
    ~DATA() =default;

    DATA(const DATA& rhs);
    DATA& operator=(const DATA& rhs);

    DATA(DATA&& rhs);
    DATA& operator=(DATA&& rhs);

    DATA operator+(const DATA& rhs);
    DATA operator-(const DATA& rhs);
    DATA operator*(const DATA& rhs);
    DATA operator/(const DATA& rhs);

    void printDetails(void);
    string getOpcode(OPCODE op);

  public:
    int m_x;
    int m_y;
    OPCODE m_op;
};


#endif

#include <iostream>
#include <typeinfo>
#include "base.hpp"

using namespace std;

BASE::BASE()
{
    this->privateMember = 0;
    this->protectedMember = 0;
    this->publicMember = 0;
}

BASE::BASE(int _A)
{
    this->publicMember = _A;
    this->protectedMember = this->publicMember + 10;
    this->privateMember = this->publicMember + 100;
}

BASE::~BASE()
{

}

void 
printMembers(BASE *ptrObj)
{

}

void
BASE::printMembers(void)
{

}

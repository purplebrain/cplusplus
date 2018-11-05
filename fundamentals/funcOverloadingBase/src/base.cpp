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
BASE::printMembers(BASE *ptrObj)
{
    cout << "BasePublicMember : " << ptrObj->publicMember << endl;
    cout << "BaseProtectedMember : " << ptrObj->protectedMember << endl;
    //cout << "BasePrivateMember : " << ptrObj->privateMember << endl;
}

void
BASE::printMembers(void)
{

}

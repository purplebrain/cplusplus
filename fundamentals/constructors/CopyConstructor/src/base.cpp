#include "base.hpp"

BASE::BASE() 
{
    cout << "In BASE::BASE() " << endl;
    this->a = 0;
    this->b = 0;
    this->ptrBuffer = NULL;
}

BASE::BASE(int _a, int _b) : a(_a), b(_b)
{
    cout << "In BASE::BASE(int, int) " << endl;
    this->ptrBuffer = new char[(a+b)];
}

BASE::BASE(const BASE& master)
{
    cout << "In BASE::copy-constructor " << endl;
    //this->a = master.a;
    //this->b = master.b;
    this->a = 1024;
    this->b = 1024;
    this->ptrBuffer = new char[(this->a + this->b)];
    memcpy(this->ptrBuffer, master.ptrBuffer, (master.a + master.b));
}

BASE&
BASE::operator=(const BASE& rhs)
{
    //BASE tmp;
    cout << "In BASE::operator= " << endl;
    this->a = rhs.a;
    this->b = rhs.b;
    if (this->ptrBuffer) {
        delete (this->ptrBuffer);
    }
    this->ptrBuffer = new char[(this->a + this->b)];
    memcpy(this->ptrBuffer, rhs.ptrBuffer, (rhs.a + rhs.b));

    return (*this); 
}

BASE::~BASE()
{
    cout << "In BASE::~BASE()" << endl;
    delete (this->ptrBuffer);
}


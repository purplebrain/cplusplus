#include "base.hpp"

BASE::BASE() 
{
    cout << "In BASE::BASE() " << endl;
    this->m_a = 0;
    this->m_b = 0;
    this->m_ptrBuffer = NULL;
}

BASE::BASE(int _a, int _b)
{
    cout << "In BASE::BASE(int, int) " << endl;
    this->m_a = _a;
    this->m_b = _b;
    this->m_ptrBuffer = new char[(m_a + m_b)];
}

BASE::BASE(const BASE& rhs)
{
    cout << "In BASE::copy-constructor " << endl;
    this->m_a = 1024;
    this->m_b = 1024;
    this->m_ptrBuffer = new char[(this->m_a + this->m_b)];
    memcpy(this->m_ptrBuffer, 
           rhs.m_ptrBuffer, 
           (rhs.m_a + rhs.m_b));
}

BASE::BASE(BASE&& rhs)
{
    cout << "In BASE::move-constructor " << endl;
    this->m_a = rhs.m_a;
    this->m_b = rhs.m_b;
    this->m_ptrBuffer = rhs.m_ptrBuffer;
    rhs.m_ptrBuffer = NULL;
}

BASE&
BASE::operator=(const BASE& rhs)
{
    //BASE tmp;
    cout << "In BASE::copy-assignment " << endl;
    this->m_a = rhs.m_a;
    this->m_b = rhs.m_b;
    if (this->m_ptrBuffer) {
        delete (this->m_ptrBuffer);
    }
    this->m_ptrBuffer = new char[(this->m_a + this->m_b)];
    memcpy(this->m_ptrBuffer, rhs.m_ptrBuffer, (rhs.m_a + rhs.m_b));

    return (*this); 
}

BASE&
BASE::operator=(BASE&& rhs)
{
    cout << "In BASE::move-assignment " << endl;
    this->m_a = rhs.m_a;
    this->m_b = rhs.m_b;
    this->m_ptrBuffer = rhs.m_ptrBuffer;
    rhs.m_ptrBuffer = NULL;

    return (*this); 
}

BASE::~BASE()
{
    cout << "In BASE::~BASE()" << endl;
    delete (this->m_ptrBuffer);
}


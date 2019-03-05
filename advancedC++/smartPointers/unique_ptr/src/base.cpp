#include "base.hpp"

BASE::BASE()
{
    this->ptrBuffer = NULL;
    this->_REAL = 0;
    this->_IMG = 0;
}

BASE::BASE(int real, int img) : _REAL(real), _IMG(img)
{
    this->ptrBuffer = new char[this->_REAL+1];
    for (int i = 0; i < this->_REAL; i++) {
        ptrBuffer[i] = (char)this->_IMG;
    }
    ptrBuffer[this->_REAL] = '\0';
}

BASE::BASE(const BASE& rhs)
{
    this->_REAL = rhs._REAL;
    this->_IMG = rhs._IMG;
    this->ptrBuffer = new char[strlen(rhs.ptrBuffer)+1];
    for (unsigned int i = 0; i < strlen(rhs.ptrBuffer); i++) {
        ptrBuffer[i] = (char)rhs._IMG;
    }
    ptrBuffer[strlen(rhs.ptrBuffer)] = '\0';
}

BASE&
BASE::operator=(const BASE& rhs)
{
    this->_REAL = rhs._REAL;
    this->_IMG = rhs._IMG;
    return (*this);
}

bool 
BASE::operator==(const BASE& rhs)
{
    return ((this->_REAL == rhs._REAL) && (this->_IMG == rhs._IMG));
}

void
BASE::printContent(void)
{

    if (this->ptrBuffer) {
        string tmp;
        tmp.assign(this->ptrBuffer);
        cout << "------------------------------" << endl;
        cout << "[Real, Img] -> [" << this->_REAL << ", " << this->_IMG << "]" << endl;
        cout << "Buffer -> " << tmp << endl;
        cout << "------------------------------" << endl;
    } else {
        cout << "Complex Number is empty" << endl;
    }

    return;
}

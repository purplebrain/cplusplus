#include <iostream>
#include <string>
#include <cstring>
#include <memory>

using namespace std;

class BASE
{
    // MEMBERS
    public:
        char *ptrBuffer;
        int _REAL;
        int _IMG;

    // METHODS
    public:
        // < CONSTRUCTOR ver#0 >
        BASE();
        
        // < CONSTRUCTOR ver#1 >
        BASE(int real, int img);

        // < COPY CONSTRUCTOR >
        BASE(const BASE& rhs);

        // < COPY ASSIGNMENT OPERATOR >
        BASE& operator=(const BASE& rhs);
        bool operator==(const BASE& rhs);
        void printContent(void);
};

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

int
main (int argc, char *argv[])
{
    string inputStr;
    int real, img;

    while (1) {
        cout << "Enter [quit|stay]" << endl;
        cin >> inputStr;
        if (inputStr.compare("quit") == 0) {
            break;
        } else if (inputStr.compare("stay") == 0) {
            cout << "Enter 'int' for Real part : ";
            cin >> real;
            cout << "Enter 'int' for Img part : ";
            cin >> img;
            break;
        } else {
            continue;
        }
    }

    BASE A(real, img);   
    A.printContent();

    unique_ptr<BASE> uptrBase(new BASE(10, 120));
    unique_ptr<BASE> uptrBase1 = move(uptrBase);

    if (*uptrBase1 == A) {
        cout << "Equal" << endl;
    } else {
        cout << "Unequal" << endl;
    }

    return (0);
}

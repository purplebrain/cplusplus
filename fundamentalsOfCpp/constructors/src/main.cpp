#include <iostream>
#include <cstring>

using namespace std;

class BASE
{
    private:
        int a;
        int b;
        char *ptrBuffer;
    public:
        BASE();														// 	default constructor
        BASE(int _a, int _b);							//	parameterized constructor
        BASE(const BASE& master);					//	copy constructor
        BASE& operator=(const BASE& rhs);	//	copy assignment operator
        ~BASE();
        friend int main(int argc, char *argv[]);
};

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

    /*
    tmp.a = rhs.a;
    //tmp.b = rhs.b;
    tmp.b = 512;
    if (tmp.ptrBuffer) {
        delete (tmp.ptrBuffer);
    }
    tmp.ptrBuffer = new char[(tmp.a + tmp.b)];
    memcpy(tmp.ptrBuffer, rhs.ptrBuffer, (rhs.a + rhs.b));
    return (tmp);
    */
}

BASE::~BASE()
{
    cout << "In BASE::~BASE()" << endl;
    delete (this->ptrBuffer);
}

int
main (int argc, char *argv[])
{
    BASE *ptrBase1 = new BASE(2, 2);
    BASE *ptrBase2 = new BASE(4, 12);
    BASE A(*ptrBase1);
    BASE B(*ptrBase2);

    BASE C = *ptrBase1;
    C = A;

    BASE D;
    D = *ptrBase2;

    return (0);
}

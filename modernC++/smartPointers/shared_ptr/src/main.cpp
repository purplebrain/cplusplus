#include <iostream>
#include <memory>

using namespace std;

class BASE
{
    private:
        int _A;
    public:
        BASE();
        BASE(int X);
        ~BASE();
        void printContent();
};

BASE::BASE()
{
    this->_A = 0;
}

BASE::BASE(int X):_A(X)
{

}

BASE::~BASE()
{

}

void
BASE::printContent(void)
{
    cout << "Value = " << this->_A << endl;
}

int
main (int argc, char *argv[])
{
    auto ptrBase1 = new BASE();
    auto ptrBase2 = new BASE(10);

    shared_ptr<BASE> sptr1(ptrBase1);
    shared_ptr<BASE> sptr2(ptrBase2);

    cout << "Shared Pointer #1 " << sptr1 << endl;
    cout << "Shared Pointer #2 " << sptr2 << endl;

    sptr1->printContent();
    sptr2->printContent();

    cout << "Swapping raw pointers" << endl;
    sptr1.swap(sptr2);

    sptr1->printContent();
    sptr2->printContent();

    return (0);
}

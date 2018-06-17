#include <iostream>

using namespace std;

class Base
{
	public:
		virtual void who()
    {
        cout << "I am Base\n";
    }
};

class Derived: public Base
{
	public:
    void who()
    { 
        cout << "I am Derived\n";
    }
};
 
int 
main(int argc, char *argv[])
{
    // note here virtual function who() is called through
    // object of the class (it will be resolved at compile
    // time) so it can be inlined.
    Base b;
    b.who();
 
    // Here virtual function is called through pointer,
    // so it cannot be inlined
    Base *ptr = new Derived();
    ptr->who();
 
    return 0;
}

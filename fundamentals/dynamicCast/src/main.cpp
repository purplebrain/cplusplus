#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{ 
public:    
    int val;
    Base():val(3)
    {
        cout << "Base ctor called\n";
    }
    virtual void show()
    { 
        cout << "Base virtual show called\n";
    }
    void getValue()
    {
        cout << "Base getValue : " << val << "\n";
    }
};

class Derived: public Base 
{
public:
    int dval;
    Derived():dval(33)
    {
        cout << "Derived ctor called\n";
    }
    void show()
    {
        cout << "Derived virtual show called\n";
    }
    void getDvalue()
    {
        cout << "Derived getDvalue : " << dval << "\n";
    }
};

void someGlobalFunction1(Base* bPtr)
{
		cout << "---------------------------------------------";
    cout << "\ntypeid(bPtr).name : " << typeid(bPtr).name();
    cout << "\ntypeid(*bPtr).name : " << typeid(*bPtr).name();
    cout << "\ntypeid(Base).name : " << typeid(Base).name();
    
    // Returns true if both type_info objects identify the same type, and false otherwise.
    // A derived type is not considered the same type as any of its base classes.
    if (typeid(Base) == typeid(*bPtr))
    {
        cout << "Base vs Derived typeid(bPtr) == typeid(*bPtr) is true\n";
    }
    else
    {
        cout << "Base vs Derived typeid(bPtr) == typeid(*bPtr) is false\n";
    }

    Derived *ptr = dynamic_cast<Derived*>(bPtr);
    if (ptr != NULL)
    {
        cout << "Base ptr had a complete derived object, dynamic_cast is successful\n";
        ptr->show();
        ptr->getDvalue();
        ptr->getValue();
    }
    else
    {
        cout << "Base ptr did not point to a complete Derived object .. only base functions are called\n";
        bPtr->show();
        bPtr->getValue();
    }
}

int main()
{
    Base bObj;
    Derived dObj;
    
    Base* ptr_base = &dObj;
    someGlobalFunction1(ptr_base);
    
    ptr_base = &bObj;
    someGlobalFunction1(ptr_base);
    
    Derived *ptr_derived = &dObj;
    someGlobalFunction1(ptr_derived);
    
    return 0;
}

#include <iostream>
#include <typeinfo>
#include "derived.hpp"

DERIVED::DERIVED()
{

}

DERIVED::DERIVED(int _A) : BASE(_A)
{


}

DERIVED::~DERIVED()
{

}

void
DERIVED::printMembers(DERIVED *ptrDerived)
{
    cout << "BasePublicMember : " << ptrDerived->publicMember << endl;
    cout << "BaseProtectedMember : " << ptrDerived->protectedMember << endl;
    //cout << "BasePrivateMember : " << ptrDerived->privateMember << endl;
}

void
DERIVED::printMembers(BASE *ptrBase)
{
    cout << "BasePublicMember : " << ptrBase->publicMember << endl;
    cout << "BaseProtectedMember : " << ptrBase->protectedMember << endl;
    //cout << "BasePrivateMember : " << ptrBase->privateMember << endl;
}

void
DERIVED::printMembers(void)
{
    cout << "BasePublicMember : " << publicMember << endl;
    cout << "BaseProtectedMember : " << protectedMember << endl;
    //cout << "BasePrivateMember : " << privateMember << endl;
}

void
DERIVED::printMembersWrapper(int X)
{
    BASE *ptrBase = new DERIVED(X);
    ptrBase->printMembers();
}

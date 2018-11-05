#ifndef __DERIVED_HPP
#define __DERIVED_HPP

#include "base.hpp"

using namespace std;

class DERIVED : public BASE
{
    public:
        DERIVED();
        DERIVED(int _A);
        ~DERIVED();
        static void printMembersWrapper(int X);
        void printMembers(DERIVED *ptrDerived);
        void printMembers(BASE *ptrObj);
        void printMembers(void);
};


#endif

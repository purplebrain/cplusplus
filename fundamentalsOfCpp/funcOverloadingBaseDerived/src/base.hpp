#ifndef __BASE_HPP
#define __BASE_HPP

using namespace std;

class BASE
{
    private:
        int privateMember;
    protected:
        int protectedMember;
    public:
        int publicMember;
    public:
        BASE();
        BASE(int _A);
        ~BASE();
        virtual void printMembers(BASE *ptrObj);
        virtual void printMembers(void);
};

#endif

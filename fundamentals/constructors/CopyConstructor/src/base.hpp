#ifndef __BASE_HPP
#define __BASE_HPP

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

#endif // __BASE_HPP

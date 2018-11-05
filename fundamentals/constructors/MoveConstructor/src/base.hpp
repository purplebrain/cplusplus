#ifndef __BASE_HPP
#define __BASE_HPP

#include <iostream>
#include <cstring>

using namespace std;

class BASE
{
    private:
        int m_a;
        int m_b;
        char *m_ptrBuffer;
    public:
        BASE();														// 	default constructor
        BASE(int _a, int _b);							//	parameterized constructor
        BASE(const BASE& master);					//	copy constructor
        BASE& operator=(const BASE& rhs);	//	copy assignment operator
        BASE(BASE&& master);					    //	move constructor
        BASE& operator=(BASE&& rhs);	    //	move assignment operator
        ~BASE();
        friend int main(int argc, char *argv[]);
};

#endif // __BASE_HPP

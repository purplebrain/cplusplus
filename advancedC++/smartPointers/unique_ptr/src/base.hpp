#include <iostream>
#include <cstring>

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


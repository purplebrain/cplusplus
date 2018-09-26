#include <iostream>
#include <cstring>
#include <string>
#include <type_traits>
#include <typeinfo>

using namespace std;
typedef unsigned int uint;

extern uint g_cnt;

class BASE
{
	private:
		int c;
	public:
    string name;
		int a;
		int b;
	public:
    // constructor & destructor
		BASE();
		BASE(string _name, int _a=-1, int _b=-1);
    ~BASE();

    // copy-semantics
		BASE(const BASE& rhs);
		BASE& operator=(const BASE& rhs);

    // move-semantics
		BASE(BASE&& rhs);
		BASE& operator=(BASE&& rhs);

    // operators
    BASE& operator+(const BASE& rhs);

    // other methods
    void printABC(void);
    int getC(void);
};


#include <iostream>
#include <type_traits>

using namespace std;

class BASE
{
	private:
    int *ptrArrElements;
    int numElements;

	public:
    // constructors
		BASE(int count=-1);

    // destructor
    ~BASE();

    // copy-semantics
		BASE(const BASE& rhs);
		BASE& operator=(const BASE& rhs);

    // move-semantics
		BASE(BASE&& rhs);
		BASE& operator=(BASE&& rhs);

    // overloaded-operators
    BASE& operator+=(const BASE& rhs);
    BASE operator+(const BASE& rhs);
    //int& operator[](int idx);
    bool operator==(const BASE& rhs);

    // other methods
    int getElement(int idx);
    int getGrpSize(void);
    void printGrp(void);

		// friend methods
		friend void swapObj(BASE&, BASE&);
};


#include <iostream>
#include <type_traits>
#include <memory>
#include "base.hpp"

using namespace std;

BASE
foo1(void)
{
	cout << "foo1(): call nothing, return by value" << endl;
	return (BASE("anonymous1"));
}

BASE
foo2(void)
{
	cout << "foo2(): call nothing, return by value" << endl;
	return (BASE("anonymous2", 3,5));
}

BASE
foo3(BASE base)
{
	cout << "foo3(): call by Lvalue, return by Lvalue, c = " << base.getC() << endl;
	BASE x(base);
	return (x);
}

int
main (int argc, char *argv[])
{
	// < 0 >
	{
		// Here foo1()'s return value is consumed by tmpBase1. 
		// As a result compiler will create a temporary object before 
  	// returning from foo1(), but it will create the temporary object 
  	// directly in the location of tmpBase1. 
  	// As a result there is no need to destruct the temporary
		// object. This is called RVO.
		cout << endl;
		cout << "< 0 >" << endl;
		BASE tmpBase1 = foo1();
		tmpBase1.printABC();
	}

	// < 1 >
	{
		// Here foo1()'s return value is consumed by ptrBase0. 
		// As a result compiler will create a temporary object before 
  	// returning from foo1(), but it will create the temporary object 
  	// directly in the location pointed to by ptrBase0. 
  	// As a result there is no need to destruct the temporary
		// object. This is called RVO.
		cout << endl;
		cout << "< 1 >" << endl;
		unique_ptr<BASE> ptrBase0(new BASE(foo1()));
		ptrBase0->printABC();
	}

	// < 2 >
	{
		// Here foo2()'s return value is consumed by tmpBase2. 
		// As a result compiler will create a temporary object before 
  	// returning from foo2(), but it will create the temporary object 
  	// directly in the location of tmpBase2. 
  	// As a result there is no need to destruct the temporary
		// object. This is called RVO.
		cout << endl;
		cout << "< 2 >" << endl;
		BASE tmpBase2 = foo2();
		tmpBase2.printABC();
	}

	// < 3 >
	{
		// Here foo3()'s return value is not consumed by anybody.
		// As a result, the temporary object created from the return
		// value of foo3() has to be destroyed. Hence the temporary
		// object's destructor is called.
		cout << endl;
		cout << "< 3 >" << endl;
		BASE tmpBase3("tmpBase3",3,5);
		foo3(tmpBase3);
		cout << "checkpoint #3.1" << endl;
		//	One move is happening here
		//	foo3(tmpBase3) = return (x)
	}

	// < 4 >
	{
		// Here foo3()'s return value is consumed by tmpBase5. 
		// As a result compiler will create a temporary object before 
	  // returning from foo3(), but it will create the temporary object 
	  // directly in the location of tmpBase5. 
	  // As a result there is no need to destruct the temporary
		// object. This is called N-RVO.
		cout << endl;
		cout << "< 4 >" << endl;
		BASE tmpBase4("tmpBase4",3,5);
		BASE tmpBase4_1 = foo3(tmpBase4); // tmpBase4_1 obj will hold
																			// tmpBase4 obj's content
		cout << "checkpoint #4.1" << endl;
		// 	Two Moves are happening here:
		//	1. foo3(tmpBase4) = return (x)
		//	2. tmpBase4_1 = foo3(tmpBase4)
	}
	
	// < 5 >
	{
		cout << endl;
		cout << "< 5 >" << endl;
		BASE tmpBase5("tmpBase6",4,6);
		tmpBase5.printABC();
		BASE&& rRef = move(tmpBase5);
		rRef.printABC();
		tmpBase5.printABC();
	}
	
	// < 6 >
	{
		cout << endl;
		cout << "< 6 >" << endl;
		BASE tmpBase6("tmpBase6",4,6);
		tmpBase6.printABC();
		BASE tmpBase6_1 = move(tmpBase6);
		tmpBase6_1.printABC();
		tmpBase6.printABC();
	}

	cout << endl;
	return (0);
}

#include <iostream>

/*
 *	CONCLUSION
 *	
 *	global 
 *		const					-->	needs to be declared and initialized together and cannot be modified henceforth
 *		static const	-->	needs to be declared and initialized together and cannot be modified henceforth
 *	local 
 *		const					-->	needs to be declared and initialized together and cannot be modified henceforth
 *		static const	-->	needs to be declared and initialized together and cannot be modified henceforth
 *
 *	If "const" is on the left of "*", data is const
 *	If "const" is on the right of "*", pointer is const
 *
 */

using namespace std;

int const global_const_x = 10;
int const * const ptr_global_const_x = &global_const_x;

int static const global_static_const_x = 10;
int static const *ptr_global_static_const_x = &global_static_const_x;

int
main (int argc, char *argv[])
{
	int const local_const_x = 10;
	int const *ptr_local_const_x = &local_const_x;

	int static const local_static_const_x = 10;
	int const *ptr_local_static_const_x = &local_static_const_x;

	int a;

	while (1) {
		cout << "Enter values of a and b" << endl;
		cout << "a : ";
		cin >> a;

		//*ptr_local_const_x = a;
		//*ptr_local_static_const_x = a;
		//*ptr_global_const_x = a;
		//*ptr_global_static_const_x = a;
	
		const_cast<int&>(global_const_x) = a;
	}

	return (0);
}


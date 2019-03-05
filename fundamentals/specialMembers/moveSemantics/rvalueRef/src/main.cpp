#include "resource.hpp"
#include "autoptr.hpp"

using namespace std;

Auto_ptr3<Resource> 
generateResource()
{
	Auto_ptr3<Resource> res(new Resource);
	return res; 
}
 
int main()
{
	Auto_ptr3<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment
 
	return 0;
}

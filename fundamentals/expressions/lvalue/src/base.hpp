#ifndef __BASE_H_
#define __BASE_H_

class BASE
{
	public:
		int a;
		int b;
	public:
		BASE(int _a, int _b) : a(_a), b(_b) {}
		~BASE() {}
		BASE& operator=(const BASE& rhs);

};


#endif // __BASE_H_

using namespace std;

#include <iostream>

class BASE {
	public:
		virtual void whoAmI (void) {
			cout << "I'm BASE class" << endl;
		}
};

class DERIVED : public BASE {
	public:
		virtual void whoAmI (void) {
			cout << "I'm DERIVED class" << endl;
		}
};

class Mother {
	public:
  	virtual void MotherMethod() {}
  	int mother_data;
};

class Father {
	public:
  	virtual void FatherMethod() {}
  	int father_data;
};

class Child : public Mother, public Father {
	public:
  	virtual void ChildMethod() {}
  	int child_data;
};

class BASE1 {
	virtual void f() { cout << "Class::f" << endl; }
	virtual void g() { cout << "Class::g" << endl; }
};


void test1(BASE1 *ptrBASE1) {

	cout << "Address of Object                       : " << (int *)(ptrBASE1) << endl;
	cout << "Address of Object Member storing vPtr   : " << (int*)(ptrBASE1+0) << endl;
	cout << "Value of vPtr for this object           : " << (int *)*(int *)(ptrBASE1+0) << endl;
	cout << "Information about VTable" << endl;
    int *vPtr = NULL;
    vPtr = (int *)*((int *)*(int *)(ptrBASE1 + 0) + 0);
	//cout << "First vTable entry  : " << (int*)*((int*)*(int*)(ptrBASE1+0) + 0) << endl;
	cout << "First vTable entry  : " << vPtr << endl;
	//cout << "Second vTable entry : " << (int*)*(((int*)*(int*)(ptrBASE1+0) + 0) + 1*sizeof(void *)) << endl;
	cout << "Second vTable entry : " << vPtr + 1*sizeof(void *) << endl;
	//cout << "Third vTable entry  : " << (int*)*(((int*)*(int*)(ptrBASE1+0) + 0) + 2*sizeof(void *)) << endl;
	cout << "Third vTable entry  : " << vPtr + 2*sizeof(void *) << endl;
	cout << "Revised " << endl;
	cout << "First vTable entry  : " << *((long *)*(int *)(ptrBASE1) + 0) << endl;
	cout << "Second vTable entry : " << *((long *)*(int *)(ptrBASE1) + 1) << endl;
	cout << "Third vTable entry  : " << *((long *)*(int *)(ptrBASE1) + 2) << endl;
	
	return;
}

int main() {

	BASE1 objClass;
	test1(&objClass);

	Child *ptrChild = NULL;
	ptrChild = new Child();
	ptrChild->mother_data = 0x11223344;
	ptrChild->father_data = 0x55667788;
	ptrChild->child_data = 0xAABBCCDD;

	BASE *ptrBASE = NULL;
	ptrBASE = new DERIVED();

	//DERIVED *ptrDERIVED = NULL;
	//ptrDERIVED = new BASE();

	return 0;
}

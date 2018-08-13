#include <iostream>
#include <memory>
#include "base.hpp"

using namespace std;

typedef shared_ptr<BASE> SPTR_BASE;
typedef weak_ptr<BASE> WPTR_BASE;
typedef unique_ptr<BASE> UPTR_BASE;

int
main (int argc, char *argv[])
{
		// ------------
		// shared_ptr<>
		// ------------
		cout << endl;
    auto ptrBase1 = new BASE(4, "chintu");
    shared_ptr<BASE> sptr1(ptrBase1);
    cout << "Shared Pointer #1 " << sptr1 << endl;
    sptr1->printDetails();

		cout << endl;
    auto ptrBase2 = new BASE(8, "pintu");
    shared_ptr<BASE> sptr2(ptrBase2);
    cout << "Shared Pointer #2 " << sptr2 << endl;
    sptr2->printDetails();

		cout << endl;
		shared_ptr<BASE> sptr3 = sptr2;
		cout << "printing use_count()" << endl;
		cout << "Sptr1->count = " << sptr1.use_count() << endl;
		cout << "Sptr2->count = " << sptr2.use_count() << endl;
		cout << "Sptr3->count = " << sptr3.use_count() << endl;

		cout << endl;
    cout << "Swapping raw pointers" << endl;
    sptr1.swap(sptr2);
    sptr1->printDetails();
    sptr2->printDetails();
		cout << "printing use_count()" << endl;
		cout << "Sptr1->count = " << sptr1.use_count() << endl;
		cout << "Sptr2->count = " << sptr2.use_count() << endl;
		cout << "Sptr3->count = " << sptr3.use_count() << endl;

		// ------------
		// weak_ptr<>
		// ------------
		cout << endl;
		weak_ptr<BASE> wptrA;
		{
			shared_ptr<BASE> sptrA(new BASE(4));
			wptrA = sptrA;
			if (wptrA.expired()) {
				cout << "wptrA expired" << endl;
			}
			wptrA.lock()->printDetails();
			sptrA->printDetails();
			sptrA.reset();
			if (wptrA.expired()) {
				cout << "wptrA expired" << endl;
			}
		}

		// ------------
		// unique_ptr<>
		// ------------
		cout << endl;
		unique_ptr<BASE> uptrA(new BASE(8, "smokey"));
		unique_ptr<BASE> uptrB;
		cout << "uptrA : "; uptrA->printDetails();
		uptrB = move(uptrA);
		if (uptrA) {
			cout << "uptrA : "; uptrA->printDetails();
		}
		if (uptrB) {
			cout << "uptrB : "; uptrB->printDetails();
		}

		cout << endl;
    return (0);
}

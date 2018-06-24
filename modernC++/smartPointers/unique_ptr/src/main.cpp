#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include "base.hpp"

int
main (int argc, char *argv[])
{
    string inputStr;
    int real, img;

    cout << "Enter 'int' for Real part : ";
    cin >> real;
    cout << "Enter 'int' for Img part : ";
    cin >> img;

    BASE A(real, img);   
    A.printContent();

    unique_ptr<BASE> uptrBase1(new BASE(10, 120));
		cout << "uptrBase contains raw-ptr : " << uptrBase1.get() << endl;
		//unique_ptr<BASE> uptrBase1 = make_unique<BASE>(10, 120);
    unique_ptr<BASE> uptrBase2 = move(uptrBase1);
		//unique_ptr<BASE> uptrBase2(new BASE(10, 120));
		cout << "uptrBase contains raw-ptr : " << uptrBase2.get() << endl;

    if (*uptrBase2 == A) {
        cout << "Equal" << endl;
    } else {
        cout << "Unequal" << endl;
    }

    return (0);
}

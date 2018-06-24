using namespace std;

#include <iostream>
#include <string>

int
main (int argc, char *argv[])
{
	string str;
	string::iterator it;
	string::reverse_iterator rit;

	str.assign("deepak subramanian");
	cout << "str : " << str << endl;

	cout << "printing char-by-char : ";
	for (it = str.begin(); it <= str.end(); it++) {
		cout << *it;
	}
	cout << endl;

	cout << "printing reverse char-by-char : ";
	for (rit = str.rbegin(); rit != str.rend(); rit++) {
		cout << *rit;
	}
	cout << endl;

	cout << "inserting a substring" << endl;
	string str_ins("mullingakulu ");
	str.insert(7, str_ins);
	cout << "str : " << str << endl;

	cout << "extracting first name" << endl;
	char fname[16];
	str.copy(fname, 6, 0);
	fname[6] = '\0';
	cout << "first name : " << fname << endl; 

	return (0);
}

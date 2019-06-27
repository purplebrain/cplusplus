#include <iostream>
#include <string>
#include <utility>
#include <map>

using namespace std;

int
main (int argc, char *argv[])
{
	map<string, int> MyMap;

	for (map<string, int>::iterator itr = MyMap.begin(); itr != MyMap.end(); itr++) {
		MyMap.insert(make_pair("bangalore", 10000000));
	}

	cout << "Size of MyMap : " << MyMap.size() << endl;

	return (0);
}

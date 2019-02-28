#include <iostream>
#include <utility>
#include <map>
#include <string>

/*
	< std::map >
	> INSERT 				O(log N), returns a pair<itr, bool>
	> DELETE/ERASE	O(log N)
	>	SEARCH/FIND		O(log N), returns itr to found element or returns end()
	>	MODIFY 				KEY_VALUE of an ELEMENT cannot be modified, VALUE can be modified
	>	TRAVERSAL 		Slower than that of Vector/Deque/Array due to less spatial locality and cache-miss
	>	OPERATOR [] 	Not Implemented (no Random Access)
	> METHOD at()		Not Implemented
	>	Other Features:
		> No Duplicates allowed
*/

using namespace std;

map<string, int> CITY;
typedef map<string, int>::iterator itrCITY;

bool
insertDbElement (string city, int population)
{
	bool retVal = false;

	pair<map<string,int>::iterator,bool> pCity = CITY.insert(pair<string,int>(city, population));
	if (pCity.second == false) {
		cout << "KEY[" << pCity.first->first << "] VALUE[" << pCity.first->second << "] already exists" << endl;
		retVal = false;
	} else {
		cout << "Insert successful" << endl;
		retVal = true;
	}
	
	return retVal; 
}

bool
modifyDbElement (string city, int population)
{
	bool retVal = true;

	itrCITY itr = CITY.find(city);
	if (itr != CITY.end()) {
		cout << "KEY[" << itr->first << "] found, modifying now" << endl;
		CITY[city] = population;
		cout << "Modify successful" << endl;
		retVal = true;
	} else {
		cout << "KEY[" << city << "] not found" << endl;
		cout << "Modify failed" << endl;
		retVal = false;
	}

	return (retVal);
}

itrCITY
findDbElement (string city)
{
	itrCITY itrRet;

	itrRet = CITY.find(city);
	if (itrRet != CITY.end()) {
		cout << "KEY[" << itrRet->first << "] VALUE[" << itrRet->second << "] found"  << endl;
	} else {
		cout << "KEY[" << city << "] not found" << endl;
	}

	return itrRet;
}

bool
deleteDbElement (string city)
{
	bool retVal = false;

	itrCITY itr;
	int numElemErased = CITY.erase(city);
	if (numElemErased) {
		cout << "Delete successful" << endl;
	} else {
		if (CITY.find(city) != CITY.end()) {
			cout << "Delete failed, system error" << endl;
		} else {
			cout << "KEY[" << city << "] not found" << endl;
			cout << "Delete failed" << endl;
		}
	}
	
	return retVal; 
}

int
main (int argc, char *argv[])
{
	char CharUserInput;
	string StrCityName;
	int IntCityPop;
	bool quit = false;

	while (1) {
		cout << "\n" << endl;
		cout << "-------------------------------------------------------------------------\n";
		cout << "Enter one the following:";
		cout << "\nI(INSERT)\nD(DELETE)\nF(FIND)\nM(MODIFY)\nP(PRINT)\nQ(QUIT)" << endl;
		cin >> CharUserInput;
		switch (CharUserInput) {
		case 'I':
			// For MAP there is no push_back() or push_front().
			// For MAP there are no duplicates.
			cout << "Inserting a Map Entry" << endl;
			cout << "Name: ";
			cin >> StrCityName;
			cout << "Population: ";
			cin >> IntCityPop;
			insertDbElement(StrCityName, IntCityPop);
			break;
		case 'D':
			cout << "Deleting a Map Entry" << endl;
			cout << "Name: ";
			cin >> StrCityName;
			deleteDbElement(StrCityName);
			break;
		case 'F':
			cout << "Finding a Map Entry" << endl;
			cout << "Name: ";
			cin >> StrCityName;
			findDbElement(StrCityName);
			break;
		case 'M':
			cout << "Modifying a Map Entry" << endl;
			cout << "Name: ";
			cin >> StrCityName;
			cout << "Population (new): ";
			cin >> IntCityPop;
			modifyDbElement(StrCityName, IntCityPop);
			break;
		case 'P':
			cout << "Printing Map Database" << endl;
			if (CITY.size()) {
				for (itrCITY itr = CITY.begin(); itr != CITY.end(); itr++) {
					cout << "[City, Population] = " << "[" << itr->first << ", " << itr->second << "]" << endl;
				}
			} else {
					cout << "Database is empty" << endl;
			}
			break;
		case 'Q':
			cout << "Quiting" << endl;
			quit = true;
			break;
		default:
			break;
		}
		if (quit == true) {
			break;
		}
	}
	return (0);
}

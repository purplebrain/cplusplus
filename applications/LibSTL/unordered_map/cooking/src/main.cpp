#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int
main(int argc, char *argv[])
{
	unordered_map<string, double> mapItems;
	int inputChoice;
	bool isExit = false;
	string inputIngredient;
	double inputQuantity;
	double inputMaxLF;

	while (1) {
		cout << endl;
		cout << "-------------------" << endl;
		cout << "Enter your choice : " << endl;
		cout << "(0) to exit" << endl;
		cout << "(1) for Inserting new ingredient" << endl;
		cout << "(2) for Deleting an ingredient" << endl;
		cout << "(3) for Stats" << endl;
		cout << "(4) for changing Max Load Factor" << endl;
		cin >> inputChoice;
		switch (inputChoice) {
		case 0:
			{
				cout << "Exiting.." << endl;
				isExit = true;
				break;
			}
		case 1:
			{
				cout << "Ingredient = "; cin >> inputIngredient;
				cout << "Quantity = "; cin >> inputQuantity;
				pair<string, double> pItem(inputIngredient, inputQuantity);
				mapItems.insert(pItem);
				break;
			}
		case 2:
			cout << "Ingredient = "; cin >> inputIngredient;
			if (mapItems.find(inputIngredient) != mapItems.end()) {
				mapItems.erase(inputIngredient);
			} else {
				cout << "Ingredient " << inputIngredient << " not found" << endl;
			}
			break;
		case 3:
			cout << "#### STATS ####" << endl;
			cout << "<CAPACITY>" << endl;
			cout << "\tMax Map size : " << mapItems.max_size() << endl;
			cout << "\tMax Bucket count : " << mapItems.max_bucket_count() << endl;
			cout << "\tMax Load factor: " << mapItems.max_load_factor() << endl;
			cout << "<CURRENT VALUES>" << endl;
			cout << "\tMap size : " << mapItems.size() << endl;
			cout << "\tBucket count : " << mapItems.bucket_count() << endl;
			cout << "\tLoad factor: " << mapItems.max_load_factor() << endl;
			cout << "<BUCKET ITEMS>" << endl;
			for (uint i=0; i < mapItems.bucket_count(); i++) {
					cout << "\tBucket #" << i << endl;
					cout << "\t\tSize : " << mapItems.bucket_size(i) << endl;
					cout << "\t\tElements :";
					for (auto itr = mapItems.begin(i); itr != mapItems.end(i); itr++) {
							cout << "\t (" << itr->first << ", " << itr->second << ")";
					}
					cout << endl;
			}
			break;		
		case 4:
			cout << "Max Load Factor = "; cin >> inputMaxLF;
			mapItems.max_load_factor(inputMaxLF);
			break;
		default:
			{
				cout << "Enter a valid choice" << endl;
				break;
			}
		}
		if (isExit) {
			break;
		}
	}

	cout << endl;
	return (0);
}

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int
main(int argc, char *argv[])
{
	unordered_map<string, double> mapItems;

	{
		cout << "Taking stock of ingredients.." << endl;

		pair<string, double> pEgg("eggs", 6);
		mapItems.insert(pEgg);

		pair<string, double> pMilk("milk", 2.5);
		mapItems.insert(pMilk);

		pair<string, double> pBakPow("baking_powder", 4.0);
		mapItems.insert(pBakPow);

		mapItems.insert({"rum", 2});
		mapItems.insert({"beer", 6});
		mapItems.insert({"banana", 10});
	}

	cout << endl;
	cout << "--- CAPACITY" << endl;
	cout << "Max Map size : " << mapItems.max_size() << endl;
	cout << "Max Bucket count : " << mapItems.max_bucket_count() << endl;
	cout << "Max Load factor: " << mapItems.max_load_factor() << endl;

	mapItems.max_load_factor(5.0);

	cout << endl;
	cout << "--- CURRENT VALUES" << endl;
	cout << "Map size : " << mapItems.size() << endl;
	cout << "Bucket count : " << mapItems.bucket_count() << endl;
	cout << "Load factor: " << mapItems.max_load_factor() << endl;

	cout << endl;
	cout << "< Bucket Summary >" << endl;
	for (uint i=0; i < mapItems.bucket_count(); i++) {
			cout << endl;
			cout << "Bucket #" << i << endl;
			cout << "Size : " << mapItems.bucket_size(i) << endl;
			cout << "Elements :";
			for (auto itr = mapItems.begin(i); itr != mapItems.end(i); itr++) {
					cout << "\t (" << itr->first << ", " << itr->second << ")";
			}
			cout << endl;
	}

	cout << endl;
	return (0);
}

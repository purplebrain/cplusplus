using namespace std;

#include <iostream>
#include <map>
#include <string>

#include "Citizen.hpp"

int
main (int argc, char *argv[])
{
    map<Citizen, string> mapName;
    map<Citizen, string> mapAge;
    map<Citizen, string> mapHeight;
    map<Citizen, string> mapWeight;
    map<Citizen, string> mapCity;
    map<Citizen, string>::iterator it;

    mapName.insert(pair<Citizen, string>(Citizen("eric bana",       38, 180, 200, "london", COMPARE_NAME), "england"));
    mapName.insert(pair<Citizen, string>(Citizen("brad pitt",       48, 172, 185, "los angeles", COMPARE_NAME), "usa"));
    mapName.insert(pair<Citizen, string>(Citizen("hritik roshan",   40, 179, 180, "mumbai", COMPARE_NAME), "india"));
    mapName.insert(pair<Citizen, string>(Citizen("trevor noah",     32, 189, 165, "johannesburg", COMPARE_NAME), "south africa"));
    mapName.insert(pair<Citizen, string>(Citizen("jack ma",         50, 165, 150, "beijing", COMPARE_NAME), "china"));
    cout << "Printing database sorted alphabetically by name" << endl;
    for (it = mapName.begin(); it != mapName.end(); it++) {
        cout << it->first.citizen_name << " from " << it->second << endl;
    }
    cout << endl;

    mapAge.insert(pair<Citizen, string>(Citizen("eric bana",        38, 180, 200, "london", COMPARE_AGE), "england"));
    mapAge.insert(pair<Citizen, string>(Citizen("brad pitt",        48, 172, 185, "los angeles", COMPARE_AGE), "usa"));
    mapAge.insert(pair<Citizen, string>(Citizen("hritik roshan",    40, 179, 180, "mumbai", COMPARE_AGE), "india"));
    mapAge.insert(pair<Citizen, string>(Citizen("trevor noah",      32, 189, 165, "johannesburg", COMPARE_AGE), "south africa"));
    mapAge.insert(pair<Citizen, string>(Citizen("jack ma",          50, 165, 150, "beijing", COMPARE_AGE), "china"));
    cout << "Printing database sorted by age" << endl;
    for (it = mapAge.begin(); it != mapAge.end(); it++) {
        cout << it->first.citizen_name << " from " << it->second << endl;
    }
    cout << endl;

    mapHeight.insert(pair<Citizen, string>(Citizen("eric bana",     38, 180, 200, "london", COMPARE_HEIGHT), "england"));
    mapHeight.insert(pair<Citizen, string>(Citizen("brad pitt",     48, 172, 185, "los angeles", COMPARE_HEIGHT), "usa"));
    mapHeight.insert(pair<Citizen, string>(Citizen("hritik roshan", 40, 179, 180, "mumbai", COMPARE_HEIGHT), "india"));
    mapHeight.insert(pair<Citizen, string>(Citizen("trevor noah",   32, 189, 165, "johannesburg", COMPARE_HEIGHT), "south africa"));
    mapHeight.insert(pair<Citizen, string>(Citizen("jack ma",       50, 165, 150, "beijing", COMPARE_HEIGHT), "china"));
    cout << "Printing database sorted by height" << endl;
    for (it = mapHeight.begin(); it != mapHeight.end(); it++) {
        cout << it->first.citizen_name << " from " << it->second << endl;
    }
    cout << endl;

    mapWeight.insert(pair<Citizen, string>(Citizen("eric bana",     38, 180, 200, "london", COMPARE_WEIGHT), "england"));
    mapWeight.insert(pair<Citizen, string>(Citizen("brad pitt",     48, 172, 185, "los angeles", COMPARE_WEIGHT), "usa"));
    mapWeight.insert(pair<Citizen, string>(Citizen("hritik roshan", 40, 179, 180, "mumbai", COMPARE_WEIGHT), "india"));
    mapWeight.insert(pair<Citizen, string>(Citizen("trevor noah",   32, 189, 165, "johannesburg", COMPARE_WEIGHT), "south africa"));
    mapWeight.insert(pair<Citizen, string>(Citizen("jack ma",       50, 165, 150, "beijing", COMPARE_WEIGHT), "china"));
    cout << "Printing database sorted by weight" << endl;
    for (it = mapWeight.begin(); it != mapWeight.end(); it++) {
        cout << it->first.citizen_name << " from " << it->second << endl;
    }
    cout << endl;

    mapCity.insert(pair<Citizen, string>(Citizen("eric bana",       38, 180, 200, "london", COMPARE_CITY), "england"));
    mapCity.insert(pair<Citizen, string>(Citizen("brad pitt",       48, 172, 185, "los angeles", COMPARE_CITY), "usa"));
    mapCity.insert(pair<Citizen, string>(Citizen("hritik roshan",   40, 179, 180, "mumbai", COMPARE_CITY), "india"));
    mapCity.insert(pair<Citizen, string>(Citizen("trevor noah",     32, 189, 165, "johannesburg", COMPARE_CITY), "south africa"));
    mapCity.insert(pair<Citizen, string>(Citizen("jack ma",         50, 165, 150, "beijing", COMPARE_CITY), "china"));
    cout << "Printing database sorted alphabetically by city" << endl;
    for (it = mapCity.begin(); it != mapCity.end(); it++) {
        cout << it->first.citizen_name << " from " << it->second << endl;
    }
    cout << endl;

    return(0);
}

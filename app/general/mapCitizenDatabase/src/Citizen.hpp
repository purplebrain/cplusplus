#ifndef __CITIZEN_HPP
#define __CITIZEN_HPP

using namespace std;

#include <iostream>
#include <string>

enum CompType_t
{
    COMPARE_NAME=0,
    COMPARE_AGE=1,
    COMPARE_HEIGHT=2,
    COMPARE_WEIGHT=3,
    COMPARE_CITY=4
};

class Citizen
{
    public:
        string citizen_name;
        int citizen_age;
        int citizen_height;
        int citizen_weight;
        string citizen_city;
        CompType_t compare_type;

    public:
        Citizen (string name, 
                 int age, 
                 int height, 
                 int weight, 
                 string city,
                 CompType_t c_type):
                                citizen_name(name),
                                citizen_age(age),
                                citizen_height(height),
                                citizen_weight(height),
                                citizen_city(city),
                                compare_type(c_type)               
        {
        }

        void
        getCitizenName ()
        {
            cout << citizen_name << endl;
            return;
        }

        bool operator< (Citizen citizenObj) const
        {
            switch (this->compare_type) {
                
                case COMPARE_NAME:
                    return (citizen_name.compare(citizenObj.citizen_name));
                    break;

                case COMPARE_AGE:
                    if (citizen_age > citizenObj.citizen_age) {
                        return true;
                    }
                    break;
                
                case COMPARE_HEIGHT:
                    if (citizen_height > citizenObj.citizen_height) {
                        return true;
                    }
                    break;
                
                case COMPARE_WEIGHT:
                    if (citizen_weight > citizenObj.citizen_weight) {
                        return true;
                    }
                    break;
                
                case COMPARE_CITY:
                    return (citizen_city.compare(citizenObj.citizen_city));
                    break;
                
                default:
                    break;
            }

            return false;
        }
};

#endif

#ifndef __PERSON_HPP
#define __PERSON_HPP

#include <iostream>
#include <string>

using namespace std;

class PERSON
{
	public:
		int m_ID;
		PERSON (int id) : m_ID(id) {}
};

class STAFF : public PERSON
{
	public:
		int m_salary;
		STAFF (int id, int salary) : PERSON (id), m_salary(salary) {}
};

class PATIENT : public PERSON
{
	public:
		string m_phone;
		PATIENT (int id , string pNum) : PERSON (id), m_phone(pNum) {}
};

#endif // __PERSON_HPP

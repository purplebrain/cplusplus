#ifndef __HOSPITAL_HPP
#define __HOSPITAL_HPP

#include <iostream>
#include <unordered_map>
#include <vector>

#include "Bst.hpp"
#include "Person.hpp"

using namespace std;

typedef struct TIME_T
{
	public:
		unsigned int m_start;
		unsigned int m_end;
		TIME_T (int start, int end)
		{
			this->m_start = start;
			this->m_end = end;
		}
}TIME;

typedef class BST PERSON_DB;
typedef unordered_map<int,unordered_map<int,vector<TIME>>> VISIT_DB;
typedef unordered_map<int,vector<TIME>> DB_STAFF;

typedef class HOSPITAL_T
{
	public:
		PERSON_DB m_bst;
		VISIT_DB m_visit_db;
		HOSPITAL_T();
		void create_person (int ID, int SALARY);
		void create_person (int ID, string PHONE_NUM);
		void find_person (int ID);
		void add_visit (int PATIENT_ID, int STAFF_ID, unsigned int START, unsigned int END);
    void print_all_members (void);
    void print_member_record (int id);
    void print_member_visit_log (int id);
    void query_visit_log(int patient_id, int staff_id, unsigned int start_time, unsigned int end_time);
} HOSPITAL;

#endif // __HOSPITAL_HPP

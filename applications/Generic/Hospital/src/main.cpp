#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Hospital.hpp"
#include "Bst.hpp"
#include "Person.hpp"

using namespace std;

HOSPITAL hospital;

void
run_tc_query_visit_log (void)
{
	cout << "\n--------------------";
	cout << "\n{ QUERY VISIT LOGS }";
	cout << "\n--------------------";
	ifstream tc_file("TC_QUERY_VISITS.txt", ifstream::in);
	if (!tc_file) {
		cout << "\nError opening file TC_QUERY_VISITS.txt" << endl;
		return;
	}
	int line_num = 0;
	string line;
	while (getline(tc_file, line)) {
		line_num++;
		if (line_num != 1) {
			istringstream iss(line);
			// Read each person (staff/patient) related info
			int patient_id;
			int staff_id;
			unsigned int start_time;
			unsigned int end_time;
			iss >> patient_id;
			iss >> staff_id;
			iss >> start_time;
			iss >> end_time;
			hospital.query_visit_log(patient_id, staff_id, start_time, end_time);
			cout << endl;
		}
	}
}

void
run_tc_print_visit_log (void)
{
	cout << "\n-----------------------";
	cout << "\n{ PRINTING VISIT LOGS }";
	cout << "\n-----------------------";
	ifstream tc_file("TC_PRINT_VISIT_LOG.txt", ifstream::in);
	if (!tc_file) {
		cout << "\nError opening file TC_PRINT_VISIT_LOG.txt" << endl;
		return;
	}
	int line_num = 0;
	string line;
	while (getline(tc_file, line)) {
		line_num++;
		if (line_num != 1) {
			istringstream iss(line);
			// Read each person (staff/patient) related info
			int id;
			iss >> id;
			hospital.print_member_visit_log(id);
			cout << endl;
		}
	}
}

void
run_tc_add_visits (void)
{
	cout << "\n-----------------";
	cout << "\n{ ADDING VISITS }";
	cout << "\n-----------------";
	ifstream tc_file("TC_ADD_VISITS.txt", ifstream::in);
	if (!tc_file) {
		cout << "\nError opening file TC_ADD_VISITS.txt" << endl;
		return;
	}
	string line;
	int line_num = 0;
	while (getline(tc_file, line)) {
		line_num++;
		if (line_num != 1) {
			istringstream iss(line);
			// Read each person (staff/patient) related info
			int patient_id;
			int staff_id;
			unsigned int start_time;;
			unsigned int end_time;;
			iss >> patient_id;
			iss >> staff_id;
			iss >> start_time;
			iss >> end_time;
			cout << "\n\nAdding VISIT #" << (line_num-1);
			cout << "\nPatientID=" << patient_id;
			cout << "\nStaffID=" << staff_id;
			cout << "\nStartTime=" << start_time;
			cout << "\nEndTime=" << end_time;
			hospital.add_visit(patient_id, staff_id, start_time, end_time);
		}
	}
}

void
run_tc_search_people (void)
{
	cout << "\n--------------------";
	cout << "\n{ SEARCHING PEOPLE }";
	cout << "\n--------------------";
	ifstream tc_file("TC_SEARCH_PEOPLE.txt", ifstream::in);
	if (!tc_file) {
		cout << "\nError opening file TC_SEARCH_PEOPLE.txt" << endl;
		return;
	}
	int line_num = 0;
	string line;
	while (getline(tc_file, line)) {
		line_num++;
		if (line_num != 1) {
			istringstream iss(line);
			// Read each person (staff/patient) related info
			int id;
			iss >> id;
			cout << "\nSEARCHING RECORD OF PERSON WITH ID " << id;
			hospital.print_member_record(id);
			cout << endl;
		}
	}
}

void
run_tc_add_people (void)
{
	cout << "\n-----------------";
	cout << "\n{ ADDING PEOPLE }";
	cout << "\n-----------------";
	int numPerson = 0;
	ifstream tc_file("TC_ADD_PEOPLE.txt", ifstream::in);
	if (!tc_file) {
		cout << "\nError opening file TC_ADD_PEOPLE.txt" << endl;
		return;
	}
	int line_num = 0;
	string line;
	while (getline(tc_file, line)) {
		line_num++;
		if (line_num != 1) {
			istringstream iss(line);
			if (line_num == 2) {
				// Read number of persons (staff/patient)
				// to be added
				iss >> numPerson;
				cout << "\nAdding a total of " << numPerson << \
					" people in PersonDb of hospital which is a BST";
			} else {
				// Read each person (staff/patient) related info
				int isStaff;
				int id;
				string str;
				unsigned int salary;
				string phone_num;
				iss >> isStaff;
				iss >> id;
				iss >> str;
				//cout << "\nisStaff" << isStaff << " id=" << id << " str=" << str;
				if (isStaff) {
					// Insert Staff
					salary = stoi(str);
					hospital.create_person(id, salary);
				} else {
					// Insert Patient
					phone_num = str;
					hospital.create_person(id, phone_num);
				}
			}
		}
	}
}

int
main (int argc, char *argv[])
{
	cout << endl;
	run_tc_add_people();

	cout << endl;
	hospital.print_all_members();

	cout << endl;
	run_tc_search_people();

	cout << endl;
	run_tc_add_visits();

	cout << endl;
	run_tc_print_visit_log();

	cout << endl;
	run_tc_query_visit_log();

	cout << endl;
	return (0);
}

#include "Hospital.hpp"

HOSPITAL::HOSPITAL_T()
{
	cout << "\nCreating Hospital";
}

void
HOSPITAL::create_person (int ID, int SALARY)
{
	this->m_bst.insert(ID, SALARY);
}

void
HOSPITAL::create_person (int ID, string PHONE_NUM)
{
	this->m_bst.insert(ID, PHONE_NUM);
}

void
HOSPITAL::find_person (int ID)
{
	this->m_bst.search(ID);
}

void 
HOSPITAL::print_all_members (void)
{
  this->m_bst.print_bst_db();
}

void 
HOSPITAL::print_member_record (int id)
{
  this->m_bst.search(id);
}

void
HOSPITAL::query_visit_log(int PATIENT_ID, int STAFF_ID,
                          unsigned int START, 
                          unsigned int END)
{
  int numVisits = 0;
  cout << "\nNUM OF VISITS for [PATIENT_ID=" << PATIENT_ID << " ,STAFF_ID=" << STAFF_ID << \
          "] between [StartTime= " << START << " ,EndTime= " << END << "] is ";
  auto dbPatient = this->m_visit_db.find(PATIENT_ID);
	if (dbPatient != this->m_visit_db.end()) {
    DB_STAFF dbStaff = dbPatient->second;
    if (dbStaff.find(STAFF_ID) != dbStaff.end()) {
      vector<TIME> visitList = dbStaff[STAFF_ID]; 
      for (auto eachVisit = visitList.begin(); eachVisit != visitList.end(); eachVisit++) {
        if (START <= eachVisit->m_start) {
          if (END >= eachVisit->m_end) {
            numVisits++;
          }
        }
      }
    } else {
        cout << "\nPATIENT_ID=" << PATIENT_ID << " never visited STAFF_ID=" << STAFF_ID;
    }
  } else {
    cout << "\nPATIENT_ID= " << PATIENT_ID << " not found";
  }
  cout << numVisits;
}

void
HOSPITAL::print_member_visit_log (int id)
{
	cout << "\nVISIT LOG FOR PATIENT_ID=" << id;
  auto dbPatient = this->m_visit_db.find(id);
	if (dbPatient != this->m_visit_db.end()) {
    auto dbStaff = dbPatient->second;
    for (auto eachStaff = dbStaff.begin(); eachStaff != dbStaff.end(); eachStaff++) {
      vector<TIME> visitList = eachStaff->second;
      cout << "\nVisited STAFF_ID=" << eachStaff->first << " " << eachStaff->second.size() << " times between : ";
      for (auto eachVisit = visitList.begin(); eachVisit != visitList.end(); eachVisit++) {
        cout << "\n\tStartTime = " << eachVisit->m_start << " EndTime = " << eachVisit->m_end;
      }
    }
  } else {
    cout << "\nPATIENT_ID= " << id << " not found";
  }
}

void
HOSPITAL::add_visit (int PATIENT_ID,
									 	 int STAFF_ID,
										 unsigned int START,
										 unsigned int END) 
{
	TIME time(START,END);
	auto dbPatient = this->m_visit_db.find(PATIENT_ID);
	if (dbPatient != this->m_visit_db.end()) {
		// Patient record found, so we will also have respective
    // visited Staff database or 'dbStaff'
		cout << "\nPatient record found";
		DB_STAFF dbStaff = dbPatient->second;
		if (dbStaff.find(STAFF_ID) != dbStaff.end()) {
			// CASE-1: Visiting an old Staff
		  cout << "\nVisiting an already visited staff member";
			this->m_visit_db[PATIENT_ID][STAFF_ID].push_back(time);
		} else {
			// CASE-2: Visiting a new Staff
		  cout << "\nVisiting a new staff member";
      this->m_visit_db[PATIENT_ID][STAFF_ID] = vector<TIME>(); // initialize with a null-vector
      this->m_visit_db[PATIENT_ID][STAFF_ID].push_back(time);
		}
	} else {
		// Patient record not found, so we have to also create the
    // visited staff database or 'dbStaff'
		cout << "\nPatient record not found, creating a new record";
	  DB_STAFF dbStaff;
    dbStaff[STAFF_ID] = vector<TIME>(); // initialize with a null-vector
    dbStaff[STAFF_ID].push_back(time);
    this->m_visit_db[PATIENT_ID] = dbStaff;
	}
  cout << "\nNum of visits = " << this->m_visit_db[PATIENT_ID][STAFF_ID].size();
}

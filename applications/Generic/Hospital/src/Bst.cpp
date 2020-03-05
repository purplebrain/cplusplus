#include "Bst.hpp"
#include "Person.hpp"

NODE::NODE (int id, int salary)
{
	m_isStaff = true;
	m_ptrLeft = NULL;
	m_ptrRight = NULL;
	m_ptrData = new STAFF(id, salary);
}

NODE::NODE (int id, string pNum)
{
	m_isStaff = false;
	m_ptrLeft = NULL;
	m_ptrRight = NULL;
	m_ptrData = new PATIENT(id, pNum);
}

BST::BST()
{
	this->m_ptrRoot = NULL;
	this->Tsize = 0;
}

void
BST::printRecord (NODE *ptrNode)
{
	if (!ptrNode) {
		cout << "\nNo Record found";
		return;
	}

	if (ptrNode->m_isStaff) {
		cout << "\nRecord Found for STAFF";
		cout << "\nID=" << ptrNode->m_ptrData->m_ID;
		cout << "\nSALARY=" << ((STAFF *)ptrNode->m_ptrData)->m_salary;
	} else {
		cout << "\nRecord Found for PATIENT";
		cout << "\nID=" << ptrNode->m_ptrData->m_ID;
		cout << "\nPHONE_NUM=" << ((PATIENT *)ptrNode->m_ptrData)->m_phone;
	}
}

// insert for STAFF 
void
BST::print_bst_db_helper (NODE *ptrNode)
{
  if (!this->m_ptrRoot) {
    cout << "No nodes in the BST " << endl;
  } 
  if (!ptrNode) {
    return;
  }
  print_bst_db_helper(ptrNode->m_ptrLeft);
  cout << "\nID = " << ptrNode->m_ptrData->m_ID;
  print_bst_db_helper(ptrNode->m_ptrRight);
}

void
BST::print_bst_db (void)
{
	cout << "\n[ CURRRENT DATABASE (BST inorder) ]";
	print_bst_db_helper(this->m_ptrRoot);
}

NODE *
BST::insert_helper (NODE *ptrCurrentNode, NODE *ptrTargetNode)
{
	if (!ptrTargetNode) {
		return (NULL);
	}

	if (!ptrCurrentNode) {
		// Insert node
		if (!this->Tsize) {
			// Insert Root node
			this->m_ptrRoot = ptrTargetNode;
			this->Tsize++;
			return (this->m_ptrRoot);
		} else {
			this->Tsize++;
			return (ptrTargetNode);		
		}
	}
	
	if (ptrTargetNode->m_ptrData->m_ID < ptrCurrentNode->m_ptrData->m_ID) {
		// Traverse Left Child
		ptrCurrentNode->m_ptrLeft = 
				insert_helper(ptrCurrentNode->m_ptrLeft, ptrTargetNode);
	} else if (ptrTargetNode->m_ptrData->m_ID > ptrCurrentNode->m_ptrData->m_ID) {
		// Traverse Right Child
		ptrCurrentNode->m_ptrRight = 
				insert_helper(ptrCurrentNode->m_ptrRight, ptrTargetNode);
	}

  return (ptrCurrentNode);
}

// insert for STAFF 
void
BST::insert (int id, int salary)
{
	NODE *ptrNodeStaff = new NODE(id, salary);
	cout << "\nInserting STAFF with ID=" << id << " SALARY=" << salary;
	insert_helper(this->m_ptrRoot, ptrNodeStaff);
}

// insert for PATIENT
void
BST::insert (int id, string pNum)
{
	NODE *ptrNodePatient = new NODE(id, pNum);
	cout << "\nInserting PATIENT with ID=" << id << " PhoneNum=" << pNum;
	insert_helper(this->m_ptrRoot, ptrNodePatient);
}

NODE *
BST::search_helper (NODE *ptrCurrentNode, int ID)
{
	NODE *ptrNode = NULL;

	if (!ptrCurrentNode) {
		// We may have reached a LeafNode
		return (NULL);
	}

	if (ID == ptrCurrentNode->m_ptrData->m_ID) {
		ptrNode = ptrCurrentNode;
	} else if (ID < ptrCurrentNode->m_ptrData->m_ID) {
		ptrNode = search_helper(ptrCurrentNode->m_ptrLeft, ID);
  } else if (ID > ptrCurrentNode->m_ptrData->m_ID) {
		ptrNode = search_helper(ptrCurrentNode->m_ptrRight, ID);
	}

	return (ptrNode);
}

void
BST::search (int id)
{
	NODE *ptrNode = NULL;
	ptrNode = search_helper(this->m_ptrRoot, id);
	printRecord(ptrNode);
	return;
}

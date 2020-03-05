#ifndef __BST_HPP
#define __BST_HPP

#include <iostream>
#include <string>
#include "Person.hpp"

using namespace std;

class NODE
{	
	public:
		bool m_isStaff;
		NODE *m_ptrLeft;
		NODE *m_ptrRight;
		PERSON *m_ptrData; // base_ptr
		NODE (int id, int salary);  // user-define constructor
		NODE (int id, string pNum); // user-define constructor
		NODE (const NODE &src);
};

class BST
{	private:
		NODE* insert_helper (NODE *ptrCurrentNode, NODE *ptrTargetNode);
		NODE* search_helper (NODE *ptrCurrentNode, int ID);
		void print_bst_db_helper (NODE *ptrNode);
	public:
		NODE *m_ptrRoot;
		int Tsize;
		BST ();
		void insert (int id, int salary); 
		void insert (int id, string phone); 
		void search (int ID); 
		void print_bst_db (void); 
		void printRecord (NODE *ptrNode);
};

#endif // __BST_HPP




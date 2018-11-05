#ifndef __MY_TREE_UTILS_HPP
#define __MY_TREE_UTILS_HPP

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "MyTreeNode.hpp"

using namespace std;

#define INT_MIN 0
#define INT_MAX 101

enum MY_SCAN_TYPE_T
{
    SCAN_NONE = 0,
    SCAN_LEFT = 1,
    SCAN_RIGHT = 2,
    SCAN_LEAF = 3,
    SCAN_MAX = 4
};

// 
//	<CLASS>	MyTreeUtils
//	This class consists of static methods that can be used at utils
//	
class MyTreeUtils
{
	private:
		static bool isBinSearchTree_helper (MyTreeNode *ptrNode, int min, int max);
		static void print_in_order_helper (MyTreeNode *ptrSubRoot);
		static void print_pre_order_helper (MyTreeNode *ptrSubRoot);
		static void print_post_order_helper (MyTreeNode *ptrSubRoot);
		static void print_level (MyTreeNode *ptrSubRoot, int level);
    	static void destroyTree_helper (MyTreeNode *ptrSubRoot);
    	static bool isBalanced_helper (MyTreeNode *ptrSubRoot);
		static void print_tree_boundary_helper (MyTreeNode *ptrSubRoot, MY_SCAN_TYPE_T type);
        static void print_vertical_order_helper (MyTreeNode *ptrNode, int line, int dist);

	public:
    	//  Generic APIs
    	static bool isLeafNode (MyTreeNode *ptrNode);
    	static int getHeight (MyTreeNode *ptrRoot);
        static int sumOfTree (MyTreeNode *ptrNode);
        static int sumOfChildren (MyTreeNode *ptrNode);
        static bool isSumPropertyBinTree (MyTreeNode *ptrRoot);
		static MyTreeNode* getMaxNodeInBst (MyTreeNode *ptrSubRoot);
		static MyTreeNode* getMinNodeInBst (MyTreeNode *ptrSubRoot);

    	//  Tree Destroy & Removal
    	static void destroyTree (MyTreeNode *ptrRoot);

    	//  Balanced Binary Tree
    	static bool isBalanced (MyTreeNode *ptrRoot);

    	//  Complete Binary Tree
		static bool isCompBinTree (MyTreeNode *ptrRoot);

    	//  Binary Search Tree
		static bool isBinSearchTree (MyTreeNode *ptrRoot);

    	//  Tree Traversal APIs
		static void print_in_order (MyTreeNode *ptrRoot);
		static void print_pre_order (MyTreeNode *ptrRoot);
		static void print_post_order (MyTreeNode *ptrRoot);
		static void print_level_order (MyTreeNode *ptrRoot);
    	static void print_tree_boundary (MyTreeNode *ptrRoot);
        static void print_vertical_order (MyTreeNode *ptrRoot);
};

#endif // __MY_TREE_UTILS_HPP

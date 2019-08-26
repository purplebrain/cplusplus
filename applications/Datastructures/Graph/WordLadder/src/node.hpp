#ifndef __NODE_HPP
#define __NODE_HPP

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include "edge.hpp"

using namespace std;

class NODE_T 
{
	public:
		string m_name;
		unordered_map<string, EDGE> m_mapNeighbors;
		bool isVisited;
	public:
		NODE_T (string _name)
		{
			this->m_name = _name;
			this->isVisited = false;
		}

};
typedef class NODE_T NODE;

#endif // __NODE_HPP

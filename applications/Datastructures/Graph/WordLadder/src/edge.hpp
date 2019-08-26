#ifndef __EDGE_HPP
#define __EDGE_HPP

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class EDGE_T 
{
	public:
		string m_dst;
	public:
    EDGE_T (void) {}
		EDGE_T (string _dst) 
		{
			this->m_dst = _dst;
		}
};
typedef class EDGE_T EDGE;

#endif // __EDGE_HPP

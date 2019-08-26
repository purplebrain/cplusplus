#ifndef __GRAPH_HPP
#define __GRAPH_HPP

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include "node.hpp"
#include "edge.hpp"

using namespace std;

class GRAPH_T
{
	public:
		int m_size;
		unordered_map<string, NODE> m_mapVertices;
	public:
		GRAPH_T (void)
		{
			this->m_size = 0;
		}

		unordered_map<string, NODE>::iterator
		find_node (string _strNode)
		{
			return (this->m_mapVertices.find(_strNode));
		}

		void
		insert_node (string _strNode)
		{
			NODE tmpNode(_strNode);
			if (m_mapVertices.find(_strNode) != m_mapVertices.end()) {
				return;
			} else {
        pair<string, NODE> tmpPair(_strNode, tmpNode);
				m_mapVertices.insert(tmpPair);
			}
		}

		void
		insert_edge (string src, string dst)
		{
			unordered_map<string, NODE>::iterator itrSrc = m_mapVertices.find(src);
			unordered_map<string, NODE>::iterator itrDst = m_mapVertices.find(dst);
			if (itrSrc != m_mapVertices.end() &&
					itrDst != m_mapVertices.end()) {
        pair<string, EDGE> tmpPair;
				EDGE tmpEdge;
				tmpEdge.m_dst = dst;
        tmpPair = make_pair(dst,tmpEdge);
				itrSrc->second.m_mapNeighbors.insert(tmpPair);
				tmpEdge.m_dst = src;
        tmpPair = make_pair(src,tmpEdge);
				itrDst->second.m_mapNeighbors.insert(tmpPair);
			}
			return;
		}

    void
    print_graph (void)
    {
      for (auto& itrV : this->m_mapVertices) {
        cout << "\nVertex - " << itrV.second.m_name;
        cout << "\n\tEdges - ";
        for (auto& itrE : itrV.second.m_mapNeighbors) {
          cout << itrE.second.m_dst << " ";
        }
      }
    }
};
typedef class GRAPH_T GRAPH;

#endif // __GRAPH_HPP

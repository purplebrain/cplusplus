#ifndef __MY_GRAPH_HPP
#define __MY_GRAPH_HPP

#include <iostream>
#include <cstddef>
#include <ctime>
#include <string>
#include <unordered_map>
#include "MyGraphNode.hpp"

using namespace std;

//
//  <CLASS> MyGraph
//  This is a template class that implements a Graph.
//
template <class T>
class MyGraph
{
  public:
    string m_name;
    bool m_is_weighted;
    int m_size;
    unordered_map<string, NODE<T> > m_adjList;
  protected:
    int defaultWeight;

  public:
    //
    // Constructor
    //
    MyGraph(string _name="graph", bool _w=false)
    {
      this->m_name = _name;
      this->m_size = 0;
      this->m_is_weighted = _w;
      if (!this->m_is_weighted) {
        defaultWeight = -1;
      } else {
        defaultWeight = 0;
      }
    }
    //
    // Destructor
    //
    ~MyGraph() =default;
    //
    // Methods
    //
    void insert_node (MyGraphNode<T> node);
    void insert_edge (string src, string dst, int weight);
    void print_graph (void);
};

#endif //__MY_GRAPH_HPP

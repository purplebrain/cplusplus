#ifndef __MY_GRAPH_NODE_HPP
#define __MY_GRAPH_NODE_HPP

#include <iostream>
#include <cstddef>
#include <string>
#include <unordered_map>

using namespace std;

// 
//	<CLASS>	MyGraphEdge or EDGE
//  This is a concrete class that implements a graph-edge
//  that will be used to build the graph.
class MyGraphEdge
{
  public:
    string dst;
	  int weight;
};
typedef class MyGraphEdge EDGE;

// 
//	<CLASS>	MyGraphNode or NODE
//	This is a template class that implements a graph-node
//	that will be used to build the graph.
//  The graph could be either Adjacency Matrix or Adjacency List
//
template <class T>
class MyGraphNode
{
    public:
			string name;
    	T data;
    	unordered_map<string, EDGE> mapNeighbor;
    public:
			// Constructor
      MyGraphNode ()
      {
        this->name = "";
      }

    	MyGraphNode (string _name, T _data)
    	{
					this->name = _name;
    	    this->data = _data;
    	}

			// Destructor
			~MyGraphNode() =default;

			// Copy Semantics
			MyGraphNode(const MyGraphNode&) =default;
			MyGraphNode& operator=(const MyGraphNode&) =default;

			// Move Semantics
			MyGraphNode(MyGraphNode&&) =default;
			MyGraphNode& operator=(MyGraphNode&&) =default;
};
template <class T>
using NODE = MyGraphNode<T>; // Alias Template

#endif // __MY_GRAPH_NODE_HPP

#include "MyGraphNode.hpp"
#include "MyGraph.hpp"

using namespace std;

template <class T>
void
MyGraph<T>::insert_node (MyGraphNode<T> node)
{
  if (this->m_adjList.find(node.name) == this->m_adjList.end()) {
    // Graph Node not found in the graph. So insert it.
    this->m_adjList.insert(make_pair(node.name, node));
    this->m_size++;
		cout << "\nLOG : graph-node " << node.name << " inserted";
  } else {
		cout << "\nLOG : graph-node " << node.name << " exists";
		cout << "\nLOG : graph-node insert failure";
  }

  return;
}

template <class T>
void
MyGraph<T>::insert_edge (string src, string dst, int weight) 
{
	cout << "\nLOG : EDGE INSERT src=" << src << " dst=" << dst;
	bool isSrcNodeFound = true;
	bool isDstNodeFound = true;
  typename unordered_map<string, MyGraphNode<T> >::iterator itrSrc, itrDst;

	// Verify the existence of src and dst nodes in the graph
  itrSrc = this->m_adjList.find(src);
	itrDst = this->m_adjList.find(dst);
	if (itrSrc == this->m_adjList.end()) {
		cout << "\nLOG: SrcNode=" << src << " not found";
		isSrcNodeFound = false;;
	}
	if (itrDst == this->m_adjList.end()) {
		cout << "\nLOG: DstNode=" << dst << " not found";
		isDstNodeFound = false;;
	}
	if (!isSrcNodeFound || !isDstNodeFound) {
		cout << "\nLOG : graph-edge insert failure";
		return;
	}

  // Source Node found, go ahead and insert the edge
  unordered_map<string, EDGE>::iterator itrEdge;

	// Updating SrcNode of the edge
  itrEdge = itrSrc->second.mapNeighbor.find(dst);
  if (itrEdge != itrSrc->second.mapNeighbor.end()) {
    // Edge to dest node already found. Update it's weight.
    itrEdge->second.weight = weight; 
		cout << "\nLOG : graph-edge already exists, weight updated";
  } else {
    // Edge not found, it's a new edge. Create one and insert it.
    EDGE edgeTmp;
    edgeTmp.dst = dst;
    edgeTmp.weight = weight;
    itrSrc->second.mapNeighbor.insert(make_pair(dst,edgeTmp));
		cout << "\nLOG : new graph-edge inserted";
  }

	// Updating DstNode of the edge
  itrEdge = itrDst->second.mapNeighbor.find(src);
  if (itrEdge != itrDst->second.mapNeighbor.end()) {
    // Edge to dest node already found. Update it's weight.
    itrEdge->second.weight = weight; 
		cout << "\nLOG : graph-edge already exists, weight updated";
  } else {
    // Edge not found, it's a new edge. Create one and insert it.
    EDGE edgeTmp;
    edgeTmp.dst = src;
    edgeTmp.weight = weight;
    itrDst->second.mapNeighbor.insert(make_pair(src,edgeTmp));
		cout << "\nLOG : new graph-edge inserted";
  }
}

template <class T>
void
MyGraph<T>::print_graph (void)
{
  typename unordered_map<string, MyGraphNode<T> >::iterator itrNode;
	cout << "\n\n------------------------------------";
	cout << "\nGRAPH : " << this->m_name;
	cout << "\nSIZE  : " << this->m_adjList.size();
  for (itrNode = this->m_adjList.begin(); itrNode != this->m_adjList.end(); itrNode++) {
    cout << "\nNODE{" << itrNode->second.name << "}";
    unordered_map<string, EDGE>::iterator itrEdge;
    for (itrEdge = itrNode->second.mapNeighbor.begin(); itrEdge != itrNode->second.mapNeighbor.end(); itrEdge++) {
			if (itrEdge == itrNode->second.mapNeighbor.begin()) {
				cout << "\n    (" << itrNode->second.name << "," 
					<< itrEdge->second.dst << "," << itrEdge->second.weight 
					<< ")";
			} else {
				cout << " | (" << itrNode->second.name << "," 
					<< itrEdge->second.dst << "," << itrEdge->second.weight 
					<< ")";
			}
    }
  }

	cout << endl;

  return;
}

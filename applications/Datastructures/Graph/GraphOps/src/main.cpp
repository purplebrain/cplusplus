#include <iostream>
#include "MyGraphNode.hpp"
#include "MyGraph.hpp"
#include "MyGraph.cpp"

using namespace std;

int
main (int argc, char *argv[])
{
	MyGraph<int> myG("INDIA CITIES", true);
	NODE<int> nodeTmp;
	EDGE tmpEdge;

	nodeTmp.name = "delhi";
	nodeTmp.data = 1;
	myG.insert_node(nodeTmp);

	nodeTmp.name = "mumbai";
	nodeTmp.data = 2;
	myG.insert_node(nodeTmp);

	nodeTmp.name = "kolkata";
	nodeTmp.data = 3;
	myG.insert_node(nodeTmp);

	nodeTmp.name = "chennai";
	nodeTmp.data = 4;
	myG.insert_node(nodeTmp);

	myG.insert_edge("delhi", "mumbai", 1465);
	myG.insert_edge("delhi", "chennai", 2191);
	myG.insert_edge("kolkata", "chennai", 1670);
	myG.insert_edge("mumbai", "chennai", 1347);
	//myG.insert_edge("chennai", "mumbai", 1347);
	myG.print_graph();

	nodeTmp.name = "bangalore";
	nodeTmp.data = 5;
	myG.insert_node(nodeTmp);
	myG.print_graph();

	return (0);
}

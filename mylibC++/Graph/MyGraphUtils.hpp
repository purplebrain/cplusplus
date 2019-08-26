#ifdef __MY_GRAPH_UTILS_HPP
#define __MY_GRAPH_UTILS_HPP

#include "MyGraphNode.hpp"

class MyGraphUtils
{

  public:
    static bool isLoopingNode (MyGraphNode *ptrNode);
    static bool isConnected (MyGraphNode *ptrNode1, MyGraphNode *ptrNode2);
    static void printDFS (MyGraphNode *ptrNode);
    static void printBFS (MyGraphNode *ptrNode);
};



#endif // __MY_GRAPH_UTILS_HPP

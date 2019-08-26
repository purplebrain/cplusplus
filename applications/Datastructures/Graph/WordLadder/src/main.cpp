#include <iostream>
#include <utility>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include "node.hpp"
#include "edge.hpp"
#include "graph.hpp"

using namespace std;

vector<vector<string>> gVecResult;
priority_queue<int, vector<int>, greater<int>> gQResLen;
vector<string> gInputVecWordList;
unsigned int gInputNumWords;
string gInputBeginWord;
string gInputEndWord;

bool
is_diff_one (string strX, string strY)
{
	bool retVal = false;
	unsigned int numDiff = 0;
	for (int i = 0; i < strX.size(); i++) {
		if (strX[i] != strY[i]) {
			numDiff++;
		}
		if (numDiff > 1) {
			return (false);
		}
	}
	if (numDiff == 1) {
		return (true);
	}

	return (retVal);
}

void
bfs (GRAPH graphWords, queue<string> qCurSearch, vector<string> vecCurSolution, string end)
{
	string strCurNode = qCurSearch.front();
	qCurSearch.pop();
	auto curNode = graphWords.m_mapVertices.find(strCurNode);
	for (auto& itr : curNode->second.m_mapNeighbors) {
		auto curNeighbor = graphWords.m_mapVertices.find(itr.second.m_dst);
		if (!curNeighbor->second.isVisited) {
			curNeighbor->second.isVisited = true;
			qCurSearch.push(itr.second.m_dst);
			vecCurSolution.push_back(itr.second.m_dst);
			if (itr.second.m_dst == end) {
				gVecResult.push_back(vecCurSolution);
				gQResLen.push(vecCurSolution.size());
				break;
			} else {
				bfs(graphWords, qCurSearch, vecCurSolution, end);
				qCurSearch.pop();
				vecCurSolution.pop_back();
			}
		}
	}

	return;
}

void
bfs (GRAPH graphWords, string begin, string end)
{
	queue<string> qCurSearch;
	vector<string> vecCurSolution;
	qCurSearch.push(begin);
	vecCurSolution.push_back(begin);
	auto curNode = graphWords.m_mapVertices.find(begin);
	curNode->second.isVisited = true;
	bfs(graphWords, qCurSearch, vecCurSolution, end);
}

bool
findLadders(string beginWord, string endWord) 
{
  bool retVal = true;

	//  BUILD A GRAPH OF GIVEN WORDLIST
	//  Each graph-node will have neighbors as those words that differ by 1 letter.
	//  This graph also has 'beginWord' as one of the graph-nodes.
	cout << "\nLOG : building graph";
	GRAPH graphWords;
	cout << "\nLOG : copying words";
	vector<string> vecWords(gInputVecWordList);
	cout << "\nLOG : pushing beginWord in the list";
	vecWords.push_back(beginWord);

	//	INSERT NODES
	for (int i = 0; i < vecWords.size(); i++) {
		cout << "\nLOG : insert node";
		graphWords.insert_node(vecWords[i]);
	}

	//	INSERT EDGES
	for (int i = 0; i < vecWords.size(); i++) {
		for (auto idx : vecWords) {
			if (is_diff_one(vecWords[i], idx)) {
				// Then 'idx' is a neighbor of wordList[i]
				cout << "\nLOG : insert edge";
				graphWords.insert_edge(vecWords[i], idx);
			}
		}
	}

	//	PRINT GRAPH
	graphWords.print_graph();

  //  SANITY CHECK
  if (graphWords.m_mapVertices.find(endWord) == graphWords.m_mapVertices.end()) {
    return (false);
  }

	//  TRAVERSE THE GRAPH BEGINNING WITH 'beginWord' using BFS
	cout << "\nLOG : doing BFS";
	bfs(graphWords, beginWord, endWord);

  return (retVal);
}

int
main (int argc, char *argv[])
{ 
	while (1) {
		gVecResult.clear();
		gInputVecWordList.clear();
		gQResLen = priority_queue<int, vector<int>, greater<int>>();
		cout << "\n\n==================";
		cout << "\nEnter number of words in word-list : ";
		cin >> gInputNumWords;
		cout << "Enter words in word-list\n";
		string strTmp;
		for (int i = 0; i < gInputNumWords; i++) {
			cout << "Word-" << i << " : ";
			cin >> strTmp;
			gInputVecWordList.push_back(strTmp);
		}
		cout << "Enter beginWord = ";
		cin >> gInputBeginWord;
		cout << "Enter endWord = ";
		cin >> gInputEndWord;

    cout << "\nResult";
    if (findLadders(gInputBeginWord, gInputEndWord)) {
      int shortestLen = gQResLen.top();
      for (auto& itr1 : gVecResult) {
        if (itr1.size() == shortestLen) {
          cout << "\n[ ";
          for (auto itr2 : itr1) {
            cout << itr2 << ", ";
          }
          cout << "]";
        }
      }
    } else {
      cout << "\nNo word ladder";
    }
	}

	return (0);
}


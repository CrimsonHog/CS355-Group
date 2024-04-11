// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the header file that uses the road trip graph (seen as 
// an example in the design document) and determines connectivity with weights 
// between graph nodes.
// ---------------------------------------------------------------------------

// NOTE: I will be implementing an edge class to make an attribute of the node class since I ran into a problem with 
// merging edges and nodes

#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include "GraphNodes.h"
using namespace std;

/*
	* GLOBAL VARIABLES
*/
const int CITY_COUNT = 11;
const int EDGE_COUNT = 12;

class Graph
{
private:
	/*
		* ATTRIBUTES
	*/
	GraphNodes nodes[CITY_COUNT];
	int nodeCount;
	int edgeWeights[EDGE_COUNT];
	bool adjacencyMatrix[CITY_COUNT][CITY_COUNT];
	
public:
	/*
		* CONSTRUCTORS/METHODS
	*/
	Graph(); 
	void SetEdgeWeights(int, bool);
};

#endif

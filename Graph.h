#ifndef _GRAPH_H
#define _GRAPH_H

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the header file that uses the road trip graph (seen as 
// an example in the design document) and determines connectivity with weights 
// between graph nodes.
// ---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "GraphNode.h"
#include "Edge.h"
using namespace std;

/*
	* GLOBAL VARIABLES
*/
const int CITYCOUNT = 11;

class Graph
{
private:
	/*
		* ATTRIBUTES
	*/
	GraphNode nodes[CITYCOUNT];
	
	int nodeCount;
	bool adjacencyMatrix[CITYCOUNT][CITYCOUNT];
	
public:
	/*
		* CONSTRUCTORS/METHODS
	*/
	Graph(); 
	void SetEdgeWeights(string);
	//getters
	GraphNode GetNode(int);
};

#endif

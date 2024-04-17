#ifndef _GRAPH_H
#define _GRAPH_H

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 04/16/24
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
	//Attributes
	GraphNode nodes[CITYCOUNT]; //an array that holds GraphNodes, this is the main storage structure of the program
	bool adjacencyMatrix[CITYCOUNT][CITYCOUNT]; //The matrix that shows connections between nodes
	
public:
	//Constructors
	Graph(); 
	//setters
	void SetEdgeWeights(string); //uses a file to pass in weights for edges
	//getters
	GraphNode GetNode(int); //Returns the node at the index passed in
};

#endif

#ifndef _EDGE_H
#define _EDGE_H

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the header file for the edges of the graph, which will
// be implemented as an attribute of a GraphNode object. This way, each node
// will have an edge attribute that shows what the node's edge is connected to, 
// and it will also store the weights of the nodes.
// ---------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Edge
{
private:
	/*
		* ATTRIBUTES
	*/
	int nodePreviousIndex;
	int nodeConnectionIndex;
	int weight;
	
public:
	/*
		* CONSTRUCTORS/METHODS
	*/
	Edge();
	Edge(int, int, int);
	//setters
	void SetPrevConnectionIndex(int);
	void SetNodeConnectionIndex(int);
	void SetEdgeWeight(int);
	//getters
	int GetPrevConnectionIndex();
	int GetNodeConnectionIndex();
	int GetEdgeWeight();
	
	//operator overloads
	void operator=(const Edge&); // allows for a deep copy of data to be performed
};

#endif

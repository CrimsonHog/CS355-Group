#ifndef _EDGE_CPP
#define _EDGE_CPP

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the cpp file for the edges of the graph that implements
// the Edge constructors, which will be implemented as an attribute of a GraphNode 
// object. This way, each node will have an edge attribute that shows what the node's 
// edge is connected to, and it will also store the weights of the nodes.
// ---------------------------------------------------------------------------

#include <iostream>
#include <limits>
#include "Edge.h"
using namespace std;

/*
Edge Constructors
Purpose: Used when creating an edge to connect nodes.
*/
	/* 
	Edge() - Default constructor of the Edge type. Creates an Edge that will have default values.
	Incoming Data - N/A
	Outgoing data - N/A
	Authors - Lydia Sparks
	Tester(s) - 
	*/ 
	Edge::Edge()
	{
		cout << "The index of the node the edge connects to should always be passed as a parameter, setting to 20." << endl;
		nodeConnectionIndex = 20; // index that goes outside of size of array since edges should be always initialized
		cout << "The index of the previous node should always be passed as a parameter, setting to 19." << endl;
		nodePreviousIndex = 19; // index that goes outside of size of array since edges should be always initialized
		weight = INT_MAX; // assuming the edge has an infinite weight
	}
	
	/* 
	Edge() - parameterized constructor for the index of the node the edge is pointing to and the weight
	Incoming Data - int i, int w: edge is constructed with specified pointing to node index and weight
	Outgoing data - N/A
	Authors - Lydia Sparks
	Tester(s) - 
	*/ 
	Edge::Edge(int prev, int next, int w)
	{
		nodePreviousIndex = prev;
		nodeConnectionIndex = next;
		weight = w;
	}
	
//Setters
	/* 
	void SetPrevConenctionIndex() - gives a value to previous connection index attribute
	Incoming Data - int INdex: The incoming index value (will be assigned from graph.cpp)
	Outgoing data - N/A
	Authors - Kelson Moore
	Tester(s) - 
	*/ 
	void Edge::SetPrevConnectionIndex(int INdex)
	{
		nodePreviousIndex = INdex;
	}
	
	/* 
	void SetNodeConenctionIndex() - gives a value to the connection index attribute
	Incoming Data - int INdex: The incoming index value (will be assigned from graph.cpp)
	Outgoing data - N/A
	Authors - Kelson Moore
	Tester(s) - 
	*/ 
	void Edge::SetNodeConnectionIndex(int INdex)
	{
		nodeConnectionIndex = INdex;
	}
	
	/* 
	void SetEdgeWeight() - gives a value to previous connection index attribute
	Incoming Data - int inWeight: The incoming weight value (will be assigned from graph.cpp)
	Outgoing data - N/A
	Authors - Kelson Moore
	Tester(s) - 
	*/ 
	void Edge::SetEdgeWeight(int inWeight)
	{
		weight = inWeight;
	}
	
//Getters
	/* 
	int GetPrevConenctionIndex() - returns the nodePreviousIndex attribute
	Incoming Data - N/A
	Outgoing data - int nodePreviousIndex: the previous node attribute of the edge class
	Authors - Kelson Moore
	Tester(s) - 
	*/ 
	int Edge::GetPrevConnectionIndex()
	{
		return nodePreviousIndex;
	}
	
	/* 
	int GetConenctionIndex() - returns the nodeConnectionIndex attribute
	Incoming Data - N/A
	Outgoing data - int nodeConnectionIndex: the next connecting node attribute of the edge class
	Authors - Kelson Moore
	Tester(s) - 
	*/ 
	int Edge::GetNodeConnectionIndex()
	{
		return nodeConnectionIndex;
	}
	
	/* 
	int GetEdgeWeight() - returns the weight attribute of the Edge class
	Incoming Data - N/A
	Outgoing data - int weight: the weight attribute
	Authors - Kelson Moore
	Tester(s) - 
	*/ 
	int Edge::GetEdgeWeight()
	{
		return weight;
	}

#endif
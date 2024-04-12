#ifndef _GRAPHNODE_CPP
#define _GRAPHNODE_CPP

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the cpp file that implements the constructors and 
// methods for the nodes of the graph that is used with the shortest path 
// algorithm, using the binary heap as a priority queue.
// ---------------------------------------------------------------------------

#include "GraphNode.h"
#include <limits>
using namespace std;

/*
GraphNode Constructors
Purpose: Used when creating a node for the graph, have made all version of the constructor, some may not be used (Take out later)
*/
	/* 
	GraphNode() - default constructor of the GraphNode type. Creates a GraphNode that will have default values
	Incoming Data - N/A
	Outgoing data - N/A
	Authors - Kelson Moore, Gage Mathis & Lydia Sparks
	Tester(s) - 
	*/ 
	GraphNode::GraphNode()
	{
		index = 0; // sets the index automatically to 0
		name = "Default City"; //default name
		weight = INT_MAX;
		
		// initializing edges to default constructor of Edge object
		edges.resize(1);
	}
	
	/* 
	GraphNode() - parameterized constructor for the index, weight, and city name of the node
	Incoming Data - int inIndex, string inName: node is constructed with specified index and city name
	Outgoing data - N/A
	Authors - Lydia Sparks & Kelson Moore
	Tester(s) - 
	*/ 
	GraphNode::GraphNode(int inIndex, string inName)
	{
		index = inIndex;
		name = inName;
		weight = INT_MAX;
	}

/*
	* SETTERS ARE COMMENTED OUT SINCE NOT NEEDED FOR NOW
*/

/*
GraphNode Setters
Purpose: Changes the attributes stored in the GraphNode class
*/
	/* 
	ChangeWeight(int inWeight) - sets the weight attribute for the unweighted graph
	Incoming Data - int inWeight: the weight of the predicating node in the graph
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	void GraphNode::ChangeWeight(int inWeight)
	{
		this->weight = ++inWeight; //for unweighted the node weight only needs to be one more than the node before it.
	}
	
	/* 
	SetEdge(Edge edge) - sets the edge weight and the index of the node it points to
	Incoming Data - Edge edge: an incoming Edge object will contain an index and weight to 
		be copied over to the node's array of edges
	Outgoing data - N/A
	Authors - Lydia Sparks & Kelson Moore
	Tester(s) - 
	*/ 
	void GraphNode::SetEdge(int edgeIndex, Edge inEdge)
	{
		edges[edgeIndex].SetNodeConnectionIndex(inEdge.GetNodeConnectionIndex());
		edges[edgeIndex].SetPrevConnectionIndex(inEdge.GetPrevConnectionIndex());
		edges[edgeIndex].SetEdgeWeight(inEdge.GetEdgeWeight());
	}

/*
GraphNode Getters
Purpose: Retrieves the attributes stored in the GraphNode class
*/
	/* 
	int GetWeight() - returns the weight attribute
	Incoming Data - N/A
	Outgoing data - int weight: the weight attribute
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	int GraphNode::GetWeight()
	{
		return weight;
	}
	
	/* 
	int GetIndex() - returns the index attribute
	Incoming Data - N/A
	Outgoing data - int index: the index attribute
	Authors - Lydia Sparks
	Tester(s) - 
	*/ 
	int GraphNode::GetIndex()
	{
		return index;
	}
	
	/* 
	string GetName() - returns the name attribute
	Incoming Data - N/A
	Outgoing data - string name: the name attribute
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	string GraphNode::GetName()
	{
		return name;
	}
	
#endif
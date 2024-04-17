#ifndef _GRAPHNODE_CPP
#define _GRAPHNODE_CPP

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the cpp file that implements the constructors and 
// methods for the nodes of the graph that are used with the shortest path 
// algorithm, using the binary heap as a priority queue.
// ---------------------------------------------------------------------------

#include "GraphNode.h"
#include <limits>
using namespace std;

/*
GraphNode Constructors
Purpose: Used when creating a node for the graph, have made all version of the constructor, some may not be used
*/
	/* 
	GraphNode() - default constructor of the GraphNode type. Creates a GraphNode that will have default values
	Incoming Data - N/A
	Outgoing data - N/A
	Authors - Kelson Moore, Gage Mathis, & Lydia Sparks
	Tester(s) - Kelson Moore, Gage Mathis, & Lydia Sparks
	*/ 
	GraphNode::GraphNode()
	{	
//		cout << endl << "Default GraphNode" << endl;
		index = 0; // sets the index automatically to 0
		name = "Default City"; //default name
		weight = INT_MAX;
		
		// initializing edges to default constructor of Edge object
		edges[0] = Edge();
		edgeCount = 0;
		precedingNodeIndex = -1;
	}
	
	/* 
	GraphNode() - parameterized constructor for the index, weight, and city name of the node
	Incoming Data - int inIndex, string inName: node is constructed with specified index and city name
	Outgoing data - N/A
	Authors - Lydia Sparks & Kelson Moore
	Tester(s) - Lydia Sparks & Kelson Moore
	*/ 
	GraphNode::GraphNode(int inIndex, string inName)
	{
//		cout << "Parametered GraphNode" << endl;
		index = inIndex; 
		name = inName;
		weight = INT_MAX;
		
//		cout << "Checking GraphNode Values, should see this message 11 times" << endl;
//		cout << index << endl;
//		cout << name << endl;
//		cout << weight << endl;
		
		// initializing edges to default constructor of Edge object
		edges[0] = Edge();
		edgeCount = 0;
		precedingNodeIndex = -1;
	}

/*
GraphNode Setters
Purpose: Changes the attributes stored in the GraphNode class
*/
	/* 
	ChangeWeight(int inWeight) - sets the weight attribute for the graph
	Incoming Data - int inWeight: the weight of the node in the graph
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - Lydia Sparks, Kelson Moore, & Gage Mathis
	*/ 
	void GraphNode::ChangeWeight(int inWeight)
	{
		weight = inWeight; 
	}
	
	/* 
	SetEdge(Edge edge) - sets the edge weight and the index of the node it points to
	Incoming Data - Edge edge: an incoming Edge object will contain an index and weight to 
		be copied over to the node's array of edges
	Outgoing data - N/A
	Authors - Lydia Sparks & Kelson Moore
	Tester(s) - Lydia Sparks, Kelson Moore, Gage Mathis, & Ethan Rinke
	*/ 
	void GraphNode::SetEdge(int edgeIndex, Edge inEdge)
	{
//		cout << "Entering SetEdge in GraphNode.cpp" << endl;
//		edges[edgeIndex].SetNodeConnectionIndex(inEdge.GetNodeConnectionIndex());
//		edges[edgeIndex].SetPrevConnectionIndex(inEdge.GetPrevConnectionIndex());
//		edges[edgeIndex].SetEdgeWeight(inEdge.GetEdgeWeight());
		edges[edgeIndex] = inEdge;
		
//		cout << "After setting edges[edgeIndex] = inEdge checks" << endl;
//		cout << "Connection: " << edges[edgeIndex].GetNodeConnectionIndex() << endl;
//		cout << "Predecessor: " << edges[edgeIndex].GetPrevConnectionIndex() << endl;
//		cout << "Weight: " << edges[edgeIndex].GetEdgeWeight() << endl;
	}
	
	/*
	SetPrecedingNode()
	Incoming Data - GraphNode preceder: a graphNode being passed in to be stored as the node that comes before this one
	Outgoing data - N/A
	Authors - Kelson Moore
	Tester(s) - Lydia Sparks, Kelson Moore, Gage Mathis, & Ethan Rinke
	*/ 
	void GraphNode::SetPrecedingNodeIndex(int precedingIndex)
	{
		precedingNodeIndex = precedingIndex;
	}

	void GraphNode::SetEdgeCount()
	{
		edgeCount++;
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
	Tester(s) - Lydia Sparks, Kelson Moore, & Gage Mathis
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
	Tester(s) - Lydia Sparks, Kelson Moore, & Gage Mathis
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
	Tester(s) -  Lydia Sparks, Kelson Moore, Ethan Rinke, & Gage Mathis
	*/ 
	string GraphNode::GetName()
	{
		return name;
	}
	
	/* 
	int GetEdgeAmount() - returns the amount of edges the Node has
	Incoming Data - N/A
	Outgoing data - int that corresponds with the size of the array
	Authors - Kelson Moore
	Tester(s) -  Lydia Sparks, Kelson Moore, & Gage Mathis
	*/ 
	int GraphNode::GetEdgeAmount()
	{
		return edgeCount;
	}
	
	/* 
	int CheckNextNode()
	Incoming Data -	int edgeIndex: passing the index of the edge you are wanting to check
	Outgoing data - int: will return the index of the next GraphNode
	Authors - Kelson Moore
	Tester(s) - Lydia Sparks, Kelson Moore, & Gage Mathis
	*/ 
	int GraphNode::CheckNextNode(int edgeIndex)
	{
		Edge connection = edges[edgeIndex]; //setting an edge object to the edge stored in that index of the vector
		return connection.GetNodeConnectionIndex(); //returning the index of the next node in the Graph Object array of nodes
	}
	
	/* 
	int GetEdgeWeight()
	Incoming Data -	int edgeIndex: passing the index of the edge you are wanting to check
	Outgoing data - int: will return the weight of the edge at the index specified
	Authors - Kelson Moore
	Tester(s) - Lydia Sparks, Kelson Moore, & Gage Mathis
	*/ 
	int GraphNode::GetEdgeWeight(int edgeIndex)
	{
		Edge connection = edges[edgeIndex]; //setting an edge object to the edge stored in that index of the vector
		return connection.GetEdgeWeight(); //returning the weight of the edge
	}

	/* 
	int GetPrecedingNodeIndex()
	Incoming Data -	N/A
	Outgoing data - int: returns the index of the preceding node
	Authors - Kelson Moore
	Tester(s) - Lydia Sparks, Kelson Moore, & Gage Mathis
	*/ 
	int GraphNode::GetPrecedingNodeIndex()
	{
		return precedingNodeIndex;
	}
	
	/* 
	operator=() - overloads the assignment operator to perform a deep copy on the GraphNode
		objects
	Incoming Data -	const GraphNode& copyNode: reference to the GraphNode to be copied
	Outgoing data - N/A
	Authors - Lydia Sparks
	Tester(s) - Lydia Sparks, Kelson Moore, & Gage Mathis
	*/ 
	void GraphNode::operator=(const GraphNode& copyNode)
	{
		index = copyNode.index;
		name = copyNode.name;
		weight = copyNode.weight;

		for (int i = 0; i < EDGE_COUNT; i++)
		{
			edges[i] = copyNode.edges[i];
		}
		precedingNodeIndex = copyNode.precedingNodeIndex;
	}

	/* 
	PrintEdge() - uses as a tester function to make sure the edges got initialized correctly
	Incoming Data -	int INdex: the index of the Edge object to be printed
	Outgoing data - N/A
	Authors - Lydia Sparks & Kelson Moore
	Tester(s) - Lydia Sparks, Kelson Moore, & Gage Mathis
	*/ 
	void GraphNode::PrintEdge(int INdex)
	{
		cout << "Prev Connect: " << edges[INdex].GetPrevConnectionIndex() << endl;
		cout << "Next Connect: " << edges[INdex].GetNodeConnectionIndex() << endl;
		cout << "Weight: " << edges[INdex].GetEdgeWeight() << endl;
	}
#endif

#ifndef GRAPHNODES_CPP
#define GRAPHNODES_CPP
#include "GraphNodes.h"
#include <limits>
using namespace std;

/*
GraphNodes Constructors
Purpose: Used when creating a node for the graph, have made all version of the constructor, some may not be used (Take out later)
*/
	/* 
	GraphNodes() - default constructor of the GraphNodes type. Creates a GraphNode that will have default values
	Incoming Data - N/A
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	GraphNodes::GraphNodes()
	{
		weight = INT_MAX; //sets the weight of the node to the maximum
		name = "Default City"; //default name
	}
	/* 
	GraphNodes(int inName) - parametered Constructor (will never need a parametered for weight since weight will always be set to inifinity upon creation)
	Incoming Data - int inName: if there is an incoming name the node will be constructed with that data
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	GraphNodes::GraphNodes(string inName)
	{
		weight = INT_MAX; //sets the weight of the node to the maximum
		name = inName; //sets name to the incoming name parameter
	}
/*
GraphNodes Setters
Purpose: Changes the attributes stored in the GraphNodes class
*/
	/* 
	ChangeWeight(int inWeight) - sets the weight attribute for the unwieghted graph
	Incoming Data - int inWeight: the weight of the predicating node in the graph
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	void GraphNodes::ChangeWeight(int inWeight)
	{
		this->weight = ++inWeight; //for unweighted the node weight only needs to be one more than the node before it.
	}
	/* 
	ChangeWeight() - sets the weight attribute for the weighted graph
	Incoming Data - 
		int inWeight: the weight of the predicating node in the graph
		inEdge: The weight of the edge connecting the nodes in the graph
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	void GraphNodes::ChangeWeight(int inWeight, int inEdge)
	{
		this->weight = (inWeight + inEdge);
	}
	/* 
	ChangeName(string inName) - changes the name attribute of the node
	Incoming Data - int inName: if there is an incoming name the node will be constructed with that data
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	void GraphNodes::ChangeName(string inName)
	{
		this->name = inName;
	}
/*
GraphNodes Getters
Purpose: Retrieves the attributes stored in the GraphNodes class
*/
	/* 
	GetWeight() - returns the weight attribute
	Incoming Data - N/A
	Outgoing data - int weight: the weight attribute
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	int GraphNodes::GetWeight()
	{
		return weight;
	}
	/* 
	string GetName() - returns the name attribute
	Incoming Data - N/A
	Outgoing data - string name: the name attribute
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	string GraphNodes::GetName()
	{
		return name;
	}
#endif

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the implementation file for the GraphNodes class
// used to implement the shortest path algorithm in our road trip project.
// ---------------------------------------------------------------------------
#ifndef GRAPHNODE_CPP
#define GRAPHNODE_CPP
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
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	GraphNode::GraphNode()
	{
		weight = INT_MAX; //sets the weight of the node to the maximum
		city = "Default City"; //default name
		predecessor = nullptr; //sets the predecessor node to null, all will be null until decided otherwise during the finding shortest path algorithm
	}
	
	/* 
	GraphNode(string inCity) - parametered Constructor
	Incoming Data - int inCity: if there is an incoming name the node will be constructed with that data
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	GraphNode::GraphNode(string inCity)
	{
		weight = INT_MAX; //sets the weight of the node to the maximum
		city = inCity; //sets name to the incoming name parameter
	}
	
	/* 
	GraphNode(int inWeight, int inCity) - parametered Constructor: creates the node with the incoming weight and city attributes
	Incoming Data - 
		int inWeight: incoming weight of the node, should only happen for orgin node since its the only node that starts off at anything but inifinity
		string inCity: incoming name of the city
	Outgoing data - N/A
	Authors - Kelson Moore
	Tester(s) - 
	*/ 
	GraphNode::GraphNode(int inWeight, string inCity)
	{
		weight = inWeight; //sets the weight of the node to the maximum
		city = inCity; //sets name to the incoming name parameter
	}
	
/*
GraphNode Setters
Purpose: Changes the attributes stored in the GraphNode class
*/
	/* 
	ChangeWeight(int inWeight) - sets the weight attribute for the unwieghted graph
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
	ChangeWeight() - sets the weight attribute for the weighted graph
	Incoming Data - 
		int inWeight: the weight of the predicating node in the graph
		inEdge: The weight of the edge connecting the nodes in the graph
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	void GraphNode::ChangeWeight(int inWeight, int inEdge)
	{
		this->weight = (inWeight + inEdge);
	}
	
	/* 
	ChangeCity(string inCity) - changes the city attribute of the node
	Incoming Data - string inCity: the incoming name of a city
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	void GraphNode::ChangeCity(string inCity)
	{
		this->city = inCity;
	}
	
	/* 
	ChangePredecessor(string inCity) - changes the predecessor attribute of the node
	Incoming Data - string inPred: the incoming address of a node
	Outgoing data - N/A
	Authors - Kelson Moore
	Tester(s) - 
	*/ 	
	void GraphNode::ChangePredecessor(GraphNode* inPred)
	{
		this->predecessor = inPred; 
		//we are sending in an entire GraphNode, not just a GraphNode*. This should be fine since "predecessor" is set to be a pointer of GraphNode type.
		//So in theory, this still needs testing and maybe a rewrite, only the address of the inPred will be stored in "predecessor".
	}
	
/*
GraphNode Getters
Purpose: Retrieves the attributes stored in the GraphGraphGraphNode class
*/
	/* 
	GetWeight() - returns the weight attribute
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
	string GetName() - returns the name attribute
	Incoming Data - N/A
	Outgoing data - string city: the city name attribute
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	string GraphNode::GetCity()
	{
		return city;
	}
	
	/* 
	GetPredecessor() - returns the predecessor attribute of the node
	Incoming Data - N/A
	Outgoing data - GraphNode* predecessor: The predecesor that holds the address of the node before it
	Authors - Kelson Moore
	Tester(s) - 
	*/ 	
	GraphNode* GraphNode::GetPredecessor()
	{
		return predecessor;
	}
	
	
#endif
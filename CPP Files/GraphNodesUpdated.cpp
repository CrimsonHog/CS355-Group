// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the cpp file that implements the constructors and 
// methods for the nodes of the graph that is used with the shortest path 
// algorithm, using the binary heap as a priority queue.
// ---------------------------------------------------------------------------

#include "GraphNodes.h"
using namespace std;

/*
GraphNodes Constructors
Purpose: Used when creating a node for the graph, have made all version of the constructor, some may not be used (Take out later)
*/
	/* 
	GraphNodes() - default constructor of the GraphNodes type. Creates a GraphNode that will have default values
	Incoming Data - N/A
	Outgoing data - N/A
	Authors - Kelson Moore, Gage Mathis & Lydia Sparks
	Tester(s) - 
	*/ 
	GraphNodes::GraphNodes()
	{
		index = 0; // sets the index automatically to 0
		name = "Default City"; //default name
	}
	
	/* 
	GraphNodes(int inName) - parametered Constructor (will never need a parametered for weight since weight will always be set to inifinity upon creation)
	Incoming Data - int inName: if there is an incoming name the node will be constructed with that data
	Outgoing data - N/A
	Authors - Kelson Moore, Gage Mathis & Lydia Sparks
	Tester(s) - 
	*/ 
	//GraphNodes::GraphNodes(string inName)
	//{
		//weight = INT_MAX; //sets the weight of the node to the maximum
		//index = 0; // sets the index automatically to 0
		//name = inName; //sets name to the incoming name parameter
	//}
	
	/* 
	GraphNodes() - parameterized constructor for the index, weight, and city name of the node
	Incoming Data - int inIndex, int inWeight, string inName: node is constructed with specified index, 
		weight, and city name
	Outgoing data - N/A
	Authors - Lydia Sparks
	Tester(s) - 
	*/ 
	GraphNodes::GraphNodes(int inIndex, string inName)
	{
		index = inIndex;
		name = inName;
	}

/*
	* SETTERS ARE COMMENTED OUT SINCE NOT NEEDED FOR NOW
*/

/*
GraphNodes Setters
Purpose: Changes the attributes stored in the GraphNodes class
*/
	/* 
	ChangeWeight(int inWeight) - sets the weight attribute for the unweighted graph
	Incoming Data - int inWeight: the weight of the predicating node in the graph
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	// void GraphNodes::ChangeWeight(int inWeight)
	// {
	//	 this->weight = ++inWeight; //for unweighted the node weight only needs to be one more than the node before it.
	// }
	/* 
	ChangeWeight() - sets the weight attribute for the weighted graph
	Incoming Data - 
		int inWeight: the weight of the predicating node in the graph
		inEdge: The weight of the edge connecting the nodes in the graph
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	// void GraphNodes::ChangeWeight(int inWeight, int inEdge)
	// {
	// 	this->weight = (inWeight + inEdge);
	// }
	/* 
	ChangeName(string inName) - changes the name attribute of the node
	Incoming Data - int inName: if there is an incoming name the node will be constructed with that data
	Outgoing data - N/A
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	// void GraphNodes::ChangeName(string inName)
	// {
	// 	this->name = inName;
	// }

/*
GraphNodes Getters
Purpose: Retrieves the attributes stored in the GraphNodes class
*/
	/* 
	int GetWeight() - returns the weight attribute
	Incoming Data - N/A
	Outgoing data - int weight: the weight attribute
	Authors - Kelson Moore & Gage Mathis
	Tester(s) - 
	*/ 
	//int GraphNodes::GetWeight()
	//{
	//	return weight;
	//}
	
	/* 
	int GetIndex() - returns the index attribute
	Incoming Data - N/A
	Outgoing data - int index: the index attribute
	Authors - Lydia Sparks
	Tester(s) - 
	*/ 
	int GraphNodes::GetIndex()
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
	string GraphNodes::GetName()
	{
		return name;
	}
	
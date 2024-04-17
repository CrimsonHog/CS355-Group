#ifndef _GRAPHNODE_H
#define _GRAPHNODE_H

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the header file for the nodes of the graph that is 
// used with the shortest path algorithm, using the binary heap as a priority
// queue.
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "Edge.h"
using namespace std;

const int EDGE_COUNT = 10;

//Authors: Lydia Sparks & Kelson Moore

class GraphNode
{
	private:
		/*
			* ATTRIBUTES
		*/
		int index; // holds the index of the node to help visual tracking for programming
		string name; // holds the name of the cities(nodes) for convienience of tracking.
		int weight; //holds the weight (distance from origin) of the node itself
		Edge edges[EDGE_COUNT]; // Vector of edges since nodes may have more than one edge
		int edgeCount; // total number of edges in the array (NOT MAXIMUM, ACTUAL)
		int precedingNodeIndex; //Stores the node that comes before it during the shortest path, makes it easy to backtrack for the shortest path
		
	public:
		/*
			* CONSTRUCTORS/METHODS
		*/
		//Constructors
		GraphNode();
		GraphNode(int, string);
		
		//setters
		void ChangeWeight(int);
		void SetEdge(int, Edge);
		void SetPrecedingNodeIndex(int);
		void SetEdgeCount();
		
		//getters
		int GetIndex(); // gets the index of the current node
		string GetName(); // gets the city name of the current node
		int GetWeight(); // gets the weight of the current node
		int GetEdgeAmount(); // gets the number of edges in the current node
		int CheckNextNode(int); //pass in the index of the next edge in the vector
		int GetEdgeWeight(int); //getting the weight of the edge at the index being passed in
		int GetPrecedingNodeIndex(); //passes back the index storing the preceding node
		void PrintEdge(int); // convenience method that will call all of the getters relating to the edge
		
		// overloaded operators
		void operator=(const GraphNode&); // allows for a deep copy of data to be performed
};

#endif

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

//Authors: Lydia Sparks & Kelson Moore

class GraphNode
{
	private:
		/*
			* ATTRIBUTES
		*/
		int index; // holds the index of the node to help with adjacency matrix
		string name; // holds the name of the cities(nodes) for convienience of tracking.
		int weight; //holds the weight (distance from origin) of the node itself
		vector<Edge> edges; // Vector of edges since nodes may have more than one edge
		
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
		
		//getters
		int GetIndex();
		string GetName();
		int GetWeight();
};

#endif

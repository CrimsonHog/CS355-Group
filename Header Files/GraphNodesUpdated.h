// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the header file for the nodes of the graph that is 
// used with the shortest path algorithm, using the binary heap as a priority
// queue.
// ---------------------------------------------------------------------------

#ifndef _GRAPHNODES_H
#define _GRAPHNODES_H
#include <iostream>
#include <string>
using namespace std;

class GraphNodes
{
	private:
		/*
			* ATTRIBUTES
		*/
		int index; // holds the index of the node to help with adjacency matrix
		string name; // holds the name of the cities(nodes) for convienience of tracking.
		Edge edges[EDGE_COUNT]; // array of edges since nodes may have more than one edge
		
	public:
		/*
			* CONSTRUCTORS/METHODS
		*/
		//Constructors
		GraphNodes(); 
		GraphNodes(string);
		GraphNodes(int, string);
		
		//setters
		//void ChangeWeight(int);
		//void ChangeWeight(int, int);
		//void ChangeName(string);
		void SetEdge(Edge);
		
		//getters
		int GetIndex();
		string GetName();
};

#endif

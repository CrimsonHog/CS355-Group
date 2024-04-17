#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the header file for the Binary Heap data structure 
// used to implement the shortest path algorithm in our road trip project.
// ---------------------------------------------------------------------------

#include "GraphNode.h"
#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <vector>
using namespace std;


//GLOBALS

/*
	* BINARY HEAP CLASS
*/
class BinaryHeap
{

private:
	/*
		* ATTRIBUTES
	*/
	vector<GraphNode> heap;

public:
	/*
		* METHODS
	*/
	//Constructors
	BinaryHeap();
	BinaryHeap(Graph);
	//keeping order in the heap
	void PercolateUp(int index); // used to help with maintaining binary heap ordering property in Insert() and Remove()
	void PercolateDown(int index); // used with BuildHeap()
	//adding to and taking away from the heap
	void Insert(GraphNode newNode); // for inserting into the array
	GraphNode Remove(); // for removing from the array; only removing the root, so the array is the only parameter
	//getters
	int GetSize();
	GraphNode GetNode(int);
};

#endif

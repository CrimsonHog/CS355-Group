// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the header file for the Binary Heap data structure 
// used to implement the shortest path algorithm in our road trip project.
// ---------------------------------------------------------------------------

#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H
#include "GraphNode.h"
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
	void PercolateUp(int index); // used to help with maintaining binary heap ordering property in Insert() and Remove()
	void PercolateDown(int index); // used with BuildHeap()
	void Insert(GraphNode newNode); // for inserting into the array
	GraphNode Remove(GraphNode newNode); // for removing from the array; only removing the root, so the array is the only parameter
	};

#endif

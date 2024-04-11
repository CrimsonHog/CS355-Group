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
	int largestIndex = 0;

public:
	/*
		* METHODS
	*/
	void PercolateUp(GraphNode newNode); // used to help with maintaining binary heap ordering property in Insert() and Remove()
	void PercolateDown(GraphNode newNode); // used with BuildHeap()
	void Insert(GraphNode newNode); // for inserting into the array
	void Remove(GraphNode newNode); // for removing from the array; only removing the root, so the array is the only parameter
	bool BuildHeap(); // sorts the elements of the array into a binary heap
	int ViewMin(); // allows for the root to be viewed
	void PrintBinaryHeap()const; // used for testing that the binary heap was created successfully
};

#endif

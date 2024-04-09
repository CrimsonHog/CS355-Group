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
const int CITY_COUNT = 20; // number of cities in the txt file

/*
	* BINARY HEAP CLASS
*/
class BinaryHeap
{

private:
	/*
		* ATTRIBUTES
	*/
	
public:
	/*
		* METHODS
	*/
	void Insert(string c, int w); // for inserting into the array
	void Remove(int val); // for removing from the array; only removing the root, so the array is the only parameter
	bool FindShortestPath(); // finds the shortest path based upon weights; array has weights in GraphNode objects
	void PercolateUp(int hole); // used to help with maintaining binary heap ordering property in Insert() and Remove()
	void PercolateDown(int hole); // used with BuildHeap()
	bool BuildHeap(); // sorts the elements of the array into a binary heap
	int ViewMin(); // allows for the root to be viewed
	void PrintBinaryHeap()const; // used for testing that the binary heap was created successfully
};

#endif

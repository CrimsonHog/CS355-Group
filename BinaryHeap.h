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
#include <iostream>
using namespace std;

/*
	* NODE CLASS
*/
class Node
{

private:
	/*
		* ATTRIBUTES
	*/
	string city[]; // each city corresponding to txt file
	int weight[]; // each weight corresponding to txt file
	
	/*
		* METHODS
	*/
	Node();
	Node(string c, int w);
	
	friend class BinaryHeap;
};

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
	bool Insert(string c, int w, Node factor[]); // for inserting into the array
	bool Remove(Node factor[]); // for removing from the array; only removing the root, so the array is the only parameter
	bool FindShortestPath(Node factor[]); // finds the shortest path based upon weights; array has weights in Node objects
	bool PercolateUp(Node factor[]); // used to help with maintaining binary heap ordering property in Insert() and Remove()
	bool PercolateDown(Node factor[]); // used with BuildHeap()
	bool BuildHeap(Node factor[]); // sorts the elements of the array into a binary heap
	int ViewMin(Node factor[]); // allows for the root to be viewed
	void PrintBinaryHeap(Node factor[])const; // used for testing that the binary heap was created successfully
};

#endif

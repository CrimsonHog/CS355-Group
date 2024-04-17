#ifndef _BINARYHEAP_CPP
#define _BINARYHEAP_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include "BinaryHeap.h"
using namespace std;

/*
	Function Name: BinaryHeap
	Function Inputs: N/A
	Function Outputs: N/A
	Function Description: Default Constructor for the BinaryHeap, not good to use since we need to initialize the heap with a node from the graph
	Author: Kelson Moore
	Testers: Kelson Moore
*/
BinaryHeap::BinaryHeap()
{
	cout << "Please dont use this constructor, pass in a Graph" << endl;
}

/*
	Function Name: BinaryHeap
	Function Inputs: Graph theGraph: This is the graph that holds all of our data
	Function Outputs: N/A
	Function Description: will intialize the implicit vector of the heap with the origin node of the graph
	Author: Kelson Moore
	Testers: Kelson Moore
*/
BinaryHeap::BinaryHeap(Graph theGraph)
{
//	cout << "Heap parametered constructor" << endl;
	heap.push_back(theGraph.GetNode(0)); //set the index being passed in to whatever the origin node of the graph will be
//	cout << heap.size()<< endl;
}

/*
	Function Name: PercolateUp
	Function Inputs: GraphNode newNode
	Function Outputs: N/A
	Function Description: 
	Author: Ethan Rinke, Gage Mathis, & Kelson Moore
	Testers: Kelson Moore
*/
void BinaryHeap::PercolateUp(int index)
{
//	cout << endl << "Entering PercolateUp in BinaryHeap.cpp" << endl;
//	cout << "Next Node: " << heap[index].GetName() << endl;
//	cout << "Next Node's Weight: " << heap[index].GetWeight() << endl;
//	cout << "Next Node's Edge Count: " << heap[index].GetEdgeAmount() << endl;
//	cout << "Parent Node: " << heap[(index - 1) / 2].GetName() << endl;
//	cout << "Parent Node's Weight: " << heap[(index - 1) / 2].GetWeight() << endl;
//	cout << "Parent Node's Edge Count: " << heap[(index - 1) / 2].GetEdgeAmount() << endl;
//	cout << "root: " << heap[0].GetName() << endl;
//	cout << "root Weight: " << heap[0].GetWeight() << endl << endl;
//
//	cout << "BinaryHeap: Starting Index is: " << index << endl;
//	
	if(heap.size() > 1)
	{
//		cout << "BinaryHeap: Heap has more than one val" << endl;
		while(heap[index].GetWeight() < heap[(index - 1) / 2].GetWeight() ) //&& ((index - 1) / 2) >= 1)
		{
//			cout << "Swap is being made" << endl;
			//swap the newNode and parent
			GraphNode temp = heap[index];
			heap[index] = heap[(index - 1) / 2];
			heap[(index - 1) / 2] = temp;
			//update the index
			index = (index - 1) / 2;
		}
	}
	else
	{
		return;
	}
	
//	cout << "That node was moved to index: " << index << endl;
//	cout << "The root node is: " << heap[0].GetName() << endl;
//	cout << "RootNode edge count is: " << heap[0].GetEdgeAmount() << endl;
//	cout << "After PercolateUp while loop" << endl;
}

/*
	Function Name: PercolateDown
	Function Inputs: GraphNode newNode
	Function Outputs: N/A
	Function Description: 
	Author: Lydia Sparks, Gage Mathis, & Ethan Rinke
	Testers:
*/

void BinaryHeap::PercolateDown(int index)
{
	int leftChildIndex = 2 * index + 1;

	while(leftChildIndex < heap.size())
	{
		int rightChildIndex = 2 * index + 2;
		int minimumIndex = leftChildIndex; // assume minimum child is left child before finding

		if (rightChildIndex < heap.size()) // be sure right child doesn't go beyond bounds of heap
		{
			if (heap[rightChildIndex].GetWeight() < heap[minimumIndex].GetWeight()) // checks if right child is less than current min
			{
				minimumIndex = rightChildIndex;
			}
		}

		if (heap[index].GetWeight() <= heap[minimumIndex].GetWeight())
		{
			return; // minimum heap is good
		}
		else
		{
			GraphNode temp = heap[index];
			heap[index] = heap[minimumIndex];
			heap[minimumIndex] = temp;
			index = minimumIndex;
			leftChildIndex = 2 * index + 1;
		}
	}
}

/*
	Function Name: Insert
	Function Inputs: 
	Function Outputs: N/A
	Function Description: Insert into node array and percolate up to make sure any new node is in the correct position
	Author: Ethan Rinke, Gage Mathis, & Kelson Moore
	Testers: Kelson Moore
*/
void BinaryHeap::Insert(GraphNode newNode)
{
//	cout << endl << "Entering Insert in BinaryHeap.cpp" << endl;
//	cout << "Heap size upon enter: " << heap.size() << endl;
	heap.push_back(newNode);
//	cout << "Heap size after insertion: " << heap.size() << endl;
//	cout << "All the values in the heap are:" << endl;
//	for(int i = 0; i < heap.size(); i++)
//	{
//		cout << heap[i].GetName() << endl;
//		cout << "\tWeight: " << heap[i].GetWeight() << endl;
//		cout << "\tEdge Count: " << heap[i].GetEdgeAmount() << endl;
//	}
//	cout << endl;
	PercolateUp(heap.size() - 1); //we need to do the -1 since the value we just inserted is at the INDEX below the SIZE of the vector
//	cout << "Heap size is now: " << heap.size() << endl;
}

/*
	Funtion Name: Remove
	Function Inputs: GraphNode factor[], int val
	Function Outputs: N/A
	Function Description: Remove the root node from the array and percolate down to make sure the array is in the correct order
	Author: Ethan Rinke, Gage Mathis, & Kelson Moore
	Testers: Kelson MOore
*/
GraphNode BinaryHeap::Remove()
{
	GraphNode minValue = heap[0];
	GraphNode newValue = heap[heap.size() - 1];
//	cout << "Heap size is: " << heap.size() << endl;
	heap.pop_back(); 
//	cout << "After pop size is: " << heap.size() << endl;

	if (heap.size() > 0)
	{
		heap[0] = newValue;
		PercolateDown(0);
	}
	
//	cout << "New min val is: " << heap[0].GetName() << endl;

//	cout << "BinaryHeap.cpp::Remove(): Minvalue edgeCount: " << minValue.GetEdgeAmount() << endl;
	return minValue;
}

int BinaryHeap::GetSize()
{
	return heap.size();
}

GraphNode BinaryHeap::GetNode(int index)
{
	return heap[index];
}
#endif

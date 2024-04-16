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
	Author: Kelson
	Testers:
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
	Author: Kelson
	Testers:
*/
BinaryHeap::BinaryHeap(Graph theGraph)
{
	heap.push_back(theGraph.GetNode(0)); //set the index being passed in to whatever the origin node of the graph will be
}


/*
	Function Name: PercolateUp
	Function Inputs: GraphNode newNode
	Function Outputs: N/A
	Function Description: 
	Author: Ethan / Kelson
	Testers:
*/
void BinaryHeap::PercolateUp(int index)
{
	cout << "Before PercolateUp while loop" << endl;
	cout << heap[index].GetWeight() << endl;
	cout << heap[(index - 1) / 2].GetWeight() << endl;

	while(index > 0 && heap[index].GetWeight() < heap[(index - 1) / 2].GetWeight())
	{
		cout << "Inside PercolateUp while loop" << endl;
		//swap the newNode and parent
		GraphNode temp = heap[index];
		heap[index] = heap[(index - 1) / 2];
		heap[(index - 1) / 2] = temp;
		//update the index
		index = (index - 1) / 2;
	}
	cout << "After PercolateUp while loop" << endl;
};

/*
	Function Name: PercolateDown
	Function Inputs: GraphNode newNode
	Function Outputs: N/A
	Function Description: 
	Author: Ethan / Kelson / Gage
	Testers:
*/
void BinaryHeap::PercolateDown(int index)
{
	int childIndex = 2 * index + 1;
	GraphNode value = heap[index];

	while(childIndex < heap.size())
	{
		GraphNode maxValue = value;
		int maxIndex = -1;
		for(int i = 0; i < 2 && i + childIndex < heap.size(); i++)
		{
			if(heap[i + childIndex].GetWeight() < maxValue.GetWeight())
			{
				maxValue = heap[i + childIndex];
				maxIndex = i + childIndex;
			}
		}

		if (maxValue.GetWeight() == value.GetWeight())
		{
			return;
		}
		else
		{
			GraphNode temp = heap[index];
			heap[index] = heap[maxIndex];
			heap[maxIndex] = temp;
			index = maxIndex;
		}

		childIndex = 2 * index + 1;
	}
}

/*
	Function Name: Insert
	Function Inputs: 
	Function Outputs: N/A
	Function Description: Insert into node array and percolate up to make sure any new node is in the correct position
	Author: Ethan / Kelson
	Testers:
*/
void BinaryHeap::Insert(GraphNode newNode)
{
	cout << "Entering insert" << endl;
	heap.push_back(newNode);
	cout << "push back" << endl;
	PercolateUp(heap.size() - 1);
	cout << "percolate up" << endl;
}

/*
	Funtion Name: Remove
	Function Inputs: GraphNode factor[], int val
	Function Outputs: N/A
	Function Description: Remove the root node from the array and percolate down to make sure the array is in the correct order
	Author: Ethan / Kelson
	Testers: 
*/
GraphNode BinaryHeap::Remove()
{
	GraphNode returnValue = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	PercolateDown(0);
	return returnValue;
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

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
	heap.push_back(theGraph.GetNode(1));
	heap.push_back(theGraph.GetNode(2));
	heap.push_back(theGraph.GetNode(3));
	heap.push_back(theGraph.GetNode(4));
	heap.push_back(theGraph.GetNode(5));
	heap.push_back(theGraph.GetNode(6));
	heap.push_back(theGraph.GetNode(7));
	heap.push_back(theGraph.GetNode(8));
	heap.push_back(theGraph.GetNode(9));
	heap.push_back(theGraph.GetNode(10));
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
	//cout << "Before PercolateUp while loop" << endl;
	cout << "Next Node: " << heap[index].GetName() << endl;
	cout << "Next Node's Weight: " << heap[index].GetWeight() << endl;
	cout << "Parent Node: " << heap[(index - 1) / 2].GetName() << endl;
	cout << "Parent Node's Weight: " << heap[(index - 1) / 2].GetWeight() << endl;
	cout << "Origin: " << heap[0].GetName() << endl;
	cout << "Origin Weight: " << heap[0].GetWeight() << endl << endl;

	while(index > 0)
	{
		//cout << "Inside PercolateUp while loop" << endl;

		if (heap[index].GetWeight() <= heap[(index - 1) / 2].GetWeight())
		{
			//swap the newNode and parent
			GraphNode temp = heap[index];
			heap[index] = heap[(index - 1) / 2];
			heap[(index - 1) / 2] = temp;
			//update the index
			index = (index - 1) / 2;
		}
		else
		{
			return;
		}
	}
	cout << "After PercolateUp while loop" << endl;
}

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
	Author: Ethan / Kelson
	Testers:
*/
void BinaryHeap::Insert(GraphNode newNode)
{
	heap.push_back(newNode);
	PercolateUp(heap.size() - 1);
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
	GraphNode minValue = heap[0];
	GraphNode newValue = heap[heap.size() - 1];
	heap.pop_back();

	if (heap.size() > 0)
	{
		heap[0] = newValue;
		PercolateDown(0);
	}

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

bool BinaryHeap::Empty()
{
	bool empty = false;

	if (heap.size() == 0)
	{
		empty = true;
	}

	return empty;
}

void BinaryHeap::Heapify()
{
	int i = heap.size() / 2 - 1; // calculates parent node index

	while (i >= 0)
	{
		PercolateDown(i);
		i--;
	}

	i = heap.size() - 1;

	while (i > 0)
	{
		// swap heap[0] and heap[i]
		GraphNode temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		PercolateDown(0);
		i--;
	}

	for (int i = 0; i < heap.size(); i++)
	{
		cout << "Name: " << heap[i].GetName() << endl;
		cout << "Weight: " << heap[i].GetWeight() << endl;
	}
}

#endif

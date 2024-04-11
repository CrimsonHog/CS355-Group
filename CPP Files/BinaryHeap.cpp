#ifndef _BINARYHEAP_CPP
#define _BINARYHEAP_CPP
#include <iostream>
#include <fstream>
#include "BinaryHeap.h"
using namespace std;
/*
	Function Name: PercolateUp
	Function Inputs: GraphNode newNode
	Function Outputs: N/A
	Function Description: 
	Author: Ethan / Kelson
	Testers:
*/
void BinaryHeap::PercolateUp(GraphNode newNode)
{
	largestIndex++;
	heap[largestIndex] = newNode;
	int currentIndex = largestIndex;
	while(currentIndex > 0 && heap[currentIndex].weight < heap[(currentIndex - 1) / 2].weight)
	{
		//swap the newNode and parent
		GraphNode temp = heap[currentIndex];
		heap[currentIndex] = heap[(currentIndex - 1) / 2];
		heap[(currentIndex - 1) / 2] = temp;
		//update the index
		currentIndex = (currentIndex - 1) / 2;
	}
};

/*
	Function Name: PercolateDown
	Function Inputs: GraphNode newNode
	Function Outputs: N/A
	Function Description: 
	Author: Ethan / Kelson
	Testers:
*/
void BinaryHeap::PercolateDown(int index)
{
	
}

/*
	Function Name: Insert
	Function Inputs: 
	Function Outputs: N/A
	Function Description: Insert into node array and percolate up to make sure any new node is in the correct position
	Author: Ethan
	Testers:
*/
void BinaryHeap::Insert(GraphNode newNode){
	PercolateUp(newNode);
};

/*
	Funtion Name: Remove
	Function Inputs: GraphNode factor[], int val
	Function Outputs: N/A
	Function Description: Remove the root node from the array and percolate down to make sure the array is in the correct order
	Author: Ethan
	Testers: 
*/
void BinaryHeap::Remove(GraphNode newNode){
	PercolateDown(0);
	largestIndex--;
};

/*
  Funtion Name: PrintBinaryHeap
  Function Inputs: Node factor
  Function Outputs: cout City and corresponding Weight
  Function Description: used for testing that the binary heap was created successfully. prints city alongside corresponding weight. 
  Author: Gage Mathis
  Testers: 
*/
void BinaryHeap::PrintBinaryHeap(Node factor)const {
  for (int i = 0; i < CITY_COUNT; i++) {
    cout << "City: " << factor.city[i] << "has Weight: " << factor.weight[i] << endl ;
  }
}


#endif

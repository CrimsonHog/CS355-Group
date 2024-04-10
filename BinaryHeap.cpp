#ifndef _BINARYHEAP_CPP
#define _BINARYHEAP_CPP
#include <iostream>
#include <fstream>
#include "BinaryHeap.h"
using namespace std;
/*
	Function Name: PercolateUp
	Function Inputs: int hole
	Function Outputs: N/A
	Function Description: 
	Author: Ethan
	Testers:
*/
void BinaryHeap::PercolateUp(GraphNode factor[factorSize], int hole){
	hole = factorSize - 1;
	int parent = hole / 2;
	GraphNode temp = factor[hole];
	
	while (hole > 1 && temp.weight < factor[parent].weight){
		factor[hole] = factor[parent];
		hole = parent;
		parent = hole / 2;
	}
	factor[hole] = temp;
};

/*
	Function Name: PercolateDown
	Function Inputs: GraphNode factor[factorSize], int hole
	Function Outputs: N/A
	Function Description: 
	Author: Ethan
	Testers:
*/
void BinaryHeap::PercolateDown(GraphNode factor[factorSize], int hole){
	int child;
	GraphNode temp = factor[hole];
	
	while (hole * 2 <= factorSize){
		child = hole * 2;
		if (child != factorSize && factor[child + 1].weight < factor[child].weight){
			child++;
		}
		if (factor[child].weight < temp.weight){
			factor[hole] = factor[child];
		}
		else{
			break;
		}
		hole = child;
	}
	factor[hole] = temp;
};

/*
	Function Name: Insert
	Function Inputs: string c, int w, GraphNode factor[]
	Function Outputs: N/A
	Function Description: Insert into node array and percolate up to make sure any new node is in the correct position
	Author: Ethan
	Testers:
*/
void BinaryHeap::Insert(string c, int w, GraphNode factor[]){
	GraphNode temp;
//	temp.city = c;
	temp.ChangeCity(c);
//	temp.weight = w;
	temp.ChangeWeight(w);
	
	PercolateUp(factor, factorSize);
};

/*
	Funtion Name: Remove
	Function Inputs: GraphNode factor[], int val
	Function Outputs: N/A
	Function Description: Remove the root node from the array and percolate down to make sure the array is in the correct order
	Author: Ethan
	Testers: 
*/
void BinaryHeap::Remove(GraphNode factor[], int val){
	GraphNode temp = factor[1];
	factor[1] = factor[factorSize];
	factor[factorSize] = temp;
	
	PercolateDown(factor, factorSize);
};
#endif
#include <iostream>
#include <fstream>
#include "BinaryHeap.h"
using namespace std;

Node::Node()
{
	for (int i = 0; i < CITY_COUNT; i++)
	{
		city[i] = "Default City"; 
		weight[i] = INT_MAX;
	}
}

Node::Node(string c[], int w[]) 
{
	ifstream cityAndWeights;
	cityAndWeights.open("");
	
	for (int i = 0; i < CITY_COUNT; i++) // have cities be half the txt file and corresponding weights be other half 
	{
		if (i <= (CITY_COUNT / 2))
		{
			cityAndWeights >> city[i];
		}
		else 
		{
			cityAndWeights >> weight[i];
		}
	}
	
	cityAndWeights.close();
};

/*
	Function Name: PercolateUp
	Function Inputs: Node factor[factorSize], int hole
	Function Outputs: N/A
	Function Description: 
	Author: Ethan
	Testers:
*/
void BinaryHeap::PercolateUp(Node factor[factorSize], int hole){
	hole = factorSize - 1;
	int parent = hole / 2;
	Node temp = factor[hole];
	
	while (hole > 1 && temp.weight < factor[parent].weight){
		factor[hole] = factor[parent];
		hole = parent;
		parent = hole / 2;
	}
	factor[hole] = temp;
};

/*
	Function Name: PercolateDown
	Function Inputs: Node factor[factorSize], int hole
	Function Outputs: N/A
	Function Description: 
	Author: Ethan
	Testers:
*/
void BinaryHeap::PercolateDown(Node factor[factorSize], int hole){
	int child;
	Node temp = factor[hole];
	
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
	Function Inputs: string c, int w, Node factor[]
	Function Outputs: N/A
	Function Description: Insert into node array and percolate up to make sure any new node is in the correct position
	Author: Ethan
	Testers:
*/
void Insert(string c, int w, Node factor[]){
	Node temp;
	temp.city = c;
	temp.weight = w;
	
	PercolateUp(factor, factorSize);
};

/*
	Funtion Name: Remove
	Function Inputs: Node factor[], int val
	Function Outputs: N/A
	Function Description: Remove the root node from the array and percolate down to make sure the array is in the correct order
	Author: Ethan
	Testers: 
*/
void Remove(Node factor[], int val){
	Node temp = factor[1];
	factor[1] = factor[factorSize];
	factor[factorSize] = temp;
	
	PercolateDown(factor, factorSize);
};
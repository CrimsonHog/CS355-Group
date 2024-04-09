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
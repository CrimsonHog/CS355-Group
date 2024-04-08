#include <iostream>
#include <ifstream>
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
}





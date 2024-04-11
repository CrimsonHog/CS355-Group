#ifndef GRAPHNODES_H
#define GRAPHNODES_H
#include <iostream>
#include <string>
using namespace std;

class GraphNodes
{
	private:
		int weight; //will hold the weight of the pointer when we implement a weighted graph
		string name; //Holds the name of the cities(nodes) for convienience of tracking.
	public:
		//Constructors
		GraphNodes(); 
		GraphNodes(string);
		//setters
		void ChangeWeight(int);
		void ChangeWeight(int, int);
		void ChangeName(string);
		//getters
		int GetWeight();
		string GetName();
};
#endif

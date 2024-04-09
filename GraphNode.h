// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the header file for the GraphNodes class
// used to implement the shortest path algorithm in our road trip project.
// ---------------------------------------------------------------------------
#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <iostream>
#include <string>


using namespace std;

class GraphNode
{
	private:
		int weight; //will hold the weight of the pointer when we implement a weighted graph
		string city; //Holds the name of the cities(nodes) for convienience of tracking.
	public:
		//Constructors
		GraphNode(); 
		GraphNode(string);
		//setters
		void ChangeWeight(int);
		void ChangeWeight(int, int);
		void ChangeCity(string);
		//getters
		int GetWeight();
		string GetCity();
		
	friend class BinaryHeap;
};
#endif
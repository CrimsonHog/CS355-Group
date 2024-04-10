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
		GraphNode* predecessor; //This will hold the address of the preceding node
		string city; //Holds the name of the cities(nodes) for convienience of tracking.
	public:
		//Constructors
		GraphNode(); 
		GraphNode(string);
		GraphNode(int, string);
		//setters
		void ChangeWeight(int); //changes the weight of just a node without an edge;
		void ChangeWeight(int, int); //changes the weight of a node with a weighted edge;
		void ChangeCity(string);
		void ChangePredecessor(GraphNode*); //used to store the preceding city
		//getters
		int GetWeight();
		string GetCity();
		GraphNode* GetPredecessor();
		
		
	friend class BinaryHeap;
};
#endif
// ----------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS-355-02
// Assignment: Project 04
// Date due: 04/16/24
// Description: CONDENSED VERSION OF OUR DESCRIPTION
// ----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstring>
#include "GraphNode.h"
#include "BinaryHeap.h"

using namespace std;

bool FindShortestPath(Graph); //the algorithm that finds the shortest path
int PrintMenu(); //lets the user chose which aspect they want to minimize

int main(){
    //Get the choice from the user on what they want to minimize
	int choice = PrintMenu();

	Graph theGraph; //this is the graph that we will be using to run the entire program
	
	//depending on what the user choses this will load the edges from whichever text file corresponds to the aspect the user chose to minimize
	switch (choice)
	{
		case 1:
			cout << "You have chosen minimize time" << endl;
			theGraph.SetEdgeWeights("TimePath.txt");
			break;
		case 2:
			cout << "You have chosen to minimize cost" << endl;
			theGraph.SetEdgeWeights("CostPath.txt");
			break;
		case 3:
			cout << "You have chosen to minimize distance" << endl;
			theGraph.SetEdgeWeights("DistancePath.txt");
			break;
		case 4:
			cout << "You have chosen to exit" << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
	}
	
	if(choice >= 4 || choice < 1)
	{
		return 0;
	}
	else
	{
		FindShortestPath(theGraph);
	}

    return 0;
}


/*
	Funtion Name: FindShortestPath()
	Function Inputs: BinaryHeap : The root of the Binary Heap;
	Function Outputs: N/A
	Function Description: Find the shortest path from the orgin to the destination using Dijkstra's shortest path algorithm
	Author: Kelson Moore
	Testers: 
*/

bool FindShortestPath(Graph theGraph)
{
	//set the current to orgin
	BinaryHeap theHeap(theGraph);//passing in the graph so that the heap can initialize itself with the origin point of the graph.
	
	//do until you get to destination in a way that has destination < min weight of heap
	//Check and see what the current node can see, add those to the binary heap
	//check adjacency matrix to see if the adjacent node's weight is more than current weight + edge
		//if checked weight is less, call ChangeWeight(weight, edge); edge will be stored in the adjaency matrix
			//if changed store current node as the predecessor to the changed node
		//if not then continue on without making weight changes
	//set current to what the minimum node is (top of the heap)
	
	/*while(end.getWeight > root.getWeight) //where end is the destination & root is the first value in the implicit heap (will implement later)
	{
		
	}*/
	
}

/*
	Funtion Name: PrintMenu
	Function Inputs: N/A
	Function Outputs: int choice: Corresponds to whatever the user decided to minimize
	Function Description: Will output a list of choices to the user, the user will select one
	Author: Kelson Moore
	Testers: 
*/
int PrintMenu()
{
	int choice;
	cout << "What do you want to minimize? " << endl
		 << "\t1. Time" << endl
		 << "\t2. Cost" << endl
		 << "\t3. Distance" << endl
		 << "\t4. Exit" << endl;

	cin >> choice;
}
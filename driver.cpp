// ----------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS-355-02
// Assignment: Project 04
// Date due: 04/16/24
// Description: This file will create a graph made up of graph nodes, each having their own edges. It will then perform Dijkstra's algorithm 
// on this graph to return a shortest path based on your desired factor.
// ----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Graph.h"
#include "Edge.h"
#include "GraphNode.h"
#include "BinaryHeap.h"

using namespace std;

void FindShortestPath(Graph); //the algorithm that finds the shortest path
void PrintMenu(int& choice); //lets the user chose which aspect they want to minimize

//Global Constants
int ORIGIN_INDEX = 0; //the index of your starting node in the Graph Class array
int DESTINATION_INDEX = 10; //the index of your destination node in the Graph Class array

int main(){
    //Get the choice from the user on what they want to minimize
	int choice = 0;
	PrintMenu(choice);

//	cout << endl << "Before Graph Intialization" << endl << endl;
	Graph theGraph; //this is the graph that we will be using to run the entire program
//	cout << endl << endl << "After Graph Initialization" << endl << endl;
	
	//depending on what the user chooses this will load the edges from whichever text file corresponds to the aspect the user chose to minimize
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
	Function Name: FindShortestPath
	Function Inputs: The Graph
	Function Outputs: N/a
	Function Description: Dijkstra's algorithm
	Author: Kelson Moore
	Testers: Kelson Moore, Lydia Sparks, Gage Mathis, Ehtan Rinke. 
*/
void FindShortestPath(Graph theGraph)
{
	BinaryHeap theHeap(theGraph);//passing in the graph so that the heap can initialize itself with the origin point of the graph.
	GraphNode beginningNode = theGraph.GetNode(ORIGIN_INDEX); //start off by setting equal to whatever will be the orgin node
	GraphNode destinationNode = theGraph.GetNode(DESTINATION_INDEX); //pass in the index of whatever your destination node is

	//using GraphNodes and the edges stores in them find the next connected nodes
	//put the next connected nodes into the heap if the sum of currentNode.weight + edgeWeight < ConnectedNode.weight
		//before the node goes into the heap, update the weight of ConnectedNode to be currentNode.weight + edgeWeight.
		//Once that weight is changes update the predecessor Value inside of GraphNode for easy back traversal
	//the heap will perlocate GraphNodes around in the heap until the node with the minimum weight reaches the root
	//Do that for all the edges stored in the GraphNode edge vector
	//Set currentNode to the root of the heap and repeat the process until you get to destinationNode with destinationNode having the smallest weight of the heap
		//Using this as the stop condition for the while loop since once you get to the destination using the shorest path each time you must have found
		// the shorest path to the destination, and any nodes left in the heap would take more distance to get to the destination
	
	GraphNode currentNode = theHeap.Remove();
//	cout << currentNode.GetIndex() << " " << currentNode.GetName() << " " << currentNode.GetWeight() << endl;
	while (currentNode.GetWeight() < destinationNode.GetWeight() && currentNode.GetIndex() != destinationNode.GetIndex())
	{
//		cout << "Driver: Entering Node checking loop." << endl;
		for (int i = 0; i < currentNode.GetEdgeAmount(); i++) //checks for all of the edges in the node
		{
//			cout << "Driver: Entering edge checking loop" << endl;
			GraphNode checkNode = theGraph.GetNode(currentNode.CheckNextNode(i)); //creates a variable that is used to check the next Node against the current Node
			
			//currentNode testers
//			cout << endl << "CurrentNode Data: " << endl;
//			cout << "\tName: " << currentNode.GetName() << endl;
//			cout << "\tIndex: " << currentNode.GetIndex() << endl;
//			cout << "\tWeight: " << currentNode.GetWeight() << endl;
//			cout << "\tNumber of edges: " << currentNode.GetEdgeAmount() << endl;
//			cout << "\tEdge #" << i << " Weight: " << currentNode.GetEdgeWeight(i) << endl;
//			cout << "\tCurrent Node + EdgeWeight: " << (currentNode.GetWeight() + currentNode.GetEdgeWeight(i)) << endl;
//			if(currentNode.GetPrecedingNodeIndex() != -1)
//				cout << "CurrentNode's Predecessor: " << theGraph.GetNode(currentNode.GetPrecedingNodeIndex()).GetName() << endl;

			//CheckNode testers
//			cout << "CheckNode Data: " << endl;
//			cout << "\tName: " << checkNode.GetName() << endl;
//			cout << "\tIndex: " << checkNode.GetIndex() << endl;
//			cout << "\tWeight: " << checkNode.GetWeight() << endl;
//			cout << "\tNumber of edges: " << checkNode.GetEdgeAmount() << endl;
//			cout << "\tEdge #1 Weight: " << checkNode.GetEdgeWeight(0) << endl;
//			cout << "\tWeight: " << checkNode.GetWeight() << endl;
			
//			cout << "!!! " << (currentNode.GetWeight() + currentNode.GetEdgeWeight(i)) << " !!!" << endl;
			if ((checkNode.GetWeight() > (currentNode.GetWeight() + currentNode.GetEdgeWeight(i))) && ((currentNode.GetWeight() + currentNode.GetEdgeWeight(i)) > 0))
			{
//				cout << "Entering if statement" << endl;
				//setting the weight of the checkNode to the weight of currentNode + the connecting edge
				checkNode.ChangeWeight(currentNode.GetWeight() + currentNode.GetEdgeWeight(i));
//				cout << "Next Node's Weight after change: " << checkNode.GetWeight() << endl;
				checkNode.SetPrecedingNodeIndex(currentNode.GetIndex()); //setting the preceding node attribute in GraphNode to the node that changed its weight
//				cout << "Previous Node after change: " << theGraph.GetNode(checkNode.GetPrecedingNodeIndex()).GetName() << endl;
				theHeap.Insert(checkNode); //putting the updated checkNode into the heap
			}
//			cout << "Driver: Exited if statement" << endl;
		}
//		cout << "Driver: Exited for loop" << endl;
//		cout << endl << endl << endl;

		currentNode = theHeap.Remove();
		
//		cout << "After Remove" << endl;
//		cout << endl << "CurrentNode Data: " << endl;
//		cout << "\tName: " << currentNode.GetName() << endl;
//		cout << "\tIndex: " << currentNode.GetIndex() << endl;
//		cout << "\tWeight: " << currentNode.GetWeight() << endl;
//		cout << "\tNumber of edges: " << currentNode.GetEdgeAmount() << endl;
//		cout << "\tEdge #" << i << " Weight: " << currentNode.GetEdgeWeight(i) << endl;
//		cout << "\tCurrent Node + EdgeWeight: " << (currentNode.GetWeight() + currentNode.GetEdgeWeight(i)) << endl;
		
		
//		cout << "Driver: Current Node: " << currentNode.GetName() << endl << endl;
//		cout << "Driver: CurrEdgeCount: " << currentNode.GetEdgeAmount() << endl << endl;
	}
//	cout << "Driver: Exited while loop" << endl;

	cout << "The Shortest Path from " << theGraph.GetNode(0).GetName() << " to " << theGraph.GetNode(10).GetName() << " is:" << endl;
	while (currentNode.GetIndex() != ORIGIN_INDEX)
	{
//		cout << theGraph.GetNode(currentNode.GetIndex()).GetName() << " <--- ";
		cout << "Current Node: " << theGraph.GetNode(currentNode.GetIndex()).GetName() << endl;
		cout << "Preceding Node: " << theGraph.GetNode(currentNode.GetPrecedingNodeIndex()).GetName() << endl;
		currentNode = theGraph.GetNode(currentNode.GetPrecedingNodeIndex());
	}
}

/*
	Funtion Name: PrintMenu
	Function Inputs: N/A
	Function Outputs: int choice: Corresponds to whatever the user decided to minimize + the menu itself
	Function Description: Will output a list of choices to the user, the user will select one
	Author: Kelson Moore
	Testers: Gage Mathis, Ethan Rinke, Lydia Sparks, Kelson Moore
*/
void PrintMenu(int& choice)
{
	cout << "What do you want to minimize? " << endl
		 << "\t1. Time" << endl
		 << "\t2. Cost" << endl
		 << "\t3. Distance" << endl
		 << "\t4. Exit" << endl;

	cin >> choice;
}

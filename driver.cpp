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
#include <vector>
#include "Graph.h"
#include "Edge.h"
#include "GraphNode.h"
#include "BinaryHeap.h"

using namespace std;

void FindShortestPath(Graph); //the algorithm that finds the shortest path
void PrintMenu(int& choice); //lets the user chose which aspect they want to minimize
//void ListShortestPath(Graph); //makes and prints the shortest path list

//Global Constants
int ORIGIN_INDEX = 0; //the index of your starting node in the Graph Class array
int DESTINATION_INDEX = 10; //the index of your destination node in the Graph Class array

int main(){
    //Get the choice from the user on what they want to minimize
	int choice = 0;
	PrintMenu(choice);

	Graph theGraph; //this is the graph that we will be using to run the entire program
	//GraphNode currentNode = theGraph.GetNode(ORIGIN_INDEX); //start off by setting equal to whatever will be the orgin node
	//GraphNode destinationNode = theGraph.GetNode(DESTINATION_INDEX); //pass in the index of whatever your destination node is
	
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
	
	//ListShortestPath(theGraph);
    return 0;
}

void FindShortestPath(Graph theGraph)
{
	BinaryHeap theHeap(theGraph);//passing in the graph so that the heap can initialize itself with the origin point of the graph.
	//theHeap.Heapify();
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
	while (!theHeap.Empty())
	{
		cout << "Entering while loop." << endl;

		GraphNode currentNode = theHeap.Remove();

		if (currentNode.GetIndex() != destinationNode.GetIndex())
		{
			for (int i = 0; i < currentNode.GetEdgeAmount(); i++)
			{
				cout << "Entering for loop" << endl;
				GraphNode checkNode = theGraph.GetNode(currentNode.CheckNextNode(i)); //creates a variable that is used to check the next Node against the current Node

				if (checkNode.GetWeight() > (currentNode.GetWeight() + currentNode.GetEdgeWeight(i)))
				{
					cout << "Entering if statement" << endl;
					//setting the weight of the checkNode to the weight of currentNode + the connecting edge
					checkNode.ChangeWeight(currentNode.GetWeight() + currentNode.GetEdgeWeight(i));
					cout << "Next Node's Weight: " << checkNode.GetWeight() << endl;
					checkNode.SetPrecedingNode(currentNode); //setting the preceding node attribute in GraphNode to the node that changed its weight
					cout << "Previous Node: " << checkNode.GetPrecedingNode().GetName() << endl;
					theHeap.Insert(checkNode); //putting the updated checkNode into the heap
				}

				cout << "Exited if statement" << endl;
			}
		}

		cout << "Exited for loop" << endl;
		cout << "Current Node: " << currentNode.GetName() << endl << endl;
	}

	cout << "Exited while loop" << endl;

	cout << "The Shortest Path from " << theGraph.GetNode(0).GetName() << " to " << theGraph.GetNode(10).GetName() << " is:" << endl;
	while (destinationNode.GetPrecedingNodePtr() != nullptr)
	{
		cout << destinationNode.GetName() << " <--- " << endl;

		destinationNode = destinationNode.GetPrecedingNode();
	}
}

/*
void FindShortestPath(Graph theGraph)
{
	BinaryHeap theHeap(theGraph);//passing in the graph so that the heap can initialize itself with the origin point of the graph.
	theHeap.Heapify();
	GraphNode currentNode = theGraph.GetNode(ORIGIN_INDEX); //start off by setting equal to whatever will be the orgin node
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
	while (currentNode.GetIndex() != destinationNode.GetIndex() && !theHeap.Empty())
	{
		cout << "Entering while loop." << endl;
		for (int i = 0; i < currentNode.GetEdgeAmount(); i++)
		{
			cout << "Entering for loop" << endl;
			GraphNode checkNode = theGraph.GetNode(currentNode.CheckNextNode(i)); //creates a variable that is used to check the next Node against the current Node

			if (checkNode.GetWeight() > (currentNode.GetWeight() + currentNode.GetEdgeWeight(i)))
			{
				cout << "Entering if statement" << endl;
				//setting the weight of the checkNode to the weight of currentNode + the connecting edge
				checkNode.ChangeWeight(currentNode.GetWeight() + currentNode.GetEdgeWeight(i));
				cout << "Next Node's Weight: " << checkNode.GetWeight() << endl;
				checkNode.SetPrecedingNode(currentNode); //setting the preceding node attribute in GraphNode to the node that changed its weight
				cout << "Previous Node: " << checkNode.GetPrecedingNode().GetName() << endl;
				theHeap.Insert(checkNode); //putting the updated checkNode into the heap
			}

			cout << "Exited if statement" << endl;
		}

		cout << "Exited for loop" << endl;
		currentNode = theHeap.Remove(); //setting the current Node to whatever the top of the heap is
		cout << "Current Node: " << currentNode.GetName() << endl << endl;
	}

	cout << "Exited while loop" << endl;

	cout << "The Shortest Path from " << theGraph.GetNode(0).GetName() << " to " << theGraph.GetNode(10).GetName() << " is:" << endl;
	while (destinationNode.GetPrecedingNodePtr() != nullptr)
	{
		cout << destinationNode.GetName() << " <--- " << endl;

		destinationNode = destinationNode.GetPrecedingNode();
	}
}
*/

/*
	Funtion Name: FindShortestPath()
	Function Inputs: BinaryHeap : The root of the Binary Heap
	Function Outputs: N/A
	Function Description: Find the shortest path from the orgin to the destination using Dijkstra's shortest path algorithm
	Author: Kelson Moore
	Testers: 
*/
/*
void FindShortestPath(Graph theGraph)
{
	BinaryHeap theHeap(theGraph);//passing in the graph so that the heap can initialize itself with the origin point of the graph.
	GraphNode currentNode = theGraph.GetNode(ORIGIN_INDEX); //start off by setting equal to whatever will be the orgin node
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
	while(currentNode.GetWeight() < destinationNode.GetWeight())
	{
		cout << "Entering while loop." << endl; 
		for(int i = 0; i < currentNode.GetEdgeAmount(); i++)
		{
			cout << "Entering for loop" << endl;
			GraphNode checkNode = theGraph.GetNode(currentNode.CheckNextNode(i)); //creates a variable that is used to check the next Node against the current Node
			if(checkNode.GetWeight() > (currentNode.GetWeight() + currentNode.GetEdgeWeight(i)))
			{
				cout << "Entering if statement" << endl;
				//setting the weight of the checkNode to the weight of currentNode + the connecting edge
				checkNode.ChangeWeight(currentNode.GetWeight() + currentNode.GetEdgeWeight(i));
				cout << "1" << endl;
				cout << checkNode.GetWeight() << endl;
				checkNode.SetPrecedingNode(currentNode); //setting the preceding node attribute in GraphNode to the node that changed its weight
				cout << "2" << endl;
				theHeap.Insert(checkNode); //putting the updated checkNode into the heap
				cout << "3" << endl;
			}

			cout << "Exited if statement" << endl;
		}

		cout << "Exited for loop" << endl;
		currentNode = theHeap.Remove(); //setting the current Node to whatever the top of the heap is
	}
}
*/

/*
	Funtion Name: PrintMenu
	Function Inputs: N/A
	Function Outputs: int choice: Corresponds to whatever the user decided to minimize
	Function Description: Will output a list of choices to the user, the user will select one
	Author: Kelson Moore
	Testers: 
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

/*
void ListShortestPath(Graph theGraph)
{
	vector<GraphNode> shortestPath;

	
	GraphNode tempNode = theGraph.GetNode(DESTINATION_INDEX);
	//int i = 0;
	while(tempNode.GetPrecedingNodePtr() != nullptr)
	{
		cout << "Entering while loop." << endl;
		//shortestPath[i] = tempNode.GetPrecedingNode();
		//i++;
		shortestPath.push_back(tempNode.GetPrecedingNode());

		tempNode = tempNode.GetPrecedingNode();
	}
	
	cout << "\tShortest Path is: " << endl; 
	cout << "Shortest Path size: " << shortestPath.size() << endl;
    for(int x = shortestPath.size() - 1; x >= 0; x--)
    {
		cout << shortestPath[x].GetName() << endl;
	}
}
*/

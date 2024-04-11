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
//GLOBAL CONST
const int SIZE = 11; //This is the amount of nodes in the graph

//void fileInput(int, string*, int);
void FileInputMatrix(int adjacencyList[SIZE][SIZE]);
void FileInputArray(GraphNode nodeList[SIZE]);
bool FindShortestPath(); // finds the shortest path based upon weights; array has weights in GraphNode objects

int main(){
    // Front end, doesnt have to be anything to complicated
    // This could be where we call and create objects from header files
            // New variables do not all need to be at the top, call them where necessary
            // No need to clutter the reading of the drive
    



    // Call Graph calls - creating and taking 
    //Dummy Graph variables
    
/*   int edgeWeight; 
    string* graphPathway; 
    int graphData;
    fileInput(edgeWeight, graphPathway, graphData);
*/
	GraphNode nodeList[SIZE];
	
	int adjacencyList [SIZE][SIZE];
	
    //Move FindShortestPath here since it uses the Binary Heap, not a part of the Binary heap


    //Create menu
	int choice;
	printMenu(choice);

	// Fix cases once GraphNode is implemented properly
	switch (choice){
		case 1:
			cout << "You have chosen cityInput.txt" << endl;
				FileInputArray(nodeList,"cityInput.txt");
				FileInputMatrix(adjacencyList);
			break;
		case 2:
			cout << "You have chosen graphMatrix.txt" << endl;
				FileInputArray(nodeList,"graphMatrix.txt");
				FileInputMatrix(adjacencyList);
			break;
		case 3:
			cout << "You have chosen to exit" << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
	}


    return 0;
}


// ----------------------------------------------------------
// Function Name: FileInputArray
// Function Type: void 
// Inputs: GraphNode (array) graphNodes;
// output: N/A
// Description: Function calls cityInput.txt and inputs the
//              the names of the cities into the GraphNoded array
// Author: Kelson
// ----------------------------------------------------------
void FileInputArray(GraphNode nodeList[SIZE], string fileName)
{
	ifstream inFile;
    inFile.open(fileName);

	string cityName = "";
	//File input
    if (inFile.is_open())
	{
        while(!inFile.eof()) //goes until the end of the file
		{	
			for(int i = 0; i < SIZE; i++)
			{
				getline(inFile, cityName);
				nodeList[i].ChangeCity(cityName);
			}
        }
        inFile.close();
    }
    /*
    //Check Print for the array
    for(int i = 0; i < SIZE; i++)
	{
		cout << nodeList[i].GetCity() << endl;
	}*/
}


// ----------------------------------------------------------
// Function Name: FileInputMatrix
// Function Type: void 
// Inputs: int (matrix) adjacencyList
// output: N/A
// Description: Function calls graphMatrix.txt and inputs the
//              edge weights into the adjacency matrix
// Author: Kelson
// ----------------------------------------------------------
void FileInputMatrix(int adjacencyList[SIZE][SIZE])
{
	ifstream inFile;
    inFile.open("graphMatrix.txt");

	int edgeWeight;
	//File input
    if (inFile.is_open())
	{
        while(!inFile.eof()) //goes until the end of the file
		{	
			for(int y = 0; y < SIZE; y++)
			{
	        	for(int x = 0; x < SIZE; x++) //goes across the row of int, size must correspond to the file
	        	{
	            	inFile >> edgeWeight;
	        		adjacencyList[x][y] = edgeWeight;
				}
			}
        }
        inFile.close();
    }
    /*
    //Check print for the matrix
    for(int b = 0; b < SIZE; b++)
    {
    	for(int a = 0; a < SIZE; a++)
    	{
    		cout << adjacencyList[a][b] << " ";
		}
		cout << endl;
	}*/
}


/*
	Funtion Name: FindShortestPath()
	Function Inputs: BinaryHeap : The root of the Binary Heap;
	Function Outputs: N/A
	Function Description: Find the shortest path from the orgin to the destination using Dijkstra's shortest path algorithm
	Author: Kelson Moore
	Testers: 
*/
/*
bool FindShortestPath(/*GraphNode root)
{
	//set the current to orgin
	GraphNode current = orgin;
	
	//do until you get to destination in a way that has destination < min weight of heap
	//Check and see what the current node can see, add those to the binary heap
	//check adjacency matrix to see if the adjacent node's weight is more than current weight + edge
		//if checked weight is less, call ChangeWeight(weight, edge); edge will be stored in the adjaency matrix
			//if changed store current node as the predecessor to the changed node
		//if not then continue on without making weight changes
	//set current to what the minimum node is (top of the heap)
	
	while(end.getWeight > root.getWeight) //where end is the destination & root is the first value in the implicit heap (will implement later)
	{
		root
	}
	
}*/	

int printMenu(int choice)
{
	cout << "Which file will you load: " << endl
		 << "\t1. cityInput.txt" << endl
		 << "\t2. graphMatrix.txt" << endl
		 << "\t3. Exit" << endl;

	cin >> choice;

	return choice;
}
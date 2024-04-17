#ifndef _GRAPH_CPP
#define _GRAPH_CPP

// ---------------------------------------------------------------------------
// Name: Gage Mathis, Kelson Moore, Ethan Rinke, Lydia Sparks
// Course-Section: CS355-Section#02
// Assignment: Project 4
// Date due: 
// Description: This is the cpp file that implements the constructors/methods 
// that use the road trip graph (seen as an example in the design document) 
// and determine connectivity with weights between graph nodes.
// ---------------------------------------------------------------------------

#include <iostream>
#include <limits>
#include <fstream>
#include "Graph.h"
using namespace std;

/*
Graph Constructors
Purpose: Used when creating a graph of nodes.
*/
	/* 
	Graph() - Default constructor of the Graph type. Creates a Graph that will have default values.
	Incoming Data - N/A
	Outgoing data - N/A
	Authors - Lydia Sparks & Kelson Moore
	Tester(s) - Kelson Moore
	*/ 
	Graph::Graph()
	{
//		cout << endl << endl << "Entering Default Graph Constructor" << endl << endl;
		// initializing all of the nodes to their city name and corresponding index
//since we have already declared that GraphNodes will be stored in the array, we must explicitly call the parameterd contructor by using the = operator
		nodes[0] = GraphNode(0, "UNA");
//		cout << endl;
		nodes[0].ChangeWeight(0);
//		cout << endl;
		nodes[1] = GraphNode(1, "Huntsville");
//		cout << endl;
		nodes[2] = GraphNode(2, "Starkville");
//		cout << endl;
		nodes[3] = GraphNode(3, "Dothan");
//		cout << endl;
		nodes[4] = GraphNode(4, "Birmingham");
//		cout << endl;
		nodes[5] = GraphNode(5, "Hoover");
//		cout << endl;
		nodes[6] = GraphNode(6, "Helena");
//		cout << endl;
		nodes[7] = GraphNode(7, "Tuscaloosa");
//		cout << endl;
		nodes[8] = GraphNode(8, "Athens");
//		cout << endl;
		nodes[9] = GraphNode(9, "Jasper");
//		cout << endl;
		nodes[10] = GraphNode(10, "Gulf Shores");
//		cout << endl;	
		
	/*	//Testing to see what values are stored in the nodes array after initialization
		for(int i = 0; i < 11; i++)
		{
			cout << "Index of Node " << i << ": " << nodes[i].GetIndex() << endl;
			cout << "Name of Node " << i << ": " << nodes[i].GetName() << endl;
			cout << "Weight of Node " << i << ": " << nodes[i].GetWeight() << endl;
			cout << endl;
		}
	*/
		// initializing all node connections to 0 (0 represents not a connection)
		for (int i = 0; i < CITYCOUNT; i++)
		{
			for (int j = 0; j < CITYCOUNT; j++)
			{
				adjacencyMatrix[i][j] = 0;
			}
		}
		
		// manually specify where adjacencies are located and set them to 1 (1 representes a connection is made)
		adjacencyMatrix[0][1] = 1; // UNA connected to Huntsville
		adjacencyMatrix[0][4] = 1; // UNA connected to Birmingham
		adjacencyMatrix[0][7] = 1; // UNA connected to Tuscaloosa
		adjacencyMatrix[1][2] = 1; // Huntsville connected to Starkville
		adjacencyMatrix[2][3] = 1; // Starkville connected to Dothan
		adjacencyMatrix[3][10] = 1; // Dothan connected to Gulf Shores
		adjacencyMatrix[4][5] = 1; // Birmingham connected to Hoover
		adjacencyMatrix[4][6] = 1; // Birmingham connected to Helena
		adjacencyMatrix[5][10] = 1; // Hoover connected to Gulf Shores
		adjacencyMatrix[6][10] = 1; // Helena connected to Gulf Shores
		adjacencyMatrix[7][8] = 1; // Tuscaloosa connected to Athens
		adjacencyMatrix[8][9] = 1; // Athens connected to Jasper
		adjacencyMatrix[9][10] = 1; // Jasper connected to Gulf Shores
		
		// used for testing to make sure adjacency matrix was created successfully
		// DELETE LATER
/*		for (int i = 0; i < CITYCOUNT; i++)
		{
			for (int j = 0; j < CITYCOUNT; j++)
			{
				cout << adjacencyMatrix[i][j] << " ";
			}
			
			cout << endl;
		}
*/	}
	
/*
Graph Methods
*/
	/* 
	void SetEdgeWeights(bool adjMat[][CITY_COUNT]) - uses adjacency matrix to 
		assign weights from a txt file to each edge 
	Incoming Data - bool adjMat[][CITY_COUNT]: uses connections in graph to assign an edge weight
	Outgoing data - N/A
	Authors - Lydia Sparks & Kelson Moore
	Tester(s) - Kelson Moore
	*/ 
	void Graph::SetEdgeWeights(string fileName)
	{	
//		cout << "Entering SetEdgeWeights in Graph.cpp" << endl;
//		cout << "Using file: " << fileName << endl;
		ifstream inFile;
		inFile.open(fileName);

		if (!inFile.is_open())
		{
			cout << "File could not be opened." << endl;
		}
		
		for (int i = 0; i < CITYCOUNT; i++) //outer loop represents what city the edge is coming from
		{
			int edgeIndex = 0; //This variable will keep track of the index where we need to input the edges in the edge array in the GraphNode
			for (int j = 0; j < CITYCOUNT; j++) //inner loop represents what city the edge is going to
			{
				if (adjacencyMatrix[i][j] == 1) //checks to see if the connection has been labeled true or not
				{
					if (inFile)
					{
//						cout << endl << endl;
//						cout << "row: " << i << endl;
//						cout << "column: " << j << endl;
						
						int weight; 
						inFile >> weight;
//						cout << "weight: " << weight << endl;
						
						Edge tempEdge(i, j, weight); //edge will hold (whereFrom, WhereTo, DistanceBetween) in that order
//						cout << "Edge Weight is: " << tempEdge.GetEdgeWeight() << endl << endl;
						
						nodes[i].SetEdge(edgeIndex, tempEdge);//since the array and matrix are "parallel" keeping track of where from in both works	
						edgeIndex++;
						nodes[i].SetEdgeCount();
//						cout << "Node #" << i << "has " << nodes[i].GetEdgeAmount() << " edges" << endl;
					}
					
				}
			}
//			cout << endl << "Edge Amount of Node " << i << ": " << nodes[i].GetEdgeAmount() << endl;
		}
/*		
		cout << endl << endl << "Checking all edges to make sure they connected correctly" << endl;
		for(int i = 0; i < 11; i++)
		{
			for(int j = 0; j < nodes[i].GetEdgeAmount(); j++)
			{
				cout << "Node: "<< i << " Edge: " << j << endl;
				nodes[i].PrintEdge(j);
				cout << endl;
			}
		}
*/		
		inFile.close();
	}
	
	/* 
	GraphNode GetNode() - returns a single index of the array holding the nodes in the graph
	Incoming Data - int index: The index of the node that is going to be returned
	Outgoing data - GraphNode nodes[index]
	Authors - Kelson Moore
	Tester(s) - 
	*/ 
	GraphNode Graph::GetNode(int index)
	{
		return nodes[index];
	}
	
#endif

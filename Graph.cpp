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
	Tester(s) - 
	*/ 
	Graph::Graph()
	{
		// initializing all of the nodes to their city name and corresponding index
//since we have already declared that GraphNodes will be stored in the array, we must explicitly call the parameterd contructor by using the = operator
		nodes[0] = GraphNode(0, "UNA");
		nodes[0].ChangeWeight(0);
		nodes[1] = GraphNode(1, "Huntsville");
		nodes[2] = GraphNode(2, "Starkville");
		nodes[3] = GraphNode(3, "Dothan");
		nodes[4] = GraphNode(4, "Birmingham");
		nodes[5] = GraphNode(5, "Hoover");
		nodes[6] = GraphNode(6, "Helena");
		nodes[7] = GraphNode(7, "Tuscaloosa");
		nodes[8] = GraphNode(8, "Athens");
		nodes[9] = GraphNode(9, "Jasper");
		nodes[10] = GraphNode(10, "Gulf Shores");	

		nodeCount = CITYCOUNT; // setting number of nodes to number of cities
		
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
		for (int i = 0; i < CITYCOUNT; i++)
		{
			for (int j = 0; j < CITYCOUNT; j++)
			{
				cout << adjacencyMatrix[i][j] << " ";
			}
			
			cout << endl;
		}
	}
	
/*
Graph Methods
*/
	/* 
	void SetEdgeWeights(bool adjMat[][CITY_COUNT]) - uses adjacency matrix to 
		assign weights from a txt file to each edge 
	Incoming Data - bool adjMat[][CITY_COUNT]: uses connections in graph to assign an edge weight
	Outgoing data - N/A
	Authors - Lydia Sparks & Kelson Moore
	Tester(s) - 
	*/ 
	void Graph::SetEdgeWeights(string fileName)
	{	
		ifstream inFile;
		inFile.open(fileName);
		
		for (int i = 0; i < CITYCOUNT; i++) //outer loop represents what city the edge is coming from
		{
			for (int j = 0; j < CITYCOUNT; j++) //inner loop represents what city the edge is going to
			{
				if (adjacencyMatrix[i][j] == 1) //checks to see if the connection has been labeled true or not
				{
					if (inFile)
					{
						int weight; 
						inFile >> weight;
							
						Edge tempEdge(i, j, weight); //edge will hold (whereFrom, WhereTo, DistanceBetween) in that order
							
						nodes[i].SetEdge(i, tempEdge);//since the array and matrix are "parallel" keeping track of where from in both works	
					}
				}
			}
		}
		
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

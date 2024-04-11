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
	Authors - Lydia Sparks
	Tester(s) - 
	*/ 
	Graph::Graph()
	{
		// initializing all of the nodes to their city name and corresponding index
		nodes[0].GraphNodes(0, "UNA");
		nodes[1].GraphNodes(1, "Huntsville");
		nodes[2].GraphNodes(2, "Starkville");
		nodes[3].GraphNodes(3, "Dothan");
		nodes[4].GraphNodes(4, "Birmingham");
		nodes[5].GraphNodes(5, "Hoover");
		nodes[6].GraphNodes(6, "Helena");
		nodes[7].GraphNodes(7, "Tuscaloosa");
		nodes[8].GraphNodes(8, "Athens");
		nodes[9].GraphNodes(9, "Jasper");
		nodes[10].GraphNodes(10, "Gulf Shores");
		
		
		int nodeCount = CITY_COUNT; // setting number of nodes to number of cities
		
		// initializing all node connections to 0
		for (int i = 0; i < CITYCOUNT; i++)
		{
			for (int j = 0; j < CITYCOUNT; j++)
			{
				adjacencyMatrix[i][j] = 0;
			}
		}
		
		// manually specify where adjacencies are located and set them to 1
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
	Authors - Lydia Sparks
	Tester(s) - 
	*/ 
	void Graph::SetEdgeWeights(bool adjMat[][CITY_COUNT], ifstream inFile)
	{
		while (inFile)
		{
			for (int i = 0; i < CITYCOUNT; i++)
			{
				for (int j = 0; j < CITYCOUNT; j++)
				{
					if (adjacencyMatrix[i][j] == 1)
					{
						int weight; 
						weight >> inFile;
						
						Edge edge(j, weight);
						
						nodes[i].SetEdge(edge);
					}
				}
			}
		}
	}
	
	

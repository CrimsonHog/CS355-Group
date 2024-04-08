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
using namespace std;

void fileInput(int, string*, int){};


int main(){
    // Front end, doesnt have to be anything to complicated
    // This could be where we call and create objects from header files
            // New variables do not all need to be at the top, call them where necessary
            // No need to clutter the reading of the drive
    

    //Create menu

    // Call Graph calls - creating and taking 
    //Dummy Graph variables
    int graphWeight; 
    string* graphPathway; 
    int graphData;
    fileInput(graphWeight, graphPathway, graphData);
    

    return 0;
}

// ----------------------------------------------------------
// Function Name: fileInput
// Function Type: void 
// Inputs: Int, string pointer, int
// output: N/A
// Description: Function calls graphInfo text file and inputs them into the 
//              graph node array
// Author: Ethan
// ----------------------------------------------------------
void fileInput(int graphWeight, string* graphPathway, int graphData){
    // Dummy Variables for the file 
    // Change once we are able to call the graphNode Header file
    ifstream inputFile;
    inputFile.open("graphInfo.txt");

    //File input
    if (inputFile.is_open()){
        while(!inputFile.eof()){
            inputFile >> graphWeight;
            inputFile >> *graphPathway;
            inputFile >> graphData;
        }
        inputFile.close();
    }

    // Come back and fix this function so that it works with the graphNode Array
    // Currently does not work as is (LATER ISSUE: Wait for header files to be completed)
};
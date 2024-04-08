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

int main(){
    // Front end, doesnt have to be anything to complicated
    // This could be where we call and create objects from header files
            // New variables do not all need to be at the top, call them where necessary
            // No need to clutter the reading of the drive

    // Dummy Variables for the file 
    // Change once we are able to call the graphNode Header file
    int weight;
    string* pathway;
    int data;
    
    ifstream inputFile;
    inputFile.open("graphInfo.txt");
    //File input
    if (inputFile.is_open()){
        while(!inputFile.eof()){
            inputFile >> weight;
            inputFile >> *pathway;
            inputFile >> data;
        }
        inputFile.close();
    }

    
    // Create menu Here

    return 0;
}

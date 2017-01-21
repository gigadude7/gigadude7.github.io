#include "MazeLoader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

MazeLoader::MazeLoader(string nameOfMaze) {
	mazeName = nameOfMaze; 
}

bool MazeLoader::readMaze() {
	//reads in file
	string const fileName = mazeName;
	ifstream inputFile(fileName.c_str());

	//returns false if file does not exist
	if (!inputFile)
		return false;
	
	//creates maze using nodes
	int lineNumber = 0; 
	int numberOfNodes; 

 
	while (!inputFile.eof()) {
		getline(inputFile, currentLine);
		if (currentLine.compare("") == 0 || currentLine.compare("\n") == 0) {
			continue; 
		}
		if (lineNumber == 0) {
			numberOfNodes = atoi(currentLine.c_str());
			nodeArray = new Node[numberOfNodes]; 
			elementsInArray = 0; 
		}
		else if (lineNumber == 1) {
			startNode = currentLine;
		}
		else if (lineNumber == 2) {
			destinationNode = currentLine;
		}
		else {
			string lineContent; 
			int count = 0; 
			string tempArray[5]; 
			Node lineNode; //Node that is happening on this line. 

			istringstream iss(currentLine); 

			while (iss >> lineContent && count < 5) {
				tempArray[count] = lineContent; 
 				count++;
			}

			for (int i = 0; i <= 4; i++) {  //for every node name in temp array
				bool nodeExists = false;
				for (int j = 0; j < numberOfNodes; j++) { //look at every element in the nodes
					if (nodeArray[j].getNodeName().compare(tempArray[i]) == 0) //if one of them has the same name, then the node already exists
						nodeExists = true; 
				}
				if (!nodeExists && tempArray[i].compare("*") != 0) { //so if it doesn't, create it!
					Node tempNode = Node(tempArray[i]); 
					if (i == 0)
						lineNode = tempNode; 
					nodeArray[elementsInArray] = tempNode; 
					elementsInArray++; 
				}
			}

			//fill that node up!
			for (int i = 1; i < 5; i++) {	//all the other nodes in the temp array
				Node* nodeToBeAssigned;		//var to store the node once found
				bool nodeExists = false;	//bool to check existance
				Node* nodePointer; 
				if (tempArray[i].compare("*") != 0) {	//if temp array does not have a node, you can't do node operations on it. 
					for (int j = 0; j < numberOfNodes; j++) {	//for all the nodes we know exist
						if (nodeArray[j].getNodeName().compare(tempArray[i]) == 0) {	//if that node name == the name of the node we're looking for
							nodeExists = true;		//the node exists
							nodePointer = &nodeArray[j]; 
						}
							
					}
				}
				if (nodeExists) 
					lineNode.attachNewNode(nodePointer, i); 
			}
		}
		lineNumber++; 
	}
	for (int i = 0; i < numberOfNodes; i++) {
		cout << "\nI am node number " << i << ". My name is: " << nodeArray[i].getNodeName(); 
	}
}

void MazeLoader::solveMaze() {
}
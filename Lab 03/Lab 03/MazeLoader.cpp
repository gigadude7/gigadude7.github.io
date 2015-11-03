#include "MazeLoader.h"
#include <fstream>
#include <string>
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
		if (lineNumber = 0) {
			numberOfNodes = atoi(currentLine.c_str());
			nodeArray = new Node[numberOfNodes]; 
		}
		else if (lineNumber = 1) {
			startNode = currentLine;
		}
		else if (lineNumber = 2) {
			destinationNode = currentLine;
		}
		else {
			string lineContent; 
			int count = 0; 
			string tempArray[5]; 
			while (inputFile >> lineContent) {
				tempArray[count] = lineContent; 
				count++;
			}

			for (int i = 0; i < 4; i++) {  //for every node name in temp array
				bool nodeExists = false;
				for (int j = 0; j < numberOfNodes; j++) { //look at every element in the nodes
					if (nodeArray[j].getNodeName().compare(tempArray[i]) == 0) //if one of them has the same name, then the node already exists
						nodeExists = true; 
				}
				if (!nodeExists && tempArray[i].compare("*") != 0) { //so if it doesn't, create it!
					Node* tempNode =  new Node(tempArray[i]); 
				}
			}

			//fill that node up!
			for (int i = 0; i < numberOfNodes; i++) {
				if (nodeArray[i].getNodeName().compare(tempArray[1]) == 0) { //get the node that corresponds to the first element in temp array
					for (int j = 1; j < 5; j++) { //sets up a loop in the tempArray
						for (int k = 0; k < numberOfNodes; k++) { //looks for each element of the temp array in all of the nodes
							if (nodeArray[k].getNodeName().compare(tempArray[j]) == 0) { //if the element is in the temp array and in the nodes, attaches the node
								//nodeArray[i].attachNewNode(nodeArray[k], j - 1); 
							}
						}
					}
				}
			}


		
		}



		lineNumber++; 
	}

}

void MazeLoader::solveMaze() {
}
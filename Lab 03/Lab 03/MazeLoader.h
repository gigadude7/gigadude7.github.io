#pragma once
#include "Node.h"

class MazeLoader
{
public:
	MazeLoader(string nameOfMaze);
	string mazeName; 
	bool readMaze(); 
	void solveMaze(); 
	Node* nodeArray; 
	string currentLine;
	string startNode;
	string destinationNode;
};


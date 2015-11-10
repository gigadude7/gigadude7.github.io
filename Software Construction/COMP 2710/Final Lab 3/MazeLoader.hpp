//
//  MazeLoader.hpp
//  lab3
//
//  Created by Grant Hamilton Cordle on 11/9/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_1 (lab3)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           11/9/2015
//  Email:          ghc0001@auburn.edu
//  Description:    This class handles reading the strigs and converting them into nodes, as well as solving the maze once the nodes are loaded.
#include "Node.hpp"
#include <vector>
#include <list>

class MazeLoader
{
public:
	MazeLoader(string nameOfMaze);      //constructor
	string mazeName;                    //name of the maze
	bool readMaze();                    //reads in the maze
	void solveMaze();                   //solve the maze
	Node *nodeArray;                    //array of all nodes read in
	string currentLine;                 //contents on current line when reading in
	string startNode;                   //where you want to start
	string destinationNode;             //where you want to go
    vector<string> traversedNodes;      //all the nodes that have been visited

private:
	int elementsInArray;                        //how big the nodeArray is
    int numberOfNodes;                          //how many elemets are in the NodeArray
    bool hasBeenVisited(Node* node);
    bool markAsVisited(Node* node, int prevDirection);
    list<Node*> path;                           //a list of the nodes taken
    vector<string> solvedPath;                  //a list of the processed nodes taken
};


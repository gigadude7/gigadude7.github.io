//
//  MazeLoader.cpp
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


#include "MazeLoader.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <vector>

//Function:     MazeLoader(string nameOfMaze)
//Inputs:       name of maze: what you want the name to be
//Outputs:      none
//Description:  constructor with string parameter that creates and names the maze.
//
MazeLoader::MazeLoader(string nameOfMaze) {
    mazeName = nameOfMaze;
}

//Function:     ltrim(string &s)
//Inputs:       string to be trimmed
//Outputs:      string with left side trimmed
//Description:  function that gets rid of whitespace on a string.
//
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

//Function:     rtrim(string &s)
//Inputs:       string to be trimmed
//Outputs:      string with right side trimmed
//Description:  function that gets rid of whitespace on a string.
//
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

//Function:     trim(string &s)
//Inputs:       string to be trimmed
//Outputs:      string with both sides trimmed
//Description:  function that gets rid of whitespace on a string.
//
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

//Function:     readMaze()
//Inputs:       none
//Outputs:      bool saying wether or not successful
//Description:  gets the name of a maze and reads it in. If the file exists, it reads the strings and constructs a maze of nodes.
//
bool MazeLoader::readMaze() {
    //reads in file
    
    //
    string const fileName = mazeName;
    ifstream inputFile(fileName.c_str());
    
    //returns false if file does not exist
    if (!inputFile)
        return false;
    
    //creates maze using nodes
    int lineNumber = 0;
    
    
    while (!inputFile.eof()) {
        getline(inputFile, currentLine);
        if (currentLine.compare("") == 0 || currentLine.compare("\n") == 0) { //make sure not empty line
            continue;
        }
        if (lineNumber == 0) {
            numberOfNodes = atoi(currentLine.c_str()); //get number of nodes
            nodeArray = new Node[numberOfNodes];       //make array that size
            elementsInArray = 0;
        }
        //trim the string and make it start node
        else if (lineNumber == 1) {
            trim(currentLine);
            startNode = currentLine;
        }
        //trim the string and make it end node
        else if (lineNumber == 2) {
            trim(currentLine);
            destinationNode = currentLine;
        }
        else {
            string lineContent;
            int count = 0;
            string tempArray[5]; //all nodes on this line
            Node* lineNode = 0; //Node that is happening on this line.
            
            istringstream iss(currentLine); //so we can read word by word
            
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
                    nodeArray[elementsInArray] = tempNode;
                    elementsInArray++;
                }
            }
            
            for (int i = 0; i < numberOfNodes; i++) {
                if (nodeArray[i].getNodeName().compare(tempArray[0]) == 0)
                    lineNode = &nodeArray[i];
            }
            
            //fill that node up!
            for (int i = 1; i < 5; i++) {	//all the other nodes in the temp array
                if (tempArray[i].compare("*") != 0) {	//if temp array does not have a node, you can't do node operations on it.
                    for (int j = 0; j < numberOfNodes; j++) {	//for all the nodes we know exist
                        Node* nodePointer = 0;
                        if (nodeArray[j].getNodeName().compare(tempArray[i]) == 0) {	//if that node name == the name of the node we're looking for
                            nodePointer = &nodeArray[j];
                        }
                        if (lineNode != 0 && nodePointer != 0)
                            lineNode->attachNewNode(nodePointer, i - 1);
                    }
                }
                
            }
        }
        lineNumber++;
    }
    return true;
}

//Function:     hasBeenVisited(Node* node)
//Inputs:       a pointer to a node
//Outputs:      a bool
//Description:  returns wether or not every pathway that the node can take has been visited
//
bool MazeLoader::hasBeenVisited(Node* node) {
    if (node == 0)
        return true;
    for (int i = 0; i < traversedNodes.size(); i++) {
        if (node->getNodeName().compare(traversedNodes[i]) == 0)
            return true;
    }
    return false;
}


//Function:     markAsVisited(Node* node, int prevDirection)
//Inputs:       a pointer to a node, an int that specifies the direction of the previous node
//Outputs:      a bool
//Description:  If every pathway has been visited, returns true so that the user does not have to spend time working on it
//
bool MazeLoader::markAsVisited(Node* node, int prevDirection) {
    if (prevDirection == -1) {
        return false;
    }
    
    bool directions [4];
    for (int i = 0; i < 4; i++) {
        directions[i] = false;
    }
    
    for (int i = 0; i < 4; i++) {
        if (hasBeenVisited(node->getAttachedNode(i))) {
            directions[i] = true;
        }
    }
    if (directions[0] && directions[1] && directions[2] && directions[3]) {
        string tempString = node->getNodeName();
        traversedNodes.push_back(tempString);
        return true;
    }
    //If there is only one direction to go in.
    else if ((!directions[0] && directions[1] && directions[2] && directions[3]) || (!directions[1] && directions[0] && directions[2] && directions[3]) || (!directions[2] && directions[1] && directions[0] && directions[3]) || (!directions[3] && directions[1] && directions[2] && directions[0])) {
        
        string tempString = node->getNodeName();
        traversedNodes.push_back(tempString);
        return true;
    }
    return false;
}

//Function:     solveMaze()
//Inputs:       none
//Outputs:      none
//Description:  takes the maze of nodes and travels from the start node to the destination node using an Depth First Search Algorythm.
//
void MazeLoader::solveMaze() {
    //start of reset block//
    Node* currentNode = 0;
    vector<string> resetter;
    traversedNodes = resetter;
    solvedPath = resetter;
    list<Node*> resetterNode;
    path = resetterNode; 
    //end of reset block//
    
    //get mem address of start node
    for (int i = 0; i < numberOfNodes; i++) {
        if (nodeArray[i].getNodeName().compare(startNode) == 0) {
            currentNode = &nodeArray[i];
            break; 
        }
    }
    
    
    string solution;
    list<int>directions;
    
    bool outOfOptions = false; //wether or not there are more moves
    bool noSolution = false;    //wether or not there is a soln
    int prevDirection = -1;     //initializer for previous direction
    
    for (int i = 0; i < numberOfNodes; i++) {
        traversedNodes.push_back("");
    }
    
    cout << "\nThe start node is: " << startNode;
    cout << "\nThe destination node is: " << destinationNode;
    cout << "\nFinding a solution...\n";
    
    path.push_front(currentNode); //load node
    
    //basically what this while loop does is it looks at every possible combination
    //of moves. If it doesn't have to backtrack, then it doesn't
    //but if all other possiblilites have been taken, it backtracks one node and then
    //markds the direction it came from as visited
    while (currentNode->getNodeName().compare(destinationNode) != 0 && !outOfOptions) {
        if( markAsVisited(currentNode, prevDirection)) {
            path.pop_front();
            path.pop_front();
        }
        
        if (!hasBeenVisited(currentNode->getAttachedNode(0)) && prevDirection != 0) {
            prevDirection = 2;
            path.push_front(currentNode->getAttachedNode(0));
            directions.push_front(prevDirection);
            
        }
        else if (!hasBeenVisited(currentNode->getAttachedNode(1)) && prevDirection != 1) {
            path.push_front(currentNode->getAttachedNode(1));
            prevDirection = 3;
            directions.push_front(prevDirection);
        }
        else if (!hasBeenVisited(currentNode->getAttachedNode(2)) && prevDirection != 2) {
            path.push_front(currentNode->getAttachedNode(2));
            prevDirection = 0;
            directions.push_front(prevDirection);
        }
        else if (!hasBeenVisited(currentNode->getAttachedNode(3)) && prevDirection != 3) {
            path.push_front(currentNode->getAttachedNode(3));
            prevDirection = 1;
            directions.push_front(prevDirection);
        }
        else if (!hasBeenVisited(currentNode->getAttachedNode(0))) {
            prevDirection = 2;
            path.push_front(currentNode->getAttachedNode(0));
            directions.push_front(prevDirection);
        }
        else if (!hasBeenVisited(currentNode->getAttachedNode(1))) {
            path.push_front(currentNode->getAttachedNode(1));
            prevDirection = 3;
            directions.push_front(prevDirection);
        }
        
        else if (!hasBeenVisited(currentNode->getAttachedNode(2))) {
            path.push_front(currentNode->getAttachedNode(2));
            prevDirection = 0;
            directions.push_front(prevDirection);
        }
        
        else if (!hasBeenVisited(currentNode->getAttachedNode(3))) {
            path.push_front(currentNode->getAttachedNode(3));
            prevDirection = 1;
            directions.push_front(prevDirection);
        }
        else {
            outOfOptions = true;
            noSolution = true;
            cout << "\nA solution could not be found.\n\n";
            break;
        }
        
        if (path.size() != 0) {
            currentNode = path.front();
        }
    }
    
    //this is the section that prints the path
    if (path.size() > 0 && !noSolution) {
    int pathSize = path.size();
    for (int i = 0; i < pathSize; i++) {
        Node* tempNode = path.front();
        path.pop_front();
        
        bool alreadyWritten = false;
        
        for (int j = 0; j < solvedPath.size(); j++) {
            if (tempNode->getNodeName().compare(solvedPath[j]) == 0) {
                alreadyWritten = true;
            }
        }
        
        if (!alreadyWritten) {
            solvedPath.push_back(tempNode->getNodeName());
        }
        if (tempNode->getNodeName().compare(startNode) == 0) {
            break;
        }
    }
        cout << "\nThe solution to the maze is: \n";
        
        for (int g = 0; g < solvedPath.size(); g++) {
            cout << solvedPath[solvedPath.size() - g] << " ";
        }
        cout << destinationNode << "\n\n";
        
    }
}
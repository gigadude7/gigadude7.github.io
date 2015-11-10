//
//  Node.cpp
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
//  Description:    This class defines the Node data structure.
#include <iostream>

using namespace std; 

class Node {
public: 
	Node(string newname);
	Node();
	void setNodeName(string newname);
	string getNodeName();
	void attachNewNode(Node *newNode, int direction);
	Node *getAttachedNode(int direction);
private:
	string name;    //name of node
	Node *attachedNodes[4]; //array of node pointers to it's 'attached' nodes
};
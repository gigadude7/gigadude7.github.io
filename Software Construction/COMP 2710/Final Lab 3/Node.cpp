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
#include "Node.hpp"
#include <iostream>

using namespace std; 

//Function:     Node(string newname)
//Inputs:       name of node: what you want the name to be
//Outputs:      none
//Description:  constructor with string parameter that creates and names the node.
//
Node::Node(string newname) {
	name = newname; 
}

//Function:     Node()
//Inputs:       none
//Outputs:      none
//Description:  parameterless constructor
//
Node::Node() {
}

//Function:     setNodeName(string newname)
//Inputs:       name of node: what you want the name to be
//Outputs:      none
//Description:  sets the name of a node
//
void Node::setNodeName(string newName) {
	name = newName; 
}

//Function:     getNodeName()
//Inputs:       name of node: what you want the name to be
//Outputs:      none
//Description:  gets the name of a node
//
string Node::getNodeName() {
	return name; 
}

//Function:     attachNewNode(Node *newNode, int direction)
//Inputs:       nodepointer, what direction the pointer will point.
//Outputs:      none
//Description:  attaches a nodepointer to the internal attachedNodes array that in the direction that the user specifies
//
void Node::attachNewNode(Node *newNode, int direction) {
	attachedNodes[direction] = newNode; 
}

//Function:     getAttachedNode(int direction)
//Inputs:       what direction you want to get
//Outputs:      Node pointer to the node in that direction
//Description:  gets a pointer to the node in the direction that you want. 
//
Node* Node::getAttachedNode(int direction) {
	return attachedNodes[direction]; 
}
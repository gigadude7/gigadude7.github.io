#pragma once
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
	string name;
	Node *attachedNodes[4]; 
};
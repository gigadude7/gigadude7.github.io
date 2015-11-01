#include "Node.h"
#include <iostream>

using namespace std; 

Node::Node(string newname) {
	name = newname; 
}

Node::Node() {
}

void Node::setNodeName(string newName) {
	name = newName; 
}

string Node::getNodeName() {
	return name; 
}

void Node::attachNewNode(Node *newNode, int direction) {
	attachedNodes[direction] = newNode; 
}

Node* Node::getAttachedNode(int direction) {
	return attachedNodes[direction]; 
}
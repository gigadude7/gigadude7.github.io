#include <iostream>
#include <fstream>
#include <string>
#include "MazeLoader.h"

using namespace std; 

int main() {
	cout << "========================================================\n";
	cout << "          Welcome to the Automatic Maze Path Finder      \n";
	cout << "========================================================\n\n";
	cout << "Please enter the name of the maze configuration file to solve the maze, or 'Quit' to exit the program: ";

	string mazeName = "";                     //string to hold name of maze
	do {
		if (mazeName.compare("") != 0 && mazeName.compare("Quit") != 0) {
			MazeLoader maze = MazeLoader(mazeName); 
			if (!maze.readMaze()) {
				cout << "\n\nThere seems to be nothing here. Please try a different file name!\n";
			}
		}

		getline(cin, mazeName);
		cin.clear(); 
		cin.ignore(10000, '\n'); 
	} while (mazeName.compare("Quit") != 0); 

	cout << "\nThanks for using my Maze Solver! \n-Grant"; 
	return 0; 
}
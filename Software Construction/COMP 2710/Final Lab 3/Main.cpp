//
//  Main.cpp
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
//  Description:    This is the main fuction. It handles starting as well as ending the program.


#include <iostream>
#include <fstream>
#include <string>
#include "MazeLoader.hpp"

using namespace std; 
//Function:     main()
//Inputs:       None
//Outputs:      int
//Description:  Handles user input. Handles starting and stopping the project.
//

int main() {
	cout << "========================================================\n";
	cout << "          Welcome to the Automatic Maze Path Finder      \n";
	cout << "========================================================\n\n";

	string mazeName = "";                     //string to hold name of maze
	do {
        
		if (mazeName.compare("") != 0 && mazeName.compare("Quit") != 0) {
			MazeLoader maze = MazeLoader(mazeName); 
			if (!maze.readMaze()) {
				cout << "\n\nThere seems to be nothing here. Please try a different file name or type 'Quit' to quit the program.\n";
			}
            else {
                maze.solveMaze(); 
            }
		}
        cout << "Please enter the name of the maze configuration file to solve the maze, or 'Quit' to exit the program: ";
		getline(cin, mazeName);
		//cin.ignore(10000, '\n');
		cin.clear(); 
	} while (mazeName.compare("Quit") != 0); 

	cout << "\nThanks for using my Maze Solver! \n-Grant"; 
	return 0; 
}
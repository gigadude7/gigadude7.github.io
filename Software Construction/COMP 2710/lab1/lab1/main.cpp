//
//  main.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_1 (lab1)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Sept 27, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    This is the main function that stores the menu and directs the User's input

#include <iostream>
#include "Menu.hpp"

using namespace std;

//Function:     Main
//Inputs:       None
//Outputs:      None
//Description:  Main method that directs User's input
//
int main(int argc, const char * argv[]) {
    cout << "============================================\n";
    cout << " Welcome to the WeagleBook Messaging System\n";
    cout << "============================================\n\n";
    
    Menu menu;                      //instance of a menu for which to process user input
    bool exit = false;              //says when to exit
    while (!exit) {
        while (true) {
            int userChoice;         //stores the user's choice to put into the menu
            
            menu.startMenu();
            std::cin >> userChoice;
            
            if (userChoice == 9)
                exit = true;
            
            if (!std::cin.fail()) {
                menu.userChoice(userChoice);
                std::cin.clear();
            }
            
            else {
                std::cout << "\n\nPlease enter a whole number between 1 and 9!\n\n";
                cin.clear();
                std::cin.ignore(10000, '\n');
                break;
            }
        }
    }
}
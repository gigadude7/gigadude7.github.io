//
//  main.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 10/14/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_2 (lab2)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Oct 14, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    This is the main function that stores the menu and directs the User's input

#include <iostream>
#include "Menu.hpp"
#include "User.hpp"
#include <fstream>

using namespace std;

//Function:     Main
//Inputs:       None
//Outputs:      None
//Description:  Main method that directs User's input
//
int main(int argc, const char * argv[]) {
    
    
    cout << "========================================================\n";
    cout << "           Distributed WeagleBook Messaging \n";
    cout << "========================================================\n\n";
    cout << "Please enter user name: ";
    
    string username;
    getline(cin, username);
    User currentUser = User(username);
    System console = System(username);
    
    cout << "\n\n========================================================\n";
    cout << " Welcome to the Distributed WeagleBook Messaging System\n";
    cout << "========================================================\n";
    
    
    Menu menu;                      //instance of a menu for which to process user input
    bool exit = false;              //says when to exit
    while (!exit) {
        while (true) {
            char userChoice;         //stores the user's choice to put into the menu
            
            menu.startMenu();
            std::cin >> userChoice;
            
            if (userChoice == 'q') {
                cout << "Thanks for using the Distributed WeagleBook Messaging System!\n";
                exit = true;
                break; 
            }
            
            if (!std::cin.fail()) {
                menu.userChoice(userChoice, console);
                std::cin.clear();
            }
            
            else {
                std::cout << "\n\nPlease enter a one of the valid characters! (f, p, t, w, h, or q)\n\n";
                cin.clear();
                std::cin.ignore(10000, '\n');
                break;
            }
        }
    }
}
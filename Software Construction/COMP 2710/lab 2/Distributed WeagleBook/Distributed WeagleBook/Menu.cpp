//
//  Menu.cpp
//  lab2
//
//  Created by Grant Hamilton Cordle on 10/14/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_2 (lab2)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Oct 14, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    This program is made to handle all of the different from the main function.
#include "Menu.hpp"
#include <iostream>

//Function:     startMenu()
//Inputs:       None
//Outputs:      None
//Description:  Displays the formatted menu choices for the user to choose from.
//
void Menu::startMenu() {
    std::cout << "\n\nEnter the character to access the feature:\nAdd Friend (f), Post (p), Tweet(t), Wall (w), Home (h), Quit (q)\n";
}

//Function:     userChoice()
//Inputs:       char that tells the program what action to do
//Outputs:      None
//Description:  Processes the User's input, and if invalid, does not accept it.
//
void Menu::userChoice(char input, System &currentSystem) {
    switch (input) {
        case 'f':
            currentSystem.addFriend();
            break;
        case 'p':
            currentSystem.postMessage();
            break;
        case 't':
            currentSystem.tweetMessage();
            break;
        case 'w':
            currentSystem.displayWall();
            break;
        case 'h':
            currentSystem.displayHome();
            break;
        case 'q':
            // handled in main.cpp
            break;
        default:
            std::cout<< "Not a valid input! Please enter a valid character!";
            break;
    }
}

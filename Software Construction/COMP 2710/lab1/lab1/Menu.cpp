//
//  Menu.cpp
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
//  Description:    This program is made to handle all of the different from the main function.
#include "Menu.hpp"
#include <iostream>

//Function:     startMenu()
//Inputs:       None
//Outputs:      None
//Description:  Displays the formatted menu choices for the user to choose from.
//
void Menu::startMenu() {
    std::cout << "\n1) Create a new user\n2) Post a message\n3) Tweet a message \n4) Display Wall page \n5) Display Home page \n6) Add a friend \n7) Switch to a different user \n8) Display Friends \n9) Quit WeagleBook\n\n   Please Choose an Option:";
}

//Function:     userChoice()
//Inputs:       int that tells the program what action to do
//Outputs:      None
//Description:  Processes the User's input, and if invalid, does not accept it.
//
void Menu::userChoice(int input) {
    switch (input) {
        case 1:
            console.createNewUser();
            break;
        case 2:
            console.postMessage();
            break;
        case 3:
            console.tweetMessage(); 
            break;
        case 4:
            console.displayWall();
            break;
        case 5:
            console.displayHome();
            break;
        case 6:
            console.addFriend(); 
            break;
        case 7:
            console.switchUsers(); 
            break;
        case 8:
            console.displayFriends();
            break;
        case 9:
            console.quitWeagleBook();
        default:
            std::cout<< "Not a valid input! Please enter a whole number between 1 and 9";
            break;
    }
}
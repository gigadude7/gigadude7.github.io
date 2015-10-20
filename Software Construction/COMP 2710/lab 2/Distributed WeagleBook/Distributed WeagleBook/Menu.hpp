//
//  Menu.hpp
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
//  Description:    This is the main function that stores the menu and directs the User's input

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "System.hpp"

class Menu {
public:
    void startMenu();                                   //parameterless constructor
    void userChoice(char input, System &currentSystem); //method that starts the menu and handles the user input
};

#endif /* Menu_hpp */

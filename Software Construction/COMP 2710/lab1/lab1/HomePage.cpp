//
//  HomePage.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/22/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_1 (lab1)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Sept 27, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    This is the class that handles the User's Home page, it determines wether or not more messages should be displayed

#include "HomePage.hpp"

//Function:     WallPage()
//Inputs:       None
//Outputs:      None
//Description:  Constructor for the Wall Page
//
HomePage::HomePage() {
    messagesDisplayed = 0;
    displayMore = false;
}

int HomePage:: getDisplayedMessages() {
    return messagesDisplayed;
}

bool HomePage:: getDisplayMore() {
    return displayMore;
}

void HomePage:: shouldDisplayMore(bool userInput) {
    displayMore = userInput;
}
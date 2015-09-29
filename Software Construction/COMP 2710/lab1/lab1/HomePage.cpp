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
    messagesDisplayed = 0;  //number of messages currently displayed
    displayMore = false;    //wether or not to display more messages
}

//Function:     getDisplayedMessages()
//Inputs:       None
//Outputs:      Number of messages that is currently displayed
//Description:  getter for the number of messages that is currently displayed
//
int HomePage:: getDisplayedMessages() {
    return messagesDisplayed;
}

//Function:     getDisplayMore()
//Inputs:       None
//Outputs:      bool for wether or not to display more messages
//Description:  getter for wether or not to display more messages
//
bool HomePage:: getDisplayMore() {
    return displayMore;
}

//Function:     WallPage()
//Inputs:       bool - set wether or not to display more messages
//Outputs:      None
//Description:  Setter for wether or not to display more messages
//
void HomePage:: shouldDisplayMore(bool userInput) {
    displayMore = userInput;
}
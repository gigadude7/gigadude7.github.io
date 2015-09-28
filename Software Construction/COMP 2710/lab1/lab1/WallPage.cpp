//
//  WallPage.cpp
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
//  Description:    This is the implementation of the Wall page class. It returns bools for wether or not to display more messages. 

#include "User.hpp"

//Function:     WallPage()
//Inputs:       None
//Outputs:      None
//Description:  Constructor for the Wall Page
//
WallPage::WallPage() {
    messagesDisplayed = 0;  //number of messages currently displayed
    displayMore = false;    //wether or not to display more messages
}

//Function:     getDisplayedMessages
//Inputs:       None
//Outputs:      Int - #of messages
//Description:  returns the number of messages displayed
//
int WallPage:: getDisplayedMessages() {
    return messagesDisplayed;
}

//Function:     getDisplayMore
//Inputs:       None
//Outputs:      Bool - should display more messages
//Description:  returns wether or not you should display more messages
//
bool WallPage:: getDisplayMore() {
    return displayMore;
}

//Function:     shouldDisplayMore
//Inputs:       the User's input in Bool form
//Outputs:      void
//Description:  sets wether or not to display more messages
//
void WallPage:: shouldDisplayMore(bool userInput) {
    displayMore = userInput;
}
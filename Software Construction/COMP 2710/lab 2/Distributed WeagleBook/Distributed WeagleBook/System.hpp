//
//  System.hpp
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
//  Description:    This is the function that effectively calls the other functions and gets them to interface with each other.

#ifndef System_hpp
#define System_hpp

#include <stdio.h>
#include <iostream>
#include "User.hpp"
#include "Message.hpp"
#include "Time.hpp"

using namespace std;
class System {
public:
    System(User user);
    bool addFriend();
    bool postMessage();
    bool tweetMessage();
    void displayHome();
    void displayWall(); 
private:
    User currentUser;       //Current User of the System
    Time newTime;           //Instance of time for messaging purposes
};

#endif /* System_hpp */

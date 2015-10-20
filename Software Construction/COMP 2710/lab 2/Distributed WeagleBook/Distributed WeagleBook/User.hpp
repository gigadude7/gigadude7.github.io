//
//  User.cpp
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
//  Description:    This is the class that creates the user, stores all of the data, and defines it's interactions.

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class User {
public:
    User(); 
    User(string userName);
    string name; //name of User
    string fileName;    //name of User's file
    list<string> friends;   //internal list of friends
    bool hasFriend(string friendName);
    bool operator==(const User& otherUser);
    bool addFriend(string friendName); 
};

#endif /* User_hpp */

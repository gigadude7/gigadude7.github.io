//
//  User.h
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
//  Description:    Header file for User.cpp

#ifndef __lab1__User__
#define __lab1__User__

#include <stdio.h>
#include <iostream>
#include "FriendList.hpp"
#include "WallPage.hpp"
#include "HomePage.hpp"


class User {
public:
    std::string getName();
    User(std::string newName);
    User();
    bool operator==(const User& otherUser);
    FriendList friends;
    std::list<User> getUserFriends();
    std::list<std::string> usersFriends();
private:
    std::string name;   //User's name in string form
};



#endif /* defined(__lab1__User__) */




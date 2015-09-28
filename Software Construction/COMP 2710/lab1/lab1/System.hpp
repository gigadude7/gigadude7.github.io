//
//  System.h
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
//  Description:    Header for System.cpp


#ifndef __lab1__System__
#define __lab1__System__

#include <stdio.h>
#include <list>
#include <iostream>
#include "User.hpp"
#include "Message.hpp"
#include "WallPage.hpp"


class System {
    
public:
    System();
    void createNewUser();
    void postMessage();
    void tweetMessage();
    void displayWall();
    void displayHome();
    void addFriend();
    void switchUsers();
    void quitWeagleBook();
    void printRegisteredUsers();
    void displayFriends();

private:
    std::list<User> registeredUsers;
    std::list<std::string> messageBuffer;
    void login(User user);
    bool isLoggedIn;
    User currentUser;
};

#endif /* defined(__lab1__System__) */

//
//  Message.h
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
//  Description:    Header file for Message.cpp

#ifndef __lab1__Message__
#define __lab1__Message__

#include <stdio.h>
#include <iostream>


class User;

class Message {
    
public:
    Message(User& currentUser, std::string newMessage, bool isPublic);
    std::string buildMessage();
    bool isTweet; //true if tweet, false if home message
    User getMessageOwner();
    std::string getMessageContents();

private:
    std::string message;
    User *newUser;
    
};

#endif /* defined(__lab1__Message__) */

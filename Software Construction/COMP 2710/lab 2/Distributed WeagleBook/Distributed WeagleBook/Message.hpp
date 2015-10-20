//
//  Message.hpp
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
//  Description:    This is the class that creates the Message, stores all of the data, and defines it's interactions.

#ifndef Message_hpp
#define Message_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Time.hpp"
#include "User.hpp"

using namespace std;
class Message {
public:
    Message(string username, string content, int currentTime);
    bool postMessage();
    bool tweetMessage();
    
private:
    bool storeMessage(string msg);
    bool storeTweet(string msg);
    string messageOwner;    //name of the message owner
    string messageContent;  //content of message
    int messageTime;        //when the message was posted
    
};


#endif /* Message_hpp */

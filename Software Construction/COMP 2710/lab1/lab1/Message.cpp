//
//  Message.cpp
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
//  Description:    This class if for the message. It can build a message from different pars, get message contents, and get the message's owner. 

#include "Message.hpp"
#include "User.hpp"

Message::Message(User& currentUser, std::string newMessage, bool isPublic){
    newUser = &currentUser;
    message = newMessage;
    isTweet = isPublic;
}

std::string Message:: buildMessage(){
    std::string opener = "{[";
    std::string closer = "]}";
    std::string tweetString = "";
    if (isTweet) {
        tweetString = "::tweet";
    }
    
    return opener + newUser->getName() + tweetString + closer + message;
    
}

std::string Message::getMessageContents() {
    return message;
}

User Message:: getMessageOwner() {
    return *newUser;
}
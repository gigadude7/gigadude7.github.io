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

//Function:     Message()
//Inputs:       Messages Owner, Message content, wether or not the message is public
//Outputs:      None
//Description:  Constructor for the Message Class
//
Message::Message(User& currentUser, std::string newMessage, bool isPublic){
    newUser = &currentUser;     //name of message owner
    message = newMessage;       //message content
    isTweet = isPublic;         //wether or not the message is public (i.e. a tweet)
}

//Function:     buildMessage()
//Inputs:       None
//Outputs:      String that represents the message
//Description:  Takes the different components of the message, and combines them into a returnable string, then returns the string.
//
std::string Message:: buildMessage(){
    std::string opener = "{[";      //string to make the opener
    std::string closer = "]}";      //tring to make the closer
    std::string tweetString = "";   //empty string to store the tweetString
    if (isTweet)
        tweetString = "::tweet";
    
    return opener + newUser->getName() + tweetString + closer + message;
}

//Function:     getMessageContents()
//Inputs:       None
//Outputs:      a string with the message contents
//Description:  When called on a message object, it returns the string with the message's contents.
//
std::string Message::getMessageContents() {
    return message;
}

//Function:     getMessageOwner()
//Inputs:       None
//Outputs:      The owner of the message
//Description:  When called on a message object, it returns whoever wrote the message. 
//
User Message:: getMessageOwner() {
    return *newUser;
}
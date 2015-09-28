//
//  Message.h
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

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

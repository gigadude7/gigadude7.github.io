//
//  Message.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "Message.h"

Message::Message(User& currentUser, std::string newMessage, bool isPublic){
    newUser = &currentUser;
    message = newMessage;
    isTweet = isPublic;
}

std::string Message:: buildMessage(){
    std::string opener = "{[";
    std::string closer = "]]";
    std::string tweetString = "";
    if (isTweet) {
        tweetString = "::tweet";
    }
    
    return opener + newUser->getName() + tweetString + closer + message;
    
}
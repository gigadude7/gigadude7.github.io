//
//  Message.hpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

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
    string messageOwner;
    string messageContent;
    int messageTime; 
    
};


#endif /* Message_hpp */

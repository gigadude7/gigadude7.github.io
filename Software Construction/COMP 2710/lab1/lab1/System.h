//
//  System.h
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#ifndef __lab1__System__
#define __lab1__System__

#include <stdio.h>
#include <list>
#include <iostream>
#include "User.h"
#include "Message.h"


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
    bool isLoggedIn;

private:
    std::list<User> registeredUsers;
    std::list<Message> messageBuffer;
    void login(User user);
    User currentUser;
};

#endif /* defined(__lab1__System__) */

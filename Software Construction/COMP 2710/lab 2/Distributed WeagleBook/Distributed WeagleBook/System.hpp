//
//  System.hpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#ifndef System_hpp
#define System_hpp

#include <stdio.h>
#include <iostream>
#include "User.hpp"
#include "Message.hpp"
#include "Time.hpp"

using namespace std;
class System {
public:
    System(User user);
    bool addFriend();
    bool postMessage();
    bool tweetMessage();
    void displayHome();
    void displayWall(); 
private:
    User currentUser;
    Time newTime; 
};

#endif /* System_hpp */

//
//  User.hpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class User {
public:
    User(); 
    User(string userName);
    string name;
    string fileName;
    list<string> friends;
    bool hasFriend(string friendName);
    bool operator==(const User& otherUser);
    bool addFriend(string friendName); 
};

#endif /* User_hpp */

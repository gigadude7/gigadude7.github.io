//
//  User.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "User.hpp"

User::User(std::string newName) {
    name = newName;
}

User::User() {
    
}

std::string User:: getName(){
    return name;
}

bool User::operator==(const User& otherUser){
    if (otherUser.name == "") {
        return false;
    }
    
    if (this->name.compare(otherUser.name) == 0)
        return true;
    
    return false;
}

std::list<User> User::getUserFriends() {
    return friends.getList();
}

std::list<std::string> User:: usersFriends() {
    std::list<std::string>friendNames;
    if (friends.getList().size() != 0) {
        for (std::list<User>::iterator it=friends.getList().begin(); it != friends.getList().end(); ++it) {
            friendNames.push_back( it->getName().substr(0, it->getName().length()));
        }

    }
    return friendNames;
}



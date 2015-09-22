//
//  User.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "User.h"

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



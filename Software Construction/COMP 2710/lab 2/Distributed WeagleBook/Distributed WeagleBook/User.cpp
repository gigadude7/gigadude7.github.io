//
//  User.cpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "User.hpp"

User::User() {
}

User::User(string userName) {
    name = userName;
    fileName = name + ".txt"; //wallpage
    
    ofstream userFile;
    string const fileNameCStr = fileName;
    userFile.open(fileNameCStr.c_str(), ios::app);
    userFile << name + "\n";
}

//Function:     operator==(cont User& otherUser)
//Inputs:       A User object
//Outputs:      Bool that says wether the users are equivalent
//Description:  Overwritten == method. Returns true if the Users have the same name, and false if they do not.
//
bool User::operator==(const User& otherUser){
    if (otherUser.name == "")
        return false;
    if (this->name.compare(otherUser.name) == 0)
        return true;
    return false;
}

bool User::hasFriend(string friendName) {
    for (std::list<string>::iterator it=friends.begin(); it != friends.end(); ++it)
        if (it->compare(friendName) == 0)
            return true;
    return false;
}

bool User::addFriend(string friendName) {
    string const constStringforFriend = friendName + ".txt";
    ifstream ifile(constStringforFriend.c_str());
    if (ifile) {
        friends.push_front(friendName);
        return true;
    }
    return false;
}



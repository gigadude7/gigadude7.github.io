//
//  User.cpp
//  lab2
//
//  Created by Grant Hamilton Cordle on 10/14/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_2 (lab2)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Oct 14, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    This is the class that creates the user, stores all of the data, and defines it's interactions.

#include "User.hpp"

//Function:     User()
//Inputs:       None
//Outputs:      None
//Description:  Parameterless constructor for User.
//
User::User() {
}

//Function:     User(string userName)
//Inputs:       String for the name of the user
//Outputs:      None
//Description:  Creates a user and names it the username. If there isn't a file for them, it creates that too.
//
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

//Function:     hasFriend()
//Inputs:       name of friend
//Outputs:      bool
//Description:  If the friend is on the friendslist, returns true
//
bool User::hasFriend(string friendName) {
    for (std::list<string>::iterator it=friends.begin(); it != friends.end(); ++it)
        if (it->compare(friendName) == 0)
            return true;
    return false;
}

//Function:     addFriend()
//Inputs:       friendName
//Outputs:      bool
//Description:  Adds friend w/ given name to friend list. If successful, returns true. 
//
bool User::addFriend(string friendName) {
    string const constStringforFriend = friendName + ".txt";
    ifstream ifile(constStringforFriend.c_str());
    if (ifile) {
        friends.push_front(friendName);
        return true;
    }
    return false;
}



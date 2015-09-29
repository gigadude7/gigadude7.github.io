//
//  User.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_1 (lab1)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Sept 27, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    Creates Users, overloads the '==' operator for the User, returns a list of the User's friends as strings and as Users

#include "User.hpp"

//Function:     User()
//Inputs:       Name of the user you want to make
//Outputs:      None
//Description:  Constructer for the User class
//
User::User(std::string newName) {
    name = newName; //name of the user
}

//Function:     User()
//Inputs:       None
//Outputs:      None
//Description:  Parameterless constructor for the User class
//
User::User() {
    
}

//Function:     getName()
//Inputs:       None
//Outputs:      String that represents the User's name
//Description:  when called on a user, it returns a string that contains that user's name
//
std::string User:: getName(){
    return name;
}

//Function:     operator==(cont User& otherUser)
//Inputs:       A User object
//Outputs:      Bool that says wether the users are equivalent
//Description:  Overwritten == method. Returns true if the Users have the same name, and false if they do not.
//
bool User::operator==(const User& otherUser){
    if (otherUser.name == "") {
        return false;
    }
    
    if (this->name.compare(otherUser.name) == 0)
        return true;
    
    return false;
}

//Function:     getUserFriends()
//Inputs:       None
//Outputs:      A list of type user that represnts the User's friends as users.
//Description:  When called on a user, it returns that User's frineds as users.
//
std::list<User> User::getUserFriends() {
    return friends.getList();
}

//Function:     userFriends()
//Inputs:       None
//Outputs:      A list of the User's friends as strings.
//Description:  when called on a user, it returns that User's friends as strings. 
//
std::list<std::string> User:: usersFriends() {
    std::list<std::string>friendNames;
    if (friends.getList().size() != 0) {
        for (std::list<User>::iterator it=friends.getList().begin(); it != friends.getList().end(); ++it) {
            friendNames.push_back( it->getName().substr(0, it->getName().length()));
        }

    }
    return friendNames;
}



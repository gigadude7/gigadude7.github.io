//
//  FriendList.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/22/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_1 (lab1)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Sept 27, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    Friendslist class, functions to add friends, return a friendlist of users and the friendlist itself. 

#include "FriendList.hpp"
#include "User.hpp"
#include <algorithm>

//Function:     FriendList()
//Inputs:       None
//Outputs:      None
//Description:  Constructor for the FriendList.
//
FriendList::FriendList() {
    friends = *new std::list<User>;
}

//Function:     addFriend()
//Inputs:       A user to add
//Outputs:      None
//Description:  Adds the user to the friend list.
//
void FriendList::addFriend(User newFriend) {
    friends.push_front(newFriend);
}

//Function:     returnFriends()
//Inputs:       None
//Outputs:      Prints out friends
//Description:  When called on a user, it prints out a list of the User's friends.
//
void FriendList::returnFriends() {
    if (friends.size() == 0)
        std::cout << "\n\nYou have no friends.\n\n";
    for (std::list<User>::iterator it=friends.begin(); it != friends.end(); ++it)
        std::cout << "\n" + it->getName() + "\n";
}

//Function:     getList()
//Inputs:       None
//Outputs:      List of type User
//Description:  When called on a friend list, returns a list of type user of the current User's friends. 
//
std::list<User> FriendList:: getList() {
    return friends;
}
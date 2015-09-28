//
//  FriendList.hpp
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
//  Description:    Header for Friendlist.cpp

#ifndef FriendList_h
#define FriendList_h

#include <stdio.h>
#include <list>

class User;

class FriendList {
public:
    FriendList();
    void addFriend(User newFriend);
    void returnFriends();
    std::list<User> friends;
    std::list<User> getList();
};



#endif /* FriendList_h */

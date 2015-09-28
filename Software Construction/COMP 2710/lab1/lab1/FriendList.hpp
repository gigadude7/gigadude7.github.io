//
//  FriendList.hpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/22/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

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

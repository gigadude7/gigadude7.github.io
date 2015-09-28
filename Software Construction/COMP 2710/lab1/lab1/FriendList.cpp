//
//  FriendList.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/22/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "FriendList.hpp"
#include "User.hpp"
#include <algorithm>

FriendList::FriendList() {
    friends = *new std::list<User>;
}

void FriendList::addFriend(User newFriend) {
    friends.push_front(newFriend);
}

void FriendList::returnFriends() {
    if (friends.size() == 0)
        std::cout << "\n\nYou have no friends.\n\n";
    for (std::list<User>::iterator it=friends.begin(); it != friends.end(); ++it)
        std::cout << "\n" + it->getName() + "\n";
}

std::list<User> FriendList:: getList() {
    return friends;
}
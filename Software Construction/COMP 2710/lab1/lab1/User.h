//
//  User.h
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#ifndef __lab1__User__
#define __lab1__User__

#include <stdio.h>
#include <iostream>
#include "Message.h"

class User {
public:
    std::string getName();
    User(std::string newName);
    User();
    bool operator==(const User& otherUser);
private:
    std::string name;
};



#endif /* defined(__lab1__User__) */




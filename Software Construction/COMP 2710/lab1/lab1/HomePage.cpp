//
//  HomePage.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/22/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "HomePage.hpp"

HomePage::HomePage() {
    messagesDisplayed = 0;
    displayMore = false;
}

int HomePage:: getDisplayedMessages() {
    return messagesDisplayed;
}

bool HomePage:: getDisplayMore() {
    return displayMore;
}

void HomePage:: shouldDisplayMore(bool userInput) {
    displayMore = userInput;
}
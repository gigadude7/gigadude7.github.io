//
//  WallPage.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/22/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "User.hpp"

WallPage::WallPage() {
    messagesDisplayed = 0;
    displayMore = false; 
}

int WallPage:: getDisplayedMessages() {
    return messagesDisplayed;
}

bool WallPage:: getDisplayMore() {
    return displayMore;
}

void WallPage:: shouldDisplayMore(bool userInput) {
    displayMore = userInput;
}
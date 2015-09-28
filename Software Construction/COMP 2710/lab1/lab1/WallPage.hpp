//
//  WallPage.hpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/22/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#ifndef WallPage_hpp
#define WallPage_hpp

#include <stdio.h>
#include "WallPage.hpp"
#include "Message.hpp"

class WallPage {
public:
    WallPage();
    int getDisplayedMessages();
    bool getDisplayMore();
    void shouldDisplayMore(bool userInput);
    
private:
    int messagesDisplayed;
    bool displayMore;
};

#endif /* WallPage_hpp */

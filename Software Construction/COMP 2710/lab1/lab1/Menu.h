//
//  Menu.h
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#ifndef __lab1__Menu__
#define __lab1__Menu__

#include <stdio.h>
#include <iostream>
#include "System.h"

class Menu {
    
public:
    void startMenu();
    void userChoice(int input);
private:
    System console;
};

#endif /* defined(__lab1__Menu__) */

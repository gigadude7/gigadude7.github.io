//
//  Menu.hpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "System.hpp"

class Menu {
public:
    void startMenu();
    void userChoice(char input, System &currentSystem);
};

#endif /* Menu_hpp */

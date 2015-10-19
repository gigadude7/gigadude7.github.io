//
//  Time.cpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "Time.hpp"

Time::Time() {
    currentTime = 0;
}

int Time::getTime() {
    return ++currentTime; 
}
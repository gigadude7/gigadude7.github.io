//
//  Time.hpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <time.h>  

class Time {
public:
    Time();
    int getTime();
private:
    int currentTime;
};

#endif /* Time_hpp */

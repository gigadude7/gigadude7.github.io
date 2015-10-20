//
//  Time.hpp
//  lab2
//
//  Created by Grant Hamilton Cordle on 10/14/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_2 (lab2)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Oct 14, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    This is the class that creates the Time, stores all of the data, and defines it's interactions.

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <time.h>  

class Time {
public:
    Time();
    int getTime();
private:
    int currentTime;    //internal store of current time
};

#endif /* Time_hpp */

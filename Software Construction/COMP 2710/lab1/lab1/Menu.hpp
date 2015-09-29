//
//  Menu.h
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//
//  Program:        ghc0001_1 (lab1)
//  Name:           Grant Cordle
//  Class:          COMP 2710 Section 002
//  Date:           Sept 27, 2015
//  Email:          ghc0001@auburn.edu
//  Description:    Header for Menu.cpp

#ifndef __lab1__Menu__
#define __lab1__Menu__

#include <stdio.h>
#include <iostream>
#include "System.hpp"

class Menu {
    
public:
    void startMenu();
    void userChoice(int input);
private:
    System console;     //Instance of the Weaglebook system
};

#endif /* defined(__lab1__Menu__) */

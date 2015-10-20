//
//  Time.cpp
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

#include "Time.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>


using namespace std;
//Function:     Time()
//Inputs:       None
//Outputs:      None
//Description:  Parameterless constructor for time. Creates time file if it doesn't exist.
//
Time::Time() {
    ofstream outputFile;
    string const timeFile = "time.txt";
    outputFile.open((timeFile).c_str(), ios::app);
}

//Function:     getTime()
//Inputs:       None
//Outputs:      int of current time
//Description:  retrieves the correct time from the time file. places what needs to be there in the file. 
//
int Time::getTime() {
    ifstream inputFile;
    string const timeFile = "time.txt";
    string timeHolder = "";
    inputFile.open((timeFile).c_str());
    while (!inputFile.eof()) {
        getline(inputFile, timeHolder);
    }
    inputFile.close();
    
    int timeInt = 0;
    string const timeHolderConstant = timeHolder;
    
    ofstream outputFile("time.txt", ios::app);
    
    if (timeHolder.compare("") != 0) {
        timeInt = atoi(timeHolderConstant.c_str());
        timeInt = timeInt + 1;
        outputFile << "\n" << timeInt;
        outputFile.flush();
        outputFile.close();
        return timeInt;
    }
    outputFile << "\n" << timeInt;
    outputFile.flush();
    outputFile.close();
    return timeInt;
}
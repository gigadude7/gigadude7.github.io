//
//  Message.cpp
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
//  Description:    This is the class that creates the Message, stores all of the data, and defines it's interactions.

#include "Message.hpp"
#include <sstream>


using namespace std;

//Function:     Message()
//Inputs:       string for name of the message owner, content of message, time the message was created
//Outputs:      None
//Description:  Constructor for the message. If the user's message file doesn't exist, it creates it.
//
Message::Message(string username, string content, int currentTime) {
    ofstream outputFile;
    outputFile.open((username + "Messages.txt").c_str(), ios::app); //opens file if it exists. If not, creates it.
    outputFile.flush();
    outputFile.close();
    string const tweetsFile = ("Tweets.txt");
    outputFile.open(tweetsFile.c_str(), ios::app);
    outputFile.flush();
    outputFile.close();
    messageOwner = username;        //name of user
    messageContent = content;       //message content
    messageTime = currentTime;      //message post time
}

//Function:     postMessage()
//Inputs:       None
//Outputs:      bool
//Description:  formats message and passes it to be stored. returns true if stored
//
bool Message:: postMessage() {
    string formattedMessage;
    string formattedTime;
    
    std::ostringstream oss; //for converting int to string
    oss << "{<" << messageTime << ">}";
    formattedTime = oss.str();
    
    formattedMessage = formattedTime + messageContent;
    
    return storeMessage(formattedMessage);
}

//Function:     tweetMessage()
//Inputs:       None
//Outputs:      bool
//Description:  formats message and passes it to be stored. returns true if stored
//
bool Message:: tweetMessage() {
    string formattedMessage;
    string formattedTime;
    string formattedName;
    
    std::ostringstream oss; //for converting int to string
    oss << "{<" << messageTime << ">}";
    formattedTime = oss.str();
    
    formattedName = "{[" + messageOwner + "]}";
    formattedMessage = formattedTime + formattedName;
    
    return storeTweet(formattedMessage);
}


//Function:     storeMessage()
//Inputs:       User inputs a message
//Outputs:      Void
//Description:  Parses a user's message and then, if it is valid, adds it to the messageBuffer.
//
bool Message:: storeMessage(string msg) {
    fstream inputFile;
    ofstream outputFile;
    if (msg.compare("") != 0) {
        ifstream ifile((messageOwner + "Messages.txt").c_str());	//checks to see if file exists.
        if (!ifile) {
            return false;
        }
        ifile.close();
        inputFile.open((messageOwner + "Messages.txt").c_str());
        string currentLine;
        string currentMessageHolder;
        while (!inputFile.eof()) {
            getline(inputFile, currentLine);               //gets line of file
            currentMessageHolder += currentLine + "\n";
        }
        inputFile.close();
        outputFile.open((messageOwner + "Messages.txt").c_str());
        outputFile << msg << "\n" << currentMessageHolder;
        outputFile.flush();
        outputFile.close();
        return true;
        
    }
    else {
        cout << "\nYour message had no content and was not logged.\n";
        return false;
    }
}
//Function:     storeTweet()
//Inputs:       User inputs a message
//Outputs:      Void
//Description:  Parses a user's message and then, if it is valid, adds it to the messageBuffer.
//
bool Message:: storeTweet(string msg) {
    fstream inputFile;
    ofstream outputFile;
    if (msg.compare("") != 0) {
        string const tweetFileName = "Tweets.txt";
        ifstream ifile(tweetFileName.c_str());	//checks to see if file exists.
        if (!ifile) {
            return false;
        }
        inputFile.open(tweetFileName.c_str());
        string currentLine;
        string currentMessageHolder;
        while (!inputFile.eof()) {
            getline(inputFile, currentLine);               //gets line of file
            cout << currentMessageHolder + "\n";
        }
        inputFile.close();
        outputFile.open(tweetFileName.c_str());
        outputFile << msg << "\n" << currentMessageHolder;
        outputFile.flush();
        outputFile.close();
        return true;
        
    }
    else {
        cout << "\nYour message had no content and was not logged.\n";
        return false;
    }
}


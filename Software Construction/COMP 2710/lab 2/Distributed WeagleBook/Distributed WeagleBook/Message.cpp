//
//  Message.cpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "Message.hpp"
#include <sstream>


using namespace std;

Message::Message(string username, string content, int currentTime) {
    ofstream outputFile;
    outputFile.open((username + "Messages.txt").c_str(), ios::app); //opens file if it exists. If not, creates it.
    outputFile.flush();
    outputFile.close();
    string const tweetsFile = ("Tweets.txt");
    outputFile.open(tweetsFile.c_str(), ios::app);
    outputFile.flush();
    outputFile.close();
    messageOwner = username;
    messageContent = content;
    messageTime = currentTime;
}


bool Message:: postMessage() {
    string formattedMessage;
    string formattedTime;
    
    std::ostringstream oss;
    oss << "{<" << messageTime << ">}";
    formattedTime = oss.str();
    
    formattedMessage = formattedTime + messageContent;
    cout << "\nThis is the formatted Message: " << formattedMessage;
    
    return storeMessage(formattedMessage);
}

bool Message:: tweetMessage() {
    string formattedMessage;
    string formattedTime;
    string formattedName;
    
    std::ostringstream oss;
    oss << "{<" << messageTime << ">}";
    formattedTime = oss.str();
    
    formattedName = "{[" + messageOwner + "]}";
    formattedMessage = formattedTime + formattedName;
    
    return storeMessage(formattedMessage);
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
            cout << currentMessageHolder + "\n";
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


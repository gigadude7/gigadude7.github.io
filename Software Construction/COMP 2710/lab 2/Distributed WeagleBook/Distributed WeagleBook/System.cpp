//
//  System.cpp
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
//  Description:    This is the function that effectively calls the other functions and gets them to interface with each other. 
#include "System.hpp"
#include <list>

//Function:     System
//Inputs:       User for the current User
//Outputs:      None
//Description:  Constructor for the System object
//
System::System(User user){
    currentUser = user;     //sets passedin user to the current user for the system
    newTime = Time();       //creates a new time and stores it as the current time
}

//Function:     addFriend()
//Inputs:       None
//Outputs:      Bool
//Description:  Adds a friend to the User's friend list. If it does, it returns true.
//
bool System::addFriend() {
    std::string fndName;    //holder for friend's name
    cout << "\n Please enter the name of the friend you would like to add: ";
    cin.clear();
    cin.ignore(10000, '\n');
    string messageToken;
    getline(cin, messageToken);
    if (currentUser.addFriend(messageToken)) {
        cout << "\n\nFriend added\n";
        return true;
    }
    else {
        cout << "\n\nA user by that name could not be found.\n";
        return false;
    }
}

//Function:     postMessage()
//Inputs:       None
//Outputs:      Bool
//Description:  Posts the User's message. If it does, returns true.
//
bool System::postMessage(){
    std::string message = "";                   //string to store the user's message
    cout << "\n   Please enter your message:";
    cin.clear();
    cin.ignore(10000, '\n');
    while (true){
        string messageToken;
        getline(cin, messageToken);             //uses a disposable message token to store each word
        
        if (messageToken.compare("!!") == 0) {
            break;                              //exits when the "escape sequence" has been entered
        }
        message += messageToken + "\n";
    }
    Message tempMessage = Message(currentUser.name, message, newTime.getTime());
    return tempMessage.postMessage();
}

//Function:     tweetMessage()
//Inputs:       None
//Outputs:      Bool
//Description:  Tweets the User's message. If it does, returns true.
//
bool System::tweetMessage() {
    std::string message = "";                   //string to store the user's message
    cout << "\n   Please enter your message:";
    cin.clear();
    cin.ignore(10000, '\n');
    while (true){
        string messageToken;
        getline(cin, messageToken);             //uses a disposable message token to store each word
        
        if (messageToken.compare("!!") == 0) {
            break;                              //exits when the "escape sequence" has been entered
        }
        message += messageToken + "\n";
    }
    
    Message tempMessage = Message(currentUser.name, message, newTime.getTime());
    return tempMessage.tweetMessage();
}

//Function:     displayWall()
//Inputs:       None
//Outputs:      Bool
//Description:  Gets the Users messages and displays them as a wall page.
//
void System::displayWall() {
    string currentLine;                                                         //string holder
    cout<< "===============================================\n";
    cout<< "        Welcome to " <<  currentUser.name <<"'s Wall Page!\n";
    cout<< "===============================================\n";
    
    string const fileName = (currentUser.name + "Messages.txt");                //string for name of the user's messages file
    ifstream inputFile(fileName.c_str());
    if (!inputFile){
        cout << "\nYou seem to have no messages! Pleaser enter messages or try a different command!\n";
    }
    
    else {
        string currentLine;                             //string holder
        bool continueCheck = false;                     //bool to help decide when to break the loop
        int displayedMessages = 0;                      //int that helps keep track of # of displayed messages
        while (!inputFile.eof() && !continueCheck) {
            getline(inputFile, currentLine);
            if (currentLine.compare("") != 0) {
                size_t endOfTime = currentLine.find(">}");      //location of start of message
                currentLine = currentLine.substr(endOfTime + 2);
                
                cout << currentLine << "\n";
                displayedMessages++;
            }
            if (displayedMessages == 2) {
                string userChoice;                      //string holder
                cout << "\nDisplay more messages? (yes/no) > ";
                cin.clear();
                std::cin.ignore(10000, '\n');
                getline(cin, userChoice);
                displayedMessages++;
                
                if (userChoice.compare("no") == 0) {
                    continueCheck = true;
                }
                
            }
        }
        
    }
    inputFile.close();
}

//Function:     displayHome()
//Inputs:       None
//Outputs:      void
//Description:  Gets the messages from the User's frineds and all the tweets and then displays them on the home page.
//
void System::displayHome() {
    string currentLine;         //string holder
    string homePageString;      //string holder
    cout<< "===============================================\n";
    cout<< "        Welcome to " <<  currentUser.name <<"'s Home Page!\n";
    cout<< "===============================================\n";
    
    list<string> messages;
    ofstream outputFile ("homePage.txt");
    
    ifstream inputFile ("Tweets.txt");
    if (inputFile) {
        while (!inputFile.eof()) {
            getline(inputFile, currentLine);
            if (currentLine.compare("") != 0) {
                size_t endOfTime = currentLine.find(">}");          //when time ends
                size_t startOfTime = currentLine.find("{<");        //when time starts
                int timeRange = (int) (endOfTime - startOfTime);    //how long time is
                
                size_t endOfName = currentLine.find("]}");          //when name ends
                size_t startOfName = currentLine.find("{[");        //when name starts
                int nameRange = (int) (endOfName - startOfName);    //how long name is
                
                string name = currentLine.substr(startOfName + 2, nameRange);   //message name
                string time = currentLine.substr(startOfTime + 2, timeRange);   //message time
                string message = currentLine.substr(endOfTime + 2);             //message content
                
                string formattedString = time + ">} " + name + ": " + message;  //formatted message for the output file
                
                outputFile << formattedString;
            }
            
        }
    }
    inputFile.close();
    for (std::list<string>::iterator it=currentUser.friends.begin(); it != currentUser.friends.end(); ++it) {
        string friendName = it->substr(0); //gets name of friend
        ifstream friendFile (friendName + "Messages.txt");  //opens frinds messages
        
        //reads friend's messages
        while (!friendFile.eof()) {
            if (currentLine.compare("") != 0) {
                getline(friendFile, currentLine);
                
                size_t endOfTime = currentLine.find(">}");      //where time ends
                size_t startOfTime = currentLine.find("{<");    //where time begins
                int timeRange = (int) (endOfTime - startOfTime);
                
                string name = friendName;   //name of friend
                string time = currentLine.substr(startOfTime + 2, timeRange); //time message was posted
                string message = currentLine.substr(endOfTime + 2);           //message that was posted
                
                string formattedString = time + ">} " + name + ": " + message; //formatted message for outputfile
                
                outputFile << formattedString;
            }
            
        }
    }
    outputFile.flush();
    outputFile.close();
    
    string tempString;              //string holder
    bool continueCheck = false;     //bool for while loop
    int displayedMessages = 0;      //helps keep track of displayed messages
    ifstream homePage ("homePage.txt");     //stream for the homePage messages
    
    while (!homePage.eof() && !continueCheck) {
        getline(homePage, tempString);
        if (tempString.compare("") != 0) {
            cout << tempString << "\n";
            displayedMessages++;
        }
        if (displayedMessages == 2) {
            string userChoice;
            cout << "\nDisplay more messages? (yes/no) > ";
            cin.clear();
            std::cin.ignore(10000, '\n');
            getline(cin, userChoice);
            displayedMessages++;
            
            if (userChoice.compare("no") == 0) {
                continueCheck = true;
            }
            
        }
    }
    homePage.close();
    
}
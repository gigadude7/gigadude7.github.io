//
//  System.cpp
//  Distributed WeagleBook
//
//  Created by Grant Hamilton Cordle on 10/12/15.
//  Copyright © 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "System.hpp"

System::System(User user){
    currentUser = user;
    newTime = Time();
}

bool System::addFriend() {
    std::string fndName;
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
    cout << "This is the message content:" << message;
    Message tempMessage = Message(currentUser.name, message, newTime.getTime());
    return tempMessage.postMessage();
}

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

void System::displayWall() {
    string currentLine;
    cout<< "===============================================\n";
    cout<< "        Welcome to " <<  currentUser.name <<"'s Wall Page!\n";
    cout<< "===============================================\n";
    
    string const fileName = (currentUser.name + "Messages.txt");
    ifstream inputFile(fileName.c_str());
    if (!inputFile){
        cout << "\nYou seem to have no messages! Pleaser enter messages or try a different command!\n";
    }
    else {
        string const inputFileName = (currentUser.name + "Messages.txt");
        inputFile.open(inputFileName.c_str());
        if (!inputFile.eof()) {
            getline(inputFile, currentLine);
            string currentMessage = currentLine.substr(4 + currentUser.name.length()); //retrives just the message
            cout << currentMessage + "\n";		   //prints line of file
        }
        if (!inputFile.eof()) {
            getline(inputFile, currentLine);
            string currentMessage = currentLine.substr(4 + currentUser.name.length()); //retrives just the message
            cout << currentMessage + "\n";		   //prints line of file
        }
        if (getline(inputFile, currentLine)) {
            string userChoice;
            cout << "\nDisplay more messages? (yes/no) > ";
            cin.clear();
            std::cin.ignore(10000, '\n');
            getline(cin, userChoice);
            
            if (userChoice.compare("yes") == 0) {
                while (getline(inputFile, currentLine)) {
                    string currentMessage = currentLine.substr(4 + currentUser.name.length()); //retrives just the message
                    cout << currentMessage + "\n";		   //prints line of file
                }
            }
        }
    }
}

void System::displayHome() {
//    string currentLine;
//    string homePageString;
//    cout<< "===============================================\n";
//    cout<< "        Welcome to " <<  currentUser.name <<"'s Home Page!\n";
//    cout<< "===============================================\n";
//    
//    //bool find = false; //Bool that stores if the message's poster is in the friends list
//    
//    for (std::list<string>::iterator it=currentUser.friends.begin(); it != currentUser.friends.end(); ++it) {
//        ifstream iFile(*it + ".txt");
//        if (iFile) {
//            ifstream inputFile;
//            inputFile.open(*it + ".txt");
//            while (getline(inputFile, currentLine)) {
//                homePageString += currentLine + "\n";
//            }
//            inputFile.close();
//        }
//    }
//    
//    ifstream tweetFile("Tweets.txt");
//    if (tweetFile) {
//        ifstream newFile;
//        newFile.open("Tweets.txt");
//        while (getline(newFile, currentLine)) {
//            homePageString += currentLine + "\n";
//        }
//        newFile.close();
//    }
    
    
    
    
    
    
    //        size_t startOfName = it->find("{[");
    //        size_t endOfName = it->find("]}");
    //        size_t startOfTime = it ->find("{<");
    //        size_t endOfTime = it->find(">}");
    //        int nameLength = (int) (endOfName - startOfName -2);
    //        int timeLength = (int) (endOfTime - startOfName -2);
    //        string messageTime = it->substr(2, timeLength);
    //        string messageName = it->substr(endOfTime + 2, nameLength); //4 might not be the right number here.
    
    //        if (currentUser.friends.size() != 0)
    //            find = (std::find(currentUser.friends.begin(), currentUser.friends.end(), messageName) != currentUser.friends.end());
    //
    //        if (currentUser.name == messageName)
    //            find = true;
    //
    //        if (find) {
    //            <#statements#>
    //        }
    
    
}

//
//    list<string>friendsMessages;
//    list<string>friendNames = currentUser.usersFriends();
//    bool find = false;  //Bool that stores if the message's poster is in the friends list
//
//    for (std::list<string>::iterator it=messageBuffer.begin(); it != messageBuffer.end(); ++it) {
//        //if the message is from a friend OR is a tweet
//        std::size_t isATweet = it->find("::tweet");             //location of the string '::tweet' in the message
//        std::size_t startOfName = it->find("{[");               //location of the string '{[' in the message
//        std::size_t endOfName = it->find("]}");                 //location of the string ']}' in the message
//        int nameLength = (int) (endOfName - startOfName -2);    //length of the User's name
//        string messageName = it->substr(2, nameLength);         //length of the message
//
//        //check to see if msgName is an element of friendNames
//        if (friendNames.size() != 0){
//            find = (std::find(friendNames.begin(), friendNames.end(), messageName) != friendNames.end());
//        }
//    








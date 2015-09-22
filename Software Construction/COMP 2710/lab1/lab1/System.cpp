//
//  System.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "System.h"
#include <algorithm>

using namespace std;
System::System() {
   User currentUser = User();
}

void System:: createNewUser() {
    string userName;
    cout << "Enter user Name> ";
    cin >> userName;
    
    User newUser = User(userName);
    
    if (!isLoggedIn)
        login(newUser);
    
    registeredUsers.push_front(newUser);
    //printRegisteredUsers();   //see if the list is working properly
}

void System:: postMessage() {
    std::string message = "";
    while (true){
        string messageToken;
        getline(cin, messageToken);             //uses a disposable message token to store each word
        
        if (messageToken.compare("!!") == 0) {
            break;                              //exits when the "escape sequence" has been entered
        }
        message += messageToken + "\n";
    }
    
    Message newMessage = Message(currentUser, message, false);
    messageBuffer.push_front(newMessage);
}

void System:: tweetMessage() {
    std::string message = "";
    while (true){
        string messageToken;
        getline(cin, messageToken);             //uses a disposable message token to store each word
        
        if (messageToken.compare("!!") == 0) {
            break;                              //exits when the "escape sequence" has been entered
        }
        message += messageToken + "\n";
    }
    
    Message newMessage = Message(currentUser, message, true);
    messageBuffer.push_front(newMessage);
    
}

void System:: displayHome() {
    
}

void System:: displayWall() {
    
}

void System:: addFriend() {
    string userName;
    cout << "Enter user's Name> ";
    cin >> userName;
    
    User newUser = User(userName);
    
    bool find = (std::find(registeredUsers.begin(), registeredUsers.end(), newUser) != registeredUsers.end());
    
    if (find) {
        //add to friend list
    }
    else {
        cout << "\nA user by that name could not be found. Try a different name or do something else.\n";
    }
}

void System:: switchUsers() {
    string userName;
    cout << "Enter user's Name> ";
    cin >> userName;
        
    User newUser = User(userName);
    
    bool find = (std::find(registeredUsers.begin(), registeredUsers.end(), newUser) != registeredUsers.end());
    
    if (find) {
        login(newUser);
        cout<< "\nWelcome to WeagleBook " << newUser.getName() << "\n"; 
    }
    else {
        cout << "\nA user by that name could not be found. Try a different name or do something else.";
    }
    
}

void System:: quitWeagleBook() {
    cout << "\nThank you for Using WeagleBook.\nSee you next time!\n\n";
    exit(EXIT_SUCCESS);
}

//Methods for development
void System:: printRegisteredUsers() {
    for (User &u : registeredUsers){
        cout << "\n" << u.getName() << "\n";
    }
}

void System:: login(User user) {
    currentUser = user;
}
//
//  System.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "System.hpp"
#include <algorithm>
#include <list>

using namespace std;
System::System() {
    User currentUser = User();
    isLoggedIn = false;
}

void System:: createNewUser() {
    string userName;
    cout << "\n   Enter user Name> ";
    cin >> userName;
    
    User newUser = User(userName);
    
    bool find = (std::find(registeredUsers.begin(), registeredUsers.end(), newUser) != registeredUsers.end());
    
    
    if (!find) {
        if (!isLoggedIn)
            login(newUser);
        
        registeredUsers.push_front(newUser);
    }
    else {
    
    cout << "\nA user by the name of: " << newUser.getName() << " has alredy been registered, please use a different name.";
    }
    //printRegisteredUsers();   //see if the list is working properly
}

void System:: postMessage() {
    std::string message = "";
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
    
    if (message.compare("") != 0) {
        Message newMessage = Message(currentUser, message, false);
        messageBuffer.push_front(newMessage.buildMessage());
    }
    else {
        cout << "\nYour message had no content and was not logged.\n";
    }
}

void System:: tweetMessage() {
    std::string message = "";
    cout<< "\n   Please enter your message:";
    while (true){
        string messageToken;
        getline(cin, messageToken);             //uses a disposable message token to store each word
        
        if (messageToken.compare("!!") == 0) {
            break;                              //exits when the "escape sequence" has been entered
        }
        message += messageToken + "\n";
    }
    
    Message newMessage = Message(currentUser, message, true);
    messageBuffer.push_front(newMessage.buildMessage());
    
}

void System:: displayHome() {
    
    cout<< "\n===============================================\n";
    cout<< "       Now Displaying " << currentUser.getName() << "'s Home Page\n";
    cout<< "===============================================\n";
    HomePage wall = HomePage();
    list<string>friendsMessages;
    list<string>friendNames = currentUser.usersFriends();
    bool find = false;
    
    for (std::list<string>::iterator it=messageBuffer.begin(); it != messageBuffer.end(); ++it) {
        //if the message is from a friend OR is a tweet
        std::size_t isATweet = it->find("::tweet");
        std::size_t startOfName = it->find("{[");
        std::size_t endOfName = it->find("]}");
        int nameLength = (int) (endOfName - startOfName -2);
        string messageName = it->substr(2, nameLength);
        
        //check to see if msgName is an element of friendNames
        if (friendNames.size() != 0){
            find = (std::find(friendNames.begin(), friendNames.end(), messageName) != friendNames.end());
        }
        
        if (messageName.compare(currentUser.getName()) == 0) {
            find = true;
        }
        
        if (isATweet < it->size()) {
            it->replace(isATweet, 9, ":");
            it->replace(startOfName, 2, "");
            friendsMessages.push_back((*it));
        }
        
        else if (find) {
            it->replace(endOfName, 2, ":\n");
            it->replace(startOfName, 2, "");
            friendsMessages.push_back(*it);
            
        }
    }
    
    if (messageBuffer.size() == 0) {
        cout << "\nThere are no messages from you or your friends!\n";
    }
    
    else {
        if (friendsMessages.size() == 1) {
            cout << "\n" << friendsMessages.front();
            friendsMessages.pop_front();
        }
        
        else if (friendsMessages.size() == 2) {
            cout << "\n" << friendsMessages.front();
            friendsMessages.pop_front();
            cout << "\n" << friendsMessages.front();
            friendsMessages.pop_front();
        }
        
        else if (friendsMessages.size() > 2) {
            string userChoice;
            cout << "\n" << friendsMessages.front();
            friendsMessages.pop_front();
            cout << "\n" << friendsMessages.front();
            friendsMessages.pop_front();
            cout << "\nDisplay more messages? (yes/no) > ";
            cin.clear();
            std::cin.ignore(10000, '\n');
            getline(cin, userChoice);
            
            if (userChoice.compare("yes") == 0) {
                wall.shouldDisplayMore(true);
            }
            
            if (wall.getDisplayMore()) {
                while (!friendsMessages.empty()) {
                    cout << "\n" << friendsMessages.front();
                    friendsMessages.pop_front();
                }
            }
        }
    }
}

void System:: displayWall() {
    
    cout<< "===============================================\n";
    cout<< "        Welcome to " <<  currentUser.getName() <<"'s Wall Page!\n";
    cout<< "===============================================\n";
    
    
    WallPage wall = WallPage();
    list<string>userMessages;
    
    for (std::list<string>::iterator it=messageBuffer.begin(); it != messageBuffer.end(); ++it) {
        if (it->substr(2, currentUser.getName().length()).compare(currentUser.getName()) == 0) {
            std::size_t restOfString =  it->find("]}");
            userMessages.push_back(it->substr(restOfString + 2));
        }
    }
    
    if (messageBuffer.size() == 0) {
        cout << "\nThere are no messages from this user!\n";
    }
    
    else {
        if (userMessages.size() == 1) {
            cout << "\n" << userMessages.front();
            userMessages.pop_front();
        }
        
        else if (userMessages.size() == 2) {
            cout << "\n" << userMessages.front();
            userMessages.pop_front();
            cout << "\n" << userMessages.front();
            userMessages.pop_front();
        }
        
        else if (userMessages.size() > 2) {
            string userChoice;
            cout << "\n" << userMessages.front();
            userMessages.pop_front();
            cout << "\n" << userMessages.front();
            userMessages.pop_front();
            cout << "\nDisplay more messages? (yes/no) > ";
            cin.clear();
            std::cin.ignore(10000, '\n');
            getline(cin, userChoice);
            
            if (userChoice.compare("yes") == 0) {
                wall.shouldDisplayMore(true);
            }
            
            if (wall.getDisplayMore()) {
                while (!userMessages.empty()) {
                    cout << "\n" << userMessages.front();
                    userMessages.pop_front();
                }
            }
        }
    }
}



void System:: addFriend() {
    string userName;
    cout << "Enter user's Name> ";
    cin >> userName;
    
    User newUser = User(userName);
    
    bool find = (std::find(registeredUsers.begin(), registeredUsers.end(), newUser) != registeredUsers.end());
    
    if (find) {
        currentUser.friends.addFriend(newUser);
    }
    else {
        cout << "\nA user by that name could not be found. Try a different name or do something else.\n";
    }
}

void System:: displayFriends() {
    currentUser.friends.returnFriends();
}

void System:: switchUsers() {
    string userName;
    cout << "Enter user's Name> ";
    cin >> userName;
    
    User newUser = User(userName);
    
    bool find = (std::find(registeredUsers.begin(), registeredUsers.end(), newUser) != registeredUsers.end());
    
    if (find) {
        currentUser = newUser;
        cout<< "\n===============================================\n";
        cout<< "   Welcome back to WeagleBook: " << newUser.getName() << "   \n";
        cout<< "===============================================\n";
        
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
    for (std::list<User>::iterator it=registeredUsers.begin(); it != registeredUsers.end(); ++it) {
        cout << "\n" << it->getName() << "\n";
    }
    
}

void System:: login(User user) {
    currentUser = user;
    cout<< "\n\n\n===============================================\n";
    cout<< "       Welcome to WeagleBook:" << currentUser.getName() << "        \n";
    cout<< "===============================================\n";
}
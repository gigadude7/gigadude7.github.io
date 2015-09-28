//
//  System.cpp
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
//  Description:    This program is made to handle all of the different inputs from the Menu class.





#include "System.hpp"
#include <algorithm>
#include <list>

using namespace std;

//Function:     System
//Inputs:       None
//Outputs:      None
//Description:  Constructor for System
//
System::System() {
    User currentUser = User();
    isLoggedIn = false;
}

//Function:     createNewUser()
//Inputs:       User inputs a name
//Outputs:      Void
//Description:  Creates a new "User" object based on input from a user. It then logs the user in.
//
void System:: createNewUser() {
    string userName;                    //Used to store the User name
    cout << "\n   Enter user Name> ";
    cin >> userName;
    
    User newUser = User(userName);      //Used to store the new User
    
    bool find = (std::find(registeredUsers.begin(), registeredUsers.end(), newUser) != registeredUsers.end());      //If the User is already registered, stores true
    
    
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

//Function:     postMessage()
//Inputs:       User inputs a message
//Outputs:      Void
//Description:  Parses a user's message and then, if it is valid, adds it to the messageBuffer.
//
void System:: postMessage() {
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
    
    if (message.compare("") != 0) {
        Message newMessage = Message(currentUser, message, false);  //
        messageBuffer.push_front(newMessage.buildMessage());
    }
    else {
        cout << "\nYour message had no content and was not logged.\n";
    }
}

//Function:     tweetMessage()
//Inputs:       User enters a message
//Outputs:      Void
//Description:  Parses a user's message and, if it is valid, adds it to the message buffer.
//
void System:: tweetMessage() {
    std::string message = "";                   //string to store the User's message
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

//Function:     displayHome()
//Inputs:       None
//Outputs:      Void
//Description:  Displays the User's home page. The home page consists of messages from friends, tweets from friends, and tweets from non friends.
//
void System:: displayHome() {
    
    cout<< "\n===============================================\n";
    cout<< "       Now Displaying " << currentUser.getName() << "'s Home Page\n";
    cout<< "===============================================\n";
    HomePage wall = HomePage(); //an instance of HomePage so that I can manipulate it
    list<string>friendsMessages;
    list<string>friendNames = currentUser.usersFriends();
    bool find = false;  //Bool that stores if the message's poster is in the friends list
    
    for (std::list<string>::iterator it=messageBuffer.begin(); it != messageBuffer.end(); ++it) {
        //if the message is from a friend OR is a tweet
        std::size_t isATweet = it->find("::tweet");             //location of the string '::tweet' in the message
        std::size_t startOfName = it->find("{[");               //location of the string '{[' in the message
        std::size_t endOfName = it->find("]}");                 //location of the string ']}' in the message
        int nameLength = (int) (endOfName - startOfName -2);    //length of the User's name
        string messageName = it->substr(2, nameLength);         //length of the message
        
        //check to see if msgName is an element of friendNames
        if (friendNames.size() != 0){
            find = (std::find(friendNames.begin(), friendNames.end(), messageName) != friendNames.end());
        }
        
        if (messageName.compare(currentUser.getName()) == 0) {
            find = true;
        }
        
        if (isATweet < it->size()) {
            it->replace(isATweet, 9, ":");      //replaces the tweet string with a colon
            it->replace(startOfName, 2, "");    //removes the '{[' string
            friendsMessages.push_back((*it));   //places the message onto the back of the displayed message queue
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
            string userChoice;                      //stores yes or no depending on the user's answer
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

//Function:     displayWall()
//Inputs:       None
//Outputs:      Void
//Description:  Displays a User's wall page. It contains messages from that User
//
void System:: displayWall() {
    
    cout<< "===============================================\n";
    cout<< "        Welcome to " <<  currentUser.getName() <<"'s Wall Page!\n";
    cout<< "===============================================\n";
    
    
    WallPage wall = WallPage();     //instance of the User's wall page
    list<string>userMessages;       //list to store User's messages that should be shown
    
    for (std::list<string>::iterator it=messageBuffer.begin(); it != messageBuffer.end(); ++it) {
        if (it->substr(2, currentUser.getName().length()).compare(currentUser.getName()) == 0) {
            std::size_t restOfString =  it->find("]}");             //finds the length of the message w/o the name
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


//Function:     addFriend()
//Inputs:       Name of Potential friend
//Outputs:      Void
//Description:  Asks the user for the name of a friend and, if it is the name of a valid user, adds the friend to their friend list.
//
void System:: addFriend() {
    string userName;
    cout << "Enter user's Name> ";
    cin >> userName;
    
    User newUser = User(userName); //makes a user instance with the current name
    
    bool find = (std::find(registeredUsers.begin(), registeredUsers.end(), newUser) != registeredUsers.end()); //stores yes if the user is a member of the total registered users
    
    if (find) {
        currentUser.friends.addFriend(newUser);
    }
    else {
        cout << "\nA user by that name could not be found. Try a different name or do something else.\n";
    }
}

//Function:     displayFriends()
//Inputs:       None
//Outputs:      A list of the user's friends
//Description:  outputs an easy to read list of the current user's friends
//
void System:: displayFriends() {
    currentUser.friends.returnFriends();
}

//Function:     switchUsers()
//Inputs:       Name of User to swap to
//Outputs:      Void
//Description:  Reads a potentially new user and, if the user is a registered user, logs in into that user
//
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

//Function:     quitWeagleBook()
//Inputs:       None
//Outputs:      Void
//Description:  Ends the WeagleBook Program
//
void System:: quitWeagleBook() {
    cout << "\nThank you for Using WeagleBook.\nSee you next time!\n\n";
    exit(EXIT_SUCCESS);
}

//Methods for development

//Function:     printRegisteredUsers()
//Inputs:       None
//Outputs:      A list of Users
//Description:  Presents the list of all registered users. Not currently accessable to the User.
//
void System:: printRegisteredUsers() {
    for (std::list<User>::iterator it=registeredUsers.begin(); it != registeredUsers.end(); ++it) {
        cout << "\n" << it->getName() << "\n";
    }
    
}

//Function:     login()
//Inputs:       User to be logged in
//Outputs:      Void
//Description:  Logs the user in
//
void System:: login(User user) {
    currentUser = user;
    cout<< "\n\n\n===============================================\n";
    cout<< "       Welcome to WeagleBook:" << currentUser.getName() << "        \n";
    cout<< "===============================================\n";
}
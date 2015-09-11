//
//  Program Name:   Homework1.cpp
//  Name:           Grant H Cordle
//  Class:          COMP 2710-002
//  Date:           Sept. 8, 2015
//  E-Mail:         ghc0001@auburn.edu
//
//  Description: This program will continually prompt a user for a username and a message
//               in order to create a virtual bulletin board. The required inputs are
//               strings. One that contains a user's name and one that containes the message
//               they wish to post. To end a message entry, use the string "!!" on a new line.
//


#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    
    string messageBuffer;       //stores the message
    string userName;            //stores the current username
    string message;             //stores the current message
    string moreUsersPrompt;     //what the user enters when they want to exit inputting
    bool areMoreUsers = true;   //bool value to hold moreUsersPrompt
    string header = "==================================================\n|      Welcome to the Aubie Message System!      |\n==================================================\n\n"; 
	
	cout << header; 
	
    do {
        userName = "";
        message = "";
        moreUsersPrompt = "";
        
        std::cout << "Enter user Name> ";
        cin >> userName;
        userName = "{[" + userName + "]}";
        
        std::cout << "Enter the message> ";
        while (true){
            string messageToken;
            getline(cin, messageToken);             //uses a disposable message token to store each word
            
            if (messageToken.compare("!!") == 0) {
                break;                              //exits when the "escape sequence" has been entered
            }
            message += messageToken + "\n";
        }
        
        messageBuffer = userName + message + messageBuffer;
        
        std::cout << "\nAny more users? > ";
        cin >> moreUsersPrompt;
        
        //this for loop makes the user's entry lowercase
        for (int i = 0; i < moreUsersPrompt.size(); i++) {
            moreUsersPrompt[i] = tolower(moreUsersPrompt[i]);
        }
        
        if (moreUsersPrompt.compare("no") == 0) {
            areMoreUsers = false;
        }
		
		cout << "\n"; 
        
    } while (areMoreUsers);
    
    float messageBufferIndex = 0.0;                     //keep track of where you are in the message
    float foundAtIndex;                                 //if something has been found, store it's location here
    
    while (messageBufferIndex < messageBuffer.size()) {
        foundAtIndex = messageBuffer.find("{[");
        
        //if the .find cannot find the char, it sets to the max float value. Breaks so that the loop
        //does not continue an additional time
        if (foundAtIndex >= messageBuffer.size()) {
            break;
        }
        messageBuffer.replace(foundAtIndex, 2, "\n");
        messageBufferIndex = foundAtIndex;
    }
    
    //resets the variables so that I can use them again w/o declaring new ones.
    messageBufferIndex = 0.0;
    foundAtIndex = -1.0; 
    
    while (messageBufferIndex < messageBuffer.size()) {
        foundAtIndex = messageBuffer.find("]}");
        
        //if the .find cannot find the char, it sets to the max float value. Breaks so that the loop
        //does not continue an additional time
        if (foundAtIndex >= messageBuffer.size()) {
            break;
        }
        messageBuffer.replace(foundAtIndex, 2, ":");
        messageBufferIndex = foundAtIndex; 
    }

    cout << "The current Messages are:\n" << messageBuffer; 
    
}

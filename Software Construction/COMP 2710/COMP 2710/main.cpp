//
//  main.cpp
//  COMP 2710
//
//  Created by Grant Hamilton Cordle on 8/27/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#include <iostream>
#include <string>

#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    string username = "Paul";
    string message = "Please join our Aubie message group!";
    string message_buffer;
    string username2 = "Martha";
    string message2 = "Wazzup!";
    string message3 = "Go Tiger";
    string message4 = "Glory to Auburn!";
    
    message_buffer = "{[" + username2 + "]}" + message2 + "{[" + username + "]}" + message;
    
    long startIndex = message_buffer.find("{[");
    long endIndex = message_buffer.find("]}");
    
    string firstFoundUsername = message_buffer.substr(startIndex + 2, endIndex - 2);
    
        if (startIndex >= 0 && endIndex >= 0) {
    		long secondStartIndex = message_buffer.find("{[", startIndex + 2); //starts the search right after the first one has been found.
            long secondEndIndex = message_buffer.find("]}", endIndex + 2);
            long secondUsernameLength = secondEndIndex - secondStartIndex;
            
            string secondFoundUserName = message_buffer.substr(secondStartIndex + 2, secondUsernameLength - 2);
    	}
    
    long startMessageIndex = message_buffer.find("]}");
    long endMessageIndex = message_buffer.find("{[");
    long messageLength = startMessageIndex - endMessageIndex - 2;
    
    string firstFoundMessage = message_buffer.substr(startMessageIndex + 2, messageLength);
    string secondFoundMessage;
    
    if (startMessageIndex >= 0) {
        long secondMessageStartIndex = message_buffer.find("]}", startMessageIndex + 2);
        long secondMessageEndIndex = message_buffer.find("{[");
        long secondMessageLength = (secondMessageEndIndex != 0) ? secondMessageEndIndex - secondMessageStartIndex : 0;
        
        secondFoundMessage = (secondMessageLength == 0) ? message_buffer.substr(secondMessageStartIndex + 2) : message_buffer.substr(secondMessageStartIndex, secondMessageLength);
    }
    

    
   // cout << message_buffer << "\n" << startIndex << "\n" << firstFoundMessage << "\n\n" << secondFoundMessage;
    
    string messagebuffer;
//    cin >> messagebuffer;
//    cout << messagebuffer;
    getline(cin, messagebuffer);
    cout << messagebuffer;
    
    
    
}

//
//  Menu.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#include "Menu.hpp"

#include <iostream>


void Menu::startMenu() {
    std::cout << "\n1) Create a new user\n2) Post a message\n3) Tweet a message \n4) Display Wall page \n5) Display Home page \n6) Add a friend \n7) Switch to a different user \n8) Display Friends \n9) Quit WeagleBook\n\n   Please Choose an Option:";
}

void Menu::userChoice(int input) {
    switch (input) {
        case 1:
            console.createNewUser();
            break;
        case 2:
            console.postMessage();
            break;
        case 3:
            console.tweetMessage(); 
            break;
        case 4:
            console.displayWall();
            break;
        case 5:
            console.displayHome();
            break;
        case 6:
            console.addFriend(); 
            break;
        case 7:
            console.switchUsers(); 
            break;
        case 8:
            console.displayFriends();
            break;
        case 9:
            console.quitWeagleBook();
        default:
            std::cout<< "Not a valid input! Please enter a whole number between 1 and 9";
            break;
    }
}
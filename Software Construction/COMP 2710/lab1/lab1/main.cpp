//
//  main.cpp
//  lab1
//
//  Created by Grant Hamilton Cordle on 9/20/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#include <iostream>
#include "Menu.h"

using namespace std;
int main(int argc, const char * argv[]) {
    Menu menu;
    bool exit = false;
    while (!exit) {
        while (true) {
            int userChoice;
            
            menu.startMenu();
            std::cin >> userChoice;
            
            if (userChoice == 8)
                exit = true;
            
            if (!std::cin.fail()) {
                menu.userChoice(userChoice);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            else {
                std::cout << "\n\nPlease enter a whole number between 1 and 8!\n\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }

    
    //thanks for using weaglebook*+
    
}

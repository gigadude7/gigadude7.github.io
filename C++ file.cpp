//
//  C++ file.cpp
//  
//
//  Created by Grant Hamilton Cordle on 8/27/15.
//
//

#include "C++ file.h"
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int x = 1;
    int y = 0;
    if ((x) && (++y)) {
        cout << "Hello\n";
    }
    else {
        cout << "lol nope\n";
    }
    
    int i = 0;
    do {
        cout << i << "\n";
        i++;
    } while (i < 0);
    
    int first;
    int second;
    first = (first = 2, second = first + 3);
    
    cout << first << "\n" << second;
    
}
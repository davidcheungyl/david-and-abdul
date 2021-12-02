#ifndef SKELETON_H
#define SKELETON_H

#include <iostream>
#include <string>

using namespace std;

// The upper() function converts a given string to uppercase.
string upper(string str);

// The type() function uses usleep() to give a smooth typing effect to the output of the game for aesthetics
void type(string str);

// The printDiamond() function prints out a diamond logo on the screen for aesthetics
void printDiamond();

// The startingGame() function, as the name suggests, starts the game and displays the initial screen to the user
string startingGame();

#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "skeleton.h"

using namespace std;

// The lifelines() function checks for available lifelines and informs the player of this
void lifelines(string name, bool &fifty, bool &call, bool &ask);

// The quitGame() function handles the situation when the user wants to quit the game
void quitGame(string name, int ques, string value);

#endif
#ifndef LIFELINES_H
#define LIFELINES_H

#include "skeleton.h"
#include "functions.h"

using namespace std;

// The fiftyFifty() function handles the case for the 50-50 lifeline.
void fiftyFifty(string name, string answer);

// The phoneOrAsk() function handles the cases for the using the 'Phone a Friend' lifeline or 'Ask the Audience'
void phoneOrAsk(string name, string answer, string life);

// The secondChance() function handles the case when the user wants to use the second chance lifeline
void secondChance(string name, int ques, string answer, int &indVal, int &indAns, string values[], string total);

#endif
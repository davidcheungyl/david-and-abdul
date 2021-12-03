// This file is the lifelines program file, which defines functions for the lifelines

#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>

#include "skeleton.h"
#include "functions.h"

using namespace std;

// The fiftyFifty() function handles the case for the 50-50 lifeline.
// It takes in the name of the player and the answer to the question
// It returns nothing but prints out two incorrect options to facilitate the player in answering 
void fiftyFifty(string name, string answer){
    type("\nOk, so " + name + ", you have chosen the fifty-fifty lifeline");
    type("You will now be shown two incorrect options to help you narrow down your search");

    // Removing options C and D if any of A or B is correct
    if (answer == "A" || answer == "B"){
        type("\nYou may ignore options (c) and (d)\n");
    }

    // Removing options A and B if any of C or D is correct
    else if (answer == "C" || answer == "D"){
        type("\nOptions (a) and (b) are wrong, and you may proceed by ignoring them.\n");
    }
}

// The phoneOrAsk() function handles the cases for the using the 'Phone a Friend' lifeline or 'Ask the Audience'
// Since the functionailty of both, phone a friend and ask the audience is similar, we can just use one function for both
// It takes in the name of the player, the correct answer, and a string which tell which lifeline the player used out of 'Ask the Audience' or 'Phone a Friend'
// It returns nothing but prints out some text to help the player answer the question
void phoneOrAsk(string name, string answer, string life){

    // If the player chose 'Phone a Friend', printing out some suitable lines
    if (life == "CALL"){
        type("\nI see you would like to call a friend of yours, " + name);
        type("It's good that you have such reliable friends. Do share the award you take home today with them :)\n");
    }

    // If the player chose 'Ask the Audience', printing out some suitable lines
    else if (life == "ASK"){
        type("\nAhhhh yesss, the audience getting to make an impact in the game");
        type("Alright dear audience, grab your handsets and type in whatever you think is the correct answer.");
        type(name + ", your fate depends on them...");
    }

    // Common part for both, so just wrote one function for it

    // Generating a 1 or a 2 randomly
    srand(time(NULL));
    int num = rand() % 2 + 1;

    // If it's 1, we'll remove one wrong option from the given 4, using a method similar to fiftyFifty()
    if (num == 1){
        // Removing option D if any of A or B is correct
        if (answer == "A" || answer == "B"){
            type("\nYou may ignore option (d)\n");
        }

        // Removing option B if any of C or D is correct
        else if (answer == "C" || answer == "D"){
            type("\nOptions (b) is wrong, and you may proceed by ignoring it.\n");
        }
    }

    // But if it's 2, we'll hint towards the answer and the player can easily guess it
    else{
        type("\nAlright, so now, you'll be displayed a question, and it hints directly to the answer.");
        type("Read it carefully and try to think outside the box, shouldn't be any difficult for you.\n");
        if (answer == "A"){
            type("The alphabets cannot start without me. What am I?"); // Riddle created by ourselves
        }
        else if (answer == "B"){
            type("I am known for producing that sweet honey you have in breakfast everyday. What am I?"); // Riddle created by ourselves
        }
        else if (answer == "C"){
            type("Mediterranean, Caspian, Baltic, Arabian, Black, Red, Carribean... what are these names?"); // Riddle created by ourselves
            type("Now might be a good time to remember those childhood geography classes!");
        }
        else if (answer == "D"){
            type("Every Dawn and every Dusk begins with me, and Daybreak couldn’t start without me. What am I"); // Riddle inspired by https://huntclues.com/answers/the-letter-d/
        }
    }
}

// The secondChance() function handles the case when the user wants to use the second chance lifeline
// It takes the user a step back from their current position
// It takes in the name of the player, current question number, the the correct answer to the question, 
// index of the amount that the player has won so far, index of the correct answer, the values[] array, 
// and the amount at which the player is at after being taken a step back (as they used the second chance lifeline)
// It also changes indVal and/or indAns using pass-by-reference, and doesn't return anything
void secondChance(string name, int ques, string answer, int &indVal, int &indAns, string values[], string total){
    string r;

    type("\nHmm, brave move. I see you are an all-in kind of a person " + name);
    type("You are now sitting at " + total + ". You have to get this question right!!");
    type("Alright, you've already gotten this question incorrect once, let's hope you don't do it twice.");
    type("\nJust 3 choices left, what do you think is the answer now?");

    cin >> r;

    // Handling the case when the player enters something incorrect (not A, B, C, or D)
    while (upper(r) != "A" && upper(r) != "B" && upper(r) != "C" && upper(r) != "D"){
        type("\nPlease enter some valid input A, B, C, or D, but be careful this time!! ");
        cin >> r;
    }

    if (upper(r) == answer){
        type("\nOhhhhhh excellent job " + name + "! You've saved yourself from sudden death!");
        type("I don't know how you did it but that was remarkable, maintaining your calm under such pressure...");
        type("Phew, that was close!\n");
        indAns++; // Since the player will now answer 13 questions, we're incrementing indAns but not ques.
                  // In this way, the total questions answered by the player will be 13 but those that contributed 
                  // towards increasing the amount in the wallet will still be 12, just like the rest of the program.
        
        // indVal hasn't been changed in this case as even though second chance reduces it, answering correctly would restore it,
        // so the end result is the same as leaving it as it is
    }

    else{
        type("\nNOOOOO! You couldn't get it right :(\n");
        indVal--; // Decrementing indVal to take the player a step back
        quitGame(name, ques, values[indVal]); // Calling the quitGame() function as the game is over... :(
    }
}

// This file is the functions program file, which defines some more functions used in this game

#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>

#include "skeleton.h"

using namespace std;

// The lifelines() function checks for available lifelines and informs the player of this
// If the player decides to use any lifelines, the corresponding function will be called and the player will get help in answering
// It returns nothing 
void lifelines(string name, bool &fifty, bool &call, bool &ask){

    // For the case when the player has no lifelines available
    if (fifty == false && call == false && ask == false){
        type("Oops, you're out of lifelines that you can use in this situation");
        type("But it's okay, try harder, I'm sure you can figure it out :)");
    }
    
    else{
        string r; // the response of the player to whether they want to use the lifeline or not 

        type("Dear " + name + ", don't worry, you have these sources of help available: ");

        // For the 50-50 lifeline
        if (fifty == true){
            type("\nYou may get rid of two incorrect options by using the 50-50 lifeline. (enter 50)");
        }

        // For the 'Phone a friend' lifeline
        if (call == true){
            type("You can call any one of your friends. (enter CALL)");
        }

        // For the 'Ask the audience' lifeline
        if (ask == true){
            type("You have this beautiful audience here, maybe you can try asking them for some help (enter ASK)");
        }

        type("\nWhat would you like to choose? Please enter a correct option as shown in the brackets above.");
        cin >> r;

        while (r != "50" && upper(r) != "CALL" && upper(r) != "ASK"){
            type("Please enter a valid input: 50, CALL, or ASK. ");
            cin >> r;
        }

        if (r == "50"){
            // fifty();
            fifty = false;
        }

        if (upper(r) == "CALL"){
            // call();
            call = false;
        }

        if (upper(r) == "ASK"){
            // ask();
            ask = false;
        }
    }
}

// The quitGame() function handles the situation when the user wants to quit the game or has reached the end
// Takes in the current question number of the user, and the value they're taking home
// It returns nothing
void quitGame(string name, int ques, string value){
    string line; // For printing out award at the end
    type("\nSo our journey was till here, " + name);

    // Special end screen in case the player beat the gameS
    if (value == "$1,000,000"){
        type("\nYou've definitely proven your worth, and you've etched your name into the books of history with a well deserved win");
        type("We, at 'Who wants to be a Millionare', truly admire talents like yourself!");
        type("\nCONGRATULATIONS, YOU ARE NOW OFFICIALLY A MILLIONAIRE... AND THIS AWARD IS ALL YOURS!\n");
        
        ifstream fin ("award.txt"); // This ASCII art was taken from https://www.asciiart.eu/miscellaneous/awards
        while (getline(fin, line)){
            type(line);
        }
    }
    else{
        type("\nWe were having so much fun but alas, only so much!");
        type("You may have lost the game" + name + ", but you surely won our hearts <3\n");
    }

    type("All the best " + name + ", and keep grinding!\n");
    exit(1); // Exiting the program
}
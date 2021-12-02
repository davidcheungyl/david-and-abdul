// This file contains the functions needed for basic aesthetic enhancements and the one which essentially starts our game

#include <iostream>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <ctime>
#include <string>
#include <unistd.h> // For usleep()

using namespace std;

// The upper() function converts a given string to uppercase.
// It is useful for easy handling of user inputes to prevent taking in the wrong input
// It takes in a string to be converted to uppercase and returns a new string that is it's uppercase
string upper(string str){
    string new_str = "";
    for (int i = 0; i < str.length(); i++){
        new_str += toupper(str[i]);
    }
    return new_str;
}

// The type() function uses usleep() to give a smooth typing effect to the output of the game for aesthetics
// sleep() is not used here because apparently, sleep() produces a more rigid and sequential output which doesn't look as smooth as the output of usleep()
// It returns nothing and takes in a string which is to be typed
void type(string str){
    // Iterating over every character from the string and inputting it on the screen with a delay
    for (int i = 0; str[i] != '\0'; i++){
        cout << str[i];
        cout.flush(); // To keep the previously printed letter and print the next wide by its side (just like typing something letter by letter)
	    usleep(40000);
    }
    cout << endl;
}

// The printDiamond() function prints out a diamond logo on the screen for aesthetics
// The diamond is also printed sequentially, just like how the type() function prints text
// The function returns nothing, and takes in nothing as well since all it needs to run is a call alone, no parameters!
void printDiamond(){
    int row = 10, col = 60;
    char c = '*';
    string text = "WHO WANTS TO BE A MILLIONAIRE?";

    // The first for loop prints the upper part of the diamond and it adds the name of the game at the middle of the diamond
    for (int i = 0; i < row; i++){
        if (i != row - 1){
            if (i == 0){
                cout << setw(col - (3 * i ) + 1) << c << endl;
                cout.flush();
                usleep(30000);
            }
            else{
                cout << setw(col - (3 * i)) << c << setw((6 * i) + 2) << c << endl;
                cout.flush();
                usleep(30000);
            }
        }
        else{
            cout << setw(col - (3 * i)) << c << setw((4.75 * i) + 1) << text << setw(13) << c << endl;
            cout.flush();
            usleep(30000);         
        }
    }
    
    // This part prints the lower diamond
    for (int i = row - 2 ; i >= 0; i--){
        if (i == 0){
            cout << setw(col - (3 * i) + 1) << c << endl;
            cout.flush();
            usleep(30000);
        }
        else{
            cout << setw(col - (3 * i)) << c << setw((6 * i) + 2) << c << endl;
            cout.flush();
            usleep(30000);
        }
    }
}


// The startingGame() function, as the name suggests, starts the game and displays the initial screen to the user
// It asks the user their name and explains the course of the game to the user (if they want to skip the explanation, they may do so)
// It returns the username of the player for later use and takes in nothing as all it needs to run is a call alone, no parameters!
string startingGame(){
    string name, response;

    printDiamond();

    // Creating a multiline string
    const string starting = 
    "Hello, and welcome to 'Who wants to be a Millionaire'!! This is the ultimate test of your abilities. \n"
    "Do you have what it takes to become a millionaire? Well, there's only one way to find out...\n"
    "Without further ado, let's start the game.";

    type(starting);

    string question = " But first, what shall we call you? ";

    type(question);

    getline(cin, name);

    string question2 = ", would you like to read the instructions or do you just want to jump into the game directly?\n"
    "\nPlease enter 'Y' for reading the instructions or 'N' for skipping over them: ";

     type("\nOk, so " + name + question2);

    cin >> response;

    while (upper(response) != "Y" && upper(response) != "N"){
        type("\nPlease enter some valid input: Y or N? ");
        cin >> response;
    }

    string instructions =
    "\nAlright, so our instructions are pretty straightforward. You start from nothing and you climb up to a MILLION DOLLARS!\n"
    "You will be asked 12 questions from a variety of themes. Every correctly answered question will add some amount to your wallet.\n"
    "To be exact, the sequence of the values won will be as follows: \n"
    "$500, $1000, $2000, $5,000, $10,000, $20,000, $50,000, $75,000, $150,000, $250,000, $500,000 and finally, $1,000,000!\n\n"
    "Throughout your journey, you will have in total 4 lifelines that you can use to help yourself.\n\n"
    "1) 50-50: Two incorrect options will be removed from the given 4 options.\n\n"
    "2) Second life: This will revive you when you get an answer wrong. However, if only it was that simple. \n"
    "                You will be taken a step back from your current level, so you'll be asked 13 questions in total\n"
    "                Bear in mind that if you get it wrong even after using this lifeline, you would be taking home lesser\n"
    "                than what you previously had since you were brought a step down. Therefore, choose wisely...\n\n"
    "3) Phone a friend: A number will randomly be generated. If it's even, you will be hinted towards the answer directly. \n"
    "                   If it's odd, one wrong option will be taken away from the given 4.\n\n"
    "4) Ask the audience: Works in the same way as 'Phone a friend'.\n\n";
    "To get information on available lifelines or to avail them, please enter 'LIFELINE' after any question.\n\n";

    if (upper(response) == "Y"){
        type(instructions);
    }

    else{
        type("\nOh, so you're very confident? That's good, but don't get too excited. A long yet exciting journey awaits you!\n");
    }

    return name;
}
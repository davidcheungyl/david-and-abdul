// This file is the main program file, which makes use of all the functions written in other files meaningfully including some more

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

// Defining the functions used in this file, including those from other files

string upper(string str);
void type(string str);
void printDiamond();
string startingGame();
void lifelines(string name, bool &fifty, bool &call, bool &ask);
void quitGame(string name, int ques, string value);

// Main program, basically runs everything
int main(){

    // Initializing variables with necessary values

    // Booleans to demonstrate availibility of lifelines; true means available (unused), false means unavailable (already used up)
    bool fifty = true, second = true, call = true, ask = true;

    // array of correct answers (NO CHEATING :P )
    string answers[13] = {"B", "D", "C", "B", "A", "C", "C", "B", "B", "A", "B", "B", "A"};

    // Sequential values of each question
    string values[13] = {"$0", "$500", "$1000", "$2000", "$5000", "$10,000", "$20,000", "$50,000", "$75,000", "$150,000", "$250,000", "$500,000", "$1,000,000"};

    int ques = 0; // question number the player is currectly on
    string name, filename = "questions.txt"; // The name of the player

    // name = startingGame(); // Displaying introductory screen and storing the players username in the variable name

    ifstream fin(filename.c_str()); // Opening file containing questions

    // Handling failure in opening the file    
    if (fin.fail()){
        type("Error opening file");
        exit(1);
    }

    type("We're not here to waste time, " + name);
    type("Neither of us can wait to see that MILLION in your hands, so let's get started.");
    type("OK, here comes the first question...");

    while (ques != 12){
        // Declaring variables used later (q for question asked, r for answer of the player, c1 for choice 1, c2 for choice 2, and so on...)
        string q, c1, c2, c3, c4, r;
        string lifeResponse; // For storing the response of the plyaer to whether they want to use any lifeline or not
        
        // Getting line by line input to print out the question and answer choices
        cout << endl;
        getline(fin, q);
        type(q);
        type("\nAnd your options are:\n");
        getline(fin, c1);
        type(c1);
        getline(fin, c2);
        type(c2);
        getline(fin, c3);
        type(c3);
        getline(fin, c4);
        type(c4);

        type("\nDo you think you'll be needing any lifelines? Please enter Y or N");
        cin >> lifeResponse;

        // Making sure the input is correct
        while (upper(lifeResponse) != "Y" && upper(lifeResponse) != "N"){
            type("\nPlease enter some valid input: Y or N? ");
            cin >> lifeResponse;
        }
        
        if (upper(lifeResponse) == "Y"){
            lifelines(name, fifty, call, ask);
        }

        else{
            type("\nNOICE!!! So you're a confident person, eh? Let's see you do it by yourself then.");
        }

        cin >> r; // Taking in the player's answer to the question

        // Handling the case when the player enters something incorrect (not A, B, C, or D)
        while (upper(r) != "A" && upper(r) != "B" && upper(r) != "C" && upper(r) != "D"){
            type("\nPlease enter some valid input A, B, C, or D: ");
            cin >> r;
        }

        // If the player's answer is right
        if (upper(r) == answers[ques]){
            ques++;
            type("\nYesssss, you got it right!!!");
            type("Your wallet just got upgraded to " + values[ques]);
        }

        // For incorrect answer
        else{
            // If the player can get revived, the corresponding function will be called
            if (second == true){
                type("ADD SECOND LIFE CODE FROM DAVID");
                quitGame(name, ques, values[ques]);
                // secondChance();
            }

            // If the user 
            else{
                quitGame(name, ques, values[ques]);
            }
        }
    }

    // Calling the quitGame() function once the loop exits because this means that the player has passed all rounds
    quitGame(name, ques, values[ques]);

    return 0;
}
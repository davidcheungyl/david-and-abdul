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
#include "lifelines.h"

using namespace std;

// Defining the functions used in this file, including those from other files

string upper(string str);
void type(string str);
void printDiamond();
string startingGame();
void lifelines(string name, string answer, bool &fifty, bool &call, bool &ask);
void quitGame(string name, int ques, string value);
void fiftyFifty(string name, string answer);
void phoneOrAsk(string name, string answer, string life);
void secondChance(string name, int ques, string answer, int &indVal, int &indAns, string values[], string total);

// Main program, basically runs everything
int main(){

    // Initializing variables with necessary values

    // Booleans to demonstrate availibility of lifelines; true means available (unused), false means unavailable (already used up)
    bool fifty = true, second = true, call = true, ask = true;

    // array of correct answers (NO CHEATING :P )
    string answers[13] = {"B", "D", "C", "B", "A", "C", "C", "B", "B", "A", "B", "B", "A"};

    // Sequential values of each question
    string values[13] = {"$0", "$500", "$1000", "$2000", "$5000", "$10,000", "$20,000", "$50,000", "$75,000", "$150,000", "$250,000", "$500,000", "$1,000,000"};
    
    // ques is the question number the player is currectly on, indVal is the index in the array values[] of the amount the user has won so far
    // indAns is the index in the array answers[] of the answer to the question the user is answering now
    int ques = 0, indVal = 0, indAns = 0; 

    // The name of the player and filename (in separate strings)
    string name, filename = "questions.txt";

    name = startingGame(); // Displaying introductory screen and storing the players username in the variable name

    ifstream fin(filename.c_str()); // Opening file containing questions. These questions are taken from numerous sources like webpages and YouTube videos.

    // Handling failure in opening the file    
    if (fin.fail()){
        type("Error opening file");
        exit(1);
    }

    type("We're not here to waste time, " + name);
    type("Neither of us can wait to see that MILLION in your hands, so let's get started.");

    while (ques != 12){
        // Declaring variables used later (q for question asked, r for answer of the player, c1 for choice 1, c2 for choice 2, and so on...)
        string q, c1, c2, c3, c4, r;
        string lifeResponse; // For storing the response of the plyaer to whether they want to use any lifeline or not
        
        type("OK, here comes the question...");

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

        // If any lifeline is available, then the user will be asked whether they want to use it or not
        if (fifty == true || call == true || ask == true){
            type("\nDo you think you'll be needing any lifelines? Please enter Y or N");

            cin >> lifeResponse;

            // Making sure the input is correct
            while (upper(lifeResponse) != "Y" && upper(lifeResponse) != "N"){
                type("\nPlease enter some valid input: Y or N? ");
                cin >> lifeResponse;
            }
            
            if (upper(lifeResponse) == "Y"){
                lifelines(name, answers[indAns], fifty, call, ask);
            }

            else{
                type("\nNOICE!!! So you're a confident person, eh? Let's see you do it by yourself then.");
            }
        }

        // The following program will run if lifelines are available or not, so it's okay to put them outside the if statement

        type("\nWhat do you think is the right answer now? (enter A, B, C, or D)");

        cin >> r; // Taking in the player's answer to the question

        // Handling the case when the player enters something incorrect (not A, B, C, or D)
        while (upper(r) != "A" && upper(r) != "B" && upper(r) != "C" && upper(r) != "D"){
            type("\nPlease enter some valid input A, B, C, or D: ");
            cin >> r;
        }

        // If the player's answer is right
        if (upper(r) == answers[indAns]){
            // Incrementing question number, answer (so that it's now that for the next question), and the amount won
            ques++;
            indAns++;
            indVal++;
            type("\nYesssss, you got it right!!!");
            type("Your wallet just got upgraded to " + values[indVal]);
        }

        // For incorrect answer
        else{
            type("\nOH NO!! That is incorrect " + name + "...");

            // If the player can get revived, the corresponding function will be called
            if (second == true){
                string decision, total;

                // If the player is on the very first question, of course they can't be taken a step back. 
                // In this case, they would remain at the same level but have to answer 13 questions in total
                // the variable 'total' stores the value the player would be taken to if they avail the second chance lifeline
                if (indVal == 0){
                    total = "$0";
                }

                else{
                    total = values[indVal-1];
                }

                type("\nYou still have a second life left. Would you like to avail it?");
                type("If you don't, you'll be taking home " + values[indVal]);
                type("But if you do, you will have to answer one additional question to reach $1,000,000!");
                type("\nAND BEAR IN MIND THAT IF YOU DO USE THE SECOND LIFE AND STILL GET THE ANSWER WRONG, YOU WOULD LEAVE HERE WITH " + total);
                type("\nThe choice is totally yours, " + name + ". Take your time so you have no regrets later...");
                type("\nSo what will it be, second life (enter Y) or no (enter N)? ");

                cin >> decision;

                // Making sure the input is correct
                while (upper(decision) != "Y" && upper(decision) != "N"){
                    type("\nPlease enter some valid input: Y or N? ");
                    cin >> decision;
                }

                // If the player decides to take the second life, the corresponding function is called
                if (upper(decision) == "Y"){
                    secondChance(name, ques, answers[indAns], indVal, indAns, values, total);
                    second = false; // As the player has used the second chance lifeline, it's not available anymore
                }

                // If the player doesn't go for the second life, the game would just end
                else{
                    quitGame(name, ques, values[indVal]);
                }
            }

            // If the user doesn't have the second life option available (already used)
            else{
                quitGame(name, ques, values[indVal]);
            }
        }
    }

    fin.close(); // Closing the questions file

    // Calling the quitGame() function once the loop exits because this means that the player has passed all rounds
    quitGame(name, ques, values[indVal]);

    return 0;
}

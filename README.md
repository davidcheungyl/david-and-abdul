# Who Wants to be a Millionaire

# COMP2113/ENGG1340 Group Project

## Team Members (Group 116):
1. **Cheung Yu Lung** UID: 3035477616
2. **Abdulwadood Ashraf Faazli** UID: 3035832751

# Game Description

- Our game is a C++ version of the very popular TV show "Who wants to be a Millionaire". Everyone wants a shot at this game but the reality is that this isn't possible. Moreover, due to COVID-19 pandemic, many people who might have otherwise tried their luck at $1,000,000, couldn't. We believe our game would help people feel the adrenaline of the TV show and put their own skills to the test, all in a harmless, comfortable, and friendly environment.
- First of all, we welcome the player to the game and ask them for their username. We then make sure that that username isn't taken by someone else who has played the game. This is analogous to the **same person not playing the game twice** in real life. We then explain the instructions for the game to the user, but they may choose to skip over that. Then once the game starts, we ask the player a series of questions. They are rather straightforward at the start and might get challenging for some people over the course of the game.
- Every correctly answered question increases the value stored in the players wallet (amount won so far). The sequential values at questions are **$500, $1000, $2000, $5,000, $10,000, $20,000, $50,000, $75,000, $150,000, $250,000, $500,000 and finally, $1,000,000**. If the user manages to reach $1,000,000, they are said to have beaten the game.
- The game involves questions from a variety of topics including mathematics, science, general knowledge, and history. Players can only answer correctly for every question – any incorrect answer would lead to direct disqualification. However, it's not that simple. They may use a certain lifeline, if available at this point, to revive themselves, but this has it's own complications as explained later.
- Initially, we planned on allowing the user to quit the game midway. However, after looking at some actual TV show videos on YouTube, we decided not to do that. The reason for this is that let's say the user wants to quit. At this point, they wouldn't care about getting the answer correct or incorrect, right? They would just answer randomly. Now if the answer is wrong, then the game automatically ends. But what if they get it right? The resulting boost of adrenaline in the player's blood as well as the newly won money might as well just keep them in the game and you never know, maybe take home a MILLION DOLLARS too!
- Players have 4 lifelines to use over the course of a session. Each lifeline can only be used once. They are:
  -  **Fifty-Fifty**: When chosen, two incorrect choices are removed from the available options so the chances of a correct guess rise from 25% to 50%. 
  -  **Second chance**: The user can choose to be revived in case they get an answer wrong. However, the catch to this is that if the user decided to avail this lifeline, they are taken one step back from where they currently are. For example, let's say the user is at $50, 000 right now and playing for $75, 000. They get the answer wrong, but go for the 'second chance' lifeline. As a result, they would now be at $20, 000 and playing for $50, 000 (taken a step back). **Note that if the user gets the same question wrong even after using the lifeline, they would take home $20, 000, not $50, 000 as they would have in case they never used the lifeline and just left the game.** Therefore, the user is compelled to make these decisions wisely.
  -  **Phone a friend**: **USES RANDOMNESS, SO EXPLAINED LATER**
  -  **Ask the audience**: **USES RANDOMNESS, SO EXPLAINED LATER**

# Features Implemented

1) **Generation of random game sets or events:** We have introduced the element of randomness in our code during lifelines. When the user selects 'Phone a Friend' or 'Ask the Audience' lifelines, since we can't perform these actions actually, we simulate them. For this, we first generate a 1 or a 2 randomly. If the number is 2, we just directly hint towards the answer and the player can guess it quite easily. Otherwise, if it's 1, we cut out a wrong option from the choices, so the player only has 3 choices to choose from (winning probability went up from 25% to 33.3%).

2) **Data Structures:** The data structures we've used are pretty straightforward. We've used arrays to store the information like values of each question (how much the player would win after answering the question correctly). The score (amount in wallet) of the user will be extracted from this array. The username itself will be a string. Similarly, we have another array which stores the answers to all the questions.

3) **Dynamic memory management:** We create a dynamic variable (string type) every time the game runs. Names from 'users.txt' will be placed into that variable until either a match is found between the current player's name and that in the file, or the end of file is reached. This helps us simulate the reality in the game show that no person is allowed to play the game mor ethan once in a lifetime. The dynamic variable is then deleted since it taking up unnecessary memory in our system.

4) **File I/O:** The usernames of each individual player who has played the game will be stored in a file called 'users.txt'. In case the username of the current player is different from any other username in 'users.txt', we'll append that username to the file. The question bank is stored in a file too. **Note that there are 13 questions in the file to allow for successful implementation of the 'second chance' lifeline. However, not all of them will be asked every time.** Moreover, we have used some ASCII ART to appreciate our players. This art is stored in the 'win_award.txt' and 'lose_award.txt' files. The designs are printed out once the game ends.

5) **Program codes in multiple files:** We have created different program (.cpp) files for different sets of functions for easier compiling. Because of this, we've also prepared separate header (.h) files. In the end, we've organized all of this through a Makefile.

6) **Non-standard C/C++ Libraries:** 
- **#include <time.h>:** for initializing the seed for random number generation(srand()) to current time.
- **#include <unistd.h>:** We have also added a realistic and smooth typing effect to our game so the text that appears in front of the user is sequential and as if someone is typing it in real time. This is made possible by using the usleep() function from this library.

# Running the game

You can very conveniently compile all codes needed for this game and generate the final executable file for your game by this simple command: <br />
```
make game
./game
```
<br />

**IF YOU HAVE ANY QUESTIONS, FEEL FREE TO REACH OUT TO US**

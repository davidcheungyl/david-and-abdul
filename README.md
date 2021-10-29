# Who Wants to be a Millionaire

# COMP2113/ENGG1340

## Team Members (Group 116):
1. **Cheung Yu Lung** UID: 3035477616
2. **Abdulwadood Ashraf Faazli** UID:3035832751

# Game Description

- Our game is a C++ version of the very popular TV show "Who wants to be a millionaire". Everyone wants a shot at this game but the reality is that this isn't possible. We believe our game would help people feel the adrenaline of the TV show and put their own skills to the test.
- First of all, we will ask the user for his/her username and make sure that that username isn't taken by someone else who has played the game. This is analogous to the **same person not paying the game twice** in real life. Then once the game starts, we'll ask the player a series of questions.
- Every correctly answered question adds some value to the players wallet (amount won so far). The sequential values at questions are **$500, $1000, $2000, $5,000, $10,000, $20,000, $50,000, $75,000, $150,000, $250,000, $500,000 and finally, $1,000,000**. If the user manages to reach $1,000,000, they are said to have beaten the game.
- The game involves questions from a variety of topics including mathematics, science, general knowledge, and history. Players can only answer correctly for every question – any incorrect answer would lead to direct disqualification.
- Players have 4 lifelines to use over the course of a session. They are:
  -  **Fifty-Fifty**: When chosen, the two incorrect choices would be removed from the avilable options so the chances of a correct guess would rise from 25% to 50%. 
  -  **Second chance**: The user can choose another shot at any question only once during the entire course of his/her game. However, the catch to this is that if the user decided to avail this lifeline, they would taken one step back from where they currently are. For example let's say the user is at $50, 000 right now and playing for $75, 000. They get the answer wrong, but go for the 'second chance' lifeline. As a result, they would now be at $20, 000 and playing for $50, 000 (taken a step back).
  -  **Phone a friend**: **USES RANDOMNESS, SO EXPLAINED LATER**
  -  **Ask the audience**: **USES RANDOMNESS, SO EXPLAINED LATER**

# Features to Implement

1) **Generation of random game sets or events:** We will introduce the element of randomness in our code during lifelines. When the user selects 'phone a friend' or 'ask the audience', since we can't perform these actions actually, we'll simulate them randomly. For this, we'll first generate a random number. If the number is even, we'll just directly hint towards the answer and the player can guess it quite easily. Otherwise, if it's odd, we'll cut out a wrong option from the choices, so the player only has 3 choices to choose from (winning probability went up from 25% to 33.3%).

2) **Data Structures:** The data structures we plan to use are pretty straightforward. We'll use arrays to store the information of the user like username. The score (amount in wallet) of the user will be an integer. The username itself will be a string.

3) **Dynamic memory management:** We need an array to store the names of the users who have played the game. So, every time a new player entered the game, a new array will be created to store the new username, and the old array will be deleted, through dynamic memory management.

4) **File I/O:** The game results of each individual player will be stored in a file. If they decide to save the game and continue later, we'll store all their current information in a file and extract it from there when they return (start the game with the same username). The question banks will also be stored in files. 

5) **Program codes in multiple files:** We will create different .cpp files for different fucntions for easier compiling. Beacuse of this, we'll also need separate header (.h) files for those functions. In the end, we plan to organize all of this through a Makefile.

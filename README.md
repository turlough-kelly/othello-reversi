# othello-reversi
A project by Turlough Kelly (Student Number 20343033) for COMP10050, Software Engineering 1.



What is Othello?

Othello (also known as Reversi) is a type of board game that can be played with 2 players on a 8 x 8 uncheckered board. The game is played with black and white counters or "discs", where it is black on one side and white on the other.
In a given turn, if a counter is placed and from its position, there is a line of discs of the opposite colour followed by a disc of the same colour as the player, the player can flip those discs to their colour, and this applies
for any and all directions from the chosen position. The game ends in the event that:
- both players cannot make any sort of move,
- all 64 squares are filled.

The player with the most discs of their colour on the field is crowned the winner.



Instructions for the Program

- When prompted intially, please enter the names of both players. There is a 100 character limit for both names, and will be displayed throughout the game.
- Throughout the program instructions will be printed for how the user should proceed with their next action.
- When prompted to enter a move, enter a number in the range 1 to 8 for both the column, then the row. Any other number or character outside this range will be rejected.



Implementation of the Different Aspects of the Program

The following are headings that were provided to ensure all needs for the program were met during the constructing the program, with descriptions on how I implemented the tasks:
(taken from comp10050-assignment2-2020.pdf)

• Ask each player to provide their name as input from the keyboard and assign this name to the
player;
- The data for each player (black and white) are stored within structs, which includes the name of the current player, as well as variables that help to keep track of the game's progress.
The players enter their names which is stored in variables marked 'Name1' and 'Name2' respectively, using a gets() function to allow for any string to be inputted, allowing for customisation in the program.

• Assign players a disc colour;
- Using the rand() function, either 1 or 2 is chosen. Depending on the output, the players are assigned to black and white, with 1 resulting in Player 1 being black and Player 2 being white, and 2 resulting in the reverse.
The names are copied using strcpy() into the structs so that the program can operate smoothly.

• Keep track of each player’s score;
- A function called ScanBoardColour(), contained in othello.c, was created for this purpose. Firstly, it resets the currently stored values in the whitecounter and blackcounter variables. Next, it begins looping through
the board, incrementing blackcounter if a 'B' was discovered or whitecounter if a 'W' was discovered. It allows for fresh and up-to-date values to be displayed at any given stage throughout the game.

• Initialise the components of the game, eg initialise the board, initialise the score, set Black to
be the first player to move;
- Before the game can be played properly, a for loop loops through the board to set every value in the 2d array being used as the gameboard to ' ', or a blank space. Next, 2 black and 2 white counters are placed in 
the starting positions in the middle of the board, allowing the game to begin. Finally, during the large while loop used to control the game, upon restarting the loop, black always moves first before white.

• Request a move from each player in turn. A move should be entered at the keyboard. A move
can either be p (for “Pass”) or in the format ld, where l is a letter in the range a to h, and
d is a digit in the range 1 to 8;
- During the constructing of the program, I had encountered many errors when utilising char type variables to be used with the columns of the board. To allow for simplicity within the program, both the columns and the rows
are digits in the range 1 to 8, meaning the move is in the format (column, row). This allows for greater flexibility for what is possible during the program. For passing, the function ScanBoard() loops through the entire board 
and makes note of what moves can be implemented for that turn, using functions found in validmoves.c. If no moves can be made, the game automatically passes for the user, and allows the next player to move.

• Check that the entered move is valid and, if it is, effect the move. If the move is not valid,
request another move;
- When a move is inputted, the functions that are found in validmoves.c are called and, in the case of a valid move, increments the variable associated with it. If the total variable (where its value is the individual
variables tallied together) is at least 1, then continues to implement the move through functions found in implementmoves.c. Otherwise, it will allow the player to make another move. This sequence will only occur
if the initial run of the ScanBoard() function returns a value of total that is greater than 0.

• A player should only be allowed to Pass if they have no valid move;
- As mentioned earlier, the ScanBoard() function loops through the board to check for any valid moves that can be made during the turn. In the event that the total variable is 0, an automatic Pass is implemented and the next
player can act.

• Update and print the board after each move;
- This is handled by the function PrintBoard(), which also automatically updates the board as the game progresses. This function prints the names of both players, their scores, and the current layout of the board.

• When the game is over, establish which player has won, print out the winner, the score and
the final board. The date and time of the game and the result of the game (ie the winner,
the score) should also be appended to a file othello-results.txt.
- Upon completion of the game, the whitecounter and blackcounter variables are compared and determines the winner of the game, which is then printed to the console. Unless a file already exits, a new file called
othello-results.txt is created, and the data of the current game, including the time finished, the names of both players, their scores, as well as the winner, is written into the file. If the file already exists,
the data is overwritten.

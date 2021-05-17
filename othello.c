#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*These files are to be located within the same directory as this file (ie in the same folder) as they contain functions critical to the program.*/
#include "validmoves.c"
#include "implementmoves.c"



/*Structures to keep track of the game, as well as both players.*/
/*GameData helps keep track of the game board and throughout the program continuously updates, ensuring that the correct and up-to-date
info is displayed at all times.*/
struct GameData 
{
    char board[8][8];
    int totalcounter;
};

/*BlackPlayer mainly keeps track of the player whose colour is assigned "black", including their name, whether they have completed their current turn,
and if their turn does not allow any moves to be made.*/
struct BlackPlayer
{
    char player1Name[100];
    int turncomplete;
    int pass;
};

/*WhitePlayer mainly keeps track of the player whose colour is assigned "white", including their name, whether they have completed their current turn,
and if their turn does not allow any moves to be made.*/
struct WhitePlayer
{
    char player2Name[100];
    int turncomplete;
    int pass;
};

/*Setting up the structs as universal variables for more flexibility throughout the program.*/
    struct GameData GameData;
    struct BlackPlayer player1;
    struct WhitePlayer player2;

/*A function to print the Board at any given moment, which automatically updates as the game progresses.*/
void PrintBoard(char board[8][8], char player1Name[100], char player2Name[100])
{
    printf("  Black                       White\n");
    printf("  %s                            %s\n", player1Name, player2Name);
    printf("                %d:%d\n", blackcounter, whitecounter);
    printf("    1   2   3   4   5   6   7   8\n");
    printf("  ---------------------------------\n");
    printf("1 | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7]);
    printf("  ---------------------------------\n");
    printf("2 | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7]);
    printf("  ---------------------------------\n");
    printf("3 | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7]);
    printf("  ---------------------------------\n");
    printf("4 | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7]);
    printf("  ---------------------------------\n");
    printf("5 | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7]);
    printf("  ---------------------------------\n");
    printf("6 | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7]);
    printf("  ---------------------------------\n");
    printf("7 | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7]);
    printf("  ---------------------------------\n");
    printf("8 | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7]);
    printf("  ---------------------------------\n");

}

/*A function to scan the board and check for any valid moves that can be implemented by the player in a turn.*/
void ScanBoard(int target, int player, char board[8][8])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < 8; i++)
   {
       for(j = 0; j < 8; j++)
       {
            checkUp(j, i, target, player, board);
            checkDown(j, i, target, player, board);
            checkLeft(j, i, target, player, board);
            checkRight(j, i, target, player, board);
            checkUpRight(j, i, target, player, board);
            checkUpLeft(j, i, target, player, board);
            checkDownRight(j, i, target, player, board);
            checkDownLeft(j, i, target, player, board);
       }
   }
   total = n + s + e + w + nw + ne + sw + se;
}

/*A function to scan the board and update the total number of counters present, sorted by colour.*/
void ScanBoardColour(char board[8][8])
{
    int i = 0;
    int j = 0;
    whitecounter = 0;
    blackcounter = 0;

    for(i = 0; i < 8; i++)
   {
       for(j = 0; j < 8; j++)
       {
            if(board[i][j] == 66)
            {
                blackcounter++;
            }
            if(board[i][j] == 87)
            {
                whitecounter++;
            }
       }
   }
}

/*Main driver function.*/
int main()
{
/*This allows the program to keep track of the current time for printing later.*/
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );


    /*Variables that are to be used within the main driver function.*/
    FILE *results;
    char Name1[100];
    char Name2[100];
    int row = 0;
    int col;
    int i;
    int j;
    int counter;

    /*Variables to track inputs of the players throughout the game.*/
    int blackrow = 0;
    int blackcolumn = 0;
    int whiterow = 0;
    int whitecolumn = 0;

    /*Two variables with the ASCII values of Black and White for better understanding.*/
    int black = 66;
    int white = 87;

    /*srand helps to seed the random number generator used to assign Black or White randomly to the 2 players.*/
    srand(time(0));
    int chooser;

    /*A "for" loop to intialise the board and prepare for the game to be played, filling any unoccupied space on the board with a simple space.*/
   for(i = 0; i < 8; i++)
   {
       for(j = 0; j < 8; j++)
       {
           GameData.board[i][j] = ' ';
       }
   }

   /*Sets up the board with the 2 Black and White counters to allow the game to begin.*/
   GameData.board[3][3] = 'W';
   GameData.board[4][3] = 'B';
   GameData.board[3][4] = 'B';
   GameData.board[4][4] = 'W';
   GameData.totalcounter = 4;

   printf("Welcome to Othello!\n");
   printf("\n\nThis game is designed to be played with 2 players. Information on how this game is played,\nas well as its history, can be found at the following link: https://en.wikipedia.org/wiki/Reversi");
   printf("\n\nPlease enter the name for the 1st player. The limit is 100 characters: ");
   gets(Name1);
   printf("Please enter the name for the 2nd player. The limit is 100 characters: ");
   gets(Name2);

    /*Randomises which player gets to be Black and White via a Random Number Generator.*/
   chooser = (rand() % 2) + 1;
   if(chooser = 1)
   {
       printf("\n%s has been chosen as Black, while %s has been chosen as White", Name1, Name2);
       strcpy(player1.player1Name, Name1);
       strcpy(player2.player2Name, Name2);
   }
   else if(chooser = 2)
   {
       printf("\n%s has been chosen as Black, while %s has been chosen as White", Name2, Name1);
       strcpy(player1.player1Name, Name2);
       strcpy(player2.player2Name, Name1);
   }


/*The entire game, including the turns for both players, are managed within this while loop, which ends when the board is full (64 counters present) or no more moves can be made, whichever comes first.*/
while((GameData.totalcounter < 64) || (player1.pass == 1 && player2.pass == 1))
{

    /*If no move can be made, a pass variable is incremented, and this checks that in the case no moves were possible, the game ends. Otherwise, it allows the game to continue, resetting both variables in the process.*/
   if(player1.pass + player2.pass != 2)
   {
       player1.turncomplete = 0;
       player2.turncomplete = 0;
   }
   else if (player1.pass + player2.pass == 2)
   {
       break;
   }

 /*The turn for Player 1 is managed within this for loop.*/
   while(player1.turncomplete < 1)
   {
       /*Player's name is printed, the variables found in validmoves.c are reset, and the board is scanned for any possible moves that can be made within the turn.*/
       printf("\nIt is now %s's turn.\n", player1.player1Name);
       ResetValid();
       ScanBoard(white, black, GameData.board);
       total = n + s + e + w + nw + ne + sw + se;
       /*If no moves were found, the turn automatically ends for the player. Otherwise, it allows the player to input their move into the console.*/
       if(total == 0)
       {
           printf("No moves have been found across the board. Automatically passing to the next player...");
           player1.pass = 1;
           player1.turncomplete = 1;
           break;
       }
       else
       {
        PrintBoard(GameData.board, player1.player1Name, player2.player2Name);
       printf("Please input a number from 1 to 8 to select a COLUMN (going down from the top): ");
       while (scanf("%d", &blackrow) != 1 || blackrow < 1 || blackrow > 8)
            {
                printf("\nThis input is invalid. Please try again. ");
                getchar();
            }
        
        printf("Please input a number from 1 to 8 to select a ROW (going across): ");
       while (scanf("%d", &blackcolumn) != 1 || blackcolumn < 1 || blackcolumn > 8)
            {
                printf("\nThis input is invalid. Please try again. ");
                getchar();
            }
        /*The program takes the input and checks the validity of the move. If it is not valid, it will ask the user for another input. If it is, it will begin to implement the move.*/
       blackcolumn--;
       blackrow--;
       ResetValid();
       checkUp(blackcolumn, blackrow, white, black, GameData.board);
       checkDown(blackcolumn, blackrow, white, black, GameData.board);
       checkLeft(blackcolumn, blackrow, white, black, GameData.board);
       checkRight(blackcolumn, blackrow, white, black, GameData.board);
       checkUpRight(blackcolumn, blackrow, white, black, GameData.board);
       checkUpLeft(blackcolumn, blackrow, white, black, GameData.board);
       checkDownRight(blackcolumn, blackrow, white, black, GameData.board);
       checkDownLeft(blackcolumn, blackrow, white, black, GameData.board);
       total = n + s + e + w + nw + ne + sw + se;
       printf("\n\n%d\n\n", whitecounter);

        if( total > 0)
        {
            printf("A total of %d moves have been found for this position. Implementing now...", total);
            GameData.board[blackcolumn][blackrow] = 'B';
            GameData.totalcounter++;
            /*Based on what moves were valid from that position, the while loop goes through and implements moves in the specified directions and updates the board as it goes through the process.*/
         while(total > 0)
       {
           if(n == 1)
           {
               implementUp(blackcolumn, blackrow, white, black, GameData.board);
               n = 0;
               total--;
           }
           if(s == 1)
           {
               implementDown(blackcolumn, blackrow, white, black, GameData.board);
               s = 0;
               total--;
           }
           if(w == 1)
           {
               implementLeft(blackcolumn, blackrow, white, black, GameData.board);
               w = 0;
               total--;
           }
           if(e == 1)
           {
               implementRight(blackcolumn, blackrow, white, black, GameData.board);
               e = 0;
               total--;
           }
           if(ne == 1)
           {
               implementUpRight(blackcolumn, blackrow, white, black, GameData.board);
               ne = 0;
               total--;
           }
           if(nw == 1)
           {
               implementUpLeft(blackcolumn, blackrow, white, black, GameData.board);
               nw = 0;
               total--;
           }
           if(se == 1)
           {
               implementDownRight(blackcolumn, blackrow, white, black, GameData.board);
               se = 0;
               total--;
           }
           if(sw == 1)
           {
               implementDownLeft(blackcolumn, blackrow, white, black, GameData.board);
               sw = 0;
               total--;
           }
            ScanBoardColour(GameData.board);

       }
       player1.turncomplete = 1;
       /*Informs the player if no moves were found.*/
        }
       else if (total == 0)
       {
           printf("\nNo moves have been found here.");
       }
   }
       }









/*The turn for Player 2 is managed within this for loop.*/
    while(player2.turncomplete < 1)
   {
       /*Player's name is printed, the variables found in validmoves.c are reset, and the board is scanned for any possible moves that can be made within the turn.*/
       printf("\nIt is now %s's turn.\n", player2.player2Name);
       ResetValid();
       ScanBoard(black, white, GameData.board);
       total = n + s + e + w + nw + ne + sw + se;
       /*If no moves were found, the turn automatically ends for the player. Otherwise, it allows the player to input their move into the console.*/
       if(total == 0)
       {
           printf("No moves have been found across the board. Automatically passing to the next player...");
           player2.pass = 1;
           player2.turncomplete = 1;
           break;
       }
       else
       {
        PrintBoard(GameData.board,player1.player1Name, player2.player2Name);
      printf("Please input a number from 1 to 8 to select a COLUMN (going down from the top): ");
       while (scanf("%d", &whiterow) != 1 || whiterow < 1 || whiterow > 8)
            {
                printf("\nThis input is invalid. Please try again. ");
                getchar();
            }
        
        printf("Please input a number from 1 to 8 to select a ROW (going across): ");
       while (scanf("%d", &whitecolumn) != 1 || whitecolumn < 1 || whitecolumn > 8)
            {
                printf("\nThis input is invalid. Please try again. ");
                getchar();
            }
       /*The program takes the input and checks the validity of the move. If it is not valid, it will ask the user for another input. If it is, it will begin to implement the move.*/
       whitecolumn--;
       whiterow--;
       ResetValid();
       checkUp(whitecolumn, whiterow, black, white, GameData.board);
       checkDown(whitecolumn, whiterow, black, white, GameData.board);
       checkLeft(whitecolumn, whiterow, black, white, GameData.board);
       checkRight(whitecolumn, whiterow, black, white, GameData.board);
       checkUpRight(whitecolumn, whiterow, black, white, GameData.board);
       checkUpLeft(whitecolumn, whiterow, black, white, GameData.board);
       checkDownRight(whitecolumn, whiterow, black, white, GameData.board);
       checkDownLeft(whitecolumn, whiterow, black, white, GameData.board);
       total = n + s + e + w + nw + ne + sw + se;
        /*Based on what moves were valid from that position, the while loop goes through and implements moves in the specified directions and updates the board as it goes through the process.*/
       if(total > 0)
       {
           printf("A total of %d moves have been found for this position. Implementing now...", total);
           GameData.board[whitecolumn][whiterow] = 'W';
           GameData.totalcounter++;
           while(total > 0)
           {
           if(n == 1)
           {
               implementUp(whitecolumn, whiterow, black, white, GameData.board);
               n = 0;
               total--;
           }
           if(s == 1)
           {
               implementDown(whitecolumn, whiterow, black, white, GameData.board);
               s = 0;
               total--;
           }
           if(w == 1)
           {
               implementLeft(whitecolumn, whiterow, black, white, GameData.board);
               w = 0;
               total--;
           }
           if(e == 1)
           {
               implementRight(whitecolumn, whiterow, black, white, GameData.board);
               e = 0;
               total--;
           }
           if(ne == 1)
           {
               implementUpRight(whitecolumn, whiterow, black, white, GameData.board);
               ne = 0;
               total--;
           }
           if(nw == 1)
           {
               implementUpLeft(whitecolumn, whiterow, black, white, GameData.board);
               nw = 0;
               total--;
           }
           if(se == 1)
           {
               implementDownRight(whitecolumn, whiterow, black, white, GameData.board);
               se = 0;
               total--;
           }
           if(sw == 1)
           {
               implementDownLeft(whitecolumn, whiterow, black, white, GameData.board);
               sw = 0;
               total--;
           }
            GameData.totalcounter++;
            ScanBoardColour(GameData.board);
           player2.turncomplete = 1;
       }
       }
       /*Informs the player if no moves were found.*/
       else if (total == 0)
       {
           printf("\nNo moves have been found here.");
       }
   }
       }
}

/*If no such file exists, creates a file or overwrites it if it exists, and updates it with the score of the recently completed game, including the names of both players, their scores, the winner, and the current date and time.*/
results = fopen ("othello-results.txt.", "w");
PrintBoard(GameData.board, player1.player1Name, player2.player2Name);
if(whitecounter > blackcounter)
{
    printf("\n\nAnd the winner is: White (%s) with %d counters on the board!", player2.player2Name, whitecounter);
    fprintf(results, "╔═╦══╦╗╔╦═╦╗╔╗╔═╗\n║║╠╗╔╣╚╝║╦╣║║║║║║\n║║║║║║╔╗║╩╣╚╣╚╣║║\n╚═╝╚╝╚╝╚╩═╩═╩═╩═╝\n\n\nDate and Time: %s\n\n\nBlack: %s          White: %s\nScore: %d           Score:%d\n\n\nWinner: %s", asctime (timeinfo), player1.player1Name, player2.player2Name, blackcounter, whitecounter, player2.player2Name );
}

else if(blackcounter > whitecounter)
{
    printf("\n\nAnd the winner is: Black (%s) with %d counters on the board!", player1.player1Name, blackcounter);
    fprintf(results, "╔═╦══╦╗╔╦═╦╗╔╗╔═╗\n║║╠╗╔╣╚╝║╦╣║║║║║║\n║║║║║║╔╗║╩╣╚╣╚╣║║\n╚═╝╚╝╚╝╚╩═╩═╩═╩═╝\n\n\nDate and Time: %s\n\n\nBlack: %s          White: %s\nScore: %d           Score:%d\n\n\nWinner: %s", asctime (timeinfo), player1.player1Name, player2.player2Name, blackcounter, whitecounter, player1.player1Name );
}

else
{
    printf("\n\nThe game has ended in a draw.");
    fprintf(results, "╔═╦══╦╗╔╦═╦╗╔╗╔═╗\n║║╠╗╔╣╚╝║╦╣║║║║║║\n║║║║║║╔╗║╩╣╚╣╚╣║║\n╚═╝╚╝╚╝╚╩═╩═╩═╩═╝\n\n\nDate and Time: %s\n\n\nBlack: %s           White: %s\nScore: %d           Score:%d\n\n\nWinner: Draw", asctime (timeinfo), player1.player1Name, player2.player2Name, blackcounter, whitecounter);
}

fclose(results);


return 0;
}
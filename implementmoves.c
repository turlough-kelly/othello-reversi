/*This file is to be used alongside othello.c. It focuses on functions that implement valid moves throughout the game.*/
#include <stdio.h>
#include <stdlib.h>

/*Variables that keep a local track of the currently present counters in the game.*/
int whitecounter = 2;
int blackcounter = 2;

/*All the following functions are based off of the same prototype and thus function identically aside from the directions that they take.*/


/*A function that replaces every counter starting from in front of the current position until it reaches a counter of the same colour as the player, heading NORTH (up).*/
void implementUp(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column - 1;
    while(board[i][row] != playercolour)
    {
        if(board[i][row] = target)
        {
            board[i][row] = playercolour;
        }
        i--;
    }
}

/*A function that replaces every counter starting from in front of the current position until it reaches a counter of the same colour as the player, heading SOUTH (down).*/
void implementDown(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column + 1;
    while(board[i][row] != playercolour)
    {
        if(board[i][row] = target)
        {
            board[i][row] = playercolour;
        }
        i++;
    }
}

/*A function that replaces every counter starting from in front of the current position until it reaches a counter of the same colour as the player, heading WEST (left).*/
void implementLeft(int column, int row, int target, int playercolour, char board[8][8])
{
    int j = row - 1;
    while(board[column][j] != playercolour)
    {
        if(board[column][j] = target)
        {
            board[column][j] = playercolour;
            j--;
        }
    }
}

/*A function that replaces every counter starting from in front of the current position until it reaches a counter of the same colour as the player, heading EAST (right).*/
void implementRight(int column, int row, int target, int playercolour, char board[8][8])
{
    int j = row + 1;
    while(board[column][j] != playercolour)
    {
        if(board[column][j] = target)
        {
            board[column][j] = playercolour;
            j++;
        }
    }
}

/*A function that replaces every counter starting from in front of the current position until it reaches a counter of the same colour as the player, heading NORTH EAST (up and to the right).*/
void implementUpRight(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column - 1;
    int j = row + 1;
    while(board[i][j] != playercolour)
    {
        if(board[i][j] = target)
        {
            board[i][j] = playercolour;
            i--;
            j++;
        }
    }
}

/*A function that replaces every counter starting from in front of the current position until it reaches a counter of the same colour as the player, heading NORTH WEST (up and to the left).*/
void implementUpLeft(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column - 1;
    int j = row - 1;
    while(board[i][j] != playercolour)
    {
        if(board[i][j] = target)
        {
            board[i][j] = playercolour;
            i--;
            j--;
        }
    }
}

/*A function that replaces every counter starting from in front of the current position until it reaches a counter of the same colour as the player, heading SOUTH EAST (down and to the right).*/
void implementDownRight(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column + 1;
    int j = row + 1;
    while(board[i][j] != playercolour)
    {
        if(board[i][j] = target)
        {
            board[i][j] = playercolour;
            if(playercolour == 66)
            {
                whitecounter--;

            }
            else if(playercolour == 87)
            {
                blackcounter--;
            }
            i++;
            j++;
        }
    }
}

/*A function that replaces every counter starting from in front of the current position until it reaches a counter of the same colour as the player, heading SOUTH WEST (down and to the left).*/
void implementDownLeft(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column + 1;
    int j = row - 1;
    while(board[i][j] != playercolour)
    {
        if(board[i][j] = target)
        {
            board[i][j] = playercolour;
            i++;
            j--;
        }
    }
}
/*This file is to be used alongside othello.c. It focuses on functions that check for valid moves throughout the game.*/
#include <stdio.h>
#include <stdlib.h>

/*Variables that are used to track different directions so the program knows what functions to call. Total is the combined total of all the moves.*/
int n = 0;
int s = 0;
int e = 0;
int w = 0;
int nw = 0;
int sw = 0;
int ne = 0;
int se = 0;
int total = 0;

/*A function that resets all the variables for use again in one fell swoop.*/
void ResetValid()
{
    n = 0;
    s = 0;
    e = 0;
    w = 0;
    nw = 0;
    sw = 0;
    ne = 0;
    se = 0;
    total = 0;
}

/*All the following functions are based off of the same prototype and thus function identically aside from the directions that they take.*/


/*Function to check NORTH (up) from the current position. Increments n if a valid move is found.*/
void checkUp(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column;
    if(board[i - 1][row] == ' ' || board[i - 1][row] == playercolour || i - 1 < 0)
    {
        return;
    }
    else
    {
    while(i > -1)
    {
        if(board[i][row] == target && board[i - 1][row] == playercolour)
        {
            n += 1;
            break;
        }
        i--;
    }
}
}
/*Function to check SOUTH (down) from the current position. Increments s if a valid move is found.*/
void checkDown(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column;
    if(board[i + 1][row] == ' ' || board[i + 1][row] == playercolour)
    {
        return;
    }
    while(i < 8)
    {
    if(board[i][row] == target && board[i + 1][row] == playercolour)
    {
        s += 1;
        break;
    }
        i++;
    }
}

/*Function to check WEST (left) from the current position. Increments w if a valid move is found.*/
void checkLeft(int column, int row, int target, int playercolour, char board[8][8])
{
    int j = row;
    if(board[column][j - 1] == ' ' || board[column][j - 1] == playercolour)
    {
        return;
    }
    else
    {
    while(j > -1)
    {
    if(board[column][j] == target && board[column][j - 1] == playercolour)
    {
        w += 1;
        break;
    }
        j--;
    }
    }
}

/*Function to check EAST (right) from the current position. Increments e if a valid move is found.*/
void checkRight(int column, int row, int target, int playercolour, char board[8][8])
{
    int j = row;
    if(board[column][j + 1] == ' ' || board[column][j + 1] == playercolour)
    {
        return;
    }
    while(j < 8)
    {
    if(board[column][j] == target && board[column][j + 1] == playercolour)
    {
        e += 1;
        break;
    }
        j++;
    }
}

/*Function to check NORTH EAST (up and to the right) from the current position. Increments ne if a valid move is found.*/
void checkUpRight(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column;
    int j = row;
    if(board[i - 1][j + 1] == ' ' || board[i - 1][j + 1] == playercolour)
    {
        return;
    }
  while(i > -1 || j < 8)
{
    if(board[i][j] == target && board[i - 1][j + 1] == playercolour)
    {
        ne += 1;
        break;
    }
    i--;
    j++;
}
}

/*Function to check NORTH WEST (up and to the left) from the current position. Increments nw if a valid move is found.*/
void checkUpLeft(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column;
    int j = row;
    if(board[i - 1][j - 1] == ' ' || board[i - 1][j - 1] == playercolour)
    {
        return;
    }
  while(i > -1 || j > -1)
{
    if(board[i][j] == target && board[i - 1][j - 1] == playercolour)
    {
        nw += 1;
        break;
    }
    i--;
    j--;
}
}

/*Function to check SOUTH EAST (down and to the right) from the current position. Increments se if a valid move is found.*/
void checkDownRight(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column;
    int j = row;
    if(board[i + 1][j + 1] == ' ' || board[i + 1][j + 1] == playercolour)
    {
        return;
    }
  while(i < 8 || j < 8)
{
    if(board[i][j] == target && board[i + 1][j + 1] == playercolour)
    {
        se += 1;
        break;
    }
    i++;
    j++;
}

}

/*Function to check SOUTH WEST (down and to the left) from the current position. Increments sw if a valid move is found.*/
void checkDownLeft(int column, int row, int target, int playercolour, char board[8][8])
{
    int i = column;
    int j = row;
    if(board[i + 1][j - 1] == ' ' || board[i + 1][j - 1] == playercolour)
    {
        return;
    }
  while(i < 8 || j > -1)
{
    if(board[i][j] == target && board[i + 1][j - 1] == playercolour)
    {
        sw += 1;
        break;
    }
    i++;
    j--;
}

}
#include <stdio.h>
#include "board.h"

#define PLAYER1_RED   "\x1b[41m    \x1b[0m"  //red block
#define PLAYER2_BLUE  "\x1b[44m    \x1b[0m"  //blue bloc
#define EMPTY_CELL    "    "                  //empty cell size

void ResetBoard(int board[ROWS][COLS]) //Resets the board to an empty state
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

int FullBoard(int board[ROWS][COLS]) //checks if the board is full
{
    for (int j = 0; j < COLS; j++)
    {
        if (board[0][j] == EMPTY)
            return 0;
    }
    return 1;
}

void PrintBoard(int board[ROWS][COLS]) //prints the board design
{
    //column numbers
    printf("   ");
    for (int j = 0; j < COLS; j++)
        printf("%d    ", j + 1); //centers the number for each column
    printf("\n");

    for (int i = 0; i < ROWS; i++)
    {
        //upper border
        for (int j = 0; j < COLS; j++)
            printf("+----");
        printf("+\n");

        //middle borders
        for (int j = 0; j < COLS; j++)
        {
            printf("|");
            if (board[i][j] == PLAYER1)
                printf("%s", PLAYER1_RED);
            else if (board[i][j] == PLAYER2)
                printf("%s", PLAYER2_BLUE);
            else
                printf("%s", EMPTY_CELL);
        }
        printf("|\n");
    }

    //lower border
    for (int j = 0; j < COLS; j++)
        printf("+----");
    printf("+\n");
}
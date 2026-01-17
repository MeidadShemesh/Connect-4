#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"
#include "diff.h"
#include "menu.h"
#include "stats.h"


int main(void)
{
    InitStats();
    int board[ROWS][COLS];
    int currentPlayer;
    int col;
    int choice;

    while (1)
    {
        int mode = MainMenu(&choice);
        StartGame(board, &currentPlayer);
        if (mode > 0 && mode < 6)
        {
            if (mode == 1)
            {
                ClearScreen();
                PvP(board, &currentPlayer);

            }
            else if (mode == 2)
            {
                ClearScreen();
                PvC(board, &currentPlayer, choice);
            }
            else if (mode == 4)
            {
                ClearScreen();
                about();
                return main();
            }
            if (mode == 5)
            {
                printf("Thanks for playing! Exiting...\n");
                exit(0);
            }
        }
    }
    return 0;
}

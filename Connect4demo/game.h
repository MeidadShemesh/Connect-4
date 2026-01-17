#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "stats.h"

void StartGame(int board[ROWS][COLS], int* currentPlayer);
int DropDisk(int board[ROWS][COLS], int col, int player);
int CheckWin(int board[ROWS][COLS], int player);
void ClearScreen();
int GetPlayerInput(int board[ROWS][COLS]);
void PvP(int board[ROWS][COLS], int* currentPlayer);
void PvC(int board[ROWS][COLS], int* currentPlayer, int difficulty);
void wait();
int validMove(char board[ROWS][COLS], int col);


#endif

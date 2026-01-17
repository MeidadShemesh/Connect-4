#ifndef BOARD_H
#define BOARD_H
#define ROWS 6
#define COLS 7
#define EMPTY 0
#define PLAYER1 1
#define PLAYER2 2

void ResetBoard(int board[ROWS][COLS]);
int FullBoard(int board[ROWS][COLS]);
void PrintBoard(int board[ROWS][COLS]);

#endif
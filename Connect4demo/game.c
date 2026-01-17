#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "board.h"
#include "menu.h"
#include "diff.h"

void StartGame(int board[ROWS][COLS], int* currentPlayer) //Starts game with empty board and Player 1
{
	ResetBoard(board);
	*currentPlayer = PLAYER1;
}

int DropDisk(int board[ROWS][COLS], int col, int player) //Puts the disk at the lowest available row for the chosen column
{
	if (col < 0 || col >= COLS) //Column limits
		return 0;
	for (int i = ROWS - 1; i >= 0; i--) //Looks for the lowest row available
	{
		if (board[i][col] == 0)
		{
			board[i][col] = player;
			return 1;
		}
	}
	return 0;
}

int CheckWin(int board[ROWS][COLS], int player) //Win conditions
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (board[i][j] == player)
			{
				if (j + 3 < COLS &&
					board[i][j + 1] == player &&
					board[i][j + 2] == player &&
					board[i][j + 3] == player) //Vertical
					return 1;
				if (i + 3 < ROWS &&
					board[i + 1][j] == player &&
					board[i + 2][j] == player &&
					board[i + 3][j] == player) //Horizontal
					return 1;
				if (i + 3 < ROWS && j + 3 < COLS &&
					board[i + 1][j + 1] == player &&
					board[i + 2][j + 2] == player &&
					board[i + 3][j + 3] == player) //diagonal
					return 1;
				if (i + 3 < ROWS && j - 3 >= 0 &&
					board[i + 1][j - 1] == player &&
					board[i + 2][j - 2] == player &&
					board[i + 3][j - 3] == player) //inverted diagonal
					return 1;
			}
		}
	}
	return 0;
}

void ClearScreen() //clears the screen
{

	system("cls");
}

void wait()//Waits one second
{
	clock_t start = clock();
	while ((clock() - start) < CLOCKS_PER_SEC)
		;
}

void PvP(int board[ROWS][COLS], int* currentPlayer) //Starts Player vs Player mode
{
	int col;
	int winner = 0;

	while (!FullBoard(board) && winner == 0)
	{
		PrintBoard(board);
		printf("Player %d, choose a column (1-7): ", *currentPlayer);
		if (scanf_s("%d", &col) != 1)
		{
			while (getchar() != '\n');
			col = -1;
		}
		ClearScreen();
		col = col - 1; //Adjusts player input (1–7) to board index (0–6)
		if (col < 0 || col >= COLS)
		{
			ClearScreen();
			printf("Invalid column! Try again!\n");
			continue; //Resets the loop without changing the player
		}
		if (DropDisk(board, col, *currentPlayer))
		{
			if (CheckWin(board, *currentPlayer))
			{
				ClearScreen(); //
				PrintBoard(board);
				printf("\n");
				printf("congratulations player %d, you are the winner!\n", *currentPlayer);
				if (*currentPlayer == PLAYER1)
					UpdateStats(MODE_PVP, 0, RESULT_P1_WIN);
				else
					UpdateStats(MODE_PVP, 0, RESULT_P2_WIN);
				winner = 1;
				wait();
				wait();
				ClearScreen();
			}
			else
			{
				if (*currentPlayer == PLAYER1)
					*currentPlayer = PLAYER2;
				else
					*currentPlayer = PLAYER1;
			}
		}
		else
		{
			printf("Column is full! Try a different one.\n");
		}
	}
	if (winner == 0)
	{
		PrintBoard(board);
		printf("\n");
		printf("Draw! No more available moves.\n");
		UpdateStats(MODE_PVP, 0, RESULT_DRAW);
		wait();
		wait();
		ClearScreen();
		return;
	}
}

void PvC(int board[ROWS][COLS], int* currentPlayer, int difficulty)
{
	int col;
	int winner = 0;
	srand(time(NULL));

	while (!FullBoard(board) && winner == 0)
	{
		PrintBoard(board);

		if (*currentPlayer == PLAYER1)
		{
			printf("Player %d, choose a column (1-7): ", *currentPlayer);
			if (scanf_s("%d", &col) != 1)
			{
				while (getchar() != '\n');
				col = -1;
			}
			ClearScreen();
			col = col - 1; //Adjusts player input (1–7) to board index (0–6)
			if (col < 0 || col>COLS)
			{
				ClearScreen(); //
				printf("Invalid column! Try again!\n");
				continue; //Resets the loop without changing the player
			}
			if (DropDisk(board, col, *currentPlayer))
			{
				if (CheckWin(board, *currentPlayer))
				{
					ClearScreen();
					PrintBoard(board);
					printf("\n");
					printf("Congratulations player %d, you are the winner!\n", *currentPlayer);
					UpdateStats(MODE_PVC, difficulty, RESULT_P1_WIN);
					winner = 1;
					wait();
					wait();
					ClearScreen();
					return;
				}
				else
					*currentPlayer = PLAYER2;
			}
			else
			{
				printf("Column is full! Try a different one.\n");
			}
		}
		else
		{
			printf("Computer is thinking...\n");
			wait();
			col = ComMove(board, difficulty, PLAYER2);
			DropDisk(board, col, PLAYER2);
			ClearScreen();
			PrintBoard(board);
			printf("\n");
			if (CheckWin(board, PLAYER2))
			{
				printf("Computer wins!\n");
				UpdateStats(MODE_PVC, difficulty, RESULT_P2_WIN);
				winner = 1;
				wait();
				wait();
				ClearScreen();
				return;
			}
			else
			{
				ClearScreen();
				printf("Computer chose column %d\n", col + 1);
				*currentPlayer = PLAYER1;
			}
		}
	}
	if (winner == 0)
	{
		PrintBoard(board);
		printf("\n");
		printf("Draw! No more available moves.\n");
		UpdateStats(MODE_PVC, difficulty, RESULT_DRAW);
		wait();
		wait();
		ClearScreen();
		return;
	}
}

#include <stdlib.h>
#include "board.h"
#include "diff.h"
#include "game.h"

static int RandomCol(int board[ROWS][COLS]) //A function that chooses a random column
{
	int col;

	do
	{
		col = rand() % COLS;
	} while (board[0][col] != 0);
	return col;
}

int ComMove(int board[ROWS][COLS], int ComDiff, int ComPlayer) //Computer move based on the difficulty
{
	int opp;

	if (ComPlayer == PLAYER2)
		opp = PLAYER1;
	else
		opp = PLAYER2;

	if (ComDiff == EASY) //Easy level
		return RandomCol(board); //Computer chooses a random column

	if (ComDiff == MEDIUM) //Medium level
	{
		int tempBoard[ROWS][COLS];
		for (int j = 0; j < COLS; j++) //Looks for a winning column and plays it if found
		{
			if (board[0][j] == EMPTY)
			{
				for (int r = 0; r < ROWS; r++)
				{
					for (int c = 0; c < COLS; c++)
					{
						tempBoard[r][c] = board[r][c];
					}
				}
				DropDisk(tempBoard, j, ComPlayer);
				if (CheckWin(tempBoard, ComPlayer))
					return j;
			}
		}
		return RandomCol(board); //If not found, playes a random column
	}

	if (ComDiff == HARD) //Hard level
	{
		int tempBoard[ROWS][COLS];
		for (int j = 0; j < COLS; j++) //Looks for a winning column and plays it if found
		{
			if (board[0][j] == EMPTY)
			{
				for (int r = 0; r < ROWS; r++)
				{
					for (int c = 0; c < COLS; c++)
					{
						tempBoard[r][c] = board[r][c];
					}
				}
				DropDisk(tempBoard, j, ComPlayer);
				if (CheckWin(tempBoard, ComPlayer))
					return j;
			}

		}
		for (int j = 0; j < COLS; j++) //Blocks opponent's winning move if found
		{
			if (board[0][j] == EMPTY)
			{
				for (int r = 0; r < ROWS; r++)
				{
					for (int c = 0; c < COLS; c++)
					{
						tempBoard[r][c] = board[r][c];
					}
				}
				DropDisk(tempBoard, j, opp);
				if (CheckWin(tempBoard, opp))
					return j;
			}
		}
		return RandomCol(board); //If not found any of the two, playes a random column
	}
}

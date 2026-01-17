#include <stdio.h>
#include <stdlib.h>
#include "diff.h"
#include "menu.h"
#include "game.h"
#include "stats.h"

int MainMenu(int* choice) //Main menue
{
	int mode;

	printf("                        _______  _______  __    _  __    _  _______  _______  _______    _   ___ \n");
	printf("                       |       ||       ||  |  | ||  |  | ||       ||       ||       |  | | |   |\n");
	printf("                       |       ||   _   ||   |_| ||   |_| ||    ___||       ||_     _|  | |_|   |\n");
	printf("                       |       ||  | |  ||       ||       ||   |___ |       |  |   |    |       |\n");
	printf("                       |      _||  |_|  ||  _    ||  _    ||    ___||      _|  |   |    |___    |\n");
	printf("                       |     |_ |       || | |   || | |   ||   |___ |     |_   |   |        |   |\n");
	printf("                       |_______||_______||_|  |__||_|  |__||_______||_______|  |___|        |___|\n");
	printf("\n");
	printf("        1. Player VS Player        2. Player VS Computer        3. Game statistics        4. About        5. Exit\n");
	printf("\n");
	printf("                                                  Enter your choice: ");
	if (scanf_s("%d", &mode) != 1)
	{
		while (getchar() != '\n');
		mode = 0;
	}
		if (mode == 1)
		{
			*choice = 0;
		}
		if (mode == 2)
		{
			while (1)
			{
				ClearScreen();
				printf("Choose difficulty:\n");
				printf("\n");
				printf("1. Easy\n");
				printf("2. Medium\n");
				printf("3. Hard\n");
				if (scanf_s("%d", choice) != 1)
				{
					while (getchar() != '\n');
					printf("\nInvalid input! Please enter a number.\n");
					wait();
					wait();
					continue;
				}

				if (*choice < 1 || *choice > 3)
				{
					printf("\nInvalid choice! Please choose 1-3.\n");
					wait();
					wait();
					continue;
				}
				break;
			}
			
			return mode;
		}

		else if (mode == 3)
		{
			DisplayStats();
			return MainMenu(choice);
		}


		else if (mode == 4)
		{

			ClearScreen();
			return 4;

		}

		else if (mode > 5 || mode < 1)
		{
			ClearScreen();
			printf("Invalid! Try again\n");
			return MainMenu(choice);
		}


		return mode;
}

void about()//About menu
{
	int choice;

	while (1)
	{
		ClearScreen();
		printf("About Menu - Choose one:\n");
		printf("\n");
		printf("1. How to play\n");
		printf("2. About the game\n");
		printf("3. Back to main menu\n");
		if (scanf_s("%d", &choice) != 1)
		{
			while (getchar() != '\n');
			choice = -1;
		}

		if (choice == 1)
		{
			int back = 0;
			while (back != 1)
			{
				ClearScreen();
				printf("How to Play Connect 4\n");
				printf("\n");
				printf("Objective:\n");
				printf("Be the first to align four of your pieces in a row- vertically, horizontally, or diagonally.\n");
				printf("\n");
				printf("Players:\n");
				printf("Two players take turns.\n");
				printf("each player plays different color\n");
				printf("\n");
				printf("Gameplay:\n");
				printf("1. Choose a column to drop your piece.\n");
				printf("2. The piece will occupy the lowest available space in that column.\n");
				printf("3. Players alternate turns.\n");
				printf("4. The game ends when:\n");
				printf("   -A player connects four in a row, they win.\n");
				printf("   -The board is full with no winner, it's a tie.\n");
				printf("\n");
				printf("Tips:\n");
				printf("   -Pay attention to both offense and defense, block your opponent while building your line.\n");
				printf("   -Think a few moves ahead, sometimes setting traps is more effective than immediate wins.\n");
				printf("\n");
				printf("Enjoy the game!\n");
				printf("\n");
				printf("\n");
				printf("press 1 to go back\n");
				if (scanf_s("%d", &back) != 1)
				{
					while (getchar() != '\n');
					back = -1;
				}
				ClearScreen();
			}
		}
		else if (choice == 2)
		{
			int back = 0;
			while (back != 1)
			{
				ClearScreen();
				printf("About the game\n");
				printf("\n");
				printf("This Connect 4 game was developed as a project to practice programming in C\n");
				printf("It simulates the classic two-player connection game, allowing either Player vs Player or Player vs Computer gameplay\n");
				printf("\n");
				printf("The code focuses on:\n");
				printf("Using arrays to represent the board\n");
				printf("Implementing game logic for checking wins\n");
				printf("Handling player input and computer AI with different difficulty levels\n");
				printf("\n");
				printf("The goal of this project is to combine logic, problem solving, and C programming skills into a fully functional console game.\n");
				printf("\n");
				printf("The game was created by Meidad Shemesh\n");
				printf("\n");
				printf("Hope you enjoy the game!\n");
				printf("\n");
				printf("\n");
				printf("press 1 to go back\n");
				if (scanf_s("%d", &back) != 1)
				{
					while (getchar() != '\n');
					back = -1;
				}
				ClearScreen();
			}
		}
		else if (choice == 3)
		{
			ClearScreen();
			break;
		}
		if (choice < 1 || choice > 3)
		{
			continue;
		}
	}

}

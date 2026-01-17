#include <stdio.h>
#include <stdlib.h>
#include "stats.h"
#include "game.h"
#include "diff.h"

#define STATS_FILE "connect4_stats.txt"

typedef struct {
	int p1Wins;
	int p2Wins; //Player 2 or the computer
	int draws;
} StatRecord;

StatRecord allStats[4];

static void SaveStatsToFile();

// Saves the file
static void SaveStatsToFile()
{
	FILE* file;
	if (fopen_s(&file, STATS_FILE, "w") == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			fprintf(file, "%d %d %d\n", allStats[i].p1Wins, allStats[i].p2Wins, allStats[i].draws);
		}
		fclose(file);
	}
	else
	{
		printf("Error saving statistics!\n");
	}
}

//Loads the stats from the file
static void LoadStatsFromFile()
{
	FILE* file;
	if (fopen_s(&file, STATS_FILE, "r") == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			fscanf_s(file, "%d %d %d", &allStats[i].p1Wins, &allStats[i].p2Wins, &allStats[i].draws);
		}
		fclose(file);
	}
	else
	{
		//If file doesn't exist, initialize all stats to 0
		for (int i = 0; i < 4; i++)
		{
			allStats[i].p1Wins = 0;
			allStats[i].p2Wins = 0;
			allStats[i].draws = 0;
		}
		SaveStatsToFile(); //Creates the file
	}
}

void InitStats()
{
	LoadStatsFromFile();
}

void UpdateStats(int mode, int difficulty, int result)
{
	LoadStatsFromFile(); //Looks for the latest data

	int index = -1;

	if (mode == MODE_PVP)
	{
		index = 0;
	}
	else if (mode == MODE_PVC)
	{

		if (difficulty >= EASY && difficulty <= HARD)
		{
			index = difficulty;
		}
	}

	if (index != -1)
	{
		if (result == RESULT_P1_WIN) allStats[index].p1Wins++;
		else if (result == RESULT_P2_WIN) allStats[index].p2Wins++;
		else if (result == RESULT_DRAW) allStats[index].draws++;

		SaveStatsToFile();
	}
}

void DisplayStats()
{
	LoadStatsFromFile();
	ClearScreen();

	printf("==================================================\n");
	printf("                ALL-TIME STATISTICS               \n");
	printf("==================================================\n");

	printf("%-15s | %-10s | %-10s | %-8s\n", "MODE", "P1 WINS", "P2/COM WINS", "DRAWS");
	printf("--------------------------------------------------\n");

	//PvP
	printf("%-15s | %-10d | %-10d | %-8d\n",
		"PvP", allStats[0].p1Wins, allStats[0].p2Wins, allStats[0].draws);

	//Easy level
	printf("%-15s | %-10d | %-10d | %-8d\n",
		"PvC (Easy)", allStats[1].p1Wins, allStats[1].p2Wins, allStats[1].draws);

	//Medium level
	printf("%-15s | %-10d | %-10d | %-8d\n",
		"PvC (Medium)", allStats[2].p1Wins, allStats[2].p2Wins, allStats[2].draws);

	//Hard level
	printf("%-15s | %-10d | %-10d | %-8d\n",
		"PvC (Hard)", allStats[3].p1Wins, allStats[3].p2Wins, allStats[3].draws);

	printf("==================================================\n");
	printf("\nPress 1 to return to Main Menu...\n");

	int temp;
	scanf_s("%d", &temp);
	ClearScreen();
}
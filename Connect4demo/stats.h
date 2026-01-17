#ifndef STATS_H
#define STATS_H

#define MODE_PVP 1
#define MODE_PVC 2

#define RESULT_P1_WIN 1
#define RESULT_P2_WIN 2
#define RESULT_DRAW 3


void InitStats();
void UpdateStats(int mode, int difficulty, int result);
void DisplayStats();

#endif
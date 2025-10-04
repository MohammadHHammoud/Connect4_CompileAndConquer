#ifndef GAME_H
#define GAME_H

#define ROWS 6
#define COLS 7
char Board[ROWS][COLS];

int DiscsPerIndex[COLS]={0,0,0,0,0,0,0};

char playerA;
char playerB;
char currentPlayer;

void InitializeGame(char b[ROWS][COLS]);

void initializeBoard(char board[ROWS][COLS]);

void Display(char b[ROWS][COLS]);

int MakeMove(char b[ROWS][COLS], int col);

int CheckWin(char b[ROWS][COLS], int lastRow, int lastCol);

int FullBoard(char b[ROWS][COLS]);

void SwitchPlayer(char *currentPlayer, char playerA, char playerB);

#endif

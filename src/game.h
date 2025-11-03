#ifndef GAME_H
#define GAME_H

#define ROWS 6
#define COLS 7
extern char Board[ROWS][COLS];

extern int DiscsPerIndex[COLS];

extern char playerA;
extern char playerB;
extern int colorA;
extern int colorB;
extern char currentPlayer;

extern int gameMode;
extern int difficulty;

void InitializeGame(char b[ROWS][COLS]);

void initializeBoard(char board[ROWS][COLS]);

void Display(char b[ROWS][COLS]);

int MakeMove(char b[ROWS][COLS], int col);

int MakeMoveAI(char b[ROWS][COLS], int difficulty);

int CheckWin(char b[ROWS][COLS], char symbol);

int FullBoard();

void SwitchPlayer(char *currentPlayer, char playerA, char playerB);

#endif

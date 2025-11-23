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

void InitializeGame();

void initializeBoard();

void Display();

int MakeMove(int col);

int MakeMoveAI();

int CheckWin(char player);

int FullBoard();

void SwitchPlayer();

#endif

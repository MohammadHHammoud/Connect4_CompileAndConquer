#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

void InitializeGame(char board[ROWS][COLS]){
    printf("Welcome to Connect Four!\nPlayer A: ");
    scanf(" %c", &playerA); 
    playerA = toupper(playerA);
    printf("\nPlayer B: " );
    scanf(" %c", &playerB);
    playerB = toupper(playerB);
    while(playerA == playerB){
        printf("Player B cannot be the same as Player A.\nEnter again: ");
        scanf(" %c", &playerB);
        playerB = toupper(playerB);
    }
    initializeBoard(board);
    Display(board);
}


void initializeBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
}

void Display(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("1 2 3 4 5 6 7\n");
}

int MakeMove(char b[ROWS][COLS], int col){
    //TO DO
    /*Returns:

0 → success

-1 → invalid column

-2 → column full*/
}

int CheckWin(char b[ROWS][COLS], int lastRow, int lastCol){
    //TO DO
}
int FullBoard(char b[ROWS][COLS]){
    for(int i=0; i<COLS; i++){
        if(DiscsPerIndex[i]<ROWS){
            return 0;
        }
    }
    return 1;
}

void SwitchPlayer(char *currentPlayer, char playerA, char playerB){
    if(*currentPlayer == playerA){
        *currentPlayer = playerB;
    } else {
        *currentPlayer = playerA;
    }
}


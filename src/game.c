#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

char Board[ROWS][COLS];
int DiscsPerIndex[COLS] = {0, 0, 0, 0, 0, 0, 0};
char playerA = 'A';
char playerB = 'B';
char currentPlayer = 'A';

void InitializeGame(char board[ROWS][COLS]){
    printf("Welcome to Connect Four!\nPlayer A: ");
    scanf(" %c", &playerA); 
    playerA = toupper(playerA);
    printf("Player B: " );
    scanf(" %c", &playerB);
    playerB = toupper(playerB);
    while(playerA == playerB){
        printf("Player B cannot be the same as Player A.\nEnter again: ");
        scanf(" %c", &playerB);
        playerB = toupper(playerB);
    }
    currentPlayer = playerA;
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
    col++;
    if(col < 1 || col > COLS){  
        return -1;
    }
    int c = col - 1;  
    if(DiscsPerIndex[c] >= ROWS){  
        return -2;
    }
    int row = ROWS - DiscsPerIndex[c] - 1;
    b[row][c] = currentPlayer;
    DiscsPerIndex[c]++;
    return 0;  
}

int CheckWin(char board[ROWS][COLS],char symbol) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (board[r][c] == symbol &&
                board[r][c+1] == symbol &&
                board[r][c+2] == symbol &&
                board[r][c+3] == symbol) {
                return 1;
            }
        }
    }
    for (int c = 0; c < COLS; c++) {
        for (int r = 0; r <= ROWS - 4; r++) {
            if (board[r][c] == symbol &&
                board[r+1][c] == symbol &&
                board[r+2][c] == symbol &&
                board[r+3][c] == symbol) {
                return 1;
            }
        }
    }
    for (int r = 0; r <= ROWS - 4; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (board[r][c] == symbol &&
                board[r+1][c+1] == symbol &&
                board[r+2][c+2] == symbol &&
                board[r+3][c+3] == symbol) {
                return 1;
            }
        }
    }
    for (int r = 0; r <= ROWS - 4; r++) {
        for (int c = 3; c < COLS; c++) {
            if (board[r][c] == symbol &&
                board[r+1][c-1] == symbol &&
                board[r+2][c-2] == symbol &&
                board[r+3][c-3] == symbol) {
                return 1;
            }
        }
    }
    return 0;
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


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

int CheckWin(char b[ROWS][COLS], int lastRow, int lastCol){
    char player = b[lastRow][lastCol];
    if(player == '.') return 0;
    int dirs[4][2] = {{0,1},{1,0},{1,1},{1,-1}};
    for(int d=0; d<4; d++){
        int count = 1;
        int dr = dirs[d][0], dc = dirs[d][1];
        int r = lastRow + dr, c = lastCol + dc;
        while(r>=0 && r<ROWS && c>=0 && c<COLS && b[r][c]==player){
            count++;
            r += dr; c += dc;
        }
        r = lastRow - dr; c = lastCol - dc;
        while(r>=0 && r<ROWS && c>=0 && c<COLS && b[r][c]==player){
            count++;
            r -= dr; c -= dc;
        }
        if(count >= 4){
            return 1;
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "game.h"

char Board[ROWS][COLS];
int DiscsPerIndex[COLS] = {0, 0, 0, 0, 0, 0, 0};
char playerA = 'A';
char playerB = 'B';
char currentPlayer = 'A';
int gameMode = 1;
int difficulty = 1;

void InitializeGame(char board[ROWS][COLS]){
    printf("Welcome to Connect Four!\n   1) Multiplayer\n   2) Single Player\nSelect an option [1-2]:");
    int option;
    scanf("%d", &option);
    while(option != 1 && option != 2){
        printf("Invalid option. Please select 1 or 2: ");
        scanf("%d", &option);
    }
    if(option == 1){
    printf("Player A: " );
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
    } else {
        gameMode = 2;
        printf("Difficulty Levels:\n    1) Easy\n    2) Medium\n    3) Hard\nSelect a difficulty level [1-3]: ");
        int dif;
        scanf("%d", &dif);
        while(dif < 1 || dif > 3){
            printf("Invalid option. Please select a difficulty level [1-3]: ");
            scanf("%d", &dif);
        }
        if(dif==3){
            printf("Hard difficulty not yet implemented. Defaulting to Medium difficulty.\n");
            dif = 2;
        }
        difficulty = dif;
        printf("Enter your preferred character: ");
        scanf(" %c", &playerA);
        playerA = toupper(playerA);
        if(playerA != 'C') playerB = 'C';
        else playerB = 'E';
        currentPlayer = playerA;
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
    if(gameMode == 2 && currentPlayer == playerB){ 
        col=MakeMoveAI(b, col, difficulty)+1;
    } else {
        col++;
        if(col < 1 || col > COLS){  
            return -1;
        }
    }
    if(DiscsPerIndex[col-1] >= ROWS){  
        return -2;
    }
    int row = ROWS - DiscsPerIndex[col-1] - 1;
    b[row][col-1] = currentPlayer;
    DiscsPerIndex[col-1]++;
    return 0;  
}

int MakeMoveAI(char b[ROWS][COLS], int col, int difficulty){
    if(difficulty == 1){
        srand(time(NULL));
        int c;
        do{
            c = rand() % COLS; 
        }while (DiscsPerIndex[c] >= ROWS); 
        return c;
    }
    if(difficulty == 2){
        for(int c = 0; c<COLS; c++){
            if(DiscsPerIndex[c]<ROWS){
                int r = ROWS - DiscsPerIndex[c] - 1;
                b[r][c] = playerB;
                if(CheckWin(b, playerB)){
                    b[r][c] = '.';
                    return c;
                }
                b[r][c] = '.';
            }
        }
        for(int c = 0; c<COLS; c++){
            if(DiscsPerIndex[c]<ROWS){
                int r = ROWS - DiscsPerIndex[c] - 1;
                b[r][c] = playerA;
                if(CheckWin(b, playerA)){
                    b[r][c] = '.';
                    return c;
                }
                b[r][c] = '.';
            }
        }
        srand(time(NULL));
        int c;
        do{
            c = rand() % COLS; 
        }while (DiscsPerIndex[c] >= ROWS); 
        return c;
    }
    if(difficulty == 3){
        
    }
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
    *currentPlayer = (*currentPlayer == playerA) ? playerB : playerA;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <pthread.h>
#include "game.h"

#define legalMove(c) ( c >= 0 && c < COLS && DiscsPerIndex[(c)] < ROWS )

char Board[ROWS][COLS];
int DiscsPerIndex[COLS] = {0, 0, 0, 0, 0, 0, 0};
int columnOrder[COLS]   = {3, 2, 4, 1, 5, 0, 6};
char playerA, playerB, currentPlayer;
int gameMode, difficulty, colorA, colorB;

void InitializeGame(){
    srand(time(NULL));
    printf("Welcome to Connect Four!\n   1) Multiplayer\n   2) Single Player\nSelect an option [1-2]:");
    int option;
    int s = scanf("%d", &option);
    while (s==0)
    {
        printf("Please input a valid number: ");
        s = scanf("%d", &option);
    }
    
    while(option != 1 && option != 2){
        printf("Invalid option. Please select 1 or 2: ");
        scanf("%d", &option);
    }
    if(option == 1){
    printf("Player A: " );
    scanf(" %c", &playerA);
    playerA = toupper(playerA);
    printf("Choose a color for player %c :\n", playerA);
    printf("  1) White\n  \033[1;31m2) Red \033[0m\n  \033[1;32m3) Green \033[0m\n  \033[1;34m4) Blue \033[0m\n  \033[1;33m5) Yellow \033[0m\n  \033[1;35m6) Magenta \033[0m\n  \033[1;36m7) Cyan \033[0m\nSelect a number (1-7): ");
    int choiceA;
    scanf("%d", &choiceA);
    while(choiceA < 1 || choiceA > 7){
        printf("Invalid input. Please select a number from 1 to 7:");
        scanf("%d", &choiceA);
    }
    switch (choiceA){
        case 1: colorA = 37; break;
        case 2: colorA = 31; break;
        case 3: colorA = 32; break;
        case 4: colorA = 34; break;
        case 5: colorA = 33; break;
        case 6: colorA = 35; break;
        case 7: colorA = 36; break;
        default: colorA = 37; break;
    }
    printf("Player B: " );
    scanf(" %c", &playerB);
    playerB = toupper(playerB);
    while(playerA == playerB){
        printf("Player B cannot be the same as Player A.\nEnter again: ");
        scanf(" %c", &playerB);
        playerB = toupper(playerB);
    }
    printf("Choose a color for player %c :\n", playerB);
    printf("  1) White\n  \033[1;31m2) Red \033[0m\n  \033[1;32m3) Green \033[0m\n  \033[1;34m4) Blue \033[0m\n  \033[1;33m5) Yellow \033[0m\n  \033[1;35m6) Magenta \033[0m\n  \033[1;36m7) Cyan \033[0m\nSelect a number (1-7): ");
    int choiceB;
    scanf("%d", &choiceB);
    while(choiceB < 1 || choiceB > 7){
        printf("Invalid input. Please select a number from 1 to 7:");
        scanf("%d", &choiceB);
    }
    switch (choiceB){
        case 1: colorB = 37; break;
        case 2: colorB = 31; break;
        case 3: colorB = 32; break;
        case 4: colorB = 34; break;
        case 5: colorB = 33; break;
        case 6: colorB = 35; break;
        case 7: colorB = 36; break;
        default: colorB = 37; break;
    }
    currentPlayer = playerA;
    } else {
        gameMode = 2;
        playerB = '@';
        printf("Difficulty Levels:\n    1) Easy\n    2) Medium\n    3) Hard\nSelect a difficulty level [1-3]: ");
        int dif;
        scanf("%d", &dif);
        while(dif < 1 || dif > 3){
            printf("Invalid option. Please select a difficulty level [1-3]: ");
            scanf("%d", &dif);
        }
        if(dif==1) colorB=34;
        else if(dif==2) colorB=32;
        else if(dif==3) colorB=31;
        difficulty = dif;
        printf("Enter your preferred character: ");
        scanf(" %c", &playerA);
        playerA = toupper(playerA);
        int choice;
        printf("Choose your color:\n  1) White\n  \033[1;31m2) Red \033[0m\n  \033[1;32m3) Green \033[0m\n  \033[1;34m4) Blue \033[0m\n  \033[1;33m5) Yellow \033[0m\n  \033[1;35m6) Magenta \033[0m\n  \033[1;36m7) Cyan \033[0m\n");
        printf("Select a number (1-7): ");
        scanf("%d", &choice);
        while(choice < 1 || choice > 7){
            printf("Invalid input. Please select a number from 1 to 7:");
            scanf("%d", &choice);
        }
        switch (choice){
        case 1: colorA = 37; break;
        case 2: colorA = 31; break;
        case 3: colorA = 32; break;
        case 4: colorA = 34; break;
        case 5: colorA = 33; break;
        case 6: colorA = 35; break;
        case 7: colorA = 36; break;
        default: colorA = 37; break;
        }
        currentPlayer = playerA;
    }
    initializeBoard();
    Display();
}


void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Board[i][j] = '.';
        }
    }
}

void Display(){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(Board[i][j] == playerA)
                printf("\033[%dm%c \033[0m", colorA, Board[i][j]);
            else if(Board[i][j] == playerB)
                printf("\033[1;%dm%c \033[0m", colorB, Board[i][j]);
            else
                printf("%c ", Board[i][j]);
        }
        printf("\n");
    }
    printf("1 2 3 4 5 6 7\n");
}

int MakeMove(int col){ 
    if(gameMode == 2 && currentPlayer == playerB){ 
        col=MakeMoveAI()+1;
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
    Board[row][col-1] = currentPlayer;
    DiscsPerIndex[col-1]++;
    return 0;  
}
static int ScoreWindow(int a, int o, int e) {
    if (a && o) return 0;
    if (a == 4) return 100000;
    if (a == 3 && e == 1) return 180;
    if (a == 2 && e == 2) return 20;
    if (o == 3 && e == 1) return -170;
    if (o == 2 && e == 2) return -18;
    return 0;
}
int MakeMoveAI(){
    if(difficulty == 1){
        int c;
        do{
            c = rand() % COLS; 
        }while (DiscsPerIndex[c] >= ROWS); 
        return c;
    }
    if(difficulty == 2){
        for(int c = 0; c<COLS; c++){
            if(!legalMove(c)) continue;
            int r = ROWS - DiscsPerIndex[c] - 1;
            Board[r][c] = playerB;
            if(CheckWin(playerB)){
                Board[r][c] = '.';
                return c;
            }
            Board[r][c] = '.';
        }
        for(int c = 0; c<COLS; c++){
            if(!legalMove(c)) continue;
            int r = ROWS - DiscsPerIndex[c] - 1;
            Board[r][c] = playerA;
            if(CheckWin(playerA)){
                Board[r][c] = '.';
                return c;
            }
            Board[r][c] = '.';
        }
        int c;
        do{
            c = rand() % COLS; 
        } while (!legalMove(c)); 
        return c;
    }
    if(difficulty == 3){
        for(int c = 0; c<COLS; c++){
            if(!legalMove(c)) continue;
            int r = ROWS - DiscsPerIndex[c] - 1;
            Board[r][c] = playerB;
            if(CheckWin(playerB)){
                Board[r][c] = '.';
                return c;
            }
            Board[r][c] = '.';
        }
        for(int c = 0; c<COLS; c++){
            if(!legalMove(c)) continue;
            int r = ROWS - DiscsPerIndex[c] - 1;
            Board[r][c] = playerA;
            if(CheckWin(playerA)){
                Board[r][c] = '.';
                return c;
            }
            Board[r][c] = '.';
        }
        for(int c = 0; c < COLS; c++){
            if(!legalMove(c)) continue;
            int r = ROWS - DiscsPerIndex[c] - 1;
            Board[r][c] = playerB;
            int wins = 0;
            for(int c2 = 0; c2 < COLS && wins < 2; c2++){
                int add = (c2 == c) ? 1 : 0;
                if(DiscsPerIndex[c2] + add >= ROWS)
                    continue;
                int r2 = ROWS - (DiscsPerIndex[c2] + add) - 1;
                Board[r2][c2] = playerB;
                if(CheckWin(playerB))
                    wins++;
                Board[r2][c2] = '.';
            }
            Board[r][c] = '.';
            if (wins >= 2)
                return c;
        }
    int bestCol = -1;
    int bestScore = -1000000000;
    for (int oi = 0; oi < 7; ++oi) {
        int c = columnOrder[oi];
        if (!legalMove(c)) continue;
        int r = ROWS - DiscsPerIndex[c] - 1;
        Board[r][c] = playerB;
        int oppCanWin = 0;
        for (int oc = 0; oc < COLS && !oppCanWin; ++oc) {
            int add = (oc == c) ? 1 : 0;
            if (DiscsPerIndex[oc] + add >= ROWS) continue;
            int orow = ROWS - (DiscsPerIndex[oc] + add) - 1;
            Board[orow][oc] = playerA;
            if (CheckWin(playerA)) oppCanWin = 1;
            Board[orow][oc] = '.';
        }
        int s;
        if (oppCanWin) {
            s = -10000000;
        } 
        else {
            s = 0;
            for (int rr = 0; rr < ROWS; ++rr) {
                if (Board[rr][3] == playerB) s += 6;
                else if (Board[rr][3] == playerA) s -= 6;
            }
            for (int rr = 0; rr < ROWS; ++rr)
                for (int cc = 0; cc <= COLS - 4; ++cc) {
                    int a = 0, o = 0, e = 0;
                    for (int k = 0; k < 4; k++) {
                        char v = Board[rr][cc + k];
                        if (v == playerB) a++;
                        else if (v == playerA) o++;
                        else e++;
                    }
                    s += ScoreWindow(a, o, e);
                }
            for (int cc = 0; cc < COLS; ++cc)
                for (int rr = 0; rr <= ROWS - 4; ++rr) {
                    int a = 0, o = 0, e = 0;
                    for (int k = 0; k < 4; k++) {
                        char v = Board[rr + k][cc];
                        if (v == playerB) a++;
                        else if (v == playerA) o++;
                        else e++;
                    }
                    s += ScoreWindow(a, o, e);
                }
            for (int rr = 0; rr <= ROWS - 4; ++rr)
                for (int cc = 0; cc <= COLS - 4; ++cc) {
                    int a = 0, o = 0, e = 0;
                    for (int k = 0; k < 4; k++) {
                        char v = Board[rr + k][cc + k];
                        if (v == playerB) a++;
                        else if (v == playerA) o++;
                        else e++;
                    }
                    s += ScoreWindow(a, o, e);
                }
            for (int rr = 3; rr < ROWS; ++rr)
                for (int cc = 0; cc <= COLS - 4; ++cc) {
                    int a = 0, o = 0, e = 0;
                    for (int k = 0; k < 4; k++) {
                        char v = Board[rr - k][cc + k];
                        if (v == playerB) a++;
                        else if (v == playerA) o++;
                        else e++;
                    }
                    s += ScoreWindow(a, o, e);
                }
        }
        Board[r][c] = '.';
        if (s > bestScore) {
            bestScore = s;
            bestCol = c;
        }
    }
    if (bestCol != -1) return bestCol;
    if (bestCol == -1)
            for (int c = 0; c < COLS; c++)
                if (legalMove(c)) return columnOrder[c];
   }
}
int CheckWin(char player) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (Board[r][c] == player &&
                Board[r][c+1] == player &&
                Board[r][c+2] == player &&
                Board[r][c+3] == player) {
                return 1;
            }
        }
    }
    for (int c = 0; c < COLS; c++) {
        for (int r = 0; r <= ROWS - 4; r++) {
            if (Board[r][c] == player &&
                Board[r+1][c] == player &&
                Board[r+2][c] == player &&
                Board[r+3][c] == player) {
                return 1;
            }
        }
    }
    for (int r = 0; r <= ROWS - 4; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (Board[r][c] == player &&
                Board[r+1][c+1] == player &&
                Board[r+2][c+2] == player &&
                Board[r+3][c+3] == player) {
                return 1;
            }
        }
    }
    for (int r = 0; r <= ROWS - 4; r++) {
        for (int c = 3; c < COLS; c++) {
            if (Board[r][c] == player &&
                Board[r+1][c-1] == player &&
                Board[r+2][c-2] == player &&
                Board[r+3][c-3] == player) {
                return 1;
            }
        }
    }
    return 0;
}

int FullBoard(){
    for(int i=0; i<COLS; i++){
        if(DiscsPerIndex[i]<ROWS){
            return 0;
        }
    }
    return 1;
}

void SwitchPlayer(){
    currentPlayer = (currentPlayer == playerA) ? playerB : playerA;
}


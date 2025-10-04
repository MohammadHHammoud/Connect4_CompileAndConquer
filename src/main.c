#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

int main(){
    InitializeGame(Board);
    while (1){
        printf("Player %c, choose a column (1-7): ", currentPlayer);
        int col;
        scanf("%d", &col);
        int row = MakeMove(Board, col - 1);
        if (row == -1){
            printf("Invalid column.\n");
            continue;
        } else if (row == -2){
            printf("Column %d is full. Try another.\n", col);
            continue;
        } else {
            Display(Board);
            if (FullBoard(Board)){
                printf("It is a draw!\n");
                break;
            }
            if (CheckWin(Board, currentPlayer)){
                printf("Player %c wins!\n", currentPlayer);
                break;
            }
            SwitchPlayer(&currentPlayer, playerA, playerB);
        }
    }
    
}

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
            while(MakeMove(Board, col - 1) == -1){
                printf("Invalid column. Choose a column (1-7): ");
                scanf("%d", &col);
            }
        } else if (row == -2){
            while (MakeMove(Board, col - 1) == -2){
                printf("Column %d is full. Try again.\n", col);
                scanf("%d", &col);
            }
        } else {
            Display(Board);
            if (FullBoard(Board)){
                printf("It is a draw!\n");
                break;
            }
            if (CheckWin(Board, row, col - 1)){
                printf("Player %c wins!\n", currentPlayer);
                break;
            }
            SwitchPlayer(&currentPlayer, playerA, playerB);
        }
    }
    
}

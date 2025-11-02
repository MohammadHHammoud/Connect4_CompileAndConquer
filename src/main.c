#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

int main(){
    InitializeGame(Board);
    while (1){
        if(gameMode == 2 && currentPlayer == playerB){
            int row = MakeMove(Board, -1);
            Display(Board);
            if (FullBoard(Board)){
                printf("It is a draw!\n");
                break;
            }
            if (CheckWin(Board, currentPlayer)){
                    printf("Computer wins!\n");
                break;
            }
            SwitchPlayer(&currentPlayer, playerA, playerB);
        } else {
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
                if(gameMode == 2)
                    printf("You win!\n");
                else
                    printf("Player %c wins!\n", currentPlayer);
                break;
            }
            SwitchPlayer(&currentPlayer, playerA, playerB);
        }
    }
    }
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

int main(){
    InitializeGame();
    while (1){
        if(gameMode == 2 && currentPlayer == playerB){
            MakeMove(-1);
            Display();
            if (FullBoard()){
                printf("It is a draw!\n");
                break;
            }
            if (CheckWin(currentPlayer)){
                    printf("Computer wins!\n");
                break;
            }
            SwitchPlayer();
        } else {
        printf("Player %c, choose a column (1-7): ", currentPlayer);
        int col;
        scanf("%d", &col);
        int row = MakeMove(col - 1);
        if (row == -1){
            printf("Invalid column.\n");
            continue;
        } else if (row == -2){
            printf("Column %d is full. Try another.\n", col);
            continue;
        } else {
            Display();
            if (FullBoard()){
                printf("It is a draw!\n");
                break;
            }
            if (CheckWin(currentPlayer)){
                if(gameMode == 2)
                    printf("You win!\n");
                else
                    printf("Player %c wins!\n", currentPlayer);
                break;
            }
            SwitchPlayer();
        }
    }
    }
    
}

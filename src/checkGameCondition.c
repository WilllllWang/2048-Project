#include "myheader.h"

bool checkLoseCondition(Board *board, Condition *condition) {
    int row, col;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board->grid[row][col].value == 0) {
                return false;
            }
        }
    }//檢查是否還有剩餘的空格   

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE - 1; col++) {
            if (board->grid[row][col].value == board->grid[row][col + 1].value || board->grid[col][row].value == board->grid[col + 1][row].value) {
                return false; 
            }
        }
    }//檢查相鄰的兩格是否數值相同
    condition->gameCondition = 1;
    return true; 
}


bool checkWinCondition(Board *board, Condition *condition) {
    int row, col;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board->grid[row][col].value == WINNING_TILE) {
                condition->gameCondition = 2;
                return true;
            }
        }
    }//檢查版上是否有任一格達2048
    
    return false;
}


    
    






  
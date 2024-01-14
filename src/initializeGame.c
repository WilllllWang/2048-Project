#include "myheader.h"

void initializeGame(Board *board, Condition *condition) {
    board->score = 0;
    condition->gameCondition = 0;
  
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            board->grid[row][col].value = 0;
        }
    }
}
#include "myheader.h"

void generateNewTile(Board *board) {
    int row, col;
    row = rand() % BOARD_SIZE;
    col = rand() % BOARD_SIZE;
    if (!boardFull(board)) {
        while(board->grid[row][col].value != 0){
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } 

        int newValue = (rand() % 10 == 0) ? 4 : 2;
        board->grid[row][col].value = newValue; 
    }
}


bool boardFull(Board *board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board->grid[row][col].value == 0) {
                return false;
            }
        }
    }
    return true;
}
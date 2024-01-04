#include "myheader.h"

void initializeGame(Board *board) {
    board->score = 0;//初始化分數為0
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            board->grid[row][col].value = 0;
        }
    }//將板上16個方塊的數值初始化為0
}
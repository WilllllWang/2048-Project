#include "myheader.h"

void initializeGame(Board *board) {
    board->score = 0;//��l�Ƥ��Ƭ�0
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            board->grid[row][col].value = 0;
        }
    }//�N�O�W16�Ӥ�����ƭȪ�l�Ƭ�0
}
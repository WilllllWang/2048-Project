#include "myheader.h"

void generateNewTile(Board *board) {
    int row, col;
    row = rand() % BOARD_SIZE;
    col = rand() % BOARD_SIZE;// �H����ܤ@�Ӧ�M�C����m
    if (!boardFull(board)) {
        while(board->grid[row][col].value != 0){
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } 

        int newValue = (rand() % 10 == 0) ? 4 : 2;// �ھڤ@�w�����v�A�]�w�s������ƭȬ�2��4
        board->grid[row][col].value = newValue;// �b��w����m�W�]�w�s������ƭ�     
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
}//�ˬd�O�W�O�_�٦��ƭȬ�0�����A�Y���~��C���A�Y�L�h��^
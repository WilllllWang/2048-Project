#include "myheader.h"

void generateNewTile(Board *board) {
    int row, col;
    row = rand() % BOARD_SIZE;
    col = rand() % BOARD_SIZE;// 隨機選擇一個行和列的位置
    if (!boardFull(board)) {
        while(board->grid[row][col].value != 0){
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } 

        int newValue = (rand() % 10 == 0) ? 4 : 2;// 根據一定的機率，設定新方塊的數值為2或4
        board->grid[row][col].value = newValue;// 在選定的位置上設定新方塊的數值     
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
}//檢查板上是否還有數值為0的方格，若有繼續遊戲，若無則返回
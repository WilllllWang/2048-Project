#include "myheader.h"

bool moveTilesUp(Board *board) {
    int row, col, row_above;
    bool moved = false;
    for(row = 1; row < BOARD_SIZE; row++){//從第二行開始向下檢查
        for(col = 0; col < BOARD_SIZE; col++){
            if(board->grid[row][col].value != 0){
                for(row_above = row - 1; row_above >= 0; row_above--){
                    if(board->grid[row_above][col].value == 0){// 如果該方塊上面的位置是空的，將方塊向上移動
                        board->grid[row_above][col].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        row = row_above; 
                        moved = true;
                    } 
                    else if(board->grid[row_above][col].value == board->grid[row][col].value){// 如果上面的方塊數值和該方塊相同，進行合併
                        board->grid[row_above][col].value *= 2;
                        board->grid[row][col].value = 0;
                        board->score += board->grid[row_above][col].value;//更新分數 
                        moved = true;
                        break;
                    } 
                    else{
                        break;//若與上方方塊數值不同，則中斷內層迴圈
                    }
                }
            }
        }
    }
    return moved;
}


bool moveTilesDown(Board *board) {
    int row, col, row_below;
    bool moved = false;
    for(row = BOARD_SIZE-2; row >= 0; row--){//從倒數第二行開始向上檢查
        for(col = 0; col < BOARD_SIZE; col++){
            if(board->grid[row][col].value != 0){
                for(row_below = row + 1; row_below < BOARD_SIZE; row_below++){
                    if(board->grid[row_below][col].value == 0){// 如果該方塊下面的位置是空的，將方塊向下移動
                        board->grid[row_below][col].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        row = row_below; 
                        moved = true;
                    } 
                    else if(board->grid[row_below][col].value == board->grid[row][col].value){// 如果下面的方塊數值和該方塊相同，進行合併
                        board->grid[row_below][col].value *= 2;
                        board->grid[row][col].value = 0;
                        board->score += board->grid[row_below][col].value;// 更新分數
                        moved = true;
                        break;
                    } 
                    else{
                        break;// 如果與下面的方塊數值不同，則中斷內層迴圈
                    }
                    
                }
            }
        }
    }
    return moved;
}


bool moveTilesLeft(Board *board) {
    int row, col, col_left;
    bool moved = false;
    for(row = 0; row < BOARD_SIZE; row++){
        for(col = 1; col < BOARD_SIZE; col++){//從第二列開始向右檢查
            if(board->grid[row][col].value != 0){
                for(col_left = col - 1; col_left >= 0; col_left--){
                    if(board->grid[row][col_left].value == 0){//如果左方的位置是空的，則向左移動
                        board->grid[row][col_left].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        col = col_left; 
                        moved = true;
                    } 
                    else if(board->grid[row][col_left].value == board->grid[row][col].value){//若左方的方塊數值與該方塊相同，進行合併
                        board->grid[row][col_left].value *= 2;
                        board->grid[row][col].value = 0;
                        board->score += board->grid[row][col_left].value;//更新分數
                        moved = true;
                        break;
                    } 
                    else{
                        break;//如果與左方方塊數值不同，則中斷內層迴圈
                    }
                    
                }
            }
        }
    }
    return moved;
}


bool moveTilesRight(Board *board) {
    int row, col, col_right;
    bool moved = false;
    for(row = 0; row < BOARD_SIZE; row++){
        for(col = BOARD_SIZE-2; col >= 0; col--){//從第三列向左開始檢查
            if(board->grid[row][col].value != 0){
                for(col_right = col + 1; col_right < BOARD_SIZE; col_right++){
                    if(board->grid[row][col_right].value == 0){//如果右方的位置是空的，則向右移動
                        board->grid[row][col_right].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        col = col_right; 
                        moved = true;
                    } 
                    else if(board->grid[row][col_right].value == board->grid[row][col].value){//如果右邊的方塊與該方塊數值相同，則進行合併
                        board->grid[row][col_right].value *= 2;
                        board->grid[row][col].value = 0;
                        board->score += board->grid[row][col_right].value;//更新分數
                        moved = true;
                        break;
                    } 
                    else{
                        break;//如果與右方方塊數值不同，則中斷內層迴圈
                    }
                    
                }
            }
        }
    }
    return moved;
}
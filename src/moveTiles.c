#include "myheader.h"

bool moveTilesUp(Board *board, Blank *blank) {
    int row, col, row_above;
    bool moved = false;
    for(row = 1; row < BOARD_SIZE; row++){
        for(col = 0; col < BOARD_SIZE; col++){//從第二列開始向下檢查每行
            if(board->grid[row][col].value != 0){
                for(row_above = row - 1; row_above >= 0; row_above--){
                    if(board->grid[row_above][col].value == 0){
                        board->grid[row_above][col].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        row = row_above; 
                        moved = true;// 如果該方塊上面的位置是空的，將方塊向上移動
                    } 
                    else if(board->grid[row_above][col].value == board->grid[row][col].value){// 如果上面的方塊數值和該方塊相同
                        switch(board->grid[row_above][col].value){
                        case 2: blank->blank2 += board->grid[row_above][col].value; //顯示消掉"2"的方塊數量
                        break;
                        case 4: blank->blank4 += board->grid[row_above][col].value/2;//顯示消掉"4"的方塊數量
                        break;
                        case 8: blank->blank8 += board->grid[row_above][col].value/4;//顯示消掉"8"的方塊數量
                        break;
                        case 16: blank->blank16 += board->grid[row_above][col].value/8;//顯示消掉"16"的方塊數量
                        break;
                        case 32: blank->blank32 += board->grid[row_above][col].value/16;//顯示消掉"32"的方塊數量
                        break;
                        case 64: blank->blank64 += board->grid[row_above][col].value/32;//顯示消掉"64"的方塊數量
                        break;
                        case 128: blank->blank128 += board->grid[row_above][col].value/64;//顯示消掉"128"的方塊數量
                        break;
                        case 256: blank->blank256 += board->grid[row_above][col].value/128;//顯示消掉"256"的方塊數量
                        break;
                        case 512: blank->blank256 += board->grid[row_above][col].value/256;//顯示消掉"512"的方塊數量
                        break;
                        case 1024: blank->blank1024 += board->grid[row_above][col].value/512;//顯示消掉"1024"的方塊數量
                        break;
                        case 2048: blank->blank2048 += board->grid[row_above][col].value/1024;//顯示消掉"2048"的方塊數量
                        break;
                        }
                        board->grid[row_above][col].value *= 2; //將合併之方塊值*2
                        board->grid[row][col].value = 0;//將當前方塊值設為0
                        board->score += board->grid[row_above][col].value;//更新分數
                        moved = true;
                        break;
                    } 
                    else{
                        break; //若與上方方塊數值不同，則中斷內層迴圈
                    }
                }
            }
        }
    }   
    return moved;
}


bool moveTilesDown(Board *board, Blank *blank) {
    int row, col, row_below;
    bool moved = false;
    for(row = BOARD_SIZE-2; row >= 0; row--){
        for(col = 0; col < BOARD_SIZE; col++){//從第三列開始向上檢查每行
            if(board->grid[row][col].value != 0){
                for(row_below = row + 1; row_below < BOARD_SIZE; row_below++){
                    if(board->grid[row_below][col].value == 0){
                        board->grid[row_below][col].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        row = row_below; 
                        moved = true;// 如果該方塊下面的位置是空的，將方塊向下移動
                    } 
                    else if(board->grid[row_below][col].value == board->grid[row][col].value){//如果下方的方塊數值與該方塊相同
                        switch(board->grid[row_below][col].value){
                        case 2: blank->blank2 += board->grid[row_below][col].value;
                        break;
                        case 4: blank->blank4 += board->grid[row_below][col].value/2;
                        break;
                        case 8: blank->blank8 += board->grid[row_below][col].value/4;
                        break;
                        case 16: blank->blank16 += board->grid[row_below][col].value/8;
                        break;
                        case 32: blank->blank32 += board->grid[row_below][col].value/16;
                        break;
                        case 64: blank->blank64 += board->grid[row_below][col].value/32;
                        break;
                        case 128: blank->blank128 += board->grid[row_below][col].value/64;
                        break;
                        case 256: blank->blank256 += board->grid[row_below][col].value/128;
                        break;
                        case 512: blank->blank256 += board->grid[row_below][col].value/256;
                        break;
                        case 1024: blank->blank1024 += board->grid[row_below][col].value/512;
                        break;
                        case 2048: blank->blank2048 += board->grid[row_below][col].value/1024;
                        break;
                        }
                        board->grid[row_below][col].value *= 2;//將合併之方塊值*2
                        board->grid[row][col].value = 0;//將當前方塊值設為0
                        board->score += board->grid[row_below][col].value;//更新分數
                        moved = true;
                        break;
                    } 
                    else{
                        break;//若與下方方塊數值不同，則中斷內層迴圈
                    }
                    
                }
            }
        }
    }
    return moved;
}


bool moveTilesLeft(Board *board, Blank *blank) {
    int row, col, col_left;
    bool moved = false;
    for(row = 0; row < BOARD_SIZE; row++){
        for(col = 1; col < BOARD_SIZE; col++){//從第二行開始向右逐列檢查
            if(board->grid[row][col].value != 0){
                for(col_left = col - 1; col_left >= 0; col_left--){
                    if(board->grid[row][col_left].value == 0){
                        board->grid[row][col_left].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        col = col_left; 
                        moved = true;// 如果該方塊左方的位置是空的，將方塊向左移動
                    } 
                    else if(board->grid[row][col_left].value == board->grid[row][col].value){//如果左方的方塊數值與該方塊相同
                        switch(board->grid[row][col_left].value){
                        case 2: blank->blank2 += board->grid[row][col_left].value;
                        break;
                        case 4: blank->blank4 += board->grid[row][col_left].value/2;
                        break;
                        case 8: blank->blank8 += board->grid[row][col_left].value/4;
                        break;
                        case 16: blank->blank16 += board->grid[row][col_left].value/8;
                        break;
                        case 32: blank->blank32 += board->grid[row][col_left].value/16;
                        break;
                        case 64: blank->blank64 += board->grid[row][col_left].value/32;
                        break;
                        case 128: blank->blank128 += board->grid[row][col_left].value/64;
                        break;
                        case 256: blank->blank256 += board->grid[row][col_left].value/128;
                        break;
                        case 512: blank->blank256 += board->grid[row][col_left].value/256;
                        break;
                        case 1024: blank->blank1024 += board->grid[row][col_left].value/512;
                        break;
                        case 2048: blank->blank2048 += board->grid[row][col_left].value/1024;
                        break;
                        }
                        board->grid[row][col_left].value *= 2;//將合併之方塊值*2
                        board->grid[row][col].value = 0;//將當前方塊值設為0
                        board->score += board->grid[row][col_left].value;//更新分數
                        moved = true;
                        break;
                    } 
                    else{
                        break;//若與左方方塊數值不同，則中斷內層迴圈
                    }
                    
                }
            }
        }
    }
    return moved;
}


bool moveTilesRight(Board *board, Blank *blank) {
    int row, col, col_right;
    bool moved = false;
    for(row = 0; row < BOARD_SIZE; row++){
        for(col = BOARD_SIZE-2; col >= 0; col--){//從第三行開始向左逐列檢查
            if(board->grid[row][col].value != 0){
                for(col_right = col + 1; col_right < BOARD_SIZE; col_right++){
                    if(board->grid[row][col_right].value == 0){
                        board->grid[row][col_right].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        col = col_right; 
                        moved = true;// 如果該方塊右邊的位置是空的，將方塊向右移動
                    } 
                    else if(board->grid[row][col_right].value == board->grid[row][col].value){//如果右方的方塊數值與該方塊相同
                        switch(board->grid[row][col_right].value){
                        case 2: blank->blank2 += board->grid[row][col_right].value;
                        break;
                        case 4: blank->blank4 += board->grid[row][col_right].value/2;
                        break;
                        case 8: blank->blank8 += board->grid[row][col_right].value/4;
                        break;
                        case 16: blank->blank16 += board->grid[row][col_right].value/8;
                        break;
                        case 32: blank->blank32 += board->grid[row][col_right].value/16;
                        break;
                        case 64: blank->blank64 += board->grid[row][col_right].value/32;
                        break;
                        case 128: blank->blank128 += board->grid[row][col_right].value/64;
                        break;
                        case 256: blank->blank256 += board->grid[row][col_right].value/128;
                        break;
                        case 512: blank->blank256 += board->grid[row][col_right].value/256;
                        break;
                        case 1024: blank->blank1024 += board->grid[row][col_right].value/512;
                        break;
                        case 2048: blank->blank2048 += board->grid[row][col_right].value/1024;
                        break;
                        }
                        board->grid[row][col_right].value *= 2;//將合併之方塊值*2
                        board->grid[row][col].value = 0;//將當前方塊值設為0
                        board->score += board->grid[row][col_right].value;//更新分數
                        moved = true;
                        break;
                    } 
                    else{
                        break;//若與右方方塊數值不同，則中斷內層迴圈
                    }
                    
                }
            }
        }
    }
    return moved;
}
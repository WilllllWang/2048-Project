#include "myheader.h"

bool moveTilesUp(Board *board) {
    int row, col, row_above;
    bool moved = false;
    for(row = 1; row < BOARD_SIZE; row++){
        for(col = 0; col < BOARD_SIZE; col++){
            if(board->grid[row][col].value != 0){
                for(row_above = row - 1; row_above >= 0; row_above--){
                    if(board->grid[row_above][col].value == 0){
                        board->grid[row_above][col].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        row = row_above; 
                        moved = true;
                    } 
                    else if(board->grid[row_above][col].value == board->grid[row][col].value){
                        board->grid[row_above][col].value *= 2; 
                        board->grid[row][col].value = 0;
                        board->score += board->grid[row_above][col].value;
                        moved = true;
                        break;
                    } 
                    else{
                        break; 
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
    for(row = BOARD_SIZE-2; row >= 0; row--){
        for(col = 0; col < BOARD_SIZE; col++){
            if(board->grid[row][col].value != 0){
                for(row_below = row + 1; row_below < BOARD_SIZE; row_below++){
                    if(board->grid[row_below][col].value == 0){
                        board->grid[row_below][col].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        row = row_below; 
                        moved = true;
                    } 
                    else if(board->grid[row_below][col].value == board->grid[row][col].value){
                        board->grid[row_below][col].value *= 2;
                        board->grid[row][col].value = 0;
                        board->score += board->grid[row_below][col].value;
                        moved = true;
                        break;
                    } 
                    else{
                        break;
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
        for(col = 1; col < BOARD_SIZE; col++){
            if(board->grid[row][col].value != 0){
                for(col_left = col - 1; col_left >= 0; col_left--){
                    if(board->grid[row][col_left].value == 0){
                        board->grid[row][col_left].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        col = col_left; 
                        moved = true;
                    } 
                    else if(board->grid[row][col_left].value == board->grid[row][col].value){
                        board->grid[row][col_left].value *= 2;
                        board->grid[row][col].value = 0;
                        board->score += board->grid[row][col_left].value;
                        moved = true;
                        break;
                    } 
                    else{
                        break;
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
        for(col = BOARD_SIZE-2; col >= 0; col--){
            if(board->grid[row][col].value != 0){
                for(col_right = col + 1; col_right < BOARD_SIZE; col_right++){
                    if(board->grid[row][col_right].value == 0){
                        board->grid[row][col_right].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        col = col_right; 
                        moved = true;
                    } 
                    else if(board->grid[row][col_right].value == board->grid[row][col].value){
                        board->grid[row][col_right].value *= 2;
                        board->grid[row][col].value = 0;
                        board->score += board->grid[row][col_right].value;
                        moved = true;
                        break;
                    } 
                    else{
                        break;
                    }
                    
                }
            }
        }
    }
    return moved;
}

void saveScore(Board *board, int num) {
    int highScore;
    FILE *file = fopen("score.txt", "r+");
    fscanf(file, "%d\n", &num);
    
    if (board->score > num) {
        printf("%d\n",num);
        fclose(file);
        FILE *file = fopen("score.txt", "w+");
        highScore = board->score;
        num = board->score;
        fprintf(file, "%d\n", highScore); 
        fprintf(file, "%d\n", num);
        printf("%d\n",num);
        printf("%d\n",highScore);
        fclose(file); 
    } 
    else if(num > board->score) {
        fprintf(file, "%d", highScore);
        fclose(file); 
    }
}
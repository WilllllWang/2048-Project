#include "myheader.h"

bool moveTilesUp(Board *board, Blank *blank) {
    int row, col, row_above;
    bool moved = false;
    for(row = 1; row < BOARD_SIZE; row++){
        for(col = 0; col < BOARD_SIZE; col++){//�q�ĤG�C�}�l�V�U�ˬd�C��
            if(board->grid[row][col].value != 0){
                for(row_above = row - 1; row_above >= 0; row_above--){
                    if(board->grid[row_above][col].value == 0){
                        board->grid[row_above][col].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        row = row_above; 
                        moved = true;// �p�G�Ӥ���W������m�O�Ū��A�N����V�W����
                    } 
                    else if(board->grid[row_above][col].value == board->grid[row][col].value){// �p�G�W��������ƭȩM�Ӥ���ۦP
                        switch(board->grid[row_above][col].value){
                        case 2: blank->blank2 += board->grid[row_above][col].value; //��ܮ���"2"������ƶq
                        break;
                        case 4: blank->blank4 += board->grid[row_above][col].value/2;//��ܮ���"4"������ƶq
                        break;
                        case 8: blank->blank8 += board->grid[row_above][col].value/4;//��ܮ���"8"������ƶq
                        break;
                        case 16: blank->blank16 += board->grid[row_above][col].value/8;//��ܮ���"16"������ƶq
                        break;
                        case 32: blank->blank32 += board->grid[row_above][col].value/16;//��ܮ���"32"������ƶq
                        break;
                        case 64: blank->blank64 += board->grid[row_above][col].value/32;//��ܮ���"64"������ƶq
                        break;
                        case 128: blank->blank128 += board->grid[row_above][col].value/64;//��ܮ���"128"������ƶq
                        break;
                        case 256: blank->blank256 += board->grid[row_above][col].value/128;//��ܮ���"256"������ƶq
                        break;
                        case 512: blank->blank256 += board->grid[row_above][col].value/256;//��ܮ���"512"������ƶq
                        break;
                        case 1024: blank->blank1024 += board->grid[row_above][col].value/512;//��ܮ���"1024"������ƶq
                        break;
                        case 2048: blank->blank2048 += board->grid[row_above][col].value/1024;//��ܮ���"2048"������ƶq
                        break;
                        }
                        board->grid[row_above][col].value *= 2; //�N�X�֤������*2
                        board->grid[row][col].value = 0;//�N���e����ȳ]��0
                        board->score += board->grid[row_above][col].value;//��s����
                        moved = true;
                        break;
                    } 
                    else{
                        break; //�Y�P�W�����ƭȤ��P�A�h���_���h�j��
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
        for(col = 0; col < BOARD_SIZE; col++){//�q�ĤT�C�}�l�V�W�ˬd�C��
            if(board->grid[row][col].value != 0){
                for(row_below = row + 1; row_below < BOARD_SIZE; row_below++){
                    if(board->grid[row_below][col].value == 0){
                        board->grid[row_below][col].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        row = row_below; 
                        moved = true;// �p�G�Ӥ���U������m�O�Ū��A�N����V�U����
                    } 
                    else if(board->grid[row_below][col].value == board->grid[row][col].value){//�p�G�U�誺����ƭȻP�Ӥ���ۦP
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
                        board->grid[row_below][col].value *= 2;//�N�X�֤������*2
                        board->grid[row][col].value = 0;//�N���e����ȳ]��0
                        board->score += board->grid[row_below][col].value;//��s����
                        moved = true;
                        break;
                    } 
                    else{
                        break;//�Y�P�U�����ƭȤ��P�A�h���_���h�j��
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
        for(col = 1; col < BOARD_SIZE; col++){//�q�ĤG��}�l�V�k�v�C�ˬd
            if(board->grid[row][col].value != 0){
                for(col_left = col - 1; col_left >= 0; col_left--){
                    if(board->grid[row][col_left].value == 0){
                        board->grid[row][col_left].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        col = col_left; 
                        moved = true;// �p�G�Ӥ�����誺��m�O�Ū��A�N����V������
                    } 
                    else if(board->grid[row][col_left].value == board->grid[row][col].value){//�p�G���誺����ƭȻP�Ӥ���ۦP
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
                        board->grid[row][col_left].value *= 2;//�N�X�֤������*2
                        board->grid[row][col].value = 0;//�N���e����ȳ]��0
                        board->score += board->grid[row][col_left].value;//��s����
                        moved = true;
                        break;
                    } 
                    else{
                        break;//�Y�P�������ƭȤ��P�A�h���_���h�j��
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
        for(col = BOARD_SIZE-2; col >= 0; col--){//�q�ĤT��}�l�V���v�C�ˬd
            if(board->grid[row][col].value != 0){
                for(col_right = col + 1; col_right < BOARD_SIZE; col_right++){
                    if(board->grid[row][col_right].value == 0){
                        board->grid[row][col_right].value = board->grid[row][col].value;
                        board->grid[row][col].value = 0;
                        col = col_right; 
                        moved = true;// �p�G�Ӥ���k�䪺��m�O�Ū��A�N����V�k����
                    } 
                    else if(board->grid[row][col_right].value == board->grid[row][col].value){//�p�G�k�誺����ƭȻP�Ӥ���ۦP
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
                        board->grid[row][col_right].value *= 2;//�N�X�֤������*2
                        board->grid[row][col].value = 0;//�N���e����ȳ]��0
                        board->score += board->grid[row][col_right].value;//��s����
                        moved = true;
                        break;
                    } 
                    else{
                        break;//�Y�P�k�����ƭȤ��P�A�h���_���h�j��
                    }
                    
                }
            }
        }
    }
    return moved;
}

void saveScore(Board *board,int num) {
    int highScore;
    FILE *file = fopen("score.txt", "r+");
    fscanf(file, "%d\n", &num);
    if (board->score > num) {
        printf("%d\n",num);
        fclose(file);
        FILE *file = fopen("score.txt", "w+");
        highScore = board->score;
        num = board->score;
        fprintf(file, "%d\n", highScore); // 將分数寫入文件
        fprintf(file, "%d\n", num);
        printf("%d\n",num);
        printf("%d\n",highScore);
        fclose(file); // 關閉文件
    } 
    else if(num > board->score){
        fprintf(file, "%d", highScore);
        fclose(file); // 關閉文件
    }
}
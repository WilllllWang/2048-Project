#include "myheader.h"

void drawGame(Board *board, ALLEGRO_FONT *gameFont, ALLEGRO_BITMAP  *gameBackground, ALLEGRO_DISPLAY *display) {
    al_draw_bitmap(gameBackground, 0, 0, 0);
    al_draw_textf(gameFont, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 330, ALLEGRO_ALIGN_CENTRE, "Score: %d", board->score);
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            drawTile(gameFont, board->grid[row][col].value, col*TILE_SIZE, row*TILE_SIZE);
        }
    }
    al_flip_display();
}//分別繪製遊戲背景、分數、及4x4的板子


void drawTile(ALLEGRO_FONT *gameFont, int value, int row, int col) {
    ALLEGRO_COLOR color;
    ALLEGRO_COLOR textColor = al_map_rgb(0, 0, 0);

    switch (value) {
        case 0:
            color = al_map_rgb(204, 192, 179); 
            break;
        case 2:
            color = al_map_rgb(238, 228, 218); 
            break;
        case 4:
            color = al_map_rgb(237, 224, 200); 
            break;
        case 8:
            color = al_map_rgb(242, 177, 121); 
            break;
        case 16:
            color = al_map_rgb(245, 149, 99); 
            break;
        case 32:
            color = al_map_rgb(246, 124, 95); 
            break;
        case 64:
            color = al_map_rgb(246, 94, 59); 
            break;
        case 128:
            color = al_map_rgb(237, 207, 114); 
            break;
        case 256:
            color = al_map_rgb(237, 204, 97); 
            break;
        case 512:
            color = al_map_rgb(237, 200, 80); 
            break;
        case 1024:
            color = al_map_rgb(237, 197, 63); 
            break;
        case 2048:
            color = al_map_rgb(237, 194, 46); 
            break;
    }//繪製方格，並設定不同的數值方格有著不同的顏色背景

    al_draw_filled_rectangle(row+166, col+239, row+TILE_SIZE+166, col+TILE_SIZE+239, color);

    if (value != 0) {
        al_draw_textf(gameFont, textColor, row+(TILE_SIZE/2)+166, col+(TILE_SIZE/2)+200, ALLEGRO_ALIGN_CENTER, "%d", value);
    }
}//繪製非零數值的方塊
#include "myheader.h"

void drawGame(Board *board, ALLEGRO_FONT *gameFont, ALLEGRO_BITMAP  *gameBackground, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *countFont) {
    int highScore;
    FILE *file = fopen("score.txt", "r+"); 
    fscanf(file, "%d\n", &highScore);
    fclose(file); 
    
    al_draw_bitmap(gameBackground, 0, 0, 0);
    al_draw_textf(gameFont, al_map_rgb(200, 100, 100), SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 395, ALLEGRO_ALIGN_CENTRE, "Highest Score: %d", highScore);
    al_draw_textf(gameFont, al_map_rgb(0, 0, 0), SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 330, ALLEGRO_ALIGN_CENTRE, "Score: %d", board->score);
    
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            drawTile(gameFont, board->grid[row][col].value, col*TILE_SIZE, row*TILE_SIZE);
        }
    }
    al_flip_display();
}


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
    }

    al_draw_filled_rectangle(row+166, col+239, row+TILE_SIZE+166, col+TILE_SIZE+239, color);

    if (value != 0) {
        al_draw_textf(gameFont, textColor, row+(TILE_SIZE/2)+166, col+(TILE_SIZE/2)+200, ALLEGRO_ALIGN_CENTER, "%d", value);
    }
}
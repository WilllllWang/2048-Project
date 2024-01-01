#include "myheader.h"

bool checkLoseCondition(Board *board) {
    int row, col;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board->grid[row][col].value == 0) {
                return false;
            }
        }
    }

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE - 1; col++) {
            if (board->grid[row][col].value == board->grid[row][col + 1].value || board->grid[col][row].value == board->grid[col + 1][row].value) {
                return false; 
            }
        }
    }
    return true; 
}


bool checkWinCondition(Board *board) {
    int row, col;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board->grid[row][col].value == WINNING_TILE) {
                return true;
            }
        }
    }
    return false;
}

void endMenu(ALLEGRO_BITMAP  *menuBackground,ALLEGRO_BITMAP  *startButton, ALLEGRO_BITMAP  *gameBackground, ALLEGRO_BITMAP  *quitButton,  ALLEGRO_BITMAP  *restartButton, ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *endFont, ALLEGRO_FONT *menuFont){
    StartButtonValue restartButtonValue;
    restartButtonValue.startButtonWidth = al_get_bitmap_width(restartButton);
    restartButtonValue.startButtonHeight = al_get_bitmap_height(restartButton);
    restartButtonValue.startButtonX = (SCREEN_WIDTH - restartButtonValue.startButtonWidth-400) / 2;
    restartButtonValue.startButtonY = (SCREEN_HEIGHT - restartButtonValue.startButtonHeight-30) / 2;

    StartButtonValue quitButtonValue;
    quitButtonValue.startButtonWidth = al_get_bitmap_width(quitButton);
    quitButtonValue.startButtonHeight = al_get_bitmap_height(quitButton);
    quitButtonValue.startButtonX = (SCREEN_WIDTH+100) / 2;
    quitButtonValue.startButtonY = (SCREEN_HEIGHT - quitButtonValue.startButtonHeight-30) / 2;
    bool mouseOnButton = false;
     
    while (1) {
        float mouseX = al_get_mouse_state_axis(&Mstate, 0);
        float mouseY = al_get_mouse_state_axis(&Mstate, 1);
        al_get_mouse_state(&Mstate);
        al_draw_bitmap(gameBackground, 0, 0, 0);
        al_draw_bitmap(restartButton, restartButtonValue.startButtonX, restartButtonValue.startButtonY, 0);
        al_draw_bitmap(quitButton, quitButtonValue.startButtonX, quitButtonValue.startButtonY, 0);
        al_draw_text(menuFont, al_map_rgb(120, 130, 200), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-350, ALLEGRO_ALIGN_CENTER, "2 0 4 8");
        
        if ((mouseX >= restartButtonValue.startButtonX && mouseX <= (restartButtonValue.startButtonX+restartButtonValue.startButtonWidth) && (mouseY >= quitButtonValue.startButtonY && mouseY <= (quitButtonValue.startButtonY + quitButtonValue.startButtonHeight)))) {
            al_draw_text(endFont, al_map_rgb(255, 255, 255), SCREEN_WIDTH/3-35, restartButtonValue.startButtonY+35, ALLEGRO_ALIGN_CENTER, "RESTART"); 
            al_draw_text(endFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH-280, quitButtonValue.startButtonY+30, ALLEGRO_ALIGN_CENTER, "QUIT");
            mouseOnButton = true;
        }
        else if((mouseX >= quitButtonValue.startButtonX && mouseX <= (quitButtonValue.startButtonX+quitButtonValue.startButtonWidth)) && (mouseY >= quitButtonValue.startButtonY && mouseY <= (quitButtonValue.startButtonY + quitButtonValue.startButtonHeight))) {
            al_draw_text(endFont, al_map_rgb(255, 255, 255), SCREEN_WIDTH-280, quitButtonValue.startButtonY+30, ALLEGRO_ALIGN_CENTER, "QUIT"); 
            al_draw_text(endFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH/3-35, restartButtonValue.startButtonY+35, ALLEGRO_ALIGN_CENTER, "RESTART");
            mouseOnButton = true;   
        }
        else {
            al_draw_text(endFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH-280, quitButtonValue.startButtonY+30, ALLEGRO_ALIGN_CENTER, "QUIT");
            mouseOnButton = false;
            al_draw_text(endFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH/3-35, restartButtonValue.startButtonY+35, ALLEGRO_ALIGN_CENTER, "RESTART");
            mouseOnButton = false;
        }
        al_flip_display();

        if (al_mouse_button_down(&Mstate, 1) && (mouseX >= quitButtonValue.startButtonX && mouseX <= (quitButtonValue.startButtonX+quitButtonValue.startButtonWidth)) && (mouseY >= quitButtonValue.startButtonY && mouseY <= (quitButtonValue.startButtonY + quitButtonValue.startButtonHeight))) {
            al_rest(RENDERING_SPEED);
            uninstallEnd(gameBackground, quitButton, restartButton, Mstate, display, endFont, menuFont);
            break;}
        if (al_mouse_button_down(&Mstate, 1) && (mouseX >= restartButtonValue.startButtonX && mouseX <= (restartButtonValue.startButtonX+restartButtonValue.startButtonWidth) && (mouseY >= quitButtonValue.startButtonY && mouseY <= (quitButtonValue.startButtonY + quitButtonValue.startButtonHeight)))) {
            al_rest(RENDERING_SPEED);
            break;
        }
    }}   

  
#include "myheader.h"

void menu(ALLEGRO_BITMAP  *startButton,  ALLEGRO_BITMAP  *menuBackground,  ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *menuFont) {
    StartButtonValue startButtonValue;
    startButtonValue.startButtonWidth = al_get_bitmap_width(startButton);
    startButtonValue.startButtonHeight = al_get_bitmap_height(startButton);
    startButtonValue.startButtonX = (SCREEN_WIDTH - startButtonValue.startButtonWidth) / 2;
    startButtonValue.startButtonY = (SCREEN_HEIGHT - startButtonValue.startButtonHeight) / 2;
    bool mouseOnButton = false;

    while (1) {
        float mouseX = al_get_mouse_state_axis(&Mstate, 0);
        float mouseY = al_get_mouse_state_axis(&Mstate, 1);
        al_get_mouse_state(&Mstate);
        al_draw_bitmap(menuBackground, 0, 0, 0);
        al_draw_bitmap(startButton, startButtonValue.startButtonX, startButtonValue.startButtonY, 0);
        al_draw_text(menuFont, al_map_rgb(120, 130, 200), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-350, ALLEGRO_ALIGN_CENTER, "2 0 4 8");
        
        if ((mouseX >= startButtonValue.startButtonX && mouseX <= (startButtonValue.startButtonX+startButtonValue.startButtonWidth)) && (mouseY >= startButtonValue.startButtonY && mouseY <= (startButtonValue.startButtonY+startButtonValue.startButtonHeight))) {
            al_draw_text(menuFont, al_map_rgb(255, 255, 255), SCREEN_WIDTH/2, startButtonValue.startButtonY+15, ALLEGRO_ALIGN_CENTER, "PLAY"); 
            mouseOnButton = true;
        }
        else {
            al_draw_text(menuFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH/2, startButtonValue.startButtonY+15, ALLEGRO_ALIGN_CENTER, "PLAY");
            mouseOnButton = false;
        }
        al_flip_display();  

        if (al_mouse_button_down(&Mstate, 1) && mouseOnButton) {
            al_rest(RENDERING_SPEED);
            uninstallMenu(menuBackground, startButton, menuFont);
            break;
        }
    }   
}




#include "myheader.h"

void menu(ALLEGRO_BITMAP  *startButton,  ALLEGRO_BITMAP  *menuBackground, ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *menuFont, int startButtonWidth, int startButtonHeight, int startButtonX, int startButtonY){
    while(1){
        float mouseX = al_get_mouse_state_axis(&Mstate, 0);
        float mouseY = al_get_mouse_state_axis(&Mstate, 1);
        al_get_mouse_state(&Mstate);
        al_draw_bitmap(menuBackground, 0, 0, 0);
        al_draw_bitmap(startButton, startButtonX, startButtonY, 0);
        al_draw_text(menuFont, al_map_rgb(120, 130, 200), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-350, ALLEGRO_ALIGN_CENTER, "2 0 4 8");
        al_draw_text(menuFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH/2, startButtonY+15, ALLEGRO_ALIGN_CENTER, "PLAY");
        al_flip_display();  

        if(al_mouse_button_down(&Mstate, 1)){
            if ((mouseX >= startButtonX && mouseX <= (startButtonX+startButtonWidth)) && (mouseY >= startButtonY && mouseY <= (startButtonY+startButtonHeight))){
                al_rest(RENDERING_SPEED);
                uninstallMenu(menuBackground, startButton, menuFont);
                break;
            }
        }
    }   
}




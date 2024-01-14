#include "myheader.h"

void menu(ALLEGRO_BITMAP  *startButton,  ALLEGRO_BITMAP  *menuBackground,  ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font) {
    ButtonValue startButtonValue;
    ALLEGRO_SAMPLE *buttonSound = NULL;
    buttonSound = al_load_sample(BUTTON_SOUND_FILE);
    startButtonValue.ButtonWidth = al_get_bitmap_width(startButton);
    startButtonValue.ButtonHeight = al_get_bitmap_height(startButton);
    startButtonValue.ButtonX = (SCREEN_WIDTH - startButtonValue.ButtonWidth) / 2;
    startButtonValue.ButtonY = (SCREEN_HEIGHT - startButtonValue.ButtonHeight) / 2;
    bool mouseOnButton = false;

    while (1) {
        float mouseX = al_get_mouse_state_axis(&Mstate, 0);
        float mouseY = al_get_mouse_state_axis(&Mstate, 1);
        al_get_mouse_state(&Mstate);
        al_draw_bitmap(menuBackground, 0, 0, 0);
        al_draw_bitmap(startButton, startButtonValue.ButtonX, startButtonValue.ButtonY, 0);
        al_draw_text(font, al_map_rgb(120, 130, 200), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-350, ALLEGRO_ALIGN_CENTER, "2 0 4 8");
        
        if ((mouseX >= startButtonValue.ButtonX && mouseX <= (startButtonValue.ButtonX+startButtonValue.ButtonWidth)) && (mouseY >= startButtonValue.ButtonY && mouseY <= (startButtonValue.ButtonY+startButtonValue.ButtonHeight))) {
            al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH/2, startButtonValue.ButtonY+15, ALLEGRO_ALIGN_CENTER, "PLAY"); 
            mouseOnButton = true;
        }
        else {
            al_draw_text(font, al_map_rgb(220, 110, 90), SCREEN_WIDTH/2, startButtonValue.ButtonY+15, ALLEGRO_ALIGN_CENTER, "PLAY");
            mouseOnButton = false;
        }
        al_flip_display();  

        if (al_mouse_button_down(&Mstate, 1) && mouseOnButton) {
            al_play_sample(buttonSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            al_rest(RENDERING_SPEED);
            break;
        }
    }   
}


void endMenu(ALLEGRO_BITMAP  *menuBackground, ALLEGRO_BITMAP  *gameBackground, ALLEGRO_BITMAP  *quitButton,  ALLEGRO_BITMAP  *restartButton, ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *endFont, ALLEGRO_FONT *menuFont, Condition *condition) {
    ButtonValue restartButtonValue;
    ALLEGRO_SAMPLE *buttonSound = NULL;
    buttonSound = al_load_sample(BUTTON_SOUND_FILE);
    restartButtonValue.ButtonWidth = al_get_bitmap_width(restartButton);
    restartButtonValue.ButtonHeight = al_get_bitmap_height(restartButton);
    restartButtonValue.ButtonX = (SCREEN_WIDTH - restartButtonValue.ButtonWidth-400) / 2;
    restartButtonValue.ButtonY = (SCREEN_HEIGHT - restartButtonValue.ButtonHeight-30) / 2;

    ButtonValue quitButtonValue;
    quitButtonValue.ButtonWidth = al_get_bitmap_width(quitButton);
    quitButtonValue.ButtonHeight = al_get_bitmap_height(quitButton);
    quitButtonValue.ButtonX = (SCREEN_WIDTH+100) / 2;
    quitButtonValue.ButtonY = (SCREEN_HEIGHT - quitButtonValue.ButtonHeight-30) / 2;
    bool mouseOnButton = false;
     
    while (1) {
        float mouseX = al_get_mouse_state_axis(&Mstate, 0);
        float mouseY = al_get_mouse_state_axis(&Mstate, 1);
        al_get_mouse_state(&Mstate);
        al_draw_bitmap(gameBackground, 0, 0, 0);
        al_draw_bitmap(restartButton, restartButtonValue.ButtonX, restartButtonValue.ButtonY, 0);
        al_draw_bitmap(quitButton, quitButtonValue.ButtonX, quitButtonValue.ButtonY, 0);

        if (condition->gameCondition == 1) {
            al_draw_text(menuFont, al_map_rgb(120, 130, 200), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-350, ALLEGRO_ALIGN_CENTER, "Game Over");
        }
        else if (condition->gameCondition == 2) {
            al_draw_text(menuFont, al_map_rgb(120, 130, 200), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-350, ALLEGRO_ALIGN_CENTER, "You win");
        }
        else {
            al_draw_text(menuFont, al_map_rgb(120, 130, 200), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-350, ALLEGRO_ALIGN_CENTER, "2 0 4 8");
        }
       
        
        if ((mouseX >= restartButtonValue.ButtonX && mouseX <= (restartButtonValue.ButtonX+restartButtonValue.ButtonWidth) && (mouseY >= quitButtonValue.ButtonY && mouseY <= (quitButtonValue.ButtonY + quitButtonValue.ButtonHeight)))) {
            al_draw_text(endFont, al_map_rgb(255, 255, 255), SCREEN_WIDTH/3-35, restartButtonValue.ButtonY+35, ALLEGRO_ALIGN_CENTER, "MENU"); 
            al_draw_text(endFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH-280, quitButtonValue.ButtonY+30, ALLEGRO_ALIGN_CENTER, "QUIT");
            mouseOnButton = true;
        }
        else if((mouseX >= quitButtonValue.ButtonX && mouseX <= (quitButtonValue.ButtonX+quitButtonValue.ButtonWidth)) && (mouseY >= quitButtonValue.ButtonY && mouseY <= (quitButtonValue.ButtonY + quitButtonValue.ButtonHeight))) {
            al_draw_text(endFont, al_map_rgb(255, 255, 255), SCREEN_WIDTH-280, quitButtonValue.ButtonY+30, ALLEGRO_ALIGN_CENTER, "QUIT"); 
            al_draw_text(endFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH/3-35, restartButtonValue.ButtonY+35, ALLEGRO_ALIGN_CENTER, "MENU");
            mouseOnButton = true;   
        }
        else {
            al_draw_text(endFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH-280, quitButtonValue.ButtonY+30, ALLEGRO_ALIGN_CENTER, "QUIT");
            al_draw_text(endFont, al_map_rgb(220, 110, 90), SCREEN_WIDTH/3-35, restartButtonValue.ButtonY+35, ALLEGRO_ALIGN_CENTER, "MENU");
            mouseOnButton = false;
        }
        al_flip_display();

        if (al_mouse_button_down(&Mstate, 1) && (mouseX >= quitButtonValue.ButtonX && mouseX <= (quitButtonValue.ButtonX+quitButtonValue.ButtonWidth)) && (mouseY >= quitButtonValue.ButtonY && mouseY <= (quitButtonValue.ButtonY + quitButtonValue.ButtonHeight))) {
            al_play_sample(buttonSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            al_rest(RENDERING_SPEED);
            uninstallEnd(gameBackground, quitButton, restartButton, Mstate, display, endFont, menuFont);
            break;
        }
        if (al_mouse_button_down(&Mstate, 1) && (mouseX >= restartButtonValue.ButtonX && mouseX <= (restartButtonValue.ButtonX+restartButtonValue.ButtonWidth) && (mouseY >= quitButtonValue.ButtonY && mouseY <= (quitButtonValue.ButtonY + quitButtonValue.ButtonHeight)))) {
            al_play_sample(buttonSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            al_rest(RENDERING_SPEED);
            break;
        }
    }
}   
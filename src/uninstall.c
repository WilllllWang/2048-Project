#include "myheader.h"

void uninstallGame(ALLEGRO_BITMAP  *gameBackground, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *gameFont){
    al_destroy_bitmap(gameBackground);
    al_destroy_display(display);
    al_destroy_font(gameFont);
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_uninstall_system();
}


void uninstallMenu(ALLEGRO_BITMAP  *menuBackground, ALLEGRO_BITMAP  *startButton, ALLEGRO_FONT *font){
    al_destroy_bitmap(menuBackground);
    al_destroy_bitmap(startButton);
    al_destroy_font(font);
}
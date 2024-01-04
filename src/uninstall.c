#include "myheader.h"

void uninstallGame(ALLEGRO_BITMAP  *gameBackground, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *gameFont) {
    al_destroy_bitmap(gameBackground);
    al_destroy_display(display);
    al_destroy_font(gameFont);
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_uninstall_system();
}


void uninstallMenu(ALLEGRO_BITMAP  *menuBackground, ALLEGRO_BITMAP  *startButton, ALLEGRO_FONT *font) {
    al_destroy_bitmap(menuBackground);
    al_destroy_bitmap(startButton);
    al_destroy_font(font);
}


void uninstallEnd(ALLEGRO_BITMAP  *gameBackground, ALLEGRO_BITMAP  *quitButton, ALLEGRO_BITMAP  *restartButton, ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *endFont, ALLEGRO_FONT *menuFont ) {
    al_destroy_display(display);
    al_destroy_bitmap(gameBackground);
    al_destroy_bitmap(quitButton);
    al_destroy_bitmap(restartButton);
    al_destroy_font(endFont);
    al_destroy_font(menuFont);
    al_uninstall_mouse();
}

void clearCount(Blank *blank){
    blank->blank2 = 0;
    blank->blank4 = 0;
    blank->blank8 = 0;
    blank->blank16 = 0;
    blank->blank32 = 0;
    blank->blank64 = 0;
    blank->blank128 = 0;
    blank->blank256 = 0;
    blank->blank512 = 0;
    blank->blank1024 = 0;
    blank->blank2048 = 0;
}
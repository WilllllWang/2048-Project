#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "myheader.h"

int main(){
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_ttf_addon();
    al_init_font_addon();
    al_install_mouse();
    al_install_keyboard();
    
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_FONT *menuFont = NULL;
    ALLEGRO_FONT *gameFont = NULL;
    ALLEGRO_BITMAP  *menuBackground = NULL;
    ALLEGRO_BITMAP  *gameBackground = NULL;
    ALLEGRO_BITMAP  *startButton = NULL;
    ALLEGRO_MOUSE_STATE Mstate;
    ALLEGRO_KEYBOARD_STATE KBstate;

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    menuFont = al_load_ttf_font(MENU_FONT, 120, 0);
    gameFont = al_load_ttf_font(GAME_FONT, 60, 0);
    menuBackground = al_load_bitmap(MENU_BACKGROUND); 
    gameBackground = al_load_bitmap(GAME_BACKGROUND); 
    startButton = al_load_bitmap(START_BUTTON_FILE);

    Board board = {0};
    
    int game = 1;
    bool moved = false;
    
    // Start Game
    menu(startButton, menuBackground, Mstate, display, menuFont);
    srand(time(NULL));
    while (game == 1) {
        initializeGame(&board);
        generateNewTile(&board);
        generateNewTile(&board);
        drawGame(&board, gameFont, gameBackground, display);
        game = 2;

        while (game == 2) {
            al_get_keyboard_state(&KBstate);
            if (al_key_down(&KBstate, ALLEGRO_KEY_UP)) {
                moved = moveTilesUp(&board);
            } 
            else if (al_key_down(&KBstate, ALLEGRO_KEY_DOWN)) {
                moved = moveTilesDown(&board);
                
            }
            else if (al_key_down(&KBstate, ALLEGRO_KEY_LEFT)) {
                moved = moveTilesLeft(&board);
            }
            else if (al_key_down(&KBstate, ALLEGRO_KEY_RIGHT)) {
                moved = moveTilesRight(&board);
            }
            else if (al_key_down(&KBstate, ALLEGRO_KEY_ESCAPE)) {
                game = 0;
            }       
            
            drawGame(&board, gameFont, gameBackground, display);

            if (moved) {
                al_rest(RENDERING_SPEED);
                generateNewTile(&board);
                
                moved = false;

                if (checkLoseCondition(&board) || checkWinCondition(&board)) {
                    game = 1;
                }
            }
            al_rest(0.1);
        }
    }
    uninstallGame(gameBackground, display, gameFont);
    return 0;
}




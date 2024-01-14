#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "myheader.h"


int main() {
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_ttf_addon();
    al_init_font_addon();
    al_install_mouse();
    al_install_keyboard();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(3);

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_FONT *menuFont = NULL;
    ALLEGRO_FONT *countFont = NULL;
    ALLEGRO_FONT *gameFont = NULL;
    ALLEGRO_FONT *endFont = NULL;
    ALLEGRO_BITMAP  *menuBackground = NULL;
    ALLEGRO_BITMAP  *gameBackground = NULL;
    ALLEGRO_BITMAP  *startButton = NULL;
    ALLEGRO_BITMAP  *quitButton = NULL;
    ALLEGRO_BITMAP  *restartButton = NULL;
    ALLEGRO_MOUSE_STATE Mstate;
    ALLEGRO_KEYBOARD_STATE KBstate;
    ALLEGRO_SAMPLE *moveSound = NULL;
    ALLEGRO_SAMPLE *winSound = NULL;
    ALLEGRO_SAMPLE *loseSound = NULL;
    FILE *file = NULL;

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    menuFont = al_load_ttf_font(MENU_FONT, 120, 0);
    gameFont = al_load_ttf_font(GAME_FONT, 60, 0);
    countFont = al_load_ttf_font(END_FONT, 30, 0);
    endFont = al_load_ttf_font(END_FONT, 60, 0);
    menuBackground = al_load_bitmap(MENU_BACKGROUND); 
    gameBackground = al_load_bitmap(GAME_BACKGROUND); 
    startButton = al_load_bitmap(START_BUTTON_FILE);
    quitButton = al_load_bitmap(Quit_BUTTON_FILE);
    restartButton = al_load_bitmap(Restart_BUTTON_FILE);
    moveSound = al_load_sample(MOVE_SOUND_FILE);
    winSound = al_load_sample(WIN_SOUND_FILE);
    loseSound = al_load_sample(LOSE_SOUND_FILE); 

    Board board = {0};
    Condition condition;
    int game = 1;
    int num, highScore;
    bool moved = false;
    // Start Game
    while (game == 1) {
        menu(startButton, menuBackground, Mstate, display, menuFont);
        srand(time(NULL));
        game = 2; // Initialize game 
        while (game == 2) {
            initializeGame(&board, &condition);
            generateNewTile(&board);
            generateNewTile(&board);
            drawGame(&board, gameFont, gameBackground, display, countFont, highScore, num);
            game = 3; // Start game 
            while (game == 3) {
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
                    game = 1;
                    break;
                }       
                
                drawGame(&board, gameFont, gameBackground, display, countFont, highScore, num);

                if (moved) {
                    al_play_sample(moveSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    al_rest(RENDERING_SPEED);
                    generateNewTile(&board);
                    moved = false;

                    if (checkLoseCondition(&board, &condition)) {
                        al_play_sample(loseSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                        saveScore(&board,num);
                        al_rest(RENDERING_SPEED);
                        game = 1;
                    }
                    else if (checkWinCondition(&board, &condition)) {
                        al_play_sample(winSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                        saveScore(&board,num);
                        al_rest(RENDERING_SPEED);
                        game = 1;
                    }
                }
                al_rest(RENDERING_SPEED);
            }
        }
        endMenu(menuBackground, gameBackground, quitButton, restartButton, Mstate, display, endFont, menuFont, &condition);
    }
}
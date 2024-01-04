#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
#define TILE_SIZE 166
#define BOARD_SIZE 4
#define WINNING_TILE 2048
#define RENDERING_SPEED 0.075
#define MENU_BACKGROUND "images/menu_background.png"
#define GAME_BACKGROUND "images/game_background.jpg"
#define START_BUTTON_FILE "images/button.png"
#define Quit_BUTTON_FILE "images/quit.png"
#define Restart_BUTTON_FILE "images/restart.png"
#define MENU_FONT "fonts/menu_font.ttf"
#define END_FONT "fonts/menu_font.ttf"
#define GAME_FONT "fonts/game_font.ttf"

typedef struct {
    int value;
} Tile;

typedef struct {
    Tile grid[BOARD_SIZE][BOARD_SIZE];
    int score;
} Board;

typedef struct {
    int ButtonWidth;
    int ButtonHeight;
    int ButtonX;
    int ButtonY;
} ButtonValue;

typedef struct {
    int gameCondition;
} Condition;



void menu(ALLEGRO_BITMAP  *startButton,  ALLEGRO_BITMAP  *menuBackground, ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
void endMenu(ALLEGRO_BITMAP  *menuBackground, ALLEGRO_BITMAP  *gameBackground, ALLEGRO_BITMAP  *quitButton,  ALLEGRO_BITMAP  *restartButton, ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *menuFont, ALLEGRO_FONT *endFont, Condition *condition);
void drawGame(Board *board, ALLEGRO_FONT *gameFont, ALLEGRO_BITMAP  *gameBackground, ALLEGRO_DISPLAY *display);
void drawTile(ALLEGRO_FONT *gameFont, int value, int row, int col);
void generateNewTile(Board *board);
void initializeGame(Board *board, Condition *condition);
void uninstallMenu(ALLEGRO_BITMAP  *menuBackground, ALLEGRO_BITMAP  *startButton, ALLEGRO_FONT *font);
void uninstallEnd(ALLEGRO_BITMAP  *quitButton,  ALLEGRO_BITMAP  *restartButton, ALLEGRO_BITMAP  *gameBackground, ALLEGRO_MOUSE_STATE Mstate, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *endFont, ALLEGRO_FONT *menuFont);
void uninstallGame(ALLEGRO_BITMAP  *gameBackground, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *gameFont);
bool boardFull(Board *board);
bool moveTilesUp(Board *board);
bool moveTilesDown(Board *board);
bool moveTilesLeft(Board *board);
bool moveTilesRight(Board *board);
bool checkLoseCondition(Board *board, Condition *condition);
bool checkWinCondition(Board *board, Condition *condition);

#endif 
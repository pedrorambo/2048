#include <config.h>
#include <ncurses.h>

#ifndef VIEW_H
#define VIEW_H

#define SHOW_CURSOR 0

#define VIEW_COLOR_BLACK 30
#define VIEW_COLOR_WHITE 10         // piece 2
#define VIEW_COLOR_DARK_WHITE 11    // piece 4
#define VIEW_COLOR_ORANGE 12        // piece 8
#define VIEW_COLOR_DARK_ORANGE 13   // piece 16
#define VIEW_COLOR_RED 14           // piece 32
#define VIEW_COLOR_DARK_RED 15      // piece 64
#define VIEW_COLOR_LIGHT_YELLOW 16  // piece 128
#define VIEW_COLOR_YELLOW 17        // piece 256
#define VIEW_COLOR_DARK_YELLOW 18   // piece 512
#define VIEW_COLOR_DARKER_YELLOW 19 // piece 1024
#define VIEW_COLOR_PURPLE 20        // piece 2048
#define VIEW_COLOR_GREY 21

#define TABLE_WINDOW_WIDTH 100
#define TABLE_WINDOW_HEIGHT 100
#define TABLE_WINDOW_X 0
#define TABLE_WINDOW_Y 0

WINDOW *initView();
void destroyView();
int getNextKey(WINDOW *);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <tablePlays.h>

#define TABLE_WINDOW_WIDTH 100
#define TABLE_WINDOW_HEIGHT 100
#define TABLE_WINDOW_X 0
#define TABLE_WINDOW_Y 0

#define PIECE_WIDTH 10
#define PIECE_HEIGHT 5

#define PIECE_TEXT_OFFSET_X 2
#define PIECE_TEXT_OFFSET_Y 3

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

WINDOW *win = NULL;

void setColorByValue(WINDOW *win, int value)
{
    switch (value)
    {
    case 0:
        wattron(win, COLOR_PAIR(VIEW_COLOR_GREY));
        break;
    case 2:
        wattron(win, COLOR_PAIR(VIEW_COLOR_WHITE));
        break;
    case 4:
        wattron(win, COLOR_PAIR(VIEW_COLOR_DARK_WHITE));
        break;
    case 8:
        wattron(win, COLOR_PAIR(VIEW_COLOR_ORANGE));
        break;
    case 16:
        wattron(win, COLOR_PAIR(VIEW_COLOR_DARK_ORANGE));
        break;
    case 32:
        wattron(win, COLOR_PAIR(VIEW_COLOR_RED));
        break;
    case 64:
        wattron(win, COLOR_PAIR(VIEW_COLOR_DARK_RED));
        break;
    case 128:
        wattron(win, COLOR_PAIR(VIEW_COLOR_LIGHT_YELLOW));
        break;
    case 256:
        wattron(win, COLOR_PAIR(VIEW_COLOR_YELLOW));
        break;
    case 512:
        wattron(win, COLOR_PAIR(VIEW_COLOR_DARK_YELLOW));
        break;
    case 1024:
        wattron(win, COLOR_PAIR(VIEW_COLOR_DARKER_YELLOW));
        break;
    case 2048:
        wattron(win, COLOR_PAIR(VIEW_COLOR_PURPLE));
        break;
    default:
        wattron(win, COLOR_PAIR(VIEW_COLOR_BLACK));
        break;
    }
}

void drawBlockPiece(WINDOW *win, int y, int x, int value)
{
    setColorByValue(win, value);

    for (int l = x; l < (x + PIECE_HEIGHT); l++)
    {
        for (int c = y; c < (y + PIECE_WIDTH); c++)
        {
            wmove(win, l, c);
            waddch(win, ' ');
        }
    }

    if (value == 0)
        return;

    wmove(win, (x + PIECE_TEXT_OFFSET_X), (y + PIECE_TEXT_OFFSET_Y));
    wprintw(win, "%4d", value);
}

void drawTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    wclear(win);

    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            drawBlockPiece(win, (c * PIECE_WIDTH), (l * PIECE_HEIGHT), table[l][c]);
        }
    }
    wrefresh(win);
}

void initColors()
{
    init_color(VIEW_COLOR_BLACK, 0, 0, 0);
    init_color(VIEW_COLOR_WHITE, 933, 894, 854);
    init_color(VIEW_COLOR_DARK_WHITE, 933, 882, 788);
    init_color(VIEW_COLOR_ORANGE, 952, 698, 478);
    init_color(VIEW_COLOR_DARK_ORANGE, 964, 588, 392);
    init_color(VIEW_COLOR_RED, 968, 486, 372);
    init_color(VIEW_COLOR_DARK_RED, 968, 372, 231);
    init_color(VIEW_COLOR_LIGHT_YELLOW, 929, 815, 450);
    init_color(VIEW_COLOR_YELLOW, 929, 800, 380);
    init_color(VIEW_COLOR_DARK_YELLOW, 929, 823, 474);
    init_color(VIEW_COLOR_DARKER_YELLOW, 929, 772, 247);
    init_color(VIEW_COLOR_PURPLE, 556, 266, 678);
    init_color(VIEW_COLOR_GREY, 188, 188, 188);

    init_pair(VIEW_COLOR_WHITE, COLOR_BLACK, VIEW_COLOR_WHITE);
    init_pair(VIEW_COLOR_DARK_WHITE, COLOR_BLACK, VIEW_COLOR_DARK_WHITE);
    init_pair(VIEW_COLOR_ORANGE, COLOR_BLACK, VIEW_COLOR_ORANGE);
    init_pair(VIEW_COLOR_DARK_ORANGE, COLOR_BLACK, VIEW_COLOR_DARK_ORANGE);
    init_pair(VIEW_COLOR_RED, COLOR_BLACK, VIEW_COLOR_RED);
    init_pair(VIEW_COLOR_DARK_RED, COLOR_BLACK, VIEW_COLOR_DARK_RED);
    init_pair(VIEW_COLOR_LIGHT_YELLOW, COLOR_BLACK, VIEW_COLOR_LIGHT_YELLOW);
    init_pair(VIEW_COLOR_YELLOW, COLOR_BLACK, VIEW_COLOR_YELLOW);
    init_pair(VIEW_COLOR_DARK_YELLOW, COLOR_BLACK, VIEW_COLOR_DARK_YELLOW);
    init_pair(VIEW_COLOR_DARKER_YELLOW, COLOR_BLACK, VIEW_COLOR_DARKER_YELLOW);
    init_pair(VIEW_COLOR_PURPLE, COLOR_BLACK, VIEW_COLOR_PURPLE);
    init_pair(VIEW_COLOR_GREY, COLOR_BLACK, VIEW_COLOR_GREY);
}

void initView()
{
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(SHOW_CURSOR);
    initColors();
    win = newwin(TABLE_WINDOW_WIDTH, TABLE_WINDOW_HEIGHT, TABLE_WINDOW_X, TABLE_WINDOW_Y);
    wrefresh(win);
}

int getNextKey()
{
    //FIXME Documentar
    keypad(win, TRUE);
    cbreak();
    noecho();
    int ch = wgetch(win);

    //FIXME Debug
    wmove(win, 0, 42);
    wprintw(win, "Tecla: %i ", ch);
    wrefresh(win);

    return ch;
}

void destroyView()
{
    endwin();
}
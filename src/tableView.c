#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>

#define CARD_TITLE_PADDING 2
#define CARD_VALUE_PADDING 1

#define SCORE_CARD_WIDTH 9
#define MOVEMENTS_CARD_WIDTH 14

#define RANKING_CARD_WIDTH 24
#define RANKING_CARD_SCORE_WIDTH 7

void setColorByValue(WINDOW *window, int value)
{
    switch (value)
    {
    case 0:
        wattron(window, COLOR_PAIR(VIEW_COLOR_GREY));
        break;
    case 2:
        wattron(window, COLOR_PAIR(VIEW_COLOR_WHITE));
        break;
    case 4:
        wattron(window, COLOR_PAIR(VIEW_COLOR_DARK_WHITE));
        break;
    case 8:
        wattron(window, COLOR_PAIR(VIEW_COLOR_ORANGE));
        break;
    case 16:
        wattron(window, COLOR_PAIR(VIEW_COLOR_DARK_ORANGE));
        break;
    case 32:
        wattron(window, COLOR_PAIR(VIEW_COLOR_RED));
        break;
    case 64:
        wattron(window, COLOR_PAIR(VIEW_COLOR_DARK_RED));
        break;
    case 128:
        wattron(window, COLOR_PAIR(VIEW_COLOR_LIGHT_YELLOW));
        break;
    case 256:
        wattron(window, COLOR_PAIR(VIEW_COLOR_YELLOW));
        break;
    case 512:
        wattron(window, COLOR_PAIR(VIEW_COLOR_DARK_YELLOW));
        break;
    case 1024:
        wattron(window, COLOR_PAIR(VIEW_COLOR_DARKER_YELLOW));
        break;
    case 2048:
        wattron(window, COLOR_PAIR(VIEW_COLOR_PURPLE));
        break;
    default:
        wattron(window, COLOR_PAIR(VIEW_COLOR_BLACK));
        break;
    }
}

void drawBlockPiece(WINDOW *window, int y, int x, int value)
{
    setColorByValue(window, value);

    for (int l = x; l < (x + PIECE_HEIGHT); l++)
    {
        for (int c = y; c < (y + PIECE_WIDTH); c++)
        {
            wmove(window, l, c);
            waddch(window, ' ');
        }
    }

    if (value == 0)
        return;

    wmove(window, (x + PIECE_TEXT_OFFSET_X), (y + PIECE_TEXT_OFFSET_Y));
    wprintw(window, "%4d", value);
}

void drawTable(WINDOW *window, int table[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            drawBlockPiece(window, (c * PIECE_WIDTH), (l * PIECE_HEIGHT), table[l][c]);
        }
    }
}

void drawInt(WINDOW *window, int value, int x, int y, int width, int padding, int colorPairIndex)
{
    int valueMaxLength = width - (padding * 2);
    wattron(window, COLOR_PAIR(colorPairIndex));
    wmove(window, y, x);
    wprintw(window, "%*c%*d%*c", padding, ' ', valueMaxLength, value, padding, ' ');
}

void drawString(WINDOW *window, char value[], int x, int y, int width, int padding, int colorPairIndex)
{
    int valueMaxLength = width - (padding * 2);
    wattron(window, COLOR_PAIR(colorPairIndex));
    wmove(window, y, x);
    wprintw(window, "%*c%*s%*c", padding, ' ', valueMaxLength, value, padding, ' ');
}

void drawCardInt(WINDOW *window, char title[], int value, int x, int y, int width)
{
    drawString(window, title, x, y, width, CARD_TITLE_PADDING, VIEW_COLOR_LIGHT_GREY);
    drawInt(window, value, x, y + 1, width, CARD_VALUE_PADDING, VIEW_COLOR_GREY);
}

void drawCardRanking(WINDOW *window, char title[], t_tableData *tableData, int x, int y, int width)
{
    drawString(window, title, x, y, width, CARD_TITLE_PADDING, VIEW_COLOR_LIGHT_GREY);

    for (int i = 0; i < tableData->rankingSize; i++)
    {
        drawInt(window, tableData->ranking[i].score, x, y + i + 1, RANKING_CARD_SCORE_WIDTH, CARD_VALUE_PADDING, VIEW_COLOR_GREY);
        drawString(window, tableData->ranking[i].name, x + RANKING_CARD_SCORE_WIDTH, y + i + 1, width - RANKING_CARD_SCORE_WIDTH, CARD_VALUE_PADDING, VIEW_COLOR_GREY);
    }
}

void drawStats(WINDOW *window, t_tableData *tableData)
{
    int tableHorizontalSize = PIECE_WIDTH * TABLE_SIZE;

    drawCardInt(window, "Score", tableData->score, tableHorizontalSize + 2, 1, SCORE_CARD_WIDTH);
    drawCardInt(window, "Movimentos", tableData->movements, tableHorizontalSize + 2 + SCORE_CARD_WIDTH + 1, 1, MOVEMENTS_CARD_WIDTH);
    drawCardRanking(window, "Ranking", tableData, tableHorizontalSize + 2, 4, RANKING_CARD_WIDTH);
}

void renderTable(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawTable(window, tableData->table);
    drawStats(window, tableData);
    wrefresh(window);
}
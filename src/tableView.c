#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>

/* Define a cor de acordo com o número da peça */
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

/*Função para criar um bloco gráficamente*/
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

/* Desenha um tabuleiro */
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

/* Desenha o score, movimentos e ranking */
void drawStats(WINDOW *window, t_tableData *tableData)
{
    int tableHorizontalSize = PIECE_WIDTH * TABLE_SIZE;

    drawCardInt(window, "Score", tableData->score, tableHorizontalSize + 2, 1, SCORE_CARD_WIDTH);
    drawCardInt(window, "Movimentos", tableData->movements, tableHorizontalSize + 2 + SCORE_CARD_WIDTH + 1, 1, MOVEMENTS_CARD_WIDTH);
    drawCardRanking(window, "Ranking", tableData, tableHorizontalSize + 2, 4, RANKING_CARD_WIDTH);
}

/*Função para inicializar um quadro com informações do jogo*/
void drawHud(WINDOW *window)
{
    drawString(window, "Comandos", 42, 16, 24, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "N - Novo Jogo", 42, 17, 24, 1, VIEW_COLOR_GREY);
    drawString(window, "S - Salvar Jogo", 42, 18, 24, 1, VIEW_COLOR_GREY);
    drawString(window, "ESC - Sair do Jogo", 42, 19, 24, 1, VIEW_COLOR_GREY);
}

/*Função para mostrar tabuleiro na tela para o usuário*/
void renderTable(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawTable(window, tableData->table);
    drawStats(window, tableData);
    drawHud(window);
    wrefresh(window);
}
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <tablePlays.h>
#include <view.h>
#define KEY_ESC 27

int main(void)
{
    srand(time(NULL));
    int table[TABLE_SIZE][TABLE_SIZE] = {0};
    initView();
    addInitialPiecesToTable(table);
    drawTable(table);
    int key;
    

    do
    {
        key = getNextKey();
        

        
        if (key == KEY_DOWN){ // Down
        
            if (playDown(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
        }
        else if (key == KEY_UP){ // Up
            if (playUp(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
        }
        else if (key == KEY_LEFT){ // Left
            if (playLeft(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
            }
        else if (key == KEY_RIGHT){ // Right
            if (playRight(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
        }
        
      
    }while (key != KEY_ESC);
    
    destroyView();
    return 0;
}
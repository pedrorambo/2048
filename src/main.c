#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <core.h>
#include <view.h>
#include <tableView.h>
#include <promptView.h>

#ifndef KEY_ESC
#define KEY_ESC 27
#endif

#ifndef KEY_NEWGAME
#define KEY_NEWGAME 110
#endif

int main(void)
{
    int key;
    t_tableData tableData;
    WINDOW *window = initView();
    WINDOW *window2 = initView();

    srand(time(NULL));
    initGame(&tableData);

    renderTable(window, &tableData);

    do
    {
        key = getNextKey(window);

        switch (key)
        {
        case KEY_DOWN:
            playDown(&tableData);
            renderTable(window, &tableData);
            break;
        case KEY_UP:
            playUp(&tableData);
            renderTable(window, &tableData);
            break;
        case KEY_RIGHT:
            playRight(&tableData);
            renderTable(window, &tableData);
            break;
        case KEY_LEFT:
            playLeft(&tableData);
            renderTable(window, &tableData);
            break;
        case KEY_NEWGAME:
            destroyTable(window);
            
            if(TRUE){  
                renderPrompt(window2);
                initGame(&tableData);

            }

            else{
                renderTable(window, &tableData);
            }

        default:
            break;
        }

        
    } while (key != KEY_ESC);

    destroyView();
    return 0;
}
#include <iostream>
#include "loadmodule.h"
#include "typedef.hpp"
#include <dlfcn.h>
#include <ncurses.h>

WINDOW *win;
int refreshscreen(gamestate g){
    for(int i = 0; i < g.listcnt; i++){
        mvwprintw(win, i + 1, 2, "%s", g.screen[i]);
    }
    return 0;
}

int crashhandler(){
    printw("Program exitted unexpectedly. Press any key to exit.");
    getch();
    endwin();
    return -1;
}
int main() {

    loadpack("vanilla.zip");
    
    win = initscr();
    start_color();
    init_pair(1,COLOR_BLUE, COLOR_RED);
    box(win, '|', '-');

    game.screen[0] = "Buy beetroot";
    game.screen[1] = "Buy wall";
    game.listcnt = 2;
    refreshscreen(game);
    

    return crashhandler();
}

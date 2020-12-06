#include <iostream>
#include <ncurses.h>

#define GOLD_PER_PEASANT 40
class player{
    public:
    int turns = 0;
    int coin = 0;
    int peasants = 5;
} game;

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

int maxx, maxy;
int shop(){
    rectangle(2, 5, maxx, maxy);
    return 0;
}
int main() {
    WINDOW *win = initscr();
    maxx = getmaxx(win);
    maxy = getmaxy(win);
    mvwprintw(win, 0, 0, "Peasants: %d (%d gold per turn +%%d bonus) x: %d", game.peasants, game.peasants * GOLD_PER_PEASANT, 0, maxx);
    refresh();
    char a = getch();
    if(a == 's'){
        shop();
    }
    getch();
    endwin();
    return 0;
}



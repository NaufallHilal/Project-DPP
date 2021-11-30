#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <windows.h>
#include <time.h>
using namespace std;

void start_game(){
mvprintw(18,38,"P");
refresh(); Sleep(0100);
mvprintw(18,39,"r");
refresh(); Sleep(0100);
mvprintw(18,40,"e");
refresh(); Sleep(0100);
mvprintw(18,41,"s");
refresh(); Sleep(0100);
mvprintw(18,42,"s");
refresh(); Sleep(0100);
mvprintw(18,43," ");
refresh(); Sleep(0100);
mvprintw(18,44,"X");
refresh(); Sleep(0100);
mvprintw(18,45," ");
refresh(); Sleep(0100);
mvprintw(18,46,"B");
refresh(); Sleep(0100);
mvprintw(18,47,"u");
refresh(); Sleep(0100);
mvprintw(18,48,"t");
refresh(); Sleep(0100);
mvprintw(18,49,"t");
refresh(); Sleep(0100);
mvprintw(18,50,"o");
refresh(); Sleep(0100);
mvprintw(18,51,"n");
refresh(); Sleep(0100);
mvprintw(18,52," ");
refresh(); Sleep(0100);
mvprintw(18,53,"t");
refresh(); Sleep(0100);
mvprintw(18,54,"o");
refresh(); Sleep(0100);
mvprintw(18,55," ");
refresh(); Sleep(0100);
mvprintw(18,56,"C");
refresh(); Sleep(0100);
mvprintw(18,57,"o");
refresh(); Sleep(0100);
mvprintw(18,58,"n");
refresh(); Sleep(0100);
mvprintw(18,59,"t");
refresh(); Sleep(0100);
mvprintw(18,60,"i");
refresh(); Sleep(0100);
mvprintw(18,61,"n");
refresh(); Sleep(0100);
mvprintw(18,62,"u");
refresh(); Sleep(0100);
mvprintw(18,63,"e");
refresh(); Sleep(0100);	
}

int main(){
char pilihan,pill='x',pilll='X';
initscr();
start_game();

startgame:
cin>>pilihan;
if (pilihan == pill|| pilihan == pilll){
goto ingame;
}else{
goto startgame;
}
ingame:
endwin();
}

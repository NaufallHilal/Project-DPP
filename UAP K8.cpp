#include <iostream>
#include <ncurses.h>
#include <windows.h>
using namespace std;

int x,y,fruitX,fruitY,score,penambah,level,nkalimat,kolom,baris;
int tailX[100],tailY[100];
int ntail;
string nama;
char start,pilstart1,pilstart2;
char keluar,pilend1,pilend2,pilend3,pilend4;
bool gameOver;

void setup()
{
	nama="kelompok 8 : Naufal Hilal,Kurnia Ramadhani,Rivanza Syifa";
	nkalimat = nama.length();
	kolom=22;
	baris=5;
	x=1;
	y=1;
	fruitX= (rand() % 28)+ 1;
	fruitY= (rand() % 18)+ 1;
	score=0;
	level=1;
	penambah=1000;
	pilstart1='x';
	pilstart2='X';
	pilend1='y';
	pilend2='n';
	pilend3='Y';
	pilend4='N';
	gameOver=false;
	
}
void awal()
{
	refresh(); Sleep(0300);
	mvprintw(baris-1,kolom,"===========================================================");
	mvprintw(baris+11,kolom,"===========================================================");
	refresh(); Sleep(0100);
	mvprintw(baris,kolom," ========================================================= ");
	mvprintw(baris+10,kolom," ========================================================= ");
	refresh(); Sleep(0200);
	mvprintw(baris+9,kolom,"  ####   #   #  ### #  # ####     ####   ### #  #  # ####  ");
	mvprintw(baris+1,kolom,"   ####             #             ####                     ");
	refresh(); Sleep(0100);
	mvprintw(baris+2,kolom,"  #    #            #            #                         ");
	mvprintw(baris+8,kolom," #    #  #   # #  # # #  #       #    # #  # # # # # #     ");
	refresh(); Sleep(0100);
	mvprintw(baris+3,kolom,"  #                 #            #                         ");
	mvprintw(baris+7,kolom,"      #  #   # #  # ##   #####   #    # #  # ##   ## ####  ");
	refresh(); Sleep(0100);
	mvprintw(baris+4,kolom,"   #                #            #                         ");
	mvprintw(baris+6,kolom,"     #    ###   ##  # #  #    #  #  ##   ##  #     # #   # ");
	refresh(); Sleep(0100);
	mvprintw(baris+5,kolom,"    #               #  #  ####   #                    #### ");
	refresh(); Sleep(0200);
		
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

void credit(){
	for(int huruf=0;huruf<=nkalimat;huruf++){
	mvprintw(baris,kolom,"%s",nama.c_str());
	refresh();
	mvprintw(baris,kolom+huruf," ");
	refresh();Sleep(0100);
	}
}
void pengecekan()
{	
	if (x==fruitX && y==fruitY){
	fruitX = (rand() % 28)+1;
	fruitY = (rand() % 18)+1;
	score = score+penambah;
	ntail++;
	}
	level=1+score/10000;

	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	for (int i=1;i<ntail;i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	for (int i=0;i<ntail;i++){
		if (tailX[i]==x && tailY[i]==y){
			gameOver = true;
		}
	}
}

void akhir()
{
	int baris=5;
	clear();
	string akhir1=" ###                   ###               ";
	string akhir2="#                     #   #              ";
	string akhir3="#  #   ##  #   # ###  #   # #   # ### ###";
	string akhir4="#   # #  # ## ## ##   #   #  # #  ##  # #";
	string akhir5=" ###   ### # # # ###   ###    #   ### #  ";

	mvprintw(baris,32,"%s",akhir1.c_str());
	refresh(); Sleep(0100);
	mvprintw(baris+1,32,"%s",akhir2.c_str());
	refresh(); Sleep(0100);
	mvprintw(baris+2,32,"%s",akhir3.c_str());
	refresh(); Sleep(0100);
	mvprintw(baris+3,32,"%s",akhir4.c_str());
	refresh(); Sleep(0100);
	mvprintw(baris+4,32,"%s",akhir5.c_str());
	refresh();
}

int main()
{

//	setup
	initscr();
	clear();
	setup();
	
//	awal
	awal();
	startgame:
    cin>>start;
    if (start == pilstart1|| start == pilstart2){
 	goto ingame;
	}else{
    goto startgame;
	}
	 
//	ingame
	ingame:
	clear();
	WINDOW * win = newwin(20, 30, 3, 37);
	box(win, 0, 0);
	refresh();
	
	wmove(win, fruitY,fruitX);
	wprintw(win, "*");
	
	wmove(win, y, x);
	wprintw(win,"O");
	wrefresh(win);
	
	mvprintw(10,23,"Score : %d",score);
	mvprintw(11,23,"Level : %d",level);
	refresh();
	
	mvprintw(10,71,"gunakan UP DOWN LEFT RIGHT");
	mvprintw(11,72,"untuk menggerakkan ular!");
	refresh();
	
//	input pergerakan
	keypad(win,TRUE);
	while(!gameOver)
	{
		int movement;
		movement=wgetch(win);
		
		switch(movement){
			case KEY_LEFT:
				if(x==1){
					gameOver=true;
				}else{
					x--;
				}
				tailX[0]=x+1;
				tailY[0]=y;
				break;
			case KEY_RIGHT:
				if(x==28){
					gameOver = true;
				}else{
					x++;
				}
				tailX[0]=x-1;
				tailY[0]=y;
				break;
			case KEY_UP:
				if (y==1){
					gameOver =true;
				}else{
					y--;
				}
				tailX[0]=x;
				tailY[0]=y+1;
				break;
			case KEY_DOWN:
				if (y==18){
					gameOver =true;
				}else{
					y++;
				}
				tailX[0]=x;
				tailY[0]=y-1;
				break;
			case 'f':
				clear();
				credit();
				goto end;
	}
//	pengecekan setelah input
		pengecekan();
			
//	output setelah pengecekan
		wclear(win);
		box(win,0,0);
		wrefresh(win);
		
		wmove(win,fruitY,fruitX);
		wprintw(win,"*");
		wrefresh(win);
		
		wmove(win,y,x);
		wprintw(win,"O");
		wrefresh(win);
		
		for(int k=0;k<ntail;k++){
			wmove(win,tailY[k],tailX[k]);
			wprintw(win,"o");
			wrefresh(win);
		}
		
		mvprintw(10,23,"Score : %d",score);
		mvprintw(11,23,"Level : %d",level);
		refresh();
		
		if (ntail==2){
			mvprintw(12,77,"F for rsepect");
		}else{
			mvprintw(12,77,"             ");
		}
		
	}
	
//	gameover
	end:
	akhir();
	
	mvprintw(11,45,"Score : %d",score);
	refresh();
	mvprintw(12,42,"Level Permainan : %d",level);
	refresh();
	mvprintw(13,30,"Apakah anda ingin mengulangi permainan? (y/n) ");
	refresh();

	cin>>keluar;
	if(keluar==pilend1||keluar==pilend3){
		x=1;
		y=1;
		score=0;
		level=1;
		ntail=0;
		gameOver=false;
		goto ingame;
	}else if(keluar==pilend2||keluar==pilend4){
		goto Exit;
	}else{
		goto end;
	}
	getch();
	Exit:
	endwin();
}

#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio/SoundBuffer.hpp>
#include<SFML/Audio/Sound.hpp>
// #include<Windows.h>
using namespace std;
//    /$$$$$$                                  /$$                           /$$             
//   /$$__  $$                                | $$                          | $$             
//  | $$  \__/  /$$$$$$  /$$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$  /$$$$$$$  /$$$$$$   /$$$$$$$
//  | $$       /$$__  $$| $$__  $$ /$$_____/|_  $$_/   |____  $$| $$__  $$|_  $$_/  /$$_____/
//  | $$      | $$  \ $$| $$  \ $$|  $$$$$$   | $$      /$$$$$$$| $$  \ $$  | $$   |  $$$$$$ 
//  | $$    $$| $$  | $$| $$  | $$ \____  $$  | $$ /$$ /$$__  $$| $$  | $$  | $$ /$$\____  $$
//  |  $$$$$$/|  $$$$$$/| $$  | $$ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$  | $$  |  $$$$//$$$$$$$/
//   \______/  \______/ |__/  |__/|_______/    \___/   \_______/|__/  |__/   \___/ |_______/                                                                                           
constexpr int canvas_easy_x = 9;
constexpr int canvas_easy_y = 9;
constexpr int canvas_inter_x = 16;
constexpr int canvas_inter_y = 16;
constexpr int canvas_adv_x = 30;
constexpr int canvas_adv_y = 16;
//   /$$      /$$        /$$$$$$        /$$$$$$$ 
//  | $$$    /$$$       /$$__  $$      | $$__  $$
//  | $$$$  /$$$$      | $$  \ $$      | $$  \ $$
//  | $$ $$/$$ $$      | $$$$$$$$      | $$$$$$$/
//  | $$  $$$| $$      | $$__  $$      | $$____/ 
//  | $$\  $ | $$      | $$  | $$      | $$      
//  | $$ \/  | $$      | $$  | $$      | $$      
//  |__/     |__/      |__/  |__/      |__/                                                                                                                                        
int canvas_easy[50][50];
int canvas_view_easy[50][50];
int canvas_inter[50][50];
int canvas_view_inter[50][50];
int canvas_adv[50][50];
int canvas_view_adv[50][50];
int hints = 5;
//   /$$$$$$$                      /$$
//  | $$__  $$                    | $$
//  | $$  \ $$  /$$$$$$   /$$$$$$ | $$
//  | $$$$$$$  /$$__  $$ /$$__  $$| $$
//  | $$__  $$| $$  \ $$| $$  \ $$| $$
//  | $$  \ $$| $$  | $$| $$  | $$| $$
//  | $$$$$$$/|  $$$$$$/|  $$$$$$/| $$
//  |_______/  \______/  \______/ |__/
bool create_canvas_easy = false;
bool create_canvas_inter = false;
bool create_canvas_adv = false;
bool savegameselected = false;
bool savegamepressed = false;	
bool hintsel = false;
bool hinpre = false;
bool clicked = false;
bool hintnormal = true;
bool bombfound = false;
bool firstmove = true;
bool emptyfound = false;
bool oneminefound = false;
bool game_end = false;
int** canvas = new int* [canvas_easy_x];
int moves;
int mov = 0;
bool settingpressed = false;
bool settingselected = false;
bool easymode = false;
bool intermode = false;
bool advmode = false;
bool meselected = false;
bool miselected = false;
bool maselected = false;
bool create_easy = false;
bool clicksave = false;
bool okselected = false;
bool okpressed = false;
int sy;
int ways[][2] = { { -1, -1 },
	{ -1, 0 },
	{ -1, 1 },
	{ 0, -1 },
	{ 0, 1 },
	{ 1, -1 },
	{ 1, 0 },
	{ 1, 1 } };


//   /$$$$$$$$                    /$$                                                    /$$$            /$$$$$$                      /$$   /$$                        
//  |__  $$__/                   | $$                                                   /$$ $$          /$$__  $$                    |__/  | $$                        
//     | $$  /$$$$$$  /$$   /$$ /$$$$$$   /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$$      |  $$$          | $$  \__/  /$$$$$$   /$$$$$$  /$$ /$$$$$$    /$$$$$$   /$$$$$$$
//     | $$ /$$__  $$|  $$ /$$/|_  $$_/  | $$  | $$ /$$__  $$ /$$__  $$ /$$_____/       /$$ $$/$$      |  $$$$$$  /$$__  $$ /$$__  $$| $$|_  $$_/   /$$__  $$ /$$_____/
//     | $$| $$$$$$$$ \  $$$$/   | $$    | $$  | $$| $$  \__/| $$$$$$$$|  $$$$$$       | $$  $$_/       \____  $$| $$  \ $$| $$  \__/| $$  | $$    | $$$$$$$$|  $$$$$$ 
//     | $$| $$_____/  >$$  $$   | $$ /$$| $$  | $$| $$      | $$_____/ \____  $$      | $$\  $$        /$$  \ $$| $$  | $$| $$      | $$  | $$ /$$| $$_____/ \____  $$
//     | $$|  $$$$$$$ /$$/\  $$  |  $$$$/|  $$$$$$/| $$      |  $$$$$$$ /$$$$$$$/      |  $$$$/$$      |  $$$$$$/| $$$$$$$/| $$      | $$  |  $$$$/|  $$$$$$$ /$$$$$$$/
//     |__/ \_______/|__/  \__/   \___/   \______/ |__/       \_______/|_______/        \____/\_/       \______/ | $$____/ |__/      |__/   \___/   \_______/|_______/ 
//                                                                                                               | $$                                                  
//                                                                                                               | $$                                                  
//                                                                                                               |__/                                                 
sf::Texture ibox, button1;
sf::Sprite ok;
sf::Sprite isprite;	
sf::Texture one, two, three, four, five, six, seven, eight, em, bo, view; // for mines
sf::Sprite o, tw, th, fo, fi, si, se, ei, emp, v, bomb;
// for settings
sf::Sprite sete;
sf::Texture settings;
sf::Text ezm,izm,azm;
sf::Sprite save;
sf::Sprite outtile;

sf::Texture pattern;
sf::Sprite patt;
//--------------------------------------------------------
// for time
sf::Texture a, blue, cc, d, egg, ff, g, hh, i, j,k,l;
sf::Sprite aa, bb, ccc, dd, eeg, fff, gg, hhh, ii, jj,kk,ll;
sf::RenderWindow menu(sf::VideoMode(1920, 1090), "Mode Menu", sf::Style::Titlebar | sf::Style::Close);
sf::Texture mine;
sf::Texture savegame;
sf::Texture cre,opt;
sf::Sprite c,op,s;
sf::Texture flag,te;
sf::Font f;
sf::Text formenu, easy_opt, inter_opt, adv_opt, title, credits, arrow;
sf::Font f1;
// sf::Clock;
sf::Texture texture;
sf::Text tame;
sf::Text h;
int sx;
std::string USERNAME;
sf::Text user_name,user_score,high_score,topplayer;
string top_player;
int score = 0;
int highscore = 69	;
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm  
//    /$$$$$$  /$$           /$$                 /$$       /$$$$$$$$                              /$$     /$$                              
//   /$$__  $$| $$          | $$                | $$      | $$_____/                             | $$    |__/                              
//  | $$  \__/| $$  /$$$$$$ | $$$$$$$   /$$$$$$ | $$      | $$    /$$   /$$ /$$$$$$$   /$$$$$$$ /$$$$$$   /$$  /$$$$$$  /$$$$$$$   /$$$$$$$
//  | $$ /$$$$| $$ /$$__  $$| $$__  $$ |____  $$| $$      | $$$$$| $$  | $$| $$__  $$ /$$_____/|_  $$_/  | $$ /$$__  $$| $$__  $$ /$$_____/
//  | $$|_  $$| $$| $$  \ $$| $$  \ $$  /$$$$$$$| $$      | $$__/| $$  | $$| $$  \ $$| $$        | $$    | $$| $$  \ $$| $$  \ $$|  $$$$$$ 
//  | $$  \ $$| $$| $$  | $$| $$  | $$ /$$__  $$| $$      | $$   | $$  | $$| $$  | $$| $$        | $$ /$$| $$| $$  | $$| $$  | $$ \____  $$
//  |  $$$$$$/| $$|  $$$$$$/| $$$$$$$/|  $$$$$$$| $$      | $$   |  $$$$$$/| $$  | $$|  $$$$$$$  |  $$$$/| $$|  $$$$$$/| $$  | $$ /$$$$$$$/
//   \______/ |__/ \______/ |_______/  \_______/|__/      |__/    \______/ |__/  |__/ \_______/   \___/  |__/ \______/ |__/  |__/|_______/                                                                                                                                                                 
bool isvalid(int row, int col)
{
	if ((row >= 0) && (row < sx) && (col >= 0) && (col < sy))
	{
		return true;
	}
	else return false;
}
void tileskholdo(int x, int y, int board[][50], int board_view[][50])
{
			for (int i = -1; i <= 1; i++)
			{
				if (board[x][y + i] == 0 && board_view[x][y+i]==10)
				{
					board_view[x][y + i] = board[x][y + i];
					int newx = x;
					int newy = y + i;
					if (board[newx][newy + i] == 0 && board_view[newx][newy+i]==10)tileskholdo(newx, newy + i, board, board_view);
				}
				if (board[x + i][y] == 0 && board_view[x+i][y]==10)
				{
					board_view[x + i][y] = board[x + i][y];
					int newx = x + i;
					int newy = y;
					if (board[newx+ i][newy] == 0 && board_view[newx+i][newy]==10)tileskholdo(newx + i, newy, board, board_view);
				}
				if (board[x - 1][y + i] == 0 && board_view[x-1][y+i]==10)
				{
					board_view[x - 1][y + i] = board[x - 1][y + i];
					int newx = x - 1;
					int newy = y + i;
					if (board[newx - 1][newy + i] == 0 && board_view[newx-1][newy+i]==10)tileskholdo(newx - 1, newy + i, board, board_view);
				}
				if (board[x + 1][y + i] == 0 && board_view[x+1][y+i]==10)
				{
					
					board_view[x + 1][y + i] = board[x + 1][y + i];
					int newx = x + 1;
					int newy = y + i;
					if (board[newx + 1][newy + i] == 0 && board_view[newx+1][newy+i]==10)tileskholdo(newx+ 1, newy + i, board, board_view);
				}
			}
}

void leaderboard()
{
	;; // some code here
}
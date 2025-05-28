#include "classes.h"
#include <SFML/Graphics.hpp>
#include <random>

//    /$$$$$$              /$$           /$$      /$$ /$$
//   /$$__  $$            | $$          | $$$    /$$$|__/
//  | $$  \__/  /$$$$$$  /$$$$$$        | $$$$  /$$$$ /$$ /$$$$$$$   /$$$$$$
//  /$$$$$$$ |  $$$$$$  /$$__  $$|_  $$_/        | $$ $$/$$ $$| $$| $$__  $$
//  /$$__  $$ /$$_____/
//   \____  $$| $$$$$$$$  | $$          | $$  $$$| $$| $$| $$  \ $$| $$$$$$$$|
//   $$$$$$
//   /$$  \ $$| $$_____/  | $$ /$$      | $$\  $ | $$| $$| $$  | $$| $$_____/
//   \____  $$
//  |  $$$$$$/|  $$$$$$$  |  $$$$/      | $$ \/  | $$| $$| $$  | $$|  $$$$$$$
//  /$$$$$$$/
//   \______/  \_______/   \___/        |__/     |__/|__/|__/  |__/
//   \_______/|_______/
class setmine {
  int no_of_bombs;

public:
  bool isMine(int i, int j) {
    if (canvas_easy[i][j] == 0)
      return true;
    else
      return false;
  }
  void set_no_of_bombs(int sizex, int sizey, int board[][50]);
  void bombrakhdo(int sizex, int sizey, int b, int board[][50],
                  int board_view[][50]);
  void firstmovesafe(int sizex, int sizey, int board[][50], int posx, int posy);
};
// mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void setmine::firstmovesafe(int sizex, int sizey, int board[][50], int posx,
                            int posy) {
  for (int i = 0; i < sizex; i++) {
    for (int j = 0; j < sizey; j++) {
      if (board[i][j] != 9 && emptyfound == false) {
        board[i][j] = 9;
        board[posx][posy] = 0;
        emptyfound = true;
      }
    }
  }
}
// mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void setmine::bombrakhdo(int sizex, int sizey, int b, int board[][50],
                         int board_view[][50]) {
  std::random_device rd;
  std::mt19937 gen(rd());
  int bombs = 0;
  if (sizex == 9) {
    board_view[10][2] = 20;
  } else if (sizex == 16) {
    board_view[19][2] = 20;
  } else if (sizex == 30) {
    board_view[32][2] = 20;
  }

  for (int i = 0; i < sizex; i++) {
    for (int j = 0; j < sizey; j++) {
      board_view[i][j] = 10;
      if (rand() % 5 == 0 && bombs < b) // 10
      {
        board[i][j] = 9;
        bombs++;
      } else
        board[i][j] = 0;
    }
  }
  for (int i = sizex; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      board_view[i][j] = 0;
    }
  }
  for (int i = 0; i < 50; i++) {
    for (int j = sizey; j < 50; j++) {
      board_view[i][j] = 0;
    }
  }
}
// mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void setmine::set_no_of_bombs(int sizex, int sizey, int board[][50]) {
  for (int i = 0; i < sizex; i++) {
    for (int j = 0; j < sizey; j++) {
      int n = 0;
      if (board[i][j] == 9)
        continue;
      if (board[i + 1][j] == 9)
        n++;
      if (board[i][j + 1] == 9)
        n++;
      if (board[i - 1][j] == 9)
        n++;
      if (board[i][j - 1] == 9)
        n++;
      if (board[i + 1][j + 1] == 9)
        n++;
      if (board[i - 1][j - 1] == 9)
        n++;
      if (board[i - 1][j + 1] == 9)
        n++;
      if (board[i + 1][j - 1] == 9)
        n++;
      board[i][j] = n;
    }
  }
}
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "canvas.h"
#include "classes.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// #include<Windows.h>
#include "savefile.h"
using namespace sf;
//   /$$      /$$                       /$$
//  | $$$    /$$$                      |__/
//  | $$$$  /$$$$        /$$$$$$        /$$       /$$$$$$$
//  | $$ $$/$$ $$       |____  $$      | $$      | $$__  $$
//  | $$  $$$| $$        /$$$$$$$      | $$      | $$  \ $$
//  | $$\  $ | $$       /$$__  $$      | $$      | $$  | $$
//  | $$ \/  | $$      |  $$$$$$$      | $$      | $$  | $$
//  |__/     |__/       \_______/      |__/      |__/  |__/
//
int main() {
  blue.loadFromFile("time/1.png");
  cc.loadFromFile("time/2.png");
  d.loadFromFile("time/3.png");
  egg.loadFromFile("time/4.png");
  ff.loadFromFile("time/5.png");
  g.loadFromFile("time/6.png");
  hh.loadFromFile("time/7.png");
  i.loadFromFile("time/8.png");
  j.loadFromFile("time/9.png");
  k.loadFromFile("time/10.png");
  // l.loadFromFile("time/10.png");
  //------------ pak india border ---------------
  te.loadFromFile("images/ijk.png");
  s.setTexture(te);
  flag.loadFromFile("images/flag.png");
  f.loadFromFile("images/font.ttf");
  f1.loadFromFile("images/fonth.ttf");
  one.loadFromFile("images/1.png");
  two.loadFromFile("images/2.png");
  three.loadFromFile("images/3.png");
  four.loadFromFile("images/4.png");
  five.loadFromFile("images/5.png");
  six.loadFromFile("images/6.png");
  seven.loadFromFile("images/7.png");
  eight.loadFromFile("images/8.png");
  em.loadFromFile("images/empty.png");
  bo.loadFromFile("images/mine.png");
  view.loadFromFile("images/user_view.png");
  tw.setTexture(two);
  th.setTexture(three);
  fo.setTexture(four);
  fi.setTexture(five);
  si.setTexture(six);
  se.setTexture(seven);
  ei.setTexture(eight);
  emp.setTexture(em);
  v.setTexture(view);
  bomb.setTexture(bo);
  srand(time(0));
  Menu a;
  a.Process();
}

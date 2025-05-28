#pragma once
#include "Menu.h"
#include "classes.h"
#include "setmine.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// #include<Windows.h>
#include "savefile.h"
// #include<tchar.h>
// #include<windowsx.h>
//    /$$$$$$
//   /$$__  $$
//  | $$  \__/        /$$$$$$        /$$$$$$$        /$$    /$$        /$$$$$$
//  /$$$$$$$ | $$             |____  $$      | $$__  $$      |  $$  /$$/ |____
//  $$       /$$_____/ | $$              /$$$$$$$      | $$  \ $$ \  $$/$$/
//  /$$$$$$$      |  $$$$$$ | $$    $$       /$$__  $$      | $$  | $$ \  $$$/
//  /$$__  $$       \____  $$ |  $$$$$$/      |  $$$$$$$      | $$  | $$ \  $/
//  |  $$$$$$$       /$$$$$$$/
//   \______/        \_______/      |__/  |__/          \_/           \_______/
//   |_______/
class createcanvas : public setmine {
public:
  void createcanvas_type(int sx, int sy, int b, sf::RenderWindow &window,
                         int board[][50], int board_view[][50], int tilesize) {
    setmine::bombrakhdo(sx, sy, b, board, board_view);
    setmine::set_no_of_bombs(sx, sy, board);
    //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
    if (sx == 9 || sx == 16) {
      user_score.setPosition(sf::Vector2f(window.getSize().x / 2 + 200.f,
                                          window.getSize().y / 2 - 150.f));
      user_score.setString("Score : " + std::to_string(score));
      user_score.setFillColor(sf::Color(158, 161, 232));
      user_score.setOutlineColor(sf::Color::Black);
      user_score.setOutlineThickness(2);
      user_score.setCharacterSize(30);
      user_score.setFont(f);
      //-------------------------------------
      high_score.setFont(f);
      high_score.setPosition(sf::Vector2f(window.getSize().x / 2 + 190.f,
                                          window.getSize().y / 2 - 185.f));
      high_score.setString("HighScore : " + std::to_string(highscore));
      high_score.setFillColor(sf::Color(240, 135, 132));
      high_score.setOutlineColor(sf::Color::Black);
      high_score.setOutlineThickness(3);
      high_score.setCharacterSize(25);
    }
    //--------------------------------------
  start:
    sf::Time time;
    sf::Clock clock;
    if (sx == 9 || sx == 16) {
      if (clicksave == false) {
        user_name.setFont(f);
        user_name.setPosition(sf::Vector2f(window.getSize().x / 2 + 190.f,
                                           window.getSize().y / 2 - 250.f));
        user_name.setCharacterSize(25);
        user_name.setOutlineColor(sf::Color(8, 130, 99));
        user_name.setOutlineThickness(1);
        user_name.setString("Guest Player");
        user_name.setFillColor(sf::Color::Transparent);
      }
    }
    if (sx == 30) {
      if (clicksave = false) {
        user_name.setFont(f);
        user_name.setPosition(sf::Vector2f(window.getSize().x / 2 + 150.f,
                                           window.getSize().y / 2));
        user_name.setOrigin(-550.f, +400.f);
        user_name.setCharacterSize(25);
        user_name.setOutlineColor(sf::Color(8, 130, 99));
        user_name.setOutlineThickness(1);
        user_name.setString("Guest Player");
        user_name.setFillColor(sf::Color::Transparent);
      }
      //---------------------------------------------
      user_score.setPosition(sf::Vector2f(window.getSize().x / 2 + 200.f,
                                          window.getSize().y / 2 - 150.f));
      user_score.setOrigin(-500.f, +200.f);
      user_score.setString("Score : " + std::to_string(score));
      user_score.setFillColor(sf::Color(158, 161, 232));
      user_score.setOutlineColor(sf::Color::Black);
      user_score.setOutlineThickness(2);
      user_score.setCharacterSize(30);
      user_score.setFont(f);
      //------------------------------------------
      high_score.setFont(f);
      high_score.setPosition(sf::Vector2f(window.getSize().x / 2 + 200.f,
                                          window.getSize().y / 2 - 150.f));
      high_score.setOrigin(-500.f, +300.f);
      high_score.setString("HighScore : " + std::to_string(highscore));
      high_score.setFillColor(sf::Color(240, 135, 132));
      high_score.setOutlineColor(sf::Color::Black);
      high_score.setOutlineThickness(3);
      high_score.setCharacterSize(25);
    }
    if (clicksave == true) {
      clicksave = false;
      sf::RenderWindow name(sf::VideoMode(352, 115), "Input", sf::Style::Close);
      ibox.loadFromFile("images/inputimg.png");
      button1.loadFromFile("images/ok.png");
      isprite.setTexture(ibox);
      ok.setTexture(button1);
      ok.setColor(sf::Color(192, 192, 192));
      ok.setPosition(sf::Vector2f(name.getSize().x / 2 + 32.f,
                                  name.getSize().y / 2 + 20.f));
      Textbox textbox1(15, sf::Color::Black, true);
      sf::Font afont;
      afont.loadFromFile("images/font.ttf");
      textbox1.setfont(afont);
      textbox1.setposition(sf::Vector2f(name.getSize().x / 2 - 80.f,
                                        name.getSize().y / 2 - 15.f));
      textbox1.setlimit(true, 31);

      while (name.isOpen()) {
        sf::Event namei;
        while (name.pollEvent(namei)) {
          switch (namei.type) {
          case sf::Event::Closed:
            name.close();
          case sf::Event::TextEntered:
            textbox1.typedon(namei);
          }
          if (namei.type == sf::Event::KeyPressed) {
            switch (namei.key.code) {
            case sf::Keyboard::Return: {
              if (okselected) {
                okpressed = true;
                name.close();
                clock.restart();
                USERNAME = textbox1.gettext();
                user_name.setFont(f);
                user_name.setPosition(
                    sf::Vector2f(window.getSize().x / 2 + 150.f,
                                 window.getSize().y / 2 - 250.f));
                user_name.setCharacterSize(30);
                user_name.setOutlineColor(sf::Color(8, 130, 99));
                user_name.setOutlineThickness(1);
                user_name.setString("Player : " + USERNAME);
                user_name.setFillColor(sf::Color::Transparent);
              }
            }
            }
          }
          if (namei.type == sf::Event::MouseMoved) {
            switch (namei.type) {
            case sf::Event::MouseMoved: {
              // std::cout << "x : " << namei.mouseMove.x << " | y : " <<
              // namei.mouseMove.y << "\n";
            }
            }
          }
          switch (namei.type) {
          case sf::Event::MouseMoved: {
            if (namei.mouseMove.x >= 211 && namei.mouseMove.x <= 264 &&
                namei.mouseMove.y >= 79 && namei.mouseMove.y <= 98) {
              ok.setColor(sf::Color(186, 239, 255));
              okselected = true;
            } else {
              ok.setColor(sf::Color(192, 192, 192));
              okselected = false;
            }
          }
          case sf::Event::MouseButtonPressed: {
            if (okselected == true) {

              if (namei.mouseButton.button == sf::Mouse::Left) {
                okpressed = true;
                name.close();
                clock.restart();
                USERNAME = textbox1.gettext();
                user_name.setFont(f);
                user_name.setPosition(
                    sf::Vector2f(window.getSize().x / 2 + 150.f,
                                 window.getSize().y / 2 - 250.f));
                user_name.setCharacterSize(30);
                user_name.setOutlineColor(sf::Color(8, 130, 99));
                user_name.setOutlineThickness(1);
                user_name.setString("Player : " + USERNAME);
                user_name.setFillColor(sf::Color::Transparent);
                //------------------------------------------
              }
              if (sx == 30) {
                if (namei.mouseButton.button == sf::Mouse::Left) {
                  okpressed = true;
                  name.close();
                  clock.restart();
                  USERNAME = textbox1.gettext();
                  user_name.setFont(f);
                  user_name.setPosition(sf::Vector2f(
                      window.getSize().x / 2 + 150.f, window.getSize().y / 2));
                  user_name.setOrigin(-500.f, +500.f);
                  user_name.setCharacterSize(30);
                  user_name.setOutlineColor(sf::Color(8, 130, 99));
                  user_name.setOutlineThickness(1);
                  user_name.setString("Player : " + USERNAME);
                  user_name.setFillColor(sf::Color::Transparent);
                  //------------------------------------------
                }
              }
            }
          }
          }
        }
        name.clear();
        name.draw(isprite);
        name.draw(ok);
        textbox1.drawto(name);
        name.display();
      }
    }
    while (window.isOpen()) {
      time = clock.getElapsedTime();
      int t = time.asSeconds();
      // std::cout << "Time is >> " << t << "\n";
      sf::Event e;
      while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
          window.close();
        }

        //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
        //
        //   /$$      /$$ /$$$$$$$$                              /$$
        //  | $$$    /$$$                                              |
        //  $$_____/                             | $$ | $$$$  /$$$$  /$$$$$$ /$$
        //  /$$  /$$$$$$$  /$$$$$$       | $$    /$$    /$$ /$$$$$$  /$$$$$$$
        //  /$$$$$$   /$$$$$$$ | $$ $$/$$ $$ /$$__  $$| $$  | $$ /$$_____/ /$$__
        //  $$      | $$$$$|  $$  /$$//$$__  $$| $$__  $$|_  $$_/  /$$_____/ |
        //  $$  $$$| $$| $$  \ $$| $$  | $$|  $$$$$$ | $$$$$$$$      | $$__/
        //  \  $$/$$/| $$$$$$$$| $$  \ $$  | $$   |  $$$$$$ | $$\  $ | $$| $$  |
        //  $$| $$  | $$ \____  $$| $$_____/      | $$     \  $$$/ | $$_____/|
        //  $$  | $$  | $$ /$$\____  $$ | $$ \/  | $$|  $$$$$$/|  $$$$$$/
        //  /$$$$$$$/|  $$$$$$$      | $$$$$$$$\  $/  |  $$$$$$$| $$  | $$  |
        //  $$$$//$$$$$$$/
        //  |__/     |__/ \______/  \______/ |_______/  \_______/ |________/ \_/
        //  \_______/|__/  |__/   \___/ |_______/
        else if (e.type == sf::Event::MouseMoved) {
          switch (e.type) {

          case sf::Event::MouseMoved: {
            std::cout << "x : " << e.mouseMove.x << " | y : " << e.mouseMove.y
                      << "\n";
          }
          }
          switch (e.type) {
          case sf::Event::MouseMoved: {
            if (sx == 9) {
              if (e.mouseMove.x >= 680 && e.mouseMove.x <= 749 &&
                  e.mouseMove.y >= 396 && e.mouseMove.y <= 426) {
                meselected = true;
                miselected = false;
                maselected = false;

              } else
                meselected = false;
              if (e.mouseMove.x >= 600 && e.mouseMove.x <= 658 &&
                  e.mouseMove.y >= 436 && e.mouseMove.y <= 460) {
                meselected = false;
                miselected = true;
                maselected = false;
              } else
                miselected = false;
              if (e.mouseMove.x >= 610 && e.mouseMove.x <= 664 &&
                  e.mouseMove.y >= 510 && e.mouseMove.y <= 532) {
                meselected = false;
                miselected = false;
                maselected = true;
              } else
                maselected = false;
              break;
            } else if (sx == 16) {

              if (e.mouseMove.x >= 987 && e.mouseMove.x <= 1055 &&
                  e.mouseMove.y >= 766 && e.mouseMove.y <= 799) {
                meselected = true;
                miselected = false;
                maselected = false;
              } else
                meselected = false;
              if (e.mouseMove.x >= 1112 && e.mouseMove.x <= 1176 &&
                  e.mouseMove.y >= 834 && e.mouseMove.y <= 856) {
                meselected = false;
                miselected = true;
                maselected = false;
              } else
                miselected = false;
              if (e.mouseMove.x >= 992 && e.mouseMove.x <= 1045 &&
                  e.mouseMove.y >= 908 && e.mouseMove.y <= 934) {
                meselected = false;
                miselected = false;
                maselected = true;
              } else
                maselected = false;
              break;
            } else if (sx == 30) {
              if (e.mouseMove.x >= 708 && e.mouseMove.x <= 784 &&
                  e.mouseMove.y >= 963 && e.mouseMove.y <= 997) {
                meselected = true;
                miselected = false;
                maselected = false;
              } else
                meselected = false;
              if (e.mouseMove.x >= 835 && e.mouseMove.x <= 893 &&
                  e.mouseMove.y >= 899 && e.mouseMove.y <= 923) {
                meselected = false;
                miselected = true;
                maselected = false;
              } else
                miselected = false;
              if (e.mouseMove.x >= 950 && e.mouseMove.x <= 1006 &&
                  e.mouseMove.y >= 962 && e.mouseMove.y <= 988) {
                meselected = false;
                miselected = false;
                maselected = true;
              } else
                maselected = false;

              break;
            }
          } break;
          }
          switch (e.type) {
          case sf::Event::MouseMoved: {
            if (sx == 9) {
              if (settingpressed == false && e.mouseMove.x >= 724 &&
                  e.mouseMove.x <= 778 && e.mouseMove.y >= 484 &&
                  e.mouseMove.y <= 535) {
                sete.setColor(sf::Color::Magenta);
                settingselected = true;
              } else {
                settingselected = false;
                sete.setColor(sf::Color(168, 168, 168));
              }
              if (settingpressed == true) {
                sete.setColor(sf::Color(154, 80, 250));
                settingselected = false;
              }
              break;
            } else if (sx == 16) {

              if (settingpressed == false && e.mouseMove.x >= 995 &&
                  e.mouseMove.x <= 1049 && e.mouseMove.y >= 829 &&
                  e.mouseMove.y <= 878) {
                sete.setColor(sf::Color::Magenta);
                settingselected = true;
              } else {
                settingselected = false;
                sete.setColor(sf::Color(168, 168, 168));
              }
              if (settingpressed == true) {
                sete.setColor(sf::Color(154, 80, 250));
                settingselected = false;
              }
              break;
            } else if (sx == 30) {
              if (settingpressed == false && e.mouseMove.x >= 823 &&
                  e.mouseMove.x <= 877 && e.mouseMove.y >= 962 &&
                  e.mouseMove.y <= 1020) {
                sete.setColor(sf::Color::Magenta);
                settingselected = true;
              } else {
                settingselected = false;
                sete.setColor(sf::Color(168, 168, 168));
              }
              if (settingpressed == true) {
                sete.setColor(sf::Color(154, 80, 250));
                settingselected = false;
              }
              break;
            }
          } break;
          }
        }
        if (e.type == sf::Event::MouseButtonPressed) {
          if (settingselected == true) {
            if (e.mouseButton.button == sf::Mouse::Left) {
              settingpressed = true;
              easymode = intermode = advmode = true;
            }
          } else if (settingpressed == easymode == intermode == advmode ==
                     true) {
            if (e.mouseButton.button == sf::Mouse::Left) {
              settingpressed = false;
              easymode = intermode = advmode = false;
            }
          }
        }
        if (e.type == sf::Event::MouseButtonPressed) {
          int x = (int)(e.mouseButton.x / tilesize);
          int y = (int)(e.mouseButton.y / tilesize);
          if (meselected == true) {
            if (e.mouseButton.button == sf::Mouse::Left) {
              bombfound = false;
              window.close();
              sf::RenderWindow game_easy(sf::VideoMode(780, 540),
                                         "     Easy Mode", sf::Style::Close);
              createcanvas canvas;
              canvas.createcanvas_type(9, 9, 10, game_easy, canvas_easy,
                                       canvas_view_easy, 60);
              goto start;
            }
          } else if (miselected == true) {
            if (e.mouseButton.button == sf::Mouse::Left) {
              bombfound = false;
              window.close();
              sf::RenderWindow game_inter(sf::VideoMode(1920, 990),
                                          "    Intermediate Mode",
                                          sf::Style::Close);
              createcanvas canvas;
              canvas.createcanvas_type(16, 16, 40, game_inter, canvas_inter,
                                       canvas_view_inter, 55);
            }
          } else if (maselected == true) {
            if (e.mouseButton.button == sf::Mouse::Left) {
              bombfound = false;
              window.close();
              sf::RenderWindow game_adv(sf::VideoMode(1920, 1080),
                                        "Advance Mode", sf::Style::Close);
              createcanvas canvas;
              canvas.createcanvas_type(30, 16, 100, game_adv, canvas_adv,
                                       canvas_view_adv, 53);
              if (sx == 30) {
                if (settingpressed == false) {
                  settings.loadFromFile("images/opt.png");
                  sete.setTexture(settings);
                  sete.setPosition(sf::Vector2f(game_adv.getSize().x / 2,
                                                game_adv.getSize().y / 2));
                  sete.setOrigin(+140.f, -415.f);
                  settingpressed = false;
                  maselected = false;
                } else if (settingpressed == true) {
                  settings.loadFromFile("images/optr.png");
                  sete.setTexture(settings);
                  sete.setPosition(sf::Vector2f(game_adv.getSize().x / 2,
                                                game_adv.getSize().y / 2));
                  sete.setOrigin(+130.f, -405.f);
                }
                if (easymode = intermode = advmode == true) {

                  ezm.setFont(f);
                  ezm.setString("Easy");
                  ezm.setOutlineColor(sf::Color::Black);
                  ezm.setOutlineThickness(4);
                  ezm.setFillColor(sf::Color::White);
                  ezm.setPosition(sf::Vector2f(game_adv.getSize().x / 2,
                                               game_adv.getSize().y / 2));
                  ezm.setOrigin(+250.f, -415.f);
                  ezm.setCharacterSize(30);
                  //----------------------
                  izm.setFont(f);
                  izm.setString("Inter");
                  izm.setOutlineColor(sf::Color::Black);
                  izm.setOutlineThickness(4);
                  izm.setFillColor(sf::Color::White);
                  izm.setPosition(sf::Vector2f(game_adv.getSize().x / 2,
                                               game_adv.getSize().y / 2));
                  izm.setOrigin(+130, -350.f);
                  izm.setCharacterSize(30);
                  //----------------------------
                  azm.setFont(f);
                  azm.setString("Adv");
                  azm.setOutlineColor(sf::Color::Black);
                  azm.setOutlineThickness(4);
                  azm.setFillColor(sf::Color::White);
                  azm.setPosition(sf::Vector2f(game_adv.getSize().x / 2,
                                               game_adv.getSize().y / 2));
                  azm.setOrigin(+10.f, -415.f);
                  azm.setCharacterSize(30);
                }
                if (meselected == true) {
                  ezm.setFillColor(sf::Color::Green);
                  ezm.setPosition(sf::Vector2f(game_adv.getSize().x / 2,
                                               game_adv.getSize().y / 2));
                  ezm.setOrigin(+250.f, -415.f);
                  ezm.setCharacterSize(40);
                }
                if (miselected == true) {
                  izm.setFillColor(sf::Color::Yellow);
                  izm.setPosition(sf::Vector2f(game_adv.getSize().x / 2,
                                               game_adv.getSize().y / 2));
                  izm.setOrigin(+130, -350.f);
                  izm.setCharacterSize(40);
                }
                if (maselected == true) {
                  azm.setFillColor(sf::Color::Red);
                  azm.setPosition(sf::Vector2f(game_adv.getSize().x / 2,
                                               game_adv.getSize().y / 2));
                  azm.setOrigin(+10.f, -415.f);
                  azm.setCharacterSize(40);
                }
              }
            }
          }
          if ((e.mouseButton.button == sf::Mouse::Right)) {
            if (board_view[x][y] != 11 && board_view[x][y] == 10)
              board_view[x][y] = 11;
            else if (board_view[x][y] == 11)
              board_view[x][y] = 10;
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (e.mouseButton.button == sf::Mouse::Left) {
            if (board_view[x][y] == 20) // for hints
            {
              int flag = true;
              for (int i = rand() % 9; i < sx; i++) {
                for (int j = rand() % 9; j < sy; j++) {
                  if (board[i][j] != 9 && board_view[i][j] == 10 &&
                      flag == true && hints > 0) {
                    board_view[i][j] = 22;
                    hints--;
                    score--;
                    std::cout << score << "\n";
                    flag = false;
                  }
                }
              }
            }
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmm
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (x <= sx && x >= 0 && y <= sy && y >= 0) {
            if (e.mouseButton.button == sf::Mouse::Left) {
              board_view[x][y] = board[x][y];
              if (board_view[x][y] != 0) {
                score = score + 2;
                if (score >= 0 && bombfound != true) {
                  if (score > highscore) {
                    highscore = score;
                    high_score.setPosition(
                        sf::Vector2f(window.getSize().x / 2 + 190.f,
                                     window.getSize().y / 2 - 185.f));
                    high_score.setString("HighScore : " +
                                         std::to_string(highscore));
                    high_score.setFillColor(sf::Color(240, 135, 132));
                    high_score.setOutlineColor(sf::Color::Black);
                    high_score.setOutlineThickness(3);
                    high_score.setCharacterSize(25);
                    top_player = USERNAME;
                  }
                  user_score.setPosition(
                      sf::Vector2f(window.getSize().x / 2 + 200.f,
                                   window.getSize().y / 2 - 150.f));
                  user_score.setString("Score : " + std::to_string(score));
                  user_score.setFillColor(sf::Color(158, 161, 232));
                  user_score.setOutlineColor(sf::Color::Black);
                  user_score.setOutlineThickness(2);
                  user_score.setCharacterSize(30);
                }
              }

              if (board[x][y] == 0) {
                board_view[x][y] = board[x][y];
                tileskholdo(x, y, board, board_view);
                moves++;
                score++;
                std::cout << score << "\n";
                window.draw(tame);
              }
              //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
              //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
              if (board[x][y] == 9 && firstmove == true) {
                firstmovesafe(sx, sy, board, x, y);
                board_view[x][y] = board[x][y];
                firstmove = false;
              }
              if (board_view[x][y] == 9 && firstmove == false) {
                oneminefound == true;
                board_view[x][y] = board[x][y];
                moves++;
                window.draw(tame);
                bombfound = true;
                board_view[x][y] = board[x][y];
                for (int i = 0; i < sx; i++) {
                  for (int j = 0; j < sy; j++) {
                    board_view[i][j] = board[i][j];
                  }
                }
              }

              //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
            }
          }
        }
      }

      //        poll event closed
      //================================================
      //    /$$$$$$              /$$           /$$$$$$$$                    /$$
      //   /$$__  $$            | $$          |__  $$__/                   | $$
      //  | $$  \__/  /$$$$$$  /$$$$$$           | $$  /$$$$$$  /$$   /$$
      //  /$$$$$$   /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$$ |  $$$$$$  /$$__
      //  $$|_  $$_/           | $$ /$$__  $$|  $$ /$$/|_  $$_/  | $$  | $$
      //  /$$__  $$ /$$__  $$ /$$_____/
      //   \____  $$| $$$$$$$$  | $$             | $$| $$$$$$$$ \  $$$$/   | $$
      //   | $$  | $$| $$  \__/| $$$$$$$$|  $$$$$$
      //   /$$  \ $$| $$_____/  | $$ /$$         | $$| $$_____/  >$$  $$   | $$
      //   /$$| $$  | $$| $$      | $$_____/ \____  $$
      //  |  $$$$$$/|  $$$$$$$  |  $$$$/         | $$|  $$$$$$$ /$$/\  $$  |
      //  $$$$/|  $$$$$$/| $$      |  $$$$$$$ /$$$$$$$/
      //   \______/  \_______/   \___/           |__/ \_______/|__/  \__/ \___/
      //   \______/ |__/       \_______/|_______/
      //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
      // for settings

      if (bombfound == true) {
        t = 99;
      }
      if (sx == 9) {
        if (settingpressed == false) {

          settings.loadFromFile("images/opt.png");
          sete.setTexture(settings);
          sete.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          sete.setOrigin(-330.f, -210);
        } else {
          settings.loadFromFile("images/optr.png");
          sete.setTexture(settings);
          sete.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          sete.setOrigin(-330.f, -210);
        }
        if (easymode == intermode == advmode == true) {
          clicksave = true;
          ezm.setFont(f);
          ezm.setString("Easy");
          ezm.setOutlineColor(sf::Color::Black);
          ezm.setOutlineThickness(4);
          ezm.setFillColor(sf::Color::White);
          ezm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          ezm.setOrigin(-290.f, -120);
          ezm.setCharacterSize(30);
          //----------------------
          izm.setFont(f);
          izm.setString("Inter");
          izm.setOutlineColor(sf::Color::Black);
          izm.setOutlineThickness(4);
          izm.setFillColor(sf::Color::White);
          izm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          izm.setOrigin(-210.f, -160);
          izm.setCharacterSize(30);
          //----------------------------
          azm.setFont(f);
          azm.setString("Adv");
          azm.setOutlineColor(sf::Color::Black);
          azm.setOutlineThickness(4);
          azm.setFillColor(sf::Color::White);
          azm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          azm.setOrigin(-220.f, -230);
          azm.setCharacterSize(30);
        }
        if (easymode == false) {

          ezm.setFillColor(sf::Color::Transparent);
          ezm.setOutlineColor(sf::Color::Transparent);
          izm.setFillColor(sf::Color::Transparent);
          izm.setOutlineColor(sf::Color::Transparent);
          azm.setFillColor(sf::Color::Transparent);
          azm.setOutlineColor(sf::Color::Transparent);
        }
        if (meselected == true) {
          score = 0;
          ezm.setFillColor(sf::Color::Green);
          ezm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          ezm.setOrigin(-280.f, -110);
          ezm.setCharacterSize(40);
        }
        if (miselected == true) {
          score = 0;
          izm.setFillColor(sf::Color::Yellow);
          izm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          izm.setOrigin(-200.f, -150);
          izm.setCharacterSize(40);
        }
        if (maselected == true) {
          score = 0;
          azm.setFillColor(sf::Color::Red);
          azm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          azm.setOrigin(-210.f, -220);
          azm.setCharacterSize(40);
        }
      } else if (sx == 16) {
        if (savegameselected == true) {
          ;
        } else {
          savegame.loadFromFile("images/save.jpg");
          save.setTexture(savegame);
          save.setPosition(sf::Vector2f(window.getSize().x / 2 + 165.f,
                                        window.getSize().y / 2 + 250.f));
          save.setScale(sf::Vector2f((float)110 / (float)savegame.getSize().x,
                                     (float)110 / (float)savegame.getSize().y));
        }
        if (settingpressed == false) {
          settings.loadFromFile("images/opt.png");
          sete.setTexture(settings);
          sete.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          sete.setOrigin(-30.f, -280);
        }
        if (settingpressed == true) {
          settings.loadFromFile("images/optr.png");
          sete.setTexture(settings);
          sete.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          // sete.setOrigin(-50.f, -280);
        }
        if (easymode == intermode == advmode == true) {

          ezm.setFont(f);
          ezm.setString("Easy");
          ezm.setOutlineColor(sf::Color::Black);
          ezm.setOutlineThickness(4);
          ezm.setFillColor(sf::Color::White);
          ezm.setPosition(sf::Vector2f(window.getSize().x / 2 - 265.f,
                                       window.getSize().y / 2 + 100.f));
          ezm.setCharacterSize(30);
          //----------------------
          izm.setFont(f);
          izm.setString("Inter");
          izm.setOutlineColor(sf::Color::Black);
          izm.setOutlineThickness(4);
          izm.setFillColor(sf::Color::White);
          izm.setPosition(sf::Vector2f(window.getSize().x / 2 - 50.f,
                                       window.getSize().y / 2 + 135.f));
          izm.setCharacterSize(30);
          //----------------------------
          azm.setFont(f);
          azm.setString("Adv");
          azm.setOutlineColor(sf::Color::Black);
          azm.setOutlineThickness(4);
          azm.setFillColor(sf::Color::White);
          azm.setPosition(sf::Vector2f(window.getSize().x / 2 - 190.f,
                                       window.getSize().y / 2 + 130.f));
          azm.setCharacterSize(30);
        }
        if (easymode == false) {
          ezm.setFillColor(sf::Color::Transparent);
          ezm.setOutlineColor(sf::Color::Transparent);
          izm.setFillColor(sf::Color::Transparent);
          izm.setOutlineColor(sf::Color::Transparent);
          azm.setFillColor(sf::Color::Transparent);
          azm.setOutlineColor(sf::Color::Transparent);
        }
        if (meselected == true) {
          score = 0;
          ezm.setFillColor(sf::Color::Green);
          ezm.setPosition(sf::Vector2f(window.getSize().x / 2 - 275.f,
                                       window.getSize().y / 2 + 90.f));
          ezm.setCharacterSize(40);
        }
        if (miselected == true) {
          score = 0;
          izm.setFillColor(sf::Color::Yellow);
          izm.setPosition(sf::Vector2f(window.getSize().x / 2 - 60.f,
                                       window.getSize().y / 2 + 130.f));
          izm.setCharacterSize(40);
        }
        if (maselected == true) {
          score = 0;
          azm.setFillColor(sf::Color::Red);
          azm.setPosition(sf::Vector2f(window.getSize().x / 2 - 200.f,
                                       window.getSize().y / 2 + 120.f));
          azm.setCharacterSize(40);
        }
      } else if (sx == 30) {
        if (settingpressed == false) {
          settings.loadFromFile("images/opt.png");
          sete.setTexture(settings);
          sete.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          sete.setOrigin(+140.f, -415.f);
          settingpressed = false;
          maselected = false;
        } else if (settingpressed == true) {
          settings.loadFromFile("images/optr.png");
          sete.setTexture(settings);
          sete.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          sete.setOrigin(+130.f, -405.f);
        }
        if (easymode = intermode = advmode == true) {

          ezm.setFont(f);
          ezm.setString("Easy");
          ezm.setOutlineColor(sf::Color::Black);
          ezm.setOutlineThickness(4);
          ezm.setFillColor(sf::Color::White);
          ezm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          ezm.setOrigin(+250.f, -415.f);
          ezm.setCharacterSize(30);
          //----------------------
          izm.setFont(f);
          izm.setString("Inter");
          izm.setOutlineColor(sf::Color::Black);
          izm.setOutlineThickness(4);
          izm.setFillColor(sf::Color::White);
          izm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          izm.setOrigin(+130, -350.f);
          izm.setCharacterSize(30);
          //----------------------------
          azm.setFont(f);
          azm.setString("Adv");
          azm.setOutlineColor(sf::Color::Black);
          azm.setOutlineThickness(4);
          azm.setFillColor(sf::Color::White);
          azm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          azm.setOrigin(+10.f, -415.f);
          azm.setCharacterSize(30);
        }
        if (meselected == true) {
          score = 0;
          ezm.setFillColor(sf::Color::Green);
          ezm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          ezm.setOrigin(+250.f, -415.f);
          ezm.setCharacterSize(40);
        }
        if (miselected == true) {
          score = 0;
          izm.setFillColor(sf::Color::Yellow);
          izm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          izm.setOrigin(+130, -350.f);
          izm.setCharacterSize(40);
        }
        if (maselected == true) {
          score = 0;
          azm.setFillColor(sf::Color::Red);
          azm.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          azm.setOrigin(+10.f, -415.f);
          azm.setCharacterSize(40);
        }
      }
      if (sx == 30) {
        aa.setPosition(sf::Vector2f(window.getSize().x / 2 + 150.f,
                                    window.getSize().y / 2));
        aa.setOrigin(-500.f, 300.f);
        if (t == 0 && sx == 30) {
          a.loadFromFile("time/0.png");
          aa.setTexture(a);
          aa.setPosition(sf::Vector2f(window.getSize().x / 2 + 150.f,
                                      window.getSize().y / 2));
          aa.setOrigin(-500.f, 300.f);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 1 && sx == 30) {
          a.loadFromFile("time/1.png");
          aa.setTexture(a);
        }
        if (t == 2 && sx == 30) {
          a.loadFromFile("time/2.png");
          aa.setTexture(a);
        }
        if (t == 3 && sx == 30) {
          a.loadFromFile("time/3.png");
          aa.setTexture(a);
        }
        if (t == 4 && sx == 30) {
          a.loadFromFile("time/4.png");
          aa.setTexture(a);
        }
        if (t == 5 && sx == 30) {
          a.loadFromFile("time/5.png");
          aa.setTexture(a);
        }
        if (t == 6 && sx == 30) {
          a.loadFromFile("time/6.png");
          aa.setTexture(a);
        }
        if (t == 7 && sx == 30) {

          a.loadFromFile("time/7.png");
          aa.setTexture(a);
        }
        if (t == 8 && sx == 30) {
          a.loadFromFile("time/8.png");
          aa.setTexture(a);
        }
        if (t == 9 && sx == 30) {
          a.loadFromFile("time/9.png");
          aa.setTexture(a);
        }
        if (t == 10 && sx == 30) {
          a.loadFromFile("time/10.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Red);
        }
        if (t == 11) {
          a.loadFromFile("time/11.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 12) {
          a.loadFromFile("time/12.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 13) {
          window.clear();
          a.loadFromFile("time/13.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 14) {
          a.loadFromFile("time/14.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 15) {
          a.loadFromFile("time/15.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 16) {
          a.loadFromFile("time/16.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 17) {
          a.loadFromFile("time/17.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 18) {
          a.loadFromFile("time/18.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 19) {
          a.loadFromFile("time/19.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 20) {
          a.loadFromFile("time/20.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Red);
        }
        if (t == 21) {
          a.loadFromFile("time/21.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 22) {
          a.loadFromFile("time/22.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 23) {
          a.loadFromFile("time/23.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 24) {
          a.loadFromFile("time/24.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 25) {
          a.loadFromFile("time/25.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 26) {
          a.loadFromFile("time/26.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 27) {
          a.loadFromFile("time/27.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 28) {
          a.loadFromFile("time/28.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 29) {
          a.loadFromFile("time/29.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 30) {
          a.loadFromFile("time/30.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Red);
        }
        if (t == 31) {
          a.loadFromFile("time/31.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 32) {
          a.loadFromFile("time/32.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 33) {
          a.loadFromFile("time/33.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 34) {
          a.loadFromFile("time/34.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 35) {
          a.loadFromFile("time/35.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 36) {
          a.loadFromFile("time/36.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 37) {
          a.loadFromFile("time/37.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 38) {
          a.loadFromFile("time/38.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 39) {
          a.loadFromFile("time/39.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 40) {
          a.loadFromFile("time/40.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Red);
        }
        if (t == 41) {
          a.loadFromFile("time/41.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 42) {
          a.loadFromFile("time/42.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 43) {
          a.loadFromFile("time/43.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 44) {
          a.loadFromFile("time/44.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 45) {
          a.loadFromFile("time/45.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 46) {
          a.loadFromFile("time/46.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 47) {
          a.loadFromFile("time/47.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 48) {
          a.loadFromFile("time/48.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 49) {
          a.loadFromFile("time/49.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 50) {
          a.loadFromFile("time/50.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Red);
        }
        if (t == 51) {
          a.loadFromFile("time/51.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 52) {
          a.loadFromFile("time/52.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 53) {
          a.loadFromFile("time/53.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 54) {
          a.loadFromFile("time/54.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 55) {
          a.loadFromFile("time/55.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 56) {
          a.loadFromFile("time/56.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 57) {
          a.loadFromFile("time/57.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 58) {
          a.loadFromFile("time/58.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 59) {
          a.loadFromFile("time/59.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 60) {
          a.loadFromFile("time/60.png");
          aa.setTexture(a);
        }
      }
      //==================================================
      else if (sx == 9 || sx == 16) {

        if (t == 0) {

          a.loadFromFile("time/0.png");
          aa.setTexture(a);
          aa.setPosition(
              sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
          aa.setOrigin(-120.f, 150.f);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 1) {
          aa.setTexture(blue);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 2) {
          aa.setTexture(cc);
          aa.setColor(sf::Color::Magenta);
          aa.getInverseTransform();
        }
        if (t == 3) {
          aa.setTexture(d);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 4) {
          aa.setTexture(egg);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 5) {
          aa.setTexture(ff);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 6) {
          aa.setTexture(g);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 7) {
          aa.setTexture(hh);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 8) {
          aa.setTexture(i);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 9) {
          aa.setTexture(j);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 10) {
          aa.setTexture(k);
          aa.setColor(sf::Color::Red);
        }
        if (t == 11) {
          a.loadFromFile("time/11.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 12) {
          a.loadFromFile("time/12.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 13) {
          window.clear();
          a.loadFromFile("time/13.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 14) {
          a.loadFromFile("time/14.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 15) {
          a.loadFromFile("time/15.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 16) {
          a.loadFromFile("time/16.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 17) {
          a.loadFromFile("time/17.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 18) {
          a.loadFromFile("time/18.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 19) {
          a.loadFromFile("time/19.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 20) {
          a.loadFromFile("time/20.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Red);
        }
        if (t == 21) {
          a.loadFromFile("time/21.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 22) {
          a.loadFromFile("time/22.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 23) {
          a.loadFromFile("time/23.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 24) {
          a.loadFromFile("time/24.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 25) {
          a.loadFromFile("time/25.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 26) {
          a.loadFromFile("time/26.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 27) {
          a.loadFromFile("time/27.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 28) {
          a.loadFromFile("time/28.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 29) {
          a.loadFromFile("time/29.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 30) {
          a.loadFromFile("time/30.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Red);
        }
        if (t == 31) {
          a.loadFromFile("time/31.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 32) {
          a.loadFromFile("time/32.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 33) {
          a.loadFromFile("time/33.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 34) {
          a.loadFromFile("time/34.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 35) {
          a.loadFromFile("time/35.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 36) {
          a.loadFromFile("time/36.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 37) {
          a.loadFromFile("time/37.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 38) {
          a.loadFromFile("time/38.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 39) {
          a.loadFromFile("time/39.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 40) {
          a.loadFromFile("time/40.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 41) {
          a.loadFromFile("time/41.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 42) {
          a.loadFromFile("time/42.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 43) {
          a.loadFromFile("time/43.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 44) {
          a.loadFromFile("time/44.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 45) {
          a.loadFromFile("time/45.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 46) {
          a.loadFromFile("time/46.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 47) {
          a.loadFromFile("time/47.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 48) {
          a.loadFromFile("time/48.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 49) {
          a.loadFromFile("time/49.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 50) {
          a.loadFromFile("time/50.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Red);
        }
        if (t == 51) {
          a.loadFromFile("time/51.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 52) {
          a.loadFromFile("time/52.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 53) {
          a.loadFromFile("time/53.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 54) {
          a.loadFromFile("time/54.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 55) {
          a.loadFromFile("time/55.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 56) {
          a.loadFromFile("time/56.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 57) {
          a.loadFromFile("time/57.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 58) {
          a.loadFromFile("time/58.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 59) {
          a.loadFromFile("time/59.png");
          aa.setTexture(a);
          aa.setColor(sf::Color::Magenta);
        }
        if (t == 60) {
          a.loadFromFile("time/60.png");
          aa.setTexture(a);
        }
      }
      if (hinpre == true) {
        sf::Texture hint;
        hint.loadFromFile("images/hintt.png");
        sf::Sprite h(hint);
        h.setPosition(
            sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
        h.setOrigin(h.getLocalBounds().width / 2 - 1110.f,
                    h.getLocalBounds().height + 400.f);
        h.setScale(sf::Vector2f((float)tilesize / (float)hint.getSize().x,
                                (float)tilesize / (float)hint.getSize().y));
        window.draw(h);
        // sf::sleep();
        hintnormal = true;
      }
      // mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
      for (int i = 0; i < 50; i++) {
        for (int j = sy; j < 50; j++) {
          if (board_view[i][j] == 0) {
            emp.setPosition(i * tilesize, j * tilesize);
            emp.setScale(sf::Vector2f((float)tilesize / (float)em.getSize().x,
                                      (float)tilesize / (float)em.getSize().y));
            window.draw(emp);
          }
        }
      }
      for (int i = sx; i < 50; i++) {
        for (int j = 0; j < 50; j++) {

          if (board_view[i][j] == 0) {
            emp.setPosition(i * tilesize, j * tilesize);
            emp.setScale(sf::Vector2f((float)tilesize / (float)em.getSize().x,
                                      (float)tilesize / (float)em.getSize().y));
            window.draw(emp);
          }
          if (board_view[i][j] == 20) {
            if (sx == 16) {
              sf::Texture hint;
              hint.loadFromFile("images/hint.png");
              sf::Sprite h(hint);
              h.setPosition(sf::Vector2f(i * tilesize, j * tilesize));
              h.setScale(
                  sf::Vector2f((float)tilesize / (float)hint.getSize().x,
                               (float)tilesize / (float)hint.getSize().y));
              window.draw(h);
            } else if (sx == 9) {

              sf::Texture hint;
              hint.loadFromFile("images/hint.png");
              sf::Sprite h(hint);
              h.setPosition(sf::Vector2f(i * tilesize, j * tilesize));
              h.setScale(
                  sf::Vector2f((float)tilesize / (float)hint.getSize().x,
                               (float)tilesize / (float)hint.getSize().y));
              window.draw(h);
            } else if (sx == 30) {
              sf::Texture hint;
              hint.loadFromFile("images/hint.png");
              sf::Sprite h(hint);
              h.setPosition(sf::Vector2f(i * tilesize, j * tilesize));
              h.setScale(
                  sf::Vector2f((float)tilesize / (float)hint.getSize().x,
                               (float)tilesize / (float)hint.getSize().y));
              window.draw(h);
            }
          }
        }
      }
      for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {

          //---------------------------------------------------------
          if (board_view[i][j] == 10) {
            // canvas_view_easy[i][j] = canvas_easy[i][j];
            v.setPosition(i * tilesize, j * tilesize);
            v.setScale(sf::Vector2f((float)tilesize / (float)view.getSize().x,
                                    (float)tilesize / (float)view.getSize().y));
            window.draw(v);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 1) {
            o.setTexture(one);
            o.setPosition(i * tilesize, j * tilesize);
            o.setScale(sf::Vector2f((float)tilesize / (float)one.getSize().x,
                                    (float)tilesize / (float)one.getSize().y));
            window.draw(o);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 2) {
            tw.setPosition(i * tilesize, j * tilesize);
            tw.setScale(sf::Vector2f((float)tilesize / (float)two.getSize().x,
                                     (float)tilesize / (float)two.getSize().y));
            window.draw(tw);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 3) {
            th.setPosition(i * tilesize, j * tilesize);
            th.setScale(
                sf::Vector2f((float)tilesize / (float)three.getSize().x,
                             (float)tilesize / (float)three.getSize().y));
            window.draw(th);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 4) {
            fo.setPosition(i * tilesize, j * tilesize);
            fo.setScale(
                sf::Vector2f((float)tilesize / (float)four.getSize().x,
                             (float)tilesize / (float)four.getSize().y));
            window.draw(fo);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 5) {
            fi.setPosition(i * tilesize, j * tilesize);
            fi.setScale(
                sf::Vector2f((float)tilesize / (float)five.getSize().x,
                             (float)tilesize / (float)five.getSize().y));
            window.draw(fi);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 6) {
            si.setPosition(i * tilesize, j * tilesize);
            si.setScale(sf::Vector2f((float)tilesize / (float)six.getSize().x,
                                     (float)tilesize / (float)six.getSize().y));
            window.draw(si);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 7) {
            se.setPosition(i * tilesize, j * tilesize);
            se.setScale(
                sf::Vector2f((float)tilesize / (float)seven.getSize().x,
                             (float)tilesize / (float)seven.getSize().y));
            window.draw(se);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 8) {
            ei.setPosition(i * tilesize, j * tilesize);
            ei.setScale(
                sf::Vector2f((float)tilesize / (float)eight.getSize().x,
                             (float)tilesize / (float)eight.getSize().y));
            window.draw(ei);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 9) {
            bomb.setPosition(i * tilesize, j * tilesize);
            bomb.setScale(
                sf::Vector2f((float)tilesize / (float)bo.getSize().x,
                             (float)tilesize / (float)bo.getSize().y));
            window.draw(bomb);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 11) {
            sf::Sprite f(flag);
            f.setPosition(i * tilesize, j * tilesize);
            f.setScale(sf::Vector2f((float)tilesize / (float)flag.getSize().x,
                                    (float)tilesize / (float)flag.getSize().y));
            window.draw(f);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 0) {
            emp.setPosition(i * tilesize, j * tilesize);
            emp.setScale(sf::Vector2f((float)tilesize / (float)em.getSize().x,
                                      (float)tilesize / (float)em.getSize().y));
            window.draw(emp);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 11) {
            sf::Texture pat;
            pat.loadFromFile("images/flag.png");
            sf::Sprite p(pat);
            p.setPosition(i * tilesize, j * tilesize);
            p.setScale(sf::Vector2f((float)tilesize / (float)pat.getSize().x,
                                    (float)tilesize / (float)pat.getSize().y));
            window.draw(p);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 20) {
            sf::Texture hint;
            hint.loadFromFile("images/hint.png");
            sf::Sprite h(hint);
            h.setPosition(sf::Vector2f(i * tilesize, j * tilesize));
            h.setScale(sf::Vector2f((float)tilesize / (float)hint.getSize().x,
                                    (float)tilesize / (float)hint.getSize().y));
            window.draw(h);
          }
          //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
          if (board_view[i][j] == 22) {
            sf::Texture hint;
            hint.loadFromFile("images/safe.png");
            sf::Sprite h(hint);
            h.setPosition(sf::Vector2f(i * tilesize, j * tilesize));
            h.setScale(sf::Vector2f((float)tilesize / (float)hint.getSize().x,
                                    (float)tilesize / (float)hint.getSize().y));
            window.draw(h);
          }
          //		//
          //mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
        }
      }
      window.draw(patt);
      window.draw(sete);
      window.draw(outtile);
      window.draw(aa);
      if (easymode == true) {
        window.draw(ezm);
        window.draw(izm);
        window.draw(azm);
      }
      window.draw(h);
      window.draw(save);
      window.draw(user_name);
      window.draw(user_score);
      window.draw(high_score);
      window.draw(topplayer);
      window.display();
    }
  }
};
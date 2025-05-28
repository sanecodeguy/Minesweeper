#pragma once
#include "canvas.h"
#include "classes.h"
#include <SFML/Graphics.hpp>

//   /$$      /$$
//  | $$$    /$$$
//  | $$$$  /$$$$        /$$$$$$        /$$$$$$$        /$$   /$$
//  | $$ $$/$$ $$       /$$__  $$      | $$__  $$      | $$  | $$
//  | $$  $$$| $$      | $$$$$$$$      | $$  \ $$      | $$  | $$
//  | $$\  $ | $$      | $$_____/      | $$  | $$      | $$  | $$
//  | $$ \/  | $$      |  $$$$$$$      | $$  | $$      |  $$$$$$/
//  |__/     |__/       \_______/      |__/  |__/       \______/
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
class Menu : public createcanvas {
  bool easy_button_selected;
  bool easy_button_pressed;
  bool inter_button_selected;
  bool inter_button_pressed;
  bool adv_button_selected;
  bool adv_button_pressed;
  bool easyb;
  bool interb;
  bool advb;

public:
  sf::Sprite displaybackground();
  void Draw();
  void Process();
  void Text();
  void select();
  // int** init();
  Menu(); // server end
  ~Menu();
};
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
sf::Sprite Menu::displaybackground() {
  texture.loadFromFile("images/img12.jpg");
  sf::Sprite x(texture);
  return x;
}
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Menu::select() {
  if (easy_button_selected) {
    easy_opt.setCharacterSize(70);
    easy_opt.setOutlineColor(sf::Color::White);
    easy_opt.setOutlineThickness(20);
    easy_opt.setFillColor(sf::Color::Green);
    easy_opt.setOrigin(easy_opt.getLocalBounds().width / 2,
                       easy_opt.getLocalBounds().height / 2 + 85.f);
  }
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  else if (inter_button_selected) {
    inter_opt.setCharacterSize(70);
    inter_opt.setOutlineColor(sf::Color::White);
    inter_opt.setOutlineThickness(20);
    inter_opt.setFillColor(sf::Color::Yellow);
    inter_opt.setOrigin(inter_opt.getLocalBounds().width / 2,
                        inter_opt.getLocalBounds().height / 2 - 50.f);
  }
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  else if (adv_button_selected) {
    adv_opt.setCharacterSize(70);
    adv_opt.setOutlineColor(sf::Color::White);
    adv_opt.setOutlineThickness(20);
    adv_opt.setFillColor(sf::Color::Red);
    adv_opt.setOrigin(adv_opt.getLocalBounds().width / 2,
                      adv_opt.getLocalBounds().height / 2 - 180.f);
  }
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  if (easy_button_pressed) {
    create_easy = true;
    if (create_easy == true) {
      inter_button_pressed = false;
      adv_button_pressed = false;
      easy_button_pressed = true;
      menu.close();
      create_easy = false;
      sf::RenderWindow game_easy(sf::VideoMode(780, 540), "     Easy Mode",
                                 sf::Style::Close);
      createcanvas canvas;
      canvas.createcanvas_type(9, 9, 10, game_easy, canvas_easy,
                               canvas_view_easy, 60);
    }
  }
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  else if (inter_button_pressed) {
    inter_button_pressed = true;
    adv_button_pressed = false;
    easy_button_pressed = false;
    menu.close();
    sf::RenderWindow game_inter(sf::VideoMode(1920, 1080),
                                "    Intermediate Mode", sf::Style::Close);
    createcanvas canvas;
    canvas.createcanvas_type(16, 16, 40, game_inter, canvas_inter,
                             canvas_view_inter, 55);
    if (sx == 16) {
      if (savegameselected == true) {
        ;
      } else {
        savegame.loadFromFile("images/hehe.png");
        save.setTexture(savegame);
        save.setPosition(sf::Vector2f(game_inter.getSize().x / 2 + 200.f,
                                      game_inter.getSize().y / 2 + 250.f));
        save.setScale(sf::Vector2f((float)110 / (float)savegame.getSize().x,
                                   (float)110 / (float)savegame.getSize().y));
      }
      if (settingpressed == false) {
        settings.loadFromFile("images/opt.png");
        sete.setTexture(settings);
        sete.setPosition(sf::Vector2f(game_inter.getSize().x / 2,
                                      game_inter.getSize().y / 2));
        sete.setOrigin(-30.f, -280);
      }
      if (settingpressed == true) {
        settings.loadFromFile("images/optr.png");
        sete.setTexture(settings);
        sete.setPosition(sf::Vector2f(game_inter.getSize().x / 2,
                                      game_inter.getSize().y / 2));
        // sete.setOrigin(-50.f, -280);
      }
      if (easymode == intermode == advmode == true) {
        ezm.setFont(f);
        ezm.setString("Easy");
        ezm.setOutlineColor(sf::Color::Black);
        ezm.setOutlineThickness(4);
        ezm.setFillColor(sf::Color::White);
        ezm.setPosition(sf::Vector2f(game_inter.getSize().x / 2 - 265.f,
                                     game_inter.getSize().y / 2 + 100.f));
        ezm.setCharacterSize(30);
        //----------------------
        izm.setFont(f);
        izm.setString("Inter");
        izm.setOutlineColor(sf::Color::Black);
        izm.setOutlineThickness(4);
        izm.setFillColor(sf::Color::White);
        izm.setPosition(sf::Vector2f(game_inter.getSize().x / 2 - 50.f,
                                     game_inter.getSize().y / 2 + 135.f));
        izm.setCharacterSize(30);
        //----------------------------
        azm.setFont(f);
        azm.setString("Adv");
        azm.setOutlineColor(sf::Color::Black);
        azm.setOutlineThickness(4);
        azm.setFillColor(sf::Color::White);
        azm.setPosition(sf::Vector2f(game_inter.getSize().x / 2 - 190.f,
                                     game_inter.getSize().y / 2 + 130.f));
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
        ezm.setFillColor(sf::Color::Green);
        ezm.setPosition(sf::Vector2f(game_inter.getSize().x / 2 - 275.f,
                                     game_inter.getSize().y / 2 + 90.f));
        ezm.setCharacterSize(40);
      }
      if (miselected == true) {
        izm.setFillColor(sf::Color::Yellow);
        izm.setPosition(sf::Vector2f(game_inter.getSize().x / 2 - 60.f,
                                     game_inter.getSize().y / 2 + 130.f));
        izm.setCharacterSize(40);
      }
      if (maselected == true) {
        azm.setFillColor(sf::Color::Red);
        azm.setPosition(sf::Vector2f(game_inter.getSize().x / 2 - 200.f,
                                     game_inter.getSize().y / 2 + 120.f));
        azm.setCharacterSize(40);
      }
    }
  }
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  else if (adv_button_pressed) {
    inter_button_pressed = false;
    adv_button_pressed = true;
    easy_button_pressed = false;
    menu.close();
    sf::RenderWindow game_adv(sf::VideoMode(1920, 1080), "Advance Mode",
                              sf::Style::Close);
    createcanvas canvas;
    canvas.createcanvas_type(30, 16, 100, game_adv, canvas_adv, canvas_view_adv,
                             53);
  }
}
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
Menu::~Menu() {
  easy_button_selected = false;
  easy_button_pressed = false;
  inter_button_selected = false;
  inter_button_pressed = false;
  adv_button_selected = false;
  adv_button_pressed = false;
}
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
Menu::Menu() {
  easy_button_selected = false;
  easy_button_pressed = false;
  inter_button_selected = false;
  inter_button_pressed = false;
  adv_button_selected = false;
  adv_button_pressed = false;
  easyb = false;
  interb = false;
  advb = false;
}
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Menu::Text() {
  title.setFont(f1);
  title.setString("MineSweeper");
  title.setPosition(sf::Vector2f(menu.getSize().x / 2, menu.getSize().y / 2));
  title.setCharacterSize(100);
  title.setOrigin(title.getLocalBounds().width / 2 + 10.f,
                  title.getLocalBounds().height / 2 + 500.f);
  title.setOutlineColor(sf::Color::White);
  title.setFillColor(sf::Color(235, 154, 235));
  title.setOutlineThickness(10);
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  easy_opt.setFont(f1);
  easy_opt.setString("Easy");
  easy_opt.setPosition(
      sf::Vector2f(menu.getSize().x / 2, menu.getSize().y / 2));
  easy_opt.setCharacterSize(50);
  easy_opt.setOrigin(easy_opt.getLocalBounds().width / 2 + 10.f,
                     easy_opt.getLocalBounds().height / 2 + 85.f);
  easy_opt.setOutlineColor(sf::Color::White);
  easy_opt.setFillColor(sf::Color(237, 55, 130));
  easy_opt.setOutlineThickness(10);
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  adv_opt.setFont(f1);
  adv_opt.setString("Advance");
  adv_opt.setPosition(sf::Vector2f(menu.getSize().x / 2, menu.getSize().y / 2));
  adv_opt.setCharacterSize(50);
  adv_opt.setOrigin(adv_opt.getLocalBounds().width / 2,
                    adv_opt.getLocalBounds().height / 2 - 180.f);
  adv_opt.setOutlineColor(sf::Color::White);
  adv_opt.setFillColor(sf::Color(237, 55, 130));
  adv_opt.setOutlineThickness(10);
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  inter_opt.setFont(f1);
  inter_opt.setString("Intermediate");
  inter_opt.setPosition(
      sf::Vector2f(menu.getSize().x / 2, menu.getSize().y / 2));
  inter_opt.setCharacterSize(50);
  inter_opt.setOrigin(inter_opt.getLocalBounds().width / 2,
                      inter_opt.getLocalBounds().height / 2 - 50.f);
  inter_opt.setOutlineColor(sf::Color::White);
  inter_opt.setFillColor(sf::Color(237, 55, 130));
  inter_opt.setOutlineThickness(10);
  //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
  credits.setFont(f1);
  credits.setFont(f1);
  credits.setString("Made By Raham & Rizvi �");
  credits.setPosition(sf::Vector2f(menu.getSize().x / 2, menu.getSize().y / 2));
  credits.setCharacterSize(25);
  credits.setOrigin(credits.getLocalBounds().width / 2,
                    credits.getLocalBounds().height / 2 - 300.f);
  credits.setOutlineColor(sf::Color::Black);
  credits.setFillColor(sf::Color(240, 136, 191));
  credits.setStyle(sf::Text::Style::Italic | sf::Text::Style::Underlined);
  credits.setOutlineThickness(3);
}
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Menu::Draw() {
  Menu::displaybackground();
  menu.draw(displaybackground());
  menu.draw(easy_opt);
  menu.draw(inter_opt);
  menu.draw(adv_opt);
  menu.draw(title);
  // menu.draw(credits);
  // menu.draw(arrow);
  menu.display();
}
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Menu::Process() {
  // Credits window render here
  /*sf::RenderWindow credit(sf::VideoMode(1920, 1080), "Credits",
sf::Style::Fullscreen); while (credit.isOpen())
          {
                  sf::Event c;
                  while (credit.pollEvent(c))
                  {
                          if (c.type == sf::Event::Closed)
                                  credit.close();
                          credit.draw(s);
}
                  credit.display();
                  Sleep(1500);
                  credit.clear();
                  credit.close();
          }*/
  // Menu Window render here
  while (menu.isOpen()) {
    sf::Event m;
    while (menu.pollEvent(m)) {
      if (m.type == sf::Event::Closed) {
        menu.close();
      }
      //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
      if (m.type == sf::Event::MouseButtonPressed) {
        if (easy_button_selected == true) {
          switch (m.key.code) {
          case sf::Mouse::Left: {
            easy_button_pressed = true;
            inter_button_pressed = false;
            adv_button_pressed = false;
            break;
          } break;
          }
        }
      }
      if (m.type == sf::Event::MouseButtonPressed) {
        if (inter_button_selected == true) {
          switch (m.key.code) {
          case sf::Mouse::Left: {
            easy_button_pressed = false;
            inter_button_pressed = true;
            adv_button_pressed = false;
            break;
          } break;
          }
        }
      }
      if (m.type == sf::Event::MouseButtonPressed) {
        if (adv_button_selected == true) {
          switch (m.key.code) {
          case sf::Mouse::Left: {
            easy_button_pressed = false;
            inter_button_pressed = false;
            adv_button_pressed = true;
            break;
          } break;
          }
        }
      }
      //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
      else if (m.type == sf::Event::MouseMoved) {
        switch (m.type) {

        case sf::Event::MouseMoved: {
          // std::cout << "x : " << m.mouseMove.x << " | y : " << m.mouseMove.y
          // << "\n";
          if (m.mouseMove.x <= 1024 && m.mouseMove.x >= 863 &&
              m.mouseMove.y >= 412 && m.mouseMove.y <= 491) {
            easy_button_selected = true;
            inter_button_selected = false;
            adv_button_selected = false;
            easyb = true;
            interb = false;
            advb = false;
            break;
          } else
            easy_button_selected = false;
        }
        }
        //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
        switch (m.type) {
        case sf::Event::MouseMoved: {
          if (m.mouseMove.x >= 762 && m.mouseMove.x <= 1153 &&
              m.mouseMove.y <= 616 && m.mouseMove.y >= 569) {
            easy_button_selected = false;
            inter_button_selected = true;
            // inter_button_pressed = true;
            adv_button_selected = false;
            easyb = false;
            interb = true;
            advb = false;
            break;
          } else
            inter_button_selected = false;
        }
        }
        //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
        switch (m.type) {
        case sf::Event::MouseMoved: {
          if (m.mouseMove.x >= 810 && m.mouseMove.x <= 1098 &&
              m.mouseMove.y <= 746 && m.mouseMove.y >= 700) {
            easy_button_selected = false;
            inter_button_selected = false;
            adv_button_selected = true;
            easyb = false;
            interb = false;
            advb = true;
            break;
          } else
            adv_button_selected = false;
        }
        }
        //  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
      }
      this->Text();
      this->select();
    }
    this->Draw();
    menu.display();
  }
}
//  mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm

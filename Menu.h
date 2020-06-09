#ifndef DOODLEJUMP2_MENU_H
#define DOODLEJUMP2_MENU_H
#include <SFML/Graphics.hpp>
#include "Game.h"


class Menu
{
    Game & game;

    sf::Texture playbuttonTexture;
    sf::Texture playagainbuttonTexture;
    sf::Texture cancelbuttonTexture;
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::RectangleShape playbutton;
    sf::RectangleShape cancelbutton;
    //sf::RectangleShape playagainbutton;

public:

    Menu(Game & G);
    void Menu1_display(sf::RenderWindow &window);
    void Menu1();
    void Menu2();
    void Menu2_display(sf::RenderWindow &window);
    void Menu_controler(sf::Event &event,sf::RenderWindow &window);
};

#endif //DOODLEJUMP2_MENU_H

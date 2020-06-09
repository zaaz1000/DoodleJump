#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <iostream>

Menu::Menu(Game & G) : game(G)
{
    playbuttonTexture.loadFromFile("../play-button.png");
    cancelbuttonTexture.loadFromFile("../cancel-button.png");
    backgroundTexture.loadFromFile("../background.png");
    playagainbuttonTexture.loadFromFile("../play_again.Gif");

    playbutton.setSize(sf::Vector2f(90,50));
    playbutton.setPosition(215,150);
    playbutton.setTexture(&playbuttonTexture);

    cancelbutton.setSize(sf::Vector2f(90,50));
    cancelbutton.setPosition(215,400);
    cancelbutton.setTexture(&cancelbuttonTexture);

    background.setSize(sf::Vector2f(500,700));
    background.setPosition(0,0);
    background.setTexture(&backgroundTexture);

    //playagainbutton.setSize(sf::Vector2f(90,50));
    //playagainbutton.setPosition(sf::Vector2f(215,150));
    //playagainbutton.setTexture(&playagainbuttonTexture);

}

void Menu::Menu1_display(sf::RenderWindow &window)
{
    window.draw(background);
    window.draw(playbutton);
    window.draw(cancelbutton);
}
void Menu::Menu1()
{
    game.gamestate=game.MENU;
}

void Menu::Menu2_display(sf::RenderWindow &window)
{
    window.draw(background);
    //window.draw(playagainbutton);
    window.draw(game.points);
    //window.draw(game.bestpoints);
    window.draw(cancelbutton);
}
void Menu::Menu2()
{
    game.gamestate=game.GAMEOVER;
}


void Menu::Menu_controler(sf::Event &event,sf::RenderWindow &window)
{
    if(event.type==sf::Event::MouseButtonPressed && event.mouseButton.x >= 215 && event.mouseButton.x <= 295
       && event.mouseButton.y >= 150 && event.mouseButton.y <= 230)
    {
        this->game.gamestate=game.GAME;
    }

    if(event.type==sf::Event::MouseButtonPressed && event.mouseButton.x >= 215 && event.mouseButton.x <= 295
       && event.mouseButton.y >= 400 && event.mouseButton.y <= 480)
    {
        window.close();
    }
}
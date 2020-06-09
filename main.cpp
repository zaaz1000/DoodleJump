#include <SFML/Window.hpp>>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Game.h"
#include "Doodle.h"
#include "Platform.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500,700),"DoodleJump", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Clock clock;
    sf::Event event;
    Platfor platfor;
    Game game;
    Menu menu(game);
    Doodle doodle(platfor, game);
    platfor.Platform();
    platfor.Spring();
    game.gamestate=game.MENU;
    while(window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(game.gamestate==game.MENU)
        {
            window.clear();
            menu.Menu1();
            menu.Menu_controler(event,window);
            menu.Menu1_display(window);
            window.display();

        }
        if(game.gamestate==game.GAMEOVER)
        {
            window.clear();
            menu.Menu2();
            menu.Menu_controler(event,window);
            menu.Menu2_display(window);
            window.display();
        }
        if(game.gamestate==game.GAME)
        {
            window.clear();
            doodle.Jump();
            doodle.JumpOnPlatform();
            doodle.getSpring();
            doodle.Stearing();
            doodle.GameOver();
            doodle.Points();
            game.Game_display(window);
            platfor.Platform_display(window);
            doodle.Doodle_display(window);
            game.Points_display(window);
            window.display();
        }
    }

    return 0;
}
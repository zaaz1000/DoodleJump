#ifndef DOODLEJUMP2_GAME_H
#define DOODLEJUMP2_GAME_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdlib.h>

class Game
{
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;
    std::fstream plik;
    std::string linia;
    int nr_linii=1;
    std::vector<int>wektor;
    //int tablica[10];
    int score=0;

public:

    enum GameState
    {
        MENU,
        GAME,
        GAMEOVER
    };
    GameState gamestate;
    sf::Text points;
    //sf::Text bestpoints;

    Game();
    void Game_display(sf::RenderWindow &window);
    void Points_display(sf::RenderWindow &window);
    void SavePosints();
    //void BestPoints();
    int getScore();

};

#endif //DOODLEJUMP2_GAME_H

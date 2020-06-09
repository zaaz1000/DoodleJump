#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include <iostream>
#include <string>


Game::Game()
{
    backgroundTexture.loadFromFile("../background.png");
    background.setSize(sf::Vector2f(500,700));
    background.setPosition(0,0);
    background.setTexture(&backgroundTexture);

    font.loadFromFile("../al-seana.ttf");
    points.setFont(font);
    points.setFillColor(sf::Color::Red);
    points.setCharacterSize(35);
    points.setPosition(sf::Vector2f(20,10));

    //bestpoints.setFont(font);
    //bestpoints.setFillColor(sf::Color::Red);
    //bestpoints.setCharacterSize(35);
    //bestpoints.setPosition(sf::Vector2f(150,650));


    gamestate=GAME;
}
void Game::Game_display(sf::RenderWindow &window)
{
    window.draw(background);
}

void Game::Points_display(sf::RenderWindow &window)
{
    window.draw(points);
}

void Game::SavePosints()
{
    std::ofstream plik("../wyniki.txt", std::ios::out | std::ios_base::app);
    if (plik.good() == false)
        std::cout << "ERROR";
    plik<<score<< std::endl;
    plik.close();
}

/*void Game::BestPoints()
{
    plik.open("../wyniki.txt", std::ios::in | std::ios_base::app);
    {
        while(getline(plik, linia));
        {
            wektor.push_back(atoi(linia.c_str()));
        }
    }
    plik.close();
    for(int i=0; i<=wektor.size(); i++)
    {
        if(wektor[0]<=wektor[i])
        {
            std::swap(wektor[0],wektor[i]);
        }
    }
    bestpoints.setString("Your best score: "+std::to_string(wektor[1]));
    std::cout<<wektor.size();

}*/

int Game::getScore()
{
    return score++;
}

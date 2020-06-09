#ifndef DOODLEJUMP2_DOODLE_H
#define DOODLEJUMP2_DOODLE_H
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include <SFML/Audio.hpp>
#include "Game.h"

class Doodle
{
    Game & game;
    Platfor & platfor;

    sf::Texture doodleTexture;
    sf::RectangleShape doodle;
    sf::SoundBuffer jump_sound;
    sf::SoundBuffer spring_sound;
    sf::Sound jump;
    sf::Sound spring;

    int x=100;
    int y=100;
    int h=200;
    float dy=0;
    bool detectjump=false;
    bool detectspring=false;

    int left_boundingbox =20;
    int right_boundingbox=20;
    int bottom_boundingbox=70;

public:

    Doodle(Platfor & P,Game & G);
    void Doodle_display(sf::RenderWindow &window);
    void Jump();
    void JumpOnPlatform();
    void getSpring();
    void Stearing();
    void GameOver();
    void Points();


};

#endif //DOODLEJUMP2_DOODLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Doodle.h"
#include <iostream>

Doodle::Doodle(Platfor & P, Game & G) : platfor(P), game(G)
{
    doodleTexture.loadFromFile("../doodler.png");
    doodle.setSize(sf::Vector2f(40,70));
    doodle.setPosition(220,630);
    doodle.setTexture(&doodleTexture);

    jump_sound.loadFromFile("../jump.wav");
    jump.setBuffer(jump_sound);

    spring_sound.loadFromFile("../feder.wav");
    spring.setBuffer(spring_sound);

}

void Doodle::Doodle_display(sf::RenderWindow &window)
{
    window.draw(doodle);
}

void Doodle::Jump()
{
    dy+=0.5;
    y+=dy;
    if(!detectjump)
    {
        if(y>630)
        {
            dy=-20;
        }
    }

    if(x>500)
        x=0;
    if(x<0)
        x=500;

    if(y<h)
    {
        for (int i = 0; i < 10; i++)
        {
            y = h;
            platfor.plat[i].y = platfor.plat[i].y - dy;
            if (platfor.plat[i].y > 630)
            {
                platfor.plat[i].y = 0;
                platfor.plat[i].x = rand() % 450;

            }
        }
        y=h;
        platfor.sprin[0].y=platfor.sprin[0].y-dy;
        if(platfor.sprin[0].y>630)
        {
            platfor.sprin[0].y=platfor.plat[5].y-15;
            platfor.sprin[0].x=platfor.plat[5].x+15;
        }
        platfor.spring.setPosition(x,y);
    }
    doodle.setPosition(x,y);
}
void Doodle::Stearing()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        x+=6;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        x-=6;
}

void Doodle::JumpOnPlatform()
{
    for(int i=0; i<10; i++)
    {
        if((x+right_boundingbox>platfor.plat[i].x) && (x+ left_boundingbox < platfor.plat[i].x+50)
           && (y+bottom_boundingbox>platfor.plat[i].y) && (y+bottom_boundingbox<platfor.plat[i].y+10)
           && (dy>0))
        {
            detectjump=true;
            dy=-20;
            jump.play();
        }
    }
}

void Doodle::getSpring()
{
    if((x+right_boundingbox>platfor.sprin[0].x) && (x+ left_boundingbox < platfor.sprin[0].x+50)
       && (y+bottom_boundingbox>platfor.sprin[0].y) && (y+bottom_boundingbox<platfor.sprin[0].y+10) && (dy>0))
    {
        detectspring=true;
        dy=-50;
        spring.play();
    }
}

void Doodle::GameOver()
{
    if(y>650)
    {
        game.gamestate=game.GAMEOVER;
        game.SavePosints();
        //game.BestPoints();
    }
}

void Doodle::Points()
{
    game.getScore();
    if(y==h && dy<(-1.62))
    {
        game.getScore();
        game.points.setString("Score: "+std::to_string(game.getScore()));

     }
}

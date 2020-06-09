#include <SFML/Graphics.hpp>
#include "Platform.h"
#include <iostream>

Platfor::Platfor()
{
    platformTexture.loadFromFile("../platform.png");
    platform.setSize(sf::Vector2f(60,20));
    platform.setTexture(&platformTexture);

    springTexture.loadFromFile("../Spring.gif");
    spring.setSize(sf::Vector2f(30,15));
    spring.setPosition(600,700);
    spring.setTexture(& springTexture);

}

void Platfor::Platform()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        plat[i].x = rand() % 440;
        plat[i].y = rand() % 680;
    }


}
void Platfor::Platform_display(sf::RenderWindow &window)
{
    for(int i=0; i<10; i++)
    {
        platform.setPosition(plat[i].x, plat[i].y);
        window.draw(platform);
    }
    spring.setPosition(sprin[0].x, sprin[0].y);
    window.draw(spring);
}

void Platfor::Spring()
{
        sprin[0].x=plat[5].x+15;
        sprin[0].y=plat[5].y-15;
}
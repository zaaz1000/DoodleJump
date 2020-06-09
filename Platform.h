#ifndef DOODLEJUMP2_PLATFORM_H
#define DOODLEJUMP2_PLATFORM_H

class Platfor
{
    sf::Texture platformTexture;
    sf::RectangleShape platform;

public:

    struct platform
    {
        int x;
        int y;
    }plat[10];

    struct spring
    {
        int x;
        int y;
    }sprin[0];

    sf::Texture springTexture;
    sf::RectangleShape spring;

    Platfor();
    void Platform();
    void Platform_display(sf::RenderWindow &window);
    void Spring();

};

#endif //DOODLEJUMP2_PLATFORM_H

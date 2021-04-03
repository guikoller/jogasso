
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Player.h"

int windowHeight = 768;
int windowWidht = 1280;

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidht, windowHeight), "Jogo");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Player jogado;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
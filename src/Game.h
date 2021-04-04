#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>


#include "Player.h"

class Game{
private:
    sf::RenderWindow window;
    int width = 800;
    int height = 600;
    void initWindow();
public:
    Game(/* args */);
    ~Game();
    //Functions
    void update();
    void render();
    const sf::RenderWindow& getWindow() const;//retorna estado da janela (aberta ou fechada)
};



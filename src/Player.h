#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Player{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    
    //animacao




    //movimento




    //status do jogador



    void initTexture();
    void initSprite();
public:
    Player();
    ~Player();
    void update();
    void render(sf::RenderTarget&target);
};
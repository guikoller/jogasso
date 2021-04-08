#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Jogador{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    
    //animacao




    //movimento




    //status do jogador


    //Texuras 
    void upadateMovimento();
    void initTexture();
    void initSprite();

public:
    Jogador();
    ~Jogador();
    void update();
    void render(sf::RenderTarget&target);
};
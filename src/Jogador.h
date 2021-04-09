#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Jogador{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool movendo; //para checar se esta movendo ou não
    sf::Clock timerAnimacao;
    
    //Animacao
    sf::IntRect frameAtual;


    //movimento




    //status do jogador


    //Texuras
    void iniciaVariaveis(); 
    void upadateMovimento();
    void uptadeAnimacao();
    void iniciaTextura();
    void iniciaSprite();
    void iniciaAnimacao();

public:
    Jogador();
    ~Jogador();
    void update();
    void render(sf::RenderTarget&target);
};
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

enum ESTADOS_ANIMACOES{PARADO = 0, MOVE_DIREITA, MOVE_ESQUERDA, PULANDO, CAINDO, ATACANDO};

class Jogador{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock timerAnimacao;
    
    //Animacao
    short estadoAnimacao;
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
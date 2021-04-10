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


    //Fisica
    sf::Vector2f velocidade;
    float velMax;
    float velMin;
    float aceleracao;
    float desaceleracao;



    //status do jogador


    //Texuras
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();
    void iniciaAnimacao();
    void initFisica();

public:
    Jogador();
    ~Jogador();

    void move(const float x, const float y);
    void updateFisica();
    void upadateMovimento();
    void uptadeAnimacao();
    void update();
    void render(sf::RenderTarget&target);
};
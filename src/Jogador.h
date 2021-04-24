#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Jogador{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock timerAnimacao;
    bool espelhado;
    
    //Animacao
    short estadoAnimacao;
    sf::IntRect frameAtual;

    enum {andando_direita,andando_esquerda,parado,pulando} STATE;

    //Fisica
    sf::Vector2f velocidade;
    float gravidade;
    float VelMaxY;



    //status do Jogador


    //Texuras
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();
    void flip(bool f);
    void iniciaAnimacao();
    void initFisica();

public:
    Jogador();
    ~Jogador();

    //Acessores
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getPosicao() const;

    void setPosicao(const float x, const float y);
    void resetVelY();

    void move(const float x, const float y);
    void updateFisica();
    void upadateMovimento();
    void uptadeAnimacao();
    void update();
    void render(sf::RenderTarget&target);
};

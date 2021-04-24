#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Monstro{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock timerAnimacao;
    
    //Animacao
    short estadoAnimacao;
    sf::IntRect frameAtual;

    enum {andando_direita,andando_esquerda,parado,atacando} STATE;

    //Fisica
    sf::Vector2f velocidade;
    float gravidade;
    float VelMaxY;



    //status do Monstro


    //Texuras
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();
    void iniciaAnimacao();
    void initFisica();

public:
    Monstro();
    ~Monstro();

    //Acessores
    const sf::FloatRect getGlobalBounds() const;
    sf::Sprite getSprite();

    void setPosicao(const float x, const float y);
    void resetVelY();

    void move(const float x, const float y);
    void updateFisica();
    void upadateMovimento();
    void uptadeAnimacao();
    void update();
    void render(sf::RenderTarget&target);
};

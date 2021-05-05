#pragma once
#include "Entidade.h"


class Personagem : protected Entidade{
public:
    sf::Sprite hitBox;
    sf::Texture textura;
    sf::Clock timerAnimacao;
    
    
    //Animacao
    sf::IntRect frameAtual;
    bool espelhado;

    enum {andando_direita,andando_esquerda,parado,pulando,caindo,atacando} STATE;

    //Fisica
    sf::Vector2f velocidade;
    float gravidade;
    float VelMaxY;

    //status do Jogador
    int vida;

    //Texturas
    virtual void iniciaVariaveis()= 0;//
    virtual void iniciaTextura()= 0;//
    virtual void iniciaSprite()=0;
    void iniciaAnimacao();//
    void iniciaFisica();//


    Personagem();//
    virtual ~Personagem()= 0;//

    //Acessores
    const sf::FloatRect getGlobalBounds() const;//
    const sf::Vector2f getPosicao() const;//
    sf::Sprite getSprite();//

    void setPosicao(const float x, const float y);//
    void resetVelY();//
    void resetVelX();//

    void updateFisica();//
    virtual void move(const float x, const float y)= 0;
    virtual void upadateMovimento()= 0;
    virtual void uptadeAnimacao()= 0;
    void update();//
    void render(sf::RenderTarget&targets);//
};
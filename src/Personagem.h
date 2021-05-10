#pragma once
#include "Entidade.h"


class Personagem : protected Entidade{
public:
    sf::RectangleShape hitBox;
    sf::Texture textura;
    sf::Clock timerAnimacao;
    
    
    //Animacao
    sf::IntRect frameAtual;
    bool espelhado;

    enum {andando_direita = 0,andando_esquerda,parado,pulando,caindo,atacando} STATE;

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


    Personagem();//
    virtual ~Personagem()= 0;//

    //Acessores
    const sf::FloatRect getGlobalBounds() const;//
    const sf::Vector2f getPosicao() const;//
    sf::Sprite getSprite();//
    void setVida(int vida);
    int getVida()const;
    int getState();
    bool estaAtacando();

    void setPosicao(const float x, const float y);//
    void resetVelY();//
    void resetVelX();//
    void setVelX(float vel);

    virtual void move(const float x, const float y);
    virtual void upadateMovimento()= 0;
    virtual void uptadeAnimacao()= 0;
    virtual void update();//
    void render(sf::RenderTarget&targets);//
};
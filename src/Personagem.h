#include "Entidade.h"

class Personagem : protected Entidade{
protected:
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

    //Texuras
    virtual void iniciaVariaveis();
    virtual void iniciaTextura();
    void iniciaAnimacao();
    void iniciaFisica();

public:
    Personagem();
    virtual ~Personagem();

    //Acessores
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getPosicao() const;
    sf::Sprite getSprite();

    void setPosicao(const float x, const float y);
    void resetVelY();
    void resetVelX();

    void updateFisica();
    virtual void move(const float x, const float y);
    virtual void upadateMovimento();
    virtual void uptadeAnimacao();
    void update();
    void render(sf::RenderTarget&targets);
};
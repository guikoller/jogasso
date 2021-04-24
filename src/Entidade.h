#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Entidade{
public:
    //Fisica
    sf::Vector2f velocidade;
    float gravidade;
    float VelMaxY;



    //status do Entidade


    //Texuras
    void iniciaVariaveis();
    void initFisica();


    Entidade();
    virtual ~Entidade();

    void resetVelY();

    virtual void move(const float x, const float y);
    virtual void updateFisica();

    virtual void update();
    virtual void render(sf::RenderTarget&target);
};

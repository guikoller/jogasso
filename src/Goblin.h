#pragma once
#include "Inimigo.h"
#include "Jogador.h"

class Goblin : public Inimigo{
private:
    //status do Goblin

    bool podeAtacar;

    //Texuras
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();


public:
    Goblin();
    ~Goblin();

    void jogadorPerto(Jogador *jogador, sf::Clock tempo);
    void upadateMovimento();
    void uptadeAnimacao();
};

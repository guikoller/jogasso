#pragma once
#include "Jogador.h"


class Martelador: public Jogador{
private:
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();
 public:
    Martelador();
    ~Martelador();
    // void move(const float x, const float y);
    void upadateMovimento();
    void uptadeAnimacao();
};

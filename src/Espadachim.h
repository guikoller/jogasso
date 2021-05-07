#pragma once
#include "Jogador.h"


class Espadachim: public Jogador{
private:
    void iniciaVariaveis();
    void iniciaTextura();
    void iniciaSprite();
 public:
    Espadachim();
    ~Espadachim();
    // void move(const float x, const float y);
    void upadateMovimento();
    void uptadeAnimacao();
};

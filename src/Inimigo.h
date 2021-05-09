#pragma once
#include "Personagem.h"

class Inimigo: public Personagem{
private:
    float posInicial;
public:
    Inimigo(/* args */);
    virtual ~Inimigo() = 0;

    void setPosInicial(float pos);
    float getPosInicial();
};
#pragma once
#include "Personagem.h"

class Inimigo: public Personagem{
private:
    /* data */
public:
    Inimigo(/* args */);
    virtual ~Inimigo() = 0;
};
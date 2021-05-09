#pragma once
#include "Personagem.h"

class Inimigo: public Personagem{
private:
public:
    Inimigo(/* args */);
    virtual ~Inimigo() = 0;
};
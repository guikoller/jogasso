#pragma once
#include "Personagem.h"




class Jogador : public Personagem{
protected:
    bool estaPulando;
public:
    Jogador();
    virtual ~Jogador()= 0;
    bool getPulando();
    void setPulando(const bool pulo);
};

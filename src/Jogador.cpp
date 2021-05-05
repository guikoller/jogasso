#include "Jogador.h"
Jogador::Jogador(){}
Jogador::~Jogador(){}

bool Jogador::getPulando(){
    return this->estaPulando;
}


void Jogador::setPulando(const bool pulo){
    this->estaPulando = pulo;
}

Colisor* Jogador::getColisao()const{
    return Colisor(this->hitBox);
}
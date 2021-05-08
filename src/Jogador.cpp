#include "Jogador.h"
Jogador::Jogador(){}
Jogador::~Jogador(){}

bool Jogador::getPulando(){
    return this->estaPulando;
}


void Jogador::iniciaFisica(){
    this->gravidade = 9.f;
    this->VelMaxY = 15.f;
}

void Jogador::setPulando(const bool pulo){
    this->estaPulando = pulo;
}

void Jogador::updateFisica(){
    this->velocidade.y += 1.0 * this->gravidade;
    if(std::abs(this->velocidade.y) >  this->VelMaxY){
        this->velocidade.y = this->VelMaxY *((this->velocidade.y < 0.f) ? -1.f : 1.f);
    }
	this->move(this->velocidade.x, velocidade.y);
}

void Jogador::update(){
    this->updateFisica();
    this->upadateMovimento();
    this->uptadeAnimacao();
}